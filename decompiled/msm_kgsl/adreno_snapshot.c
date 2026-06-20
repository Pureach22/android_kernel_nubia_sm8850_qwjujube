unsigned __int64 __fastcall adreno_snapshot(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x9
  __int64 v9; // x27
  __int64 v10; // x25
  __int64 v11; // x9
  unsigned __int64 v12; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x0
  __int64 v16; // x8
  _DWORD *v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  _DWORD *v20; // x8
  __int64 v21; // x0
  __int64 v22; // x23
  size_t v23; // x0
  unsigned __int64 v24; // x2
  __int64 v25; // x23
  int v26; // w26
  __int64 v27; // x23
  __int64 next; // x0
  __int64 v29; // x24
  __int64 v30; // x23
  unsigned int v31; // w26
  __int64 v32; // x0
  bool v33; // cc
  __int64 v34; // x8
  __int64 v35; // x10
  __int64 v36; // x9
  _DWORD *v37; // x8
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x9
  __int64 v41; // x27
  unsigned __int64 v42; // x28
  unsigned int v43; // w9
  char *v44; // x24
  __int64 v45; // x9
  __int64 v46; // x8
  __int64 (__fastcall *v47)(_QWORD); // x8
  unsigned __int64 v48; // x0
  int v54; // w8
  __int64 v55; // x2
  unsigned __int64 v56; // x3
  __int64 v57; // x10
  unsigned int v58; // w8
  __int64 v59; // x8
  __int64 v60; // x10
  unsigned int v61; // w11
  _QWORD *v62; // x21
  __int64 v63; // x2
  unsigned int v64; // w9
  unsigned __int64 v65; // x3
  __int64 v66; // x10
  unsigned int v67; // w8
  __int64 v68; // x8
  __int64 v69; // x11
  unsigned int v70; // w10
  _QWORD *v71; // x21
  unsigned __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // [xsp+8h] [xbp-18h] BYREF
  __int64 v75; // [xsp+10h] [xbp-10h]
  __int64 v76; // [xsp+18h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 88);
  v9 = *(_QWORD *)(a1[1783] + 40LL);
  *(_QWORD *)v8 = -2947743742LL;
  *(_DWORD *)(v8 + 8) = *((_DWORD *)a1 + 3562);
  v10 = *(_QWORD *)(a2 + 88);
  v11 = *(_QWORD *)(a2 + 80);
  v12 = *(_QWORD *)(a2 + 96) - 12LL;
  *(_QWORD *)(a2 + 88) = v10 + 12;
  *(_QWORD *)(a2 + 96) = v12;
  *(_QWORD *)(a2 + 80) = v11 + 12;
  if ( v12 <= 0xA7 )
  {
    if ( (unsigned int)__ratelimit(&adreno_snapshot_os__rs, "adreno_snapshot_os") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "OS");
    goto LABEL_46;
  }
  *(_DWORD *)(v10 + 20) = 515;
  result = strnlen(&bpf_trace_run5[2], 0x20u);
  if ( result >= 0x41 )
    goto LABEL_146;
  if ( result == 32 )
    v14 = 32;
  else
    v14 = result + 1;
  if ( v14 >= 0x21 )
LABEL_147:
    _fortify_panic(7, 32, v14);
  sized_strscpy(v10 + 84, &bpf_trace_run5[2]);
  result = strnlen(&bpf_trace_run5[67], 0x20u);
  if ( result >= 0x41 )
  {
LABEL_146:
    _fortify_panic(2, 65, result + 1);
    goto LABEL_147;
  }
  if ( result == 32 )
    v14 = 32;
  else
    v14 = result + 1;
  if ( v14 >= 0x21 )
    goto LABEL_147;
  v15 = sized_strscpy(v10 + 116, (char *)&trace_print_flags_seq + 3);
  *(_DWORD *)(v10 + 24) = ktime_get_real_seconds(v15);
  *(_DWORD *)(v10 + 28) = a1[1141];
  *(_DWORD *)(v10 + 32) = *((_DWORD *)a1 + 2510);
  *(_DWORD *)(v10 + 36) = a1[1260];
  *(_DWORD *)(v10 + 40) = clk_get_rate(a1[1105]);
  v16 = a1[11];
  if ( v16 && (v17 = *(_DWORD **)(v16 + 24)) != nullptr )
  {
    if ( *(v17 - 1) != -200603286 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(_QWORD *, __int64))v17)(a1 + 7, a3);
  }
  else
  {
    v18 = 0;
  }
  *(_QWORD *)(v10 + 48) = v18;
  v19 = a1[11];
  if ( v19 && (v20 = *(_DWORD **)(v19 + 24)) != nullptr )
  {
    if ( *(v20 - 1) != -200603286 )
      __break(0x8228u);
    v21 = ((__int64 (__fastcall *)(_QWORD *, __int64))v20)(a1 + 7, a4);
  }
  else
  {
    v21 = 0;
  }
  *(_QWORD *)(v10 + 56) = v21;
  *(_DWORD *)(v10 + 80) = 0;
  if ( a3 )
  {
    *(_DWORD *)(v10 + 72) = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(v10 + 64) = *(_DWORD *)(a3 + 12);
    v22 = *(_QWORD *)(a3 + 24);
    v23 = strnlen((const char *)(v22 + 16), 0x10u);
    if ( v23 >= 0x11 )
    {
LABEL_148:
      _fortify_panic(2, 16, v23 + 1);
      goto LABEL_149;
    }
    if ( v23 == 16 )
      v24 = 16;
    else
      v24 = v23 + 1;
    if ( v24 >= 0x11 )
      goto LABEL_149;
    sized_strscpy(v10 + 148, v22 + 16);
  }
  if ( !a4 )
    goto LABEL_40;
  *(_DWORD *)(v10 + 76) = *(_DWORD *)(a4 + 4);
  *(_DWORD *)(v10 + 68) = *(_DWORD *)(a4 + 12);
  v25 = *(_QWORD *)(a4 + 24);
  v23 = strnlen((const char *)(v25 + 16), 0x10u);
  if ( v23 >= 0x11 )
    goto LABEL_148;
  if ( v23 == 16 )
    v24 = 16;
  else
    v24 = v23 + 1;
  if ( v24 < 0x11 )
  {
    sized_strscpy(v10 + 164, v25 + 16);
LABEL_40:
    v26 = *(_DWORD *)(a2 + 96);
    v27 = *(_QWORD *)(a2 + 88);
    raw_read_lock(a1 + 1401);
    LODWORD(v74) = 0;
    next = idr_get_next(a1 + 1398, &v74);
    if ( next && (unsigned int)(v26 + 152) >= 0x10 )
    {
      v29 = next;
      v30 = v27 + 180;
      v31 = v26 + 136;
      do
      {
        kgsl_readtimestamp(a1, v29, 3, v30 - 8);
        kgsl_readtimestamp(a1, v29, 1, v30 - 4);
        kgsl_readtimestamp(a1, v29, 2, v30);
        ++*(_DWORD *)(v10 + 80);
        LODWORD(v74) = v74 + 1;
        v32 = idr_get_next(a1 + 1398, &v74);
        if ( !v32 )
          break;
        v29 = v32;
        v33 = v31 > 0xF;
        v31 -= 16;
        v30 += 16;
      }
      while ( v33 );
    }
    raw_read_unlock(a1 + 1401);
    v34 = (unsigned int)(16 * *(_DWORD *)(v10 + 80) + 168);
    *(_DWORD *)(v10 + 12) = 16886733;
    *(_DWORD *)(v10 + 16) = v34;
    v35 = *(_QWORD *)(a2 + 80);
    v36 = *(_QWORD *)(a2 + 96);
    *(_QWORD *)(a2 + 88) += v34;
    *(_QWORD *)(a2 + 96) = v36 - *(unsigned int *)(v10 + 16);
    *(_QWORD *)(a2 + 80) = v35 + *(unsigned int *)(v10 + 16);
LABEL_46:
    ib_max_objs = 0;
    objbufptr = 0;
    snapshot_frozen_objsize = 0;
    *(_QWORD *)(a2 + 224) = setup_fault_process(a1);
    *(_QWORD *)(a2 + 232) = setup_fault_process(a1);
    kgsl_snapshot_add_section(a1, 2305, a2, adreno_snapshot_sqe, 0);
    result = kgsl_snapshot_add_section(a1, 2305, a2, adreno_snapshot_aqe, 0);
    v37 = *(_DWORD **)(v9 + 16);
    if ( v37 )
    {
      if ( *(v37 - 1) != 474314034 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_QWORD *, __int64))v37)(a1, a2);
    }
    *(_WORD *)(a2 + 36) = 0;
    *(_WORD *)(a2 + 64) = 0;
    v38 = a1[2455];
    v74 = a2;
    v75 = v38;
    if ( v38 )
    {
      result = kgsl_snapshot_add_section(a1, 770, a2, snapshot_rb, &v74);
      v38 = a1[2455];
    }
    v39 = a1[2457];
    if ( v39 != v38 )
    {
      v74 = a2;
      v75 = v39;
      if ( v39 )
      {
        result = kgsl_snapshot_add_section(a1, 770, a2, snapshot_rb, &v74);
        v38 = a1[2457];
      }
      else
      {
        v38 = 0;
      }
    }
    v40 = a1[2456];
    if ( v40 != v38 && v40 != a1[2455] )
    {
      v74 = a2;
      v75 = v40;
      if ( v40 )
        result = kgsl_snapshot_add_section(a1, 770, a2, snapshot_rb, &v74);
    }
    if ( (a1[1413] & 1) != 0 )
      goto LABEL_141;
    kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, a1[5]);
    kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, a1[6]);
    kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, a1[2536]);
    kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, a1[2556]);
    if ( !(unsigned int)kgsl_mmu_get_mmutype(a1) )
    {
      kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, a1[121]);
      if ( (a1[1780] & 0x200) != 0 )
        kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, a1[125]);
    }
    kgsl_snapshot_add_section(a1, 3586, a2, snapshot_capture_mem_list, *(_QWORD *)(a2 + 224));
    kgsl_snapshot_add_section(a1, 3586, a2, snapshot_capture_mem_list, *(_QWORD *)(a2 + 232));
    ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))adreno_static_ib_dump)(
      a1,
      *(_QWORD *)(a2 + 224),
      *(_QWORD *)a2,
      *(_QWORD *)(a2 + 8),
      *(unsigned int *)(a2 + 28),
      *(_QWORD *)(a2 + 16),
      *(unsigned int *)(a2 + 32));
    result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))adreno_static_ib_dump)(
               a1,
               *(_QWORD *)(a2 + 232),
               *(_QWORD *)(a2 + 40),
               *(_QWORD *)(a2 + 48),
               *(unsigned int *)(a2 + 60),
               0,
               0);
    if ( objbufptr )
    {
      v41 = 0;
      v42 = 0;
      do
      {
        v44 = (char *)&objbuf[v41];
        v45 = *(unsigned int *)(a2 + 24);
        metadata = a2;
        qword_17B9D0 = (__int64)&objbuf[v41];
        qword_17B9D8 = *(_QWORD *)a2;
        qword_17B9E0 = v45;
        qword_17B9E8 = *(_QWORD *)(a2 + 8);
        qword_17B9F0 = *(unsigned int *)(a2 + 28);
        qword_17B9F8 = *(_QWORD *)(a2 + 16);
        qword_17BA00 = *(unsigned int *)(a2 + 32);
        qword_17BA08 = *(_QWORD *)(a2 + 40);
        qword_17BA10 = *(unsigned int *)(a2 + 56);
        qword_17BA18 = *(_QWORD *)(a2 + 48);
        qword_17BA20 = *(unsigned int *)(a2 + 60);
        result = kgsl_snapshot_add_section(a1, 1026, a2, snapshot_ib, &metadata);
        if ( v41 == 448 )
          goto LABEL_145;
        if ( (unsigned __int64)(v41 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_144;
        result = *((_QWORD *)v44 + 4);
        if ( result )
        {
          v46 = *(_QWORD *)(result + 72);
          if ( v46 )
          {
            v47 = *(__int64 (__fastcall **)(_QWORD))(v46 + 32);
            if ( v47 )
            {
              v48 = result + 8;
              if ( *((_DWORD *)v47 - 1) != 1555154090 )
                __break(0x8228u);
              result = v47(v48);
              if ( (unsigned __int64)(v41 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
              {
LABEL_144:
                __break(1u);
                goto LABEL_145;
              }
              result = *((_QWORD *)v44 + 4);
            }
          }
          if ( result && result <= 0xFFFFFFFFFFFFF000LL )
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v54 = __ldxr((unsigned int *)result);
            while ( __stlxr(v54 - 1, (unsigned int *)result) );
            if ( v54 == 1 )
            {
              __dmb(9u);
              result = kgsl_mem_entry_destroy();
            }
            else if ( v54 <= 0 )
            {
              result = refcount_warn_saturate(result, 3);
            }
          }
        }
        ++v42;
        v41 += 7;
        v43 = objbufptr;
      }
      while ( v42 < (unsigned int)objbufptr );
      if ( (*(_BYTE *)(a2 + 36) & 1) == 0 )
      {
        v74 = 0;
        if ( !objbufptr )
          goto LABEL_112;
        v59 = *(_QWORD *)a2;
        v55 = *(_QWORD *)(a2 + 224);
        v60 = 0;
        v61 = 0;
        while ( 1 )
        {
          if ( v60 == 448 )
            goto LABEL_145;
          if ( objbuf[v60] == v59 )
          {
            if ( (unsigned __int64)(v60 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
              goto LABEL_144;
            if ( *(_QWORD *)(objbuf[v60 + 4] + 256LL) == v55 )
              break;
          }
          v60 += 7;
          ++v61;
          if ( 7LL * (unsigned int)objbufptr == v60 )
            goto LABEL_90;
        }
        if ( v61 >= 0x40 )
          goto LABEL_145;
        v62 = &objbuf[7 * (v61 & 0x3F)];
        if ( v59 == *v62 )
        {
          result = adreno_ib_create_object_list(
                     (__int64)a1,
                     *(_QWORD *)(v62[4] + 256LL),
                     *(_QWORD *)a2,
                     v62[1] >> 2,
                     *(_QWORD *)(a2 + 8),
                     &v74);
          if ( (_DWORD)result == -7 )
            ib_max_objs = 1;
          if ( v74 )
          {
            snapshot_freeze_obj_list(a2, *(_QWORD *)(v62[4] + 256LL));
            result = adreno_ib_destroy_obj_list(v74);
          }
          goto LABEL_112;
        }
LABEL_90:
        if ( v43 )
        {
          v56 = *(_QWORD *)(a2 + 8);
          v57 = 0;
          v58 = 0;
          while ( 1 )
          {
            if ( v57 == 448 )
              goto LABEL_145;
            if ( objbuf[v57] == v56 )
            {
              if ( (unsigned __int64)(v57 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
                goto LABEL_144;
              if ( *(_QWORD *)(objbuf[v57 + 4] + 256LL) == v55 )
                break;
            }
            v57 += 7;
            ++v58;
            if ( 7LL * v43 == v57 )
              goto LABEL_112;
          }
          if ( v58 > 0x3F )
            goto LABEL_145;
          result = adreno_parse_ib(a1, a2, v55, v56, objbuf[7 * (v58 & 0x3F) + 1] >> 2);
        }
LABEL_112:
        if ( ib_max_objs == 1 )
          result = dev_err(*a1, "Max objects found in GC IB\n");
        if ( *(_BYTE *)(a2 + 64) == 1 )
        {
          if ( (*(_BYTE *)(a2 + 65) & 1) != 0 )
            goto LABEL_139;
          v63 = *(_QWORD *)(a2 + 232);
          v64 = objbufptr;
LABEL_117:
          if ( !v64 )
            goto LABEL_139;
          v65 = *(_QWORD *)(a2 + 48);
          v66 = 0;
          v67 = 0;
          while ( 1 )
          {
            if ( v66 == 448 )
              goto LABEL_145;
            if ( objbuf[v66] == v65 )
            {
              if ( (unsigned __int64)(v66 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
                goto LABEL_144;
              if ( *(_QWORD *)(objbuf[v66 + 4] + 256LL) == v63 )
                break;
            }
            v66 += 7;
            ++v67;
            if ( 7LL * v64 == v66 )
              goto LABEL_139;
          }
          if ( v67 <= 0x3F )
          {
            result = adreno_parse_ib_lpac(a1, a2, v63, v65, objbuf[7 * (v67 & 0x3F) + 1] >> 2);
            goto LABEL_139;
          }
          goto LABEL_145;
        }
        v74 = 0;
        v64 = objbufptr;
        if ( !objbufptr )
        {
LABEL_139:
          if ( ib_max_objs == 1 )
          {
            result = dev_err(*a1, "Max objects found in LPAC IB\n");
            v72 = snapshot_frozen_objsize;
            if ( !snapshot_frozen_objsize )
              goto LABEL_141;
          }
          else
          {
            v72 = snapshot_frozen_objsize;
            if ( !snapshot_frozen_objsize )
            {
LABEL_141:
              _ReadStatusReg(SP_EL0);
              return result;
            }
          }
          result = dev_err(*a1, "GPU snapshot froze %zdKb of GPU buffers\n", v72 >> 10);
          goto LABEL_141;
        }
        v68 = *(_QWORD *)(a2 + 40);
        v63 = *(_QWORD *)(a2 + 232);
        v69 = 0;
        v70 = 0;
        while ( 1 )
        {
          if ( v69 == 448 )
            goto LABEL_145;
          if ( objbuf[v69] == v68 )
          {
            if ( (unsigned __int64)(v69 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
              goto LABEL_144;
            if ( *(_QWORD *)(objbuf[v69 + 4] + 256LL) == v63 )
              break;
          }
          v69 += 7;
          ++v70;
          if ( 7LL * (unsigned int)objbufptr == v69 )
            goto LABEL_117;
        }
        if ( v70 < 0x40 )
        {
          v71 = &objbuf[7 * (v70 & 0x3F)];
          if ( v68 != *v71 )
            goto LABEL_117;
          result = adreno_ib_create_object_list(
                     (__int64)a1,
                     *(_QWORD *)(v71[4] + 256LL),
                     *(_QWORD *)(a2 + 40),
                     v71[1] >> 2,
                     *(_QWORD *)(a2 + 48),
                     &v74);
          if ( (_DWORD)result == -7 )
            ib_max_objs = 1;
          if ( v74 )
          {
            snapshot_freeze_obj_list(a2, *(_QWORD *)(v71[4] + 256LL));
            result = adreno_ib_destroy_obj_list(v74);
          }
          goto LABEL_139;
        }
LABEL_145:
        __break(0x5512u);
        goto LABEL_146;
      }
      if ( (*(_BYTE *)(a2 + 37) & 1) != 0 )
        goto LABEL_112;
    }
    else
    {
      if ( (*(_BYTE *)(a2 + 36) & 1) == 0 )
        goto LABEL_112;
      v43 = 0;
      if ( (*(_BYTE *)(a2 + 37) & 1) != 0 )
        goto LABEL_112;
    }
    v55 = *(_QWORD *)(a2 + 224);
    v74 = 0;
    goto LABEL_90;
  }
LABEL_149:
  v73 = _fortify_panic(7, 16, v24);
  return setup_fault_process(v73);
}
