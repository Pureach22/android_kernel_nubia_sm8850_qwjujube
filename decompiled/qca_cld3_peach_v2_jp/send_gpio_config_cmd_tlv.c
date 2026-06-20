__int64 __fastcall send_gpio_config_cmd_tlv(__int64 a1, _DWORD *a2)
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
  int v18; // w9
  int v19; // w6
  int v20; // w7
  int v21; // w9
  int v22; // w10
  int v23; // w11
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
  unsigned int v40; // w20
  __int64 v41; // [xsp+18h] [xbp-38h]
  __int64 v42; // [xsp+28h] [xbp-28h]

  if ( a2[2] > 2u || a2[3] > 5u || a2[1] > 1u )
    return 16;
  v42 = v3;
  v7 = wmi_buf_alloc_fl(a1, 0x20u, "send_gpio_config_cmd_tlv", 0x94u);
  if ( !v7 )
    return 16;
  v16 = *(_DWORD **)(v7 + 224);
  v17 = v7;
  *v16 = 10027036;
  v16[1] = *a2;
  v16[2] = a2[1] == 0;
  v18 = a2[2];
  if ( v18 == 2 )
    v19 = 2;
  else
    v19 = v18 == 1;
  v16[3] = v19;
  if ( (unsigned int)(a2[3] - 1) >= 5 )
    v20 = 0;
  else
    v20 = a2[3];
  v16[4] = v20;
  v21 = a2[4];
  v16[5] = v21;
  v22 = a2[5];
  v16[6] = v22;
  v23 = a2[6];
  v16[7] = v23;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: GPIO num %d, input-dir %d, pull_type %d, intr_mode %d mux_config_val %d drive %d init_enable %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "send_gpio_config_cmd_tlv",
    v21,
    v22,
    v23,
    v41,
    v2,
    v42);
  wmi_mtrace(0x1E001u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v17,
             0x20u,
             0x1E001u,
             "send_gpio_config_cmd_tlv",
             0xACu,
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
    v40 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Sending GPIO config cmd failed",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "send_gpio_config_cmd_tlv");
    wmi_buf_free();
    return v40;
  }
  return result;
}
