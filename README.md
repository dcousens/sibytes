# sibytes
A streaming, line-delimited, integer to SI unit bytes tool.

The output is not rounded,  precision is maintained.

Maximum input is a 64 bit integer, or `18446744073709551615`.


## Examples
``` bash
> echo '1' | sibytes
1 B

> echo '10' | sibytes
10 B

> echo '100' | sibytes
100 B

> echo '1000' | sibytes
1 kB

> echo '1077' | sibytes
1.077 kB

> echo '10000' | sibytes
10 kB

> echo '100000' | sibytes
100 kB

> echo '1000000' | sibytes
1 MB

...

> echo '162195527' | sibytes
162.195527 MB

> echo '1000000000000' | sibytes
1 TB

> echo -e '111\n2222\n4444224444' | sibytes
111 B
2.222 kB
4.444224444 GB

> echo '1000 foobar' | sibytes
1 kB

> echo '18446744073709551616' | sibytes
terminate called after throwing an instance of 'std::out_of_range'
  what():  stol

> echo 'foobar' | sibytes
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stol
```

## LICENSE [MIT](LICENSE)
