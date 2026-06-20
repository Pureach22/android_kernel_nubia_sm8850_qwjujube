__int64 __fastcall qce_sps_init(__int64 a1)
{
  __int64 v2; // x22
  _UNKNOWN **v3; // x8
  void *v4; // x10
  void *v5; // x9
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x0
  unsigned int v11; // w0
  int v12; // w8
  __int64 v13; // x9
  __int64 v14; // x10
  _BOOL4 v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w0
  __int64 *v18; // x1
  __int64 *v19; // x20
  unsigned int inited; // w21
  unsigned int v21; // w0
  __int64 v22; // x22
  __int64 v23; // x2
  __int64 v25; // [xsp+8h] [xbp-98h] BYREF
  __int64 v26; // [xsp+10h] [xbp-90h]
  __int64 v27; // [xsp+18h] [xbp-88h]
  __int64 v28; // [xsp+20h] [xbp-80h]
  __int64 v29; // [xsp+28h] [xbp-78h]
  __int64 v30; // [xsp+30h] [xbp-70h]
  __int64 v31; // [xsp+38h] [xbp-68h]
  __int64 v32; // [xsp+40h] [xbp-60h]
  __int64 v33; // [xsp+48h] [xbp-58h]
  __int64 v34; // [xsp+50h] [xbp-50h]
  __int64 v35; // [xsp+58h] [xbp-48h]
  __int64 v36; // [xsp+60h] [xbp-40h]
  __int64 v37; // [xsp+68h] [xbp-38h]
  __int64 v38; // [xsp+70h] [xbp-30h]
  __int64 v39; // [xsp+78h] [xbp-28h]
  __int64 v40; // [xsp+80h] [xbp-20h]
  __int64 v41; // [xsp+88h] [xbp-18h]
  __int64 v42; // [xsp+90h] [xbp-10h]
  __int64 v43; // [xsp+98h] [xbp-8h]

  v2 = a1 + 69632;
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  mutex_lock(&bam_register_lock);
  v3 = &qce50_bam_list;
  do
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &qce50_bam_list )
      goto LABEL_6;
  }
  while ( *((_DWORD *)v3 + 7) != *(_DWORD *)(a1 + 52) );
  if ( v3 )
  {
    v4 = v3[2];
    ++*((_DWORD *)v3 + 6);
    *(_QWORD *)(a1 + 392) = v4;
    *(_DWORD *)(a1 + 292) = *((_DWORD *)v3 + 7);
    v5 = v3[4];
    *(_QWORD *)(a1 + 8) = v3;
    *(_QWORD *)(a1 + 296) = v5;
    *(_BYTE *)(a1 + 68) = *((_BYTE *)v3 + 40);
    goto LABEL_21;
  }
LABEL_6:
  v6 = _kmalloc_cache_noprof(kfree, 3520, 48);
  if ( !v6 )
    goto LABEL_50;
  v7 = *(unsigned int *)(a1 + 52);
  v8 = *(unsigned int *)(a1 + 56);
  if ( arm64_use_ng_mappings )
    v9 = 0x68000000000F13LL;
  else
    v9 = 0x68000000000713LL;
  *(_DWORD *)(v6 + 24) = 1;
  *(_DWORD *)(v6 + 28) = v7;
  v10 = ioremap_prot(v7, v8, v9);
  *(_QWORD *)(v6 + 32) = v10;
  if ( !v10 )
  {
    kfree(v6);
    printk(&unk_161B3, "qce_sps_get_bam", v23);
LABEL_50:
    inited = -12;
LABEL_51:
    mutex_unlock(&bam_register_lock);
    goto LABEL_52;
  }
  *(_QWORD *)(a1 + 296) = v10;
  *(_QWORD *)(v6 + 16) = 0;
  *(_DWORD *)(a1 + 292) = *(_DWORD *)(v6 + 28);
  v11 = readl_relaxed((unsigned int *)(v10 + 124));
  v12 = (v11 >> 27) & 1;
  *(_BYTE *)(v6 + 40) = (v11 & 0x8000000) != 0;
  if ( (v11 & 0x8000000) == 0 )
  {
    printk(&unk_16437, "qce_sps_get_bam", v11);
    LOBYTE(v12) = *(_BYTE *)(v6 + 40);
    *(_BYTE *)(a1 + 128) = 0;
  }
  v13 = *(unsigned int *)(a1 + 292);
  v14 = *(_QWORD *)(a1 + 296);
  *(_BYTE *)(a1 + 68) = v12;
  v26 = v13;
  v27 = v14;
  LODWORD(v14) = *(_DWORD *)(a1 + 288);
  HIDWORD(v33) = 16;
  HIDWORD(v29) = 64;
  HIDWORD(v28) = v14;
  v15 = (v12 & 1) == 0 || *(_DWORD *)(a1 + 60) != 0;
  v16 = *(_DWORD *)(a1 + 312);
  LODWORD(v38) = v15;
  v39 = v16 | 0x200000000LL;
  LODWORD(v25) = 1024;
  v17 = sps_register_bam_device(&v25, v6 + 16);
  if ( v17 )
  {
    printk(&unk_16687, "qce_sps_get_bam", v17);
    iounmap(*(_QWORD *)(v6 + 32));
    kfree(v6);
    inited = -5;
    goto LABEL_51;
  }
  *(_QWORD *)(a1 + 8) = v6;
  v18 = (__int64 *)off_598;
  if ( off_598 == (_UNKNOWN **)v6 || *off_598 != (_UNKNOWN *)&qce50_bam_list )
  {
    _list_add_valid_or_report(v6);
  }
  else
  {
    off_598 = (_UNKNOWN **)v6;
    *(_QWORD *)v6 = &qce50_bam_list;
    *(_QWORD *)(v6 + 8) = v18;
    *v18 = v6;
  }
  *(_QWORD *)(a1 + 392) = *(_QWORD *)(v6 + 16);
