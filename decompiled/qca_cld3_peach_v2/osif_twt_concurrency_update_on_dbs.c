__int64 __fastcall osif_twt_concurrency_update_on_dbs(
        __int64 result,
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
  __int64 v10; // x19
  unsigned int v11; // w20
  unsigned __int8 macid_by_vdev_id; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w21
  unsigned __int8 v23; // w22
  const char *v24; // x2
  int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  char v43[4]; // [xsp+4h] [xbp-5Ch] BYREF
  int v44; // [xsp+8h] [xbp-58h] BYREF
  __int64 v45; // [xsp+Ch] [xbp-54h]
  __int64 v46; // [xsp+14h] [xbp-4Ch]
  __int64 v47; // [xsp+1Ch] [xbp-44h]
  __int64 v48; // [xsp+24h] [xbp-3Ch]
  __int64 v49; // [xsp+2Ch] [xbp-34h]
  __int64 v50; // [xsp+34h] [xbp-2Ch]
  __int64 v51; // [xsp+3Ch] [xbp-24h]
  __int64 v52; // [xsp+44h] [xbp-1Ch]
  __int64 v53; // [xsp+4Ch] [xbp-14h]
  int v54; // [xsp+54h] [xbp-Ch]
  __int64 v55; // [xsp+58h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43[0] = 0;
  if ( !a2 )
  {
    v24 = "%s: vdev is null";
    goto LABEL_26;
  }
  if ( *(_DWORD *)(a2 + 20) != 3 )
    goto LABEL_27;
  v10 = *(_QWORD *)(result + 80);
  if ( !v10 )
  {
    v24 = "%s: psoc is null";
    goto LABEL_26;
  }
  v11 = *(unsigned __int8 *)(a2 + 168);
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(*(_QWORD *)(result + 80), v11);
  v22 = *(_DWORD *)(a2 + 16);
  v23 = macid_by_vdev_id;
  if ( v22 > 1 )
  {
    if ( v22 != 2 )
    {
      if ( v22 != 3 )
      {
LABEL_15:
        result = qdf_trace_msg(
                   0x48u,
                   2u,
                   "%s: TWT not supported for mode %d",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "osif_twt_concurrency_update_on_dbs",
                   (unsigned int)v22);
        goto LABEL_27;
      }
      result = wlan_vdev_p2p_is_wfd_r2_mode(v10, v11, v14, v15, v16, v17, v18, v19, v20, v21);
      if ( (result & 1) == 0 )
        goto LABEL_27;
      goto LABEL_13;
    }
    result = wlan_vdev_p2p_is_wfd_r2_mode(v10, v11, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( (result & 1) == 0 )
      goto LABEL_27;
    goto LABEL_17;
  }
  if ( !v22 )
  {
LABEL_17:
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Concurrency exist on STA/P2P CLI vdev",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "osif_twt_concurrency_update_on_dbs");
    v44 = v23;
    v53 = 0;
    v52 = 0;
    v51 = 0;
    v50 = 0;
    v49 = 0;
    v48 = 0;
    v47 = 0;
    v46 = 0;
    v45 = 0;
    v54 = 1;
    result = ucfg_twt_set_requestor_enable_cmd_in_progress(v10);
    if ( (_DWORD)result )
    {
      if ( (_DWORD)result == 6 )
        goto LABEL_27;
      result = qdf_status_to_os_return(result);
      v25 = result;
    }
    else
    {
      v25 = osif_twt_requestor_enable(v10, (__int64)&v44);
      result = ucfg_twt_reset_requestor_enable_cmd_in_progress(v10);
    }
    if ( !v25 )
      goto LABEL_27;
    v24 = "%s: TWT requestor enable cmd to fw failed";
LABEL_26:
    result = qdf_trace_msg(0x48u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "osif_twt_concurrency_update_on_dbs");
    goto LABEL_27;
  }
  if ( v22 != 1 )
    goto LABEL_15;
LABEL_13:
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Concurrency exist on SAP/P2P GO vdev",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "osif_twt_concurrency_update_on_dbs");
  v44 = v23;
  v53 = 0;
  v52 = 0;
  v51 = 0;
  v50 = 0;
  v49 = 0;
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v45 = 0;
  v54 = 1;
  if ( (unsigned int)osif_twt_responder_enable(v10, (__int64)&v44) )
  {
    v24 = "%s: TWT responder enable cmd to fw failed";
    goto LABEL_26;
  }
  ucfg_twt_cfg_get_responder(v10, v43);
  v34 = osif_twt_send_responder_disable_per_vdev(v10, v11, v22, v43[0], v26, v27, v28, v29, v30, v31, v32, v33);
  if ( v34 && v34 != 11 )
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: TWT responder disable per vdev cmd to fw failed %d",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               "osif_twt_concurrency_update_on_dbs",
               v34);
  else
    result = ucfg_twt_update_beacon_template();
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
