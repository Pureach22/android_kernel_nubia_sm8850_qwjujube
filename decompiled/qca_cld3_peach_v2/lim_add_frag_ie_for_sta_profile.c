__int64 __fastcall lim_add_frag_ie_for_sta_profile(_BYTE *a1, _WORD *a2)
{
  size_t v2; // x20
  _BYTE *v5; // x0
  _BYTE *v6; // x22
  unsigned __int16 v7; // w9
  int v8; // w8
  int v9; // w10
  int v10; // w14
  int v11; // w15
  int v12; // w15
  char v13; // w17
  bool v14; // cc

  v2 = (unsigned __int16)*a2;
  v5 = (_BYTE *)_qdf_mem_malloc(v2, "lim_add_frag_ie_for_sta_profile", 1352);
  if ( !v5 )
    return 2;
  v6 = v5;
  qdf_mem_copy(v5, a1, (unsigned int)v2);
  if ( (unsigned int)v2 >= 0x102 )
  {
    if ( (unsigned __int8)((unsigned __int16)(v2 - 513) >> 8) != 255 )
      LODWORD(v2) = v2 + 2 * ((unsigned __int16)(v2 - 513) / 0xFFu) + 2;
    LOWORD(v2) = v2 + 2;
  }
  *a1 = *v6;
  a1[1] = v6[1];
  if ( (unsigned __int16)*a2 >= 3u )
  {
    a1[2] = v6[2];
    if ( (unsigned __int16)*a2 >= 4u )
    {
      v7 = 3;
      v8 = 1;
      v9 = -1;
      v10 = 3;
      do
      {
        a1[(unsigned __int16)v10] = v6[v7];
        v11 = v10 + 1;
        if ( (unsigned int)(-16843009 * v8) <= 0x1010101 )
        {
          a1[(unsigned __int16)(v10 + 1)] = -2;
          v12 = v9 + (unsigned __int16)*a2;
          v13 = v12 - 2;
          v14 = v12 <= 257;
          v11 = v10 + 3;
          if ( !v14 )
            v13 = -1;
          a1[(unsigned __int16)(v10 + 2)] = v13;
        }
        ++v8;
        --v9;
        ++v7;
        v10 = v11;
      }
      while ( (unsigned __int16)*a2 - 2 > v8 );
    }
  }
  *a2 = v2;
  _qdf_mem_free((__int64)v6);
  return 0;
}
