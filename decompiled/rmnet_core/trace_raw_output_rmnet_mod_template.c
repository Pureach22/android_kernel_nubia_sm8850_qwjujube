__int64 __fastcall trace_raw_output_rmnet_mod_template(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "fun:%u ev:%u u1:%u u2:%u ul1:%llu ul2:%llu p1:0x%pK p2:0x%pK\n",
      *(unsigned __int8 *)(v1 + 8),
      *(unsigned __int8 *)(v1 + 9),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(const void **)(v1 + 40),
      *(const void **)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
