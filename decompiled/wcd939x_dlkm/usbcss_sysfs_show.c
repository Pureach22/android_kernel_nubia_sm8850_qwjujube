__int64 __fastcall usbcss_sysfs_show(__int64 a1, const char **a2, __int64 a3)
{
  const char *v3; // x20
  __int64 v5; // x21
  __int64 v7; // x8

  v3 = *a2;
  v5 = *(_QWORD *)(*(_QWORD *)*(a2 - 1) + 144LL);
  if ( !strcmp(*a2, "rdson_3p6v") )
  {
    v7 = 228;
  }
  else if ( !strcmp(v3, "rdson_6v") )
  {
    v7 = 224;
  }
  else if ( !strcmp(v3, "r1_l") )
  {
    v7 = 72;
  }
  else if ( !strcmp(v3, "r1_r") )
  {
    v7 = 100;
  }
  else if ( !strcmp(v3, "r3_l") )
  {
    v7 = 76;
  }
  else if ( !strcmp(v3, "r3_r") )
  {
    v7 = 104;
  }
  else if ( !strcmp(v3, "r4_sbu1") )
  {
    v7 = 148;
  }
  else if ( !strcmp(v3, "r4_sbu2") )
  {
    v7 = 184;
  }
  else if ( !strcmp(v3, "r5_sbu1") )
  {
    v7 = 152;
  }
  else if ( !strcmp(v3, "r5_sbu2") )
  {
    v7 = 188;
  }
  else if ( !strcmp(v3, "r6_sbu1") )
  {
    v7 = 156;
  }
  else if ( !strcmp(v3, "r6_sbu2") )
  {
    v7 = 192;
  }
  else if ( !strcmp(v3, "r7_sbu1") )
  {
    v7 = 160;
  }
  else if ( !strcmp(v3, "r7_sbu2") )
  {
    v7 = 196;
  }
  else if ( !strcmp(v3, "r_common_gnd_offset") )
  {
    v7 = 248;
  }
  else if ( !strcmp(v3, "rcom_margin") )
  {
    v7 = 252;
  }
  else if ( !strcmp(v3, "se_slope_factor_times_1000") )
  {
    v7 = 272;
  }
  else if ( !strcmp(v3, "diff_slope_factor_times_1000") )
  {
    v7 = 268;
  }
  else if ( !strcmp(v3, "lin_k_aud") )
  {
    v7 = 116;
  }
  else
  {
    if ( strcmp(v3, "xtalk_config") )
      return 0;
    v7 = 260;
  }
  return (int)scnprintf(a3, 10, "%d\n", *(_DWORD *)(v5 + v7));
}
