# Chanda Identifier (Thenga Coder) شناسایی‌کنندهٔ چندا
A C++ command-line tool for identifying the metrical pattern (chandas) of Sanskrit verses. This project analyzes the sequence of light (laghu) and heavy (guru) syllables in a given line of Devanagari text to determine its meter.

# 📖 Overview
In the grand tradition of Sanskrit poetry, Chandas (छन्दस्) represents the soul of verse—its rhythm, meter, and cadence. Just as tala gives structure to Carnatic music, chandas gives life to poetry. The system is built upon the classification of syllables into two types:

Laghu (लघु): A 'light' or short syllable.

Guru (गुरु): A 'heavy' or long syllable.

This program serves as a digital pandit, capable of reading a line of Sanskrit and precisely identifying the specific chandas it follows, from the ubiquitous Anuṣṭubh to the elegant Vasantatilakā.

The Story Behind "Thenga Coder"
This name is a heartfelt nod to our roots in Kerala. "Thenga" (തേങ്ങ), the Malayalam word for coconut, is an integral part of our culture. It represents simplicity, utility, and a touch of home. We are the "Thenga Coders"—building modern solutions inspired by ancient wisdom.

# How It Works
The identification logic is a direct implementation of the rules of Sanskrit prosody:

Syllabification: The input string is intelligently parsed into its constituent syllables (aksharas).

Laghu/Guru Analysis: Each syllable is algorithmically classified as laghu or guru based on a set of precise rules:

A syllable is guru if its vowel is inherently long (ā, ī, ū, ṝ, e, ai, o, au).

A syllable is also guru if its short vowel is followed by a consonant cluster (samyuktakshara), an anusvāra (ं), or a visarga (ः).

If neither of these conditions is met, the syllable is classified as laghu.

Pattern Recognition: The generated sequence of laghu and guru syllables is then matched against a comprehensive library of known chandas patterns stored within the program.

Result: The program outputs the name of the identified chandas, bringing clarity to the verse's structure.

# Features
High Accuracy: Faithfully implements the core principles of Sanskrit metrical analysis.

Extensive Chandas Library: Pre-loaded with patterns for dozens of common and classical meters.

Full Unicode Support: Natively handles Devanagari script (UTF-8) for seamless input.

Lightweight & Fast: Built in C++ for efficient command-line performance.

Educational: An excellent tool for students of Sanskrit, poetry, and linguistics.

# 🚀 Getting Started
To get a local copy up and running, follow these simple steps.

Prerequisites
You will need a C++ compiler that supports the C++11 standard or newer.

On Linux/macOS: g++ or clang++

On Windows: MinGW or Visual Studio with C++ tools

Compilation and Execution
Clone the Repository

git clone [https://github.com/SmithinJRaj/chanda_identifier_thenga_coder.git](https://github.com/SmithinJRaj/chanda_identifier_thenga_coder.git)
cd chanda_identifier_thenga_coder

Compile the Program

g++ -std=c++11 -o chanda_identifier main.cpp

This command will create an executable file named chanda_identifier.

Run the Identifier
Execute the program from your terminal, passing the Sanskrit verse in quotes as an argument.

Example using a verse from the Bhagavad Gita:

./chanda_identifier "यदा यदा हि धर्मस्य ग्लानिर्भवति भारत"

Expected Output:

Verse: यदा यदा हि धर्मस्य ग्लानिर्भवति भारत
Pattern: L-G L-G L-L-G-G | L-G-L-L-G-L-L-G
Chandas Identified: Anuṣṭubh (अनुष्टुभ्)

# 🤝 Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

Fork the Project

Create your Feature Branch (git checkout -b feature/AmazingFeature)

Commit your Changes (git commit -m 'Add some AmazingFeature')

Push to the Branch (git push origin feature/AmazingFeature)

Open a Pull Request

# 📜 License
Distributed under the MIT License. See LICENSE file for more information.