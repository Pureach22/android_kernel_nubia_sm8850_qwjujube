__int64 __fastcall rrm_process_link_measurement_request(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x25
  __int64 cmpt_obj; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x24
  _BYTE *v35; // x26
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w23
  __int64 result; // x0
  unsigned __int8 max_tx_power; // w0
  unsigned int v47; // w8
  int v48; // w26
  unsigned int v49; // w4
  __int64 tx_ops; // x0
  void (__fastcall *v51)(__int64, __int64, __int64); // x8
  __int64 v52; // x0
  __int64 v53; // x1
  __int64 v54; // x27
  char v55; // w8
  int v56; // w22
  __int64 v57; // x24
  char v58; // w8
  char v59; // w9
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  _QWORD v68[2]; // [xsp+0h] [xbp-10h] BYREF

  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE5(v68[0]) = 0;
  *(_DWORD *)((char *)v68 + 1) = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Received Link measurement request",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "rrm_process_link_measurement_request");
  if ( !a2 || !a3 || !a4 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid parameters - Ignoring the request",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "rrm_process_link_measurement_request");
    result = 16;
    goto LABEL_43;
  }
  v24 = *(_QWORD *)(a2 + 16);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a4 + 16), v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev component object is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "rrm_process_link_measurement_request");
    result = 4;
    goto LABEL_43;
  }
  v34 = cmpt_obj;
  v35 = (_BYTE *)(a4 + 7032);
  if ( (wlan_reg_is_ext_tpc_supported(*(_QWORD *)(a1 + 21624), v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0
    && (*(_BYTE *)(a4 + 10070) & 1) == 0 )
  {
    v48 = *(unsigned __int8 *)(v34 + 568);
    *(_BYTE *)(v34 + 568) = *(_BYTE *)(a3 + 4);
    *(_BYTE *)(v34 + 948) = 1;
    lim_calculate_tpc(a1, a4, 0, v36, v37, v38, v39, v40, v41, v42, v43);
    v49 = *(_DWORD *)(v34 + 132);
    v44 = (unsigned __int8)*(_WORD *)(v34 + 656);
    BYTE1(v68[0]) = *(_WORD *)(v34 + 656);
    if ( v49 )
    {
      if ( v49 < v44 )
        LOBYTE(v44) = v49;
      BYTE1(v68[0]) = v44;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: HW power limit: %d, Link tx power: %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "rrm_process_link_measurement_request");
    }
    if ( (unsigned __int8)v44 >= 8u )
    {
      if ( (unsigned __int8)v44 < 0x19u )
        goto LABEL_27;
      LOBYTE(v44) = 24;
    }
    else
    {
      LOBYTE(v44) = 8;
    }
    BYTE1(v68[0]) = v44;
LABEL_27:
    if ( *(unsigned __int8 *)(a3 + 4) != v48 )
    {
      tx_ops = wlan_reg_get_tx_ops(*(_QWORD *)(a1 + 21624), v36, v37, v38, v39, v40, v41, v42, v43);
      if ( !tx_ops )
      {
        result = 16;
        goto LABEL_43;
      }
      v51 = *(void (__fastcall **)(__int64, __int64, __int64))(tx_ops + 144);
      if ( v51 )
      {
        v52 = *(_QWORD *)(a1 + 21624);
        v53 = *(unsigned __int8 *)(a4 + 10);
        if ( *((_DWORD *)v51 - 1) != 1094041931 )
          __break(0x8228u);
        v51(v52, v53, v34 + 544);
      }
    }
    goto LABEL_33;
  }
  if ( (*(_BYTE *)(a4 + 10070) & 1) != 0 )
  {
    LOBYTE(v44) = 0;
  }
  else
  {
    *(_BYTE *)(v34 + 552) = *(_BYTE *)(a4 + 10042);
    *(_BYTE *)(v34 + 568) = *(_BYTE *)(a3 + 4);
    max_tx_power = lim_get_max_tx_power(a1, v34, v36, v37, v38, v39, v40, v41, v42, v43);
    v47 = *(_DWORD *)(v34 + 132);
    LOBYTE(v44) = max_tx_power;
    BYTE1(v68[0]) = max_tx_power;
    if ( v47 )
    {
      if ( v47 <= max_tx_power )
        LOBYTE(v44) = v47;
      BYTE1(v68[0]) = v44;
    }
    if ( (unsigned __int8)*v35 != (unsigned __int8)v44
      && !(unsigned int)rrm_send_set_max_tx_power_req(
                          a1,
                          v44,
                          (unsigned __int8 *)a4,
                          v36,
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          v42,
                          v43) )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Local: %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "rrm_process_link_measurement_request",
        (unsigned int)(char)*v35);
      *v35 = v44;
    }
  }
LABEL_33:
  v54 = jiffies;
  if ( rrm_process_link_measurement_request___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Link Request Tx Pwr: %d Link Report Tx Pwr: %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "rrm_process_link_measurement_request",
      *(unsigned __int8 *)(a3 + 4),
      (unsigned __int8)v44);
    rrm_process_link_measurement_request___last_ticks = v54;
  }
  v55 = *(_BYTE *)(a3 + 2);
  WORD1(v68[0]) = 0;
  v56 = *(_DWORD *)(a2 + 52);
  LOBYTE(v68[0]) = v55;
  v57 = jiffies;
  if ( rrm_process_link_measurement_request___last_ticks_11 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x35u,
      4u,
      "%s: Received Link report frame with %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "rrm_process_link_measurement_request",
      (unsigned int)(char)v56,
      v68[0]);
    rrm_process_link_measurement_request___last_ticks_11 = v57;
  }
  if ( (char)v56 >= -109 )
  {
    if ( (char)v56 <= 0 )
      v58 = 2 * v56 - 36;
    else
      v58 = -36;
  }
  else
  {
    v58 = 0;
  }
  v59 = *(_BYTE *)(a2 + 4);
  BYTE4(v68[0]) = v58;
  BYTE5(v68[0]) = v59;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending Link report frame",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "rrm_process_link_measurement_request",
    v68[0]);
  result = lim_send_link_report_action_frame(
             a1,
             (char *)v68,
             (unsigned __int8 *)(v24 + 10),
             a4,
             v60,
             v61,
             v62,
             v63,
             v64,
             v65,
             v66,
             v67);
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
