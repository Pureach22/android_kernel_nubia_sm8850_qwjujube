__int64 __fastcall msm_cvp_proc_oob(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 v5; // x28
  int v6; // w9
  _QWORD *v7; // x22
  unsigned __int64 v8; // x8
  __int64 v9; // x22
  _QWORD *v10; // x20
  __int64 v11; // x0
  unsigned int *v12; // x20
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned __int64 v15; // x24
  unsigned __int64 v16; // x27
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v26; // x10
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x8
  void *v33; // x0
  unsigned __int64 v34; // x9
  unsigned __int64 v36; // x9
  unsigned __int64 v38; // x10
  __int64 v40; // x0
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  __int64 v44; // x0
  __int64 v46; // x0
  __int64 v47; // x10
  __int64 v48; // x12
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x9
  __int64 v52; // x0
  __int64 v54; // x8
  unsigned __int64 v55; // x8
  _QWORD *v56; // x23
  __int64 v57; // x1
  __int64 v58; // x2
  void *v59; // x0
  __int64 v60; // x8
  __int64 v61; // x26
  __int64 v62; // x23
  _QWORD *v63; // x0
  int v64; // w0
  int v65; // w0
  __int64 v66; // x8
  unsigned __int64 v67; // x23
  unsigned int *v68; // x8
  unsigned int *v69; // x10
  __int64 v70; // x9
  unsigned __int64 v71; // x7
  unsigned int v72; // w5
  __int64 v73; // x12
  int v74; // w11
  unsigned int v75; // w11
  __int64 v76; // x12
  __int64 v77; // x1
  __int64 v78; // x2
  void *v79; // x0
  __int64 v80; // x8
  unsigned int *v81; // x26
  _QWORD *v82; // x0
  _QWORD *v83; // x27
  unsigned __int64 v84; // x10
  __int64 v85; // x3
  unsigned __int64 v86; // x9
  __int64 v87; // x8
  __int64 v88; // x10
  int v89; // w11
  int v90; // w12
  int *v91; // x13
  __int64 v92; // x14
  int v93; // w15
  int v94; // w16
  int *v95; // x8
  unsigned __int64 v96; // x9
  int v97; // t1
  int v98; // w27
  unsigned __int64 v99; // x8
  unsigned __int64 v101; // x9
  char *v102; // x8
  size_t v103; // [xsp+28h] [xbp-58h]
  __int64 v104; // [xsp+30h] [xbp-50h]
  __int64 v105; // [xsp+30h] [xbp-50h]
  unsigned int *v106; // [xsp+30h] [xbp-50h]
  __int64 v107; // [xsp+38h] [xbp-48h]
  __int64 v108; // [xsp+38h] [xbp-48h]
  __int64 v109; // [xsp+38h] [xbp-48h]
  _QWORD v110[2]; // [xsp+40h] [xbp-40h] BYREF
  __int64 v111; // [xsp+50h] [xbp-30h]
  __int64 v112; // [xsp+58h] [xbp-28h] BYREF
  __int64 v113; // [xsp+60h] [xbp-20h]
  __int64 v114; // [xsp+68h] [xbp-18h]
  __int64 v115; // [xsp+70h] [xbp-10h]
  __int64 v116; // [xsp+78h] [xbp-8h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && *(_QWORD *)(a1 + 128) )
  {
    if ( *(_DWORD *)(a2 + 4) != 18886684 )
    {
      LODWORD(v7) = 0;
      goto LABEL_64;
    }
    v114 = 0;
    v115 = 0;
    v112 = 0;
    v113 = 0;
    mutex_lock(&wncc_buf_pool);
    if ( (byte_6C550 & 1) != 0 )
    {
      v4 = dword_6C554;
      if ( (dword_6C554 & 1) != 0 )
      {
        if ( (dword_6C554 & 2) != 0 )
        {
          if ( (dword_6C554 & 4) != 0 )
          {
            if ( (dword_6C554 & 8) != 0 )
            {
              if ( (dword_6C554 & 0x10) != 0 )
              {
                if ( (dword_6C554 & 0x20) != 0 )
                {
                  if ( (dword_6C554 & 0x40) != 0 )
                  {
                    if ( (dword_6C554 & 0x80) != 0 )
                    {
                      mutex_unlock(&wncc_buf_pool);
                      v13 = _kmalloc_large_noprof(131064, 3520);
                      v12 = (unsigned int *)v13;
                      if ( !v13 )
                      {
                        LODWORD(v7) = -12;
                        goto LABEL_64;
                      }
                      v14 = a2;
                      LODWORD(v5) = 255;
                      goto LABEL_41;
                    }
                    v6 = 128;
                    v5 = 7;
                  }
                  else
                  {
                    v6 = 64;
                    v5 = 6;
                  }
                }
                else
                {
                  v6 = 32;
                  v5 = 5;
                }
              }
              else
              {
                v6 = 16;
                v5 = 4;
              }
            }
            else
            {
              v6 = 8;
              v5 = 3;
            }
          }
          else
          {
            v6 = 4;
            v5 = 2;
          }
        }
        else
        {
          v6 = 2;
          v5 = 1;
        }
      }
      else
      {
        v5 = 0;
        v6 = 1;
      }
LABEL_39:
      dword_6C554 = v6 | v4;
      v12 = *((unsigned int **)&wncc_buf_pool + v5 + 7);
      v13 = mutex_unlock(&wncc_buf_pool);
      if ( !v12 )
      {
        LODWORD(v7) = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_8B4A1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          v12 = nullptr;
          LODWORD(v7) = -22;
        }
        goto LABEL_59;
      }
      v14 = a2;
LABEL_41:
      v15 = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(v14 + 2400);
      if ( (*(_BYTE *)(v15 + 70) & 0x20) != 0 )
      {
        v18 = v16 & ((__int64)(v16 << 8) >> 8);
        if ( v18 <= 0x7FFFFE0004LL )
          goto LABEL_49;
      }
      else if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
      {
        if ( (v16 & ((__int64)(v16 << 8) >> 8)) <= 0x7FFFFE0004LL )
        {
LABEL_65:
          if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
          {
            if ( (v16 & ((__int64)(v16 << 8) >> 8)) > 0x7FFFFFFFFCLL )
              goto LABEL_67;
          }
          else if ( v16 >= 0x7FFFFFFFFDLL )
          {
LABEL_67:
            LODWORD(v7) = -22;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_96758, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
              LODWORD(v7) = -22;
            }
            goto LABEL_59;
          }
          v18 = *(_QWORD *)(v14 + 2400);
          if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
            v18 = v16 & ((__int64)(v16 << 8) >> 8);
LABEL_49:
          LODWORD(v7) = -14;
          if ( v18 >= 0x7FFFFFFFFDLL )
            goto LABEL_59;
          _X8 = v16 & 0xFF7FFFFFFFFFFFFFLL;
          v20 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v26 = *(_QWORD *)(v15 + 8);
          _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v26);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v20);
          __asm { LDTR            W5, [X8] }
          v28 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v30 - 4096);
          _WriteStatusReg(TTBR1_EL1, v30);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v28);
          if ( (_DWORD)_X5 != 1 )
          {
            LODWORD(v7) = -22;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8C884, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
              LODWORD(v7) = -22;
            }
            goto LABEL_59;
          }
          v31 = v16 + 4;
          if ( (*(_BYTE *)(v15 + 70) & 0x20) != 0 )
          {
            v34 = v31 & ((__int64)(v31 << 8) >> 8);
            if ( v34 <= 0x7FFFFFFFFCLL )
            {
LABEL_86:
              if ( v34 >= 0x7FFFFFFFFDLL )
              {
                *v12 = 0;
                LODWORD(v7) = -14;
                goto LABEL_59;
              }
              _X8 = v31 & 0xFF7FFFFFFFFFFFFFLL;
              v36 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v38 = *(_QWORD *)(v15 + 8);
              _WriteStatusReg(TTBR1_EL1, v38 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v38);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v36);
              __asm { LDTR            W22, [X8] }
              v40 = uaccess_ttbr0_disable(v13);
              *v12 = _X22;
              if ( (unsigned int)_X22 >= 0x24D )
              {
                LODWORD(v7) = -22;
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  printk(&unk_86377, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                  LODWORD(v7) = -22;
                }
                goto LABEL_59;
              }
              v41 = v16 + 8;
              if ( (*(_BYTE *)(v15 + 70) & 0x20) != 0 )
              {
                v42 = v41 & ((__int64)(v41 << 8) >> 8);
                if ( v42 <= 0x7FFFFFFFFCLL )
                  goto LABEL_105;
              }
              else if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
              {
                if ( (v41 & ((__int64)(v41 << 8) >> 8)) <= 0x7FFFFFFFFCLL )
                  goto LABEL_103;
              }
              else if ( v41 < 0x7FFFFFFFFDLL )
              {
LABEL_103:
                v42 = v16 + 8;
                if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
                  v42 = v41 & ((__int64)(v41 << 8) >> 8);
LABEL_105:
                if ( v42 >= 0x7FFFFFFFFDLL )
                {
                  v12[1] = 0;
                  LODWORD(v7) = -14;
                  goto LABEL_59;
                }
                _X22 = v41 & 0xFF7FFFFFFFFFFFFFLL;
                v44 = uaccess_ttbr0_enable(v40);
                __asm { LDTR            W22, [X22] }
                v46 = uaccess_ttbr0_disable(v44);
                v12[1] = _X22;
                if ( (unsigned int)(_X22 - 5) < 0xFFFFFFFC )
                {
                  LODWORD(v7) = -22;
                  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                  {
                    printk(&unk_8F724, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                    LODWORD(v7) = -22;
                  }
                  goto LABEL_59;
                }
                v7 = nullptr;
                v47 = 0;
                v48 = (v16 << 8) + 3072;
                do
                {
                  if ( v47 == 4 )
                  {
LABEL_237:
                    __break(0x5512u);
LABEL_238:
                    __break(1u);
                    v99 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    LODWORD(v7) = -14;
                    v101 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                    _WriteStatusReg(TTBR0_EL1, v101 - 4096);
                    _WriteStatusReg(TTBR1_EL1, v101);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v99);
                    goto LABEL_59;
                  }
                  v104 = v47;
                  v49 = (unsigned __int64)v7 + v16 + 12;
                  if ( (*(_BYTE *)(v15 + 70) & 0x20) != 0 )
                  {
                    v50 = v49 & (v48 >> 8);
                    if ( v50 > 0x7FFFFFFFFCLL )
                      goto LABEL_138;
                  }
                  else
                  {
                    if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
                    {
                      if ( (((unsigned __int64)v7 + v16 + 12) & (v48 >> 8)) > 0x7FFFFFFFFCLL )
                      {
LABEL_138:
                        LODWORD(v7) = -22;
                        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                        {
                          printk(&unk_896BD, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                          LODWORD(v7) = -22;
                        }
                        goto LABEL_59;
                      }
                    }
                    else if ( v49 >= 0x7FFFFFFFFDLL )
                    {
                      goto LABEL_138;
                    }
                    v50 = (unsigned __int64)v7 + v16 + 12;
                    if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
                      v50 = ((unsigned __int64)v7 + v16 + 12) & (v48 >> 8);
                  }
                  v107 = v48;
                  if ( v50 >= 0x7FFFFFFFFDLL )
                  {
                    v102 = (char *)v7 + (_QWORD)v12;
                    LODWORD(v7) = -14;
                    *((_DWORD *)v102 + 2) = 0;
                    goto LABEL_59;
                  }
                  _X23 = v49 & 0xFF7FFFFFFFFFFFFFLL;
                  v52 = uaccess_ttbr0_enable(v46);
                  __asm { LDTR            W23, [X23] }
                  uaccess_ttbr0_disable(v52);
                  *(_DWORD *)((char *)v7 + (_QWORD)v12 + 8) = _X23;
                  if ( (unsigned int)(_X23 - 4096) <= 0xFFFFF000 )
                  {
                    LODWORD(v7) = -22;
                    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    {
                      printk(&unk_8A106, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                      LODWORD(v7) = -22;
                    }
                    goto LABEL_59;
                  }
                  v103 = (unsigned int)(8 * _X23);
                  if ( !(unsigned int)access_ok((char *)v7 + v16 + 16)
                    || ((v54 = (unsigned int)(_X23 - 1), (*(_BYTE *)(v15 + 70) & 0x20) != 0)
                     || (*(_QWORD *)v15 & 0x4000000) != 0
                      ? (v55 = ((unsigned __int64)&v7[v54 + 2] + v16) & ((v107 + (v54 << 11) + 1024) >> 8))
                      : (v55 = (unsigned __int64)&v7[(unsigned int)v54 + 2] + v16),
                        v55 >= 0x7FFFFFFFF9LL) )
                  {
                    LODWORD(v7) = -22;
                    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    {
                      printk(&unk_8512A, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                      LODWORD(v7) = -22;
                    }
                    goto LABEL_59;
                  }
                  v56 = v7;
                  _check_object_size((char *)v7 + (_QWORD)v12 + 12, v103, 0);
                  v46 = inline_copy_from_user((int)v12 + (int)v7 + 12, (int)v16 + (int)v7 + 16, v103);
                  LODWORD(v7) = v46;
                  if ( (_DWORD)v46 )
                    goto LABEL_59;
                  v47 = v104 + 1;
                  v7 = (_QWORD *)((char *)v56 + 32764);
                  v48 = v107 + 8387584;
                }
                while ( v104 + 1 < (unsigned __int64)v12[1] );
                v114 = 0;
                v115 = 0;
                v112 = 0;
                v113 = 0;
                v110[1] = 0;
                v111 = 0;
                v110[0] = 3735928495LL;
                v105 = v12[1];
                if ( (unsigned int)(v105 - 5) > 0xFFFFFFFB )
                {
                  v60 = *v12;
                  if ( (unsigned int)v60 <= (unsigned int)(-48 * v105 + 2400) >> 2 )
                  {
                    v61 = 4 * v60;
                    v62 = 2;
                    v108 = 0;
                    while ( 1 )
                    {
                      v63 = (_QWORD *)dma_buf_get(*(unsigned int *)(a2 + v61));
                      v7 = v63;
                      if ( (unsigned __int64)v63 >= 0xFFFFFFFFFFFFF001LL )
                        break;
                      if ( *v63 < 16 * (unsigned __int64)v12[v62] )
                      {
                        v98 = -22;
                        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                          printk(&unk_86E99, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
LABEL_213:
                        dma_buf_put(v7);
                        LODWORD(v7) = v98;
LABEL_214:
                        wncc_unmap_metadata_bufs(a2, v12, &v112);
                        goto LABEL_215;
                      }
                      v64 = dma_buf_begin_cpu_access(v63, 1);
                      if ( v64 )
                      {
                        v98 = v64;
                        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                          printk(&unk_8C8C1, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                        goto LABEL_213;
                      }
                      v65 = dma_buf_vmap_unlocked(v7, v110);
                      v66 = v110[0];
                      v111 = v110[0];
                      if ( v65 )
                      {
                        v98 = v65;
                        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                          printk(&unk_83B96, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                        dma_buf_end_cpu_access(v7, 1);
                        goto LABEL_213;
                      }
                      if ( (msm_cvp_debug & 0xEFE8) != 0 && !msm_cvp_debug_out )
                      {
                        printk(&unk_88E4E, &unk_94624, "_wncc_map_metadata_bufs", v108);
                        v66 = v111;
                      }
                      *(&v112 + v108) = v66;
                      dma_buf_put(v7);
                      v61 += 48;
                      ++v108;
                      v62 += 0x1FFF;
                      if ( v105 == v108 )
                        goto LABEL_161;
                    }
                    if ( (msm_cvp_debug & 1) == 0 )
                      goto LABEL_214;
                    if ( msm_cvp_debug_out )
                      goto LABEL_214;
                    printk(&unk_82820, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                    if ( (_DWORD)v7 )
                      goto LABEL_214;
LABEL_161:
                    mutex_lock(a1 + 616);
                    if ( *(_DWORD *)(a1 + 12920) && *(_QWORD *)(a1 + 12928) )
                    {
                      if ( !v12[1] )
                      {
                        LODWORD(v7) = 0;
                        goto LABEL_231;
                      }
                      LODWORD(v7) = 0;
                      v67 = 0;
                      v106 = v12 + 4;
LABEL_166:
                      if ( v67 == 4 )
                        goto LABEL_237;
                      v68 = &v12[0x1FFF * v67 + 2];
                      v109 = 8 * v67;
                      if ( !*v68 )
                        goto LABEL_186;
                      v69 = v106;
                      v70 = 0;
                      v71 = 0;
                      while ( 1 )
                      {
                        if ( v71 == 4095 )
                          goto LABEL_237;
                        v72 = *(v69 - 1);
                        if ( v72 - 2401 <= 0xFFFFF69F )
                          break;
                        v73 = *(_QWORD *)(a1 + 12928) + 12LL * v72;
                        v74 = *(_DWORD *)(v73 - 8);
                        if ( !v74 )
                        {
                          LODWORD(v7) = -22;
                          if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
                            goto LABEL_186;
                          v77 = *(unsigned int *)(v15 + 1800);
                          v78 = *(unsigned int *)(v15 + 1804);
                          v79 = &unk_8ECD2;
                          goto LABEL_185;
                        }
                        if ( *v69 >= *(_DWORD *)(v73 - 4) )
                        {
                          LODWORD(v7) = -22;
                          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                          {
                            v77 = *(unsigned int *)(v15 + 1800);
                            v78 = *(unsigned int *)(v15 + 1804);
                            v79 = &unk_8BF4B;
                            goto LABEL_185;
                          }
LABEL_186:
                          v80 = *v12;
                          if ( (unsigned int)v80 > 0x258 )
                            goto LABEL_237;
                          v81 = (unsigned int *)(a2 + 4 * v80 + 48 * v67);
                          v82 = (_QWORD *)dma_buf_get(*v81);
                          v83 = v82;
                          if ( (unsigned __int64)v82 < 0xFFFFFFFFFFFFF001LL )
                          {
                            if ( *v82 >= (unsigned __int64)v81[1] )
                            {
                              dma_buf_put(v82);
                              if ( (v81[9] & 1) == 0 )
                                goto LABEL_165;
                              if ( v109 == 32 )
                                goto LABEL_238;
                              v84 = v81[1];
                              if ( (unsigned int)v84 >= 4 )
                              {
                                v86 = v84 >> 2;
                                v87 = *(&v112 + v67);
                                if ( (unsigned int)v84 >= 8 )
                                {
                                  v88 = (v84 >> 2) & 0x3FFFFFFE;
                                  v89 = 0;
                                  v90 = 0;
                                  v91 = (int *)(v87 + 4);
                                  v92 = v88;
                                  do
                                  {
                                    v93 = *(v91 - 1);
                                    v94 = *v91;
                                    v92 -= 2;
                                    v91 += 2;
                                    v89 += v93;
                                    v90 += v94;
                                  }
                                  while ( v92 );
                                  v85 = (unsigned int)(v90 + v89);
                                  if ( v88 == v86 )
                                    goto LABEL_200;
                                }
                                else
                                {
                                  v88 = 0;
                                  LODWORD(v85) = 0;
                                }
                                v95 = (int *)(v87 + 4 * v88);
                                v96 = v86 - v88;
                                do
                                {
                                  v97 = *v95++;
                                  --v96;
                                  v85 = (unsigned int)(v97 + v85);
                                }
                                while ( v96 );
                              }
                              else
                              {
                                v85 = 0;
                              }
LABEL_200:
                              v81[10] = v85;
                              if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
                                printk(&unk_85105, &unk_84256, "msm_cvp_proc_oob_wncc", v85);
LABEL_165:
                              ++v67;
                              v106 += 0x1FFF;
                              if ( v67 >= v12[1] )
                                goto LABEL_231;
                              goto LABEL_166;
                            }
                            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                              printk(
                                &unk_84639,
                                *(unsigned int *)(v15 + 1800),
                                *(unsigned int *)(v15 + 1804),
                                &unk_8E7CE);
                            dma_buf_put(v83);
LABEL_230:
                            LODWORD(v7) = -22;
                            goto LABEL_231;
                          }
                          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                            printk(&unk_82820, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                          LODWORD(v7) = (_DWORD)v83;
                          goto LABEL_231;
                        }
                        if ( v109 == 32 )
                          goto LABEL_238;
                        v75 = *v69 + v74;
                        ++v71;
                        v69 += 2;
                        *(_QWORD *)(*(&v112 + v67) + v70) = *(_QWORD *)(*(&v112 + v67) + v70) & 0x3FFFFFFFFFFLL
                                                          | ((unsigned __int64)v75 << 42);
                        v76 = *(&v112 + v67) + v70;
                        v70 += 16;
                        *(_QWORD *)(v76 + 8) = *(_QWORD *)(v76 + 8) & 0xFFFFFFFFFFFFFC00LL | (v75 >> 22);
                        if ( v71 >= *v68 )
                          goto LABEL_186;
                      }
                      LODWORD(v7) = -22;
                      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
                        goto LABEL_186;
                      v77 = *(unsigned int *)(v15 + 1800);
                      v78 = *(unsigned int *)(v15 + 1804);
                      v79 = &unk_88E02;
LABEL_185:
                      printk(v79, v77, v78, &unk_8E7CE);
                      LODWORD(v7) = -22;
                      goto LABEL_186;
                    }
                    LODWORD(v7) = -22;
                    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    {
                      printk(&unk_83099, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                      goto LABEL_230;
                    }
LABEL_231:
                    mutex_unlock(a1 + 616);
                    if ( (unsigned int)wncc_unmap_metadata_bufs(a2, v12, &v112)
                      && (msm_cvp_debug & 1) != 0
                      && !msm_cvp_debug_out )
                    {
                      v33 = &unk_8966F;
                      goto LABEL_74;
                    }
                    goto LABEL_61;
                  }
                  LODWORD(v7) = -22;
                  if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
                    goto LABEL_215;
                  v57 = *(unsigned int *)(v15 + 1800);
                  v58 = *(unsigned int *)(v15 + 1804);
                  v59 = &unk_86377;
                }
                else
                {
                  LODWORD(v7) = -22;
                  if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
                  {
LABEL_215:
                    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    {
                      v33 = &unk_8B637;
                      goto LABEL_74;
                    }
LABEL_61:
                    if ( (_DWORD)v5 == 255 )
                    {
                      kfree(v12);
                    }
                    else
                    {
                      mutex_lock(&wncc_buf_pool);
                      dword_6C554 &= ~(unsigned int)(1LL << v5);
                      memset(v12, 0, 0x1FFF8u);
                      mutex_unlock(&wncc_buf_pool);
                    }
                    goto LABEL_64;
                  }
                  v57 = *(unsigned int *)(v15 + 1800);
                  v58 = *(unsigned int *)(v15 + 1804);
                  v59 = &unk_8F724;
                }
                printk(v59, v57, v58, &unk_8E7CE);
                LODWORD(v7) = -22;
                goto LABEL_215;
              }
              LODWORD(v7) = -22;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_8BF9B, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
                LODWORD(v7) = -22;
              }
LABEL_59:
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v15 = _ReadStatusReg(SP_EL0);
                v33 = &unk_8B604;
LABEL_74:
                printk(v33, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
              }
              goto LABEL_61;
            }
          }
          else if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
          {
            if ( (v31 & ((__int64)(v31 << 8) >> 8)) <= 0x7FFFFFFFFCLL )
              goto LABEL_84;
          }
          else if ( v31 < 0x7FFFFFFFFDLL )
          {
LABEL_84:
            v34 = v16 + 4;
            if ( (*(_QWORD *)v15 & 0x4000000) != 0 )
              v34 = v31 & ((__int64)(v31 << 8) >> 8);
            goto LABEL_86;
          }
          LODWORD(v7) = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_90439, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
            LODWORD(v7) = -22;
          }
          goto LABEL_59;
        }
      }
      else if ( v16 < 0x7FFFFE0005LL )
      {
        goto LABEL_65;
      }
      LODWORD(v7) = -22;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8A0D2, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
        LODWORD(v7) = -22;
      }
      goto LABEL_59;
    }
    v9 = 0;
    v10 = &unk_6C540;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v11 = _kmalloc_large_noprof(131064, 3520);
      v10[3] = v11;
      if ( !v11 )
        break;
      --v9;
      ++v10;
      if ( v9 == -8 )
      {
        v4 = 0;
        v5 = 0;
        v6 = 1;
        byte_6C550 = 1;
        goto LABEL_39;
      }
    }
    if ( v9 )
    {
      kfree(v10[2]);
      if ( (unsigned __int64)-v9 >= 2 )
      {
        kfree(v10[1]);
        if ( (unsigned __int64)~v9 >= 2 )
        {
          kfree(*v10);
          if ( (unsigned __int64)(-2 - v9) >= 2 )
          {
            kfree(*(v10 - 1));
            if ( (unsigned __int64)(-3 - v9) >= 2 )
            {
              kfree(*(v10 - 2));
              if ( (unsigned __int64)(-4 - v9) >= 2 )
              {
                kfree(*(v10 - 3));
                if ( (unsigned __int64)(-5 - v9) >= 2 )
                  kfree(*(v10 - 4));
              }
            }
          }
        }
      }
    }
    mutex_unlock(&wncc_buf_pool);
    LODWORD(v7) = -12;
  }
  else
  {
    LODWORD(v7) = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_8B4A1, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      LODWORD(v7) = -22;
    }
  }
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
