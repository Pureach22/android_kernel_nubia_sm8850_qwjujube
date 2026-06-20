__int64 __fastcall hdd_set_antenna_mode(__int64 *a1, unsigned int a2)
{
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  unsigned int v16; // w22
  const char *v17; // x2
  unsigned int v18; // w1
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x21
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // [xsp+8h] [xbp-28h] BYREF
  __int64 (__fastcall *v82)(); // [xsp+10h] [xbp-20h]
  __int64 v83; // [xsp+18h] [xbp-18h]
  _BYTE v84[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v85; // [xsp+28h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = a1[4];
  v82 = nullptr;
  v83 = 0;
  v81 = 0;
  v6 = *(_QWORD *)(v4 + 24);
  if ( !(unsigned int)wlan_is_tdls_session_present(v5) )
  {
    v17 = "%s: TDLS session exists";
    v18 = 8;
LABEL_7:
    qdf_trace_msg(0x33u, v18, v17, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_set_antenna_mode");
    v16 = -22;
LABEL_8:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Set antenna status: %d current mode: %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_set_antenna_mode",
      v16,
      *(unsigned int *)(v6 + 1452));
    goto LABEL_9;
  }
  if ( a2 - 1 >= 2 )
  {
    v17 = "%s: unsupported antenna mode";
    v18 = 2;
    goto LABEL_7;
  }
  v15 = *(unsigned __int8 *)(v6 + 3744);
  LODWORD(v81) = a2;
  HIDWORD(v81) = a2;
  if ( v15 != 1 )
  {
    if ( a2 == 1 )
    {
      v37 = *(_QWORD *)v6;
      v84[0] = 0;
      if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(v37, v84) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: unable to get vht_enable2x2",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_is_supported_chain_mask_1x1");
      if ( !v84[0] )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: System only supports 1x1 mode",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_set_antenna_mode");
        v16 = 0;
        goto LABEL_8;
      }
    }
    else
    {
      v28 = *(_QWORD *)v6;
      v84[0] = 0;
      if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(v28, v84) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: unable to get vht_enable2x2",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "hdd_is_supported_chain_mask_1x1");
      if ( !v84[0] )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: System does not support 2x2 mode",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "hdd_set_antenna_mode");
        v16 = -1;
        goto LABEL_8;
      }
    }
    if ( *(_DWORD *)(v4 + 40)
      || !policy_mgr_is_sta_active_connection_exists(*(_QWORD *)v6)
      || (v16 = wlan_hdd_tdls_antenna_switch(a1, a2)) == 0 )
    {
      v46 = osif_request_alloc(hdd_set_antenna_mode_request_params);
      if ( v46 )
      {
        v55 = v46;
        v82 = wlan_hdd_soc_set_antenna_mode_cb;
        v83 = osif_request_cookie(v46);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Set antenna mode rx chains: %d tx chains: %d",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "hdd_set_antenna_mode",
          a2,
          a2);
        v64 = sme_soc_set_antenna_mode(*(_QWORD *)(v6 + 16), &v81);
        if ( v64 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: set antenna mode failed status : %d",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "hdd_set_antenna_mode",
            v64);
          v16 = -14;
        }
        else
        {
          v16 = osif_request_wait_for_response(v55);
          if ( v16 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: send set antenna mode timed out",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              "hdd_set_antenna_mode");
          else
            hdd_update_smps_antenna_mode(v6, a2);
        }
        osif_request_put(v55);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Request Allocation Failure",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "hdd_set_antenna_mode");
        v16 = -12;
      }
    }
    goto LABEL_8;
  }
  v16 = hdd_set_dynamic_antenna_mode(a1, a2, a2);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v16;
}
