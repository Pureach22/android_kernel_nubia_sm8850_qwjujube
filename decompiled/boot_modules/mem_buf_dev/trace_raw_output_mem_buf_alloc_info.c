__int64 __fastcall trace_raw_output_mem_buf_alloc_info(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  unsigned int v4; // w21
  __int64 v5; // x20
  __int64 v6; // x24
  __int64 v7; // x25
  const char *v8; // x22
  const char *v9; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 16);
    v5 = *(_QWORD *)(v1 + 8);
    v6 = *(unsigned __int16 *)(v1 + 20);
    v7 = *(unsigned __int16 *)(v1 + 24);
    v8 = (const char *)trace_print_array_seq(a1 + 136, v1 + *(unsigned __int16 *)(v1 + 28), v4, 2);
    v9 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + *(unsigned __int16 *)(v1 + 32),
                         *(unsigned int *)(v1 + 16),
                         1);
    trace_event_printf(
      a1,
      "size: 0x%lx src mem type: %s dst mem type: %s nr ACL entries: %d ACL VMIDs: %s ACL Perms: %s\n",
      v5,
      (const char *)(v1 + v6),
      (const char *)(v1 + v7),
      v4,
      v8,
      v9);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
