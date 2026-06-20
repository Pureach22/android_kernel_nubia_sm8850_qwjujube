__int64 __fastcall mmrm_init_sw_clk_mgr(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x25
  unsigned __int64 v7; // x26
  __int64 v8; // x27
  _DWORD *v9; // x9
  __int64 v10; // x8
  int v11; // w9
  unsigned int v12; // w8
  unsigned __int64 v13; // x9
  __int64 v14; // x13
  int v15; // w13
  int v16; // w14
  int v17; // w15
  int v18; // w8
  unsigned __int64 StatusReg; // x21
  __int64 v21; // x22
  __int64 (__fastcall *v22)(_QWORD, _QWORD); // x0

  v2 = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 160);
  if ( !v2 )
    goto LABEL_20;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 80);
    *(_QWORD *)(v2 + 56) = a1;
    v4 = _kmalloc_noprof((unsigned int)(720 * v3), 3520);
    *(_QWORD *)(v2 + 64) = v4;
    if ( !v4 )
      break;
    v5 = *(_DWORD *)(a1 + 80);
    *(_QWORD *)(v2 + 72) = v5;
    *(_QWORD *)(v2 + 136) = v2 + 136;
    *(_QWORD *)(v2 + 144) = v2 + 136;
    if ( v5 )
    {
      v6 = 0;
      v7 = 0;
      v8 = 684;
      do
      {
        v9 = (_DWORD *)(*(_QWORD *)(a1 + 72) + v6);
        v10 = *(_QWORD *)(v2 + 64);
        *(_DWORD *)(v10 + v8 - 524) = v9[1] | (*v9 << 16);
        *(_DWORD *)(v10 + v8 - 412) = v9[2];
        *(_DWORD *)(v10 + v8 - 376) = v9[3];
        *(_DWORD *)(v10 + v8 - 508) = v9[4];
        if ( (~msm_mmrm_debug & 0x10002) == 0 )
          printk(&unk_CA14, "high", "mmrm_sw_prepare_table");
        ++v7;
        v8 += 720;
        v6 += 20;
      }
      while ( v7 < *(unsigned int *)(v2 + 72) );
    }
    v11 = *(_DWORD *)(a1 + 88);
    v12 = *(unsigned __int16 *)(a1 + 48);
    *(_QWORD *)(v2 + 128) = 0;
    *(_DWORD *)(v2 + 124) = v11;
    *(_WORD *)(v2 + 120) = v12;
    if ( !v12 )
    {
LABEL_18:
      _mutex_init(v2, "&sw_clk_mgr->lock", &mmrm_init_sw_clk_mgr___key);
      v18 = *(_DWORD *)(a1 + 24);
      *(_QWORD *)(a1 + 96) = v2;
      *(_QWORD *)(v2 + 152) = clk_client_swops;
      *(_DWORD *)(v2 + 48) = v18;
      return 0;
    }
    v13 = 0;
    while ( 1 )
    {
      v15 = *(_DWORD *)(v2 + 72);
      if ( v15 )
        break;
LABEL_11:
      if ( ++v13 >= v12 )
        goto LABEL_18;
    }
    if ( v13 <= 4 )
    {
      v16 = *(_DWORD *)(a1 + 28 + 4 * v13);
      v17 = 0;
      while ( *(_DWORD *)(*(_QWORD *)(v2 + 64) + 720LL * v17 + 160) != v16 )
      {
        if ( v15 == ++v17 )
          goto LABEL_11;
      }
      v14 = v2 + 80 + 8 * v13;
      *(_DWORD *)v14 = v16;
      v12 = *(unsigned __int16 *)(v2 + 120);
      *(_WORD *)(v14 + 4) = v17;
      goto LABEL_11;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    v22 = _kmalloc_noprof;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v2 = _kmalloc_cache_noprof(v22, 3520, 160);
    *(_QWORD *)(StatusReg + 80) = v21;
    if ( !v2 )
    {
LABEL_20:
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_E146, "err ", "mmrm_init_sw_clk_mgr");
      goto LABEL_25;
    }
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_E185, "err ", "mmrm_init_sw_clk_mgr");
  kfree(v2);
  *(_QWORD *)(a1 + 96) = 0;
LABEL_25:
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_DA62, "err ", "mmrm_init_sw_clk_mgr");
  return 4294967284LL;
}
