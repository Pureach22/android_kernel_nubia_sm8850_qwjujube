__int64 __fastcall ib_parse_type7_set_draw_state(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x22
  unsigned __int64 *v8; // x23
  unsigned __int64 i; // x24
  __int64 result; // x0
  int v11; // w8
  unsigned __int64 v12; // x2
  unsigned __int64 v13; // x3
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned int v16; // w4

  v4 = *a2 & 0x3FFFLL;
  if ( (*a2 & 0x3FFF) != 0 )
  {
    v8 = (unsigned __int64 *)(a2 + 2);
    for ( i = 1; i <= v4; i += 3LL )
    {
      v11 = *((_DWORD *)v8 - 1);
      if ( (v11 & 0x10000) != 0 || (v11 & 0xF0000) == 0 )
      {
        v13 = (unsigned __int16)*((_DWORD *)v8 - 1);
        if ( (unsigned __int16)*((_DWORD *)v8 - 1) )
        {
          v12 = *v8;
          v14 = a1;
          v15 = a3;
          v16 = 4;
LABEL_3:
          result = adreno_ib_find_objs(v14, v15, v12, v13, v16, a4, 2u);
          if ( (_DWORD)result )
            return result;
        }
      }
      else if ( (v11 & 0x80000) != 0 )
      {
        v12 = *v8;
        v13 = (unsigned __int16)*((_DWORD *)v8 - 1);
        v14 = a1;
        v15 = a3;
        v16 = 2;
        goto LABEL_3;
      }
      v8 = (unsigned __int64 *)((char *)v8 + 12);
    }
  }
  return 0;
}
