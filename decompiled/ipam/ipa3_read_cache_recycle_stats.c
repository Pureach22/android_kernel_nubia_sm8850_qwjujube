__int64 __fastcall ipa3_read_cache_recycle_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  v7 = scnprintf(
         dbg_buff,
         4096,
         "COAL  (cache) : Total number of pkts replenished =%llu\n"
         "COAL  (cache) : Number of pkts alloced  =%llu\n"
         "COAL  (cache) : Number of pkts not alloced  =%llu\n"
         "DEF   (cache) : Total number of pkts replenished =%llu\n"
         "DEF   (cache) : Number of pkts alloced  =%llu\n"
         "DEF   (cache) : Number of pkts not alloced  =%llu\n"
         "OTHER (cache) : Total number of packets replenished =%llu\n"
         "OTHER (cache) : Number of pkts alloced  =%llu\n"
         "OTHER (cache) : Number of pkts not alloced  =%llu\n",
         *(_QWORD *)(ipa3_ctx + 33000),
         *(_QWORD *)(ipa3_ctx + 32984),
         *(_QWORD *)(ipa3_ctx + 32992),
         *(_QWORD *)(ipa3_ctx + 33024),
         *(_QWORD *)(ipa3_ctx + 33008),
         *(_QWORD *)(ipa3_ctx + 33016),
         *(_QWORD *)(ipa3_ctx + 33048),
         *(_QWORD *)(ipa3_ctx + 33032),
         *(_QWORD *)(ipa3_ctx + 33040));
  return simple_read_from_buffer(a2, a3, a4, dbg_buff, v7);
}
