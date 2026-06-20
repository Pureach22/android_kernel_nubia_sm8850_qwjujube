__int64 __fastcall osif_twt_create_work(_QWORD *a1)
{
  a1[175] = osif_twt_work_handler;
  a1[171] = 0xFFFFFFFE00000LL;
  a1[176] = a1;
  a1[172] = a1 + 172;
  a1[173] = a1 + 172;
  a1[174] = _qdf_defer_func;
  return 0;
}
