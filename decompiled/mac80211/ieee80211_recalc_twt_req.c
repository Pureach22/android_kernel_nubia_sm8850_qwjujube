__int64 __fastcall ieee80211_recalc_twt_req(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x10
  _BYTE *v9; // x8
  int v10; // w9
  __int64 v11; // x8

  v5 = *(_DWORD *)(a1 + 4720);
  if ( *(_BYTE *)(a1 + 5848) != 1 )
    goto LABEL_6;
  if ( v5 == 2 )
  {
    v6 = 8;
    v7 = *(unsigned __int16 *)(a2 + 92);
    if ( *(_WORD *)(a2 + 92) )
      goto LABEL_8;
    goto LABEL_18;
  }
  if ( v5 != 3 )
  {
LABEL_6:
    v6 = (unsigned __int8)*(_DWORD *)(a1 + 4720);
    if ( v6 >= 0xC )
    {
      __break(0x800u);
    }
    else
    {
      v7 = *(unsigned __int16 *)(a2 + 92);
      if ( *(_WORD *)(a2 + 92) )
        goto LABEL_8;
    }
LABEL_18:
    v9 = nullptr;
    goto LABEL_19;
  }
  v6 = 9;
  v7 = *(unsigned __int16 *)(a2 + 92);
  if ( !*(_WORD *)(a2 + 92) )
    goto LABEL_18;
LABEL_8:
  if ( v6 == 4 )
    LOBYTE(v6) = 3;
  v8 = 1LL << v6;
  v9 = (_BYTE *)(*(_QWORD *)(a2 + 96) + 2LL);
  while ( ((unsigned __int16)v8 & *((_WORD *)v9 - 1)) == 0 )
  {
    --v7;
    v9 += 128;
    if ( !v7 )
      goto LABEL_18;
  }
  if ( v9 == byte_2 || (*v9 & 1) == 0 )
    goto LABEL_18;
LABEL_19:
  if ( *(unsigned __int8 *)(a5 + 696) >= 0xAu && (*(_BYTE *)(*(_QWORD *)(a5 + 40) + 9LL) & 0x40) != 0 )
  {
    v10 = 0;
    if ( v9 && (*(_BYTE *)(*(_QWORD *)(a4 + 920) + 85LL) & 4) != 0 )
      v10 = ((unsigned __int8)v9[1] >> 1) & 1;
  }
  else
  {
    v10 = 0;
  }
  v11 = *(_QWORD *)(a3 + 944);
  if ( *(unsigned __int8 *)(v11 + 41) == v10 )
    return 0;
  *(_BYTE *)(v11 + 41) = v10;
  return 0x8000000;
}
