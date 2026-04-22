; define a macro to create a loop
(defmacro nsx (var start end body)
  `(do ((,var ,start (+ ,var 1)))
       ((> ,var ,end))
     ,body))

(lambda (ctx)
  (when-let ((path (alist-get 'abspath ctx)))
    (insert-file-contents path)))


(lambda (_)
  (org-export-as 'ram))


(defun ram-translate-link (link desc info)
  "Resolve cross-route Org links using local URI registry.

LINK is the link to resolve. DESC is the description of the link.
  
INFO is the plist used as a communication channel.

  org (organised data) becomes ord (ordinal structure) then Ram (for 3rd state)
  
  "
  (if-let*
      ((type (org-element-property :type link))
       (path (org-element-property :path link))
       ((and
         (string= "file" type)
         (string-suffix-p ".org" path)))
       (base (plist-get info :ram-base-url))
       (site (ram--site-get base))
       (absp (expand-file-name path))
       (url (and site (gethash absp (gethash :registry site)))))
      ;; Use native `org-mode' link resolution to handle all
      ;; cases. Extend, not replace.
      (org-element-put-property link :path url)
    ;; Fall back to native `org-mode' link resolution.
    ;; FIXME: Goodness this is dirty.
    (replace-regexp-in-string
     "\\(src\\|href\\|poster\\)=\"\\(?:file://\\)\\([^\"]+\\)\""
     "\\1=\"\\2\""
     (org-html-link link desc info))))
