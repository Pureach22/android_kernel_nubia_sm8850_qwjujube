__int64 __fastcall arm_smmu_attach_dev(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 **v3; // x23
  __int64 *v4; // x19
  __int64 v7; // x22
  unsigned int v8; // w0
  __int64 v9; // x28
  __int64 **v10; // x27
  __int64 v11; // x0
  unsigned int v12; // w24
  __int64 v13; // x0
  __int64 v14; // x24
  const char *v15; // x25
  __int64 *v16; // x22
  int v17; // w25
  __int64 v18; // x26
  unsigned int v19; // w8
  unsigned int v20; // w27
  _QWORD **v21; // x23
  int v22; // w1
  __int64 v23; // x9
  __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x9
  __int64 v26; // x10
  unsigned int v27; // w10
  __int64 v28; // x3
  __int64 v29; // x11
  unsigned int v30; // w10
  __int64 v31; // x2
  _DWORD *v32; // x8
  unsigned int v33; // w8
  unsigned int v39; // w10
  char v40; // w8
  const char *v41; // x25
  __int64 v42; // x8
  int v43; // w8
  int v44; // w8
  int v45; // w9
  __int64 v46; // x11
  unsigned __int64 v47; // x9
  __int64 v48; // x12
  unsigned __int64 v49; // x25
  int v50; // w10
  unsigned int v51; // w26
  __int64 (__fastcall **v52)(); // x8
  unsigned __int64 v53; // x9
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x8
  int v58; // w8
  unsigned int fast_iova_range; // w0
  __int64 v60; // x8
  _DWORD *v61; // x8
  __int64 *v62; // x8
  __int64 v63; // x9
  int v64; // w9
  __int64 v65; // x27
  _QWORD *v66; // x8
  __int64 v67; // t1
  int v68; // w10
  __int64 v69; // x11
  __int64 v70; // x13
  unsigned int next_zero_bit; // w0
  __int64 v72; // x8
  unsigned __int64 v75; // x9
  __int64 v76; // x20
  int v78; // w8
  __int16 v79; // w8
  char v80; // w9
  unsigned int v81; // w22
  __int64 *v82; // x9
  __int64 v83; // x10
  __int64 v84; // x8
  __int64 v85; // x8
  __int64 (__fastcall *v86)(__int64 **, __int64 *, __int64); // x8
  __int64 v87; // x8
  __int64 v88; // x0
  char v89; // w10
  __int64 v90; // x8
  __int64 v91; // x25
  __int64 v92; // x8
  char v93; // w9
  unsigned int inited; // w0
  unsigned __int64 v95; // x8
  unsigned __int64 v96; // x9
  __int64 v97; // x8
  __int64 v98; // x8
  void (__fastcall *v99)(__int64 **, __int64); // x8
  __int64 v100; // x8
  unsigned int v101; // w24
  __int64 (__fastcall *v102)(); // x3
  unsigned __int64 v105; // x10
  unsigned int v108; // w8
  unsigned int v109; // w8
  int v110; // [xsp+8h] [xbp-138h]
  unsigned int v111; // [xsp+14h] [xbp-12Ch]
  __int64 v112; // [xsp+20h] [xbp-120h]
  unsigned int v113; // [xsp+28h] [xbp-118h]
  __int64 v114; // [xsp+30h] [xbp-110h]
  int v115; // [xsp+3Ch] [xbp-104h] BYREF
  const char *v116; // [xsp+40h] [xbp-100h] BYREF
  __int64 v117; // [xsp+48h] [xbp-F8h] BYREF
  __int64 v118; // [xsp+50h] [xbp-F0h]
  __int64 v119; // [xsp+58h] [xbp-E8h]
  unsigned __int64 v120; // [xsp+60h] [xbp-E0h]
  __int64 v121; // [xsp+68h] [xbp-D8h]
  __int64 v122; // [xsp+70h] [xbp-D0h]
  __int64 v123; // [xsp+78h] [xbp-C8h]
  __int64 v124; // [xsp+80h] [xbp-C0h]
  __int64 v125; // [xsp+88h] [xbp-B8h]
  __int64 v126; // [xsp+90h] [xbp-B0h]
  __int64 v127; // [xsp+98h] [xbp-A8h]
  __int64 v128; // [xsp+A0h] [xbp-A0h]
  __int64 v129; // [xsp+A8h] [xbp-98h]
  __int64 v130; // [xsp+B0h] [xbp-90h]
  __int64 (__fastcall **v131)(); // [xsp+B8h] [xbp-88h]
  __int64 (__fastcall **v132)(); // [xsp+C0h] [xbp-80h]
  __int64 v133; // [xsp+C8h] [xbp-78h]
  __int64 v134; // [xsp+D0h] [xbp-70h] BYREF
  __int64 v135; // [xsp+D8h] [xbp-68h] BYREF
  _QWORD v136[12]; // [xsp+E0h] [xbp-60h] BYREF

  v136[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 824);
  if ( !v2 || (v3 = *(__int64 ***)(v2 + 72)) == nullptr )
  {
    v12 = -19;
    goto LABEL_156;
  }
  v4 = *v3;
  v7 = **v3;
  v114 = *(_QWORD *)(v2 + 56);
  if ( (*(_WORD *)(v7 + 488) & 7) != 0 || (v8 = _pm_runtime_resume(v7, 4), (v8 & 0x80000000) == 0) )
  {
    v9 = a1 - 104;
    v130 = 0;
    v131 = nullptr;
    v134 = 0;
    v135 = 0;
    v10 = (__int64 **)(a1 - 184);
    v132 = nullptr;
    v133 = 0;
    v128 = 0;
    v129 = 0;
    v126 = 0;
    v127 = 0;
    v124 = 0;
    v125 = 0;
    v122 = 0;
    v123 = 0;
    v120 = 0;
    v121 = 0;
    v118 = 0;
    v119 = 0;
    v117 = 0;
    mutex_lock(a1 - 104);
    if ( *(_QWORD *)(a1 - 184) )
    {
      v11 = mutex_unlock(a1 - 104);
      v12 = 0;
      goto LABEL_7;
    }
    *(_QWORD *)(a1 - 176) = a2;
    v13 = *(_QWORD *)(a2 + 744);
    if ( !v13
      || ((v116 = nullptr,
           v115 = 0,
           memset(v136, 0, 80),
           (unsigned int)_of_parse_phandle_with_args(v13, "qcom,iommu-group", 0, 0, 0, v136))
       || (v14 = v136[0]) == 0)
      && (v14 = *(_QWORD *)(a2 + 744)) == 0 )
    {
LABEL_82:
      v43 = *((_DWORD *)v4 + 8);
      if ( (v43 & 4) != 0 )
      {
        if ( (v43 & 8) != 0 )
        {
LABEL_84:
          if ( (v43 & 0x400) == 0 )
            goto LABEL_85;
          goto LABEL_89;
        }
      }
      else
      {
        *(_DWORD *)(a1 - 112) = 1;
        v43 = *((_DWORD *)v4 + 8);
        if ( (v43 & 8) != 0 )
          goto LABEL_84;
      }
      *(_DWORD *)(a1 - 112) = 0;
      v43 = *((_DWORD *)v4 + 8);
      if ( (v43 & 0x400) == 0 )
      {
LABEL_85:
        if ( (v43 & 0x380) != 0 )
        {
LABEL_86:
          v44 = 1;
          *(_DWORD *)(a1 - 120) = 1;
LABEL_91:
          v45 = *(_DWORD *)(a1 - 112);
          if ( (unsigned int)(v45 - 1) < 2 )
          {
            *(_DWORD *)(a1 - 124) = 0;
            LODWORD(v46) = 40;
            v47 = v4[22];
            if ( v47 >= 0x28 )
              LODWORD(v48) = 40;
            else
              v48 = v4[22];
            if ( (unsigned __int64)v4[23] < 0x28 )
              v46 = v4[23];
            if ( v44 == 1 )
              v49 = v4[23];
            else
              LODWORD(v49) = v46;
            if ( v44 == 1 )
            {
              v50 = 3;
            }
            else
            {
              LODWORD(v47) = v48;
              v50 = 1;
            }
            v113 = v47;
            v51 = 0;
            if ( *((_DWORD *)v4 + 10) == 2 )
              v52 = arm_smmu_s2_tlb_ops_v2;
            else
              v52 = arm_smmu_s2_tlb_ops_v1;
            goto LABEL_126;
          }
          if ( !v45 )
          {
            *(_DWORD *)(a1 - 124) = 1;
            v53 = v4[21];
            v49 = v4[22];
            v51 = *((_DWORD *)v4 + 15);
            if ( v44 == 2 )
            {
              LODWORD(v56) = 32;
              v50 = 0;
              if ( v53 < 0x20 )
                v56 = v4[21];
              _CF = v49 >= 0x28;
              v113 = v56;
              v58 = 40;
            }
            else
            {
              if ( v44 == 1 )
              {
                LODWORD(v54) = 39;
                if ( v53 < 0x27 )
                  v54 = v4[21];
                if ( (*((_BYTE *)v4 + 36) & 4) != 0 )
                  LODWORD(v55) = v54;
                else
                  v55 = v4[21];
                v50 = -2;
                v113 = v55;
LABEL_125:
                v52 = arm_smmu_s1_tlb_ops;
LABEL_126:
                *(_QWORD *)(a1 - 144) = v52;
                if ( (*(_BYTE *)(a1 - 47) & 4) == 0 )
                {
                  if ( *(_DWORD *)(a1 - 44) != -1 )
                    LODWORD(v133) = *(_DWORD *)(a1 - 44);
LABEL_131:
                  v60 = v4[6];
                  v111 = v50;
                  if ( v60 && (v61 = *(_DWORD **)(v60 + 128)) != nullptr )
                  {
                    v110 = v49;
                    v112 = a1 - 104;
                    if ( *(v61 - 1) != 321709247 )
                      __break(0x8228u);
                    v12 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, _QWORD))v61)(a1 - 184, v4, a2, v51);
LABEL_136:
                    v9 = v112;
                    LODWORD(v49) = v110;
                    if ( (v12 & 0x80000000) != 0 )
                      goto LABEL_153;
                  }
                  else
                  {
                    v62 = *(__int64 **)(a2 + 824);
                    if ( v62 )
                    {
                      v63 = v62[7];
                      v62 = (__int64 *)v62[9];
                    }
                    else
                    {
                      v63 = 0;
                    }
                    v64 = *(_DWORD *)(v63 + 12);
                    v65 = *((int *)v4 + 14);
                    if ( !v64 )
                    {
LABEL_146:
                      v110 = v49;
                      v112 = a1 - 104;
                      while ( 1 )
                      {
                        next_zero_bit = find_next_zero_bit(v4 + 8, v65, (int)v51);
                        v12 = next_zero_bit;
                        if ( (_DWORD)v65 == next_zero_bit )
                          break;
                        v72 = 1LL << next_zero_bit;
                        _X10 = (unsigned __int64 *)&v4[(next_zero_bit >> 6) + 8];
                        __asm { PRFM            #0x11, [X10] }
                        do
                          v75 = __ldxr(_X10);
                        while ( __stlxr(v75 | v72, _X10) );
                        __dmb(0xBu);
                        if ( (v75 & v72) == 0 )
                          goto LABEL_136;
                      }
                      v9 = a1 - 104;
                      v12 = -28;
                      goto LABEL_153;
                    }
                    v67 = *v62;
                    v66 = v62 + 1;
                    v68 = 0;
                    v69 = *(_QWORD *)(v67 + 112);
                    while ( 1 )
                    {
                      v70 = v69 + 24LL * *((__int16 *)v66 + v68);
                      if ( *(_BYTE *)(v70 + 21) == 1 )
                        break;
                      if ( v64 == ++v68 )
                        goto LABEL_146;
                    }
                    LOBYTE(v12) = *(_BYTE *)(v70 + 20);
                  }
                  *(_QWORD *)(a1 - 184) = v4;
                  *(_BYTE *)(a1 - 136) = v12;
                  if ( *((_DWORD *)v4 + 10) > 1u )
                  {
                    v10 = (__int64 **)(a1 - 184);
                    *(_BYTE *)(a1 - 135) = v12;
                  }
                  else
                  {
                    _X9 = (unsigned int *)(v4 + 11);
                    __asm { PRFM            #0x11, [X9] }
                    do
                    {
                      v108 = __ldxr(_X9);
                      v109 = v108 + 1;
                    }
                    while ( __stlxr(v109, _X9) );
                    __dmb(0xBu);
                    *(_BYTE *)(a1 - 135) = v109;
                    v10 = (__int64 **)(a1 - 184);
                    LOBYTE(v12) = *(_BYTE *)(a1 - 136);
                    *(_BYTE *)(a1 - 135) = (int)(unsigned __int8)v109 % *((_DWORD *)v4 + 50);
                  }
                  v78 = *(_DWORD *)(a1 - 112);
                  v132 = arm_smmu_pgtable_log_ops;
                  if ( v78 == 1 )
                    v79 = (unsigned __int8)v12 + 1;
                  else
                    v79 = (unsigned __int8)v12;
                  v80 = *(_BYTE *)(a1 - 152);
                  *(_WORD *)(a1 - 134) = v79;
                  v131 = arm_smmu_iotlb_ops;
                  if ( (v80 & 1) != 0 )
                  {
                    v81 = v113;
                    LOBYTE(v82) = 1;
                  }
                  else
                  {
                    v82 = *v10;
                    v81 = v113;
                    if ( *v10 )
                    {
                      v82 = (__int64 *)*v82;
                      if ( v82 )
                        LODWORD(v82) = (*((unsigned __int8 *)v82 + 844) >> 5) & 1;
                    }
                  }
                  v83 = *v4;
                  v119 = v4[24];
                  v84 = *(_QWORD *)(a1 - 144);
                  v126 = 0;
                  v127 = 0;
                  v128 = 0;
                  v129 = 0;
                  v130 = 0;
                  v122 = v84;
                  v123 = v83;
                  v124 = 0;
                  v125 = 0;
                  v85 = v4[6];
                  v117 = 0;
                  v118 = 0;
                  v120 = __PAIR64__(v49, v81);
                  LOBYTE(v121) = (_BYTE)v82;
                  *(_DWORD *)((char *)&v121 + 1) = 0;
                  HIDWORD(v121) = 0;
                  if ( !v85 )
                    goto LABEL_174;
                  v86 = *(__int64 (__fastcall **)(__int64 **, __int64 *, __int64))(v85 + 48);
                  if ( !v86 )
                    goto LABEL_174;
                  if ( *((_DWORD *)v86 - 1) != 1353781333 )
                    __break(0x8228u);
                  v12 = v86(v10, &v117, a2);
                  if ( !v12 )
                  {
LABEL_174:
                    v87 = *(_QWORD *)(a1 - 160);
                    if ( v87 )
                      v118 |= v87;
                    v88 = qcom_alloc_io_pgtable_ops(v111, &v117, v10);
                    if ( v88 )
                    {
                      v89 = v118;
                      v90 = -1LL << v81;
                      v91 = v88;
                      *(_QWORD *)(a1 + 32) = v119;
                      if ( (v89 & 0x20) != 0 )
                      {
                        *(_QWORD *)(a1 + 40) = v90;
                        v92 = -1;
                      }
                      else
                      {
                        v92 = ~v90;
                      }
                      v93 = *(_BYTE *)(a1 - 47);
                      *(_QWORD *)(a1 + 48) = v92;
                      *(_BYTE *)(a1 + 56) = 1;
                      if ( (v93 & 4) != 0 )
                      {
                        inited = fast_smmu_init_mapping(a2, a1, v88);
                        if ( inited )
                        {
                          v12 = inited;
                          qcom_free_io_pgtable_ops(*(_QWORD *)(a1 - 168));
                          goto LABEL_184;
                        }
                        v93 = *(_BYTE *)(a1 - 47);
                      }
                      if ( (v93 & 2) != 0 )
                      {
                        *(_BYTE *)(a1 + 120) = 1;
                        arm_smmu_rpm_get(v4);
                      }
                      arm_smmu_init_context_bank(v10, &v117);
                      v98 = v4[6];
                      if ( v98 )
                      {
                        v99 = *(void (__fastcall **)(__int64 **, __int64))(v98 + 56);
                        if ( v99 )
                        {
                          if ( *((_DWORD *)v99 - 1) != 903477104 )
                            __break(0x8228u);
                          v99(v10, a2);
                        }
                      }
                      arm_smmu_write_context_bank((__int64)v4, *(unsigned __int8 *)(a1 - 136));
                      v100 = v4[6];
                      v101 = *(_DWORD *)(v4[26] + 4LL * *(unsigned __int8 *)(a1 - 135));
                      if ( !v100 || (v102 = *(__int64 (__fastcall **)())(v100 + 120)) == nullptr )
                        v102 = arm_smmu_context_fault;
                      if ( (devm_request_threaded_irq(
                              *v4,
                              v101,
                              arm_smmu_context_fault_irq,
                              v102,
                              8320,
                              "arm-smmu-context-fault",
                              v10)
                          & 0x80000000) != 0 )
                      {
                        dev_err(*v4, "failed to request context IRQ %d (%u)\n", *(unsigned __int8 *)(a1 - 135), v101);
                        *(_BYTE *)(a1 - 135) = -1;
                      }
                      v11 = mutex_unlock(v9);
                      v12 = 0;
                      *(_QWORD *)(a1 - 168) = v91;
                      goto LABEL_7;
                    }
                    v12 = -12;
                  }
LABEL_184:
                  v95 = *(unsigned __int8 *)(a1 - 136);
                  v96 = v95 >> 6;
                  v97 = 1LL << v95;
                  _X9 = (unsigned __int64 *)&v4[v96 + 8];
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v105 = __ldxr(_X9);
                  while ( __stxr(v105 & ~v97, _X9) );
                  *v10 = nullptr;
                  v11 = mutex_unlock(v9);
                  if ( (v12 & 0x80000000) == 0 )
                  {
LABEL_7:
                    if ( *v10 == v4 )
                    {
                      v16 = *v3;
                      v17 = *(unsigned __int8 *)(a1 - 136);
                      v18 = (*v3)[14];
                      mutex_lock(*v3 + 15);
                      v19 = *(_DWORD *)(v114 + 12);
                      if ( v19 )
                      {
                        v20 = 0;
                        v21 = v3 + 1;
                        do
                        {
                          v22 = *((__int16 *)v21 + (int)v20);
                          v23 = v18 + 24LL * *((__int16 *)v21 + (int)v20);
                          if ( *(_DWORD *)(v23 + 12) || *(unsigned __int8 *)(v23 + 20) != v17 )
                          {
                            *(_QWORD *)(v23 + 12) = 0;
                            *(_BYTE *)(v23 + 20) = v17;
                            v24 = v16[6];
                            if ( v24 && (v25 = *(void (__fastcall **)(_QWORD))(v24 + 136)) != nullptr )
                            {
                              if ( *((_DWORD *)v25 - 1) != -1998289792 )
                                __break(0x8229u);
                              v25(v16);
                            }
                            else
                            {
                              v26 = v16[14] + 24LL * v22;
                              v27 = ((*(_DWORD *)(v26 + 12) & 3) << 16) & 0xFCFFFFFF
                                  | ((*(_DWORD *)(v26 + 16) & 3) << 24)
                                  | *(unsigned __int8 *)(v26 + 20);
                              v28 = v27 | 0x300;
                              if ( (*((_BYTE *)v16 + 33) & 0x10) != 0 )
                              {
                                v29 = v16[13];
                                if ( v29 )
                                {
                                  v30 = v27 | 0x700;
                                  if ( *(_BYTE *)(v29 + 8LL * v22 + 4) )
                                    v28 = v30;
                                  else
                                    v28 = (unsigned int)v28;
                                }
                              }
                              v31 = 4LL * v22 + 3072;
                              if ( v24 && (v32 = *(_DWORD **)(v24 + 8)) != nullptr )
                              {
                                if ( *(v32 - 1) != -1008624849 )
                                  __break(0x8228u);
                                ((void (__fastcall *)(__int64 *, _QWORD, __int64, __int64))v32)(v16, 0, v31, v28);
                              }
                              else
                              {
                                writel_relaxed_0(v28, (unsigned int *)(v16[1] + v31));
                              }
                            }
                            v19 = *(_DWORD *)(v114 + 12);
                          }
                          ++v20;
                        }
                        while ( v20 < v19 );
                      }
                      mutex_unlock(v16 + 15);
                      if ( (unsigned int)iommu_logger_register(a1, a2, *(_QWORD *)(a1 - 168)) )
                        dev_err(a2, "Registering iommu debug info failed, continuing.\n");
                      pm_runtime_set_autosuspend_delay(*v4, 20);
                      v11 = _pm_runtime_use_autosuspend(*v4, 1);
                    }
                    else
                    {
                      v12 = -22;
                    }
                  }
LABEL_154:
                  if ( (*(_WORD *)(*v4 + 488) & 7) == 0 )
                  {
                    v76 = *v4;
                    *(_QWORD *)(v76 + 520) = ktime_get_mono_fast_ns(v11);
                    _pm_runtime_suspend(*v4, 13);
                  }
                  goto LABEL_156;
                }
                fast_iova_range = qcom_iommu_get_fast_iova_range(a2, &v134, &v135);
                if ( (fast_iova_range & 0x80000000) == 0 )
                {
                  v50 = -1;
                  goto LABEL_131;
                }
                v12 = fast_iova_range;
LABEL_153:
                v11 = mutex_unlock(v9);
                goto LABEL_154;
              }
              v58 = 32;
              v50 = 4;
              if ( v53 >= 0x20 )
                LODWORD(v53) = 32;
              _CF = v49 >= 0x20;
              v113 = v53;
            }
            if ( _CF )
              LODWORD(v49) = v58;
            goto LABEL_125;
          }
LABEL_114:
          v12 = -22;
          goto LABEL_153;
        }
LABEL_90:
        v44 = *(_DWORD *)(a1 - 120);
        if ( !v44 )
          goto LABEL_114;
        goto LABEL_91;
      }
LABEL_89:
      *(_DWORD *)(a1 - 120) = 2;
      if ( (v4[4] & 0x380) != 0 )
        goto LABEL_86;
      goto LABEL_90;
    }
    if ( (unsigned int)of_property_read_string(v14, "qcom,iommu-dma", &v116) )
    {
      v15 = "default";
      v116 = "default";
    }
    else
    {
      v15 = v116;
    }
    if ( !strcmp(v15, "bypass") )
    {
      v40 = 1;
    }
    else if ( !strcmp(v15, "fastmap") )
    {
      v40 = 6;
    }
    else
    {
      if ( strcmp(v15, "atomic") )
      {
        if ( !strcmp(v15, "disabled") )
          goto LABEL_82;
LABEL_60:
        if ( (of_property_match_string(v14, "qcom,iommu-faults", "stall-disable") & 0x80000000) == 0 )
          *(_BYTE *)(a1 - 48) |= 4u;
        if ( (of_property_match_string(v14, "qcom,iommu-faults", "no-CFRE") & 0x80000000) == 0 )
          *(_BYTE *)(a1 - 48) |= 2u;
        if ( (of_property_match_string(v14, "qcom,iommu-faults", "HUPCF") & 0x80000000) == 0 )
          *(_BYTE *)(a1 - 48) |= 8u;
        if ( (of_property_match_string(v14, "qcom,iommu-faults", "non-fatal") & 0x80000000) == 0 )
          *(_BYTE *)(a1 - 48) |= 1u;
        if ( (of_property_read_variable_u32_array(v14, "qcom,iommu-vmid", &v115, 1, 0) & 0x80000000) == 0 )
          *(_DWORD *)(a1 - 44) = v115;
        if ( (unsigned int)of_property_read_string(v14, "qcom,iommu-pagetable", &v116) )
        {
          v41 = "disabled";
          v116 = "disabled";
        }
        else
        {
          v41 = v116;
        }
        if ( !strcmp(v41, "coherent") )
        {
          *(_BYTE *)(a1 - 152) = 1;
        }
        else
        {
          if ( !strcmp(v41, "LLC") )
          {
            v42 = 64;
          }
          else
          {
            if ( strcmp(v41, "LLC_NWA") )
              goto LABEL_80;
            v42 = 0x80000000LL;
          }
          *(_QWORD *)(a1 - 160) = v42;
        }
LABEL_80:
        if ( of_find_property(v14, "qcom,iommu-earlymap", 0) )
          *(_BYTE *)(a1 - 46) = 1;
        goto LABEL_82;
      }
      v40 = 2;
    }
    *(_BYTE *)(a1 - 47) |= v40;
    goto LABEL_60;
  }
  v33 = *(_DWORD *)(v7 + 480);
  v12 = v8;
  do
  {
    if ( !v33 )
      break;
    _X12 = (unsigned int *)(v7 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v39 = __ldxr(_X12);
      if ( v39 != v33 )
        break;
      if ( !__stlxr(v33 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v39 == v33;
    v33 = v39;
  }
  while ( !_ZF );
LABEL_156:
  _ReadStatusReg(SP_EL0);
  return v12;
}
