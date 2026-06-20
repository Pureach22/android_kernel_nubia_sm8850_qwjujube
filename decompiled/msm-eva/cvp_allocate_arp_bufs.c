__int64 __fastcall cvp_allocate_arp_bufs(_QWORD *a1, unsigned int a2)
{
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x1
  __int64 v8; // x2
  void *v9; // x0
  unsigned __int64 v10; // x8
  int v12; // w8
  _QWORD *v13; // x21
  _QWORD *v14; // x22
  __int64 v15; // x8
  __int64 v16; // x10
  _QWORD *v17; // x1
  _QWORD *v18; // x21
  __int64 *v19; // x1
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned int v28; // w9
  unsigned int v31; // w10
  __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  __int64 v33; // [xsp+8h] [xbp-18h]
  __int64 v34; // [xsp+10h] [xbp-10h]
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v32 = 0;
  if ( !a1 )
  {
    v4 = 0;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_22;
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = *(unsigned int *)(StatusReg + 1800);
    v8 = *(unsigned int *)(StatusReg + 1804);
    v9 = &unk_95BCB;
    goto LABEL_16;
  }
  if ( !a2 )
  {
LABEL_21:
    v4 = 0;
    goto LABEL_22;
  }
  v4 = cvp_kmem_cache_zalloc(cvp_driver + 104, 3264);
  if ( !v4 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_22;
    v10 = _ReadStatusReg(SP_EL0);
    v7 = *(unsigned int *)(v10 + 1800);
    v8 = *(unsigned int *)(v10 + 1804);
    v9 = &unk_8D304;
LABEL_16:
    printk(v9, v7, v8, &unk_8E7CE);
    goto LABEL_21;
  }
  v5 = cvp_kmem_cache_zalloc(cvp_driver + 120, 3264);
  *(_QWORD *)(v4 + 56) = v5;
  if ( !v5 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D304, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
    }
    goto LABEL_20;
  }
  *(_DWORD *)(v5 + 88) = 1;
  if ( (unsigned int)msm_cvp_smem_alloc(a2, 1, 0, a1[16] + 608LL, *(_QWORD *)(v4 + 56), 0) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v20 = _ReadStatusReg(SP_EL0);
      printk(&unk_8B57D, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
    }
    cvp_kmem_cache_free(cvp_driver + 120, *(_QWORD *)(v4 + 56));
LABEL_20:
    cvp_kmem_cache_free(cvp_driver + 104, v4);
    goto LABEL_21;
  }
  *(_DWORD *)(*(_QWORD *)(v4 + 56) + 96LL) = 0;
  *(_DWORD *)(*(_QWORD *)(v4 + 56) + 92LL) = 0;
  _X8 = (unsigned int *)(*(_QWORD *)(v4 + 56) + 40LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 + 1, _X8) );
  v12 = *(_DWORD *)(*(_QWORD *)(v4 + 56) + 80LL);
  *(_DWORD *)(v4 + 28) = 5;
  *(_DWORD *)(v4 + 48) = 0;
  *(_DWORD *)(v4 + 20) = v12;
  _X9 = (unsigned int *)(a1 + 66);
  __asm { PRFM            #0x11, [X9] }
  do
    v31 = __ldxr(_X9);
  while ( __stxr(v31 + v12, _X9) );
  sized_strscpy(&v32, "Internal Scratch Buffer");
  HIDWORD(v34) = *(_DWORD *)(v4 + 20);
  v13 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3264, 88);
  if ( v13 )
  {
    v14 = a1 + 58;
    mutex_lock(a1 + 60);
    v15 = v34;
    v16 = v32;
    v17 = (_QWORD *)a1[59];
    v13[9] = v33;
    v13[10] = v15;
    v13[8] = v16;
    if ( v13 == a1 + 58 || v17 == v13 || (_QWORD *)*v17 != v14 )
    {
      _list_add_valid_or_report(v13, v17, a1 + 58);
    }
    else
    {
      a1[59] = v13;
      *v13 = v14;
      v13[1] = v17;
      *v17 = v13;
    }
    mutex_unlock(a1 + 60);
  }
  v18 = a1 + 50;
  if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
    printk(&unk_8EC7B, &unk_84256, "MAP ARP buffer", *(unsigned int *)(v4 + 20));
  mutex_lock(a1 + 52);
  v19 = (__int64 *)a1[51];
  if ( (_QWORD *)v4 == v18 || v19 == (__int64 *)v4 || (_QWORD *)*v19 != v18 )
  {
    _list_add_valid_or_report(v4, v19, a1 + 50);
  }
  else
  {
    a1[51] = v4;
    *(_QWORD *)v4 = v18;
    *(_QWORD *)(v4 + 8) = v19;
    *v19 = v4;
  }
  mutex_unlock(a1 + 52);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v4;
}
