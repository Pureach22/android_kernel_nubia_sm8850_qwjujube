__int64 __fastcall _init_power_domains(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  char *v9; // x10
  char v10; // t1
  __int64 v11; // x11
  __int64 v12; // x8
  unsigned int v13; // w10
  unsigned __int64 *v14; // x24
  char v15; // w9
  __int64 result; // x0
  __int64 v17; // x26
  __int64 v18; // x0
  unsigned __int64 v19; // x21
  __int64 v20; // x8
  int v21; // w9
  bool v22; // cf
  unsigned int v23; // w9
  void *v24; // x0
  __int64 v25; // x24
  __int64 v26; // x27
  __int64 v27; // x25
  char v28; // w8
  __int64 v29; // x8
  void *v30; // x0
  void *v31; // x0
  unsigned int v32; // w19
  __int64 v33; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v34[11]; // [xsp+8h] [xbp-58h] BYREF

  v34[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[489];
  v33 = 0;
  v2 = *(unsigned int *)(v1 + 40);
  if ( !(_DWORD)v2 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v24 = &unk_7FD4E;
      goto LABEL_48;
    }
LABEL_12:
    result = 0;
    goto LABEL_49;
  }
  v3 = *(_QWORD *)(v1 + 32);
  if ( !v3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v31 = &unk_85239;
      goto LABEL_51;
    }
LABEL_14:
    result = 4294967274LL;
    goto LABEL_49;
  }
  v5 = a1[488];
  v6 = devm_kmalloc(*a1 + 16, 24 * v2, 3520);
  *(_QWORD *)(v5 + 48) = v6;
  if ( !v6 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_826AA, "err ", 0xFFFFFFFFLL, "codec", "__init_power_domains");
    result = 4294967284LL;
    goto LABEL_49;
  }
  v7 = 0;
  v8 = 0;
  v9 = (char *)(v3 + 9);
  *(_DWORD *)(v5 + 56) = v2;
  do
  {
    ++v8;
    *(_QWORD *)(*(_QWORD *)(v5 + 48) + v7 + 8) = *(_QWORD *)(v9 - 9);
    *(_BYTE *)(*(_QWORD *)(v5 + 48) + v7 + 16) = *(v9 - 1);
    v10 = *v9;
    v9 += 16;
    v11 = *(_QWORD *)(v5 + 48) + v7;
    v7 += 24;
    *(_BYTE *)(v11 + 17) = v10;
  }
  while ( v8 < *(unsigned int *)(v5 + 56) );
  v12 = a1[488];
  v13 = *(_DWORD *)(v12 + 56);
  v14 = *(unsigned __int64 **)(v12 + 48);
  if ( v14 < &v14[3 * v13] )
  {
    v15 = msm_vidc_debug;
    do
    {
      if ( (v15 & 2) != 0 )
      {
        printk(&unk_89FCE, "high", 0xFFFFFFFFLL, "codec", "__init_power_domains");
        v15 = msm_vidc_debug;
        v12 = a1[488];
      }
      v13 = *(_DWORD *)(v12 + 56);
      v14 += 3;
    }
    while ( (unsigned __int64)v14 < *(_QWORD *)(v12 + 48) + 24 * (unsigned __int64)v13 );
    v14 = *(unsigned __int64 **)(v12 + 48);
  }
  if ( v14 >= &v14[3 * v13] )
  {
LABEL_24:
    v20 = a1[489];
    v21 = *(_DWORD *)(v20 + 56);
    v22 = v21 != 0;
    v23 = v21 - 1;
    if ( v23 == 0 || !v22 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v24 = &unk_9714F;
LABEL_48:
        printk(v24, "high", 0xFFFFFFFFLL, "codec", "__init_power_domains");
        result = 0;
        goto LABEL_49;
      }
      goto LABEL_12;
    }
    v25 = *(_QWORD *)(v20 + 48);
    if ( v25 )
    {
      v26 = 8LL * v23;
      v27 = 0;
      v28 = msm_vidc_debug;
      do
      {
        if ( (v28 & 2) != 0 )
        {
          printk(&unk_93F13, "high", 0xFFFFFFFFLL, "codec", "__init_power_domains");
          v28 = msm_vidc_debug;
        }
        v27 += 8;
      }
      while ( v26 != v27 );
      v29 = *a1;
      memset(v34, 0, 56);
      v34[7] = v25;
      v34[8] = &v33;
      v34[9] = 0;
      devm_pm_opp_set_config(v29 + 16, v34);
      goto LABEL_14;
    }
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v31 = &unk_81903;
LABEL_51:
      printk(v31, "err ", 0xFFFFFFFFLL, "codec", "__init_power_domains");
      goto LABEL_14;
    }
    goto LABEL_14;
  }
  while ( 1 )
  {
    v17 = *a1;
    v18 = dev_pm_domain_attach_by_name(*a1 + 16, v14[1]);
    if ( !v18 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_38;
      v30 = &unk_97189;
      goto LABEL_53;
    }
    v19 = v18;
    if ( (unsigned int)_devm_add_action(v17 + 16, devm_pd_release, v18, "devm_pd_release") )
      break;
    *v14 = v19;
    if ( v19 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_39;
    v14 += 3;
    if ( (unsigned __int64)v14 >= *(_QWORD *)(a1[488] + 48) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 56) )
      goto LABEL_24;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "devm_pd_release");
  dev_pm_domain_detach(v19, 1);
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v30 = &unk_8A01B;
LABEL_53:
    printk(v30, "err ", 0xFFFFFFFFLL, "codec", "devm_pd_get");
  }
LABEL_38:
  v19 = 0;
  *v14 = 0;
LABEL_39:
  if ( v19 )
    result = (unsigned int)v19;
  else
    result = 4294966775LL;
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v32 = result;
    printk(&unk_8F55D, "err ", 0xFFFFFFFFLL, "codec", "__init_power_domains");
    result = v32;
  }
  *v14 = 0;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
