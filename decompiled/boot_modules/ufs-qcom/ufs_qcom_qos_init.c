__int64 __fastcall ufs_qcom_qos_init(__int64 a1)
{
  unsigned __int64 v1; // x22
  _QWORD *v2; // x25
  __int64 v3; // x26
  const char *v4; // x27
  __int64 v5; // x0
  __int64 next_available_child; // x0
  __int64 v7; // x1
  int v8; // w19
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x1
  int v13; // w19
  unsigned __int64 v14; // x23
  __int64 v15; // x24
  __int64 v16; // x0
  unsigned __int64 v17; // x19
  int v18; // w28
  __int64 v19; // x0
  unsigned __int64 v20; // x20
  _QWORD *v21; // x21
  unsigned __int64 v22; // x21
  __int64 v23; // x19
  __int64 v24; // x19
  __int64 v25; // x20
  __int64 v26; // x23
  char v27; // w8
  unsigned __int64 v28; // x28
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x1
  unsigned __int64 v31; // x24
  __int64 cpu_device; // x0
  int v33; // w0
  __int64 v34; // x21
  __int64 v35; // x0
  __int64 v36; // x8
  _BYTE *v37; // x21
  __int64 v38; // x28
  __int64 v39; // x23
  __int64 v40; // x0
  __int64 v41; // x24
  __int64 *v42; // x19
  __int64 v43; // t1
  unsigned int v44; // w19
  __int64 *v45; // x20
  __int64 v46; // t1
  __int64 v47; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v49; // x20
  __int64 v50; // x0
  const char *v51; // [xsp+10h] [xbp-20h]
  _QWORD *v52; // [xsp+18h] [xbp-18h]
  __int64 v53; // [xsp+18h] [xbp-18h]
  __int64 v54; // [xsp+20h] [xbp-10h]
  __int64 v55; // [xsp+28h] [xbp-8h]

  if ( !a1 )
    goto LABEL_84;
  v4 = *(const char **)(a1 + 64);
  v2 = (_QWORD *)a1;
  v3 = *(_QWORD *)(a1 + 184);
  v5 = _cpu_possible_mask;
  v1 = *((_QWORD *)v4 + 93);
  *(_BYTE *)(v3 + 632) = 1;
  if ( *(_DWORD *)(v3 + 3192) != (unsigned int)_sw_hweight64(v5) && (*(_BYTE *)(v3 + 760) & 1) == 0 )
    return dev_err(v2[8], "%s: QoS disabled. Check partial CPUs\n", "ufs_qcom_qos_init");
  next_available_child = of_get_next_available_child(v1, 0);
  if ( !next_available_child )
    return dev_err(v4, "QoS groups undefined\n");
  v7 = next_available_child;
  v8 = 0;
  do
  {
    v7 = of_get_next_available_child(v1, v7);
    --v8;
  }
  while ( v7 );
  if ( !v8 )
    return dev_err(v4, "QoS groups undefined\n");
  result = _kmalloc_cache_noprof(reset_control_deassert, 3520, 24);
  v10 = result;
  if ( !result )
    return result;
  while ( 1 )
  {
    *(_QWORD *)(v3 + 472) = v10;
    v11 = of_get_next_available_child(v1, 0);
    if ( v11 )
    {
      v12 = v11;
      v13 = 0;
      do
      {
        ++v13;
        v12 = of_get_next_available_child(v1, v12);
      }
      while ( v12 );
    }
    else
    {
      v13 = 0;
    }
    *(_DWORD *)(v10 + 8) = v13;
    v14 = 80LL * *(unsigned int *)(v10 + 8);
    v15 = _kmalloc_noprof(v14, 3520);
    if ( !v15 )
      break;
    v51 = v4;
    v52 = v2;
    v55 = v10;
    *(_QWORD *)v10 = v15;
    v16 = of_get_next_available_child(v1, 0);
    v54 = v3;
    if ( !v16 )
    {
LABEL_34:
      v3 = v52[23];
      v24 = *(_QWORD *)(v3 + 472);
      v53 = v52[8];
      v4 = *(const char **)v24;
      if ( *(_DWORD *)(v24 + 8) )
      {
        LODWORD(v25) = 0;
        _ReadStatusReg(SP_EL0);
LABEL_37:
        v1 = 80LL * (unsigned int)_sw_hweight64(*(unsigned int *)v4);
        v26 = _kmalloc_noprof(v1, 3520);
        *((_QWORD *)v4 + 2) = v26;
        if ( v26 )
        {
          v27 = 0;
          v28 = 0;
          while ( 1 )
          {
            v29 = (unsigned int)(-1LL << v27) & *(_DWORD *)v4;
            if ( !(_DWORD)v29 )
            {
LABEL_36:
              LODWORD(v25) = v25 + 1;
              *((_QWORD *)v4 + 4) = 0xFFFFFFFE00000LL;
              *((_QWORD *)v4 + 5) = v4 + 40;
              *((_QWORD *)v4 + 6) = v4 + 40;
              *((_QWORD *)v4 + 7) = ufs_qcom_vote_work;
              v4 += 80;
              if ( (unsigned int)v25 >= *(_DWORD *)(v24 + 8) )
                goto LABEL_48;
              goto LABEL_37;
            }
            if ( v1 >= v28 )
              v30 = v1 - v28;
            else
              v30 = 0;
            if ( v30 <= 0x4F )
            {
              _fortify_panic(15, v30, 80);
              goto LABEL_82;
            }
            v2 = (_QWORD *)(v26 + v28);
            v2[8] = 0;
            v2[9] = 0;
            v31 = __clz(__rbit64(v29));
            v2[6] = 0;
            v2[7] = 0;
            v2[4] = 0;
            v2[5] = 0;
            v2[2] = 0;
            v2[3] = 0;
            *v2 = 0;
            v2[1] = 0;
            cpu_device = get_cpu_device((unsigned int)v31);
            v33 = dev_pm_qos_add_request(cpu_device, v26 + v28, 1, 0x7FFFFFFF);
            if ( v33 < 0 )
              break;
            v28 += 80LL;
            v27 = v31 + 1;
            if ( v31 > 0x1E )
              goto LABEL_36;
          }
          dev_err(v53, "Fail (%d) add qos-req: grp-%d\n", v33, v25);
          if ( (_DWORD)v25 )
            goto LABEL_67;
          kfree(*((_QWORD *)v4 + 2));
          goto LABEL_69;
        }
LABEL_66:
        if ( (_DWORD)v25 )
        {
LABEL_67:
          v42 = (__int64 *)(v4 + 16);
          do
          {
            v43 = *v42;
            v42 -= 10;
            LODWORD(v25) = v25 - 1;
            kfree(v43);
          }
          while ( (_DWORD)v25 );
        }
LABEL_69:
        v3 = v54;
        v21 = (_QWORD *)v55;
        if ( *(_DWORD *)(v55 + 8) )
        {
          v44 = 0;
          v45 = (__int64 *)(*(_QWORD *)v55 + 8LL);
          do
          {
            v46 = *v45;
            v45 += 10;
            kfree(v46);
            ++v44;
          }
          while ( v44 < *(_DWORD *)(v55 + 8) );
        }
        goto LABEL_72;
      }
LABEL_48:
      if ( *(int *)(v3 + 648) < 1 )
      {
        LODWORD(v25) = 0;
        if ( (*(_BYTE *)(v3 + 632) & 1) != 0 )
          goto LABEL_65;
        v37 = (_BYTE *)(v3 + 632);
      }
      else
      {
        v34 = 0;
        v25 = 0;
        do
        {
          v35 = cpufreq_cpu_get(*(unsigned int *)(*(_QWORD *)(v3 + 640) + v34));
          if ( !v35 )
          {
            dev_err(v53, "Failed cpufreq policy,cpu=%u\n", *(_DWORD *)(*(_QWORD *)(v3 + 640) + v34));
            *(_BYTE *)(v3 + 632) = 1;
            goto LABEL_65;
          }
          *(_DWORD *)(*(_QWORD *)(v3 + 640) + v34 + 8) = *(_DWORD *)(v35 + 44);
          *(_DWORD *)(*(_QWORD *)(v3 + 640) + v34 + 12) = *(_DWORD *)(v35 + 40);
          ((void (*)(void))cpufreq_cpu_put)();
          v36 = *(int *)(v3 + 648);
          ++v25;
          v34 += 32;
        }
        while ( v25 < v36 );
        if ( (*(_BYTE *)(v3 + 632) & 1) != 0 )
          goto LABEL_65;
        v37 = (_BYTE *)(v3 + 632);
        if ( (int)v36 > 0 )
        {
          v2 = nullptr;
          v38 = 0;
          do
          {
            v39 = *(unsigned int *)((char *)v2 + *(_QWORD *)(v3 + 640));
            v40 = cpufreq_cpu_get((unsigned int)v39);
            if ( !v40 )
            {
              dev_err(*(_QWORD *)(*(_QWORD *)(v3 + 16) + 64LL), "Failed to get cpu(%u)freq policy\n", v39);
              LODWORD(v1) = -22;
              goto LABEL_78;
            }
            if ( (unsigned int)v39 >= 0x20 )
              goto LABEL_83;
            v41 = v40;
            v1 = (unsigned int)freq_qos_add_request(v40 + 144, (char *)&qos_min_req + _per_cpu_offset[v39], 1, 0);
            cpufreq_cpu_put(v41);
            if ( (v1 & 0x80000000) != 0 )
            {
              dev_err(*(_QWORD *)(*(_QWORD *)(v3 + 16) + 64LL), "Failed to add freq qos req(%u), err=%d\n", v39, v1);
              goto LABEL_78;
            }
            ++v38;
            v2 += 4;
          }
          while ( v38 < *(int *)(v3 + 648) );
          if ( !(_DWORD)v1 )
          {
            *(_QWORD *)(v3 + 528) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v3 + 536) = v3 + 536;
            *(_QWORD *)(v3 + 544) = v3 + 536;
            *(_QWORD *)(v3 + 552) = ufs_qcom_cpufreq_dwork;
            init_timer_key(v3 + 560, &delayed_work_timer_fn, 0x200000, 0, 0);
            goto LABEL_65;
          }
LABEL_78:
          v37 = (_BYTE *)(v3 + 632);
LABEL_79:
          dev_err(v53, "Failed to register for freq_qos: %d\n", v1);
          *v37 = 1;
LABEL_65:
          result = alloc_workqueue("%s", (const char *)0x6000A);
          *(_QWORD *)(v24 + 16) = result;
          if ( result )
            return result;
          goto LABEL_66;
        }
      }
      LODWORD(v1) = -22;
      goto LABEL_79;
    }
    v2 = (_QWORD *)v16;
    v17 = 0;
    v4 = "vote";
    _ReadStatusReg(SP_EL0);
LABEL_17:
    if ( of_find_property(v2, "perf", 0) )
    {
      if ( v14 < v17 + 76 )
        goto LABEL_82;
      *(_BYTE *)(v15 + 76) = 1;
      *(_BYTE *)(v3 + 632) = 0;
      if ( v14 <= v17 )
        goto LABEL_82;
      *(_QWORD *)v15 = *(_QWORD *)(v3 + 744);
    }
    else
    {
      if ( v14 <= v17 )
        goto LABEL_82;
      *(_QWORD *)v15 = *(_QWORD *)(v3 + 752);
      if ( *(_BYTE *)(v3 + 3139) == 1 )
      {
        if ( v14 < v17 + 76 )
          goto LABEL_82;
        *(_BYTE *)(v15 + 76) = 1;
      }
    }
    v18 = of_property_count_elems_of_size(v2, "vote", 4);
    if ( v18 <= 0 )
    {
      dev_err(v51, "1 vote is needed, bailing out: %d\n", v18);
      v21 = (_QWORD *)v55;
LABEL_72:
      kfree(*v21);
      kfree(v21);
      v47 = *(_QWORD *)(v3 + 640);
      *(_QWORD *)(v3 + 472) = 0;
      result = kfree(v47);
      *(_QWORD *)(v3 + 640) = 0;
      return result;
    }
    v19 = _kmalloc_noprof(4LL * (unsigned int)v18, 3264);
    v20 = v17 | 8;
    if ( v14 >= (v17 | 8) )
    {
      v21 = (_QWORD *)v55;
      *(_QWORD *)(v15 + 8) = v19;
      if ( !v19 )
        goto LABEL_72;
      v22 = v17;
      v23 = 0;
      v3 = 0;
      while ( v14 >= v20 )
      {
        if ( (unsigned int)of_property_read_u32_index(v2, "vote", (unsigned int)v3, *(_QWORD *)(v15 + 8) + v23) )
          goto LABEL_69;
        ++v3;
        v23 += 4;
        if ( v18 == v3 )
        {
          if ( v14 <= v22 + 64 )
            break;
          v3 = v54;
          v17 = v22 + 80;
          *(_QWORD *)(v15 + 64) = v54;
          v15 += 80;
          v2 = (_QWORD *)of_get_next_available_child(v1, v2);
          if ( v2 )
            goto LABEL_17;
          goto LABEL_34;
        }
      }
    }
LABEL_82:
    __break(1u);
LABEL_83:
    __break(0x5512u);
LABEL_84:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v49 = *(_QWORD *)(StatusReg + 80);
    v50 = reset_control_deassert;
    *(_QWORD *)(StatusReg + 80) = &ufs_qcom_qos_init__alloc_tag;
    result = _kmalloc_cache_noprof(v50, 3520, 24);
    v10 = result;
    *(_QWORD *)(StatusReg + 80) = v49;
    if ( !result )
      return result;
  }
  result = kfree(v10);
  *(_QWORD *)(v3 + 472) = 0;
  return result;
}
