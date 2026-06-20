__int64 __fastcall _ll_lt_sap_is_bs_req_valid(
        unsigned __int8 *a1,
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
  const char *v10; // x2

  if ( a1 )
  {
    if ( *a1 < 6u )
    {
      if ( *((_DWORD *)a1 + 3) < 6u )
        return 1;
      v10 = "Invalid source %d in BS_SM request";
    }
    else
    {
      v10 = "Invalid vdev id %d in BS_SM request";
    }
    qdf_trace_msg(0xA1u, 2u, v10, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  else
  {
    qdf_trace_msg(0xA1u, 2u, "BS_SM request is null (via %s)", a3, a4, a5, a6, a7, a8, a9, a10, a2);
  }
  return 0;
}
