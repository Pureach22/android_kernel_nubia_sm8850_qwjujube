unsigned __int64 __fastcall qcom_cpuss_sleep_stats_v4_probe(__int64 a1)
{
  const char *v1; // x21
  char *v2; // x22
  const char *v3; // x23
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 dir; // x0
  __int64 v8; // x8
  unsigned __int64 result; // x0
  __int64 match_data; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x8
  int v19; // w8
  __int64 v20; // x0
  int v21; // w8
  __int64 v22; // x0
  int v23; // w8
  __int64 v24; // x0
  int v25; // w8
  __int64 v26; // x0
  int v27; // w8
  __int64 v28; // x0
  int v29; // w8
  __int64 v30; // x0
  int v31; // w8
  __int64 v32; // x0
  int v33; // w8
  __int64 v34; // x0
  int v35; // w8
  __int64 v36; // x0
  int v37; // w8
  __int64 v38; // x0
  int v39; // w8
  _QWORD *v40; // x8
  __int64 v41; // x9
  __int64 v42; // x2
  __int64 v43; // x3
  __int64 v44; // x2
  __int64 v45; // x8
  int v46; // w24
  __int64 v47; // x25
  __int64 v48; // x26
  __int64 v49; // x27
  __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x2
  __int64 v53; // x8
  __int64 v54; // x2
  __int64 v55; // x8
  __int64 v56; // x24
  __int64 v57; // x25
  int v58; // w26
  __int64 v59; // x27
  __int64 i; // x3
  char s[4]; // [xsp+10h] [xbp-20h] BYREF
  __int16 v62; // [xsp+14h] [xbp-1Ch]
  char v63[8]; // [xsp+18h] [xbp-18h] BYREF
  __int16 v64; // [xsp+20h] [xbp-10h]
  __int64 v65; // [xsp+28h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = devm_kmalloc(a1 + 16, 152, 3520);
  if ( !v5 )
    goto LABEL_29;
  v6 = v5;
  dir = debugfs_create_dir("qcom_cpuss_sleep_stats", 0);
  v8 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v6 + 56) = dir;
  *(_QWORD *)v6 = a1;
  if ( (unsigned int)of_device_is_compatible(v8, "qcom,cpuss-sleep-stats-v4") )
  {
    result = devm_platform_get_and_ioremap_resource(a1, 0, 0);
    *(_QWORD *)(v6 + 16) = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_73;
    match_data = of_device_get_match_data(a1 + 16);
    *(_QWORD *)(v6 + 24) = match_data;
    if ( !match_data )
    {
      result = 4294967274LL;
      goto LABEL_73;
    }
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,cpuss-sleep-stats-v6") )
  {
    v11 = *(_QWORD *)(a1 + 760);
    *(_DWORD *)(v6 + 8) = nr_cpu_ids;
    if ( (of_property_read_variable_u32_array(v11, "num-clusters", v6 + 12, 1, 0) & 0x80000000) != 0 )
    {
      result = 4294967277LL;
      goto LABEL_73;
    }
    v12 = *(unsigned int *)(v6 + 8);
    if ( (v12 & 0x80000000) != 0 )
    {
      *(_QWORD *)(v6 + 32) = 0;
      result = 4294967284LL;
      goto LABEL_73;
    }
    v13 = devm_kmalloc(a1 + 16, 16 * v12, 3520);
    *(_QWORD *)(v6 + 32) = v13;
    if ( !v13 )
      goto LABEL_29;
    v14 = *(unsigned int *)(v6 + 12);
    if ( (v14 & 0x80000000) != 0 )
    {
      *(_QWORD *)(v6 + 40) = 0;
    }
    else
    {
      v15 = devm_kmalloc(a1 + 16, 8 * v14, 3520);
      v16 = *(_QWORD *)(v6 + 32);
      *(_QWORD *)(v6 + 40) = v15;
      if ( !v16 )
        goto LABEL_29;
    }
    v17 = devm_kmalloc(a1 + 16, 8, 3520);
    v18 = *(_QWORD *)(v6 + 32);
    *(_QWORD *)(v6 + 48) = v17;
    if ( v18 )
    {
      v19 = *(_DWORD *)(v6 + 8);
      v62 = 0;
      *(_DWORD *)s = 0;
      v64 = 0;
      *(_QWORD *)v63 = 0;
      if ( v19 >= 1 )
      {
        snprintf(s, 6u, "pcpu%u", 0);
        v20 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
        v21 = *(_DWORD *)(v6 + 8);
        *(_QWORD *)(v6 + 64) = v20;
        if ( v21 >= 2 )
        {
          snprintf(s, 6u, "pcpu%u", 1);
          v22 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
          v23 = *(_DWORD *)(v6 + 8);
          *(_QWORD *)(v6 + 72) = v22;
          if ( v23 > 2 )
          {
            snprintf(s, 6u, "pcpu%u", 2);
            v24 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
            v25 = *(_DWORD *)(v6 + 8);
            *(_QWORD *)(v6 + 80) = v24;
            if ( v25 >= 4 )
            {
              snprintf(s, 6u, "pcpu%u", 3);
              v26 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
              v27 = *(_DWORD *)(v6 + 8);
              *(_QWORD *)(v6 + 88) = v26;
              if ( v27 >= 5 )
              {
                snprintf(s, 6u, "pcpu%u", 4);
                v28 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
                v29 = *(_DWORD *)(v6 + 8);
                *(_QWORD *)(v6 + 96) = v28;
                if ( v29 >= 6 )
                {
                  snprintf(s, 6u, "pcpu%u", 5);
                  v30 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
                  v31 = *(_DWORD *)(v6 + 8);
                  *(_QWORD *)(v6 + 104) = v30;
                  if ( v31 >= 7 )
                  {
                    snprintf(s, 6u, "pcpu%u", 6);
                    v32 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
                    v33 = *(_DWORD *)(v6 + 8);
                    *(_QWORD *)(v6 + 112) = v32;
                    if ( v33 >= 8 )
                    {
                      v1 = "pcpu%u";
                      v3 = (_BYTE *)&unk_6;
                      v2 = s;
                      snprintf(s, 6u, "pcpu%u", 7);
                      v34 = debugfs_create_dir(s, *(_QWORD *)(v6 + 56));
                      v35 = *(_DWORD *)(v6 + 8);
                      *(_QWORD *)(v6 + 120) = v34;
                      if ( v35 > 8 )
                        goto LABEL_81;
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ( *(int *)(v6 + 12) >= 1 )
      {
        snprintf(v63, 0xAu, "cluster%u", 0);
        v36 = debugfs_create_dir(v63, *(_QWORD *)(v6 + 56));
        v37 = *(_DWORD *)(v6 + 12);
        *(_QWORD *)(v6 + 128) = v36;
        if ( v37 >= 2 )
        {
          v1 = "cluster%u";
          v3 = (_BYTE *)&unk_A;
          v2 = v63;
          snprintf(v63, 0xAu, "cluster%u", 1);
          v38 = debugfs_create_dir(v63, *(_QWORD *)(v6 + 56));
          v39 = *(_DWORD *)(v6 + 12);
          *(_QWORD *)(v6 + 136) = v38;
          if ( v39 > 2 )
            goto LABEL_79;
        }
      }
      *(_QWORD *)(v6 + 144) = debugfs_create_dir("cpuss", *(_QWORD *)(v6 + 56));
      goto LABEL_25;
    }
LABEL_29:
    result = 4294967284LL;
    goto LABEL_73;
  }
LABEL_25:
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)v6 + 760LL), "qcom,cpuss-sleep-stats-v4") )
    goto LABEL_42;
  v41 = *(_QWORD *)(v6 + 16);
  v40 = *(_QWORD **)(v6 + 24);
  v63[2] = 0;
  *(_WORD *)v63 = 0;
  *v40 = v41;
  snprintf(v63, 3u, (const char *)(*(_QWORD *)(v6 + 24) + 12LL));
  if ( *(unsigned __int16 *)v63 ^ 0x4C43 | (unsigned __int8)v63[2] )
  {
    if ( *(unsigned __int16 *)v63 ^ 0x5353 | (unsigned __int8)v63[2] )
      goto LABEL_34;
    v42 = *(_QWORD *)(v6 + 144);
    v43 = *(_QWORD *)(v6 + 24);
  }
  else
  {
    v43 = *(_QWORD *)(v6 + 24);
    v42 = *(_QWORD *)(v6 + 128);
  }
  debugfs_create_file(v43 + 12, 256, v42, v43, &qcom_stats_count_fops);
LABEL_34:
  *(_QWORD *)(*(_QWORD *)(v6 + 24) + 40LL) = *(_QWORD *)(v6 + 16);
  snprintf(v63, 3u, (const char *)(*(_QWORD *)(v6 + 24) + 52LL));
  if ( !(*(unsigned __int16 *)v63 ^ 0x4C43 | (unsigned __int8)v63[2]) )
  {
    v45 = *(_QWORD *)(v6 + 24);
    v44 = *(_QWORD *)(v6 + 136);
    goto LABEL_38;
  }
  if ( !(*(unsigned __int16 *)v63 ^ 0x5353 | (unsigned __int8)v63[2]) )
  {
    v44 = *(_QWORD *)(v6 + 144);
    v45 = *(_QWORD *)(v6 + 24);
LABEL_38:
    debugfs_create_file(v45 + 52, 256, v44, v45 + 40, &qcom_stats_count_fops);
  }
  *(_QWORD *)(*(_QWORD *)(v6 + 24) + 80LL) = *(_QWORD *)(v6 + 16);
  snprintf(v63, 3u, (const char *)(*(_QWORD *)(v6 + 24) + 92LL));
  if ( !(*(unsigned __int16 *)v63 ^ 0x4C43 | (unsigned __int8)v63[2]) )
  {
LABEL_77:
    __break(0x5512u);
LABEL_78:
    *(_DWORD *)(*(_QWORD *)(v6 + 40) + 20LL) = 41;
    __break(0x5512u);
LABEL_79:
    for ( i = 2; ; i = 8 )
    {
      snprintf(v2, (size_t)v3, v1, i);
      debugfs_create_dir(v2, *(_QWORD *)(v6 + 56));
      __break(0x5512u);
LABEL_81:
      ;
    }
  }
  if ( !(*(unsigned __int16 *)v63 ^ 0x5353 | (unsigned __int8)v63[2]) )
    debugfs_create_file(
      *(_QWORD *)(v6 + 24) + 92LL,
      256,
      *(_QWORD *)(v6 + 144),
      *(_QWORD *)(v6 + 24) + 80LL,
      &qcom_stats_count_fops);
LABEL_42:
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)v6 + 760LL), "qcom,cpuss-sleep-stats-v6") )
  {
    if ( *(int *)(v6 + 12) >= 1 )
    {
      **(_DWORD **)(v6 + 40) = 36;
      debugfs_create_file(
        "CL5_Count",
        256,
        *(_QWORD *)(v6 + 128),
        *(_QWORD *)(v6 + 40),
        &qcom_stats_cluster_cpuss_count_fops);
      if ( *(int *)(v6 + 12) > 1 )
      {
        *(_DWORD *)(*(_QWORD *)(v6 + 40) + 8LL) = 38;
        debugfs_create_file(
          "CL5_Count",
          256,
          *(_QWORD *)(v6 + 136),
          *(_QWORD *)(v6 + 40) + 8LL,
          &qcom_stats_cluster_cpuss_count_fops);
        if ( *(int *)(v6 + 12) > 2 )
        {
          *(_DWORD *)(*(_QWORD *)(v6 + 40) + 16LL) = 40;
          goto LABEL_77;
        }
      }
    }
    **(_DWORD **)(v6 + 48) = 44;
    debugfs_create_file(
      "SS3_Count",
      256,
      *(_QWORD *)(v6 + 144),
      *(_QWORD *)(v6 + 48),
      &qcom_stats_cluster_cpuss_count_fops);
    if ( *(int *)(v6 + 8) >= 1 )
    {
      v46 = 0;
      v47 = 0;
      v48 = v6 + 64;
      v1 = "C2_Count";
      v2 = (char *)&qcom_stats_core_count_fops;
      v49 = 8;
      v3 = "C4_Count";
      do
      {
        *(_DWORD *)(*(_QWORD *)(v6 + 32) + v49 - 8) = v46;
        if ( v49 == 136 )
          goto LABEL_77;
        debugfs_create_file(
          "C2_Count",
          256,
          *(_QWORD *)(v48 + 8 * v47),
          *(_QWORD *)(v6 + 32) + v49 - 8,
          &qcom_stats_core_count_fops);
        *(_DWORD *)(*(_QWORD *)(v6 + 32) + v49) = v46 | 0x10;
        debugfs_create_file(
          "C4_Count",
          256,
          *(_QWORD *)(v48 + 8 * v47++),
          *(_QWORD *)(v6 + 32) + v49,
          &qcom_stats_core_count_fops);
        v46 += 2;
        v49 += 16;
      }
      while ( v47 < *(int *)(v6 + 8) );
    }
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)v6 + 760LL), "qcom,cpuss-sleep-stats-v4") )
    goto LABEL_64;
  v51 = *(_QWORD *)(v6 + 16);
  v50 = *(_QWORD *)(v6 + 24);
  v63[2] = 0;
  *(_WORD *)v63 = 0;
  *(_QWORD *)(v50 + 120) = v51;
  snprintf(v63, 3u, (const char *)(*(_QWORD *)(v6 + 24) + 132LL));
  if ( *(unsigned __int16 *)v63 ^ 0x4C43 | (unsigned __int8)v63[2] )
  {
    if ( *(unsigned __int16 *)v63 ^ 0x5353 | (unsigned __int8)v63[2] )
      goto LABEL_56;
    v52 = *(_QWORD *)(v6 + 144);
    v53 = *(_QWORD *)(v6 + 24);
  }
  else
  {
    v53 = *(_QWORD *)(v6 + 24);
    v52 = *(_QWORD *)(v6 + 128);
  }
  debugfs_create_file(v53 + 132, 256, v52, v53 + 120, &qcom_stats_residency_fops);
