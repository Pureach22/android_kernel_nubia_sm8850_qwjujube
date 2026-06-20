__int64 __fastcall tdls_handle_link_unforce(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  __int64 result; // x0
  _QWORD v11[11]; // [xsp+8h] [xbp-58h] BYREF

  v11[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 104);
  v11[0] = a1;
  memset(&v11[1], 0, 56);
  v11[8] = 983040;
  v11[9] = 0;
  qdf_trace_msg(0, 8u, "%s: set vdev %d unforce", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_handle_link_unforce", v9);
  result = tdls_set_link_mode(v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
