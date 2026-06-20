__int64 __fastcall fastrpc_dev_map_dma(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x22
  __int64 v9; // x19
  unsigned int v10; // w8
  unsigned int v12; // w20
  unsigned int v18; // w9
  __int64 v19; // x20
  int *v20; // x26
  __int64 v22; // x0
  int v23; // w28
  int v24; // w23
  __int64 v25; // x22
  __int64 result; // x0
  __int64 v28; // x1
  unsigned int v30; // w8
  int v32; // w8
  __int64 v33; // x21
  int v34; // w8
  unsigned int v37; // w8
  __int64 v38; // x8
  __int64 v39; // x24
  __int64 *v40; // x9
  int v41; // w10
  int v42; // w11
  __int64 v43; // x25
  __int64 v44; // x8
  __int64 v45; // x2
  __int64 v46; // x3
  __int64 v47; // x4
  __int64 v48; // x5
  __int64 v49; // [xsp+8h] [xbp-128h] BYREF
  _QWORD v50[2]; // [xsp+10h] [xbp-120h] BYREF
  __int64 v51; // [xsp+20h] [xbp-110h] BYREF
  int v52; // [xsp+28h] [xbp-108h] BYREF
  __int64 v53; // [xsp+2Ch] [xbp-104h]
  int v54; // [xsp+34h] [xbp-FCh]
  __int64 v55; // [xsp+38h] [xbp-F8h]
  __int64 v56; // [xsp+40h] [xbp-F0h]
  _QWORD v57[15]; // [xsp+48h] [xbp-E8h] BYREF
  _QWORD v58[3]; // [xsp+C0h] [xbp-70h] BYREF
  _QWORD *v59; // [xsp+D8h] [xbp-58h]
  __int64 v60; // [xsp+E0h] [xbp-50h]
  __int64 v61; // [xsp+E8h] [xbp-48h]
  _QWORD *v62; // [xsp+F0h] [xbp-40h]
  __int64 v63; // [xsp+F8h] [xbp-38h]
  __int64 v64; // [xsp+100h] [xbp-30h]
  __int64 *v65; // [xsp+108h] [xbp-28h]
  __int64 v66; // [xsp+110h] [xbp-20h]
  __int64 v67; // [xsp+118h] [xbp-18h]
  __int64 v68; // [xsp+120h] [xbp-10h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v8 = raw_spin_lock_irqsave(&g_frpc);
  if ( !a1 || *(_BYTE *)(a1 + 944) == 1 )
  {
    printk(&unk_24BE7, "fastrpc_dev_map_dma", v4, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    result = -3;
    goto LABEL_46;
  }
  v9 = *(_QWORD *)(a1 + 936);
  if ( !v9 )
  {
    printk(&unk_2316F, "fastrpc_dev_map_dma", v4, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    result = -9;
    goto LABEL_46;
  }
  v10 = *(_DWORD *)(v9 + 664);
  _X0 = (unsigned int *)(v9 + 664);
  if ( v10 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v18 = __ldxr(_X0);
      while ( v18 == v10 && __stxr(v10 + 1, _X0) );
      v12 = v10;
      if ( v18 == v10 )
        break;
      v12 = 0;
      v10 = v18;
    }
    while ( v18 );
  }
  else
  {
    v12 = 0;
  }
  if ( (((v12 + 1) | v12) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X0, 0);
    if ( v12 )
      goto LABEL_15;
LABEL_28:
    printk(&unk_24DA5, "fastrpc_dev_map_dma", v9, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    result = -2;
    goto LABEL_46;
  }
  if ( !v12 )
    goto LABEL_28;
LABEL_15:
  v19 = *(_QWORD *)(v9 + 128);
  v20 = (int *)(v19 + 64136);
  _X0 = (unsigned int *)(v19 + 51664);
  __asm { PRFM            #0x11, [X0] }
  do
    v30 = __ldxr(_X0);
  while ( __stxr(v30 + 1, _X0) );
  if ( v30 )
  {
    if ( (((v30 + 1) | v30) & 0x80000000) == 0 )
      goto LABEL_17;
    v28 = 1;
  }
  else
  {
    v28 = 2;
  }
  refcount_warn_saturate(_X0, v28);
LABEL_17:
  *(_BYTE *)(v9 + 307) = 1;
  raw_spin_unlock_irqrestore(&g_frpc, v8);
  v22 = raw_spin_lock_irqsave(v19 + 51600);
  v23 = *v20;
  if ( *v20 )
  {
    raw_spin_unlock_irqrestore(v19 + 51600, v22);
    v24 = -32;
    goto LABEL_39;
  }
  ++*(_DWORD *)(v19 + 64180);
  raw_spin_unlock_irqrestore(v19 + 51600, v22);
  mutex_lock(v9 + 328);
  v24 = fastrpc_map_create(
          v9,
          0xFFFFFFFFLL,
          0,
          *(_QWORD *)a2,
          *(_QWORD *)(a2 + 16),
          *(unsigned int *)(a2 + 8),
          6,
          &v49,
          1);
  mutex_unlock(v9 + 328);
  v25 = v49;
  if ( v24 )
  {
LABEL_22:
    if ( !v25 )
      goto LABEL_39;
    goto LABEL_23;
  }
  _X10 = (unsigned int *)(v49 + 120);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v37 = __ldxr(_X10);
    if ( v37 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v37 )
  {
    v24 = -114;
    goto LABEL_22;
  }
  v38 = *(_QWORD *)(v25 + 64);
  v39 = *(_QWORD *)(v25 + 72);
  v40 = *(__int64 **)(v9 + 136);
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = nullptr;
  v41 = *(_DWORD *)(v9 + 244);
  v62 = nullptr;
  v63 = 0;
  v42 = *(_DWORD *)(v25 + 108);
  v60 = 0;
  v61 = 0;
  v58[2] = 0;
  v59 = nullptr;
  v51 = 0;
  v43 = *v40;
  v50[0] = v38;
  v50[1] = v39;
  v53 = 0xFFFFFFFFLL;
  v55 = 0;
  v56 = 16;
  v59 = v50;
  v60 = 16;
  v62 = v50;
  v63 = 0;
  v65 = &v51;
  v66 = 8;
  v52 = v41;
  v54 = v42;
  memset(&v57[2], 0, 104);
  v58[0] = &v52;
  v58[1] = 32;
  v57[0] = 0xA03010000000001LL;
  v57[1] = v58;
  v24 = fastrpc_internal_invoke(v9, 1, v57);
  if ( !v24 )
  {
    v44 = v51;
    *(_QWORD *)(v25 + 96) = v51;
    *(_QWORD *)(a2 + 24) = v44;
    *(_DWORD *)(v25 + 120) = 2;
    goto LABEL_39;
  }
  dev_err(v43, "mem mmap error, fd %d, vaddr %llx, size %zx, err 0x%x\n", -1, 0, v39, v24);
  printk(&unk_2347D, "fastrpc_dev_map_dma", v45, v46, v47, v48);
  *(_DWORD *)(v25 + 120) = 0;
  if ( v25 )
  {
LABEL_23:
    mutex_lock(v9 + 328);
    _X0 = (unsigned int *)(v25 + 112);
    __asm { PRFM            #0x11, [X0] }
    do
      v32 = __ldxr(_X0);
    while ( __stlxr(v32 - 1, _X0) );
    if ( v32 == 1 )
    {
      __dmb(9u);
      _fastrpc_free_map(v25);
    }
    else if ( v32 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    mutex_unlock(v9 + 328);
  }
LABEL_39:
  v33 = raw_spin_lock_irqsave(v19 + 51600);
  if ( *(int *)(v9 + 628) >= 3 && *(_BYTE *)(v9 + 307) == 1 )
    complete(v9 + 472);
  *(_BYTE *)(v9 + 307) = 0;
  if ( !v23 )
  {
    v34 = *(_DWORD *)(v19 + 64180) - 1;
    *(_DWORD *)(v19 + 64180) = v34;
    if ( !v34 )
      _wake_up(v19 + 64216, 1, 1, 0);
  }
  raw_spin_unlock_irqrestore(v19 + 51600, v33);
  fastrpc_channel_ctx_put(v19);
  fastrpc_file_put((__int64 *)v9, 0);
  result = v24;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
