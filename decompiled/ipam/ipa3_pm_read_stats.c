__int64 __fastcall ipa3_pm_read_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w3

  v7 = ipa_pm_stat(dbg_buff, 4096);
  if ( v7 < 0 )
    v7 = scnprintf(dbg_buff, 4096, "Error in printing PM stat %d\n", v7);
  return simple_read_from_buffer(a2, a3, a4, dbg_buff, v7);
}
