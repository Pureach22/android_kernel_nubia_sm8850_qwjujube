__int64 __fastcall ieee80211_rts_duration(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  unsigned __int8 *v5; // x10
  int v6; // w8
  int v7; // w11
  unsigned __int64 v8; // x10
  unsigned __int64 v9; // x9
  unsigned int v10; // w10
  int v11; // w11

  if ( (*(_DWORD *)(a4 + 4) & 7u) >= 6 )
  {
    __break(0x5512u);
    return ieee80211_ctstoself_duration(a1, a2, a3, a4);
  }
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (*(_DWORD *)(a4 + 4) & 7) + 328);
  v5 = (unsigned __int8 *)(*(_QWORD *)(v4 + 8) + 12LL * *(char *)(a4 + 20));
  if ( a2 )
  {
    v6 = *(unsigned __int8 *)(a2 + 134);
    if ( *(_BYTE *)(a2 - 968) == 1 )
    {
      v7 = (*v5 >> 4) & 1;
      v8 = *((unsigned __int16 *)v5 + 2);
      if ( (v7 & 1) != 0 )
        return 4 * ((4 * (int)v8 + 1339) / (unsigned int)(4 * v8))
             + 36
             + 4 * ((4 * (int)v8 + 1339) / (unsigned int)(4 * v8) + (unsigned int)((4 * v8 + 80 * a3 + 539) / (4 * v8)))
             + 72;
      goto LABEL_8;
    }
  }
  else
  {
    v6 = 0;
  }
  v8 = *((unsigned __int16 *)v5 + 2);
LABEL_8:
  if ( *(_DWORD *)(v4 + 16) == 1 )
    return 4 * ((4 * (int)v8 + 1339) / (unsigned int)(4 * v8))
         + 36
         + 4 * ((4 * (int)v8 + 1339) / (unsigned int)(4 * v8) + (unsigned int)((4 * v8 + 80 * a3 + 539) / (4 * v8)))
         + 72;
  v9 = (v8 + 80 * a3 + 319) / v8;
  v10 = ((int)v8 + 1119) / (unsigned int)v8;
  if ( v6 )
    v11 = 106;
  else
    v11 = 202;
  return v10 + v11 + v10 + v11 + (_DWORD)v9 + v11;
}
