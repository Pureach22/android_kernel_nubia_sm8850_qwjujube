__int64 __fastcall lim_validate_received_frame_a1_addr(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  bool v11; // zf
  unsigned int v12; // w19
  const char *v13; // x2

  if ( a1 )
    v11 = a3 == 0;
  else
    v11 = 1;
  v12 = v11;
  if ( v11 )
  {
    v13 = "%s: mac or session context is null";
  }
  else
  {
    if ( (*a2 & 1) != 0 || !(unsigned int)qdf_mem_cmp(a2, (const void *)(a3 + 30), 6u) )
      return 1;
    v13 = "%s: Invalid A1 address in received frame";
  }
  qdf_trace_msg(0x35u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "lim_validate_received_frame_a1_addr");
  return v12;
}