LABEL_56:
  *(_QWORD *)(*(_QWORD *)(v6 + 24) + 160LL) = *(_QWORD *)(v6 + 16);
  snprintf(v63, 3u, (const char *)(*(_QWORD *)(v6 + 24) + 172LL));
  if ( *(unsigned __int16 *)v63 ^ 0x4C43 | (unsigned __int8)v63[2] )
  {
    if ( *(unsigned __int16 *)v63 ^ 0x5353 | (unsigned __int8)v63[2] )
      goto LABEL_61;
    v54 = *(_QWORD *)(v6 + 144);
    v55 = *(_QWORD *)(v6 + 24);
  }
  else
  {
    v55 = *(_QWORD *)(v6 + 24);
    v54 = *(_QWORD *)(v6 + 136);
  }
  debugfs_create_file(v55 + 172, 256, v54, v55 + 160, &qcom_stats_residency_fops);
LABEL_61:
  *(_QWORD *)(*(_QWORD *)(v6 + 24) + 200LL) = *(_QWORD *)(v6 + 16);
  snprintf(v63, 3u, (const char *)(*(_QWORD *)(v6 + 24) + 212LL));
  if ( !(*(unsigned __int16 *)v63 ^ 0x4C43 | (unsigned __int8)v63[2]) )
    goto LABEL_77;
  if ( !(*(unsigned __int16 *)v63 ^ 0x5353 | (unsigned __int8)v63[2]) )
    debugfs_create_file(
      *(_QWORD *)(v6 + 24) + 212LL,
      256,
      *(_QWORD *)(v6 + 144),
      *(_QWORD *)(v6 + 24) + 200LL,
      &qcom_stats_residency_fops);
