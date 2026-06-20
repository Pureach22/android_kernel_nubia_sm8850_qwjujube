__int64 __fastcall scm_legacy_call(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v3; // x26
  __int64 v5; // x23
  __int64 v7; // x20
  __int64 v8; // x24
  int v9; // w9
  __int64 v10; // x22
  __int64 v11; // x25
  int v12; // w8
  char v13; // w0
  unsigned int v14; // w24
  char v15; // w23
  const char *v16; // x0
  const char *v17; // x2
  __int64 v18; // x0
  __int64 v19; // x24
  __int64 v20; // x8
  unsigned __int64 v21; // x9
  unsigned int *v22; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x24
  _QWORD v26[4]; // [xsp+10h] [xbp-30h] BYREF
  int v27; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v14 = -517;
    goto LABEL_47;
  }
  LODWORD(v3) = *(_DWORD *)(a2 + 8);
  v5 = a2;
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  v7 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 4096);
  if ( !v7 )
  {
LABEL_46:
    v14 = -12;
    goto LABEL_47;
  }
  while ( 1 )
  {
    v8 = 4 * (unsigned int)(v3 & 0xF);
    v9 = *(_DWORD *)(v5 + 4) & 0x3FF | (*(_DWORD *)v5 << 10);
    v10 = v8 + 40;
    v11 = (unsigned int)(v8 + 16);
    v12 = v3 & 0xF;
    *(_DWORD *)v7 = v8 + 40;
    *(_DWORD *)(v7 + 4) = 16;
    *(_DWORD *)(v7 + 8) = v11;
    *(_DWORD *)(v7 + 12) = v9;
    if ( (v3 & 0xF) != 0 )
    {
      *(_DWORD *)(v7 + 16) = *(_QWORD *)(v5 + 16);
      if ( v12 != 1 )
      {
        *(_DWORD *)(v7 + 20) = *(_QWORD *)(v5 + 24);
        if ( v12 != 2 )
        {
          *(_DWORD *)(v7 + 24) = *(_QWORD *)(v5 + 32);
          if ( v12 != 3 )
          {
            *(_DWORD *)(v7 + 28) = *(_QWORD *)(v5 + 40);
            if ( v12 != 4 )
            {
              *(_DWORD *)(v7 + 32) = *(_QWORD *)(v5 + 48);
              if ( v12 != 5 )
              {
                *(_DWORD *)(v7 + 36) = *(_QWORD *)(v5 + 56);
                if ( v12 != 6 )
                {
                  *(_DWORD *)(v7 + 40) = *(_QWORD *)(v5 + 64);
                  if ( v12 != 7 )
                  {
                    *(_DWORD *)(v7 + 44) = *(_QWORD *)(v5 + 72);
                    if ( v12 != 8 )
                    {
                      *(_DWORD *)(v7 + 48) = *(_QWORD *)(v5 + 80);
                      if ( v12 != 9 )
                      {
                        *(_DWORD *)(v7 + 52) = *(_QWORD *)(v5 + 88);
                        if ( v12 != 10 )
                          goto LABEL_45;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    v13 = is_vmalloc_addr(v7);
    if ( (v13 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v15 = v13;
      dma_map_single_attrs___already_done = 1;
      v16 = (const char *)dev_driver_string(a1);
      v17 = *(const char **)(a1 + 112);
      if ( !v17 )
        v17 = *(const char **)a1;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v16, v17);
      __break(0x800u);
      if ( (v15 & 1) != 0 )
      {
LABEL_17:
        v14 = -12;
        goto LABEL_43;
      }
    }
    else if ( (v13 & 1) != 0 )
    {
      goto LABEL_17;
    }
    v18 = dma_map_page_attrs(
            a1,
            ((unsigned __int64)((v7 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v7 & 0xFF8,
            v8 + 40,
            1,
            0);
    if ( v18 == -1 )
      goto LABEL_17;
    v5 = v18;
    v3 = v7 + v11;
    down(&qcom_scm_sem_lock);
    do
      _arm_smccc_smc(1, &v27, v5, 0, 0, 0, 0, 0, v26, 0);
    while ( v26[0] == 1 );
    if ( v26[0] )
      break;
    up(&qcom_scm_sem_lock);
    v19 = v8 + v5 + 16;
    do
    {
      if ( (*(_BYTE *)(a1 + 844) & 0x40) == 0 )
        _dma_sync_single_for_cpu(a1, v19, 12, 2);
    }
    while ( !*(_DWORD *)(v3 + 8) );
    if ( (*(_BYTE *)(a1 + 844) & 0x40) == 0 )
      _dma_sync_single_for_cpu(a1, v19 + *(unsigned int *)(v3 + 4), 12, 2);
    if ( !a3 )
    {
      v14 = 0;
      goto LABEL_42;
    }
    v20 = *(unsigned int *)(v3 + 4);
    v21 = v11 + v20;
    if ( (unsigned __int64)(v11 + v20) <= 0xFFC )
    {
      v22 = (unsigned int *)(v3 + v20);
      *a3 = *v22;
      if ( v21 - 4089 >= 4 )
      {
        a3[1] = v22[1];
        if ( v21 <= 0xFF4 )
        {
          v14 = 0;
          a3[2] = v22[2];
          goto LABEL_42;
        }
      }
    }
    __break(1u);
LABEL_45:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v7 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 4096);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( !v7 )
      goto LABEL_46;
  }
  if ( LODWORD(v26[0]) < 0xFFFFFFF4 )
    v14 = -22;
  else
    v14 = *(_DWORD *)((char *)&unk_12DB8 + (((v26[0] << 32) + 0xC00000000LL) >> 30));
  up(&qcom_scm_sem_lock);
LABEL_42:
  dma_unmap_page_attrs(a1, v5, v10, 1, 0);
LABEL_43:
  kfree(v7);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v14;
}
