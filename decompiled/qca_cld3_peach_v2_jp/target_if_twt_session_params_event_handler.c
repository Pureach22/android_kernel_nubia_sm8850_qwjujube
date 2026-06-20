__int64 __fastcall target_if_twt_session_params_event_handler(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *psoc_from_scn_hdl; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  __int64 v30; // x8
  __int64 v31; // x21
  __int64 v32; // x24
  __int64 v33; // x22
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w23
  __int64 result; // x0
  const char *v45; // x2
  int v46; // w8
  char v47; // w26
  unsigned int v48; // w23
  __int64 v49; // x4
  __int64 v50; // x5
  __int64 v51; // x6
  __int64 v52; // x7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _QWORD *peer_by_mac; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x28
  __int64 v71; // x8
  void (__fastcall *v72)(__int64, __int64, char *, __int64, char *); // x8
  __int64 v73; // x1
  __int64 comp_private_obj; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x27
  void (__fastcall *v84)(__int64, __int64 *); // x8
  __int64 v85; // x8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  _QWORD *v94; // [xsp+0h] [xbp-70h]
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-68h]
  __int64 v96; // [xsp+10h] [xbp-60h] BYREF
  char v97; // [xsp+18h] [xbp-58h] BYREF
  _BYTE v98[7]; // [xsp+19h] [xbp-57h] BYREF
  __int64 v99; // [xsp+30h] [xbp-40h] BYREF
  __int64 v100; // [xsp+38h] [xbp-38h]
  __int64 v101; // [xsp+40h] [xbp-30h]
  __int64 v102; // [xsp+48h] [xbp-28h]
  __int64 v103; // [xsp+50h] [xbp-20h]
  __int64 v104; // [xsp+58h] [xbp-18h]
  int v105; // [xsp+60h] [xbp-10h]
  __int64 v106; // [xsp+68h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v105 = 0;
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v96 = 0;
  qdf_trace_msg(0x49u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_twt_session_params_event_handler");
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, evt_buf: 0x%pK",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_twt_session_params_event_handler",
      a1,
      a2);
    goto LABEL_14;
  }
  psoc_from_scn_hdl = (_QWORD *)target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v45 = "%s: psoc object is null!";
LABEL_13:
    qdf_trace_msg(0x49u, 2u, v45, v21, v22, v23, v24, v25, v26, v27, v28, "target_if_twt_session_params_event_handler");
    goto LABEL_14;
  }
  v29 = psoc_from_scn_hdl[351];
  if ( !v29 )
  {
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v30 = psoc_from_scn_hdl[350];
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 16)) == 0 )
  {
    v45 = "%s: wmi_handle is null!";
    goto LABEL_13;
  }
  v32 = psoc_from_scn_hdl[267];
  if ( !v32 )
  {
    v45 = "%s: No valid twt session stats rx ops";
    goto LABEL_13;
  }
  v33 = (__int64)psoc_from_scn_hdl;
  v34 = wmi_extract_twt_session_stats_event(*(_QWORD *)(v30 + 16), a2, &v96);
  if ( v34 )
  {
    v43 = v34;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Could not extract twt session stats event",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "target_if_twt_session_params_event_handler");
    result = qdf_status_to_os_return(v43);
    goto LABEL_15;
  }
  if ( HIDWORD(v96) >= 2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Number of twt sessions exceeded, num:%d max:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "target_if_twt_session_params_event_handler");
    goto LABEL_14;
  }
  v46 = target_if_ll_sap_twt_session_params(v33, a2, &v96, &v99);
  result = 0;
  if ( v46 && HIDWORD(v96) )
  {
    v47 = 0;
    v48 = 0;
    v94 = v98;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( !(unsigned int)wmi_extract_twt_session_stats_data(v31, a2, &v96, &v99, v48) )
    {
      peer_by_mac = wlan_objmgr_get_peer_by_mac(v33, (_BYTE *)&v99 + 4, 0x26u);
      if ( peer_by_mac )
      {
        v70 = (__int64)peer_by_mac;
        if ( HIDWORD(v100) == 1 )
        {
          v47 = 1;
        }
        else if ( HIDWORD(v100) == 2 )
        {
          v47 = 0;
        }
        if ( *(_QWORD *)v29 )
        {
          v71 = *(_QWORD *)(*(_QWORD *)v29 + 8LL);
          if ( v71 )
          {
            v72 = *(void (__fastcall **)(__int64, __int64, char *, __int64, char *))(v71 + 112);
            if ( v72 )
            {
              v73 = (unsigned int)v99;
              v97 = v47;
              *v94 = 0;
              v94[1] = 0;
              *(_QWORD *)((char *)v94 + 15) = 0;
              if ( *((_DWORD *)v72 - 1) != 201075190 )
                __break(0x8228u);
              v72(v29, v73, (char *)&v99 + 4, 3, &v97);
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            "cdp_txrx_set_peer_param");
        }
        comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v70, 0x1Bu);
        if ( comp_private_obj )
        {
          v83 = comp_private_obj;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(comp_private_obj + 24);
          }
          else
          {
            raw_spin_lock_bh(comp_private_obj + 24);
            *(_QWORD *)(v83 + 32) |= 1uLL;
          }
          v84 = *(void (__fastcall **)(__int64, __int64 *))(v32 + 200);
          if ( *((_DWORD *)v84 - 1) != 2117292247 )
            __break(0x8228u);
          v84(v33, &v99);
          v85 = *(_QWORD *)(v83 + 32);
          if ( (v85 & 1) != 0 )
          {
            *(_QWORD *)(v83 + 32) = v85 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v83 + 24);
          }
          else
          {
            raw_spin_unlock(v83 + 24);
          }
          wlan_objmgr_peer_release_ref(v70, 0x26u, v86, v87, v88, v89, v90, v91, v92, v93);
        }
        else
        {
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: peer_cp_stats is null",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "target_if_twt_session_params_event_handler");
        }
      }
      else
      {
        if ( &v99 == (__int64 *)-4LL )
          v49 = 0;
        else
          v49 = BYTE4(v99);
        if ( &v99 == (__int64 *)-4LL )
          v50 = 0;
        else
          v50 = BYTE5(v99);
        if ( &v99 == (__int64 *)-4LL )
          v51 = 0;
        else
          v51 = BYTE6(v99);
        if ( &v99 == (__int64 *)-4LL )
          v52 = 0;
        else
          v52 = BYTE1(v100);
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: peer obj not found for %02x:%02x:%02x:**:**:%02x",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "target_if_twt_session_params_event_handler",
          v49,
          v50,
          v51,
          v52,
          v94);
      }
      ++v48;
      result = 0;
      if ( v48 >= HIDWORD(v96) )
        goto LABEL_15;
    }
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Unable to extract twt params for idx %d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "target_if_twt_session_params_event_handler",
      v48);
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
