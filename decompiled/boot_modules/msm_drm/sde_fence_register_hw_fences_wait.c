__int64 __fastcall sde_fence_register_hw_fences_wait(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 v6; // x8
  __int64 v7; // x27
  __int64 v8; // x28
  int v10; // w8
  const char *v11; // x6
  unsigned int *v12; // x23
  int v13; // w27
  int v14; // w22
  int v15; // w24
  __int64 v16; // x8
  int v18; // w19
  __int64 v19; // x8
  __int64 v20; // x1
  unsigned int v26; // w8
  __int64 v27; // x22
  size_t v28; // x0
  unsigned __int64 v29; // x21
  unsigned __int64 v30; // x25
  unsigned __int64 v31; // x6
  __int64 (__fastcall *v32)(__int64, __int64 *, __int64, __int64, __int64, __int64, unsigned __int64); // x8
  __int64 v33; // x27
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x25
  int v37; // w8
  int v38; // w24
  int v39; // w21
  __int64 v40; // x27
  __int64 v41; // x22
  size_t v42; // x0
  __int64 (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // x19
  signed int v45; // w26
  __int64 v46; // x8
  int v47; // w8
  __int64 v48; // x10
  unsigned int v49; // w22
  __int64 v50; // x1
  unsigned int v52; // w8
  _QWORD *v53; // x28
  size_t v54; // x0
  __int64 v55; // x26
  __int64 (__fastcall *v56)(_QWORD); // x8
  __int64 v57; // x8
  int v59; // w8
  unsigned int v60; // w26
  __int64 v61; // x2
  __int64 v62; // x0
  unsigned __int64 v63; // x21
  __int64 v64; // x25
  size_t v65; // x0
  unsigned __int64 v66; // x6
  __int64 (__fastcall *v67)(_QWORD); // x8
  __int64 v68; // x19
  __int64 v69; // x21
  __int64 v70; // x0
  int v71; // w0
  void *v72; // x0
  int v73; // w21
  __int64 v74; // x8
  int v77; // w8
  int v79; // w8
  int v80; // w21
  __int64 v81; // x8
  int v84; // w8
  char v87; // [xsp+0h] [xbp-80h]
  int v88[2]; // [xsp+30h] [xbp-50h]
  __int64 v89; // [xsp+38h] [xbp-48h]
  __int64 v90; // [xsp+38h] [xbp-48h]
  int v91; // [xsp+40h] [xbp-40h]
  unsigned int v92; // [xsp+44h] [xbp-3Ch] BYREF
  __int64 v93; // [xsp+48h] [xbp-38h] BYREF
  unsigned int *v94; // [xsp+50h] [xbp-30h]
  __int64 v95; // [xsp+58h] [xbp-28h]
  __int64 v96; // [xsp+60h] [xbp-20h]
  __int64 v97; // [xsp+68h] [xbp-18h]
  __int64 v98; // [xsp+70h] [xbp-10h]
  __int64 v99; // [xsp+78h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = nullptr;
  v92 = 0;
  if ( !a1 )
  {
    printk(&unk_232975, "sde_fence_register_hw_fences_wait");
    LODWORD(v12) = -22;
    goto LABEL_148;
  }
  v6 = *(_QWORD *)(a1 + 168);
  v7 = a1;
  v91 = *(_DWORD *)(a1 + 64) - 1;
  if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_247027, "sde_fence_register_hw_fences_wait");
    LODWORD(v12) = -22;
    goto LABEL_148;
  }
  LODWORD(v8) = a3;
  if ( (_drm_debug & 4) != 0 )
  {
    v10 = *(_DWORD *)(a1 + 164);
    if ( v10 <= 1217 )
    {
      switch ( v10 )
      {
        case 1024:
          v11 = "SYNX_CLIENT_HW_FENCE_GFX_CTX0";
          goto LABEL_22;
        case 1216:
          v11 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL0";
          goto LABEL_22;
        case 1217:
          v11 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL1";
LABEL_22:
          _drm_dev_dbg(0, 0, 0, "register for wait fences:%d ctl_id:%d hw_fence_client:%s\n", a3, v91, v11);
          goto LABEL_23;
      }
    }
    else
    {
      if ( v10 <= 1219 )
      {
        if ( v10 == 1218 )
          v11 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL2";
        else
          v11 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL3";
        goto LABEL_22;
      }
      if ( v10 == 1220 )
      {
        v11 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL4";
        goto LABEL_22;
      }
      if ( v10 == 1221 )
      {
        v11 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL5";
        goto LABEL_22;
      }
    }
    v11 = "Unknown";
    goto LABEL_22;
  }
