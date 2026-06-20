__int64 __fastcall trace_raw_output_alloc_req_msg_class(__int64 a1)
{
  __int64 v1; // x24
  __int64 result; // x0
  unsigned int v4; // w22
  int v5; // w20
  __int64 v6; // x25
  __int64 v7; // x21
  __int64 v8; // x26
  const char *v9; // x23
  const char *v10; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 28);
    v5 = *(_DWORD *)(v1 + 8);
    v6 = *(unsigned __int16 *)(v1 + 12);
    v7 = *(_QWORD *)(v1 + 16);
    v8 = *(unsigned __int16 *)(v1 + 24);
    v9 = (const char *)trace_print_array_seq(a1 + 136, v1 + *(unsigned __int16 *)(v1 + 32), v4, 2);
    v10 = (const char *)trace_print_array_seq(
                          a1 + 136,
                          v1 + *(unsigned __int16 *)(v1 + 36),
                          *(unsigned int *)(v1 + 28),
                          1);
    trace_event_printf(
      a1,
      "txn_id: %d msg_type: %s alloc_sz: 0x%llx src_mem_type: %s nr ACL entries: %d ACL VMIDs: %s ACL Perms: %s\n",
      v5,
      (const char *)(v1 + v6),
      v7,
      (const char *)(v1 + v8),
      v4,
      v9,
      v10);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
