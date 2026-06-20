__int64 __fastcall sub_6E09D8(double a1, double a2, double a3, double a4, long double a5)
{
  __int64 v5; // x19
  __int128 v6; // q20

  *(long double *)v5 = a5;
  *(_OWORD *)(v5 + 16) = v6;
  return mlo_link_recfg_sm_deliver_event();
}
