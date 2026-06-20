__int64 __fastcall ipa3_read_lan_coal_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  unsigned int v8; // w26
  int v9; // w0
  int v10; // w0
  __int64 result; // x0
  char s[1024]; // [xsp+50h] [xbp-410h] BYREF
  __int64 v13; // [xsp+450h] [xbp-10h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v7 = 0;
  v8 = 0;
  do
  {
    if ( v8 >= 0x401 )
      __break(0x5512u);
    v9 = scnprintf(&s[v8], 1024LL - v8, "(%u/%llu) ", v7, *(_QWORD *)(ipa3_ctx + 8 * v7 + 33928));
    ++v7;
    v8 += v9;
  }
  while ( v7 != 17 );
  v10 = scnprintf(
          dbg_buff,
          4096,
          "LAN COAL rx            = %llu\n"
          "LAN COAL pkts          = %llu\n"
          "LAN COAL left as is    = %llu\n"
          "LAN COAL reconstructed = %llu\n"
          "LAN COAL hdr qmap err  = %llu\n"
          "LAN COAL hdr nlo err   = %llu\n"
          "LAN COAL hdr pkt err   = %llu\n"
          "LAN COAL csum err      = %llu\n"
          "LAN COAL ip invalid    = %llu\n"
          "LAN COAL trans invalid = %llu\n"
          "LAN COAL tcp           = %llu\n"
          "LAN COAL tcp bytes     = %llu\n"
          "LAN COAL udp           = %llu\n"
          "LAN COAL udp bytes     = %llu\n"
          "LAN COAL (veid/cnt)...(veid/cnt) = %s\n",
          *(_QWORD *)(ipa3_ctx + 33848),
          *(_QWORD *)(ipa3_ctx + 33872),
          *(_QWORD *)(ipa3_ctx + 33856),
          *(_QWORD *)(ipa3_ctx + 33864),
          *(_QWORD *)(ipa3_ctx + 33880),
          *(_QWORD *)(ipa3_ctx + 33888),
          *(_QWORD *)(ipa3_ctx + 33896),
          *(_QWORD *)(ipa3_ctx + 33904),
          *(_QWORD *)(ipa3_ctx + 33912),
          *(_QWORD *)(ipa3_ctx + 33920),
          *(_QWORD *)(ipa3_ctx + 34064),
          *(_QWORD *)(ipa3_ctx + 34072),
          *(_QWORD *)(ipa3_ctx + 34080),
          *(_QWORD *)(ipa3_ctx + 34088),
          s);
  result = simple_read_from_buffer(a2, a3, a4, dbg_buff, v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
