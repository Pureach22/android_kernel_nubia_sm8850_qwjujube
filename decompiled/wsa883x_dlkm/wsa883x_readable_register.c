__int64 __fastcall wsa883x_readable_register(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8

  v2 = a2 - 12288;
  if ( a2 <= 0x3000 )
    return 0;
  if ( v2 >> 9 >= 0x1B )
  {
    __break(0x5512u);
    JUMPOUT(0xFFFFFFFFFF178444LL);
  }
  return wsa883x_reg_access[v2] & 1;
}
