__int64 __fastcall wma_get_rcpi_req(
        __int64 *a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x22
  const char *v21; // x2
  unsigned int v22; // w1
  __int64 result; // x0
  _QWORD *v24; // x0
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x21
  __int64 v29; // [xsp+Ch] [xbp-14h] BYREF
  int v30; // [xsp+14h] [xbp-Ch]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  HIDWORD(v29) = 0;
  qdf_trace_msg(0x36u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wma_get_rcpi_req");
  v20 = a1[65] + 488LL * *(unsigned int *)a2;
  if ( *(_QWORD *)(v20 + 272) )
  {
    v21 = "%s: previous rcpi request is pending";
    v22 = 2;
  }
  else
  {
    v24 = (_QWORD *)_qdf_mem_malloc(0x20u, "wma_get_rcpi_req", 4286);
    if ( !v24 )
    {
      result = 2;
      goto LABEL_4;
    }
    v25 = a2[1];
    v26 = a2[2];
    v27 = a2[3];
    v28 = (__int64)v24;
    *v24 = *a2;
    v24[1] = v25;
    v24[2] = v26;
    v24[3] = v27;
    *(_QWORD *)(v20 + 272) = v24;
    qdf_mem_copy((char *)&v29 + 4, a2 + 3, 6u);
    if ( (unsigned int)wmi_unified_send_request_get_rcpi_cmd(*a1) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to send WMI_REQUEST_RCPI_CMDID",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wma_get_rcpi_req");
      *(_QWORD *)(v20 + 272) = 0;
      _qdf_mem_free(v28);
      result = 16;
      goto LABEL_4;
    }
    v21 = "%s: Exit";
    v22 = 8;
  }
  qdf_trace_msg(0x36u, v22, v21, v12, v13, v14, v15, v16, v17, v18, v19, "wma_get_rcpi_req");
  result = 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
