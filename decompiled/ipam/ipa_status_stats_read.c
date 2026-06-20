__int64 ipa_status_stats_read()
{
  unsigned int *v0; // x19
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x9
  const void *v4; // x1
  __int64 v5; // x1
  int v6; // w27
  __int64 v7; // x26
  __int64 v9; // x28
  unsigned int *v10; // x25
  __int64 v11; // x1
  unsigned __int64 StatusReg; // x20
  __int64 v14; // x21

  v0 = (unsigned int *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2888);
  if ( !v0 )
    return -14;
  while ( 1 )
  {
    v1 = ipa3_ctx;
    if ( !*(_DWORD *)(ipa3_ctx + 34308) )
      break;
    v2 = 0;
    while ( v2 != 36 )
    {
      v3 = *(_QWORD *)(v1 + 480 * v2 + 640);
      if ( v3 )
      {
        v4 = *(const void **)(v3 + 1768);
        if ( v4 )
        {
          memcpy(v0, v4, 0xB48u);
          printk(&unk_3E3763, (unsigned int)v2);
          v5 = v0[720];
          v6 = 30;
          while ( 1 )
          {
            printk(&unk_3B1EC8, v5);
            v7 = v0[720];
            if ( (unsigned int)v7 > 0x1E )
              goto LABEL_27;
            if ( ((32 * ((3 * v7) & 0x3FFFFFFFFLL)) | 8uLL) > 0xB48 || (_DWORD)v7 == 30 )
              goto LABEL_26;
            v9 = 96 * v7;
            v10 = &v0[24 * v7];
            printk(&unk_3D831A, v10[2]);
            if ( ((96 * v7) | 0xCuLL) > 0xB48 )
              goto LABEL_26;
            printk(&unk_3E377B, v10[3]);
            if ( (v9 | 0x10uLL) > 0xB48 )
              goto LABEL_26;
            printk(&unk_3EEC5A, v10[4]);
            if ( (v9 | 0x14uLL) > 0xB48
              || (printk(&unk_3F1DAF, v10[5]), (_DWORD)v7 == 30)
              || (printk(&unk_3AF546, *((unsigned __int8 *)v10 + 58)),
                  printk(&unk_3E613E, *((unsigned __int8 *)v10 + 59)),
                  (v9 | 0x18uLL) > 0xB48)
              || (printk(&unk_3DB12A, v10[6]), (v9 | 0x1CuLL) > 0xB48)
              || (printk(&unk_3C09CE, *((unsigned __int8 *)v10 + 28)), (v9 | 0x1DuLL) > 0xB48)
              || (printk(&unk_3C97F0, *((unsigned __int8 *)v10 + 29)), (v9 | 0x1EuLL) > 0xB48)
              || (printk(&unk_3EC0FF, *((unsigned __int8 *)v10 + 30)), (v9 | 0x1FuLL) > 0xB48) )
            {
LABEL_26:
              __break(1u);
              goto LABEL_27;
            }
            printk(&unk_3B4ABD, *((unsigned __int8 *)v10 + 31));
            printk(&unk_3CC34E, *((unsigned __int8 *)v10 + 32));
            printk(&unk_3C9801, *((unsigned __int16 *)v10 + 25));
            printk(&unk_3DE0EF, *((unsigned __int8 *)v10 + 33));
            printk(&unk_3D8330, *((unsigned __int8 *)v10 + 34));
            printk(&unk_3D54CD, *((unsigned __int8 *)v10 + 35));
            printk(&unk_3F7BEC, *((unsigned __int8 *)v10 + 60));
            printk(&unk_3E378D, *((unsigned __int8 *)v10 + 36));
            printk(&unk_3DB13B, *((unsigned __int16 *)v10 + 26));
            printk(&unk_3E0AD4, *((unsigned __int8 *)v10 + 37));
            printk(&unk_3DE100, *((unsigned __int16 *)v10 + 27));
            printk(&unk_3CF6CD, v10[10]);
            printk(&unk_3AF55B, *(_QWORD *)v10 & 0xFFFFFFFFFFFFLL);
            printk(&unk_3E9340, *((unsigned __int8 *)v10 + 61));
            printk(&unk_3C9815, v10[11]);
            printk(&unk_3FAF41, *((unsigned __int8 *)v10 + 48));
            printk(&unk_3C3966, *((unsigned __int16 *)v10 + 28));
            printk(&unk_3EEC6E, *((unsigned __int8 *)v10 + 49));
            printk(&unk_3E6154, *((unsigned __int8 *)v10 + 62));
            printk(&unk_3C6A44, *((unsigned __int8 *)v10 + 89));
            printk(&unk_3BDA76, v11);
            --v6;
            v5 = (v0[720] + 1) % 0x1E;
            v0[720] = v5;
            if ( !v6 )
            {
              v1 = ipa3_ctx;
              break;
            }
          }
        }
      }
      if ( ++v2 >= (unsigned __int64)*(unsigned int *)(v1 + 34308) )
        goto LABEL_25;
    }
LABEL_27:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipa_status_stats_read__alloc_tag;
    v0 = (unsigned int *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2888);
    *(_QWORD *)(StatusReg + 80) = v14;
    if ( !v0 )
      return -14;
  }
LABEL_25:
  kfree(v0);
  return 0;
}
