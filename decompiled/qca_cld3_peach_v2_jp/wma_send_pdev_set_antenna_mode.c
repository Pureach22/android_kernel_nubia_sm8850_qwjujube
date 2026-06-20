__int64 __fastcall wma_send_pdev_set_antenna_mode(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x19
  unsigned int v23; // w9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w21
  unsigned int v33; // w20
  __int64 result; // x0
  _DWORD *v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x19
  _QWORD v45[7]; // [xsp+8h] [xbp-38h] BYREF

  v45[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( a2 )
    {
      v12 = wmi_buf_alloc_fl(*a1, 0xCu, "wma_send_pdev_set_antenna_mode", 0x28A9u);
      if ( v12 )
      {
        v21 = *(_QWORD *)(v12 + 224);
        v22 = v12;
        *(_QWORD *)v21 = 33882120;
        v23 = a2[1];
        *(_DWORD *)(v21 + 8) = v23;
        *(_DWORD *)(v21 + 8) = v23 | (*a2 << 16);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Num of chains TX: %d RX: %d txrx_chains: 0x%x",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wma_send_pdev_set_antenna_mode",
          *a2,
          a2[1]);
        if ( (unsigned int)wmi_unified_cmd_send_fl(
                             *a1,
                             v22,
                             0xCu,
                             0x4020u,
                             "wma_send_pdev_set_antenna_mode",
                             0x28BFu,
                             v24,
                             v25,
                             v26,
                             v27,
                             v28,
                             v29,
                             v30,
                             v31) )
        {
          wmi_buf_free();
          v32 = 16;
          v33 = 2;
        }
        else
        {
          v33 = 0;
          v32 = 0;
        }
      }
      else
      {
        v33 = 2;
        v32 = 2;
      }
      v35 = (_DWORD *)_qdf_mem_malloc(4u, "wma_send_pdev_set_antenna_mode", 10439);
      if ( v35 )
      {
        v44 = (__int64)v35;
        *v35 = v33;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Send antenna mode resp to LIM status: %d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "wma_send_pdev_set_antenna_mode",
          v33);
        v45[1] = v44;
        v45[0] = 4249;
        v45[4] = 0;
        v45[5] = 0;
        v45[2] = 0;
        v45[3] = wma_discard_fw_event;
        if ( (unsigned int)scheduler_post_msg_by_priority(53, (unsigned __int16 *)v45, 0) )
          _qdf_mem_free(v44);
        result = v32;
      }
      else
      {
        result = 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Set antenna mode param is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wma_send_pdev_set_antenna_mode");
      result = 29;
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
      "wma_send_pdev_set_antenna_mode");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
