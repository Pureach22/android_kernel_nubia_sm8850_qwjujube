unsigned __int64 __fastcall _init_resources(_QWORD *a1)
{
  unsigned __int64 *v2; // x20
  unsigned __int64 v3; // x0
  unsigned __int64 result; // x0
  __int64 v5; // x20
  unsigned int irq; // w0
  char v7; // w9
  unsigned int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 v12; // x22
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x12
  __int64 v18; // x25
  unsigned __int64 v19; // x27
  char v20; // w8
  void *v21; // x0
  const char *v22; // x4
  __int64 *v23; // x8
  __int64 v24; // x20
  __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x8
  unsigned __int64 v28; // x9
  int *v29; // x10
  int v30; // t1
  __int64 v31; // x11
  __int64 v32; // x8
  unsigned int v33; // w10
  unsigned __int64 *v34; // x27
  char v35; // w9
  unsigned __int64 v36; // x19
  void *v37; // x0
  const char *v38; // x4
  const char *v39; // x25
  __int64 v40; // x8
  __int64 (__fastcall *v41)(_QWORD); // x8

  v2 = (unsigned __int64 *)a1[488];
  v3 = devm_platform_ioremap_resource(*a1, 0);
  *v2 = v3;
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8B92F, "err ", 0xFFFFFFFFLL, "codec", "__init_register_base");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8F435, "high", 0xFFFFFFFFLL, "codec", "__init_register_base");
  v5 = a1[488];
  irq = platform_get_irq(*a1, 0);
  v7 = msm_vidc_debug;
  v8 = irq;
  *(_DWORD *)(v5 + 8) = irq;
  if ( (v7 & 2) != 0 )
  {
    printk(&unk_8C3D7, "high", 0xFFFFFFFFLL, "codec", "__init_irq");
    v8 = *(_DWORD *)(v5 + 8);
  }
  result = devm_request_threaded_irq(*a1 + 16LL, v8, venus_hfi_isr, venus_hfi_isr_handler, 4, "msm-vidc", a1);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v36 = result;
      printk(&unk_818AD, "err ", 0xFFFFFFFFLL, "codec", "__init_irq");
      return v36;
    }
    return result;
  }
  if ( (a1[596] & 1) == 0 )
    disable_irq_nosync(*(unsigned int *)(v5 + 8));
  v9 = a1[489];
  v10 = *(_QWORD *)(v9 + 128);
  v11 = *(unsigned int *)(v9 + 136);
  if ( !v10 || !(_DWORD)v11 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v21 = &unk_8DC1E;
    v22 = "__init_context_banks";
LABEL_26:
    printk(v21, "err ", 0xFFFFFFFFLL, "codec", v22);
    return 4294967274LL;
  }
  v12 = a1[488];
  v13 = devm_kmalloc(*a1 + 16LL, 56 * v11, 3520);
  *(_QWORD *)(v12 + 112) = v13;
  if ( !v13 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v37 = &unk_84564;
      v38 = "__init_context_banks";
      goto LABEL_74;
    }
    return 4294967284LL;
  }
  v14 = 0;
  v15 = v10 + 12;
  v16 = 48;
  *(_DWORD *)(v12 + 120) = v11;
  do
  {
    ++v14;
    *(_QWORD *)(*(_QWORD *)(v12 + 112) + v16 - 48) = *(_QWORD *)(v15 - 12);
    *(_DWORD *)(*(_QWORD *)(v12 + 112) + v16 - 40) = *(_DWORD *)(v15 - 4);
    *(_DWORD *)(*(_QWORD *)(v12 + 112) + v16 - 36) = *(_DWORD *)v15;
    *(_BYTE *)(*(_QWORD *)(v12 + 112) + v16 - 32) = *(_BYTE *)(v15 + 4);
    *(_BYTE *)(*(_QWORD *)(v12 + 112) + v16 - 31) = *(_BYTE *)(v15 + 5);
    *(_DWORD *)(*(_QWORD *)(v12 + 112) + v16 - 8) = *(_DWORD *)(v15 + 8);
    v17 = *(_QWORD *)(v15 + 12);
    v15 += 32;
    *(_QWORD *)(*(_QWORD *)(v12 + 112) + v16) = v17;
    v16 += 56;
  }
  while ( v14 < *(unsigned int *)(v12 + 120) );
  v18 = a1[488];
  v19 = *(_QWORD *)(v18 + 112);
  if ( v19 < v19 + 56LL * *(unsigned int *)(v18 + 120) )
  {
    v20 = msm_vidc_debug;
    do
    {
      if ( (v20 & 2) != 0 )
      {
        printk(&unk_9198A, "high", 0xFFFFFFFFLL, "codec", "__init_context_banks");
        v20 = msm_vidc_debug;
        v18 = a1[488];
      }
      v19 += 56LL;
    }
    while ( v19 < *(_QWORD *)(v18 + 112) + 56 * (unsigned __int64)*(unsigned int *)(v18 + 120) );
  }
  if ( *((_BYTE *)a1 + 4768) == 1 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_97073, "high", 0xFFFFFFFFLL, "codec", "__init_resources");
    return 0;
  }
  v23 = (__int64 *)a1[489];
  v24 = *v23;
  v25 = *((unsigned int *)v23 + 2);
  if ( !*v23 || !(_DWORD)v25 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v21 = &unk_83A69;
    v22 = "__init_bus";
    goto LABEL_26;
  }
  v26 = devm_kmalloc(*a1 + 16LL, 24 * v25, 3520);
  *(_QWORD *)(v18 + 16) = v26;
  if ( !v26 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v37 = &unk_95B55;
      v38 = "__init_bus";
LABEL_74:
      printk(v37, "err ", 0xFFFFFFFFLL, "codec", v38);
      return 4294967284LL;
    }
    return 4294967284LL;
  }
  v27 = 0;
  v28 = 0;
  v29 = (int *)(v24 + 12);
  *(_DWORD *)(v18 + 24) = v25;
  do
  {
    ++v28;
    *(_QWORD *)(*(_QWORD *)(v18 + 16) + v27 + 8) = *(_QWORD *)(v29 - 3);
    *(_DWORD *)(*(_QWORD *)(v18 + 16) + v27 + 16) = *(v29 - 1);
    v30 = *v29;
    v29 += 4;
    v31 = *(_QWORD *)(v18 + 16) + v27;
    v27 += 24;
    *(_DWORD *)(v31 + 20) = v30;
  }
  while ( v28 < *(unsigned int *)(v18 + 24) );
  v32 = a1[488];
  v33 = *(_DWORD *)(v32 + 24);
  v34 = *(unsigned __int64 **)(v32 + 16);
  if ( v34 < &v34[3 * v33] )
  {
    v35 = msm_vidc_debug;
    do
    {
      if ( (v35 & 2) != 0 )
      {
        printk(&unk_93332, "high", 0xFFFFFFFFLL, "codec", "__init_bus");
        v35 = msm_vidc_debug;
        v32 = a1[488];
      }
      v33 = *(_DWORD *)(v32 + 24);
      v34 += 3;
    }
    while ( (unsigned __int64)v34 < *(_QWORD *)(v32 + 16) + 24 * (unsigned __int64)v33 );
    v34 = *(unsigned __int64 **)(v32 + 16);
  }
  if ( v34 >= &v34[3 * v33] )
    goto LABEL_61;
  while ( 1 )
  {
    v39 = (const char *)v34[1];
    if ( !strcmp(v39, "venus-llcc") && msm_vidc_syscache_disable == 1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_94DA9, "high", 0xFFFFFFFFLL, "codec", "__init_bus");
      goto LABEL_53;
    }
    result = devm_of_icc_get(*a1 + 16LL, v39);
    *v34 = result;
    if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
      break;
