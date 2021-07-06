# generative-music-score
Short Version: A new song is created everytime the device is reset.
  
Long Version: This system generates unique 16 note melodies. It randomly chooses 4 notes or rests and assigns them to section A. It repeats the above process and assigns the results to section B. Finally, it randomly chooses 4 bits which determine whether section A or B will be played and stores this information in a list. This final list is iterated through playing each section. Each section also has an octave multiplier, an integer from 1 to 6, which multiplies all notes in the section to enable different octaves while only explicitly defining 12 notes. The end result is an emergent system creating 16 note melodies using verse-chorus song structure (i.e. AABA, ABAB, etc.) with a considerable amount of compositional variation. 

A Video of the device in action: https://photos.app.goo.gl/rHBAmfNFVsW9pobc7.
