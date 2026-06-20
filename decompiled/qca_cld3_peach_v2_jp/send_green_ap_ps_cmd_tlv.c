__int64 __fastcall send_green_ap_ps_cmd_tlv(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  _DWORD *v15; // x23
  __int64 v16; // x20
  _DWORD *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Set Green AP PS val %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "send_green_ap_ps_cmd_tlv",
    a2);
  v14 = wmi_buf_alloc_fl(a1, 0xCu, "send_green_ap_ps_cmd_tlv", 0x9DCu);
  if ( !v14 )
    return 2;
  v15 = *(_DWORD **)(v14 + 224);
  v16 = v14;
  *v15 = 11141128;
  v17 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *(v17 - 1) != -2112860426 )
    __break(0x8228u);
  v15[1] = ((__int64 (__fastcall *)(__int64, _QWORD))v17)(a1, a3);
  v15[2] = a2;
  qdf_mtrace(49, 100, 0x20Bu, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0xCu,
             0x400Bu,
             "send_green_ap_ps_cmd_tlv",
             0x9ECu,
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
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Set Green AP PS param Failed val %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "send_green_ap_ps_cmd_tlv",
      a2);
    wmi_buf_free();
    return 16;
  }
  return result;
}
