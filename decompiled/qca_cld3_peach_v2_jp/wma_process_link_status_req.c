__int64 __fastcall wma_process_link_status_req(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  __int64 *v12; // x20
  __int64 v13; // t1
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  _ReadStatusReg(SP_EL0);
  v11 = a1[65] + 488LL * *(unsigned __int8 *)(a2 + 5);
  v13 = *(_QWORD *)(v11 + 248);
  v12 = (__int64 *)(v11 + 248);
  if ( v13 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: previous link status request is pending,deleting the new request",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_process_link_status_req");
    result = _qdf_mem_free(a2);
  }
  else
  {
    *v12 = a2;
    result = wmi_unified_link_status_req_cmd(*a1);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to send WMI link  status request to fw",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wma_process_link_status_req");
      *v12 = 0;
      result = wma_post_link_status(a2, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
