__int64 __fastcall dp_rx_err_exception(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w4
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x10
  unsigned int v16; // w10
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  __int64 v26; // x8
  void (__fastcall *v27)(__int64, __int64 *); // x8
  unsigned __int8 *v28; // x21
  __int64 (__fastcall *v29)(_QWORD); // x8
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x9
  unsigned __int64 v35; // x23
  unsigned __int64 v36; // x8
  __int64 v37; // x23
  __int64 v38; // x8
  unsigned int v39; // w20
  __int64 result; // x0
  __int64 v41; // x8
  unsigned __int8 v42; // w9
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 v45; // x0
  __int64 v46; // [xsp+8h] [xbp-18h] BYREF
  __int64 v47; // [xsp+10h] [xbp-10h]
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v12 = *(_DWORD *)(a1 + 14072) + 1, *(_DWORD *)(a1 + 14072) = v12, v12 >= 0x15) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: pkt threshold breached! reo_err_msdu_buf_rcved %u first err pkt time_stamp %llu",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_rx_err_exception");
    _qdf_trigger_self_recovery();
  }
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  if ( 10 * StatusReg >= StatusReg )
    v14 = 10 * StatusReg / 0xC0;
  else
    v14 = 10 * (StatusReg / 0xC0);
  v15 = *(_QWORD *)(a1 + 17536);
  if ( !v15 )
  {
    v15 = v14;
    *(_QWORD *)(a1 + 17536) = v14;
  }
  if ( v14 - v15 < 0x4C4B41 )
  {
    v25 = *(_DWORD *)(a1 + 17544) + 1;
  }
  else
  {
    v16 = *(_DWORD *)(a1 + 17544);
    *(_QWORD *)(a1 + 17536) = v14;
    if ( v16 >= 0xB )
    {
      _qdf_trigger_self_recovery();
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: rate threshold breached! reo_err_msdu_buf_rcved %u first err pkt time_stamp %llu",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "dp_rx_err_exception",
        *(unsigned int *)(a1 + 14072),
        *(_QWORD *)(a1 + 17536));
      goto LABEL_15;
    }
    v25 = 1;
  }
  *(_DWORD *)(a1 + 17544) = v25;
LABEL_15:
  v26 = *(_QWORD *)(a1 + 1128);
  v46 = 0;
  v47 = 0;
  v27 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v26 + 74392) + 1464LL);
  if ( v27 )
  {
    if ( *((_DWORD *)v27 - 1) != 1721787685 )
      __break(0x8228u);
    v27(a2, &v46);
    LOWORD(v27) = v47;
    if ( (v47 & 0xF0000) != 0 )
      goto LABEL_38;
  }
  v28 = (unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 12392) + 8LL * BYTE1(v27))
                          + (unsigned __int8)v27 * (unsigned int)*(unsigned __int16 *)(a1 + 12372));
  if ( !v28 )
  {
LABEL_38:
    if ( a1 )
    {
      result = 0xFFFFFFFFLL;
      ++*(_DWORD *)(a1 + 14076);
LABEL_44:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_40:
    result = 0xFFFFFFFFLL;
    goto LABEL_44;
  }
  if ( !*(_QWORD *)v28 )
    goto LABEL_40;
  v29 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1440LL);
  if ( *((_DWORD *)v29 - 1) != 1690911915 )
    __break(0x8228u);
  v30 = v29(a2);
  v34 = 80;
  if ( (*(_BYTE *)(*(_QWORD *)v28 + 68LL) & 4) == 0 )
    v34 = 40;
  if ( v46 != *(_QWORD *)(*(_QWORD *)v28 + v34) )
  {
    if ( a1 )
      ++*(_DWORD *)(a1 + 14108);
    result = 0xFFFFFFFFLL;
    v28[30] |= 4u;
    goto LABEL_44;
  }
  v35 = v28[28];
  if ( v35 < 5 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v36 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v36 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18464);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18464);
      *(_QWORD *)(a1 + 18472) |= 1uLL;
    }
    v37 = a1 + 120LL * (unsigned int)v35;
    if ( (v28[30] & 2) != 0 )
    {
      v45 = printk(
              &unk_9BB309,
              "!rx_desc->unmapped",
              "dp_rx_err_handle_msdu_buf",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
      dump_stack(v45);
    }
    dp_rx_nbuf_unmap_pool(a1, v37 + 12368, *(_QWORD *)v28);
    v28[30] |= 2u;
    v38 = *(_QWORD *)(a1 + 18472);
    if ( (v38 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18472) = v38 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18464);
    }
    else
    {
      raw_spin_unlock(a1 + 18464);
    }
    dp_rx_buffer_pool_nbuf_free(a1, *(_QWORD *)v28, v28[28]);
    v39 = v28[28];
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v39) )
    {
      result = v28[28];
    }
    else
    {
      v41 = *(_QWORD *)(a1 + 72);
      result = v28[28];
      if ( v41 )
      {
        v42 = v28[30];
        *(_QWORD *)v28 = 0;
        v43 = v41 + 94208;
        v28[30] = v42 & 0xFE;
        *(_QWORD *)v28 = *(_QWORD *)(v43 + 1016);
        v44 = *(_QWORD *)(v43 + 1024);
        *(_QWORD *)(v43 + 1016) = v28;
        if ( !v44 || !*(_QWORD *)v28 )
          *(_QWORD *)(v43 + 1024) = v28;
      }
    }
    goto LABEL_44;
  }
  __break(0x5512u);
  return dp_rx_err_process(v30, v31, v32, v33);
}
