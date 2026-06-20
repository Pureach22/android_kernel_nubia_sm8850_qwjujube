bool __fastcall wsa883x_volatile_register(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8

  v2 = a2 - 12288;
  if ( a2 <= 0x3000 )
    return 0;
  if ( v2 >> 9 >= 0x1B )
  {
    __break(0x5512u);
    JUMPOUT(0xA610);
  }
  return (wsa883x_reg_access[v2] & 3) == 1;
}
