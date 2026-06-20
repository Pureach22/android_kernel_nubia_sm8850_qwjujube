__int64 __fastcall dp_rx_mlo_timestamp_ind_handler(__int64 result, unsigned __int8 *a2)
{
  _QWORD *v2; // x19
  int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x1
  unsigned int v14; // w21
  _BYTE *v15; // x8
  int v16; // w5
  __int64 v17; // x8
  __int64 v18; // x22
  unsigned __int64 StatusReg; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w8
  unsigned int v29; // w8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  __int64 v32; // x8

  if ( !result )
    return result;
  v2 = (_QWORD *)result;
  v4 = (*(_DWORD *)a2 >> 8) & 3;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(result + 40)) )
  {
    if ( v4 )
      v13 = (unsigned int)(v4 - 1);
    else
      v13 = 0;
    v14 = ((__int64 (__fastcall *)(_QWORD, __int64))wlan_cfg_get_hw_mac_idx)(v2[5], v13);
    if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(v2[5]) || !(unsigned __int8)wlan_cfg_get_pdev_idx(v2[5], v14) )
    {
      v15 = (_BYTE *)v2[9];
      if ( v15 )
      {
        if ( !*v15 )
          goto LABEL_18;
      }
    }
    return qdf_trace_msg(
             0x80u,
             8u,
             "%s: %pK: pdev id %d is invalid",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "dp_rx_mlo_timestamp_ind_handler",
             v2);
  }
  if ( v4 )
    v16 = v4 - 1;
  else
    v16 = 0;
  if ( v16 )
    return qdf_trace_msg(
             0x80u,
             8u,
             "%s: %pK: pdev id %d is invalid",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "dp_rx_mlo_timestamp_ind_handler",
             v2);
LABEL_18:
  v17 = v2[9];
  if ( !v17 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Invalid pdev",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "dp_rx_mlo_timestamp_ind_handler");
  v18 = v17 + 94208;
  dp_wdi_event_handler(296, v2, a2, 0xFFFF, 0xFFFFFFFFLL);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 2241);
  }
  else
  {
    raw_spin_lock_bh(v2 + 2241);
    v2[2242] |= 1uLL;
  }
  v28 = *(_DWORD *)(v18 + 2256) & 0xFFFFFC00 | *a2;
  *(_DWORD *)(v18 + 2256) = v28;
  v29 = v28 & 0xFFFFF0FF | *(_DWORD *)a2 & 0xC00;
  *(_DWORD *)(v18 + 2256) = v29;
  *(_DWORD *)(v18 + 2256) = (unsigned __int16)v29 | (*((unsigned __int16 *)a2 + 1) << 16);
  *(_DWORD *)(v18 + 2260) = *((_DWORD *)a2 + 1);
  *(_DWORD *)(v18 + 2264) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(v18 + 2268) = *((_DWORD *)a2 + 3);
  *(_DWORD *)(v18 + 2272) = *((_DWORD *)a2 + 4);
  *(_DWORD *)(v18 + 2276) = *((_DWORD *)a2 + 5);
  v30 = *(_QWORD *)(v18 + 2280) & 0xFFFFFFFFFFFF0000LL | *((unsigned __int16 *)a2 + 12);
  *(_QWORD *)(v18 + 2280) = v30;
  v31 = v30 & 0xFFFFFFFFFC00FFFFLL | ((((unsigned __int64)*((unsigned int *)a2 + 6) >> 16) & 0x3FF) << 16);
  *(_QWORD *)(v18 + 2280) = v31;
  *(_QWORD *)(v18 + 2280) = v31 & 0xFFC00000FFFFFFFFLL | ((*((_DWORD *)a2 + 7) & 0x3FFFFFLL) << 32);
  qdf_trace_msg(
    0x80u,
    8u,
    "%s: tsf_lo=%d tsf_hi=%d, mlo_ofst_lo=%d, mlo_ofst_hi=%d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "dp_rx_mlo_timestamp_ind_handler");
  v32 = v2[2242];
  if ( (v32 & 1) == 0 )
    return raw_spin_unlock(v2 + 2241);
  v2[2242] = v32 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v2 + 2241);
}
