(setq custom-file "~/.emacs.d/init.el")
(load custom-file)

(load-file "~/.emacs.d/rc.el")

(set-frame-font "Iosevka-20" nil t)
(add-to-list 'default-frame-alist '(font . "Iosevka-20"))

(tool-bar-mode 0)
(menu-bar-mode 0)
(scroll-bar-mode 0)
(show-paren-mode 1)

;; Auto completion and ido suggestions
(ido-mode 1)
(ido-everywhere 1)
(setq ido-enable-flex-matching t)


(add-to-list 'load-path "~/.emacs.d/")

(require 'simpc-mode)
(add-to-list 'auto-mode-alist '("\\.[hc]\\(pp\\)?\\'" . simpc-mode))

(global-display-line-numbers-mode 1)

(rc/require-theme 'gruber-darker)

(setq-default indent-tabs-mode t)  ;; Use tabs instead of spaces

(require 'cc-mode)
(add-hook 'c-mode-common=hook 'electric-pair-mode)
(electric-pair-mode 1)

; Mx recentf-open-files to check out recently opened files in emacs to navigate faster 
(recentf-mode 1)

(setq history-length 25)
(savehist-mode 1)

(save-place-mode 1)

; revert buffers when the underlying file has changed.
(global-auto-revert-mode 1)

; open emacs full screen on startup
(add-to-list 'default-frame-alist '(fullscreen . maximized))

; This is for vertical compilation buffer
(setq split-height-threshold nil)
(setq split-width-threshold 0)
(setq compiliation-window-width 30)

;;;;;;;;;;;;;; --- GDB MODE CHANGES  --------  
(setq gdb-many-windows nil)

(defun set-gdb-layout(&optional c-buffer)
  (if (not c-buffer)
      (setq c-buffer (window-buffer (selected-window)))) ;; save current buffer

  ;; from http://stackoverflow.com/q/39762833/846686
  (set-window-dedicated-p (selected-window) nil) ;; unset dedicate state if needed
  (switch-to-buffer gud-comint-buffer)
  (delete-other-windows) ;; clean all

  (let* (
         (w-source (selected-window)) ;; left top
         (w-gdb (split-window w-source nil 'right)) ;; right bottom
         (w-locals (split-window w-gdb nil 'above)) ;; right middle bottom
         (w-stack (split-window w-locals nil 'above)) ;; right middle top
         (w-breakpoints (split-window w-stack nil 'above)) ;; right top
         (w-io (split-window w-source (floor(* 0.9 (window-body-height)))
                             'below)) ;; left bottom
         )
    (set-window-buffer w-io (gdb-get-buffer-create 'gdb-inferior-io))
    (set-window-dedicated-p w-io t)
    (set-window-buffer w-breakpoints (gdb-get-buffer-create 'gdb-breakpoints-buffer))
    (set-window-dedicated-p w-breakpoints t)
    (set-window-buffer w-locals (gdb-get-buffer-create 'gdb-locals-buffer))
    (set-window-dedicated-p w-locals t)
    (set-window-buffer w-stack (gdb-get-buffer-create 'gdb-stack-buffer))
    (set-window-dedicated-p w-stack t)

    (set-window-buffer w-gdb gud-comint-buffer)

    (select-window w-source)
    (set-window-buffer w-source c-buffer)
    ))
(defadvice gdb (around args activate)
  "Change the way to gdb works."
  (setq global-config-editing (current-window-configuration)) ;; to restore: (set-window-configuration c-editing)
  (let (
        (c-buffer (window-buffer (selected-window))) ;; save current buffer
        )
    ad-do-it
    (set-gdb-layout c-buffer))
  )
(defadvice gdb-reset (around args activate)
  "Change the way to gdb exit."
  ad-do-it
  (set-window-configuration global-config-editing))
;;;;;;;;;;;;;; --- GDB MODE CHANGES END --------  
