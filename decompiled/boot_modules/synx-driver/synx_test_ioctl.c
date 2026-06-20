__int64 __fastcall synx_test_ioctl(__int64 a1, int a2, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x28
  _QWORD *v7; // x26
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 result; // x0
  unsigned __int64 v11; // x21
  unsigned __int64 v12; // x23
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x19
  unsigned __int64 v15; // x22
  size_t v16; // x20
  int v17; // w22
  __int64 v18; // x5
  void *v19; // x0
  const char *v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  unsigned __int64 v23; // x0
  __int64 v24; // x4
  size_t v25; // x20
  int v26; // w21
  __int64 v27; // x4
  unsigned __int64 v28; // x0
  __int64 v29; // x4
  unsigned __int64 v30; // x19
  int v31; // w21
  __int64 v32; // x20
  __int64 (__fastcall *v33)(_QWORD); // x8
  void *v34; // x0
  const char *v35; // x2
  __int64 v36; // x3
  unsigned __int64 v37; // x0
  unsigned __int64 v38; // x20
  int v39; // w24
  unsigned __int64 v40; // x25
  unsigned int v41; // w0
  unsigned __int64 v42; // x8
  __int64 v43; // x8
  int v50; // w8
  unsigned __int64 v52; // x0
  __int64 v53; // x4
  unsigned int v54; // w8
  unsigned __int64 v55; // x24
  unsigned __int64 fence; // x0
  __int64 v57; // x5
  char v58; // w8
  unsigned int v59; // w0
  __int64 v60; // x22
  __int64 v61; // x23
  __int64 v62; // x22
  __int64 v63; // x23
  unsigned __int64 v64; // x0
  unsigned int v65; // w8
  __int64 v67; // t1
  unsigned __int64 v68; // x24
  unsigned __int64 v69; // x0
  __int64 v70; // x25
  int v71; // w26
  unsigned __int64 v72; // x0
  __int64 v73; // x1
  unsigned int v74; // w0
  __int64 v75; // x22
  unsigned int sync_fd; // w0
  __int64 v77; // x23
  int v78; // w8
  int v79; // w25
  __int64 v80; // x8
  int v83; // w8
  int v84; // w8
  __int64 v85; // x26
  __int64 (__fastcall *v86)(_QWORD); // x8
  int v89; // w8
  int v91; // w8
  int v93; // w8
  void *v94; // x0
  const char *v95; // x2
  __int64 v96; // x3
  _QWORD v97[2]; // [xsp+0h] [xbp-50h] BYREF
  int v98[2]; // [xsp+10h] [xbp-40h]
  unsigned __int64 v99; // [xsp+18h] [xbp-38h] BYREF
  unsigned __int64 v100; // [xsp+20h] [xbp-30h]
  __int64 v101; // [xsp+28h] [xbp-28h]
  __int64 v102; // [xsp+30h] [xbp-20h] BYREF
  __int64 v103; // [xsp+38h] [xbp-18h]
  __int64 v104; // [xsp+40h] [xbp-10h]
  __int64 v105; // [xsp+48h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97[1] = 0;
  *(_QWORD *)v98 = 0;
  v97[0] = 0;
  if ( a2 == -1072139010 )
  {
    v7 = *(_QWORD **)(a1 + 32);
    if ( inline_copy_from_user_0((int)v97, a3, 0x18u) )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B4EB, &unk_29207, "synx_test_ioctl", 834, v8, v9);
      result = -14;
      goto LABEL_9;
    }
    if ( !*(_QWORD *)v98 )
    {
      result = -22;
      goto LABEL_9;
    }
    if ( (synx_debug & 0x10) != 0 )
      printk(
        &unk_27F2E,
        "verb",
        "synx_test_ioctl",
        842,
        LODWORD(v97[0]),
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800));
    if ( LODWORD(v97[0]) != 3 )
    {
      if ( LODWORD(v97[0]) == 2 )
      {
        v100 = 0;
        v101 = 0;
        v99 = 0;
        if ( HIDWORD(v97[0]) == 24 )
        {
          v103 = 0;
          v104 = 0;
          v102 = 0;
          if ( inline_copy_from_user_0((int)&v102, v98[0], 0x18u) )
            goto LABEL_37;
          v15 = 4LL * HIDWORD(v103);
          v23 = _kmalloc_noprof(v15, 3520);
          v14 = v23;
          if ( !v23 || v23 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_29AD7, &unk_29207, "synx_handle_dma_array_create", 679, v24, v9);
LABEL_199:
            LODWORD(v15) = -12;
            if ( (synx_debug & 0x10) == 0 )
              goto LABEL_213;
            goto LABEL_38;
          }
          if ( !(HIDWORD(v103) >> 29) )
          {
            v25 = 4LL * HIDWORD(v103);
            v26 = v102;
            _check_object_size(v23, v25, 0);
            if ( !inline_copy_from_user_0(v14, v26, v25) )
            {
              v22 = HIDWORD(v103);
              if ( HIDWORD(v103) >= 0x1000 )
              {
                if ( (synx_debug & 1) != 0 )
                {
                  v19 = &unk_282A3;
                  v20 = "synx_handle_dma_array_create";
                  v21 = 692;
                  goto LABEL_158;
                }
LABEL_82:
                kfree(v14);
                goto LABEL_211;
              }
              v38 = (unsigned __int64)HIDWORD(v103) << 6;
              v52 = _kmalloc_noprof(v38, 3520);
              v11 = v52;
              if ( v52 && v52 <= 0xFFFFFFFFFFFFF000LL )
              {
                v54 = HIDWORD(v103);
                if ( !HIDWORD(v103) )
                {
                  LODWORD(v6) = 0;
LABEL_133:
                  v73 = *v7;
                  v99 = v11;
                  v100 = __PAIR64__(v103, v54);
                  v101 = 0;
                  v74 = synx_dma_array_fence_create(&v99, v73);
                  if ( v74 )
                  {
                    v15 = v74;
                  }
                  else
                  {
                    v75 = v101;
                    sync_fd = synx_test_create_sync_fd(v101);
                    LODWORD(v104) = sync_fd;
                    if ( (synx_debug & 8) != 0 )
                      printk(&unk_2A381, &unk_2A972, "synx_handle_dma_array_create", 735, sync_fd, v75);
                    dma_fence_put(v75);
                    v15 = HIDWORD(v97[0]);
                    if ( HIDWORD(v97[0]) >= 0x19 )
                      goto LABEL_196;
                    v77 = *(_QWORD *)v98;
                    _check_object_size(&v102, HIDWORD(v97[0]), 1);
                    if ( inline_copy_to_user_0(v77, &v102, v15) )
                      v15 = 4294967282LL;
                    else
                      v15 = 0;
                  }
                  goto LABEL_143;
                }
                LODWORD(v6) = 0;
                while ( 1 )
                {
                  v55 = 4LL * (int)v6;
                  if ( v15 <= v55 )
                    break;
                  fence = sync_file_get_fence(*(unsigned int *)(v14 + 4LL * (int)v6));
                  if ( v38 <= 8LL * (int)v6 )
                    break;
                  v58 = synx_debug;
                  *(_QWORD *)(v11 + 8LL * (int)v6) = fence;
                  if ( !fence || fence >= 0xFFFFFFFFFFFFF001LL )
                  {
                    if ( (v58 & 8) == 0 )
                    {
                      v15 = 4294967274LL;
                      goto LABEL_143;
                    }
                    if ( v15 > v55 )
                    {
                      printk(
                        &unk_27893,
                        &unk_2A972,
                        "synx_handle_dma_array_create",
                        712,
                        *(unsigned int *)(v14 + 4LL * (int)v6),
                        v57);
                      v15 = 4294967274LL;
                      goto LABEL_143;
                    }
                    break;
                  }
                  if ( (v58 & 8) != 0 )
                  {
                    if ( v15 <= v55 )
                      break;
                    printk(
                      &unk_2ABE1,
                      &unk_2A972,
                      "synx_handle_dma_array_create",
                      717,
                      fence,
                      *(unsigned int *)(v14 + 4LL * (int)v6));
                  }
                  v54 = HIDWORD(v103);
                  LODWORD(v6) = v6 + 1;
                  if ( (unsigned int)v6 >= HIDWORD(v103) )
                    goto LABEL_133;
                }
LABEL_195:
                while ( 1 )
                {
                  __break(1u);
LABEL_196:
                  _copy_overflow(24, v15);
                  v15 = 4294967282LL;
LABEL_143:
                  if ( !(_DWORD)v6 )
                    break;
                  v78 = v6 - 1;
                  while ( v38 > 8LL * v78 )
                  {
                    v79 = v78;
                    v80 = *(_QWORD *)(v11 + 8LL * v78);
                    if ( v80 )
                    {
                      _X0 = (unsigned int *)(v80 + 56);
                      __asm { PRFM            #0x11, [X0] }
                      do
                        v83 = __ldxr(_X0);
                      while ( __stlxr(v83 - 1, _X0) );
                      if ( v83 == 1 )
                      {
                        __dmb(9u);
                        dma_fence_release(_X0);
                      }
                      else if ( v83 <= 0 )
                      {
                        refcount_warn_saturate(_X0, 3);
                      }
                    }
                    v78 = v79 - 1;
                    if ( !v79 )
                      goto LABEL_154;
                  }
                }
LABEL_154:
                kfree(v11);
                v64 = v14;
LABEL_155:
                kfree(v64);
                if ( (synx_debug & 0x10) == 0 )
                  goto LABEL_213;
                goto LABEL_38;
              }
              if ( (synx_debug & 1) == 0 )
                goto LABEL_217;
              v94 = &unk_29AD7;
              v95 = "synx_handle_dma_array_create";
              v96 = 701;
LABEL_219:
              printk(v94, &unk_29207, v95, v96, v53, v9);
LABEL_217:
              kfree(v14);
              goto LABEL_199;
            }
            goto LABEL_34;
          }
          goto LABEL_189;
        }
      }
      else
      {
        if ( LODWORD(v97[0]) != 1 )
          goto LABEL_211;
        v103 = 0;
        v104 = 0;
        v102 = 0;
        if ( HIDWORD(v97[0]) != 24 )
          goto LABEL_211;
        if ( inline_copy_from_user_0((int)&v102, v98[0], 0x18u) )
          goto LABEL_37;
        v11 = (unsigned int)v102;
        if ( (_DWORD)v102 == 1 )
        {
          v37 = synx_dma_fence_util_init(*v7);
          v38 = v37;
          if ( v37 && v37 < 0xFFFFFFFFFFFFF001LL )
          {
            v12 = 0;
            v14 = 0;
            v15 = 0;
            goto LABEL_56;
          }
          if ( (synx_debug & 1) != 0 )
            printk(&unk_2AF3A, &unk_29207, "synx_dma_fence_create", 431, v37, v9);
          LODWORD(v15) = -61;
          if ( (synx_debug & 0x10) == 0 )
            goto LABEL_213;
LABEL_38:
          printk(&unk_29763, "verb", "synx_test_ioctl", 858, (unsigned int)v15, v9);
          goto LABEL_213;
        }
        if ( (_DWORD)v102 == 2 )
        {
          v12 = 8LL * (unsigned int)v104;
          v13 = _kmalloc_noprof(v12, 3520);
          v14 = v13;
          LODWORD(v15) = -12;
          if ( !v13 || v13 > 0xFFFFFFFFFFFFF000LL )
          {
LABEL_212:
            if ( (synx_debug & 0x10) == 0 )
              goto LABEL_213;
            goto LABEL_38;
          }
          if ( !((unsigned int)v104 >> 28) )
          {
            v16 = 8LL * (unsigned int)v104;
            v17 = v103;
            _check_object_size(v13, v16, 0);
            if ( !inline_copy_from_user_0(v14, v17, v16) )
            {
              v15 = (unsigned int)v104;
              if ( (unsigned int)v104 >= 0x1000 )
              {
                if ( (synx_debug & 1) != 0 )
                {
                  v19 = &unk_2899E;
                  v20 = "synx_handle_dma_create";
                  v21 = 586;
                  v22 = (unsigned int)v104;
LABEL_158:
                  printk(v19, &unk_29207, v20, v21, v22, v18);
                  goto LABEL_82;
                }
                goto LABEL_82;
              }
              v68 = 8LL * (unsigned int)v104;
              v69 = _kmalloc_noprof(v68, 3520);
              v38 = v69;
              if ( v69 && v69 < 0xFFFFFFFFFFFFF001LL )
              {
                if ( (_DWORD)v15 )
                {
                  v70 = *v7;
                  v71 = 0;
                  while ( 1 )
                  {
                    v72 = synx_dma_fence_util_init(v70);
                    if ( v68 <= 8LL * v71 )
                      goto LABEL_195;
                    *(_QWORD *)(v38 + 8LL * v71) = v72;
                    if ( !v72 || v72 >= 0xFFFFFFFFFFFFF001LL )
                      break;
                    if ( (_DWORD)v15 == ++v71 )
                      goto LABEL_56;
                  }
                  if ( (synx_debug & 1) != 0 )
                  {
                    printk(&unk_2AF3A, &unk_29207, "synx_dma_fence_create", 441, v72, v9);
                    v15 = 4294967235LL;
                    if ( v71 )
                      goto LABEL_161;
                  }
                  else
                  {
                    v15 = 4294967235LL;
                    if ( v71 )
                    {
LABEL_161:
                      v84 = v71 - 1;
                      while ( 1 )
                      {
                        v6 = 8LL * v84;
                        if ( v68 <= v6 )
                          goto LABEL_195;
                        v85 = v84;
                        v11 = *(_QWORD *)(v38 + 8LL * v84);
                        if ( (*(_QWORD *)(v11 + 48) & 1) == 0 )
                          break;
LABEL_177:
                        if ( v11 )
                        {
                          _X0 = (unsigned int *)(v11 + 56);
                          __asm { PRFM            #0x11, [X0] }
                          do
                            v89 = __ldxr(_X0);
                          while ( __stlxr(v89 - 1, _X0) );
                          if ( v89 == 1 )
                          {
                            __dmb(9u);
                            dma_fence_release(_X0);
                          }
                          else if ( v89 <= 0 )
                          {
                            refcount_warn_saturate(_X0, 3);
                          }
                        }
                        v84 = v85 - 1;
                        if ( !(_DWORD)v85 )
                        {
                          LODWORD(v15) = -61;
                          goto LABEL_115;
                        }
                      }
                      v86 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v11 + 8) + 32LL);
                      if ( v86 )
                      {
                        if ( *((_DWORD *)v86 - 1) != 1879296680 )
                          __break(0x8228u);
                        if ( (v86(v11) & 1) != 0 )
                        {
LABEL_175:
                          dma_fence_signal(v11);
                          if ( v68 <= v6 )
                            goto LABEL_195;
                          v11 = *(_QWORD *)(v38 + 8 * v85);
                          goto LABEL_177;
                        }
                        if ( v68 <= v6 )
                          goto LABEL_195;
                        v11 = *(_QWORD *)(v38 + 8 * v85);
                      }
                      if ( (*(_QWORD *)(v11 + 48) & 1) != 0 )
                        __break(0x800u);
                      *(_DWORD *)(v11 + 60) = -61;
                      if ( v68 <= v6 )
                        goto LABEL_195;
                      v11 = *(_QWORD *)(v38 + 8 * v85);
                      goto LABEL_175;
                    }
                  }
                  goto LABEL_115;
                }
LABEL_56:
                if ( (_DWORD)v102 == 1 )
                {
                  v59 = synx_test_create_sync_fd(v38);
                  LODWORD(v103) = v59;
                  if ( (synx_debug & 8) != 0 )
                    printk(&unk_2AEF2, &unk_2A972, "synx_handle_dma_create", 617, v59, v38);
                  dma_fence_put(v38);
                }
                else if ( (_DWORD)v102 == 2 )
                {
                  if ( (_DWORD)v15 )
                  {
                    v39 = 0;
                    LODWORD(v6) = -1;
                    do
                    {
                      v40 = 8LL * v39;
                      v41 = synx_test_create_sync_fd(*(_QWORD *)(v38 + v40));
                      if ( v12 < v40 )
                        goto LABEL_195;
                      if ( v12 - v40 < 4 )
                        goto LABEL_195;
                      v42 = 8LL * v39;
                      if ( v12 < v42 || v12 - v42 < 4 )
                        goto LABEL_195;
                      *(_DWORD *)(v14 + 8LL * v39) = v41;
                      if ( (synx_debug & 8) != 0 )
                      {
                        printk(&unk_254FD, &unk_2A972, "synx_handle_dma_create", 629, v41, *(_QWORD *)(v38 + 8LL * v39));
                        v43 = *(_QWORD *)(v38 + 8LL * v39);
                        if ( v43 )
                        {
LABEL_67:
                          _X0 = (unsigned int *)(v43 + 56);
                          __asm { PRFM            #0x11, [X0] }
                          do
                            v50 = __ldxr(_X0);
                          while ( __stlxr(v50 - 1, _X0) );
                          if ( v50 == 1 )
                          {
                            __dmb(9u);
                            dma_fence_release(_X0);
                          }
                          else if ( v50 <= 0 )
                          {
                            refcount_warn_saturate(_X0, 3);
                          }
                        }
                      }
                      else
                      {
                        v43 = *(_QWORD *)(v38 + 8LL * v39);
                        if ( v43 )
                          goto LABEL_67;
                      }
                      ++v39;
                    }
                    while ( (_DWORD)v15 != v39 );
                  }
                  if ( (unsigned int)v104 >> 28 )
                  {
                    __break(0x800u);
                    goto LABEL_109;
                  }
                  v60 = 8LL * (unsigned int)v104;
                  v61 = v103;
                  _check_object_size(v14, v60, 1);
                  if ( inline_copy_to_user_0(v61, v14, v60) )
                  {
LABEL_109:
                    LODWORD(v15) = -14;
                    goto LABEL_114;
                  }
                }
                v62 = HIDWORD(v97[0]);
                if ( HIDWORD(v97[0]) < 0x19 )
                {
                  v63 = *(_QWORD *)v98;
                  _check_object_size(&v102, HIDWORD(v97[0]), 1);
                  if ( inline_copy_to_user_0(v63, &v102, v62) )
                    LODWORD(v15) = -14;
                  else
                    LODWORD(v15) = 0;
LABEL_114:
                  if ( (_DWORD)v11 != 2 )
                    goto LABEL_212;
LABEL_115:
                  kfree(v14);
                  v64 = v38;
                  goto LABEL_155;
                }
                _copy_overflow(24, HIDWORD(v97[0]));
                goto LABEL_109;
              }
              if ( (synx_debug & 1) == 0 )
                goto LABEL_217;
              v94 = &unk_27F62;
              v95 = "synx_handle_dma_create";
              v96 = 597;
              goto LABEL_219;
            }
            goto LABEL_34;
          }
LABEL_189:
          __break(0x800u);
LABEL_34:
          kfree(v14);
          goto LABEL_37;
        }
        if ( (synx_debug & 1) != 0 )
        {
          v34 = &unk_293A3;
          v35 = "synx_handle_dma_create";
          v36 = 602;
          v27 = (unsigned int)v102;
          goto LABEL_77;
        }
      }
      goto LABEL_211;
    }
    if ( HIDWORD(v97[0]) != 24 )
      goto LABEL_211;
    v103 = 0;
    v104 = 0;
    v102 = 0;
    if ( inline_copy_from_user_0((int)&v102, v98[0], 0x18u) )
    {
LABEL_37:
      LODWORD(v15) = -14;
      if ( (synx_debug & 0x10) == 0 )
      {
LABEL_213:
        result = (int)v15;
        goto LABEL_9;
      }
      goto LABEL_38;
    }
    v27 = (unsigned int)v102;
    if ( (_DWORD)v102 != 1 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v34 = &unk_2A3C5;
        v35 = "synx_handle_dma_signal";
        v36 = 812;
LABEL_77:
        printk(v34, &unk_29207, v35, v36, v27, v9);
      }