LABEL_64:
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)v6 + 760LL), "qcom,cpuss-sleep-stats-v6") )
  {
    if ( *(int *)(v6 + 12) >= 1 )
    {
      *(_DWORD *)(*(_QWORD *)(v6 + 40) + 4LL) = 37;
      debugfs_create_file(
        "CL5_Residency",
        256,
        *(_QWORD *)(v6 + 128),
        *(_QWORD *)(v6 + 40) + 4LL,
        &qcom_stats_cluster_cpuss_residency_fops);
      if ( *(int *)(v6 + 12) > 1 )
      {
        *(_DWORD *)(*(_QWORD *)(v6 + 40) + 12LL) = 39;
        debugfs_create_file(
          "CL5_Residency",
          256,
          *(_QWORD *)(v6 + 136),
          *(_QWORD *)(v6 + 40) + 12LL,
          &qcom_stats_cluster_cpuss_residency_fops);
        if ( *(int *)(v6 + 12) > 2 )
          goto LABEL_78;
      }
    }
    *(_DWORD *)(*(_QWORD *)(v6 + 48) + 4LL) = 45;
    debugfs_create_file(
      "SS3_Residency",
      256,
      *(_QWORD *)(v6 + 144),
      *(_QWORD *)(v6 + 48) + 4LL,
      &qcom_stats_cluster_cpuss_residency_fops);
    if ( *(int *)(v6 + 8) >= 1 )
    {
      v56 = 0;
      v57 = v6 + 64;
      v58 = 1;
      v1 = "C2_Residency";
      v59 = 12;
      v2 = (char *)&qcom_stats_core_residency_fops;
      v3 = "C4_Residency";
      do
      {
        *(_DWORD *)(*(_QWORD *)(v6 + 32) + v59 - 8) = v58;
        if ( v59 == 140 )
          goto LABEL_77;
        debugfs_create_file(
          "C2_Residency",
          256,
          *(_QWORD *)(v57 + 8 * v56),
          *(_QWORD *)(v6 + 32) + v59 - 8,
          &qcom_stats_core_residency_fops);
        *(_DWORD *)(*(_QWORD *)(v6 + 32) + v59) = (v58 - 1) | 0x11;
        debugfs_create_file(
          "C4_Residency",
          256,
          *(_QWORD *)(v57 + 8 * v56++),
          *(_QWORD *)(v6 + 32) + v59,
          &qcom_stats_core_residency_fops);
        v58 += 2;
        v59 += 16;
      }
      while ( v56 < *(int *)(v6 + 8) );
    }
  }
  result = 0;
  *(_QWORD *)(a1 + 168) = *(_QWORD *)(v6 + 56);
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
