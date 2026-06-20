__int64 __fastcall send_gpio_output_cmd_tlv(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 result; // x0
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _DWORD *v16; // x8
  __int64 v17; // x19
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
  unsigned int v34; // w20
  __int64 v35; // [xsp+8h] [xbp-28h]

  if ( a2[1] > 1u )
    return 16;
  v35 = v3;
  v7 = wmi_buf_alloc_fl(a1, 0xCu, "send_gpio_output_cmd_tlv", 0xCEu);
  if ( !v7 )
    return 16;
  v16 = *(_DWORD **)(v7 + 224);
  v17 = v7;
  *v16 = 10092552;
  v16[1] = *a2;
  v16[2] = a2[1] == 1;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: GPIO num %d, set %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "send_gpio_output_cmd_tlv",
    v2,
    v35);
  wmi_mtrace(0x1E002u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v17,
             0xCu,
             0x1E002u,
             "send_gpio_output_cmd_tlv",
             0xDDu,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    v34 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Sending GPIO output cmd failed",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_gpio_output_cmd_tlv");
    wmi_buf_free();
    return v34;
  }
  return result;
}
