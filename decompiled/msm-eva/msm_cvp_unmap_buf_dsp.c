__int64 __fastcall msm_cvp_unmap_buf_dsp(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v5; // x8
  __int64 *v6; // x19
  unsigned int *v7; // x1
  __int64 v8; // x8
  unsigned __int64 v9; // x22
  int v10; // w8
  int v11; // w8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int64 result; // x0
  unsigned __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  void *v18; // x0
  unsigned __int64 v19; // x8
  __int64 v20; // x19
  unsigned __int64 StatusReg; // x8
  __int64 **v22; // x8
  __int64 *v23; // x9
  unsigned int v30; // w10

  if ( !a1 || !a2 || !a1[16] )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(StatusReg + 1800);
    v17 = *(unsigned int *)(StatusReg + 1804);
    v18 = &unk_912BD;
LABEL_32:
    printk(v18, v16, v17, &unk_8E7CE);
    return 4294967274LL;
  }
  if ( !a1[40] )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v15 = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(v15 + 1800);
    v17 = *(unsigned int *)(v15 + 1804);
    v18 = &unk_86178;
    goto LABEL_32;
  }
  v2 = a1[18];
  if ( !v2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v19 = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(v19 + 1800);
    v17 = *(unsigned int *)(v19 + 1804);
    v18 = &unk_948BC;
    goto LABEL_32;
  }
  v3 = (__int64)a1;
  mutex_lock(v2 + 376);
  v5 = a2;
  v6 = (__int64 *)(v2 + 360);
  do
  {
    v6 = (__int64 *)*v6;
    if ( v6 == (__int64 *)(v2 + 360) )
    {
      v20 = v5;
      mutex_unlock(v2 + 376);
      print_client_buffer(1, (__int64)"invalid", v3, v20);
      return 4294967274LL;
    }
  }
  while ( *((_DWORD *)v6 + 4) != *(_DWORD *)(v5 + 8) );
  v7 = (unsigned int *)v6[7];
  v8 = v7[16];
  if ( (_DWORD)v8 )
  {
    v9 = *(_QWORD *)(v2 + 424);
    if ( v9 >= 0x29 )
    {
      __break(0x5512u);
    }
    else
    {
      memcpy((void *)(v2 + 152 * v9 + 440), v7, 0x98u);
      v10 = *(_DWORD *)(v2 + 432);
      if ( (unsigned int)(v10 + 1) < 0x28 )
        v11 = v10 + 1;
      else
        v11 = 40;
      *(_DWORD *)(v2 + 432) = v11;
      if ( v9 < 0x27 )
        v12 = v9 + 1;
      else
        v12 = v9 - 39;
      *(_QWORD *)(v2 + 424) = v12;
      LODWORD(v3) = msm_cvp_unmap_smem(v3, v6[7], (__int64)"unmap dsp");
      if ( (_DWORD)v3 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v13 = _ReadStatusReg(SP_EL0);
          printk(&unk_86E2C, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
        }
      }
      else
      {
        msm_cvp_smem_put_dma_buf(*(_QWORD *)(v6[7] + 48));
      }
      v8 = v6[7];
    }
    _X8 = (unsigned int *)(v8 + 40);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 - 1, _X8) );
  }
  else
  {
    LODWORD(v3) = 0;
  }
  v22 = (__int64 **)v6[1];
  if ( *v22 == v6 && (v23 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
  {
    v23[1] = (__int64)v22;
    *v22 = v23;
  }
  else
  {
    _list_del_entry_valid_or_report(v6);
  }
  *v6 = 0xDEAD000000000100LL;
  v6[1] = 0xDEAD000000000122LL;
  mutex_unlock(v2 + 376);
  cvp_kmem_cache_free((_QWORD *)(cvp_driver + 120));
  cvp_kmem_cache_free((_QWORD *)(cvp_driver + 104));
  return (unsigned int)v3;
}
