__int64 __fastcall _ieee80211_schedule_txq(__int64 a1, unsigned __int64 a2, char a3)
{
  unsigned __int64 v3; // x19
  __int64 v4; // x22
  unsigned __int64 v5; // x8
  __int64 v6; // x20
  _BOOL4 v8; // w9
  unsigned __int64 v9; // x8
  __int64 v11; // x11
  __int64 *v12; // x10
  _BOOL4 v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  __int64 v16; // x2
  __int64 v17; // x8
  unsigned int v18; // w8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x2
  __int64 *v22; // x10
  int v23; // w9

  v5 = *(unsigned __int8 *)(a2 + 17);
  if ( v5 >= 5 )
    goto LABEL_38;
  v4 = a1 + 308;
  v6 = a1;
  v3 = a2;
  raw_spin_lock_bh(a1 + 308 + 4 * v5);
  v8 = (a3 & 1) != 0 || *(_QWORD *)(v3 - 32) != v3 - 32 || *(_DWORD *)(v3 - 124) != 0;
  a1 = v3 - 48;
  if ( *(_QWORD *)(v3 - 48) != v3 - 48 )
    goto LABEL_6;
  v11 = *(_QWORD *)(v3 + 8);
  if ( !v8 )
  {
    if ( !v11 )
      goto LABEL_6;
    v18 = *(unsigned __int8 *)(v3 + 17);
    if ( v18 >= 5 )
      goto LABEL_38;
    if ( *(_DWORD *)(v11 - 2160 + 40LL * *(unsigned __int8 *)(v3 + 17) + 24)
       - *(_DWORD *)(v11 - 2160 + 40LL * *(unsigned __int8 *)(v3 + 17) + 28) >= 0 )
      goto LABEL_6;
    if ( v18 == 4 )
      goto LABEL_38;
    if ( *(_QWORD *)(v11 - 2160 + 40LL * *(unsigned __int8 *)(v3 + 17) + 16) - jiffies + 25LL < 0 )
      goto LABEL_6;
    v12 = (__int64 *)(v3 + 8);
LABEL_28:
    v19 = *(unsigned __int8 *)(v3 + 17);
    if ( v19 > 4 )
      goto LABEL_38;
    v20 = v6 + 16 * v19;
    v21 = v20 + 328;
    a2 = *(_QWORD *)(v20 + 336);
    if ( a1 == v20 + 328 || a2 == a1 || *(_QWORD *)a2 != v21 )
      goto LABEL_39;
    *(_QWORD *)(v20 + 336) = a1;
    *(_QWORD *)(v3 - 48) = v21;
    *(_QWORD *)(v3 - 40) = a2;
    *(_QWORD *)a2 = a1;
    if ( v8 )
      goto LABEL_33;
    goto LABEL_6;
  }
  v12 = (__int64 *)(v3 + 8);
  if ( !v11 )
    goto LABEL_28;
  v13 = *(_WORD *)(v6 + 404) && v8;
  if ( !v13 || (*(_BYTE *)(*(_QWORD *)(v6 + 72) + 116LL) & 2) == 0 )
    goto LABEL_28;
  v14 = *(unsigned __int8 *)(v3 + 17);
  if ( v14 > 4 )
    goto LABEL_38;
  v15 = v6 + 16 * v14;
  v16 = *(_QWORD *)(v15 + 328);
  a2 = v15 + 328;
  if ( *(_QWORD *)(v16 + 8) != v15 + 328 || a1 == a2 || v16 == a1 )
  {
    a1 = _list_add_valid_or_report(a1, a2);
    v17 = *v22;
    if ( *v22 )
      goto LABEL_34;
  }
  else
  {
    *(_QWORD *)(v16 + 8) = a1;
    *(_QWORD *)(v3 - 48) = v16;
    *(_QWORD *)(v3 - 40) = a2;
    *(_QWORD *)a2 = a1;
    v17 = *v12;
    if ( *v12 )
      goto LABEL_34;
  }
LABEL_6:
  while ( 1 )
  {
    v9 = *(unsigned __int8 *)(v3 + 17);
    if ( v9 <= 4 )
      return raw_spin_unlock_bh(v4 + 4 * v9);
LABEL_38:
    while ( 1 )
    {
      __break(0x5512u);
LABEL_39:
      a1 = _list_add_valid_or_report(a1, a2);
      if ( !v23 )
        break;
LABEL_33:
      v17 = *v12;
      if ( !*v12 )
        goto LABEL_6;
LABEL_34:
      if ( *(unsigned __int8 *)(v3 + 17) < 4uLL )
      {
        *(_QWORD *)(v17 + 40LL * *(unsigned __int8 *)(v3 + 17) - 2144) = jiffies;
        goto LABEL_6;
      }
    }
  }
}
