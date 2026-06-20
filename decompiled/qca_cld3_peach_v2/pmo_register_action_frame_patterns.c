__int64 __fastcall pmo_register_action_frame_patterns(__int64 a1, int a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  int v14; // w9
  _DWORD *v15; // x19
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x21
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w22
  int v30; // w0
  int v31; // w0
  int v32; // w0
  int v33; // w0
  int v34; // w0
  int v35; // w0
  int v36; // w0
  unsigned int v37; // w20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v47; // [xsp+8h] [xbp-28h] BYREF
  __int64 v48; // [xsp+10h] [xbp-20h]
  __int64 v49; // [xsp+18h] [xbp-18h]
  __int64 v50; // [xsp+20h] [xbp-10h]
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = _qdf_mem_malloc(0x428u, "pmo_register_action_frame_patterns", 477);
  if ( v4 )
  {
    v13 = *(unsigned __int8 *)(a1 + 168);
    *(_QWORD *)(v4 + 24) = 0;
    *(_QWORD *)(v4 + 32) = 0;
    *(_DWORD *)v4 = v13;
    *(_DWORD *)(v4 + 4) = 1;
    *(_QWORD *)(v4 + 12) = 48;
    if ( a2 )
      v14 = 3016499;
    else
      v14 = 3016467;
    *(_DWORD *)(v4 + 20) = 0x40000000;
    v15 = (_DWORD *)v4;
    *(_DWORD *)(v4 + 40) = 5;
    *(_DWORD *)(v4 + 8) = v14;
    *(_DWORD *)(v4 + 56) = 128;
    v16 = *(_QWORD *)(a1 + 216);
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    v17 = *(_QWORD *)(v16 + 80);
    if ( v17 )
    {
      wlan_cm_roam_cfg_get_value(v17, *(unsigned __int8 *)(a1 + 168), 0x1Fu, &v47);
      if ( (unsigned __int8)v48 == 1 )
        v15[20] = 448;
    }
    v18 = _qdf_mem_malloc(0x15Eu, "pmo_register_action_frame_patterns", 506);
    if ( v18 )
    {
      v19 = v18;
      v21 = scnprintf(v18, 350, " %d[0x%x]", 0, v15[2]);
      if ( v20 >= 1 )
      {
        v29 = v20;
        if ( (unsigned int)v20 >= 0x14A )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "serial_num[action wakeup pattern in fw]:%s",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v19);
          v29 = 0;
        }
        v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 1, v15[3]);
        if ( v30 >= 1 )
        {
          v29 += v30;
          if ( v29 >= 0x14A )
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "serial_num[action wakeup pattern in fw]:%s",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v19);
            v29 = 0;
          }
          v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 2, v15[4]);
          if ( v31 >= 1 )
          {
            v29 += v31;
            if ( v29 >= 0x14A )
            {
              qdf_trace_msg(
                0x4Du,
                8u,
                "serial_num[action wakeup pattern in fw]:%s",
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v19);
              v29 = 0;
            }
            v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 3, v15[5]);
            if ( v32 >= 1 )
            {
              v29 += v32;
              if ( v29 >= 0x14A )
              {
                qdf_trace_msg(
                  0x4Du,
                  8u,
                  "serial_num[action wakeup pattern in fw]:%s",
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v19);
                v29 = 0;
              }
              v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 4, v15[6]);
              if ( v33 >= 1 )
              {
                v29 += v33;
                if ( v29 >= 0x14A )
                {
                  qdf_trace_msg(
                    0x4Du,
                    8u,
                    "serial_num[action wakeup pattern in fw]:%s",
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v19);
                  v29 = 0;
                }
                v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 5, v15[7]);
                if ( v34 >= 1 )
                {
                  v29 += v34;
                  if ( v29 >= 0x14A )
                  {
                    qdf_trace_msg(
                      0x4Du,
                      8u,
                      "serial_num[action wakeup pattern in fw]:%s",
                      v21,
                      v22,
                      v23,
                      v24,
                      v25,
                      v26,
                      v27,
                      v28,
                      v19);
                    v29 = 0;
                  }
                  v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 6, v15[8]);
                  if ( v35 >= 1 )
                  {
                    v29 += v35;
                    if ( v29 >= 0x14A )
                    {
                      qdf_trace_msg(
                        0x4Du,
                        8u,
                        "serial_num[action wakeup pattern in fw]:%s",
                        v21,
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v19);
                      v29 = 0;
                    }
                    v21 = scnprintf(v19 + v29, 350 - v29, " %d[0x%x]", 7, v15[9]);
                    if ( v36 > 0 )
                      goto LABEL_32;
                  }
                }
              }
            }
          }
        }
        if ( v29 )
LABEL_32:
          qdf_trace_msg(
            0x4Du,
            8u,
            "serial_num[action wakeup pattern in fw]:%s",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v19);
      }
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Action frame drop bitmasks - spec_mgmt: %x public_usage: %x wnm: %x",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "pmo_register_action_frame_patterns",
        (unsigned int)v15[10],
        (unsigned int)v15[14],
        (unsigned int)v15[20]);
      v37 = pmo_tgt_send_action_frame_pattern_req(a1, v15);
      if ( v37 )
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: Failed to config wow action frame map, ret %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "pmo_register_action_frame_patterns",
          v37);
      _qdf_mem_free((__int64)v15);
      _qdf_mem_free(v19);
    }
    else
    {
      _qdf_mem_free((__int64)v15);
      v37 = -12;
    }
  }
  else
  {
    v37 = 2;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: memory allocation failed for wakeup set params",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "pmo_register_action_frame_patterns");
  }
  _ReadStatusReg(SP_EL0);
  return v37;
}
