__int64 __fastcall cvp_release_dsp_buffers(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x1
  __int64 v5; // x2
  void *v6; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 v9; // x8
  unsigned int v16; // w8
  unsigned int v17; // w8

  if ( !a1 )
  {
    v2 = -22;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return v2;
    StatusReg = _ReadStatusReg(SP_EL0);
    v4 = *(unsigned int *)(StatusReg + 1800);
    v5 = *(unsigned int *)(StatusReg + 1804);
    v6 = &unk_8B5B4;
LABEL_14:
    printk(v6, v4, v5, &unk_8E7CE);
    return (unsigned int)-22;
  }
  v1 = *(_QWORD *)(a1 + 56);
  if ( !v1 )
  {
    v2 = -22;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return v2;
    v7 = _ReadStatusReg(SP_EL0);
    v4 = *(unsigned int *)(v7 + 1800);
    v5 = *(unsigned int *)(v7 + 1804);
    v6 = &unk_82795;
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a1 + 48) == 2 )
  {
    if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      printk(&unk_850DD, &unk_84256, "cvp_release_dsp_buffers", *(unsigned int *)(a1 + 16));
    _X9 = (unsigned int *)(v1 + 40);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v16 = __ldxr(_X9);
      v17 = v16 - 1;
    }
    while ( __stlxr(v17, _X9) );
    __dmb(0xBu);
    if ( !v17 )
    {
      msm_cvp_smem_free(v1);
      cvp_kmem_cache_free(cvp_driver + 120, v1);
    }
    return 0;
  }
  v2 = 0;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v9 = _ReadStatusReg(SP_EL0);
    printk(&unk_88DC1, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    return 0;
  }
  return v2;
}
