__int64 __fastcall sdhci_msm_qos_init(unsigned __int64 *a1)
{
  unsigned __int64 v1; // x24
  unsigned __int64 v2; // x26
  unsigned int *v3; // x21
  __int64 result; // x0
  __int64 v5; // x20
  __int64 next_available_child; // x0
  __int64 v7; // x1
  int v8; // w19
  unsigned __int64 v9; // x19
  _QWORD *v10; // x23
  __int64 v11; // x25
  bool v12; // zf
  int v13; // w0
  int v14; // w27
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x20
  unsigned __int64 v18; // x22
  __int64 v19; // x19
  unsigned __int64 v20; // x8
  bool v21; // cf
  _DWORD *v22; // x25
  __int64 v23; // x19
  __int64 v24; // x20
  int v25; // w28
  unsigned int v26; // w22
  __int64 v27; // x23
  char v28; // w8
  unsigned __int64 v29; // x19
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x1
  unsigned __int64 v32; // x25
  __int64 cpu_device; // x0
  __int64 v34; // x21
  unsigned int v35; // w19
  __int64 v36; // x8
  __int64 v37; // x20
  char v38; // w8
  __int64 v39; // x8
  unsigned __int64 v40; // x23
  unsigned __int64 v41; // x8
  int v42; // w9
  int v43; // w8
  __int64 v44; // x19
  unsigned __int64 v45; // x8
  __int64 v46; // x0
  unsigned int v47; // w19
  __int64 *v48; // x21
  __int64 v49; // t1
  unsigned __int64 StatusReg; // x19
  __int64 v51; // x22
  __int64 v52; // x0
  unsigned __int64 v53; // [xsp+10h] [xbp-30h]
  __int64 v54; // [xsp+18h] [xbp-28h]
  _DWORD *v55; // [xsp+20h] [xbp-20h]
  unsigned __int64 v56; // [xsp+28h] [xbp-18h]
  int v57; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v58; // [xsp+38h] [xbp-8h]

  v1 = (unsigned __int64)a1;
  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v57 = 0;
  v3 = *(unsigned int **)(v2 + 760);
  result = _kmalloc_cache_noprof(_cpu_possible_mask, 3520, 16);
  v5 = result;
  if ( !result )
    goto LABEL_86;
  while ( 1 )
  {
    *(_QWORD *)(v1 + 464) = v5;
    next_available_child = of_get_next_available_child(v3, 0);
    if ( !next_available_child )
    {
      *(_DWORD *)(v5 + 8) = 0;
LABEL_66:
      dev_err(v2 + 16, "QoS groups undefined\n");
      result = kfree(v5);
      *(_QWORD *)(v1 + 464) = 0;
      goto LABEL_86;
    }
    v7 = next_available_child;
    v8 = 0;
    do
    {
      v7 = of_get_next_available_child(v3, v7);
      --v8;
    }
    while ( v7 );
    *(_DWORD *)(v5 + 8) = -v8;
    if ( !v8 )
      goto LABEL_66;
    v9 = 48LL * *(unsigned int *)(v5 + 8);
    v10 = (_QWORD *)_kmalloc_noprof(v9, 3520);
    if ( !v10 )
    {
      *(_QWORD *)(v1 + 464) = 0;
      result = kfree(v5);
      goto LABEL_86;
    }
    v53 = v2;
    *(_QWORD *)v5 = v10;
    result = of_get_next_available_child(v3, 0);
    v54 = v5;
    if ( !result )
      break;
    v11 = result;
    v2 = 0;
    _ReadStatusReg(SP_EL0);
    v56 = v1;
    while ( (of_property_read_variable_u32_array(v11, "mask", &v57, 1, 0) & 0x80000000) != 0 )
    {
LABEL_9:
      result = of_get_next_available_child(v3, v11);
      v11 = result;
      if ( !result )
        goto LABEL_33;
    }
    if ( v9 < v2 || v9 - v2 < 8 )
      goto LABEL_83;
    v12 = (_cpu_possible_mask & v57) == 0;
    *v10 = _cpu_possible_mask & v57;
    if ( v12 )
    {
      dev_err(v53 + 16, "Invalid group mask, use default\n");
      if ( v9 < v2 || v9 - v2 < 8 )
        goto LABEL_83;
      *v10 = _cpu_possible_mask;
    }
    v13 = of_property_count_elems_of_size(v11, "vote", 4);
    if ( v13 < 1 )
    {
      dev_err(v53 + 16, "1 vote is needed, bailing out\n");
      goto LABEL_76;
    }
    v14 = v13;
    v15 = _kmalloc_noprof(4LL * (unsigned int)v13, 3264);
    v16 = v2 + 8;
    if ( v9 >= v2 + 8 && v9 - (v2 + 8) >= 8 )
    {
      v10[1] = v15;
      if ( !v15 )
        goto LABEL_76;
      v17 = v9;
      v18 = v2;
      v19 = 0;
      v21 = v17 >= v16;
      v20 = v17 - v16;
      v1 = 0;
      v21 = v21 && v20 >= 8;
      v2 = !v21;
      while ( (v2 & 1) == 0 )
      {
        if ( (unsigned int)of_property_read_u32_index(v11, "vote", (unsigned int)v1, v10[1] + v19) )
          goto LABEL_76;
        ++v1;
        v19 += 4;
        if ( v14 == v1 )
        {
          if ( v17 >= v18 + 32 && v17 - (v18 + 32) >= 8 )
          {
            v1 = v56;
            v9 = v17;
            v2 = v18 + 48;
            v10[4] = v56;
            v10 += 6;
            goto LABEL_9;
          }
          break;
        }
      }
    }
LABEL_83:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v51 = *(_QWORD *)(StatusReg + 80);
    v52 = _cpu_possible_mask;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    result = _kmalloc_cache_noprof(v52, 3520, 16);
    v5 = result;
    *(_QWORD *)(StatusReg + 80) = v51;
    if ( !result )
      goto LABEL_86;
  }
LABEL_33:
  v22 = *(_DWORD **)(v1 + 464);
  if ( !v22 )
    goto LABEL_86;
  v23 = *(_QWORD *)(v1 + 128);
  v3 = *(unsigned int **)v22;
  v24 = *(_QWORD *)v1;
  if ( (unsigned int)_irq_apply_affinity_hint(*(unsigned int *)(v23 + 1808), *(_QWORD *)v22, 1) )
    __break(0x800u);
  *(_QWORD *)(v1 + 512) = sdhci_msm_irq_affinity_notify;
  *(_QWORD *)(v1 + 520) = sdhci_msm_irq_affinity_release;
  v56 = v1;
  result = irq_set_affinity_notifier(*(unsigned int *)(v23 + 1808), v1 + 472);
  if ( v22[2] )
  {
    v25 = 0;
    v26 = 0;
    _ReadStatusReg(SP_EL0);
    v55 = v22;
LABEL_39:
    v1 = 80LL * (unsigned int)_sw_hweight64(*v3);
    result = _kmalloc_noprof(v1, 3520);
    v27 = result;
    *((_QWORD *)v3 + 2) = result;
    if ( result )
    {
      v28 = 0;
      v29 = 0;
      while ( 1 )
      {
        v30 = (unsigned int)(-1LL << v28) & *v3;
        if ( !(_DWORD)v30 )
        {
LABEL_38:
          v22 = v55;
          ++v26;
          *((_BYTE *)v3 + 40) = 1;
          v3 += 12;
          --v25;
          if ( v26 >= v55[2] )
            goto LABEL_51;
          goto LABEL_39;
        }
        if ( v1 >= v29 )
          v31 = v1 - v29;
        else
          v31 = 0;
        if ( v31 <= 0x4F )
        {
          _fortify_panic(15);
          goto LABEL_83;
        }
        v2 = v27 + v29;
        *(_QWORD *)(v2 + 64) = 0;
        *(_QWORD *)(v2 + 72) = 0;
        v32 = __clz(__rbit64(v30));
        *(_QWORD *)(v2 + 48) = 0;
        *(_QWORD *)(v2 + 56) = 0;
        *(_QWORD *)(v2 + 32) = 0;
        *(_QWORD *)(v2 + 40) = 0;
        *(_QWORD *)(v2 + 16) = 0;
        *(_QWORD *)(v2 + 24) = 0;
        *(_QWORD *)v2 = 0;
        *(_QWORD *)(v2 + 8) = 0;
        cpu_device = get_cpu_device((unsigned int)v32);
        result = dev_pm_qos_add_request(cpu_device, v27 + v29, 1, 0x7FFFFFFF);
        if ( (result & 0x80000000) != 0 )
          break;
        v29 += 80LL;
        v28 = v32 + 1;
        if ( v32 > 0x1E )
          goto LABEL_38;
      }
      dev_err(v24 + 16, "Fail (%d) add qos-req: grp-%d\n", result, v26);
      if ( v26 )
        goto LABEL_68;
      kfree(*((_QWORD *)v3 + 2));
LABEL_74:
      v45 = v53;
    }
    else
    {
      dev_err(v24 + 16, "Memory allocation failed\n");
      if ( !v26 )
        goto LABEL_74;
LABEL_68:
      v44 = 4;
      do
      {
        result = kfree(*(_QWORD *)&v3[v44]);
        v21 = __CFADD__(v25++, 1);
        v44 -= 12;
      }
      while ( !v21 );
      v45 = v53;
      if ( !v27 )
        goto LABEL_86;
    }
    dev_err(v45 + 16, "Failed to setup PM QoS.\n");
LABEL_76:
    v46 = *(_QWORD *)v54;
    if ( *(_DWORD *)(v54 + 8) )
    {
      v47 = 0;
      v48 = (__int64 *)(v46 + 8);
      do
      {
        v49 = *v48;
        v48 += 6;
        kfree(v49);
        ++v47;
      }
      while ( v47 < *(_DWORD *)(v54 + 8) );
      v46 = *(_QWORD *)v54;
    }
    kfree(v46);
    result = kfree(v54);
    *(_QWORD *)(v56 + 464) = 0;
    goto LABEL_86;
  }
LABEL_51:
  v34 = *(_QWORD *)v22;
  v35 = **(_DWORD **)(*(_QWORD *)v22 + 8LL);
  if ( v35 != *(unsigned __int8 *)(*(_QWORD *)v22 + 41LL) )
  {
    v36 = *(_QWORD *)(v34 + 32);
    v37 = *(_QWORD *)(v34 + 16);
    result = *(_QWORD *)(v36 + 752);
    if ( result && *(_BYTE *)(v36 + 760) == 1 )
      result = ipc_log_string();
    v38 = 0;
    do
    {
      v39 = -1LL << v38;
      v40 = (unsigned int)v39 & *(_DWORD *)v34;
      if ( ((unsigned int)v39 & *(_DWORD *)v34) == 0 )
        break;
      result = dev_pm_qos_update_request(v37, v35);
      if ( (result & 0x80000000) != 0 )
        goto LABEL_61;
      v37 += 80;
      v41 = __clz(__rbit64(v40));
      v21 = v41 >= 0x1F;
      v38 = v41 + 1;
    }
    while ( !v21 );
    *(_BYTE *)(v34 + 24) = 1;
    *(_BYTE *)(v34 + 41) = v35 != 0;
  }
LABEL_61:
  v42 = __clz(__rbit64(**(unsigned int **)v22));
  if ( **(_DWORD **)v22 )
    v43 = v42;
  else
    v43 = 32;
  v22[3] = v43;
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return result;
}
