__int64 __fastcall sir_convert_qos_map_configure_frame2_struct(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _BYTE *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v9; // w20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  _QWORD v31[9]; // [xsp+8h] [xbp-48h] BYREF

  v9 = a3;
  v31[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v31, 0, 62);
  v12 = dot11f_unpack_qos_map_configure(a1, a2, a3, (__int64)v31, 0, a6, a7, a8);
  if ( (v12 & 0x10000000) != 0 || (v21 = BYTE2(v31[0])) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to parse Qos Map Configure frame (0x%08x, %d bytes):",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sir_convert_qos_map_configure_frame2_struct",
      v12,
      v9);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a2, v9);
    result = 16;
  }
  else
  {
    if ( v12 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: There were warnings while unpacking Qos Map Configure frame (0x%08x, %d bytes):",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sir_convert_qos_map_configure_frame2_struct",
        v12,
        v9);
      v21 = BYTE2(v31[0]);
    }
    *a4 = v21;
    ((void (__fastcall *)(__int64, _BYTE *, char *))convert_qos_mapset_frame)(a1, a4, (char *)v31 + 2);
    if ( (unsigned __int8)a4[1] >= 0x16u )
      a4[1] = 21;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: num of dscp exceptions: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "lim_log_qos_map_set");
    ((void (__fastcall *)(__int64, __int64, _BYTE *, __int64))qdf_trace_hex_dump)(53, 8, a4 + 2, 42);
    ((void (__fastcall *)(__int64, __int64, _BYTE *, __int64))qdf_trace_hex_dump)(53, 8, a4 + 44, 16);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
