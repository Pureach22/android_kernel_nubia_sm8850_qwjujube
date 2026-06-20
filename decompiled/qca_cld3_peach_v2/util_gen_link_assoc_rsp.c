__int64 __fastcall util_gen_link_assoc_rsp(
        char *a1,
        unsigned __int64 a2,
        char a3,
        unsigned int a4,
        __int64 a5,
        char *a6,
        unsigned __int64 a7,
        __int64 *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 v16; // x4
  unsigned __int8 v17; // w2

  v16 = a5 & 0xFFFFFFFFFFFFLL;
  if ( (a3 & 1) != 0 )
    v17 = 3;
  else
    v17 = 1;
  return util_gen_link_reqrsp_cmn(a1, a2, v17, a4, v16, nullptr, a6, a7, a9, a10, a11, a12, a13, a14, a15, a16, a8);
}
