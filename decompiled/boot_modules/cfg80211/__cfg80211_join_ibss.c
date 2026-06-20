__int64 __fastcall _cfg80211_join_ibss(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  _QWORD *v5; // x21
  __int64 v6; // x20
  __int64 result; // x0
  _QWORD *v8; // x21
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x8
  _QWORD *v13; // x0
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x9
  int v16; // w8
  __int64 v17; // x9
  int v18; // w12
  __int64 v19; // x10
  int v20; // w11
  __int64 i; // x13
  size_t v22; // x2
  const void **v23; // x8
  const void **v24; // x19
  size_t v25; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v27; // x2
  __int64 v28; // x8
  __int64 v29; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(a2 + 992);
  if ( (*(_BYTE *)(v6 + 440) & 1) != 0 )
    return 4294967280LL;
  if ( *(_BYTE *)(v6 + 356) )
    return 4294967182LL;
  if ( !*(_DWORD *)(a3 + 60) )
  {
    v15 = **(unsigned int **)(a3 + 16);
    if ( (v15 & 0xFFFFFFFD) == 1 )
      v16 = 2;
    else
      v16 = 4;
    if ( (unsigned int)v15 > 5 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        a1 = (_QWORD *)_traceiter_rdev_join_ibss(0, a1 + 124, a2, v4);
        v28 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v28;
        if ( !v28 || (a1 = v5, v27 = v4, !*(_QWORD *)(StatusReg + 16)) )
        {
          preempt_schedule_notrace(a1, a2, v27);
          a1 = v5;
        }
      }
      goto LABEL_12;
    }
    v17 = a1[v15 + 165];
    v18 = *(_DWORD *)(v17 + 24);
    if ( v18 >= 1 )
    {
      v19 = 0;
      v20 = 0;
      for ( i = 0; i < v18; ++i )
      {
        if ( (*(_DWORD *)(*(_QWORD *)(v17 + 8) + v19) & v16) != 0 )
        {
          v20 |= 1LL << i;
          *(_DWORD *)(a3 + 60) = v20;
          v18 = *(_DWORD *)(v17 + 24);
        }
        v19 += 12;
      }
    }
  }
  if ( a4 && (*(_DWORD *)(a4 + 212) & 0x80000000) != 0 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  v4 = a3;
  v8 = a1;
  if ( *(_QWORD *)(v6 + 88) )
  {
    __break(0x800u);
    v29 = a4;
    kfree_sensitive(*(_QWORD *)(v6 + 88));
    a4 = v29;
    a1 = v8;
    a3 = v4;
  }
  *(_QWORD *)(v6 + 88) = a4;
  v9 = *(_QWORD *)(a3 + 40);
  v10 = *(_QWORD *)(a3 + 16);
  v11 = *(_QWORD *)(a3 + 24);
  *(_QWORD *)(v6 + 304) = *(_QWORD *)(a3 + 32);
  *(_QWORD *)(v6 + 312) = v9;
  *(_QWORD *)(v6 + 288) = v10;
  *(_QWORD *)(v6 + 296) = v11;
  if ( a4 )
  {
    *(_QWORD *)(a3 + 152) = a4;
    *(_DWORD *)(a3 + 160) = *(_DWORD *)(a4 + 212);
  }
LABEL_12:
  v12 = *a1;
  v13 = a1 + 124;
  v14 = *(__int64 (__fastcall **)(_QWORD))(v12 + 392);
  if ( *((_DWORD *)v14 - 1) != 433503808 )
    __break(0x8228u);
  result = v14(v13);
  if ( (_DWORD)result )
  {
    *(_QWORD *)(v6 + 88) = 0;
  }
  else
  {
    v22 = *(unsigned __int8 *)(v4 + 56);
    v23 = (const void **)v4;
    if ( v22 >= 0x21 && (_cfg80211_join_ibss___already_done & 1) == 0 )
    {
      _cfg80211_join_ibss___already_done = 1;
      v25 = v22;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v22,
        "field \"wdev->u.ibss.ssid\" at ../soc-repo/net/wireless/ibss.c:150",
        0x20u);
      v22 = v25;
      v23 = (const void **)v4;
      __break(0x800u);
    }
    v24 = v23;
    memcpy((void *)(v6 + 324), *v23, v22);
    *(_BYTE *)(v6 + 356) = *((_BYTE *)v24 + 56);
    return 0;
  }
  return result;
}
