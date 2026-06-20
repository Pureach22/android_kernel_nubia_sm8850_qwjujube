__int64 __fastcall cfg80211_mlme_register_mgmt(
        unsigned __int64 a1,
        int a2,
        unsigned __int16 a3,
        const void *a4,
        int a5,
        char a6,
        const char **a7)
{
  const char **v7; // x21
  int v8; // w22
  __int64 *v9; // x24
  unsigned __int64 v10; // x25
  int v11; // w26
  const void *v12; // x27
  int v13; // w28
  __int64 v14; // x19
  __int64 v15; // x9
  const char *v16; // x19
  __int64 v18; // x8
  unsigned __int64 v19; // x23
  __int64 v20; // x20
  const void *v21; // x1
  unsigned __int64 v22; // x8
  __int64 v23; // x2
  _QWORD *v24; // x20
  int v25; // w8
  int v26; // w0
  __int64 v27; // [xsp+0h] [xbp-10h]
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-10h]
  int v29; // [xsp+8h] [xbp-8h]
  __int64 v30; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_50;
  v15 = *(_QWORD *)(v14 + 72);
  if ( !v15 )
    return 4294967201LL;
  v7 = a7;
  if ( (a3 & 0xC) != 0 )
  {
    v16 = "frame type not management";
LABEL_8:
    do_trace_netlink_extack(v16);
    if ( v7 )
      *v7 = v16;
    return 4294967274LL;
  }
  if ( (a3 & 0xFF03) != 0 )
  {
    v16 = "Invalid frame type";
    goto LABEL_8;
  }
  v18 = *(unsigned int *)(a1 + 8);
  v11 = a3;
  if ( (((unsigned __int64)*(unsigned __int16 *)(v15 + 4 * v18 + 2) >> (a3 >> 4)) & 1) == 0 )
  {
    v16 = "Registration to specific type not supported";
    goto LABEL_8;
  }
  v8 = a5;
  if ( a3 == 176 && (_DWORD)v18 == 2 && (!a4 || a5 <= 1) )
  {
    v16 = "Authentication algorithm number required";
    goto LABEL_8;
  }
  LOBYTE(v9) = a6;
  v12 = a4;
  v13 = a2;
  v10 = a1;
  v19 = a5 + 40LL;
  v20 = _kmalloc_noprof(v19, 3520);
  if ( !v20 )
    return 4294967284LL;
  while ( 1 )
  {
    v29 = (unsigned __int8)v9 & 1;
    v27 = v14 - 80;
    raw_spin_lock_bh(v14 - 80);
    v21 = v12;
    v9 = (__int64 *)(v10 + 48);
    v14 = *(_QWORD *)(v10 + 48);
    if ( v14 != v10 + 48 )
      break;
LABEL_18:
    v22 = v19 - 35;
    if ( v19 < 0x23 )
      v22 = 0;
    if ( v22 >= v8 )
    {
      memcpy((void *)(v20 + 35), v21, v8);
      if ( v19 >= 0x1C )
      {
        v22 = v19 & 0xFFFFFFFFFFFFFFFCLL;
        if ( (v19 & 0xFFFFFFFFFFFFFFFCLL) != 0x1C )
        {
          *(_DWORD *)(v20 + 28) = v8;
          if ( v22 != 24 && (v19 & 0xFFFFFFFFFFFFFFFCLL) != 0x18 )
          {
            *(_DWORD *)(v20 + 24) = v13;
            if ( v19 >= 0x20 && (v19 & 0xFFFFFFFFFFFFFFFELL) != 0x20 )
            {
              *(_WORD *)(v20 + 32) = v11;
              if ( (v19 & 0xFFFFFFFFFFFFFFF8LL) != 0x10 )
              {
                v22 = v10;
                *(_QWORD *)(v20 + 16) = v10;
                if ( v19 >= 0x23 )
                {
                  v23 = *v9;
                  *(_BYTE *)(v20 + 34) = v29;
                  if ( *(__int64 **)(v23 + 8) != v9 || (__int64 *)v20 == v9 || v23 == v20 )
                  {
                    _list_add_valid_or_report(v20, v10 + 48);
                    v22 = v10;
                    goto LABEL_34;
                  }
                  *(_QWORD *)(v23 + 8) = v20;
                  *(_QWORD *)v20 = v23;
                  if ( (v19 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
                  {
                    *(_QWORD *)(v20 + 8) = v9;
                    *v9 = v20;
LABEL_34:
                    v24 = (_QWORD *)v22;
                    *(_BYTE *)(v22 + 64) |= 1u;
                    raw_spin_unlock_bh(v27);
                    cfg80211_mgmt_registrations_update(v24);
                    return 0;
                  }
                }
              }
            }
          }
        }
      }
      __break(1u);
    }
    _fortify_panic(17, v22);
LABEL_50:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(StatusReg + 80);
    v19 = v8 + 40LL;
    *(_QWORD *)(StatusReg + 80) = &cfg80211_mlme_register_mgmt__alloc_tag;
    v20 = _kmalloc_noprof(v19, 3520);
    *(_QWORD *)(StatusReg + 80) = v30;
    if ( !v20 )
      return 4294967284LL;
  }
  while ( 1 )
  {
    if ( *(unsigned __int16 *)(v14 + 32) == v11 )
    {
      v25 = *(_DWORD *)(v14 + 28);
      if ( v25 >= v8 )
        v25 = v8;
      v26 = bcmp((const void *)(v14 + 35), v21, v25);
      v21 = v12;
      if ( !v26 )
        break;
    }
    v14 = *(_QWORD *)v14;
    if ( (__int64 *)v14 == v9 )
      goto LABEL_18;
  }
  if ( *(unsigned __int8 *)(v14 + 34) != v29 )
  {
    *(_BYTE *)(v14 + 34) = v29;
    kfree(v20);
    v22 = v10;
    goto LABEL_34;
  }
  do_trace_netlink_extack("Match already configured");
  if ( v7 )
    *v7 = "Match already configured";
  kfree(v20);
  raw_spin_unlock_bh(v27);
  return 4294967182LL;
}
