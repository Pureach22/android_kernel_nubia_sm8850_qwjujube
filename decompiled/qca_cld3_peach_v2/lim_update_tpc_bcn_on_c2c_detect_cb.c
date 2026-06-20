__int64 __fastcall lim_update_tpc_bcn_on_c2c_detect_cb(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x27
  unsigned __int64 v30; // x26
  int v31; // w8
  __int64 v32; // x24
  __int64 v33; // x0
  unsigned int v34; // w3
  unsigned int v35; // w1
  const char *v36; // x2
  const char *v37; // x3
  int v38; // w0
  int curr_6g_power_type; // w25
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v49[6]; // [xsp+10h] [xbp-30h] BYREF

  v49[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v49, 0, 40);
  context = _cds_get_context(53, (__int64)"lim_update_tpc_bcn_on_c2c_detect_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = (__int64)context;
    result = policy_mgr_get_connection_info(a1, (__int64)v49);
    if ( (_DWORD)result )
    {
      v29 = 8LL * (unsigned int)result;
      v30 = 0;
      while ( 1 )
      {
        if ( v30 == 40 )
        {
          __break(0x5512u);
LABEL_35:
          __break(1u);
        }
        if ( v30 > 0x27 )
          goto LABEL_35;
        result = pe_find_session_by_vdev_id(v19, BYTE1(v49[v30 / 8]), v21, v22, v23, v24, v25, v26, v27, v28);
        if ( !result )
        {
          v35 = 2;
          v36 = "%s: Unable to find session";
          v37 = "lim_update_tpc_bcn_on_c2c_detect_cb";
LABEL_18:
          result = qdf_trace_msg(0x35u, v35, v36, v21, v22, v23, v24, v25, v26, v27, v28, v37);
          goto LABEL_5;
        }
        v31 = *(_DWORD *)(result + 88);
        v32 = result;
        if ( v31 != 1 )
          break;
        v38 = *(_DWORD *)(result + 284);
        v48 = 0;
        result = wlan_reg_is_6ghz_chan_freq(v38);
        if ( (result & 1) == 0 )
          goto LABEL_5;
        result = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(v19 + 21624), *(unsigned __int8 *)(v32 + 10));
        if ( (result & 1) != 0 )
          goto LABEL_5;
        curr_6g_power_type = wlan_mlme_get_curr_6g_power_type(
                               *(_QWORD *)(v32 + 16),
                               v21,
                               v22,
                               v23,
                               v24,
                               v25,
                               v26,
                               v27,
                               v28);
        wlan_reg_get_cur_6g_ap_pwr_type(
          *(_QWORD *)(v19 + 21632),
          (unsigned int *)&v48,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47);
        if ( v48 == curr_6g_power_type )
        {
          v35 = 8;
          v36 = "%s: No change in SAP/Go power type";
          v37 = "lim_recompute_sap_go_tpc_bcn";
          goto LABEL_18;
        }
LABEL_4:
        result = lim_set_tpc_power(v19, v32, 0, 0, v21, v22, v23, v24, v25, v26, v27, v28);
LABEL_5:
        v30 += 8LL;
        if ( v29 == v30 )
          goto LABEL_33;
      }
      if ( v31 != 2 )
        goto LABEL_5;
      v33 = *(_QWORD *)(result + 16);
      v48 = 0;
      if ( !(unsigned int)wlan_is_tdls_session_present(v33) )
        wlan_tdls_recompute_offchannel_mode(*(_QWORD *)(v19 + 21624), *(_QWORD *)(v32 + 16));
      result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v32 + 284));
      if ( (result & 1) == 0 )
        goto LABEL_5;
      v34 = *(unsigned __int8 *)(v32 + 10068);
      if ( v34 == 2 )
      {
        if ( (wlan_reg_is_indoor_ap_detected(*(_QWORD *)(v19 + 21632), v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
        {
          v34 = 3;
          goto LABEL_28;
        }
        v34 = *(unsigned __int8 *)(v32 + 10068);
      }
      if ( v34 != 3 )
        goto LABEL_29;
      if ( (wlan_reg_is_indoor_ap_detected(*(_QWORD *)(v19 + 21632), v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
      {
        v34 = *(unsigned __int8 *)(v32 + 10068);
        goto LABEL_29;
      }
      v34 = 2;
LABEL_28:
      *(_BYTE *)(v32 + 10068) = v34;
LABEL_29:
      result = wlan_reg_get_best_6g_power_type(
                 *(_QWORD *)(v19 + 21624),
                 *(_QWORD *)(v19 + 21632),
                 (unsigned int *)&v48,
                 v34,
                 *(_DWORD *)(v32 + 284),
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28);
      if ( (_DWORD)result || v48 == *(unsigned __int8 *)(v32 + 10069) )
        goto LABEL_5;
      mlme_set_best_6g_power_type(*(_QWORD *)(v32 + 16), v48, v21, v22, v23, v24, v25, v26, v27, v28);
      *(_BYTE *)(v32 + 10069) = v48;
      goto LABEL_4;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: mac ctx is null",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "lim_update_tpc_bcn_on_c2c_detect_cb");
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
