__int64 __fastcall rate_control_set_rates(__int64 a1, __int64 a2, char *a3)
{
  __int64 *v3; // x25
  __int64 v7; // x23
  __int64 v8; // x22
  __int64 lock; // x0
  unsigned int **v10; // x8
  __int64 v11; // x23
  __int64 v12; // x8
  __int64 v13; // x22
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned int v16; // w24
  unsigned int v17; // w23
  __int64 v18; // x0
  void (__fastcall *v19)(__int64, __int64, __int64); // x8
  unsigned int expected_throughput; // w0
  __int64 result; // x0
  __int64 v22; // x9
  __int64 v23; // x1
  unsigned __int64 StatusReg; // x23
  __int64 v25; // x0
  __int64 v26; // x8
  unsigned int v27; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v28[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v29; // [xsp+18h] [xbp-18h] BYREF
  __int16 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v3 = (__int64 *)(a2 - 2608);
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 - 2608);
  v8 = *(_QWORD *)(v7 + 1616);
  if ( *(_WORD *)(v7 + 5800) )
    __break(0x800u);
  lock = _rcu_read_lock(a1, a2);
  v10 = *(unsigned int ***)(v7 + 5640);
  if ( !v10 )
  {
    _rcu_read_unlock(lock);
    goto LABEL_28;
  }
  v11 = **v10;
  _rcu_read_unlock(lock);
  if ( (unsigned int)v11 >= 6 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v25 = _traceiter_drv_sta_rate_tbl_update(0, a1, v8, a2);
      v26 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v26;
      if ( !v26 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v25);
    }
    goto LABEL_22;
  }
  v12 = *(_QWORD *)(v8 + 72) + 8 * v11;
  v13 = *(_QWORD *)(v12 + 328);
  if ( !v13 )
  {
LABEL_28:
    result = 4294967274LL;
    goto LABEL_29;
  }
  v14 = *v3;
  v15 = *(_QWORD *)(v12 + 328);
  v27 = 0;
  v30 = 0;
  v28[1] = 0;
  v29 = 0;
  v28[0] = 0;
  if ( (rate_control_cap_mask(v14, v15, a2, &v27, &v29, v28) & 1) != 0 && (a3[16] & 0x80000000) == 0 )
  {
    v16 = v27;
    v17 = *(_DWORD *)(*v3 + 4952);
    rate_idx_match_mask(a3 + 16, a3 + 20, v13, v17, v27, &v29, v28);
    if ( (a3[22] & 0x80000000) == 0 )
    {
      rate_idx_match_mask(a3 + 22, a3 + 26, v13, v17, v16, &v29, v28);
      if ( (a3[28] & 0x80000000) == 0 )
      {
        rate_idx_match_mask(a3 + 28, a3 + 32, v13, v17, v16, &v29, v28);
        if ( (a3[34] & 0x80000000) == 0 )
          rate_idx_match_mask(a3 + 34, a3 + 38, v13, v17, v16, &v29, v28);
      }
    }
  }
  v18 = *(_QWORD *)(a2 + 16);
  atomic_store((unsigned __int64)a3, (unsigned __int64 *)(a2 + 16));
  a3 = (char *)(a2 - 2688);
  if ( v18 )
    kvfree_call_rcu(v18, v18);
  if ( *(_BYTE *)(a2 - 2484) != 1 )
    goto LABEL_26;
  v8 = *v3;
  if ( *v3 && *(_DWORD *)(v8 + 4720) == 4 )
    v8 = *(_QWORD *)(v8 + 2032) - 2264LL;
  if ( (*(_BYTE *)(*(_QWORD *)(v8 + 1616) + 1471LL) & 1) != 0
    || (*(_DWORD *)(v8 + 1624) & 0x20) != 0
    || (drv_sta_rate_tbl_update___already_done_0 & 1) != 0 )
  {
    if ( (*(_BYTE *)(v8 + 1624) & 0x20) != 0 )
      goto LABEL_22;
  }
  else
  {
    v22 = *(_QWORD *)(v8 + 1608);
    drv_sta_rate_tbl_update___already_done_0 = 1;
    if ( v22 )
      v23 = v22 + 296;
    else
      v23 = v8 + 1640;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v23);
    __break(0x800u);
    if ( (*(_BYTE *)(v8 + 1624) & 0x20) != 0 )
    {
LABEL_22:
      v19 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 464) + 320LL);
      if ( v19 )
      {
        if ( *((_DWORD *)v19 - 1) != -1656504592 )
          __break(0x8228u);
        v19(a1, v8 + 4720, a2);
      }
    }
  }
LABEL_26:
  expected_throughput = sta_get_expected_throughput(a3);
  ieee80211_sta_set_expected_throughput(a2, expected_throughput);
  result = 0;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
