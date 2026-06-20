__int64 __fastcall wlan_hdd_set_txq_params(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  __int64 v15; // x7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  unsigned int v25; // w9
  __int64 v26; // x0
  unsigned int v27; // w8
  unsigned __int8 v28; // w10
  bool v29; // cc
  int v30; // w9
  unsigned __int8 v31; // w11
  int v32; // w10
  __int64 v33; // x8
  int v34; // w10
  char v35; // w9
  char v36; // w9
  __int64 v37; // x8
  unsigned int updated; // w19
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v48[2]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v49; // [xsp+12h] [xbp-Eh]
  char v50; // [xsp+14h] [xbp-Ch]
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  result = _osif_vdev_sync_op_start(a2, &v47, "wlan_hdd_set_txq_params");
  if ( (_DWORD)result )
    goto LABEL_22;
  v14 = *(_QWORD *)(a2 + 2712);
  v50 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "__wlan_hdd_set_txq_params");
  if ( (unsigned int)_wlan_hdd_validate_context(v14, "__wlan_hdd_set_txq_params") )
    goto LABEL_3;
  v25 = *((unsigned __int16 *)a3 + 3);
  v26 = *(_QWORD *)(v14 + 16);
  if ( v25 - 1024 <= 0xFFFFFC00 )
  {
    v25 = 15;
    *((_WORD *)a3 + 3) = 15;
  }
  v27 = *((unsigned __int16 *)a3 + 4);
  if ( v27 < v25 || v27 >= 0x400 )
  {
    v27 = 1023;
    *((_WORD *)a3 + 4) = 1023;
  }
  v28 = 0;
  do
  {
    v29 = v25 > 1;
    ++v28;
    v25 >>= 1;
  }
  while ( v29 );
  v30 = v28;
  v31 = 0;
  if ( v28 >= 0xFu )
    v30 = 15;
  if ( v27 )
  {
    do
    {
      v29 = v27 > 1;
      ++v31;
      v27 >>= 1;
    }
    while ( v29 );
  }
  if ( v31 >= 0xFu )
    v32 = 15;
  else
    v32 = v31;
  v33 = *a3;
  v49 = *((_WORD *)a3 + 2);
  v34 = v30 | (16 * v32);
  v35 = *((_BYTE *)a3 + 10);
  v48[1] = v34;
  if ( (unsigned int)v33 < 4 )
  {
    v36 = v35 & 0xF | (32 * (_wlan_hdd_set_txq_params_ieee_ac_to_qca_ac[v33] & 3));
    v37 = *(_QWORD *)(a2 + 55520);
    v48[0] = v36;
    if ( v37 )
    {
      updated = sme_update_session_txq_edca_params(v26, *(unsigned __int8 *)(v37 + 8), v48);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v39, v40, v41, v42, v43, v44, v45, v46, "__wlan_hdd_set_txq_params");
      v24 = qdf_status_to_os_return(updated);
      goto LABEL_21;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: invalid link_info",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "__wlan_hdd_set_txq_params");
LABEL_3:
    v24 = -22;
LABEL_21:
    _osif_vdev_sync_op_stop(v47, "wlan_hdd_set_txq_params");
    result = v24;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  *(_DWORD *)(v15 - 120) = a2;
  *(_DWORD *)(v15 - 116) = v34;
  return wlan_hdd_cfg80211_set_mon_ch(v26);
}
