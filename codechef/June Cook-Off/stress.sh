set -e
g++-11 E.cpp -o code
g++-11 Egen.cpp -o gen
g++-11 Eafter.cpp -o brute
for((i = 1; i < 1000; ++i)); do
    ./gen $i > input_file
    ./brute < input_file > correctAnswer
    ./code < input_file > myAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer