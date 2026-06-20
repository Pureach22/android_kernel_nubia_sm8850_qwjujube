__int64 __fastcall csr_process_sap_results(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x25
  __int64 v15; // x8
  unsigned int v18; // w22
  __int64 result; // x0
  __int64 v20; // x19
  int opmode_from_vdev_id; // w24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  __int64 v39; // x8
  __int64 v40; // x24
  int v41; // w0
  unsigned int v42; // w27
  int v43; // w8
  __int64 v44; // x8
  unsigned int v45; // w22
  unsigned int v46; // w23
  _DWORD *v47; // x8
  __int64 v48; // x0
  __int64 v49; // x8
  unsigned int v50; // w22
  unsigned int v51; // w23
  _DWORD *v52; // x8
  __int64 v53; // x0
  __int64 v54; // x23
  __int64 v55; // x0
  int v56; // w0
  __int64 v57; // x8
  _DWORD *v58; // x8
  __int64 v59; // x0
  const char *v60; // x2
  const char *v61; // x3
  int v62; // w23
  __int64 v63; // x28
  const char *v64; // x23
  const char *v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  unsigned int v83; // w23
  unsigned int v84; // w24
  __int64 v85; // x8
  _DWORD *v86; // x8
  __int64 v87; // x0
  int v88; // [xsp+4h] [xbp-2Ch]
  int v89; // [xsp+8h] [xbp-28h] BYREF
  int v90; // [xsp+Ch] [xbp-24h] BYREF
  _BYTE v91[4]; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v92[4]; // [xsp+14h] [xbp-1Ch] BYREF
  int v93; // [xsp+18h] [xbp-18h] BYREF
  int v94; // [xsp+1Ch] [xbp-14h] BYREF
  int v95; // [xsp+20h] [xbp-10h] BYREF
  __int16 v96; // [xsp+24h] [xbp-Ch]
  __int64 v97; // [xsp+28h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int8)a4 > 5u )
  {
    v89 = 8;
    v90 = 18;
    goto LABEL_13;
  }
  v13 = (unsigned __int8)a4;
  v15 = *(_QWORD *)(a1 + 17296) + 96LL * (unsigned __int8)a4;
  v89 = 8;
  v90 = 18;
  if ( !v15 )
  {
LABEL_13:
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: session %d not found ",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "csr_process_sap_results");
    goto LABEL_74;
  }
  v18 = (unsigned __int8)a4;
  result = _qdf_mem_malloc(0x180u, "csr_process_sap_results", 8252);
  if ( result )
  {
    v20 = result;
    opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), a4);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: SAP result : %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "csr_process_sap_results",
      a3);
    if ( a3 - 2 < 2 )
    {
      if ( opmode_from_vdev_id != 11 )
      {
        v38 = v18;
        if ( *(_DWORD *)(a1 + 4 * v13 + 17268) == 3 )
        {
          v54 = *(_QWORD *)(a1 + 17296) + 96LL * (unsigned int)v13;
          v55 = *(_QWORD *)(v54 + 32);
          if ( v55 )
          {
            _qdf_mem_free(v55);
            *(_QWORD *)(v54 + 32) = 0;
          }
          *(_DWORD *)(v54 + 24) = 0;
          *(_QWORD *)(v54 + 8) = 0;
          *(_QWORD *)(v54 + 16) = 0;
          v56 = csr_translate_to_wni_cfg_dot11_mode(a1, *(unsigned int *)(a1 + 17204));
          v38 = v18;
          *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL) = v56;
        }
        if ( a1 )
        {
          v57 = *(_QWORD *)(a1 + 17296);
          if ( v57 )
          {
            if ( (*(_BYTE *)(v57 + 96LL * (unsigned int)v13 + 1) & 1) != 0 )
            {
              wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), a4);
              v58 = *(_DWORD **)(a1 + 22040);
              if ( v58 )
              {
                v59 = *(_QWORD *)(a1 + 21624);
                if ( *(v58 - 1) != 1469140685 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, __int64))v58)(v59, a4, 0, 18, 9);
              }
              goto LABEL_73;
            }
          }
        }
        v60 = "%s: Session ID: %d is not valid";
        v61 = "csr_roam_call_callback";
        goto LABEL_72;
      }
      qdf_mem_set((void *)v20, 0x180u, 0);
      csr_roam_update_ndp_return_params(a1, a3, &v90, &v89, v20);
      if ( a1 )
      {
        v44 = *(_QWORD *)(a1 + 17296);
        if ( v44 )
        {
          if ( (*(_BYTE *)(v44 + 96LL * (unsigned int)v13 + 1) & 1) != 0 )
          {
            v46 = v89;
            v45 = v90;
            wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), a4);
            v47 = *(_DWORD **)(a1 + 22040);
            if ( v47 )
            {
              v48 = *(_QWORD *)(a1 + 21624);
              if ( *(v47 - 1) != 1469140685 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD))v47)(v48, a4, v20, v45, v46);
            }
            goto LABEL_73;
          }
        }
      }
      goto LABEL_71;
    }
    v38 = v18;
    if ( a3 == 1 )
    {
      if ( opmode_from_vdev_id == 11 )
      {
        csr_roam_update_ndp_return_params(a1, 1, &v90, &v89, v20);
        v38 = v18;
      }
      if ( a1 && (v49 = *(_QWORD *)(a1 + 17296)) != 0 && (*(_BYTE *)(v49 + 96LL * (unsigned int)v13 + 1) & 1) != 0 )
      {
        v51 = v89;
        v50 = v90;
        wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), a4);
        v52 = *(_DWORD **)(a1 + 22040);
        if ( v52 )
        {
          v53 = *(_QWORD *)(a1 + 21624);
          if ( *(v52 - 1) != 1469140685 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD))v52)(v53, a4, v20, v50, v51);
        }
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "csr_roam_call_callback",
          v38);
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL) = csr_translate_to_wni_cfg_dot11_mode(a1, *(unsigned int *)(a1 + 17204));
      goto LABEL_73;
    }
    if ( a3 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Invalid response",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "csr_process_sap_results",
        v18);
    }
    else
    {
      v93 = 7;
      v96 = -1;
      v94 = 18;
      v95 = -1;
      v92[0] = 0;
      v91[0] = 0;
      if ( !a1
        || (v39 = *(_QWORD *)(a1 + 17296)) == 0
        || (v40 = v39 + 96LL * (unsigned int)v13, (*(_BYTE *)(v40 + 1) & 1) == 0) )
      {
        v60 = "%s: Invalid session id %d";
        v61 = "csr_roam_process_start_bss_success";
LABEL_72:
        qdf_trace_msg(0x34u, 2u, v60, v30, v31, v32, v33, v34, v35, v36, v37, v61, v38);
        goto LABEL_73;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Start BSS success",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "csr_roam_process_start_bss_success",
        v18);
      v41 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), a4);
      v42 = v41 & 0xFFFFFFFD;
      if ( (v41 & 0xFFFFFFFD) == 1 )
      {
        v43 = 3;
LABEL_52:
        v62 = 0;
        *(_DWORD *)(v40 + 4) = v43;
LABEL_53:
        v63 = a1 + 17244;
        if ( *(_DWORD *)(a1 + 17244 + 4 * v13) != 3 )
        {
          v88 = v62;
          v64 = mac_trace_getcsr_roam_state(3u);
          v65 = mac_trace_getcsr_roam_state(*(_DWORD *)(v63 + 4 * v13));
          qdf_trace_msg(
            0x34u,
            8u,
            "CSR RoamState[%d]: [ %s <== %s ]",
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v18,
            v64,
            v65);
          if ( *(_DWORD *)(v63 + 4 * v13) == 2 )
            csr_roam_substate_change(a1, 0, v18, v74, v75, v76, v77, v78, v79, v80, v81);
          v62 = v88;
          *(_DWORD *)(v63 + 4 * v13) = 3;
        }
        v82 = *(_QWORD *)(v40 + 32);
        if ( v82 )
        {
          _qdf_mem_free(v82);
          *(_QWORD *)(v40 + 32) = 0;
        }
        *(_DWORD *)(v40 + 24) = 0;
        *(_QWORD *)(v40 + 8) = 0;
        *(_QWORD *)(v40 + 16) = 0;
        wlan_mlme_get_mac_vdev_id(*(_QWORD *)(a1 + 21632), a4, (void *)(v20 + 17));
        if ( v42 == 1 && wlan_is_open_wep_cipher(*(_QWORD *)(a1 + 21632), a4) )
          csr_issue_set_context_req_helper(a1, v18, (__int64)&v95, 0, 0, 0);
        *(_BYTE *)(v20 + 41) = *(_DWORD *)(a2 + 8);
        if ( v62 )
        {
          csr_roam_update_ndp_return_params(a1, 0, &v94, &v93, v20);
          v83 = v94;
          v84 = v93;
        }
        else
        {
          v83 = 18;
          v84 = 7;
        }
        *(_DWORD *)(v20 + 32) = 0;
        v85 = *(_QWORD *)(a1 + 17296);
        if ( v85 && (*(_BYTE *)(v85 + 96LL * (unsigned int)v13 + 1) & 1) != 0 )
        {
          wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), a4);
          v86 = *(_DWORD **)(a1 + 22040);
          if ( v86 )
          {
            v87 = *(_QWORD *)(a1 + 21624);
            if ( *(v86 - 1) != 1469140685 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD))v86)(v87, a4, v20, v83, v84);
          }
          goto LABEL_73;
        }
LABEL_71:
        v60 = "%s: Session ID: %d is not valid";
        v61 = "csr_roam_call_callback";
        v38 = v18;
        goto LABEL_72;
      }
      if ( v41 != 11 )
      {
        v43 = 1;
        goto LABEL_52;
      }
      *(_DWORD *)(v40 + 4) = 6;
      if ( !(unsigned int)wlan_mlme_get_wmm_mode(*(_QWORD *)(a1 + 21624), v92) )
      {
        if ( v92[0] == 2 )
        {
          *(_BYTE *)(v40 + 40) = 0;
        }
        else
        {
          if ( (unsigned int)wlan_mlme_get_wmm_uapsd_mask(*(_QWORD *)(a1 + 21624), v91) )
            goto LABEL_73;
          *(_BYTE *)(v40 + 40) = v91[0];
        }
        v62 = 1;
        goto LABEL_53;
      }
    }
LABEL_73:
    result = _qdf_mem_free(v20);
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
