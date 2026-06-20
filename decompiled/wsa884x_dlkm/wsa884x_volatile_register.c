bool __fastcall wsa884x_volatile_register(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  _BOOL8 result; // x0

  v2 = a2 - 12288;
  if ( a2 <= 0x3000 )
    return 0;
  result = 1;
  if ( a2 - 13572 >= 2 && a2 - 13701 >= 2 )
  {
    if ( v2 >> 8 >= 0x39 )
    {
      __break(0x5512u);
      JUMPOUT(0xCE3C);
    }
    return (wsa884x_reg_access[v2] & 3) == 1;
  }
  return result;
}
