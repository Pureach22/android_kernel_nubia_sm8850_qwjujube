__int64 __fastcall msm_cvp_session_add_smem(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 v7; // x14
  _QWORD *v8; // x10
  __int64 *v9; // x22
  __int64 v10; // x0
  __int64 v11; // x3
  unsigned int v12; // w21
  int v13; // w8
  __int64 v15; // x21
  int v17; // w8
  int v18; // w8
  int v19; // w8
  __int64 v20; // x24
  __int64 v21; // x0
  __int64 v22; // x20
  __int64 v24; // x24
  unsigned __int64 StatusReg; // x8
  int v26; // w9
  int v28; // w8
  __int64 v29; // x10
  __int64 v30; // x9
  __int64 v31; // x14
  _QWORD *v32; // x10
  __int64 v33; // x23
  int v35; // w8
  int v36; // w8
  unsigned int v39; // w10
  __int64 v40; // x26
  int v41; // w8
  int v42; // w8
  unsigned int v44; // w9
  unsigned int v47; // w9
  unsigned int v49; // w10
  unsigned int v52; // w10
  unsigned int v59; // w9
  unsigned int v61; // w10
  unsigned int v64; // w10
  unsigned int v66; // w11
  unsigned int v69; // w10
  unsigned __int64 v70; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(cvp_driver + 48);
  mutex_lock(a1 + 536);
  if ( *(_DWORD *)(a1 + 592) > 0x3Fu )
  {
    v9 = (__int64 *)(a1 + 584);
    v10 = rb_first(a1 + 584);
    if ( v10 )
    {
      v12 = 0;
      while ( v12 < *(_DWORD *)(a1 + 592) )
      {
        if ( !*(_DWORD *)(v10 + 40) )
        {
          v24 = v10;
          rb_erase(v10, a1 + 584);
          --*(_DWORD *)(a1 + 592);
          if ( (unsigned int)msm_cvp_unmap_smem(a1, v24, (__int64)"unmap cpu") )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              StatusReg = _ReadStatusReg(SP_EL0);
              printk(&unk_86E2C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            }
          }
          else
          {
            msm_cvp_smem_put_dma_buf(*(_QWORD *)(v24 + 48));
            v26 = *(_DWORD *)(v24 + 80);
            _X10 = (unsigned int *)(a1 + 15412);
            __asm { PRFM            #0x11, [X10] }
            do
              v66 = __ldxr(_X10);
            while ( __stxr(v66 - v26, _X10) );
            v28 = *(_DWORD *)(v24 + 80);
            _X9 = (unsigned int *)(v4 + 1304);
            __asm { PRFM            #0x11, [X9] }
            do
              v69 = __ldxr(_X9);
            while ( __stxr(v69 - v28, _X9) );
          }
          cvp_kmem_cache_free(cvp_driver + 120, v24);
          v29 = *v9;
          if ( *v9 )
          {
            do
            {
              v30 = v29;
              if ( *(_QWORD *)(a2 + 48) >= *(_QWORD *)(v29 + 48) )
                v31 = 8;
              else
                v31 = 16;
              v29 = *(_QWORD *)(v29 + v31);
            }
            while ( v29 );
            v32 = (_QWORD *)(v30 + v31);
          }
          else
          {
            v30 = 0;
            v32 = (_QWORD *)(a1 + 584);
          }
          v33 = *(_QWORD *)(cvp_driver + 48);
          *(_BYTE *)(a2 + 84) = 1;
          *(_QWORD *)a2 = v30;
          *(_QWORD *)(a2 + 8) = 0;
          *(_QWORD *)(a2 + 16) = 0;
          *v32 = a2;
          rb_insert_color(a2, a1 + 584);
          _X9 = (unsigned int *)(a1 + 15412);
          ++*(_DWORD *)(a1 + 592);
          v35 = *(_DWORD *)(a2 + 80);
          __asm { PRFM            #0x11, [X9] }
          do
            v61 = __ldxr(_X9);
          while ( __stxr(v61 + v35, _X9) );
          v36 = *(_DWORD *)(a2 + 80);
          _X9 = (unsigned int *)(v33 + 1304);
          __asm { PRFM            #0x11, [X9] }
          do
            v64 = __ldxr(_X9);
          while ( __stxr(v64 + v36, _X9) );
          goto LABEL_64;
        }
        v10 = ((__int64 (*)(void))rb_next)();
        ++v12;
        if ( !v10 )
          break;
      }
    }
    _X8 = (unsigned int *)(a2 + 40);
    __asm { PRFM            #0x11, [X8] }
    do
      v59 = __ldxr(_X8);
    while ( __stxr(v59 + 1, _X8) );
    v13 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8F7CF, &unk_84256, "msm_cvp_session_add_smem", v11);
      v13 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 0x40) != 0 )
      {
LABEL_17:
        if ( !v13 )
          printk(&unk_83BE3, &unk_84256, "msm_cvp_session_add_smem", *(unsigned int *)(a2 + 100));
      }
    }
    else if ( (msm_cvp_debug & 0x40) != 0 )
    {
      goto LABEL_17;
    }
    mutex_unlock(a1 + 536);
    return 4294967284LL;
  }
  v5 = *(_QWORD *)(a1 + 584);
  if ( v5 )
  {
    do
    {
      v6 = v5;
      if ( *(_QWORD *)(a2 + 48) >= *(_QWORD *)(v5 + 48) )
        v7 = 8;
      else
        v7 = 16;
      v5 = *(_QWORD *)(v5 + v7);
    }
    while ( v5 );
    v8 = (_QWORD *)(v6 + v7);
  }
  else
  {
    v6 = 0;
    v8 = (_QWORD *)(a1 + 584);
  }
  v15 = *(_QWORD *)(cvp_driver + 48);
  *(_BYTE *)(a2 + 84) = 1;
  *(_QWORD *)a2 = v6;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *v8 = a2;
  rb_insert_color(a2, a1 + 584);
  _X9 = (unsigned int *)(a1 + 15412);
  ++*(_DWORD *)(a1 + 592);
  v17 = *(_DWORD *)(a2 + 80);
  __asm { PRFM            #0x11, [X9] }
  do
    v49 = __ldxr(_X9);
  while ( __stxr(v49 + v17, _X9) );
  v18 = *(_DWORD *)(a2 + 80);
  _X9 = (unsigned int *)(v15 + 1304);
  __asm { PRFM            #0x11, [X9] }
  do
    v52 = __ldxr(_X9);
  while ( __stxr(v52 + v18, _X9) );
  v12 = 0;
LABEL_64:
  _X8 = (unsigned int *)(a2 + 40);
  __asm { PRFM            #0x11, [X8] }
  do
    v47 = __ldxr(_X8);
  while ( __stxr(v47 + 1, _X8) );
  mutex_unlock(a1 + 536);
  v19 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_88EE4, &unk_84256, "msm_cvp_session_add_smem", v12);
    v19 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 0x40) != 0 )
    {
LABEL_25:
      if ( !v19 )
        printk(&unk_83BE3, &unk_84256, "msm_cvp_session_add_smem", *(unsigned int *)(a2 + 100));
    }
  }
  else if ( (msm_cvp_debug & 0x40) != 0 )
  {
    goto LABEL_25;
  }
  if ( *(_DWORD *)(a1 + 592) == 64 )
  {
    if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      printk(&unk_97164, &unk_84256, "msm_cvp_session_add_smem", 64);
    v20 = *(_QWORD *)(cvp_driver + 48);
    mutex_lock(a1 + 536);
    v21 = rb_first(a1 + 584);
    if ( v21 )
    {
      v22 = v21;
      _X25 = (unsigned int *)(a1 + 15412);
      v70 = _ReadStatusReg(SP_EL0);
      do
      {
        v40 = rb_next(v22);
        if ( !*(_DWORD *)(v22 + 40) )
        {
          print_smem(0x40u, (__int64)"free", a1, v22);
          rb_erase(v22, a1 + 584);
          if ( (unsigned int)msm_cvp_unmap_smem(a1, v22, (__int64)"unmap cpu cache") )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_86E2C, *(unsigned int *)(v70 + 1800), *(unsigned int *)(v70 + 1804), &unk_8E7CE);
          }
          else
          {
            msm_cvp_smem_put_dma_buf(*(_QWORD *)(v22 + 48));
            v41 = *(_DWORD *)(v22 + 80);
            __asm { PRFM            #0x11, [X25] }
            do
              v44 = __ldxr(_X25);
            while ( __stxr(v44 - v41, _X25) );
            v42 = *(_DWORD *)(v22 + 80);
            _X9 = (unsigned int *)(v20 + 1304);
            __asm { PRFM            #0x11, [X9] }
            do
              v39 = __ldxr(_X9);
            while ( __stxr(v39 - v42, _X9) );
          }
          cvp_kmem_cache_free(cvp_driver + 120, v22);
          --*(_DWORD *)(a1 + 592);
        }
        v22 = v40;
      }
      while ( v40 );
    }
    mutex_unlock(a1 + 536);
  }
  return 0;
}
