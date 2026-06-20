__int64 __fastcall wma_send_bss_color_change_enable(
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
  unsigned int v10; // w19
  __int64 result; // x0
  const char *v12; // x2
  unsigned int v13; // w1

  v10 = *(unsigned __int8 *)(a2 + 143);
  if ( (*(_BYTE *)(a2 + 164) & 1) != 0 )
  {
    result = wmi_unified_send_bss_color_change_enable_cmd(*a1);
    if ( !(_DWORD)result )
      return result;
    v12 = "%s: Failed to enable bss color change offload, vdev:%d";
    v13 = 2;
  }
  else
  {
    v12 = "%s: he_capable is not set for vdev_id:%d";
    v13 = 8;
  }
  return qdf_trace_msg(0x36u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wma_send_bss_color_change_enable", v10);
}
