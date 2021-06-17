(defn arduino-map [x, fromMin, fromMax, toMin, toMax]
    "arduino's map function in clojure for study"
    (let [a (- x fromMin)
          b (- toMax toMin)
          c (- fromMax fromMin)
          d toMin]
             (-> (* a b) (/ (+ c d)))))

;; if i exceeds fromMax, then overflow occurs
(dotimes [i 4] (println (arduino-map i 0 3 0 255)))

;; not sure what this output means
(dotimes [i 255] (println (float (arduino-map i 0 (+ 1 i) 0 255))))