LABEL_21:
  mutex_unlock(&bam_register_lock);
  if ( *(_BYTE *)(v2 + 618) == 1 && *(_DWORD *)(a1 + 316) )
  {
    v19 = (__int64 *)(a1 + 416);
    inited = qce_sps_init_ep_conn(a1, a1 + 416, 0, 1);
    if ( inited )
      goto LABEL_47;
    inited = qce_sps_init_ep_conn(a1, a1 + 1520, 0, 0);
    if ( inited )
    {
LABEL_46:
      v22 = *v19;
      sps_disconnect(*v19);
      dma_free_attrs(*(_QWORD *)a1, *((unsigned int *)v19 + 22), v19[8], v19[9], 0);
      sps_free_endpoint(v22);
      goto LABEL_47;
    }
  }
  if ( *(_BYTE *)(v2 + 619) == 1 )
  {
    if ( *(_DWORD *)(a1 + 320) )
    {
      v19 = (__int64 *)(a1 + 600);
      inited = qce_sps_init_ep_conn(a1, a1 + 600, 1, 1);
      if ( inited )
        goto LABEL_47;
      v21 = qce_sps_init_ep_conn(a1, a1 + 1704, 1, 0);
      if ( v21 )
        goto LABEL_45;
    }
    if ( *(_BYTE *)(v2 + 619) != 1 )
      goto LABEL_48;
    if ( *(_DWORD *)(a1 + 324) )
    {
      v19 = (__int64 *)(a1 + 784);
      inited = qce_sps_init_ep_conn(a1, a1 + 784, 2, 1);
      if ( inited )
        goto LABEL_47;
      v21 = qce_sps_init_ep_conn(a1, a1 + 1888, 2, 0);
      if ( v21 )
        goto LABEL_45;
    }
    if ( *(_BYTE *)(v2 + 619) != 1 )
      goto LABEL_48;
    if ( *(_DWORD *)(a1 + 328) )
    {
      v19 = (__int64 *)(a1 + 968);
      inited = qce_sps_init_ep_conn(a1, a1 + 968, 3, 1);
      if ( inited )
        goto LABEL_47;
      v21 = qce_sps_init_ep_conn(a1, a1 + 2072, 3, 0);
      if ( v21 )
        goto LABEL_45;
    }
    if ( *(_BYTE *)(v2 + 619) != 1 )
      goto LABEL_48;
    if ( *(_DWORD *)(a1 + 332) )
    {
      v19 = (__int64 *)(a1 + 1152);
      inited = qce_sps_init_ep_conn(a1, a1 + 1152, 4, 1);
      if ( inited )
        goto LABEL_47;
      v21 = qce_sps_init_ep_conn(a1, a1 + 2256, 4, 0);
      if ( v21 )
      {
LABEL_45:
        inited = v21;
        goto LABEL_46;
      }
    }
    if ( *(_BYTE *)(v2 + 619) == 1 && *(_DWORD *)(a1 + 336) )
    {
      v19 = (__int64 *)(a1 + 1336);
      inited = qce_sps_init_ep_conn(a1, a1 + 1336, 5, 1);
      if ( !inited )
      {
        v21 = qce_sps_init_ep_conn(a1, a1 + 2440, 5, 0);
        if ( v21 )
          goto LABEL_45;
        goto LABEL_48;
      }
LABEL_47:
      qce_sps_release_bam(a1);
      goto LABEL_52;
    }
  }
LABEL_48:
  printk(&unk_1504B, "qce_sps_init", *(unsigned int *)(a1 + 292));
  inited = 0;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return inited;
}
