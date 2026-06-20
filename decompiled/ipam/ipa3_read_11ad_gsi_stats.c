__int64 __fastcall ipa3_read_11ad_gsi_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x10u )
    return 0;
  v7 = scnprintf(dbg_buff, 4096, "This feature only support on IPA4.5+\n");
  return simple_read_from_buffer(a2, a3, a4, dbg_buff, v7);
}
