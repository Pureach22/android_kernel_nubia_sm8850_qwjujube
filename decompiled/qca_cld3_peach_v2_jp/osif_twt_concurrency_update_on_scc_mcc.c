__int64 __fastcall osif_twt_concurrency_update_on_scc_mcc(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  unsigned int v12; // w21
  unsigned __int8 macid_by_vdev_id; // w0
  int v16; // w22
  unsigned __int8 v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x4
  const char *v53; // x2
  unsigned int v54; // w0
  unsigned int v55; // w8
  bool v56; // zf
  char is_mcc; // w0
  int v58; // w8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w0
  char v68; // w0
  int v69; // w8
  unsigned int v70; // w0
  unsigned int v71; // w20
  __int64 v72; // [xsp+0h] [xbp-60h] BYREF
  _BYTE v73[12]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v74; // [xsp+14h] [xbp-4Ch]
  __int64 v75; // [xsp+1Ch] [xbp-44h]
  __int64 v76; // [xsp+24h] [xbp-3Ch]
  __int64 v77; // [xsp+2Ch] [xbp-34h]
  __int64 v78; // [xsp+34h] [xbp-2Ch]
  __int64 v79; // [xsp+3Ch] [xbp-24h]
  __int64 v80; // [xsp+44h] [xbp-1Ch]
  __int64 v81; // [xsp+4Ch] [xbp-14h]
  int v82; // [xsp+54h] [xbp-Ch]
  __int64 v83; // [xsp+58h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v72) = 0;
  LOBYTE(v72) = 0;
  if ( !a2 )
  {
    v34 = "%s: vdev is null";
LABEL_32:
    result = qdf_trace_msg(
               0x48u,
               2u,
               v34,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "osif_twt_concurrency_update_on_scc_mcc",
               v72,
               *(_QWORD *)v73);
    goto LABEL_33;
  }
  if ( *(_DWORD *)(a2 + 20) != 3 )
    goto LABEL_33;
  v11 = *(_QWORD *)(result + 80);
  if ( !v11 )
  {
    v34 = "%s: psoc is null";
    goto LABEL_32;
  }
  v12 = *(unsigned __int8 *)(a2 + 104);
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(*(_QWORD *)(result + 80), v12);
  v16 = *(_DWORD *)(a2 + 16);
  v17 = macid_by_vdev_id;
  ucfg_twt_tgt_caps_get_resp_disable_per_vdev(v11, &v72, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( v16 > 1 )
  {
    if ( v16 != 2 )
    {
      if ( v16 != 3 )
      {
LABEL_19:
        result = qdf_trace_msg(
                   0x48u,
                   2u,
                   "%s: TWT not supported for mode %d",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "osif_twt_concurrency_update_on_scc_mcc",
                   (unsigned int)v16,
                   v72);
        goto LABEL_33;
      }
      result = wlan_vdev_p2p_is_wfd_r2_mode(v11, v12, v26, v27, v28, v29, v30, v31, v32, v33);
      if ( (result & 1) == 0 )
        goto LABEL_33;
      goto LABEL_13;
    }
    result = wlan_vdev_p2p_is_wfd_r2_mode(v11, v12, v26, v27, v28, v29, v30, v31, v32, v33);
    if ( (result & 1) == 0 )
      goto LABEL_33;
LABEL_21:
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Concurrency exist on STA/P2P CLI vdev",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "osif_twt_concurrency_update_on_scc_mcc",
      v72);
    if ( *(_BYTE *)(a3 + 8) == 1 )
    {
      *(_DWORD *)v73 = v17;
      v81 = 0;
      v80 = 0;
      v79 = 0;
      v78 = 0;
      v77 = 0;
      v76 = 0;
      v75 = 0;
      v74 = 0;
      *(_QWORD *)&v73[4] = 0;
      v82 = 1;
      v54 = ucfg_twt_set_requestor_enable_cmd_in_progress(v11);
      if ( !v54 )
      {
        v71 = osif_twt_requestor_enable(v11, (__int64)v73);
        ucfg_twt_reset_requestor_enable_cmd_in_progress(v11);
        result = v71;
        if ( !v71 )
          goto LABEL_33;
LABEL_31:
        v34 = "%s: TWT requestor cmd to fw failed";
        goto LABEL_32;
      }
      v55 = v54;
      v56 = v54 == 6;
      result = 0;
      if ( !v56 )
      {
        result = qdf_status_to_os_return(v55);
        if ( !(_DWORD)result )
          goto LABEL_33;
        goto LABEL_31;
      }
    }
    else
    {
      is_mcc = policy_mgr_current_concurrency_is_mcc(v11);
      *(_DWORD *)v73 = v17;
      if ( (is_mcc & 1) != 0 )
        v58 = 2;
      else
        v58 = 1;
      *(_QWORD *)&v73[4] = 1;
      LODWORD(v74) = 0;
      HIDWORD(v74) = v58;
      result = osif_twt_requestor_disable(v11, (__int64)v73);
    }
    if ( !(_DWORD)result )
      goto LABEL_33;
    goto LABEL_31;
  }
  if ( !v16 )
    goto LABEL_21;
  if ( v16 != 1 )
    goto LABEL_19;
LABEL_13:
  result = policy_mgr_is_vdev_ll_lt_sap(v11, v12);
  if ( (result & 1) == 0 || (unsigned __int8)v72 == 1 )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Concurrency exist on SAP/P2P GO vdev",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "osif_twt_concurrency_update_on_scc_mcc",
      v72);
    if ( (*(_BYTE *)(a3 + 8) & 1) != 0 || (unsigned __int8)v72 == 1 )
    {
      *(_DWORD *)v73 = v17;
      v81 = 0;
      v80 = 0;
      v79 = 0;
      v78 = 0;
      v77 = 0;
      v76 = 0;
      v75 = 0;
      v74 = 0;
      *(_QWORD *)&v73[4] = 0;
      v82 = 1;
      v43 = osif_twt_responder_enable(v11, (__int64)v73);
      if ( v43 )
      {
        v52 = v43;
        v53 = "%s: TWT responder enable cmd to fw failed %d";
LABEL_42:
        result = qdf_trace_msg(
                   0x48u,
                   2u,
                   v53,
                   v44,
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   "osif_twt_concurrency_update_on_scc_mcc",
                   v52);
        goto LABEL_33;
      }
      ucfg_twt_cfg_get_responder(v11, (char *)&v72 + 4);
      v67 = osif_twt_send_responder_disable_per_vdev(v11, v12, v16, BYTE4(v72), v59, v60, v61, v62, v63, v64, v65, v66);
      if ( v67 )
      {
        v52 = v67;
        if ( v67 != 11 )
        {
          v53 = "%s: TWT responder VDEV disable cmd fails %d";
          goto LABEL_42;
        }
      }
    }
    else
    {
      v68 = policy_mgr_current_concurrency_is_mcc(v11);
      *(_DWORD *)v73 = v17;
      if ( (v68 & 1) != 0 )
        v69 = 2;
      else
        v69 = 1;
      *(_QWORD *)&v73[4] = 1;
      LODWORD(v74) = 0;
      HIDWORD(v74) = v69;
      v70 = osif_twt_responder_disable(v11, (__int64)v73);
      if ( v70 )
      {
        v52 = v70;
        v53 = "%s: TWT disable responder cmd to fw failed %d";
        goto LABEL_42;
      }
    }
    result = ucfg_twt_update_beacon_template();
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
