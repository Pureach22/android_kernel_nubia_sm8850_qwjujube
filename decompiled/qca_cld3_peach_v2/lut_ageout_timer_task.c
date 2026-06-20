__int64 __fastcall lut_ageout_timer_task(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 ref; // x0
  const char *v12; // x2
  __int64 v14; // x21
  unsigned __int64 StatusReg; // x8
  unsigned int v16; // w8
  __int64 v17; // x9
  unsigned int v18; // w21
  __int64 v19; // x22
  __int64 v20; // x23
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  __int64 v31; // x21
  unsigned int multiplier; // w0

  if ( !a1 )
  {
    v12 = "%s: pdev object for CFR is null";
    return qdf_trace_msg(0x6Au, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "lut_ageout_timer_task");
  }
  v9 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    v12 = "%s: pdev is null";
    return qdf_trace_msg(0x6Au, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "lut_ageout_timer_task");
  }
  ref = wlan_objmgr_pdev_try_get_ref(*(_QWORD *)a1, 0x30u, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)ref )
  {
    v14 = ktime_get(ref);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1704);
      v16 = *(_DWORD *)(a1 + 80);
      if ( !v16 )
        goto LABEL_21;
    }
    else
    {
      raw_spin_lock_bh(a1 + 1704);
      *(_QWORD *)(a1 + 1712) |= 1uLL;
      v16 = *(_DWORD *)(a1 + 80);
      if ( !v16 )
        goto LABEL_21;
    }
    v17 = (unsigned __int128)(v14 * (__int128)0x431BDE82D7B634DBLL) >> 64;
    v18 = 0;
    v19 = (v17 >> 18) + ((unsigned __int64)v17 >> 63);
    do
    {
      v20 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (int)v18);
      if ( v20
        && *(_BYTE *)v20 == 1
        && (*(_BYTE *)(v20 + 1) & 1) == 0
        && (unsigned __int64)(v19 - *(_QWORD *)(v20 + 216)) >= 0xBB9 )
      {
        target_if_dbr_buf_release(v9, 1u, *(_QWORD *)(v20 + 24), v18, 0);
        ++*(_QWORD *)(a1 + 1408);
        *(_WORD *)v20 = 0;
        *(_QWORD *)(v20 + 8) = 0;
        *(_QWORD *)(v20 + 16) = 0;
        *(_QWORD *)(v20 + 24) = 0;
        *(_QWORD *)(v20 + 32) = 0;
        *(_QWORD *)(v20 + 208) = 0;
        *(_QWORD *)(v20 + 216) = 0;
        qdf_mem_set((void *)(v20 + 40), 0xA0u, 0);
        v16 = *(_DWORD *)(a1 + 80);
      }
      ++v18;
    }
    while ( v18 < v16 );
LABEL_21:
    v21 = *(_QWORD *)(a1 + 1712);
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1712) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1704);
      v30 = (unsigned int *)*(unsigned __int8 *)(a1 + 1384);
      if ( !*(_BYTE *)(a1 + 1384) )
        return wlan_objmgr_pdev_release_ref(v9, 0x30u, v30, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    else
    {
      raw_spin_unlock(a1 + 1704);
      v30 = (unsigned int *)*(unsigned __int8 *)(a1 + 1384);
      if ( !*(_BYTE *)(a1 + 1384) )
        return wlan_objmgr_pdev_release_ref(v9, 0x30u, v30, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    v31 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    mod_timer(a1 + 1328, v31 + 750LL * multiplier);
    return wlan_objmgr_pdev_release_ref(v9, 0x30u, v30, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  v12 = "%s: failed to get pdev reference";
  return qdf_trace_msg(0x6Au, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "lut_ageout_timer_task");
}
