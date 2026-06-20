__int64 __fastcall ieee80211_setup_assoc_link(__int64 result, __int64 a2, __int64 a3, _DWORD *a4, unsigned int a5)
{
  unsigned int ***v5; // x25
  unsigned int **v6; // x21
  __int64 v7; // x9
  __int64 v8; // x23
  __int64 v9; // x19
  __int64 v10; // x24
  __int64 v11; // x22
  __int64 v13; // x26
  size_t v14; // x2
  unsigned int **v16; // x8
  unsigned int **v17; // x9
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 lock; // x0
  unsigned int *v21; // x24
  unsigned __int8 *elem_match; // x20
  unsigned __int8 *v23; // x0
  unsigned __int8 v24; // w8
  __int64 v25; // x2
  __int64 v26; // x0
  char v27; // w8
  bool v28; // w8
  int v29; // w8
  const char *v30; // x9
  const char *v31; // x10
  const char *v32; // x3
  __int64 v33; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v34[14]; // [xsp+8h] [xbp-18h]
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 >= 0xF )
    goto LABEL_49;
  v5 = (unsigned int ***)(a2 + ((unsigned __int64)a5 << 6));
  v6 = *v5;
  if ( !*v5 )
  {
LABEL_48:
    __break(0x800u);
    goto LABEL_38;
  }
  v7 = **v6;
  if ( (unsigned int)v7 > 5 )
LABEL_49:
    __break(0x5512u);
  v8 = *(_QWORD *)(result + 1616);
  v9 = result;
  v10 = *(_QWORD *)(*(_QWORD *)(v8 + 72) + 8 * v7 + 328);
  if ( !v10 )
    goto LABEL_48;
  v11 = *(_QWORD *)(result + 8LL * a5 + 4568);
  if ( !v11 )
    goto LABEL_48;
  if ( !*(_QWORD *)(a3 + 784) )
  {
    *(_QWORD *)(a2 + 968) = (char *)v6 + 106;
    *(_BYTE *)(a2 + 976) = (unsigned __int8)v6[18];
  }
  v13 = a3 + 32LL * a5;
  v14 = *(_QWORD *)(v13 + 320);
  if ( v14 )
  {
    result = (__int64)memcpy(*(void **)(a2 + 1160), *(const void **)(v13 + 312), v14);
    v16 = *(unsigned int ***)(a2 + 1160);
    v5[5] = v16;
    v17 = *(unsigned int ***)(v13 + 320);
    v5[4] = v17;
    *(_QWORD *)(a2 + 1160) = (char *)v17 + (_QWORD)v16;
  }
  *(_BYTE *)(v11 + 840) = 0;
  *(_BYTE *)(v11 + 542) = 0;
  *(_BYTE *)(v11 + 563) = 0;
  if ( *a4 >= 2u )
  {
    v18 = *(_QWORD *)(v10 + 36);
    v19 = *(_QWORD *)(v10 + 42);
    v33 = *(_QWORD *)(v10 + 28);
    *(_QWORD *)v34 = v18;
    *(_QWORD *)&v34[6] = v19;
    result = ieee80211_apply_htcap_overrides(v9, (__int64)&v33);
  }
  lock = _rcu_read_lock(result, a2);
  v21 = v6[2];
  if ( !v21 )
  {
    v21 = v6[1];
    if ( !v21 )
      goto LABEL_32;
    goto LABEL_23;
  }
  elem_match = (unsigned __int8 *)cfg80211_find_elem_match(5, (char *)v21 + 29, v21[6], 0, 0, 0);
  v23 = (unsigned __int8 *)cfg80211_find_elem_match(85, (char *)v21 + 29, v21[6], 0, 0, 0);
  if ( !elem_match || elem_match[1] < 2u )
  {
    v24 = 0;
    *(_BYTE *)(v11 + 542) = 0;
    if ( !v23 )
      goto LABEL_20;
LABEL_18:
    if ( v23[1] >= 3u )
    {
      v24 = v23[4];
      *(_BYTE *)(v11 + 542) = v23[3];
    }
    goto LABEL_20;
  }
  v24 = elem_match[2];
  *(_BYTE *)(v11 + 542) = elem_match[3];
  if ( v23 )
    goto LABEL_18;
LABEL_20:
  *(_BYTE *)(v9 + 4179) = 1;
  if ( (*(_QWORD *)(v8 + 96) & 0x1000000) != 0 )
  {
    *(_QWORD *)(*(_QWORD *)(v11 + 944) + 56LL) = *(_QWORD *)v21;
    *(_DWORD *)(*(_QWORD *)(v11 + 944) + 64LL) = *((_DWORD *)v6 + 24);
    *(_BYTE *)(*(_QWORD *)(v11 + 944) + 68LL) = v24;
  }
LABEL_23:
  v25 = v21[6];
  LOBYTE(v33) = 55;
  v26 = cfg80211_find_elem_match(255, (char *)v21 + 29, v25, &v33, 1, 0);
  if ( v26 && *(unsigned __int8 *)(v26 + 1) >= 3u )
    v27 = *(_BYTE *)(v26 + 4);
  else
    v27 = 0;
  *(_BYTE *)(*(_QWORD *)(v11 + 944) + 314LL) = v27;
  lock = cfg80211_find_elem_match(127, (char *)v21 + 29, v21[6], 0, 0, 0);
  v28 = lock && *(unsigned __int8 *)(lock + 1) >= 0xBu && (*(_BYTE *)(lock + 12) & 8) != 0;
  *(_BYTE *)(*(_QWORD *)(v11 + 944) + 313LL) = v28;
LABEL_32:
  result = _rcu_read_unlock(lock);
  if ( *((_BYTE *)v6 + 166) )
  {
    v30 = "beacon and probe response";
    if ( (*((_BYTE *)v6 + 166) & 2) != 0 )
    {
      v31 = "probe response";
    }
    else
    {
      v30 = "beacon";
      v31 = "data";
    }
    if ( (*((_BYTE *)v6 + 166) & 1) != 0 )
      v32 = v30;
    else
      v32 = v31;
    result = printk(&unk_BA182, v9 + 1640, v6 + 9, v32);
    v29 = *(_DWORD *)(v11 + 544);
    if ( v29 )
      goto LABEL_37;
    goto LABEL_34;
  }
  v29 = *(_DWORD *)(v11 + 544);
  if ( !v29 )
  {
LABEL_34:
    if ( *(_BYTE *)(v9 + 2496) == 1 )
      v29 = 3;
    else
      v29 = 1;
  }
LABEL_37:
  *(_DWORD *)(v11 + 444) = v29;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
