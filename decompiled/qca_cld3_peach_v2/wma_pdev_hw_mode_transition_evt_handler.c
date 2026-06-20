__int64 __fastcall wma_pdev_hw_mode_transition_evt_handler(
        __int64 a1,
        _QWORD *a2,
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
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int *v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _DWORD *v31; // x8
  unsigned int v32; // w4
  __int64 v33; // x9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD v42[7]; // [xsp+8h] [xbp-38h] BYREF

  v42[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
      "wma_pdev_hw_mode_transition_evt_handler");
    result = 29;
    goto LABEL_23;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMI_PDEV_HW_MODE_TRANSITION_EVENTID event",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_pdev_hw_mode_transition_evt_handler");
    result = 16;
    goto LABEL_23;
  }
  if ( *(_DWORD *)(*a2 + 16LL) < 5u )
  {
    v13 = _qdf_mem_malloc(0x54u, "wma_pdev_hw_mode_transition_evt_handler", 4622);
    if ( !v13 )
    {
      result = 2;
      goto LABEL_23;
    }
    v22 = (unsigned int *)v13;
    if ( *(_DWORD *)(*a2 + 16LL) > *((_DWORD *)a2 + 6) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid num_vdev_mac_entries: %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wma_pdev_hw_mode_transition_evt_handler");
      _qdf_mem_free((__int64)v22);
      result = 4294967274LL;
      goto LABEL_23;
    }
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))wma_process_pdev_hw_mode_trans_ind)(a1, *a2, a2[2], v13);
    v31 = (_DWORD *)a2[4];
    if ( v31 )
    {
      v32 = *((_DWORD *)a2 + 10);
      if ( v32 - 4 > 0xFFFFFFFC )
      {
        v22[11] = v32;
        v22[12] = v31[1] - 1;
        v22[13] = v31[2];
        v22[14] = v31[3];
        v33 = a1;
        if ( v32 != 1 )
        {
          v22[15] = v31[5] - 1;
          v22[16] = v31[6];
          v22[17] = v31[7];
          if ( v32 != 2 )
          {
            v22[18] = v31[9] - 1;
            v22[19] = v31[10];
            v22[20] = v31[11];
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: num mac freq invalid %d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wma_process_mac_freq_mapping");
        v33 = a1;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: mac_freq Null",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wma_process_mac_freq_mapping");
      v33 = a1;
    }
    if ( (policy_mgr_is_hwmode_offload_enabled(*(_QWORD *)(v33 + 24), v23, v24, v25, v26, v27, v28, v29, v30) & 1) != 0 )
    {
      policy_mgr_hw_mode_transition_cb(
        *v22,
        v22[1],
        v22[2],
        (__int64)(v22 + 3),
        v22[11],
        (__int64)(v22 + 12),
        *(_QWORD *)(a1 + 24));
    }
    else
    {
      v42[4] = 0;
      v42[5] = 0;
      v42[2] = 0;
      v42[0] = 5227;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: post eWNI_SME_HW_MODE_TRANS_IND",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "wma_pdev_hw_mode_transition_evt_handler");
      v42[1] = v22;
      v42[3] = wma_discard_fw_event;
      if ( !(unsigned int)scheduler_post_message_debug(
                            0x36u,
                            0x34u,
                            52,
                            (unsigned __int16 *)v42,
                            0x1236u,
                            (__int64)"wma_pdev_hw_mode_transition_evt_handler") )
      {
LABEL_22:
        result = 0;
        goto LABEL_23;
      }
    }
    _qdf_mem_free((__int64)v22);
    goto LABEL_22;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: num_vdev_mac_entries: %d crossed max value: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_pdev_hw_mode_transition_evt_handler");
  result = 16;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
