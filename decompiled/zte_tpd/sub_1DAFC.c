__int64 __usercall sub_1DAFC@<X0>(_DWORD *a1@<X0>, int a2@<W8>)
{
  *a1 = 0;
  a1[1] = a2;
  return syna_spi_read(a1 - 56);
}
