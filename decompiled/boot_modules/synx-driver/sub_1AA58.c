__int64 __fastcall sub_1AA58(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        long double a8)
{
  __int64 v8; // x16
  __int128 v9; // q24

  *(_OWORD *)v8 = v9;
  *(long double *)(v8 + 16) = a8;
  return synx_global_test_status_set_parent_child_wait(a1, a2);
}
