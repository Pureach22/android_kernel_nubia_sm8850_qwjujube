__int64 __fastcall find_ie_location(__int64 a1, unsigned __int16 *a2, unsigned __int8 a3)
{
  int v3; // w8
  __int64 result; // x0
  unsigned __int16 *v5; // x10
  int v6; // w11
  bool v7; // vf

  v3 = *a2;
  result = 0;
  v5 = a2 + 1;
  v6 = *((unsigned __int8 *)a2 + 3) + 2;
  while ( *((unsigned __int8 *)v5 + (unsigned int)result) != a3 )
  {
    v7 = __OFSUB__(v3, v6);
    v3 -= v6;
    if ( (v3 < 0) ^ v7 | (v3 == 0) )
      return 0xFFFFFFFFLL;
    if ( (_DWORD)result != 256 )
    {
      v6 = *((unsigned __int8 *)v5 + (unsigned int)result + 1) + 2;
      result = (unsigned int)(v6 + result);
      if ( (unsigned int)result < 0x101 )
        continue;
    }
    __break(0x5512u);
    return 0xFFFFFFFFLL;
  }
  return result;
}
