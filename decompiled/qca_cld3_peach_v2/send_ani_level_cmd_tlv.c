__int64 __fastcall send_ani_level_cmd_tlv(__int64 a1, int *a2, unsigned __int8 a3)
{
  int v3; // w24
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
  _DWORD *v18; // x25
  __int64 v19; // x26
  int v20; // t1
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v3 = 4 * a3;
  v7 = wmi_buf_alloc_fl(a1, v3 + 8, "send_ani_level_cmd_tlv", 0x5102u);
  if ( v7 )
  {
    v16 = *(_DWORD **)(v7 + 224);
    v17 = v7;
    *v16 = 55312384;
    v16[1] = v3 | 0x100000;
    if ( a3 )
    {
      v18 = v16 + 2;
      v19 = a3;
      do
      {
        v20 = *a2++;
        *v18++ = v20;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Requesting ANI for channel[%d]",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "send_ani_level_cmd_tlv");
        --v19;
      }
      while ( v19 );
    }
    v21 = wmi_unified_cmd_send_fl(
            a1,
            v17,
            v3 + 8,
            0x1D01Du,
            "send_ani_level_cmd_tlv",
            0x5118u,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15);
    if ( v21 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_GET_CHANNEL_ANI_CMDID send error %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "send_ani_level_cmd_tlv",
        v21);
      wmi_buf_free();
    }
  }
  else
  {
    return 16;
  }
  return v21;
}
