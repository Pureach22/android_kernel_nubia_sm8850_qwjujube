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
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  const char *v16; // x2
  __int64 v18; // x21
  unsigned __int64 StatusReg; // x8
  unsigned int v20; // w8
  __int64 v21; // x9
  unsigned int v22; // w21
  __int64 v23; // x22
  __int64 v24; // x23
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  __int64 v35; // x21
  unsigned int multiplier; // w0

  if ( !a1 )
  {
    v16 = "%s: pdev object for CFR is null";
    return qdf_trace_msg(0x6Au, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "lut_ageout_timer_task");
  }
  v9 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    v16 = "%s: pdev is null";
    return qdf_trace_msg(0x6Au, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "lut_ageout_timer_task");
  }
  ref = wlan_objmgr_pdev_try_get_ref(*(_QWORD *)a1, 0x30u, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)ref )
  {
    v18 = ktime_get(ref, v12, v13, v14, v15);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1704);
      v20 = *(_DWORD *)(a1 + 80);
      if ( !v20 )
        goto LABEL_21;
    }
    else
    {
      raw_spin_lock_bh(a1 + 1704);
      *(_QWORD *)(a1 + 1712) |= 1uLL;
      v20 = *(_DWORD *)(a1 + 80);
      if ( !v20 )
        goto LABEL_21;
    }
    v21 = (unsigned __int128)(v18 * (__int128)0x431BDE82D7B634DBLL) >> 64;
    v22 = 0;
    v23 = (v21 >> 18) + ((unsigned __int64)v21 >> 63);
    do
    {
      v24 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (int)v22);
      if ( v24
        && *(_BYTE *)v24 == 1
        && (*(_BYTE *)(v24 + 1) & 1) == 0
        && (unsigned __int64)(v23 - *(_QWORD *)(v24 + 216)) >= 0xBB9 )
      {
        target_if_dbr_buf_release(v9, 1u, *(_QWORD *)(v24 + 24), v22, 0);
        ++*(_QWORD *)(a1 + 1408);
        *(_WORD *)v24 = 0;
        *(_QWORD *)(v24 + 8) = 0;
        *(_QWORD *)(v24 + 16) = 0;
        *(_QWORD *)(v24 + 24) = 0;
        *(_QWORD *)(v24 + 32) = 0;
        *(_QWORD *)(v24 + 208) = 0;
        *(_QWORD *)(v24 + 216) = 0;
        qdf_mem_set((void *)(v24 + 40), 0xA0u, 0);
        v20 = *(_DWORD *)(a1 + 80);
      }
      ++v22;
    }
    while ( v22 < v20 );
LABEL_21:
    v25 = *(_QWORD *)(a1 + 1712);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1712) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1704);
      v34 = (unsigned int *)*(unsigned __int8 *)(a1 + 1384);
      if ( !*(_BYTE *)(a1 + 1384) )
        return wlan_objmgr_pdev_release_ref(v9, 0x30u, v34, v26, v27, v28, v29, v30, v31, v32, v33);
    }
    else
    {
      raw_spin_unlock(a1 + 1704);
      v34 = (unsigned int *)*(unsigned __int8 *)(a1 + 1384);
      if ( !*(_BYTE *)(a1 + 1384) )
        return wlan_objmgr_pdev_release_ref(v9, 0x30u, v34, v26, v27, v28, v29, v30, v31, v32, v33);
    }
    v35 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    mod_timer(a1 + 1328, v35 + 750LL * multiplier);
    return wlan_objmgr_pdev_release_ref(v9, 0x30u, v34, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  v16 = "%s: failed to get pdev reference";
  return qdf_trace_msg(0x6Au, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "lut_ageout_timer_task");
}
