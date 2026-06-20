__int64 __fastcall hif_update_pipe_callback(int a1, unsigned __int8 a2, int a3)
{
  unsigned int v3; // w22
  __int64 v7; // x0

  v3 = a2;
  v7 = qdf_trace_msg(61, 8, "%s: pipeid: %d", "hif_update_pipe_callback", a2);
  if ( v3 < 0xD )
    return qdf_mem_copy(a1 + 136 * (unsigned int)a2 + 27504, a3, 0x30u);
  __break(0x5512u);
  return hif_is_target_ready(v7);
}
