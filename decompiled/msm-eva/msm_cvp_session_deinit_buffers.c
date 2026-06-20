__int64 __fastcall msm_cvp_session_deinit_buffers(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x8
  _QWORD *v4; // x1
  _QWORD *v5; // x8
  _QWORD *v6; // x21
  _QWORD *v7; // x9
  __int64 v8; // x21
  __int64 *v9; // x24
  unsigned int v10; // w20
  _QWORD *v11; // x0
  _QWORD *v12; // x8
  _QWORD *v13; // x22
  _QWORD *v14; // x9
  __int64 v15; // x0
  __int64 v16; // x21
  unsigned int v18; // w0
  const char *v19; // x1
  int v20; // w8
  int v21; // w8
  __int64 v22; // x0
  int v23; // w8
  unsigned int v29; // w9
  unsigned int v32; // w10
  __int64 *v33; // x24
  __int64 v34; // x23
  __int64 *v35; // x25
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x22
  __int64 *v39; // x28
  int v40; // w8
  __int64 **v41; // x8
  __int64 *v42; // x9
  unsigned int v45; // w10
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // [xsp+0h] [xbp-50h]
  unsigned __int64 v50; // [xsp+8h] [xbp-48h]
  __int64 v51; // [xsp+10h] [xbp-40h]
  __int64 v52; // [xsp+18h] [xbp-38h] BYREF
  __int64 v53; // [xsp+20h] [xbp-30h]
  __int64 v54; // [xsp+28h] [xbp-28h]
  __int64 v55; // [xsp+30h] [xbp-20h]
  __int64 v56; // [xsp+38h] [xbp-18h]
  __int64 v57; // [xsp+40h] [xbp-10h]
  __int64 v58; // [xsp+48h] [xbp-8h]

  v2 = (_QWORD *)(a1 + 664);
  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v3 = *(_QWORD *)(cvp_driver + 48);
  v53 = 0;
  v51 = v3;
  v52 = 0;
  mutex_lock(a1 + 680);
  v4 = *(_QWORD **)(a1 + 664);
  if ( v4 != v2 )
  {
    do
    {
      v6 = (_QWORD *)*v4;
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (_QWORD *)v6[1] == v4 )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
        v4 = v7;
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      msm_cvp_unmap_frame_buf(a1, (__int64)v4);
      v4 = v6;
    }
    while ( v6 != v2 );
  }
  mutex_unlock(a1 + 680);
  v8 = a1 + 416;
  mutex_lock(a1 + 416);
  v9 = *(__int64 **)(a1 + 400);
  if ( v9 == (__int64 *)(a1 + 400) )
  {
    v10 = 0;
LABEL_11:
    mutex_unlock(a1 + 416);
    mutex_lock(a1 + 480);
    v11 = *(_QWORD **)(a1 + 464);
    if ( v11 != (_QWORD *)(a1 + 464) )
    {
      do
      {
        v13 = (_QWORD *)*v11;
        v12 = (_QWORD *)v11[1];
        if ( (_QWORD *)*v12 == v11 && (_QWORD *)v13[1] == v11 )
        {
          v13[1] = v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v11);
          v11 = v14;
        }
        *v11 = 0xDEAD000000000100LL;
        v11[1] = 0xDEAD000000000122LL;
        kfree(v11);
        v11 = v13;
      }
      while ( v13 != (_QWORD *)(a1 + 464) );
    }
    mutex_unlock(a1 + 480);
    mutex_lock(a1 + 536);
    v15 = rb_first(a1 + 584);
    if ( !v15 || !*(_DWORD *)(a1 + 592) )
    {
LABEL_38:
      mutex_unlock(a1 + 536);
      v8 = a1 + 616;
      v33 = (__int64 *)(a1 + 600);
      mutex_lock(a1 + 616);
      if ( *(_DWORD *)(a1 + 12920) && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8DFF6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      }
      v34 = *v33;
      if ( (__int64 *)*v33 != v33 )
      {
        do
        {
          v35 = *(__int64 **)v34;
          print_internal_buffer(64, (__int64)"remove wnccbufs", a1, v34);
          v36 = *(_QWORD *)(v34 + 40);
          LODWORD(v53) = *(_DWORD *)(v34 + 16);
          HIDWORD(v55) = v36;
          mutex_unlock(a1 + 616);
          msm_cvp_unmap_buf_wncc(a1, &v52);
          mutex_lock(a1 + 616);
          v34 = (__int64)v35;
        }
        while ( v35 != v33 );
      }
      goto LABEL_77;
    }
    v16 = v15;
    _X26 = (unsigned int *)(a1 + 15412);
    v50 = _ReadStatusReg(SP_EL0);
    while ( *(_DWORD *)(v16 + 40) )
    {
      if ( (*(_BYTE *)(v16 + 89) & 1) == 0 )
      {
        v18 = 2;
        v19 = "in use";
LABEL_25:
        print_smem(v18, (__int64)v19, a1, v16);
      }
      rb_erase(v16, a1 + 584);
      v10 = msm_cvp_unmap_smem(a1, v16, (__int64)"unmap cpu cache");
      if ( v10 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_86E2C, *(unsigned int *)(v50 + 1800), *(unsigned int *)(v50 + 1804), &unk_8E7CE);
      }
      else
      {
        msm_cvp_smem_put_dma_buf(*(_QWORD *)(v16 + 48));
        v20 = *(_DWORD *)(v16 + 80);
        __asm { PRFM            #0x11, [X26] }
        do
          v29 = __ldxr(_X26);
        while ( __stxr(v29 - v20, _X26) );
        v21 = *(_DWORD *)(v16 + 80);
        _X9 = (unsigned int *)(v51 + 1304);
        __asm { PRFM            #0x11, [X9] }
        do
          v32 = __ldxr(_X9);
        while ( __stxr(v32 - v21, _X9) );
      }
      cvp_kmem_cache_free(cvp_driver + 120, v16);
      v22 = rb_first(a1 + 584);
      v23 = *(_DWORD *)(a1 + 592) - 1;
      *(_DWORD *)(a1 + 592) = v23;
      if ( v22 )
      {
        v16 = v22;
        if ( v23 )
          continue;
      }
      goto LABEL_38;
    }
    v18 = 64;
    v19 = "free";
    goto LABEL_25;
  }
  v10 = 0;
  v49 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( !v9 )
    {
      v10 = -22;
      goto LABEL_78;
    }
    v38 = v9[7];
    if ( !v38 )
      break;
    v39 = (__int64 *)*v9;
    if ( *((_DWORD *)v9 + 12) )
    {
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(
          &unk_88D96,
          &unk_84256,
          "free user persistent",
          (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      v40 = *((_DWORD *)v9 + 5);
      _X9 = (unsigned int *)(a1 + 528);
      __asm { PRFM            #0x11, [X9] }
      do
        v45 = __ldxr(_X9);
      while ( __stxr(v45 - v40, _X9) );
      if ( a1 && (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(&unk_8EC7B, &unk_84256, "FREE user persist", *((unsigned int *)v9 + 5));
      v41 = (__int64 **)v9[1];
      if ( *v41 == v9 && (v42 = (__int64 *)*v9, *(__int64 **)(*v9 + 8) == v9) )
      {
        v42[1] = (__int64)v41;
        *v41 = v42;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *v9 = 0xDEAD000000000100LL;
      v9[1] = 0xDEAD000000000122LL;
      if ( (*(_BYTE *)(v38 + 84) & 1) == 0 )
      {
        if ( *(_DWORD *)(v38 + 64) )
        {
          v10 = msm_cvp_unmap_smem(a1, v38, (__int64)"unmap persist");
          if ( v10 )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_8A06F, *(unsigned int *)(v49 + 1800), *(unsigned int *)(v49 + 1804), &unk_8E7CE);
          }
          else
          {
            msm_cvp_smem_put_dma_buf(*(_QWORD *)(v9[7] + 48));
          }
          *(_DWORD *)(v38 + 64) = 0;
        }
        cvp_kmem_cache_free(cvp_driver + 120, v38);
      }
      v37 = cvp_driver;
      v9[7] = 0;
      cvp_kmem_cache_free(v37 + 104, v9);
    }
    v9 = v39;
    if ( v39 == (__int64 *)(a1 + 400) )
      goto LABEL_11;
  }
  v10 = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v48 = _ReadStatusReg(SP_EL0);
    printk(&unk_945A1, *(unsigned int *)(v48 + 1800), *(unsigned int *)(v48 + 1804), &unk_8E7CE);
  }
LABEL_77:
  mutex_unlock(v8);
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return v10;
}
