__int64 __fastcall sub_3BCD88(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        long double a9)
{
  __int64 v9; // x29
  __int128 v10; // q31

  *(long double *)v9 = a9;
  *(_OWORD *)(v9 + 16) = v10;
  return pe_find_session_by_vdev_id_and_state(a1, a2, a3);
}
