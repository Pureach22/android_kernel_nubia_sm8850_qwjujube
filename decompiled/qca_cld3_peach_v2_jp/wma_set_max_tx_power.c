__int64 __fastcall wma_set_max_tx_power(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 *v33; // x23
  unsigned __int16 *active_channel; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  char channel_reg_power_for_freq; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  char v52; // w9
  char v53; // w21
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 result; // x0
  unsigned __int8 v79[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v80; // [xsp+8h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *((_DWORD *)a2 + 4);
  v79[0] = 0;
  if ( (v12 | 2) == 3 )
  {
    if ( (unsigned int)wma_find_vdev_id_by_addr((__int64)a1, (__int64)a2, v79) )
    {
LABEL_3:
      if ( a2 )
      {
        v21 = *a2;
        v22 = a2[1];
        v23 = a2[2];
        v24 = a2[5];
      }
      else
      {
        v23 = 0;
        v21 = 0;
        v22 = 0;
        v24 = 0;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: vdev id is invalid for %02x:%02x:%02x:**:**:%02x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_set_max_tx_power",
        v21,
        v22,
        v23,
        v24);
      goto LABEL_20;
    }
  }
  else if ( (unsigned int)wma_find_vdev_id_by_bssid((__int64)a1, (__int64)a2, v79, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    goto LABEL_3;
  }
  if ( (wma_is_vdev_up(v79[0]) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id %d is not up",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_set_max_tx_power",
      v79[0]);
LABEL_20:
    result = _qdf_mem_free((__int64)a2);
    goto LABEL_21;
  }
  v33 = (__int64 *)(a1[65] + 488LL * v79[0]);
  active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(*v33);
  if ( !active_channel )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get active channel",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wma_set_max_tx_power");
    goto LABEL_20;
  }
  channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                 *(_QWORD *)(a1[2] + 21560),
                                 *active_channel,
                                 v35,
                                 v36,
                                 v37,
                                 v38,
                                 v39,
                                 v40,
                                 v41,
                                 v42);
  v52 = channel_reg_power_for_freq;
  if ( (char)a2[12] < channel_reg_power_for_freq )
    v52 = a2[12];
  if ( a2[12] )
    v53 = v52;
  else
    v53 = channel_reg_power_for_freq;
  qdf_trace_msg(0x36u, 8u, "TXP[W][set_max_pwr_req]: %d", v44, v45, v46, v47, v48, v49, v50, v51, (unsigned int)v53);
  if ( !(unsigned int)wma_vdev_set_param(*a1, v79[0], 0x38u, v53, v54, v55, v56, v57, v58, v59, v60, v61) )
  {
    mlme_set_tx_power(*v33, v53, v62, v63, v64, v65, v66, v67, v68, v69);
    goto LABEL_20;
  }
  _qdf_mem_free((__int64)a2);
  result = qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to set vdev param wmi_vdev_param_tx_pwrlimit",
             v70,
             v71,
             v72,
             v73,
             v74,
             v75,
             v76,
             v77,
             "wma_set_max_tx_power");
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
