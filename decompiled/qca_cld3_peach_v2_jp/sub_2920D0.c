// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_2920D0(
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
  __int64 v9; // x14
  __int64 v10; // x20
  unsigned int v11; // w21
  __int64 v12; // x22
  __int64 v13; // x23
  __int64 v14; // x24
  int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  int v44; // w22
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x8
  void (__fastcall *v48)(__int64, __int64, bool); // x8
  int v49; // w20
  __int64 v50; // x1
  int v51; // w19
  __int64 v52; // [xsp-68h] [xbp-68h]
  _BYTE v53[4]; // [xsp-5Ch] [xbp-5Ch] BYREF
  __int64 v54; // [xsp-58h] [xbp-58h] BYREF
  __int64 v55; // [xsp-50h] [xbp-50h]

  if ( v9 )
    return wlan_set_sap_best_channel_2ghz();
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, v13, v14 + 296);
  v17 = ((__int64 (__fastcall *)(__int64, __int64))_wlan_hdd_validate_context)(v10 + 1536, v13);
  if ( v17 )
    goto LABEL_4;
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Command not allowed in FTM mode",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "__wlan_hdd_cfg80211_handle_wisa_cmd");
    v26 = -1;
    goto LABEL_5;
  }
  if ( (unsigned int)_nla_parse(&v54, 1, v12, v11, &wlan_hdd_wisa_cmd_policy, 31, 0) )
  {
    v43 = "%s: Invalid WISA cmd attributes";
  }
  else
  {
    if ( v55 )
    {
      v44 = *(_DWORD *)(v55 + 4);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: WISA Mode: %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "__wlan_hdd_cfg80211_handle_wisa_cmd",
        v44 != 0);
      v45 = *(_QWORD *)(v10 + 1552);
      v46 = *(_QWORD *)(v14 + 55512);
      v53[0] = v44 != 0;
      v53[1] = *(_BYTE *)(v46 + 8);
      v17 = ((__int64 (__fastcall *)(__int64, _BYTE *))sme_set_wisa_params)(v45, v53);
      if ( !v17
        || (qdf_trace_msg(
              0x33u,
              2u,
              "%s: Unable to set WISA mode: %d to FW",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "__wlan_hdd_cfg80211_handle_wisa_cmd",
              v44 != 0),
            v17 = -22,
            !v44) )
      {
        if ( a1 && *(_QWORD *)a1 && (v47 = *(_QWORD *)(*(_QWORD *)a1 + 64LL)) != 0 )
        {
          v48 = *(void (__fastcall **)(__int64, __int64, bool))(v47 + 64);
          if ( v48 )
          {
            v49 = v17;
            v50 = *(unsigned __int8 *)(*(_QWORD *)(v14 + 55512) + 8LL);
            if ( *((_DWORD *)v48 - 1) != -254072184 )
              __break(0x8228u);
            v48(a1, v50, v44 != 0);
            v17 = v49;
          }
        }
        else
        {
          v51 = v17;
          qdf_trace_msg(0x45u, 1u, "%s invalid instance", v18, v19, v20, v21, v22, v23, v24, v25, "cdp_set_wisa_mode");
          v17 = v51;
        }
      }
      goto LABEL_4;
    }
    v43 = "%s: Invalid WISA mode";
  }
  qdf_trace_msg(0x33u, 2u, v43, v35, v36, v37, v38, v39, v40, v41, v42, "__wlan_hdd_cfg80211_handle_wisa_cmd");
  v17 = -22;
LABEL_4:
  v26 = v17;
  qdf_trace_msg(0x33u, 8u, "%s: exit", v18, v19, v20, v21, v22, v23, v24, v25, "__wlan_hdd_cfg80211_handle_wisa_cmd");
LABEL_5:
  ((void (__fastcall *)(__int64, const char *))_osif_vdev_sync_op_stop)(v52, "wlan_hdd_cfg80211_handle_wisa_cmd");
  _ReadStatusReg(SP_EL0);
  return v26;
}
