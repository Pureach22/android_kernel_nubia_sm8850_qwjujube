__int64 __fastcall sub_11AD9C(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        long double a8)
{
  __int64 v8; // x17
  __int128 v9; // q14

  *(long double *)v8 = a8;
  *(_OWORD *)(v8 + 16) = v9;
  return cam_packet_util_get_cmd_mem_addr();
}
