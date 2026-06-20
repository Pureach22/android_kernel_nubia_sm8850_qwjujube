__int64 __fastcall sme_dhcp_done_ind(
        __int64 result,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8

  if ( result )
  {
    if ( a2 <= 5u && (v12 = *(_QWORD *)(result + 17224) + 96LL * a2) != 0 )
    {
      *(_BYTE *)(v12 + 88) = 0;
      *(_BYTE *)(v12 + 62) = 1;
    }
    else
    {
      return qdf_trace_msg(
               0x34u,
               2u,
               "%s: Session: %d not found",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "sme_dhcp_done_ind",
               v10,
               v11);
    }
  }
  return result;
}
