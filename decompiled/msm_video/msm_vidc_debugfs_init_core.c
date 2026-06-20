unsigned __int64 __fastcall msm_vidc_debugfs_init_core(__int64 a1)
{
  __int64 v1; // x1
  unsigned __int64 dir; // x0
  __int64 v4; // x4
  unsigned __int64 v5; // x19
  __int64 v6; // x4
  void *v7; // x0
  char v9[5]; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v10; // [xsp+9h] [xbp-37h]
  __int64 v11; // [xsp+11h] [xbp-2Fh]
  __int64 v12; // [xsp+19h] [xbp-27h]
  __int64 v13; // [xsp+21h] [xbp-1Fh]
  _BYTE v14[13]; // [xsp+29h] [xbp-17h] BYREF
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 3560);
  memset(v14, 0, sizeof(v14));
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  if ( !v1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_debugfs_init_core");
    goto LABEL_16;
  }
  strcpy(v9, "core");
  dir = debugfs_create_dir(v9, v1);
  if ( !dir || (v5 = dir, dir >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8D7F3, "err ", 0xFFFFFFFFLL, "codec", v4);
LABEL_16:
    v5 = 0;
    goto LABEL_17;
  }
  if ( !debugfs_create_file("info", 292, dir, a1, &core_info_fops)
    || !debugfs_create_file("trigger_ssr", 128, v5, a1, &ssr_fops) )
  {
    goto LABEL_9;
  }
  if ( !debugfs_create_file("trigger_stability", 128, v5, a1, &stability_fops) )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_17;
    v7 = &unk_8A66A;
    goto LABEL_11;
  }
  if ( !debugfs_create_file("stats_delay_ms", 420, v5, a1, &stats_delay_fops)
    || !debugfs_create_file("enable_crc", 128, v5, a1, &crc_fops) )
  {
LABEL_9:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = &unk_873FB;
LABEL_11:
      printk(v7, "err ", 0xFFFFFFFFLL, "codec", v6);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v5;
}
