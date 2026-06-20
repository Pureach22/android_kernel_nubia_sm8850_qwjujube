__int64 __fastcall msm_cvp_map_user_persist(_QWORD *a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  __int64 result; // x0
  unsigned int v7; // w5
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  _QWORD *v12; // x23
  __int64 v13; // x25
  int v14; // w22
  __int64 v15; // x22
  __int64 v16; // x20
  unsigned __int64 v17; // x27
  int *v18; // x28
  unsigned int v19; // w25
  unsigned __int64 dma_buf; // x0
  unsigned __int64 v21; // x24
  _QWORD *v22; // x8
  _QWORD *v23; // x26
  __int64 v24; // x9
  int v25; // w8
  unsigned int v26; // w8
  __int64 v27; // x9
  int v28; // w22
  __int64 v29; // x0
  __int64 v30; // x24
  _DWORD *smem; // x0
  int v32; // w8
  _DWORD *v33; // x26
  int v34; // w8
  int v35; // w8
  __int64 *v36; // x1
  unsigned int v43; // w10
  unsigned int v46; // w10
  unsigned int v49; // w9
  unsigned int v52; // w10
  const char *feature_name_from_type; // x20
  size_t v54; // x0
  unsigned __int64 v55; // x2
  int v56; // w8
  int v57; // w9
  int v58; // w10
  _QWORD *v59; // x20
  _QWORD *v60; // x21
  __int64 v61; // x8
  __int64 v62; // x10
  _QWORD *v63; // x1
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x8
  unsigned int v66; // w19
  unsigned __int64 v67; // x8
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x8
  int v72; // [xsp+4h] [xbp-2Ch]
  __int64 v73; // [xsp+8h] [xbp-28h]
  __int64 v74; // [xsp+10h] [xbp-20h] BYREF
  __int64 v75; // [xsp+18h] [xbp-18h]
  __int64 v76; // [xsp+20h] [xbp-10h]
  __int64 v77; // [xsp+28h] [xbp-8h]

  result = 0;
  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 || !a4 )
    goto LABEL_76;
  v7 = a3;
  v75 = 0;
  v76 = 0;
  v74 = 0;
  if ( a3 <= 0xF )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_894FC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
    goto LABEL_76;
  }
  v9 = a1[16];
