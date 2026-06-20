__int64 __fastcall hdd_any_adapter_connected(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char is_any_adapter_connected; // w0

  if ( a1 )
  {
    is_any_adapter_connected = hdd_is_any_adapter_connected(a1);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is null", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_any_adapter_connected");
    is_any_adapter_connected = 0;
  }
  return is_any_adapter_connected & 1;
}
