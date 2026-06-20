__int64 __fastcall ipa_gsb_debugfs_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w23
  __int64 v5; // x8
  __int64 v6; // x21
  int v7; // w0
  __int64 v8; // x3
  __int64 v9; // x27
  __int64 v10; // x28
  __int64 v11; // x26

  v4 = 0;
  v5 = ipa_gsb_ctx;
  v6 = 96;
  while ( 1 )
  {
    v8 = *(_QWORD *)(v5 + v6);
    if ( !v8 )
      goto LABEL_3;
    if ( v4 > 0x200 )
      break;
    v10 = *(_QWORD *)(v8 + 64);
    v9 = *(_QWORD *)(v8 + 72);
    v11 = *(_QWORD *)(v8 + 80);
    v4 += scnprintf((char *)&dbg_buff_4 + v4, 512 - v4, "netdev: %s\n", (const char *)v8);
    if ( v4 > 0x200 )
      break;
    v4 += scnprintf((char *)&dbg_buff_4 + v4, 512 - v4, "UL packets: %lld\n", v10);
    if ( v4 > 0x200 )
      break;
    v4 += scnprintf((char *)&dbg_buff_4 + v4, 512 - v4, "DL packets: %lld\n", v9);
    if ( v4 > 0x200 )
      break;
    v7 = scnprintf((char *)&dbg_buff_4 + v4, 512 - v4, "packets with insufficient headroom: %lld\n", v11);
    v5 = ipa_gsb_ctx;
    v4 += v7;
LABEL_3:
    v6 += 8;
    if ( v6 == 136 )
      return simple_read_from_buffer(a2, a3, a4, &dbg_buff_4, (int)v4);
  }
  __break(0x5512u);
  return simple_read_from_buffer(a2, a3, a4, &dbg_buff_4, (int)v4);
}
