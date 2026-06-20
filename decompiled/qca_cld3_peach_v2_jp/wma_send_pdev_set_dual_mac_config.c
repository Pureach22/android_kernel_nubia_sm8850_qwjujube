__int64 __fastcall wma_send_pdev_set_dual_mac_config(
        __int64 *a1,
        int *a2,
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
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _DWORD *v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x19
  __int64 result; // x0
  _QWORD v48[7]; // [xsp+8h] [xbp-38h] BYREF

  v48[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( a2 )
    {
      if ( !wma_fill_hold_req(a1, 0, 0x10BAu, 7u, nullptr, 0, 0x1F40u) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to allocate request for SIR_HAL_PDEV_DUAL_MAC_CFG_REQ",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wma_send_pdev_set_dual_mac_config");
LABEL_12:
        result = 16;
        goto LABEL_14;
      }
      wma_acquire_wakelock(a1 + 391, 8500);
      v20 = wmi_unified_pdev_set_dual_mac_config_cmd(*a1, a2);
      if ( !v20 )
      {
        policy_mgr_update_dbs_req_config(a1[3], *a2, a2[1]);
        result = 0;
        goto LABEL_14;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to send WMI_PDEV_SET_DUAL_MAC_CONFIG_CMDID: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wma_send_pdev_set_dual_mac_config",
        v20);
      wma_release_wakelock(a1 + 391);
      wma_remove_req((__int64)a1, 0, 7u, v29, v30, v31, v32, v33, v34, v35, v36);
      v37 = (_DWORD *)_qdf_mem_malloc(4u, "wma_send_pdev_set_dual_mac_config", 10369);
      if ( v37 )
      {
        v46 = (__int64)v37;
        *v37 = 2;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Sending failure response to LIM",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wma_send_pdev_set_dual_mac_config");
        v48[1] = v46;
        v48[0] = 4283;
        v48[4] = 0;
        v48[5] = 0;
        v48[2] = 0;
        v48[3] = wma_discard_fw_event;
        if ( (unsigned int)scheduler_post_msg_by_priority(53, (unsigned __int16 *)v48, 0) )
          _qdf_mem_free(v46);
        goto LABEL_12;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Set dual mode config is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wma_send_pdev_set_dual_mac_config");
    }
  }
  else
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
      "wma_send_pdev_set_dual_mac_config");
  }
  result = 29;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
