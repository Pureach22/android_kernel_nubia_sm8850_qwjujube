__int64 __fastcall dp_process_lmac_rings(__int64 a1, int a2)
{
  __int64 v4; // x22
  char dp_soc_rxdma_refill_lt_disable; // w23
  char dp_soc_rxdma_scan_radio_refill_lt_disable; // w24
  __int64 v7; // x27
  char v8; // w8
  char v9; // w26
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x28
  int v19; // w19
  __int64 v20; // x8
  _DWORD *v21; // x8
  int v22; // w0
  const char *v23; // x2
  __int64 v24; // x8
  __int64 v25; // x8
  _DWORD *v26; // x8
  int v27; // w0
  const char *v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  _DWORD *v38; // x8
  int v39; // w0
  const char *v40; // x2
  int v41; // w0
  unsigned __int64 v42; // x8
  char v43; // w9
  __int64 v44; // x8
  __int64 v45; // x8
  void (__fastcall *v46)(_QWORD); // x8
  const char *v47; // x2
  __int64 v48; // x8
  __int64 v49; // x8
  void (__fastcall *v50)(_QWORD); // x8
  const char *v51; // x2
  int v53; // [xsp+0h] [xbp-40h]
  int v54; // [xsp+14h] [xbp-2Ch]
  __int64 v55; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v56[2]; // [xsp+30h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  dp_soc_rxdma_refill_lt_disable = wlan_cfg_get_dp_soc_rxdma_refill_lt_disable(*(_QWORD *)(v4 + 40));
  dp_soc_rxdma_scan_radio_refill_lt_disable = wlan_cfg_get_dp_soc_rxdma_scan_radio_refill_lt_disable(*(_QWORD *)(v4 + 40));
  v7 = 0;
  v54 = a2;
  v8 = 1;
  do
  {
    v9 = v8;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v4 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v4 + 40), (unsigned int)v7) )
    {
      goto LABEL_2;
    }
    v18 = *(_QWORD *)(v4 + 72);
    if ( !v18 )
      goto LABEL_2;
    v19 = 1 << v7;
    if ( ((1 << v7) & *(unsigned __int8 *)(a1 + 2)) != 0 )
    {
      v20 = *(_QWORD *)(v4 + 20112);
      if ( v20 )
      {
        v21 = *(_DWORD **)(v20 + 432);
        if ( v21 )
        {
          if ( *(v21 - 1) != 208847759 )
            __break(0x8228u);
          v22 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v21)(
                  v4,
                  a1,
                  (unsigned int)v7,
                  (unsigned int)a2);
          if ( v22 )
            ++*(_DWORD *)(a1 + 88);
LABEL_16:
          a2 -= v22;
          if ( a2 < 1 )
            goto LABEL_71;
          goto LABEL_17;
        }
        v23 = "%s: callback not registered";
      }
      else
      {
        v23 = "%s: monitor soc is NULL";
      }
      qdf_trace_msg(0x92u, 8u, v23, v10, v11, v12, v13, v14, v15, v16, v17, "dp_monitor_process");
      v22 = 0;
      goto LABEL_16;
    }
LABEL_17:
    if ( ((unsigned __int8)v19 & *(_BYTE *)(a1 + 13)) == 0 )
      goto LABEL_29;
    v24 = *(_QWORD *)(v4 + 20112);
    if ( !v24 )
    {
      v28 = "%s: monitor soc is NULL";
      goto LABEL_27;
    }
    v25 = *(_QWORD *)(v24 + 416);
    if ( !v25 || (v26 = *(_DWORD **)(v25 + 256)) == nullptr )
    {
      v28 = "%s: callback not registered";
LABEL_27:
      qdf_trace_msg(0x92u, 8u, v28, v10, v11, v12, v13, v14, v15, v16, v17, "dp_tx_mon_process");
      v27 = 0;
      goto LABEL_28;
    }
    if ( *(v26 - 1) != 208847759 )
      __break(0x8228u);
    v27 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v26)(v4, a1, (unsigned int)v7, (unsigned int)a2);
    if ( v27 )
      ++*(_DWORD *)(a1 + 188);
LABEL_28:
    a2 -= v27;
    if ( a2 < 1 )
      goto LABEL_71;
