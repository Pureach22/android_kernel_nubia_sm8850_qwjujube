__int64 __fastcall dp_fim_flow_expiry_timer_cb(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _BYTE *v9; // x19
  __int64 v10; // x20
  unsigned int multiplier; // w0

  if ( result )
  {
    v9 = (_BYTE *)result;
    qdf_trace_msg(0x45u, 5u, "%s: FIM timer expiry", a2, a3, a4, a5, a6, a7, a8, a9, "dp_fim_flow_expiry_timer_cb");
    result = dp_fim_hash_table_delete_node((__int64)v9, nullptr, 0, 1);
    if ( *v9 == 1 )
    {
      v10 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      return mod_timer(v9 + 2136, v10 + 30000LL * multiplier);
    }
  }
  return result;
}
