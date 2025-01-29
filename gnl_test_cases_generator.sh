 echo -e "\n" > test/test2_single_newline.txt
 echo -n "A" > test/test3_single_char.txt
 echo -e "\n\n\n" > test/test4_multiple_newlines.txt
 echo -n "This is a line without a newline at the end." > test/test5_no_newline_eof.txt
 python3 -c "print('A' * 2000)" > test/test6_very_long_line.txt
 echo -ne "Hello\0World\nSecond Line\0" > test/test7_binary_data.txt
 printf "\n%.0s" {1..5} > test/test8_only_newlines.txt
 echo -e "\nLine 1\n\nLine 2\n\nLine 3" > test/test9_lines_start_with_newline.txt
 echo -e "안녕하세요\nこんにちは\nHello\n😊🔥🌟" > test/test10_utf8_characters.txt
 echo -e "Line 1\r\nLine 2\nLine 3\r\n" > test/test11_mixed_newlines.txt
 dd if=/dev/zero of=test/test12_large_file.txt bs=1M count=10
 echo -e "こんにちは\n안녕하세요\nHello 😊🔥\nSpecial characters: æøåß©®" > test/test13_non_ascii.txt
 echo -e "Line with tab\tand spaces\nLine with backslash\\ and quote\"" > test/test14_special_characters.txt
 echo -e "   \n\t\n  \t  " > test/test15_whitespace_only.txt
 echo -n "ABCD" > test/test16_short_buffer.txt
 echo -e "Line 1\n" > test/test17_no_content_after_newline.txt
 echo -e "   \n\t\nContent after whitespace." > test/test18_only_whitespace_then_content.txt
 python3 -c "print('B' * 3000)" > test/test19_multiple_buffers.txt
 echo -e "Start\nMiddle\nEnd\n" > test/test20_interleaved_newlines_and_content.txt