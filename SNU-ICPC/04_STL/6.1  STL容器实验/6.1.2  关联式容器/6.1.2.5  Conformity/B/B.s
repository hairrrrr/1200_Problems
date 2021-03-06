(require (lib "etc.ss"))
(require (lib "list.ss"))
(require (lib "math.ss"))

(define (input n)
  (if (> n 0)
      (cons
       (sort (list (read) (read) (read) (read) (read)) <)
       (input (- n 1)))
      '()))
(define (f-list f l)
  (if (empty? (cdr l))
      (car l)
      (f (car l) (f-list f (cdr l)))))
(define (min-list l) (f-list min l))
(define (max-list l) (f-list max l))
(define (sum-list l) (f-list + l))
(define (display-nl output) (begin (display output) (newline)))
(define (case n)
  (let ((tbl (make-hash-table 'equal))
        (students (input n)))
    (begin
      (map (lambda (courses)
             (hash-table-put! tbl courses
                              (+ 1 (hash-table-get tbl courses 0))))
           students)
      (let ((most (max-list (map 
                             (lambda (courses) (hash-table-get tbl courses 0))
                             students))))
        (display-nl (sum-list (map (lambda (courses)
                         (if (= (hash-table-get tbl courses 0) most)
                             1
                             0))
                       students)))))))
(define (main)
  (let ((n (read)))
    (if (= 0 n)
        '()
        (begin (case n) (main)))))
(main)
