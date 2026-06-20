__int64 __fastcall _dsp_cvp_mem_alloc(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x22
  __int64 v6; // x21
  __int64 v7; // x3
  __int64 v8; // x8
  __int64 v9; // x3
  int v10; // w8
  __int64 v11; // x22
  __int64 v12; // x23
  __int64 *v13; // x1
  int v14; // w8
  int v15; // w9
  __int64 v16; // x3
  int v17; // w4
  unsigned __int64 v18; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x8
  unsigned int v27; // w10
  unsigned int v30; // w9
  unsigned int v33; // w10
  unsigned int v36; // w9
  _QWORD v37[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v38; // [xsp+18h] [xbp-18h]
  __int64 v39; // [xsp+20h] [xbp-10h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_898C5, "dsp", "__dsp_cvp_mem_alloc", (unsigned int)off_6C7E0);
  result = (__int64)cvp_get_fastrpc_node_with_handle((unsigned int)off_6C7E0);
  if ( result )
  {
    v4 = result;
    v5 = *(_QWORD *)(result + 256);
    result = cvp_kmem_cache_zalloc((_QWORD *)(cvp_driver + 104), 3264);
    if ( !result )
      goto LABEL_8;
    v6 = result;
    if ( (unsigned int)cvp_allocate_dsp_bufs(result, dword_6C898, dword_6C894) )
    {
LABEL_7:
      result = cvp_kmem_cache_free((_QWORD *)(cvp_driver + 104));
LABEL_8:
      *(_DWORD *)(a1 + 4) = -1;
      if ( *(int *)(v4 + 28) >= 1 )
      {
        _X8 = (unsigned int *)(v4 + 28);
        __asm { PRFM            #0x11, [X8] }
        do
          v27 = __ldxr(_X8);
        while ( __stxr(v27 - 1, _X8) );
      }
      goto LABEL_14;
    }
    v38 = 0;
    v39 = 0;
    v37[1] = 0;
    if ( dword_6C8AC == 1 )
    {
      v8 = *(_QWORD *)(v6 + 56);
      v9 = *(unsigned int *)(v8 + 80);
      v37[0] = *(_QWORD *)(v8 + 48);
      v38 = v9;
      if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        printk(&unk_87C5A, "dsp", "eva_fastrpc_dev_map_dma", v9);
      if ( (unsigned int)fastrpc_driver_invoke(v5, 1, v37) )
      {
        v10 = msm_cvp_debug_out;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_85BF5, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          v10 = msm_cvp_debug_out;
          if ( (msm_cvp_debug & 1) != 0 )
          {
LABEL_23:
            if ( !v10 )
            {
              v20 = _ReadStatusReg(SP_EL0);
              printk(&unk_85BF5, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
            }
          }
        }
        else if ( (msm_cvp_debug & 1) != 0 )
        {
          goto LABEL_23;
        }
        cvp_release_dsp_buffers(v6);
        goto LABEL_7;
      }
      v11 = v39;
      *(_DWORD *)(v6 + 16) = v39;
      _X8 = &nr_maps;
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr((unsigned int *)&nr_maps);
      while ( __stxr(v36 + 1, (unsigned int *)&nr_maps) );
    }
    else
    {
      if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        printk(&unk_93F60, "dsp", "eva_fastrpc_dev_map_dma", v7);
      v11 = 0;
      *(_DWORD *)(v6 + 16) = 0;
    }
    v12 = v4 + 360;
    mutex_lock(v4 + 376);
    v13 = *(__int64 **)(v4 + 368);
    if ( v6 == v4 + 360 || v13 == (__int64 *)v6 || *v13 != v12 )
    {
      _list_add_valid_or_report(v6, v13, v4 + 360);
    }
    else
    {
      *(_QWORD *)(v4 + 368) = v6;
      *(_QWORD *)v6 = v12;
      *(_QWORD *)(v6 + 8) = v13;
      *v13 = v6;
    }
    result = mutex_unlock(v4 + 376);
    _X8 = (unsigned int *)(v4 + 6520);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 + 1, _X8) );
    v14 = msm_cvp_debug_out;
    v15 = msm_cvp_debug & 0x800;
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    {
      result = printk(&unk_9277E, "dsp", "__dsp_cvp_mem_alloc", v11);
      v14 = msm_cvp_debug_out;
      v15 = msm_cvp_debug & 0x800;
    }
    v16 = *(unsigned int *)(*(_QWORD *)(v6 + 56) + 80LL);
    *(_DWORD *)(a1 + 68) = v16;
    *(_DWORD *)(a1 + 72) = *(_DWORD *)(v6 + 16);
    *(_DWORD *)(a1 + 76) = 0;
    v17 = *(_DWORD *)(*(_QWORD *)(v6 + 56) + 64LL);
    *(_QWORD *)(a1 + 92) = v11;
    *(_DWORD *)(a1 + 84) = v17;
    if ( v15 && !v14 )
      result = printk(&unk_83ED1, "dsp", "__dsp_cvp_mem_alloc", v16);
    if ( *(int *)(v4 + 28) >= 1 )
    {
      _X8 = (unsigned int *)(v4 + 28);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 - 1, _X8) );
    }
  }
  else
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v18 = _ReadStatusReg(SP_EL0);
      result = printk(&unk_8EF8F, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
    }
    *(_DWORD *)(a1 + 4) = -1;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
