__int64 __fastcall sub_1DCCC4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        long double *a7,
        double a8,
        double a9,
        long double a10)
{
  *a7 = a10;
  a7[1] = a10;
  return cm_add_connect_req_to_list(a1, a2, a3, a4, a5, a6, a7 + 7);
}
