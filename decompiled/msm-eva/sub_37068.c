__int64 __fastcall sub_37068(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        long double a11)
{
  __int128 v11; // q20

  *(_OWORD *)a6 = v11;
  *(long double *)(a6 + 16) = a11;
  return cvp_create_pkt_cmd_session_release_buffers(a1, a2, a3, a4, a5, a6 + 736);
}
