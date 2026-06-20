__int64 __fastcall qdf_print_thread_trace(__int64 a1)
{
  unsigned int v1; // w0
  __int64 result; // x0
  _QWORD v3[33]; // [xsp+8h] [xbp-108h] BYREF

  v3[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v3, 0, 256);
  v1 = stack_trace_save_tsk(a1, v3, 32, 0);
  result = stack_trace_print(v3, v1, 4);
  _ReadStatusReg(SP_EL0);
  return result;
}
