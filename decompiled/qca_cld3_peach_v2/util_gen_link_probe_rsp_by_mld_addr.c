__int64 __fastcall util_gen_link_probe_rsp_by_mld_addr(
        char *a1,
        unsigned __int64 a2,
        unsigned int a3,
        __int64 a4,
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
  __int64 result; // x0
  unsigned int v17; // [xsp+10h] [xbp-10h] BYREF
  __int16 v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = a5;
  v18 = WORD2(a5);
  result = util_gen_link_reqrsp_cmn(
             a1,
             a2,
             5u,
             a3,
             a4 & 0xFFFFFFFFFFFFLL,
             &v17,
             a6,
             a7,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             a16,
             a8);
  _ReadStatusReg(SP_EL0);
  return result;
}
