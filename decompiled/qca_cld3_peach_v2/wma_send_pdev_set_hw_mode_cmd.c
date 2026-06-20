__int64 __fastcall wma_send_pdev_set_hw_mode_cmd(
        __int64 *a1,
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
  __int64 result; // x0
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD v39[7]; // [xsp+8h] [xbp-38h] BYREF

  v39[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
      "wma_send_pdev_set_hw_mode_cmd");
    result = 29;
    goto LABEL_14;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Set HW mode param is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_send_pdev_set_hw_mode_cmd");
LABEL_7:
    v12 = _qdf_mem_malloc(0x2Cu, "wma_send_pdev_set_hw_mode_cmd", 10301);
    if ( v12 )
    {
      v21 = v12;
      *(_DWORD *)(v12 + 8) = 0;
      *(_QWORD *)v12 = 2;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Sending HW mode fail response to LIM",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_send_pdev_set_hw_mode_cmd");
      v39[1] = v21;
      v39[0] = 4458;
      v39[4] = 0;
      v39[5] = 0;
      v39[2] = 0;
      v39[3] = wma_discard_fw_event;
      if ( (unsigned int)scheduler_post_msg_by_priority(53, (unsigned __int16 *)v39, 0) )
        _qdf_mem_free(v21);
      result = 16;
    }
    else
    {
      result = 29;
    }
    goto LABEL_14;
  }
  wma_acquire_wakelock(a1 + 391, 8000);
  if ( (unsigned int)wmi_unified_soc_set_hw_mode_cmd(*a1) )
  {
    wma_release_wakelock(a1 + 391);
    goto LABEL_7;
  }
  v22 = wma_fill_hold_req(a1, 0, 0x1169u, 6u, nullptr, 0, 0x1F3Fu);
  result = 0;
  if ( !v22 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to allocate request for SIR_HAL_PDEV_SET_HW_MODE",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_send_pdev_set_hw_mode_cmd");
    wma_remove_req((__int64)a1, 0, 6u, v31, v32, v33, v34, v35, v36, v37, v38);
    result = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
