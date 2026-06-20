__int64 __fastcall kgsl_iommu_fault_handler(__int64 a1, __int64 a2, unsigned __int64 a3, int a4)
{
  __int64 v8; // x19
  unsigned int v9; // w8
  int v10; // w9
  int v11; // w0
  char v12; // w10
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 v15; // x22
  unsigned int v16; // w8
  int v17; // w9
  int v18; // w0
  char v19; // w10
  unsigned int v20; // w24
  __int64 *v21; // x0
  __int64 *v22; // x22
  unsigned int v24; // w19
  unsigned int v25; // t1
  unsigned int v31; // w8
  __int64 v32; // x0
  unsigned int v34; // w25
  unsigned int v36; // w8
  int v37; // w9
  __int64 v38; // x26
  __int64 v39; // x25
  __int64 v40; // x8
  __int64 v41; // x27
  const char *v42; // x8
  const char *v43; // x8
  __int64 v44; // x8
  unsigned int v45; // w9
  __int64 v46; // x19
  int *v47; // x26
  int *v48; // x8
  int v49; // w9
  __int64 v50; // x28
  int v51; // w12
  int v52; // w11
  int v53; // w10
  int v54; // w9
  unsigned int v55; // w8
  int *v56; // x9
  char v57; // w8
  unsigned int v58; // w9
  int v59; // w10
  __int64 v60; // x10
  int v61; // w11
  int v62; // w12
  __int64 v63; // x10
  __int64 v64; // x8
  unsigned int *v65; // x9
  unsigned int v66; // t1
  char *v67; // x19
  __int64 v68; // x9
  __int64 v69; // x10
  size_t v70; // x0
  unsigned __int64 v71; // x2
  char *v72; // x19
  __int64 v73; // x8
  __int64 v74; // x9
  __int64 v75; // x25
  int v76; // w8
  int v77; // w9
  __int64 v78; // x23
  unsigned int v79; // w8
  int v80; // w9
  int v81; // w0
  char v82; // w10
  int v83; // w0
  __int64 v84; // x25
  int v85; // w23
  unsigned int v86; // w8
  int v87; // w9
  int v88; // w0
  char v89; // w10
  __int64 v90; // x25
  int v91; // w19
  const char *v92; // x7
  __int64 v93; // x25
  unsigned __int64 v94; // x8
  unsigned __int64 v95; // x8
  __int64 v96; // x0
  unsigned int v97; // w0
  _DWORD *v98; // x8
  __int64 v99; // x19
  const char *v100; // x0
  int v101; // w19
  __int64 next; // x0
  __int64 v103; // x25
  __int64 v104; // x26
  __int64 v105; // x8
  __int64 v106; // x2
  unsigned __int64 v107; // x8
  __int64 v108; // x8
  __int64 v109; // x2
  unsigned __int64 StatusReg; // x19
  __int64 v111; // x0
  __int64 v112; // x8
  int v114; // w8
  unsigned int v117; // w9
  int v119; // w8
  unsigned __int64 v120; // x8
  __int64 result; // x0
  unsigned __int64 v122; // x8
  bool v123; // cc
  _BOOL4 v124; // w8
  _QWORD *v125; // [xsp+0h] [xbp-C0h]
  char *s1; // [xsp+8h] [xbp-B8h]
  const char *v127; // [xsp+10h] [xbp-B0h]
  const char *v128; // [xsp+18h] [xbp-A8h]
  const char *v129; // [xsp+20h] [xbp-A0h]
  __int64 v130; // [xsp+28h] [xbp-98h]
  int v131; // [xsp+34h] [xbp-8Ch]
  unsigned int v132; // [xsp+3Ch] [xbp-84h]
  _QWORD *v133; // [xsp+40h] [xbp-80h]
  unsigned __int64 v134; // [xsp+48h] [xbp-78h]
  int *v135; // [xsp+50h] [xbp-70h]
  __int64 v136; // [xsp+58h] [xbp-68h]
  __int64 v137; // [xsp+60h] [xbp-60h]
  int v138; // [xsp+6Ch] [xbp-54h]
  int v139; // [xsp+70h] [xbp-50h] BYREF
  int v140; // [xsp+74h] [xbp-4Ch] BYREF
  __int64 v141; // [xsp+78h] [xbp-48h] BYREF
  __int64 v142; // [xsp+80h] [xbp-40h] BYREF
  unsigned __int64 v143; // [xsp+88h] [xbp-38h] BYREF
  _QWORD v144[6]; // [xsp+90h] [xbp-30h] BYREF

  v144[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 24);
  v9 = *(_DWORD *)(v8 + 1020);
  if ( v9 )
  {
    v10 = *(_DWORD *)(v8 + 1024);
  }
  else
  {
    v11 = readl_relaxed_1(*(_QWORD *)(v8 + 960) + 36LL);
    if ( v11 < 0 )
      v12 = 16;
    else
      v12 = 12;
    if ( v11 < 0 )
      v10 = 0x10000;
    else
      v10 = 4096;
    v9 = 2 << (((unsigned int)v11 >> 28) & 7) << v12;
    *(_DWORD *)(v8 + 1024) = v10;
    *(_DWORD *)(v8 + 1020) = v9;
  }
  v13 = readq_relaxed(*(_QWORD *)(v8 + 960) + v9 + (unsigned int)(*(_DWORD *)(a2 + 16) * v10) + 32LL);
  v14 = *(_QWORD *)(a2 + 24);
  v15 = v13;
  v16 = *(_DWORD *)(v14 + 1020);
  if ( v16 )
  {
    v17 = *(_DWORD *)(v14 + 1024);
  }
  else
  {
    v18 = readl_relaxed_1(*(_QWORD *)(v14 + 960) + 36LL);
    if ( v18 < 0 )
      v19 = 16;
    else
      v19 = 12;
    if ( v18 < 0 )
      v17 = 0x10000;
    else
      v17 = 4096;
    v16 = 2 << (((unsigned int)v18 >> 28) & 7) << v19;
    *(_DWORD *)(v14 + 1024) = v17;
    *(_DWORD *)(v14 + 1020) = v16;
  }
  v20 = readl_relaxed_1(*(_QWORD *)(v14 + 960) + v16 + (unsigned int)(*(_DWORD *)(a2 + 16) * v17) + 52LL);
  raw_read_lock(&unk_3A870);
  v21 = &qword_3A800;
  v137 = v15;
  do
  {
    v21 = (__int64 *)*v21;
    if ( v21 == &qword_3A800 )
      goto LABEL_32;
  }
  while ( *(_QWORD *)(*(v21 - 1) + 192) != (v15 & 0xFFFFFFFFFFFFLL) );
  v22 = v21 - 9;
  if ( v21 == (__int64 *)&_crc_kgsl_gpu_num_freqs )
    goto LABEL_32;
  v25 = *((_DWORD *)v21 - 9);
  _X0 = (unsigned int *)v21 - 9;
  v24 = v25;
  if ( v25 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v31 = __ldxr(_X0);
      while ( v31 == v24 && __stxr(v24 + 1, _X0) );
      if ( v31 == v24 )
        break;
      v24 = v31;
    }
    while ( v31 );
  }
  if ( (((v24 + 1) | v24) & 0x80000000) == 0 )
  {
    if ( v24 )
      goto LABEL_33;
    goto LABEL_32;
  }
  refcount_warn_saturate(_X0, 0);
  if ( !v24 )
