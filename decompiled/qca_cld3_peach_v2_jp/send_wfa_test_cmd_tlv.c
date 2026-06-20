__int64 __fastcall send_wfa_test_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v2; // w9
  int v4; // w11
  int v6; // w22
  int v7; // w23
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _DWORD *v17; // x11
  __int64 v18; // x19
  _DWORD *v19; // x10
  __int64 result; // x0
  _DWORD *v21; // x9
  unsigned __int8 v22; // w10
  _DWORD *v23; // x10
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v2 = *((_DWORD *)a2 + 2);
  if ( v2 >= 2 )
    v4 = 12;
  else
    v4 = 20;
  if ( v2 == 2 )
    v6 = 24;
  else
    v6 = v4;
  if ( v2 == 3 )
    v7 = 20;
  else
    v7 = 12;
  v8 = wmi_buf_alloc_fl(a1, v7 + v6, "send_wfa_test_cmd_tlv", 0x304Eu);
  if ( !v8 )
    return 2;
  v17 = *(_DWORD **)(v8 + 224);
  v18 = v8;
  *v17 = 60686340;
  v17[1] = *a2;
  if ( *((_DWORD *)a2 + 2) )
  {
    v19 = v17 + 3;
    v17[2] = 1179648;
  }
  else
  {
    v17[2] = 1179656;
    v17[3] = 60751876;
    v17[4] = *((_DWORD *)a2 + 1);
    v19 = v17 + 5;
  }
  if ( *((_DWORD *)a2 + 2) == 1 )
  {
    *v19 = 1179656;
    v19[1] = 60817412;
    v19[2] = *((_DWORD *)a2 + 1);
    v21 = v19 + 3;
  }
  else
  {
    v21 = v19 + 1;
    *v19 = 1179648;
  }
  if ( *((_DWORD *)a2 + 2) == 2 )
  {
    *v21 = 1179660;
    v21[1] = 60882952;
    v22 = **((_BYTE **)a2 + 2) - 1;
    if ( v22 >= 8u || ((0x8Bu >> v22) & 1) == 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid command type cmd %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "wmi_fill_ocv_frame_type");
LABEL_29:
      wmi_buf_free();
      return 16;
    }
    v21[2] = dword_A30250[(unsigned __int8)(**((_BYTE **)a2 + 2) - 1)];
    v21[3] = *(_DWORD *)(*((_QWORD *)a2 + 2) + 4LL);
    v23 = v21 + 4;
  }
  else
  {
    v23 = v21 + 1;
    *v21 = 1179648;
  }
  if ( *((_DWORD *)a2 + 2) == 3 )
  {
    *v23 = 1179656;
    v23[1] = 60948484;
    v23[2] = *((_DWORD *)a2 + 1);
  }
  else
  {
    *v23 = 1179648;
  }
  qdf_mtrace(49, 100, 0xF87u, *a2, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v18,
             v7 + v6,
             0x1F007u,
             "send_wfa_test_cmd_tlv",
             0x309Au,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send wfa test command",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "send_wfa_test_cmd_tlv");
    goto LABEL_29;
  }
  return result;
}
