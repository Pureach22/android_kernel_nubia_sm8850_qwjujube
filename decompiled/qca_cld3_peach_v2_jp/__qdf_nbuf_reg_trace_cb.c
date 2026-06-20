__int64 __fastcall _qdf_nbuf_reg_trace_cb(__int64 result)
{
  qdf_trace_update_cb = result;
  return result;
}