LABEL_32:
    v22 = nullptr;
LABEL_33:
  raw_read_unlock(&unk_3A870);
  raw_read_lock(a1 + 11152);
  v131 = v20;
  v32 = idr_find(a1 + 11128, v20);
  if ( !v32 || (_X24 = v32, (*(_QWORD *)(v32 + 32) & 2) != 0) )
  {
    raw_read_unlock(a1 + 11152);
  }
  else
  {
    v34 = *(_DWORD *)v32;
    if ( *(_DWORD *)v32 )
    {
      do
      {
        __asm { PRFM            #0x11, [X24] }
        do
          v36 = __ldxr((unsigned int *)v32);
        while ( v36 == v34 && __stxr(v34 + 1, (unsigned int *)v32) );
        if ( v36 == v34 )
          break;
        v34 = v36;
      }
      while ( v36 );
    }
    if ( (((v34 + 1) | v34) & 0x80000000) != 0 )
      refcount_warn_saturate(v32, 0);
    raw_read_unlock(a1 + 11152);
    if ( v34 )
    {
      if ( (a4 & 0x20) == 0 )
        goto LABEL_52;
      goto LABEL_49;
    }
  }
  _X24 = 0;
  if ( (a4 & 0x20) == 0 )
  {
LABEL_52:
    v37 = 0;
    goto LABEL_53;
  }
LABEL_49:
  if ( (*(_QWORD *)(a1 + 56) & 2) == 0 || (*(_QWORD *)(a1 + 48) & 0x100) != 0 || (*(_BYTE *)(a2 + 32) & 1) != 0 )
    goto LABEL_52;
  if ( (unsigned int)rt_mutex_trylock(a1 + 11032) )
  {
    if ( (gmu_core_isenabled(a1 - 56) & 1) != 0 )
      kgsl_pwrctrl_irq(a1 - 56, 0);
    else
      kgsl_pwrctrl_change_state((_QWORD *)(a1 - 56), 32);
    rt_mutex_unlock(a1 + 11032);
  }
  v37 = 1;
LABEL_53:
  v133 = (_QWORD *)(a1 - 56);
  if ( (*(_QWORD *)(a1 + 56) & 2) != 0 )
    v38 = (*(_QWORD *)(a1 + 48) >> 8) & 1LL;
  else
    v38 = 0;
  v138 = v37;
  v39 = *(_QWORD *)(*(_QWORD *)(a1 + 14208) + 40LL);
  if ( !v22 )
  {
    v129 = nullptr;
    goto LABEL_60;
  }
  v40 = v22[1];
  v129 = (const char *)(v22 + 2);
  if ( !v40 )
  {
LABEL_60:
    v132 = 0;
    goto LABEL_61;
  }
  v132 = *(_DWORD *)(v40 + 112);
LABEL_61:
  v41 = a4 & 1;
  v42 = "write";
  v139 = 0;
  if ( (a4 & 1) == 0 )
    v42 = "read";
  v128 = v42;
  while ( 1 )
  {
    if ( (a4 & 4) != 0 )
    {
      v43 = "translation";
    }
    else if ( (a4 & 8) != 0 )
    {
      v43 = "permission";
    }
    else
    {
      v43 = "transaction stalled";
      if ( (a4 & 0x20) == 0 )
        v43 = "unknown";
      if ( (a4 & 0x10) != 0 )
        v43 = "external";
    }
    v127 = v43;
    v130 = v39;
    raw_write_lock(a1 + 1448);
    v44 = a1 + 984;
    v45 = __clz(__rbit32(a4 & 0xFFFFFFFE));
    v46 = (a4 & 0xFFFFFFFE) != 0 ? v45 : 0xFFFFFFFFLL;
    *(_DWORD *)(v44 + 4LL * (a4 & 1)) = *(_DWORD *)(a1 + 984 + 4LL * (a4 & 1)) + 1;
    if ( (unsigned int)v46 >= 6 )
    {
      if ( !v22 )
        goto LABEL_156;
      v134 = a3;
      v125 = v22 + 83;
      v48 = (int *)v22 + v41 + 166;
      v39 = (unsigned int)(*((_DWORD *)v22 + 165) + 1);
      v135 = (int *)v22 + 165;
      v136 = v38;
      v47 = v48;
      *((_DWORD *)v22 + 165) = v39;
    }
    else
    {
      ++*(_DWORD *)(v44 + 4 * v46);
      if ( !v22 )
        goto LABEL_156;
      v136 = v38;
      v47 = (int *)v22 + v41 + 166;
      v125 = v22 + 83;
      v39 = (unsigned int)(*((_DWORD *)v22 + 165) + 1);
      v48 = (int *)v22 + v46 + 166;
      v49 = *v47;
      *((_DWORD *)v22 + 165) = v39;
      v134 = a3;
      v135 = (int *)v22 + 165;
      *v47 = v49 + 1;
    }
    v50 = a1 + 1404;
    ++*v48;
    s1 = (char *)(a1 + 1008);
    if ( strcmp((const char *)(a1 + 1404), (const char *)v22 + 16) )
      break;
    v57 = 0;
    v58 = 9;
LABEL_135:
    v59 = *(_DWORD *)(v50 + 16) + 1;
    *(_DWORD *)(v50 + 16) = v59;
    *v135 = v59;
    v60 = v50 + 20;
    v61 = *(_DWORD *)(v50 + 20 + 4 * v41) + 1;
    *(_DWORD *)(v50 + 20 + 4 * v41) = v61;
    *v47 = v61;
    if ( (unsigned int)v46 <= 5 )
    {
      v62 = *(_DWORD *)(v60 + 4 * v46) + 1;
      *(_DWORD *)(v60 + 4 * v46) = v62;
      *((_DWORD *)v22 + v46 + 166) = v62;
    }
    a3 = v134;
    v38 = v136;
    if ( (v57 & 1) != 0 )
      goto LABEL_156;
    v63 = 0;
    v64 = v58;
    v65 = (unsigned int *)(a1 + 1024);
    while ( 1 )
    {
      v66 = *v65;
      v65 += 11;
      if ( v66 < *v135 )
        break;
      if ( v64 == ++v63 )
        goto LABEL_156;
    }
    if ( (_DWORD)v64 == (_DWORD)v63 )
      goto LABEL_156;
    if ( (unsigned int)v63 <= 9 )
    {
      v39 = v63 & 0xF;
      v38 = v134;
      a3 = (unsigned __int64)&s1[44 * v39];
      v67 = &s1[44 * (unsigned int)v64];
      *((_DWORD *)v67 + 4) = *(_DWORD *)(a3 + 16);
      v68 = *(_QWORD *)(a3 + 28);
      v69 = *(_QWORD *)(a3 + 20);
      *(_QWORD *)(v67 + 36) = *(_QWORD *)(a3 + 36);
      *(_QWORD *)(v67 + 28) = v68;
      *(_QWORD *)(v67 + 20) = v69;
      v70 = strnlen((const char *)a3, 0x10u);
      if ( v70 < 0x11 )
      {
        if ( v70 == 16 )
          v71 = 16;
        else
          v71 = v70 + 1;
        if ( v71 < 0x11 )
        {
          sized_strscpy(v67, a3);
          v56 = v135;
          goto LABEL_150;
        }
LABEL_245:
        _fortify_panic(7, 16, v71);
        goto LABEL_246;
      }
LABEL_244:
      _fortify_panic(2, 16, v70 + 1);
      goto LABEL_245;
    }
LABEL_246:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v111 = _traceiter_kgsl_mmu_pagefault(0, (__int64)v133, a3, v132, (__int64)v129, (__int64)v128);
      v112 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v112;
      if ( !v112 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v111);
    }
  }
  v50 = a1 + 1360;
  if ( !strcmp((const char *)(a1 + 1360), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 8;
    goto LABEL_135;
  }
  v50 = a1 + 1316;
  if ( !strcmp((const char *)(a1 + 1316), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 7;
    goto LABEL_135;
  }
  v50 = a1 + 1272;
  if ( !strcmp((const char *)(a1 + 1272), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 6;
    goto LABEL_135;
  }
  v50 = a1 + 1228;
  if ( !strcmp((const char *)(a1 + 1228), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 5;
    goto LABEL_135;
  }
  v50 = a1 + 1184;
  if ( !strcmp((const char *)(a1 + 1184), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 4;
    goto LABEL_135;
  }
  v50 = a1 + 1140;
  if ( !strcmp((const char *)(a1 + 1140), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 3;
    goto LABEL_135;
  }
  v50 = a1 + 1096;
  if ( !strcmp((const char *)(a1 + 1096), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 2;
    goto LABEL_135;
  }
  v50 = a1 + 1052;
  if ( !strcmp((const char *)(a1 + 1052), (const char *)v22 + 16) )
  {
    v57 = 0;
    v58 = 1;
    goto LABEL_135;
  }
  v50 = a1 + 1008;
  if ( !strcmp(s1, (const char *)v22 + 16) )
  {
    v58 = 0;
    v57 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(a1 + 1420) >= (unsigned int)v39 )
    v51 = -1;
  else
    v51 = 9;
  if ( *(_DWORD *)(a1 + 1376) < (unsigned int)v39 )
    v51 = 8;
  if ( *(_DWORD *)(a1 + 1332) < (unsigned int)v39 )
    v51 = 7;
  if ( *(_DWORD *)(a1 + 1288) >= (unsigned int)v39 )
    v52 = v51;
  else
    v52 = 6;
  if ( *(_DWORD *)(a1 + 1244) < (unsigned int)v39 )
    v52 = 5;
  LODWORD(v38) = v136;
  if ( *(_DWORD *)(a1 + 1200) >= (unsigned int)v39 )
    v53 = v52;
  else
    v53 = 4;
  if ( *(_DWORD *)(a1 + 1156) >= (unsigned int)v39 )
    v54 = v53;
  else
    v54 = 3;
  if ( *(_DWORD *)(a1 + 1112) >= (unsigned int)v39 )
    v55 = v54;
  else
    v55 = 2;
  a3 = v134;
  v56 = v135;
  if ( *(_DWORD *)(a1 + 1068) < (unsigned int)v39 )
    v55 = 1;
  if ( *(_DWORD *)(a1 + 1024) >= (unsigned int)v39 )
    v39 = v55;
  else
    v39 = 0;
  if ( (v39 & 0x80000000) != 0 )
    goto LABEL_156;
  v38 = v134;
LABEL_150:
  v72 = &s1[44 * (unsigned int)v39];
  *((_DWORD *)v72 + 4) = *v56;
  v74 = v125[1];
  v73 = v125[2];
  *(_QWORD *)(v72 + 20) = *v125;
  *(_QWORD *)(v72 + 36) = v73;
  *(_QWORD *)(v72 + 28) = v74;
  v70 = strnlen((const char *)v22 + 16, 0x10u);
  if ( v70 >= 0x11 )
    goto LABEL_244;
  if ( v70 == 16 )
    v71 = 16;
  else
    v71 = v70 + 1;
  if ( v71 >= 0x11 )
    goto LABEL_245;
  a3 = v38;
  sized_strscpy(v72, v22 + 2);
  LODWORD(v38) = v136;
LABEL_156:
  raw_write_unlock(a1 + 1448);
  if ( ((*(_QWORD *)(a1 + 56) & 4) == 0 || (unsigned int)kgsl_mmu_log_fault_addr(a1, v137, a3))
    && (unsigned int)__ratelimit(a2 + 40, "kgsl_iommu_print_fault") )
  {
    v90 = *v133;
    if ( _X24 )
    {
      v91 = *(_DWORD *)(_X24 + 12);
      v92 = kgsl_context_type(*(_DWORD *)(_X24 + 400));
    }
    else
    {
      v91 = 0;
      v92 = "ANY";
    }
    dev_crit(
      v90,
      "GPU PAGE FAULT: addr = %lX group id= %d name=%s drawctxt=%d context pid = %d ctx_type=%s\n",
      a3,
      v132,
      v129,
      v131,
      v91,
      v92);
    dev_crit(*v133, "context=%s TTBR0=0x%llx (%s %s fault)\n", *(const char **)(a2 + 8), v137, v128, v127);
    if ( *(_QWORD *)(v130 + 128) )
    {
      v96 = kgsl_iommu_reg(a2, 108);
      v97 = readl_relaxed_1(v96);
      v98 = *(_DWORD **)(v130 + 128);
      v99 = *v133;
      if ( *(v98 - 1) != 2031156281 )
        __break(0x8228u);
      v100 = (const char *)((__int64 (__fastcall *)(_QWORD *, _QWORD))v98)(v133, v97);
      dev_crit(v99, "FAULTING BLOCK: %s\n", v100);
      if ( (a4 & 8) != 0 )
        goto LABEL_159;
    }
    else if ( (a4 & 8) != 0 )
    {
      goto LABEL_159;
    }
    v93 = *v133;
    v142 = 0;
    v143 = a3;
    v141 = 0;
    memset(v144, 0, 32);
    v140 = 0;
    if ( (unsigned int)kgsl_memfree_find_entry(v132, &v143, &v142, &v141, &v140) )
    {
      kgsl_get_memory_usage((char *)v144, 0x20u, v141);
      dev_err(v93, "---- premature free ----\n");
      dev_err(v93, "[%8.8llX-%8.8llX] (%s) was already freed by pid %d\n", v143, v142 + v143, (const char *)v144, v140);
      if ( (*(_QWORD *)(a1 + 48) & 0x40) == 0 )
      {
LABEL_208:
        v94 = 3932155904LL;
        if ( (*(_QWORD *)(a1 + 48) & 1LL) == 0 )
          v94 = 4160749568LL;
        if ( v94 <= a3 )
        {
          v95 = 4026527744LL;
          if ( (*(_QWORD *)(a1 + 48) & 1LL) == 0 )
            v95 = 4255121408LL;
          if ( v95 > a3 )
            goto LABEL_214;
        }
        goto LABEL_221;
      }
    }
    else if ( (*(_QWORD *)(a1 + 48) & 0x40) == 0 )
    {
      goto LABEL_208;
    }
    if ( a3 >> 39 > 0x3FE )
    {
LABEL_214:
      dev_crit(*v133, "Fault in global memory\n");
      goto LABEL_159;
    }
LABEL_221:
    if ( v22 )
    {
      v101 = v38;
      dev_crit(*v133, "---- nearby memory ----\n");
      raw_spin_lock(v22 + 4);
      v139 = 0;
      next = idr_get_next(v22 + 5, &v139);
      if ( next )
      {
        v104 = 0;
        v103 = 0;
        do
        {
          v107 = *(_QWORD *)(next + 32);
          if ( v107 < a3 && (!v104 || *(_QWORD *)(v104 + 32) < v107) )
            v104 = next;
          if ( v107 > a3 && (!v103 || *(_QWORD *)(v103 + 32) > v107) )
            v103 = next;
          ++v139;
          next = idr_get_next(v22 + 5, &v139);
        }
        while ( next );
      }
      else
      {
        v103 = 0;
        v104 = 0;
      }
      v105 = v22[1];
      if ( v105 )
        v106 = *(unsigned int *)(v105 + 112);
      else
        v106 = 0;
      print_entry(*v133, v104, v106);
      dev_crit(*v133, "<- fault @ %16.16lx\n", a3);
      v108 = v22[1];
      if ( v108 )
        v109 = *(unsigned int *)(v108 + 112);
      else
        v109 = 0;
      LODWORD(v38) = v101;
      print_entry(*v133, v103, v109);
      raw_spin_unlock(v22 + 4);
    }
  }
LABEL_159:
  if ( _X24 )
  {
    if ( (*(_BYTE *)(_X24 + 203) & 0x40) != 0 )
    {
      v75 = _kmalloc_cache_noprof(idr_find, 3520, 32);
      if ( v75 )
      {
        if ( (a4 & 4) != 0 )
        {
          v76 = 4;
        }
        else if ( (a4 & 8) != 0 )
        {
          v76 = 8;
        }
        else
        {
          v76 = (a4 & 0x10) != 0 ? 16 : a4 & 0x20;
        }
        v77 = (a4 & 1) != 0 ? 2 : 1;
        *(_QWORD *)v75 = a3;
        *(_DWORD *)(v75 + 24) = v76 | v77;
        if ( (unsigned int)kgsl_add_fault((_QWORD *)_X24, 1, v75) )
          kfree(v75);
      }
    }
  }
  if ( (((unsigned __int8)v138 | (unsigned __int8)v38) & 1) == 0 )
  {
LABEL_195:
    if ( _X24 )
    {
      __asm { PRFM            #0x11, [X24] }
      do
        v114 = __ldxr((unsigned int *)_X24);
      while ( __stlxr(v114 - 1, (unsigned int *)_X24) );
      if ( v114 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X24);
      }
      else if ( v114 <= 0 )
      {
        refcount_warn_saturate(_X24, 3);
      }
    }
    kgsl_process_private_put((unsigned int *)v22);
    if ( (((unsigned __int8)v138 | (unsigned __int8)v38) & 1) == 0 )
      goto LABEL_263;
    goto LABEL_273;
  }
  v78 = *(_QWORD *)(a2 + 24);
  v79 = *(_DWORD *)(v78 + 1020);
  if ( v79 )
  {
    v80 = *(_DWORD *)(v78 + 1024);
  }
  else
  {
    v81 = readl_relaxed_1(*(_QWORD *)(v78 + 960) + 36LL);
    if ( v81 < 0 )
      v82 = 16;
    else
      v82 = 12;
    if ( v81 < 0 )
      v80 = 0x10000;
    else
      v80 = 4096;
    v79 = 2 << (((unsigned int)v81 >> 28) & 7) << v82;
    *(_DWORD *)(v78 + 1024) = v80;
    *(_DWORD *)(v78 + 1020) = v79;
  }
  v83 = readl_relaxed_1(*(_QWORD *)(v78 + 960) + v79 + (unsigned int)(*(_DWORD *)(a2 + 16) * v80));
  v84 = *(_QWORD *)(a2 + 24);
  v85 = v83;
  v86 = *(_DWORD *)(v84 + 1020);
  if ( v86 )
  {
    v87 = *(_DWORD *)(v84 + 1024);
  }
  else
  {
    v88 = readl_relaxed_1(*(_QWORD *)(v84 + 960) + 36LL);
    if ( v88 < 0 )
      v89 = 16;
    else
      v89 = 12;
    if ( v88 < 0 )
      v87 = 0x10000;
    else
      v87 = 4096;
    v86 = 2 << (((unsigned int)v88 >> 28) & 7) << v89;
    *(_DWORD *)(v84 + 1024) = v87;
    *(_DWORD *)(v84 + 1020) = v86;
  }
  writel_relaxed_2(v85 & 0xFFFFFFBF, *(_QWORD *)(v84 + 960) + v86 + (unsigned int)(*(_DWORD *)(a2 + 16) * v87));
  __dsb(0xEu);
  if ( v138 )
  {
    *(_BYTE *)(a2 + 32) = 1;
    _X8 = (unsigned int *)(a1 + 24392);
    __asm { PRFM            #0x11, [X8] }
    do
      v117 = __ldxr(_X8);
    while ( __stxr(v117 | 8, _X8) );
    __dmb(0xAu);
    kthread_queue_work(*(_QWORD *)(a1 + 24344), a1 + 24352);
    goto LABEL_195;
  }
  if ( _X24 )
  {
    __asm { PRFM            #0x11, [X24] }
    do
      v119 = __ldxr((unsigned int *)_X24);
    while ( __stlxr(v119 - 1, (unsigned int *)_X24) );
    if ( v119 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy(_X24);
    }
    else if ( v119 <= 0 )
    {
      refcount_warn_saturate(_X24, 3);
    }
  }
  kgsl_process_private_put((unsigned int *)v22);
  if ( (v38 & 1) != 0 )
  {
LABEL_273:
    result = 4294967280LL;
    goto LABEL_274;
  }
LABEL_263:
  if ( (*(_QWORD *)(a1 + 48) & 0x40) != 0 )
  {
    if ( a3 >> 39 >= 0x3FF )
      result = 4294967258LL;
    else
      result = 0;
    if ( ((a3 >> 39 < 0x3FF) & (unsigned __int8)v38) != 0 )
      goto LABEL_273;
  }
  else
  {
    v120 = 3932155904LL;
    if ( (*(_QWORD *)(a1 + 48) & 1LL) == 0 )
      v120 = 4160749568LL;
    if ( v120 > a3 )
    {
      if ( (v38 & 1) == 0 )
      {
        result = 0;
        goto LABEL_274;
      }
      goto LABEL_273;
    }
    v122 = 4026527744LL;
    if ( (*(_QWORD *)(a1 + 48) & 1LL) == 0 )
      v122 = 4255121408LL;
    v123 = v122 > a3;
    v124 = v122 <= a3;
    if ( v123 )
      result = 4294967258LL;
    else
      result = 0;
    if ( (v124 & (unsigned int)v38 & 1) != 0 )
      goto LABEL_273;
  }
LABEL_274:
  _ReadStatusReg(SP_EL0);
  return result;
}