LABEL_53:
    v34 += 3;
    if ( (unsigned __int64)v34 >= *(_QWORD *)(a1[488] + 16LL) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 24LL) )
      goto LABEL_61;
  }
  if ( (msm_vidc_debug & 1) == 0 )
  {
    *v34 = 0;
    if ( result )
      goto LABEL_60;
    return 4294966775LL;
  }
  printk(&unk_82674, "err ", 0xFFFFFFFFLL, "codec", "__init_bus");
  result = *v34;
  *v34 = 0;
  if ( !result )
    return 4294966775LL;
LABEL_60:
  if ( !(_DWORD)result )
  {
LABEL_61:
    if ( a1 )
    {
      v40 = a1[819];
      if ( v40 )
      {
        v41 = *(__int64 (__fastcall **)(_QWORD))(v40 + 48);
        if ( v41 )
        {
          if ( *((_DWORD *)v41 - 1) != -1850880742 )
            __break(0x8228u);
          result = v41(a1);
          if ( (_DWORD)result )
            return result;
        }
      }
    }
    result = _init_clocks(a1);
    if ( (_DWORD)result )
      return result;
    result = _init_reset_clocks(a1);
    if ( (_DWORD)result )
      return result;
    result = _init_subcaches(a1);
    if ( (_DWORD)result )
      return result;
    result = _init_device_region(a1);
    if ( (_DWORD)result )
      return result;
    result = _register_mmrm(a1);
    if ( (_DWORD)result )
      return result;
    return 0;
  }
  return result;
}
