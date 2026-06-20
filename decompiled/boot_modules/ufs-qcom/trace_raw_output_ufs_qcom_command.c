__int64 __fastcall trace_raw_output_ufs_qcom_command(__int64 a1)
{
  __int64 v1; // x25
  __int64 result; // x0
  __int64 v4; // x26
  __int64 v5; // x0
  int v6; // w23
  int v7; // w22
  const char *v8; // x24
  int v9; // w20
  int v10; // w21
  const char *v11; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 8);
    v5 = trace_print_symbols_seq(a1 + 136, *(int *)(v1 + 12), &trace_raw_output_ufs_qcom_command_symbols);
    v6 = *(unsigned __int8 *)(v1 + 16);
    v7 = *(_DWORD *)(v1 + 28);
    v8 = (const char *)v5;
    v9 = *(_DWORD *)(v1 + 20);
    v10 = *(_DWORD *)(v1 + 24);
    v11 = (const char *)trace_print_symbols_seq(
                          a1 + 136,
                          *(unsigned __int8 *)(v1 + 16),
                          &trace_raw_output_ufs_qcom_command_symbols_72);
    trace_event_printf(
      a1,
      "%s: %s: tag: %d, DB: 0x%x, size: %d, opcode: 0x%x (%s)\n",
      (const char *)(v1 + v4),
      v8,
      v9,
      v10,
      v7,
      v6,
      v11);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
