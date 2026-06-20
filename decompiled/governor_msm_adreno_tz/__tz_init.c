__int64 __fastcall _tz_init(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x22
  __int64 v3; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  _DWORD *v8; // x13
  __int64 v9; // x11
  __int64 *v10; // x12
  __int64 v11; // x14
  __int64 v12; // x15
  __int64 v13; // x16
  _DWORD *v14; // x11
  __int64 v15; // x12
  __int64 v16; // x20
  __int64 v17; // x21
  __int64 v18; // x8
  unsigned __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x8
  unsigned int inited; // w21
  __int64 v23; // x0
  int v24; // w23
  int v25; // w24
  _DWORD *v26; // x20
  __int64 v27; // x21
  __int64 v28; // x0
  __int64 v29; // x8
  unsigned __int64 v30; // x12
  __int64 v31; // x9
  __int64 v32; // x8
  int v33; // w19
  void *v34; // x0
  void *v35; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v37; // x23
  int v39; // [xsp+4h] [xbp-ACh] BYREF
  __int64 v40; // [xsp+8h] [xbp-A8h] BYREF
  _DWORD *v41; // [xsp+10h] [xbp-A0h]
  __int64 v42; // [xsp+18h] [xbp-98h]
  _DWORD src[33]; // [xsp+24h] [xbp-8Ch] BYREF
  __int64 v44; // [xsp+A8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 976);
  v39 = 0;
  v2 = *(_QWORD *)(v1 - 8);
  *(_QWORD *)(a1 + 1184) = v2;
  v3 = *(unsigned int *)(v1 + 56);
  if ( (unsigned int)v3 > 0x20 )
  {
    inited = -22;
    v35 = &unk_6E6B;
LABEL_54:
    printk(v35);
    goto LABEL_55;
  }
  memset(&src[1], 0, 128);
  if ( (_DWORD)v3 )
  {
    v5 = *(_QWORD *)(v1 + 48);
    if ( (unsigned int)v3 >= 3 )
    {
      v8 = &src[2];
      v9 = 2;
      if ( (v3 & 1) != 0 )
        v9 = v3 & 1;
      v10 = (__int64 *)(v5 + 8);
      v6 = v3 - v9;
      v7 = v3 - v9 + 1;
      v11 = v6;
      do
      {
        v12 = *(v10 - 1);
        v13 = *v10;
        v11 -= 2;
        v10 += 2;
        *(v8 - 1) = v12;
        *v8 = v13;
        v8 += 2;
      }
      while ( v11 );
    }
    else
    {
      v6 = 0;
      v7 = 1;
    }
    v14 = &src[v7];
    while ( v6 != 32 )
    {
      v15 = *(_QWORD *)(v5 + 8 * v6++);
      *v14++ = v15;
      if ( v3 == v6 )
        goto LABEL_12;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v37 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v16 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 4096);
    *(_QWORD *)(StatusReg + 80) = v37;
    if ( !v16 )
      goto LABEL_52;
    goto LABEL_17;
  }
LABEL_12:
  src[0] = v3;
  if ( (qcom_scm_dcvs_core_available() & 1) == 0 )
  {
    inited = -22;
    goto LABEL_53;
  }
  v41 = nullptr;
  v42 = 0;
  v40 = 0;
  if ( (qtee_shmbridge_is_enabled() & 1) != 0 )
  {
    if ( !(unsigned int)qtee_shmbridge_allocate_shm(4096, &v40) )
    {
      v17 = v40;
      v16 = (__int64)v41;
      goto LABEL_20;
    }
LABEL_52:
    inited = -12;
    goto LABEL_53;
  }
  v16 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 4096);
  if ( !v16 )
    goto LABEL_52;
LABEL_17:
  v18 = v16 << 8 >> 8;
  v19 = (unsigned __int64)(v18 + 0x8000000000LL) >> 38;
  v20 = memstart_addr + v18 + 0x8000000000LL;
  v21 = v18 - kimage_voffset;
  if ( v19 )
    v17 = v21;
  else
    v17 = v20;
LABEL_20:
  memcpy((void *)v16, src, 0x84u);
  __dsb(0xFu);
  if ( (*(_BYTE *)(a1 + 908) & 0x40) == 0 )
    _dma_sync_single_for_device(a1 + 64, v17, 4096, 0);
  inited = qcom_scm_dcvs_init_v2(v17, 132, &v39);
  if ( inited )
  {
    if ( (qtee_shmbridge_is_enabled() & 1) != 0 )
      goto LABEL_24;
    goto LABEL_27;
  }
  *(_BYTE *)(v2 + 148) = 1;
  if ( (qtee_shmbridge_is_enabled() & 1) == 0 )
  {
LABEL_27:
    v23 = kfree_sensitive(v16);
    if ( !inited )
      goto LABEL_28;
LABEL_53:
    v35 = &unk_6DE5;
    goto LABEL_54;
  }
LABEL_24:
  v23 = qtee_shmbridge_free_shm(&v40);
  if ( inited )
    goto LABEL_53;
LABEL_28:
  if ( *(_BYTE *)(v2 + 150) != 1 )
    goto LABEL_49;
  if ( *(_BYTE *)(v2 + 148) != 1 || (qcom_scm_dcvs_ca_available(v23) & 1) == 0 )
  {
    v34 = &unk_6D1F;
    goto LABEL_48;
  }
  v24 = *(_DWORD *)(v2 + 40);
  v25 = *(_DWORD *)(v2 + 44);
  v41 = nullptr;
  v42 = 0;
  v40 = 0;
  if ( (qtee_shmbridge_is_enabled() & 1) != 0 )
  {
    if ( !(unsigned int)qtee_shmbridge_allocate_shm(4096, &v40) )
    {
      v27 = v40;
      v26 = v41;
      goto LABEL_38;
    }
  }
  else
  {
    v28 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 4096);
    v26 = (_DWORD *)v28;
    if ( v28 )
    {
      v29 = v28 << 8 >> 8;
      v30 = (unsigned __int64)(v29 + 0x8000000000LL) >> 38;
      v31 = memstart_addr + v29 + 0x8000000000LL;
      v32 = v29 - kimage_voffset;
      if ( v30 )
        v27 = v32;
      else
        v27 = v31;
LABEL_38:
      *v26 = v24;
      v26[1] = v25;
      __dsb(0xFu);
      if ( (*(_BYTE *)(a1 + 908) & 0x40) == 0 )
        _dma_sync_single_for_device(a1 + 64, v27, 4096, 0);
      v33 = qcom_scm_dcvs_init_ca_v2(v27, 8);
      if ( (qtee_shmbridge_is_enabled() & 1) != 0 )
      {
        qtee_shmbridge_free_shm(&v40);
        if ( !v33 )
          goto LABEL_49;
      }
      else
      {
        kfree_sensitive(v26);
        if ( !v33 )
          goto LABEL_49;
      }
    }
  }
  v34 = &unk_6D5F;
LABEL_48:
  printk(v34);
  *(_BYTE *)(v2 + 150) = 0;
LABEL_49:
  inited = 0;
  if ( v39 )
    goto LABEL_53;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return inited;
}
