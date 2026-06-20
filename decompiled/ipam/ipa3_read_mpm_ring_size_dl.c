__int64 __fastcall ipa3_read_mpm_ring_size_dl(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  v7 = scnprintf(&dbg_buff, 4096, "IPA_MPM_RING_SIZE_DL = %d\n", *(_DWORD *)(ipa3_ctx + 43268));
  return simple_read_from_buffer(a2, a3, a4, &dbg_buff, v7);
}
