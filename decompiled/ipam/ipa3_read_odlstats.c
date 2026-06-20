__int64 __fastcall ipa3_read_odlstats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  v7 = scnprintf(
         dbg_buff,
         4096,
         "ODL received pkt =%u\nODL processed pkt to DIAG=%u\nODL dropped pkt =%u\nODL packet in queue  =%u\n",
         *(_DWORD *)(ipa3_odl_ctx + 700),
         *(_DWORD *)(ipa3_odl_ctx + 704),
         *(_DWORD *)(ipa3_odl_ctx + 708),
         *(_DWORD *)(ipa3_odl_ctx + 712));
  return simple_read_from_buffer(a2, a3, a4, dbg_buff, v7);
}
