__int64 __fastcall _lim_process_link_measurement_req(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  unsigned int v4; // w21
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  int v18; // [xsp+0h] [xbp-10h] BYREF
  char v19; // [xsp+4h] [xbp-Ch]
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v3 = *(_QWORD *)(a2 + 24);
    v4 = *(_DWORD *)(a2 + 40);
    v19 = 0;
    v18 = 0;
    v8 = dot11f_unpack_link_measurement_request(a1, v3, v4, &v18, 0);
    if ( (v8 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to unpack and parse a Link Measure request (0x%08x, %d bytes):",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "__lim_process_link_measurement_req",
        v8,
        v4);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, v3, v4);
      result = 16;
      goto LABEL_10;
    }
    if ( v8 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: There were warnings while unpacking a Link Measure request (0x%08x, %d bytes):",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "__lim_process_link_measurement_req",
        v8,
        v4);
    if ( *(_BYTE *)(a3 + 10070) != 1 )
    {
      result = rrm_process_link_measurement_request(a1, a2, &v18, a3);
      goto LABEL_10;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: STA power has changed, reject the link measurement request",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "__lim_process_link_measurement_req");
  }
  result = 16;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
