__int64 __fastcall osif_twt_create_work(_QWORD *a1)
{
  a1[165] = osif_twt_work_handler;
  a1[161] = 0xFFFFFFFE00000LL;
  a1[166] = a1;
  a1[162] = a1 + 162;
  a1[163] = a1 + 162;
  a1[164] = _qdf_defer_func;
  return 0;
}
