__int64 *__fastcall _dsp_cvp_mem_free(__int64 a1)
{
  char v2; // w8
  __int64 *result; // x0
  __int64 *v4; // x19
  __int64 *v5; // x28
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x24
  void *v9; // x10
  __int64 v10; // x8
  __int64 v11; // x21
  void *v12; // x24
  int v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 StatusReg; // x8
  __int64 *v16; // x8
  __int64 v17; // x9
  unsigned int v24; // w10
  unsigned int v27; // w10
  __int64 v28; // [xsp+8h] [xbp-8h]

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_8528C, "dsp", "__dsp_cvp_mem_free", (unsigned int)off_6C7E0);
  result = cvp_get_fastrpc_node_with_handle((unsigned int)off_6C7E0);
  if ( !result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      result = (__int64 *)printk(
                            &unk_8493E,
                            *(unsigned int *)(StatusReg + 1800),
                            *(unsigned int *)(StatusReg + 1804),
                            &unk_8E7CE);
    }
    *(_DWORD *)(a1 + 4) = -1;
    return result;
  }
  v4 = result;
  v5 = result + 45;
  v28 = result[32];
  mutex_lock(result + 47);
  v8 = v4[45];
  if ( (__int64 *)v8 == v5 || !v8 )
    goto LABEL_30;
  v9 = &unk_91B94;
  while ( 1 )
  {
    v10 = *(_QWORD *)(v8 + 56);
    v11 = *(_QWORD *)v8;
    if ( v10 )
      break;
    if ( (msm_cvp_debug & 0x800) == 0 || msm_cvp_debug_out )
      goto LABEL_14;
    v12 = v9;
    printk(v9, "dsp", v6, v7);
    v9 = v12;
    if ( (__int64 *)v11 == v5 )
      goto LABEL_30;
LABEL_15:
    v8 = v11;
    if ( !v11 )
      goto LABEL_30;
  }
  v7 = *(unsigned int *)(v10 + 64);
  if ( (_DWORD)v7 != dword_6C8A8 || *(_DWORD *)(v8 + 16) != dword_6C89C )
  {
LABEL_14:
    if ( (__int64 *)v11 == v5 )
      goto LABEL_30;
    goto LABEL_15;
  }
  v13 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_90F61, "dsp", "__dsp_cvp_mem_free", v7);
    v13 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 0x800) != 0 )
      goto LABEL_26;
  }
  else if ( (msm_cvp_debug & 0x800) != 0 )
  {
LABEL_26:
    if ( !v13 )
      printk(&unk_898E2, "dsp", *(unsigned int *)(v8 + 16), (unsigned int)dword_6C89C);
  }
  if ( (unsigned int)eva_fastrpc_dev_unmap_dma(v28, v8, v6, v7) )
  {
LABEL_29:
    *(_DWORD *)(a1 + 4) = -1;
  }
  else
  {
    if ( (unsigned int)cvp_release_dsp_buffers(v8) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v14 = _ReadStatusReg(SP_EL0);
        printk(&unk_93ED2, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
      }
      goto LABEL_29;
    }
    v16 = *(__int64 **)(v8 + 8);
    if ( *v16 == v8 && (v17 = *(_QWORD *)v8, *(_QWORD *)(*(_QWORD *)v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v17 + 8) = v16;
      *v16 = v17;
    }
    else
    {
      _list_del_entry_valid_or_report(v8);
    }
    *(_QWORD *)v8 = 0xDEAD000000000100LL;
    *(_QWORD *)(v8 + 8) = 0xDEAD000000000122LL;
    _X8 = (unsigned int *)(v4 + 815);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 - 1, _X8) );
    cvp_kmem_cache_free((_QWORD *)(cvp_driver + 104));
  }
LABEL_30:
  result = (__int64 *)mutex_unlock(v4 + 47);
  if ( *((int *)v4 + 7) >= 1 )
  {
    _X8 = (unsigned int *)v4 + 7;
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 - 1, _X8) );
  }
  return result;
}
