__int64 __fastcall ipa3_read_page_wq_reschd_time(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  v7 = scnprintf(dbg_buff, 4096, "Page WQ reschduule time = %d\n", *(_DWORD *)(ipa3_ctx + 51400));
  return simple_read_from_buffer(a2, a3, a4, dbg_buff, v7);
}