LABEL_211:
      LODWORD(v15) = -22;
      goto LABEL_212;
    }
    v28 = sync_file_get_fence((unsigned int)v103);
    if ( !v28 || (v30 = v28, v28 >= 0xFFFFFFFFFFFFF001LL) )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2A813, &unk_29207, "synx_handle_dma_signal", 778, v29, v9);
      goto LABEL_211;
    }
    if ( *(_UNKNOWN **)(v28 + 8) == &dma_fence_array_ops )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_29062, &unk_29207, "synx_handle_dma_signal", 783, v28, v9);
      _X0 = (unsigned int *)(v30 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v93 = __ldxr(_X0);
      while ( __stlxr(v93 - 1, _X0) );
      if ( v93 == 1 )
      {
        __dmb(9u);
        dma_fence_release(_X0);
      }
      else if ( v93 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      goto LABEL_211;
    }
    v31 = HIDWORD(v103);
    if ( (synx_debug & 8) != 0 )
      printk(&unk_25558, &unk_2A972, "synx_handle_dma_signal", 792, v28, (unsigned int)v103);
    v32 = raw_spin_lock_irqsave(*(_QWORD *)v30);
    if ( (*(_QWORD *)(v30 + 48) & 1) != 0 )
    {
LABEL_121:
      v67 = *(_QWORD *)v30;
      _X19 = (unsigned int *)(v30 + 56);
      raw_spin_unlock_irqrestore(v67, v32);
      __asm { PRFM            #0x11, [X19] }
      do
        v91 = __ldxr(_X19);
      while ( __stlxr(v91 - 1, _X19) );
      if ( v91 == 1 )
      {
        __dmb(9u);
        dma_fence_release(_X19);
      }
      else if ( v91 <= 0 )
      {
        refcount_warn_saturate(_X19, 3);
      }
      LODWORD(v15) = 0;
      if ( (synx_debug & 0x10) == 0 )
        goto LABEL_213;
      goto LABEL_38;
    }
    v33 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v30 + 8) + 32LL);
    if ( v33 )
    {
      if ( *((_DWORD *)v33 - 1) != 1879296680 )
        __break(0x8228u);
      if ( (v33(v30) & 1) != 0 )
      {
        dma_fence_signal(v30);
        goto LABEL_121;
      }
    }
    if ( (v31 & 0xFFFFFFFD) == 0 )
    {
LABEL_120:
      dma_fence_signal_locked(v30);
      goto LABEL_121;
    }
    v65 = -v31;
    if ( (*(_QWORD *)(v30 + 48) & 1) != 0 )
    {
      __break(0x800u);
      if ( v65 > 0xFFFFF000 )
        goto LABEL_119;
    }
    else if ( v65 > 0xFFFFF000 )
    {
LABEL_119:
      *(_DWORD *)(v30 + 60) = v65;
      goto LABEL_120;
    }
    __break(0x800u);
    goto LABEL_119;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_26069, &unk_29207, "synx_test_ioctl", 827, a5, a6);
  result = -515;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
