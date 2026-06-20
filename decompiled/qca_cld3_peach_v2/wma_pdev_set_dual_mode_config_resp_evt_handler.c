__int64 __fastcall wma_pdev_set_dual_mode_config_resp_evt_handler(
        __int64 a1,
        __int64 *a2,
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
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD *v29; // x19
  __int64 v30; // x21
  int v31; // w8
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v42; // [xsp+10h] [xbp-30h]
  __int64 v43; // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v44)(__int64); // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wma_validate_handle",
      "wma_pdev_set_dual_mode_config_resp_evt_handler");
    goto LABEL_10;
  }
  wma_release_wakelock(a1 + 3128);
  wma_remove_req(a1, 0, 7u, v12, v13, v14, v15, v16, v17, v18, v19);
  v20 = _qdf_mem_malloc(4u, "wma_pdev_set_dual_mode_config_resp_evt_handler", 4702);
  if ( !v20 )
  {
LABEL_10:
    result = 29;
    goto LABEL_11;
  }
  v29 = (_DWORD *)v20;
  if ( a2 )
  {
    v30 = *a2;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: status: %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wma_pdev_set_dual_mode_config_resp_evt_handler",
      *(unsigned int *)(v30 + 8));
    v31 = *(_DWORD *)(v30 + 8);
    *v29 = v31;
    if ( !v31 )
    {
      policy_mgr_update_dbs_scan_config(*(_QWORD *)(a1 + 24));
      policy_mgr_update_dbs_fw_config(*(_QWORD *)(a1 + 24));
    }
    v42 = v29;
    v41 = 4283;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = wma_discard_fw_event;
    if ( (unsigned int)scheduler_post_msg_by_priority(53, (unsigned __int16 *)&v41, 0) )
      _qdf_mem_free((__int64)v29);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid event",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wma_pdev_set_dual_mode_config_resp_evt_handler");
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Sending fail response to LIM",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "wma_pdev_set_dual_mode_config_resp_evt_handler");
    *v29 = 2;
    v42 = v29;
    v41 = 4283;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = wma_discard_fw_event;
    if ( (unsigned int)scheduler_post_msg_by_priority(53, (unsigned __int16 *)&v41, 0) )
      _qdf_mem_free((__int64)v29);
    result = 16;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
