__int64 __fastcall lim_check_disassoc_deauth_ack_pending(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const void *v10; // x8
  const void *v11; // x19
  unsigned int v13; // w19
  const char *v14; // x2

  v10 = *(const void **)(a1 + 12392);
  v11 = *(const void **)(a1 + 12400);
  if ( v10 && !(unsigned int)qdf_mem_cmp(a2, v10, 6u) || v11 && !(unsigned int)qdf_mem_cmp(a2, v11, 6u) )
  {
    v13 = 1;
    v14 = "%s: Disassoc/Deauth ack pending";
  }
  else
  {
    v13 = 0;
    v14 = "%s: Disassoc/Deauth Ack not pending";
  }
  qdf_trace_msg(0x35u, 8u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_check_disassoc_deauth_ack_pending");
  return v13;
}
