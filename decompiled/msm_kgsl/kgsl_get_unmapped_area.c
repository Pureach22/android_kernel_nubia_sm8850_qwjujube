unsigned __int64 __fastcall kgsl_get_unmapped_area(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v6; // x8
  __int64 v7; // x23
  _QWORD *v8; // x26
  unsigned __int64 result; // x0
  unsigned __int64 v15; // x24
  __int64 v16; // x7
  __int64 v17; // x8
  __int64 v18; // x2
  unsigned __int64 v19; // x20
  __int64 v20; // x7
  __int64 v21; // x8
  __int64 v22; // x2
  int v24; // w8
  int v30; // w8
  _QWORD v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a1 + 32);
  v31[0] = 0;
  v8 = (_QWORD *)*v6;
  v7 = v6[1];
  if ( (a4 & 0xFFFFFFFFFFFFFLL) == 0xEFFFF )
  {
    result = _get_unmapped_area(0, a2, a3, a4, a5, 0);
    goto LABEL_5;
  }
  LODWORD(result) = get_mmap_entry(v6[1], v31);
  if ( (_DWORD)result )
  {
    result = (int)result;
    goto LABEL_5;
  }
  _X19 = (unsigned int *)v31[0];
  if ( v31[0] == -8 )
    goto LABEL_9;
  if ( (*(_DWORD *)(v31[0] + 56LL) & 0x10) != 0 )
  {
    result = -1;
    if ( v31[0] && v31[0] <= 0xFFFFFFFFFFFFF000LL )
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v30 = __ldxr(_X19);
      while ( __stlxr(v30 - 1, _X19) );
      if ( v30 == 1 )
      {
        __dmb(9u);
        kgsl_mem_entry_destroy(_X19);
        result = -1;
      }
      else
      {
        if ( v30 <= 0 )
          refcount_warn_saturate(_X19, 3);
        result = -1;
      }
    }
    goto LABEL_5;
  }
  if ( (*(_BYTE *)(v31[0] + 83LL) & 0x10) == 0 )
  {
LABEL_9:
    result = mm_get_unmapped_area(*(_QWORD *)(_ReadStatusReg(SP_EL0) + 1672), a1, a2, a3, 0, a5);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      v15 = result;
      if ( (unsigned int)__ratelimit(&kgsl_get_unmapped_area__rs, "kgsl_get_unmapped_area") )
      {
        v17 = *(_QWORD *)(v7 + 8);
        if ( v17 )
          v18 = *(unsigned int *)(v17 + 112);
        else
          v18 = 0;
        dev_err(
          *v8,
          "get_unmapped_area: pid %d addr %lx pgoff %lx len %ld failed error %d\n",
          v18,
          a2,
          a4,
          a3,
          (unsigned int)v15,
          v16);
      }
      goto LABEL_32;
    }
LABEL_20:
    if ( !_X19 )
      goto LABEL_5;
    goto LABEL_21;
  }
  result = get_svm_unmapped_area(a1, v31[0], a2, a3, a5);
  if ( result == -12 )
  {
    _flush_workqueue(qword_3A908);
    result = get_svm_unmapped_area(a1, _X19, a2, a3, a5);
  }
  if ( result < 0xFFFFFFFFFFFFF001LL )
    goto LABEL_20;
  v15 = result;
  if ( (unsigned int)__ratelimit(&kgsl_get_unmapped_area__rs_100, "kgsl_get_unmapped_area") )
  {
    v21 = *(_QWORD *)(v7 + 8);
    if ( v21 )
      v22 = *(unsigned int *)(v21 + 112);
    else
      v22 = 0;
    dev_err(
      *v8,
      "_get_svm_area: pid %d addr %lx pgoff %lx len %ld failed error %d\n",
      v22,
      a2,
      a4,
      a3,
      (unsigned int)v15,
      v20);
  }
LABEL_32:
  result = v15;
  if ( !_X19 )
    goto LABEL_5;
LABEL_21:
  if ( (unsigned __int64)_X19 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v24 = __ldxr(_X19);
    while ( __stlxr(v24 - 1, _X19) );
    if ( v24 == 1 )
    {
      __dmb(9u);
      v19 = result;
      kgsl_mem_entry_destroy(_X19);
    }
    else
    {
      if ( v24 > 0 )
        goto LABEL_5;
      v19 = result;
      refcount_warn_saturate(_X19, 3);
    }
    result = v19;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