LABEL_85:
  _X9 = (unsigned __int64 *)(v9 + 1296);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v70 = __ldxr(_X9);
    v71 = v70 + 1;
  }
  while ( __stlxr(v71, _X9) );
  __dmb(0xBu);
  v16 = 0;
  v12 = a1 + 50;
  v17 = v7;
  v15 = a4;
  *(_QWORD *)(a2 + 32) = v71 & 0x7FFFFFFFFFFFFFFFLL;
  v73 = a5;
  while ( 1 )
  {
    if ( v17 >= 0x259 )
    {
      __break(0x5512u);
      goto LABEL_83;
    }
    v18 = (int *)(a2 + 4 * v17);
    if ( v18[1] )
      break;
LABEL_11:
    ++v16;
    v17 += 12LL;
    if ( v16 == v15 )
    {
      print_persist_buffer_info(64, (__int64)"MAP user persist", 0, (__int64)a1, a2);
      feature_name_from_type = (const char *)get_feature_name_from_type(*(unsigned int *)(a2 + 64));
      v54 = strnlen(feature_name_from_type, 0x14u);
      if ( v54 != -1 )
      {
        if ( v54 == 20 )
          v55 = 20;
        else
          v55 = v54 + 1;
        if ( v55 < 0x15 )
        {
          sized_strscpy(&v74, feature_name_from_type);
          v56 = *(_DWORD *)(a2 + 72);
          v57 = *(_DWORD *)(a2 + 120);
          v58 = *(_DWORD *)(a2 + 168);
          BYTE3(v76) = 0;
          HIDWORD(v76) = v57 + v56 + v58;
          v59 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3264, 88);
          if ( v59 )
          {
            v60 = a1 + 58;
            mutex_lock(a1 + 60);
            v61 = v76;
            v62 = v74;
            v63 = (_QWORD *)a1[59];
            v59[9] = v75;
            v59[10] = v61;
            v59[8] = v62;
            if ( v59 == a1 + 58 || v63 == v59 || (_QWORD *)*v63 != v60 )
            {
              _list_add_valid_or_report(v59, v63, a1 + 58);
            }
            else
            {
              a1[59] = v59;
              *v59 = v60;
              v59[1] = v63;
              *v63 = v59;
            }
            mutex_unlock(a1 + 60);
          }
          result = 0;
          goto LABEL_76;
        }
LABEL_84:
        _fortify_panic(7);
        goto LABEL_85;
      }
LABEL_83:
      _fortify_panic(2);
      goto LABEL_84;
    }
  }
  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_73;
    v64 = _ReadStatusReg(SP_EL0);
    printk(&unk_912BD, *(unsigned int *)(v64 + 1800), *(unsigned int *)(v64 + 1804), &unk_8E7CE);
    goto LABEL_72;
  }
  v19 = *(_DWORD *)(a2 + 4);
  dma_buf = msm_cvp_smem_get_dma_buf();
  if ( !dma_buf )
  {
LABEL_72:
    result = 4294967274LL;
    goto LABEL_73;
  }
  v21 = dma_buf;
  mutex_lock(a1 + 52);
  v22 = (_QWORD *)*v12;
  if ( !*v12 )
  {
    mutex_unlock(a1 + 52);
    goto LABEL_72;
  }
  while ( v22 != v12 )
  {
    v23 = v22;
    if ( !v22 )
      goto LABEL_72;
    v24 = *(_QWORD *)(v22[7] + 48LL);
    v22 = (_QWORD *)*v22;
    if ( v21 == v24 )
    {
      v25 = *((_DWORD *)v23 + 5);
      _X9 = (unsigned int *)(a1 + 66);
      __asm { PRFM            #0x11, [X9] }
      do
        v43 = __ldxr(_X9);
      while ( __stxr(v43 - v25, _X9) );
      v13 = v15;
      v26 = *((_DWORD *)v23 + 5);
      if ( v26 <= v18[1] )
        v26 = v18[1];
      v27 = v23[7];
      *((_DWORD *)v23 + 5) = v26;
      v28 = v18[2];
      v72 = *(_DWORD *)(v27 + 64);
      _X9 = (unsigned int *)(a1 + 66);
      __asm { PRFM            #0x11, [X9] }
      do
        v46 = __ldxr(_X9);
      while ( __stxr(v46 + v26, _X9) );
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(&unk_8EC7B, &unk_84256, "MAP user persist", *((unsigned int *)v23 + 5));
      mutex_unlock(a1 + 52);
      _X8 = (unsigned int *)(v23[7] + 40LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v49 = __ldxr(_X8);
      while ( __stxr(v49 + 1, _X8) );
      v14 = v28 + v72;
      dma_buf_put(v21);
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(&unk_89715, &unk_84256, *((unsigned int *)v23 + 4), *(_QWORD *)(v23[7] + 48LL));
LABEL_10:
      a5 = v73;
      *(_DWORD *)(v73 + 4 * v16) = *v18;
      *v18 = v14;
      v15 = v13;
      goto LABEL_11;
    }
  }
  mutex_unlock(a1 + 52);
  dma_buf_put(v21);
  v29 = cvp_kmem_cache_zalloc(cvp_driver + 104, 3264);
  if ( v29 )
  {
    v30 = v29;
    smem = (_DWORD *)msm_cvp_session_get_smem(a1, a2 + 4 * v17, 1, v19);
    if ( smem )
    {
      v32 = smem[22];
      v33 = smem;
      switch ( v32 )
      {
        case 68:
          v34 = 7;
          break;
        case 36:
          v34 = 3;
          break;
        case 20:
          v34 = 4;
          break;
        default:
          v34 = 0;
          break;
      }
      v18[11] = v34;
      smem[23] = v19;
      smem[24] = v16;
      smem[25] = *v18;
      *(_QWORD *)(v30 + 56) = smem;
      *(_DWORD *)(v30 + 16) = *v18;
      v35 = v18[1];
      *(_DWORD *)(v30 + 20) = v35;
      *(_DWORD *)(v30 + 24) = v18[2];
      *(_DWORD *)(v30 + 48) = 1;
      _X9 = (unsigned int *)(a1 + 66);
      __asm { PRFM            #0x11, [X9] }
      do
        v52 = __ldxr(_X9);
      while ( __stxr(v52 + v35, _X9) );
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(&unk_8EC7B, &unk_84256, "MAP user persist", *(unsigned int *)(v30 + 20));
      mutex_lock(a1 + 52);
      v36 = (__int64 *)a1[51];
      if ( (_QWORD *)v30 == v12 || v36 == (__int64 *)v30 || (_QWORD *)*v36 != v12 )
      {
        v13 = v15;
        _list_add_valid_or_report(v30, v36, a1 + 50);
      }
      else
      {
        v13 = v15;
        a1[51] = v30;
        *(_QWORD *)v30 = v12;
        *(_QWORD *)(v30 + 8) = v36;
        *v36 = v30;
      }
      mutex_unlock(a1 + 52);
      print_internal_buffer(64, (__int64)"map persist", (__int64)a1, v30);
      v14 = v18[2] + v33[16];
      goto LABEL_10;
    }
    cvp_kmem_cache_free(cvp_driver + 104, v30);
LABEL_81:
    result = 4294967284LL;
  }
  else
  {
    result = 4294967284LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v67 = _ReadStatusReg(SP_EL0);
      printk(&unk_8F76B, *(unsigned int *)(v67 + 1800), *(unsigned int *)(v67 + 1804), &unk_8E7CE);
      goto LABEL_81;
    }
  }
LABEL_73:
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v65 = _ReadStatusReg(SP_EL0);
    v66 = result;
    printk(&unk_8D274, *(unsigned int *)(v65 + 1800), *(unsigned int *)(v65 + 1804), &unk_8E7CE);
    result = v66;
  }
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
