__int64 __fastcall spss_load(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  int v3; // w0
  __int64 result; // x0
  __int64 v5; // x2
  unsigned int *v6; // x0
  unsigned int *v7; // x19
  int v8; // w20
  __int64 v9; // x19
  void *v10; // x0
  const void *v11; // x20
  __int64 v12; // x23
  __int64 v13; // x10
  int v14; // w0
  unsigned int v15; // w19
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v17[3]; // [xsp+8h] [xbp-18h] BYREF

  v17[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 40);
  v3 = qcom_mdt_load(*v2, a2, *(_QWORD *)(a1 + 32), *((unsigned int *)v2 + 14), v2[14], v2[12], v2[15], v2 + 13);
  if ( v3 )
  {
    v15 = v3;
    dev_err(*v2, "qcom_mdt_load of SPSS image failed, error value %d\n", v3);
    goto LABEL_14;
  }
  if ( (ssr_already_occurred_since_boot & 1) == 0 )
  {
    if ( arm64_use_ng_mappings )
      v5 = 0x68000000000F13LL;
    else
      v5 = 0x68000000000713LL;
    v6 = (unsigned int *)ioremap_prot(25694216, 4, v5);
    if ( v6 )
    {
      v7 = v6;
      v8 = readl_relaxed(v6);
      iounmap(v7);
      v9 = (unsigned int)(4 * v8);
      if ( (v8 & 0x3FF) != 0 )
      {
        printk(&unk_811F);
      }
      else if ( (int)v9 > 0 )
      {
        v10 = (void *)_kmalloc_cache_noprof(MEMORY[0xAAB0], 3520, 4096);
        v11 = v10;
        if ( !v10 )
        {
          result = 4294967284LL;
          goto LABEL_20;
        }
        v12 = v2[15];
        memcpy(v10, (const void *)(v2[14] + v12 - 4096), 0x1000u);
        v13 = v2[12];
        v16 = 8;
        v17[0] = 0x600000003LL;
        v17[1] = 0x60000001ALL;
        v14 = qcom_scm_assign_mem(v13 + v9, v12 - v9, &v16, v17, 2);
        if ( !v14 )
        {
          memcpy((void *)(v2[14] + v2[15] - 4096LL), v11, 0x1000u);
          kfree(v11);
          result = 0;
          ssr_already_occurred_since_boot = 1;
          goto LABEL_20;
        }
        v15 = v14;
        dev_err(*v2, "qcom_scm_assign_mem failed %d\n", v14);
        kfree(v11);
LABEL_14:
        result = v15;
        goto LABEL_20;
      }
    }
    else
    {
      printk(&unk_7CCE);
    }
    dev_err(*v2, "failed to get pil_size.\n");
    result = 4294967282LL;
    goto LABEL_20;
  }
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
