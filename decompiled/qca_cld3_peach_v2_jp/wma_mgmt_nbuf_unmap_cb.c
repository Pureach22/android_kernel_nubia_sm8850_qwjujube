__int64 __fastcall wma_mgmt_nbuf_unmap_cb(
        __int64 result,
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
  __int64 v10; // x8

  if ( a2 )
  {
    v10 = *(_QWORD *)(result + 80);
    if ( v10 )
      return _qdf_nbuf_unmap_single(*(_QWORD *)(v10 + 2120), a2, 1);
    else
      return qdf_trace_msg(0x36u, 2u, "%s: Psoc handle NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_mgmt_nbuf_unmap_cb");
  }
  return result;
}
