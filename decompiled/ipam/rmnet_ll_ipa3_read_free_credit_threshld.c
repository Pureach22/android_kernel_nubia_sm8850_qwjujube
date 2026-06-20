__int64 __fastcall rmnet_ll_ipa3_read_free_credit_threshld(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  v7 = scnprintf(&dbg_buff_3, 4096, "Free credit Threshold = %d\n", *(_DWORD *)(rmnet_ll_ipa3_ctx + 644));
  return simple_read_from_buffer(a2, a3, a4, &dbg_buff_3, v7);
}
