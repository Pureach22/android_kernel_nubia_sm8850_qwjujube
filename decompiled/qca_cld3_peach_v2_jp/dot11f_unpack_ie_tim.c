__int64 __fastcall dot11f_unpack_ie_tim(__int64 a1, _BYTE *a2, char a3, _BYTE *a4)
{
  char v5; // w9
  char v6; // w8
  size_t v7; // x2

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 || (a4[1] = *a2, a3 == 1) || (a4[2] = a2[1], a3 == 2) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    v5 = a3 - 3;
    v6 = a2[2];
    v7 = (unsigned __int8)(a3 - 3);
    a4[4] = v5;
    a4[3] = v6;
    if ( (unsigned int)v7 < 0xFC )
    {
      qdf_mem_copy(a4 + 5, a2 + 3, v7);
      return 0;
    }
    else
    {
      *a4 = 0;
      return 8;
    }
  }
}
