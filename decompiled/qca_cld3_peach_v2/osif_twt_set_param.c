__int64 __fastcall osif_twt_set_param(__int64 a1, _WORD *a2)
{
  int v2; // w8
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  __int64 v14; // x9
  __int64 v15; // x22
  __int64 v16; // x21
  unsigned int v17; // w21
  unsigned __int8 v18; // w23
  char v19; // w0
  unsigned int v20; // w0
  __int64 v21; // x8
  __int64 v22; // x20
  __int64 v23; // x0
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  __int64 v34; // x20
  __int64 v35; // x0
  unsigned int v36; // w0
  __int64 v37; // x20
  unsigned int v38; // w19
  char v39[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v40; // [xsp+10h] [xbp-20h] BYREF
  __int64 v41; // [xsp+18h] [xbp-18h]
  __int64 v42; // [xsp+20h] [xbp-10h]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (__int16)a2[1];
  v41 = 0;
  v42 = 0;
  v40 = 0;
  if ( (v2 & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
    result = 4294967274LL;
    goto LABEL_31;
  }
  result = _nla_parse(&v40, 2, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_set_param_policy, 31, 0);
  if ( (_DWORD)result )
    goto LABEL_31;
  if ( v41 )
  {
    v13 = *(unsigned __int8 *)(v41 + 4);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_AC_CONFIG_VALUE: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "osif_twt_set_param",
      *(unsigned __int8 *)(v41 + 4));
    v14 = *(_QWORD *)(a1 + 216);
    if ( !v14 || (v15 = *(_QWORD *)(v14 + 80)) == 0 )
    {
LABEL_29:
      v20 = -22;
      goto LABEL_30;
    }
    v39[0] = 0;
    if ( v13 >= 4 )
    {
      v16 = jiffies;
      if ( osif_twt_add_ac_config___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid AC parameter. Value: %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "osif_twt_add_ac_config",
          v13);
        osif_twt_add_ac_config___last_ticks = v16;
      }
      goto LABEL_29;
    }
    v17 = *(_DWORD *)(a1 + 16);
    v18 = *(_BYTE *)(a1 + 168);
    ucfg_twt_cfg_get_responder(v15, v39);
    v19 = ucfg_twt_resp_check_bit(v15, v18, v17, v39[0]);
    if ( v17 != 1 || (v19 & 1) == 0 )
    {
      v37 = jiffies;
      if ( osif_twt_add_ac_config___last_ticks_153 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Undesired device mode. Mode: %d and responder: %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "osif_twt_add_ac_config",
          v17,
          v19 & 1);
        osif_twt_add_ac_config___last_ticks_153 = v37;
      }
      goto LABEL_29;
    }
    v20 = ucfg_twt_ac_pdev_param_send();
    if ( v20 )
    {
LABEL_30:
      v38 = v20;
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Fail to set TWT AC parameter, errno %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "osif_twt_set_param",
        v20);
      result = v38;
      goto LABEL_31;
    }
  }
  if ( !v42 )
    goto LABEL_25;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: vdev:%d unavailability_mode set",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "osif_twt_set_param",
    *(unsigned __int8 *)(a1 + 168));
  v21 = *(_QWORD *)(a1 + 216);
  if ( !v21 )
    goto LABEL_26;
  v22 = *(_QWORD *)(v21 + 80);
  if ( !v22 )
    goto LABEL_26;
  v23 = *(_QWORD *)(v21 + 80);
  v39[0] = 0;
  ucfg_twt_cfg_get_requestor(v23, v39);
  if ( v39[0] != 1 )
    goto LABEL_26;
  v24 = ucfg_twt_send_unavailability_mode(v22, a1);
  if ( v24 )
  {
    result = qdf_status_to_os_return(v24);
    if ( (_DWORD)result )
      goto LABEL_31;
  }
  if ( !v42 )
  {
LABEL_25:
    result = 0;
    goto LABEL_31;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: vdev:%d unavailability_mode set",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "osif_twt_set_param",
    *(unsigned __int8 *)(a1 + 168));
  v33 = *(_QWORD *)(a1 + 216);
  if ( !v33
    || (v34 = *(_QWORD *)(v33 + 80)) == 0
    || (v35 = *(_QWORD *)(v33 + 80), v39[0] = 0, ucfg_twt_cfg_get_requestor(v35, v39), v39[0] != 1) )
  {
LABEL_26:
    result = 4294967274LL;
    goto LABEL_31;
  }
  v36 = ucfg_twt_send_unavailability_mode(v34, a1);
  if ( !v36 )
    goto LABEL_25;
  result = qdf_status_to_os_return(v36);
  if ( !(_DWORD)result )
    goto LABEL_25;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
