__int64 __fastcall dp_srng_deinit(
        __int64 a1,
        __int64 *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v14; // x1
  __int64 v15; // x6
  __int64 v16; // x5
  void (*v18)(void); // x8
  __int64 result; // x0

  v14 = *a2;
  v15 = (unsigned int)a4;
  v16 = a3;
  if ( !v14 )
    return qdf_trace_msg(
             0x7Cu,
             2u,
             "%s: %pK: Ring type: %d, num:%d not setup",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "dp_srng_deinit",
             a1,
             a3,
             (unsigned int)a4);
  v18 = *(void (**)(void))(a1 + 1704);
  if ( v18 )
  {
    if ( *((_DWORD *)v18 - 1) != -1607343988 )
      __break(0x8228u);
    v18();
    v14 = *a2;
  }
  result = hal_srng_cleanup(*(_QWORD *)(a1 + 1128), v14, 0, a4, a5, v16, v15);
  *a2 = 0;
  return result;
}