LABEL_29:
    if ( ((unsigned __int8)v19 & *(_BYTE *)(a1 + 6)) != 0 )
    {
      if ( (unsigned int)hal_get_target_type(*(_QWORD *)(v4 + 1128)) == 36 )
      {
        v37 = *(_QWORD *)(v4 + 20112);
        if ( v37 )
        {
          v38 = *(_DWORD **)(v37 + 432);
          if ( v38 )
          {
            if ( *(v38 - 1) != 208847759 )
              __break(0x8228u);
            v39 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v38)(
                    v4,
                    a1,
                    (unsigned int)v7,
                    (unsigned int)a2);
            if ( !v39 )
            {
LABEL_42:
              a2 -= v39;
              if ( a2 < 1 )
                goto LABEL_71;
              goto LABEL_43;
            }
LABEL_38:
            ++*(_DWORD *)(a1 + 104);
            goto LABEL_42;
          }
          v40 = "%s: callback not registered";
        }
        else
        {
          v40 = "%s: monitor soc is NULL";
        }
        qdf_trace_msg(0x92u, 8u, v40, v29, v30, v31, v32, v33, v34, v35, v36, "dp_monitor_process");
        v39 = 0;
        goto LABEL_42;
      }
      v39 = dp_rxdma_err_process(a1, v4, (unsigned int)v7, (unsigned int)a2);
      if ( !v39 )
        goto LABEL_42;
      goto LABEL_38;
    }
LABEL_43:
    if ( ((unsigned __int8)v19 & *(_BYTE *)(a1 + 7)) != 0 )
    {
      v41 = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v4 + 40));
      v42 = v7;
      if ( !v41 )
      {
        v42 = *(unsigned __int8 *)(v18 + 1);
        if ( v42 > 1 )
          __break(0x5512u);
      }
      ++*(_DWORD *)(a1 + 108);
      if ( *(_BYTE *)(v4 + 20276) )
        v43 = dp_soc_rxdma_scan_radio_refill_lt_disable;
      else
        v43 = dp_soc_rxdma_refill_lt_disable;
      if ( (v43 & 1) == 0 )
      {
        v55 = 0;
        v56[0] = 0;
        LOBYTE(v53) = 0;
        _dp_rx_buffers_replenish(
          v4,
          (unsigned int)v7,
          v4 + 80 + 80 * v42,
          v4 + 12416 + 120 * v7,
          0,
          v56,
          &v55,
          0,
          v53,
          "dp_rx_buffers_lt_replenish_simple");
      }
    }
LABEL_2:
    v8 = 0;
    v7 = 1;
  }
  while ( (v9 & 1) != 0 );
  if ( !*(_BYTE *)(a1 + 8) )
    goto LABEL_61;
  v44 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 20112LL);
  if ( !v44 )
  {
    v47 = "%s: monitor soc is NULL";
    goto LABEL_60;
  }
  v45 = *(_QWORD *)(v44 + 416);
  if ( !v45 || (v46 = *(void (__fastcall **)(_QWORD))(v45 + 912)) == nullptr )
  {
    v47 = "%s: callback not registered";
LABEL_60:
    qdf_trace_msg(0x92u, 8u, v47, v10, v11, v12, v13, v14, v15, v16, v17, "dp_rx_mon_buf_refill");
    goto LABEL_61;
  }
  if ( *((_DWORD *)v46 - 1) != -462836955 )
    __break(0x8228u);
  v46(a1);
LABEL_61:
  if ( *(_BYTE *)(a1 + 12) )
  {
    v48 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 20112LL);
    if ( v48 )
    {
      v49 = *(_QWORD *)(v48 + 416);
      if ( v49 )
      {
        v50 = *(void (__fastcall **)(_QWORD))(v49 + 920);
        if ( v50 )
        {
          if ( *((_DWORD *)v50 - 1) != -462836955 )
            __break(0x8228u);
          v50(a1);
          goto LABEL_71;
        }
      }
      v51 = "%s: callback not registered";
    }
    else
    {
      v51 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v51, v10, v11, v12, v13, v14, v15, v16, v17, "dp_tx_mon_buf_refill");
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v54 - a2);
}
