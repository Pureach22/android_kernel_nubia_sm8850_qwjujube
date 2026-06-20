__int64 __fastcall tx_power_boost_mmap(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10)
{
  _QWORD *context; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  __int64 v30; // x22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x20
  unsigned int v40; // w19
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // [xsp+0h] [xbp-10h] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  context = _cds_get_context(51, (__int64)"tx_power_boost_mmap", a1, a2, a3, a4, a5, a6, a7, a8);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"tx_power_boost_mmap",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19);
  if ( !(_DWORD)result )
  {
    result = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v49, (__int64)"tx_power_boost_mmap");
    if ( !(_DWORD)result )
    {
      v30 = *a10;
      v29 = a10[1];
      if ( wlan_hdd_validate_modules_state((__int64)context, v21, v22, v23, v24, v25, v26, v27, v28) )
      {
        if ( v29 - v30 <= (unsigned __int64)*((unsigned int *)context + 2152) )
        {
          v40 = remap_pfn_range(
                  a10,
                  *a10,
                  (__int64)(((__int64)memstart_addr >> 12 << 6)
                          + ((unsigned __int64)(((__int64)((a10[10] << 20) + (context[1072] << 8)) >> 8) + 0x8000000000LL) >> 6)) >> 6,
                  v29 - v30,
                  a10[3]);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: TPB: mmap for %zu bytes success",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "__tx_power_boost_mmap",
            v29 - v30,
            v49,
            v50);
          goto LABEL_9;
        }
        v39 = jiffies;
        if ( _tx_power_boost_mmap___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: TPB: mmap size check failed (%lu %u)",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__tx_power_boost_mmap",
            v29 - v30,
            v49,
            v50);
          _tx_power_boost_mmap___last_ticks = v39;
        }
      }
      v40 = -22;
LABEL_9:
      _osif_psoc_sync_op_stop(v49, (__int64)"tx_power_boost_mmap");
      result = v40;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
