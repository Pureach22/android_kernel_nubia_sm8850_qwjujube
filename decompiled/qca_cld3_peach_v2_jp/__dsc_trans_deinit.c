__int64 __fastcall _dsc_trans_deinit(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x19

  v9 = (_QWORD *)result;
  if ( *(_DWORD *)(result + 24) )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: list length not equal to zero",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "qdf_list_destroy");
  *v9 = 0;
  return result;
}