LABEL_23:
  if ( !(_DWORD)v8 )
  {
LABEL_40:
    v27 = *a2;
    v28 = sde_dbg_base_evtlog;
    v29 = *(_QWORD *)(*a2 + 32);
    v30 = *(_QWORD *)(*a2 + 40);
    v31 = HIDWORD(v29);
    if ( (*(_QWORD *)(*a2 + 48) & 1) != 0 )
    {
      v34 = HIDWORD(v30);
    }
    else
    {
      v32 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64, __int64, __int64, __int64, unsigned __int64))(*(_QWORD *)(*a2 + 8) + 32LL);
      if ( v32 )
      {
        v90 = v7;
        v33 = sde_dbg_base_evtlog;
        if ( *((_DWORD *)v32 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v32(v27, a2, a3, a4, a5, a6, v31) & 1) != 0 )
          dma_fence_signal(v27);
        v28 = v33;
        v7 = v90;
        LODWORD(v31) = HIDWORD(v29);
        v34 = HIDWORD(v30);
      }
      else
      {
        v34 = HIDWORD(v30);
      }
    }
    sde_evtlog_log(v28, "sde_fence_register_hw_fences_wait", 486, -1, v91, v8, v31, v29, v34);
    v64 = *a2;
    v69 = 0;
LABEL_105:
    v70 = *(_QWORD *)(v7 + 168);
    LODWORD(v93) = 1;
    v96 = v64;
    v94 = &v92;
    LODWORD(v95) = 8;
    v71 = synx_import(v70, &v93);
    if ( v71 )
    {
      LODWORD(v12) = v71;
      v72 = &unk_27B0CF;
    }
    else
    {
      LODWORD(v12) = synx_release(*(_QWORD *)(v7 + 168), v92);
      if ( !(_DWORD)v12 )
      {
        if ( v69 )
        {
LABEL_108:
          _X0 = (unsigned int *)(v69 + 56);
LABEL_128:
          __asm { PRFM            #0x11, [X0] }
          do
            v79 = __ldxr(_X0);
          while ( __stlxr(v79 - 1, _X0) );
          if ( v79 != 1 )
            goto LABEL_145;
          goto LABEL_115;
        }
LABEL_113:
        if ( !*a2 )
        {
LABEL_147:
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_fence_register_hw_fences_wait",
            511,
            4,
            v91,
            v8,
            (int)v12,
            -1059143953,
            v87);
          goto LABEL_148;
        }
        _X0 = (unsigned int *)(*a2 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v79 = __ldxr(_X0);
        while ( __stlxr(v79 - 1, _X0) );
        if ( v79 != 1 )
        {
LABEL_145:
          if ( v79 <= 0 )
            refcount_warn_saturate(_X0, 3);
          goto LABEL_147;
        }
LABEL_115:
        __dmb(9u);
        dma_fence_release(_X0);
        goto LABEL_147;
      }
      v72 = &unk_228606;
    }
    printk(v72, "sde_fence_register_hw_fences_wait");
    if ( v69 )
      goto LABEL_108;
    goto LABEL_113;
  }
  v89 = v7;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  do
  {
    v16 = a2[v13];
    if ( !v16 )
      goto LABEL_29;
    _X0 = (unsigned int *)(v16 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v26 = __ldxr(_X0);
    while ( __stxr(v26 + 1, _X0) );
    if ( v26 )
    {
      if ( (((v26 + 1) | v26) & 0x80000000) == 0 )
        goto LABEL_29;
      v20 = 1;
    }
    else
    {
      v20 = 2;
    }
    refcount_warn_saturate(_X0, v20);
LABEL_29:
    v18 = v13;
    v19 = a2[v13];
    if ( *(_UNKNOWN **)(v19 + 8) == &dma_fence_array_ops )
    {
      ++v15;
      v14 += *(_DWORD *)(v19 + 68);
      if ( (_drm_debug & 4) == 0 )
        goto LABEL_25;
    }
    else if ( (_drm_debug & 4) == 0 )
    {
      goto LABEL_25;
    }
    _drm_dev_dbg(0, 0, 0, "registering fence: ctx:%llu seqno:%llu\n", *(_QWORD *)(v19 + 32), *(_QWORD *)(v19 + 40));
LABEL_25:
    ++v13;
  }
  while ( (_DWORD)v8 != v18 + 1 );
  v7 = v89;
  if ( (_DWORD)v8 == 1 )
    goto LABEL_40;
  v35 = 8LL * (unsigned int)(v8 - v15 + v14);
  _X0 = (unsigned int *)_kmalloc_noprof(v35, 3520);
  v12 = _X0;
  if ( !_X0 )
  {
    v80 = 0;
    do
    {
      v81 = a2[v80];
      if ( v81 )
      {
        _X0 = (unsigned int *)(v81 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v84 = __ldxr(_X0);
        while ( __stlxr(v84 - 1, _X0) );
        if ( v84 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
        }
        else if ( v84 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      ++v80;
    }
    while ( (_DWORD)v8 != v80 );
    LODWORD(v12) = -22;
    goto LABEL_148;
  }
  v37 = 0;
  v38 = 0;
  while ( 2 )
  {
    v39 = v8;
    v8 = a2[v37];
    v40 = v37;
    if ( *(_UNKNOWN **)(v8 + 8) != &dma_fence_array_ops )
    {
      if ( v35 > 8LL * v38 )
      {
        *(_QWORD *)&v12[2 * v38] = v8;
        v41 = *(_QWORD *)(v8 + 32);
        v42 = sde_dbg_base_evtlog;
        if ( (*(_QWORD *)(v8 + 48) & 1) == 0 )
        {
          v43 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v8 + 8) + 32LL);
          if ( v43 )
          {
            v44 = sde_dbg_base_evtlog;
            if ( *((_DWORD *)v43 - 1) != 1879296680 )
              __break(0x8228u);
            if ( (v43(v8) & 1) != 0 )
              dma_fence_signal(v8);
            v42 = v44;
          }
        }
        ++v38;
        LODWORD(v8) = v39;
        _X0 = (unsigned int *)sde_evtlog_log(
                                v42,
                                "sde_fence_register_hw_fences_wait",
                                458,
                                -1,
                                v91,
                                v39,
                                v40,
                                SHIDWORD(v41),
                                v41);
        goto LABEL_50;
      }
LABEL_127:
      __break(1u);
      goto LABEL_128;
    }
    if ( !*(_DWORD *)(v8 + 68) )
      goto LABEL_80;
    v45 = 0;
    while ( 2 )
    {
      v46 = *(_QWORD *)(*(_QWORD *)(v8 + 80) + 8LL * v45);
      if ( v46 )
      {
        _X0 = (unsigned int *)(v46 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v52 = __ldxr(_X0);
        while ( __stxr(v52 + 1, _X0) );
        if ( v52 )
        {
          if ( (((v52 + 1) | v52) & 0x80000000) != 0 )
          {
            v50 = 1;
            goto LABEL_71;
          }
        }
        else
        {
          v50 = 2;
LABEL_71:
          _X0 = (unsigned int *)refcount_warn_saturate(_X0, v50);
        }
      }
      v47 = v38 + v45;
      if ( v35 <= 8LL * (v38 + v45) )
        goto LABEL_127;
      v48 = *(_QWORD *)(*(_QWORD *)(v8 + 80) + 8LL * v45++);
      *(_QWORD *)&v12[2 * v47] = v48;
      v49 = *(_DWORD *)(v8 + 68);
      if ( v45 < v49 )
        continue;
      break;
    }
    v38 += v45;
    if ( !v49 )
    {
LABEL_80:
      LODWORD(v8) = v39;
      _X0 = (unsigned int *)sde_evtlog_log(
                              sde_dbg_base_evtlog,
                              "sde_fence_register_hw_fences_wait",
                              447,
                              -1,
                              v91,
                              v39,
                              0,
                              v40,
                              173);
      v57 = a2[v40];
      if ( v57 )
        goto LABEL_85;
      goto LABEL_50;
    }
    v53 = **(_QWORD ***)(v8 + 80);
    v54 = sde_dbg_base_evtlog;
    v55 = v53[4];
    if ( (v53[6] & 1) == 0 )
    {
      v56 = *(__int64 (__fastcall **)(_QWORD))(v53[1] + 32LL);
      if ( v56 )
      {
        *(_QWORD *)v88 = sde_dbg_base_evtlog;
        if ( *((_DWORD *)v56 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v56(v53) & 1) != 0 )
          dma_fence_signal(v53);
        v54 = *(_QWORD *)v88;
      }
    }
    LODWORD(v8) = v39;
    _X0 = (unsigned int *)sde_evtlog_log(
                            v54,
                            "sde_fence_register_hw_fences_wait",
                            444,
                            -1,
                            v91,
                            v39,
                            v49,
                            v40,
                            SBYTE4(v55));
    v57 = a2[v40];
    if ( v57 )
    {
LABEL_85:
      _X0 = (unsigned int *)(v57 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v59 = __ldxr(_X0);
      while ( __stlxr(v59 - 1, _X0) );
      if ( v59 == 1 )
      {
        __dmb(9u);
        _X0 = (unsigned int *)dma_fence_release(_X0);
      }
      else if ( v59 <= 0 )
      {
        _X0 = (unsigned int *)refcount_warn_saturate(_X0, 3);
      }
    }
LABEL_50:
    v37 = v40 + 1;
    if ( (_DWORD)v40 + 1 != (_DWORD)v8 )
      continue;
    break;
  }
  v7 = v89;
  v60 = *(_DWORD *)(v89 + 280);
  v61 = *(_QWORD *)(v89 + 272);
  *(_DWORD *)(v89 + 280) = v60 + 1;
  v62 = dma_fence_array_create((unsigned int)v38, v12, v61, v60, 0);
  if ( v62 )
  {
    v63 = *(_QWORD *)(v89 + 272);
    v64 = v62;
    v65 = sde_dbg_base_evtlog;
    v66 = HIDWORD(v63);
    if ( (*(_QWORD *)(v64 + 48) & 1) == 0 )
    {
      v67 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v64 + 8) + 32LL);
      if ( v67 )
      {
        v68 = sde_dbg_base_evtlog;
        if ( *((_DWORD *)v67 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v67(v64) & 1) != 0 )
          dma_fence_signal(v64);
        LODWORD(v66) = HIDWORD(v63);
        v65 = v68;
      }
    }
    sde_evtlog_log(v65, "sde_fence_register_hw_fences_wait", 473, -1, v91, v38, v66, v63, 0);
    v69 = v64;
    goto LABEL_105;
  }
  printk(&unk_213730, "sde_fence_register_hw_fences_wait");
  v73 = 0;
  do
  {
    v74 = a2[v73];
    if ( v74 )
    {
      _X0 = (unsigned int *)(v74 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v77 = __ldxr(_X0);
      while ( __stlxr(v77 - 1, _X0) );
      if ( v77 == 1 )
      {
        __dmb(9u);
        dma_fence_release(_X0);
      }
      else if ( v77 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    ++v73;
  }
  while ( (_DWORD)v8 != v73 );
  kfree(v12);
  LODWORD(v12) = -22;
LABEL_148:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v12;
}
