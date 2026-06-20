__int64 __fastcall dp_get_avg_ul_jitter(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  unsigned int *v15; // x22
  unsigned int v17; // w8
  unsigned int v23; // w10
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // x8
  __int64 v43; // x20
  unsigned int v46; // w9
  __int64 v47; // x8

  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18928);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18928);
      *(_QWORD *)(a1 + 18936) |= 1uLL;
    }
    v15 = *(unsigned int **)(a1 + 8LL * a2 + 12912);
    if ( v15 )
    {
      _X24 = v15 + 10640;
      v17 = v15[10640];
      while ( v17 )
      {
        __asm { PRFM            #0x11, [X24] }
        while ( 1 )
        {
          v23 = __ldxr(_X24);
          if ( v23 != v17 )
            break;
          if ( !__stlxr(v17 + 1, _X24) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v23 == v17;
        v17 = v23;
        if ( _ZF )
        {
          _X8 = v15 + 10648;
          __asm { PRFM            #0x11, [X8] }
          do
            v46 = __ldxr(_X8);
          while ( __stxr(v46 + 1, _X8) );
          v47 = *(_QWORD *)(a1 + 18936);
          if ( (v47 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v47 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          *a3 = 1000 * v15[11326] / (1000 * v15[11327]);
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: uplink_jitter %u delay_accum %u pkts_accum %u",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "dp_get_avg_ul_jitter");
          dp_print_tsf_tx_delay_hist(v15 + 1226, 1);
          v15[11326] = 0;
          v15[11327] = 0;
          qdf_mem_set(v15 + 1226, 0x80u, 0);
          dp_vdev_unref_delete(a1, (__int64)v15, 7u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
          return 0;
        }
      }
    }
    v42 = *(_QWORD *)(a1 + 18936);
    if ( (v42 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v42 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  v43 = jiffies;
  if ( dp_get_avg_ul_jitter___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev %d does not exist", a4, a5, a6, a7, a8, a9, a10, a11, "dp_get_avg_ul_jitter", a2);
    dp_get_avg_ul_jitter___last_ticks = v43;
  }
  return 16;
}
