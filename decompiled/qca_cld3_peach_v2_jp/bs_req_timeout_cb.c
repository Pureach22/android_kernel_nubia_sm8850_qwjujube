__int64 __fastcall bs_req_timeout_cb(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x3
  __int64 v10; // x8
  unsigned int v11; // w1
  __int64 v12; // x0

  if ( a1[34] )
  {
    v9 = (__int64)(a1 + 32);
    if ( a1 == (_QWORD *)-256LL )
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM No request pending",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "bs_req_timeout_cb");
  }
  else if ( a1[39] )
  {
    v9 = (__int64)(a1 + 37);
    if ( a1 == (_QWORD *)-296LL )
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM No request pending",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "bs_req_timeout_cb");
  }
  else if ( a1[44] )
  {
    v9 = (__int64)(a1 + 42);
    if ( a1 == (_QWORD *)-336LL )
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM No request pending",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "bs_req_timeout_cb");
  }
  else if ( a1[49] )
  {
    v9 = (__int64)(a1 + 47);
    if ( a1 == (_QWORD *)-376LL )
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM No request pending",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "bs_req_timeout_cb");
  }
  else
  {
    if ( !a1[54] )
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM No request pending",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "bs_req_timeout_cb");
    v9 = (__int64)(a1 + 52);
    if ( a1 == (_QWORD *)-416LL )
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM No request pending",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "bs_req_timeout_cb");
  }
  v10 = *(_QWORD *)(*a1 + 152LL);
  if ( *(_DWORD *)(v9 + 8) == 1 )
    v11 = 2;
  else
    v11 = 3;
  if ( v10 )
    v12 = *(_QWORD *)(v10 + 80);
  else
    v12 = 0;
  return bs_sm_deliver_event(v12, v11, 0x28u, v9);
}
