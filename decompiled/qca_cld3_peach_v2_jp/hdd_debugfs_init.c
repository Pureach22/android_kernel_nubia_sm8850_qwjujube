__int64 __fastcall hdd_debugfs_init(__int64 a1)
{
  __int64 v1; // x20
  __int64 dir; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v1 = *(_QWORD *)(a1 + 32);
  dir = debugfs_create_dir(v1 + 296, 0);
  *(_QWORD *)(a1 + 52048) = dir;
  if ( dir )
  {
    if ( debugfs_create_file("wow_pattern", 384, dir, v1, &fops_wowpattern)
      && debugfs_create_file("pattern_gen", 384, *(_QWORD *)(a1 + 52048), v1, &fops_patterngen)
      && !(unsigned int)wlan_hdd_create_mib_stats_file(a1) )
    {
      return 16 * (unsigned int)((unsigned int)wlan_hdd_create_ll_stats_file(a1) != 0);
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: debugfs: create folder %s fail",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_debugfs_init",
      v1 + 296);
  }
  return 16;
}
