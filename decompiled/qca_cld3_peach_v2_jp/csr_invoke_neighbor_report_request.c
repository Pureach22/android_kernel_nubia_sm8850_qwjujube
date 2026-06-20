__int64 __fastcall csr_invoke_neighbor_report_request(
        unsigned __int8 a1,
        _BYTE *a2,
        char a3,
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 result; // x0
  size_t v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( a2 )
  {
    v14 = _qdf_mem_malloc(0x2Cu, "csr_invoke_neighbor_report_request", 6708);
    if ( v14 )
    {
      v23 = v14;
      *(_DWORD *)v14 = a1;
      *(_DWORD *)(v14 + 4) = a3 & 1;
      if ( *a2 )
      {
        *(_BYTE *)(v14 + 8) = 0;
      }
      else
      {
        v25 = (unsigned __int8)a2[1];
        *(_BYTE *)(v14 + 8) = v25;
        qdf_mem_copy((void *)(v14 + 9), a2 + 2, v25);
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Sending SIR_HAL_INVOKE_NEIGHBOR_REPORT",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "csr_invoke_neighbor_report_request");
      LODWORD(v34) = 4523;
      v35 = v23;
      result = scheduler_post_message_debug(
                 0x34u,
                 0x36u,
                 54,
                 (unsigned __int16 *)&v34,
                 0x1A4Du,
                 (__int64)"csr_invoke_neighbor_report_request");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post message to WMA",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "csr_invoke_neighbor_report_request");
        _qdf_mem_free(v23);
        result = 16;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid params",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "csr_invoke_neighbor_report_request");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
