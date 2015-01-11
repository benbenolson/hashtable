#!/usr/bin/env perl
use strict; use warnings;

my $num_names = 100;
my $max_name_len = 20;
my $min_name_len = 10;

open(my $fh, '>', "names.txt");

foreach (1..$num_names) {
  # Print the first name
  my $fn_len = int(rand($max_name_len)) + $min_name_len;
  foreach(1..$fn_len) {
    print $fh chr(int(rand(26)) + 97);
  }

  print $fh " ";

  # Print the last name
  my $ln_len = int(rand($max_name_len)) + $min_name_len;
  foreach(1..$ln_len) {
    print $fh chr(int(rand(26)) + 97);
  }
  print $fh "\n";
}
