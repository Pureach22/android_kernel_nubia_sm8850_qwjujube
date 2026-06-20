__int64 *__fastcall _cam_isp_ctx_handle_deferred_buf_done_in_bubble(__int64 *result, __int64 a2)
{
  _DWORD *v2; // x21
  __int64 v3; // x22
  __int64 v5; // x20
  unsigned int v6; // w7
  unsigned int v7; // w8

  v2 = *(_DWORD **)(a2 + 32);
  v3 = *result;
  v5 = (__int64)result;
  if ( v2[14] )
    result = (__int64 *)_cam_isp_handle_deferred_buf_done(result, a2, v2[18] != 0, 3u, 0x34u);
  v6 = v2[13];
  v7 = v2[8];
  if ( v6 > v7
    && (result = (__int64 *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              8,
                              1,
                              "__cam_isp_ctx_handle_deferred_buf_done_in_bubble",
                              2487,
                              "WARNING: req_id %lld num_acked %d > map_out %d, ctx %u, link[0x%x]",
                              *(_QWORD *)(a2 + 24),
                              v6,
                              v7,
                              *(_DWORD *)(v3 + 32),
                              *(_DWORD *)(v3 + 64)),
        v6 = v2[13],
        v7 = v2[8],
        v6 > v7) )
  {
    __break(0x800u);
    if ( v2[13] != v2[8] )
      return result;
  }
  else if ( v6 != v7 )
  {
    return result;
  }
  return (__int64 *)_cam_isp_ctx_handle_buf_done_for_req_list(v5, (unsigned int *)a2);
}
