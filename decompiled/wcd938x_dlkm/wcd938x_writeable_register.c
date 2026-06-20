__int64 __fastcall wcd938x_writeable_register(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8

  v2 = a2 - 12288;
  if ( a2 <= 0x3000 )
    return 0;
  if ( v2 >= 0x34D9 )
  {
    __break(0x5512u);
    JUMPOUT(0xFFFFFFFFFF17E7C8LL);
  }
  return (*((unsigned __int8 *)&wcd938x_reg_access + v2) >> 1) & 1;
}
