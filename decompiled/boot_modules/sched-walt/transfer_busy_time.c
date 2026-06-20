_DWORD *__fastcall transfer_busy_time(_DWORD *result, char *a2, __int64 a3, char *a4)
{
  char *v4; // x20
  __int64 v5; // x21
  __int64 *v6; // x24
  int v7; // w22
  _QWORD *v8; // x23
  __int64 v9; // x1
  __int64 v10; // x6
  __int64 v11; // x8
  unsigned __int64 v12; // x14
  unsigned __int64 v13; // x19
  __int64 v14; // x2
  _QWORD *v15; // x28
  unsigned __int64 *v16; // x27
  unsigned __int64 v17; // x4
  unsigned __int64 v18; // x5
  unsigned __int64 v19; // x19
  char *v20; // x8
  _QWORD *v21; // x19
  unsigned __int64 v22; // x5
  unsigned __int64 v23; // x4
  unsigned __int64 v24; // x22
  char *v25; // x8
  unsigned __int64 v26; // x5
  unsigned __int64 v27; // x4
  unsigned __int64 v28; // x19
  char *v29; // x8
  unsigned __int64 v30; // x5
  unsigned __int64 v31; // x4
  unsigned __int64 v32; // x22
  char *v33; // x8
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x10
  unsigned __int64 v36; // x8
  bool v37; // cf
  __int64 v38; // x8
  unsigned __int64 v39; // x8
  __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  __int64 v43; // x8
  char *v44; // x22
  unsigned __int64 v45; // x5
  unsigned __int64 v46; // x19
  char *v47; // x8
  _QWORD *v48; // x19
  char *v49; // x26
  unsigned __int64 v50; // x4
  unsigned __int64 v51; // x5
  unsigned __int64 v52; // x25
  char *v53; // x8
  unsigned __int64 v54; // x5
  unsigned __int64 v55; // x4
  unsigned __int64 v56; // x19
  char *v57; // x8
  unsigned __int64 v58; // x5
  unsigned __int64 v59; // x4
  unsigned __int64 v60; // x25
  char *v61; // x8
  unsigned __int64 v62; // x9
  unsigned __int64 v63; // x10
  unsigned __int64 v64; // x8
  __int64 v65; // x8
  unsigned __int64 v66; // x8
  __int64 v67; // x8
  unsigned __int64 v68; // x8
  unsigned __int64 v69; // x9
  __int64 v70; // x8
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x10
  unsigned __int64 v73; // x12
  _QWORD *v74; // x25
  _QWORD *v75; // x26
  unsigned __int64 v76; // x9
  __int64 *v77; // x22
  unsigned __int64 v78; // x12
  unsigned __int64 v79; // x8
  unsigned __int64 v80; // x10
  unsigned __int64 v81; // x8
  unsigned __int64 v82; // x19
  __int64 v83; // x9
  char *v84; // x9
  unsigned __int64 v85; // x22
  unsigned __int64 v86; // x25
  unsigned __int64 v87; // x25
  unsigned __int64 v88; // x22
  unsigned __int64 v89; // x25
  unsigned __int64 v90; // x25
  unsigned __int64 v91; // x27
  unsigned __int64 StatusReg; // x19
  __int64 v93; // x8
  __int64 v94; // x0
  __int64 v95; // x1
  unsigned __int64 v96; // [xsp+10h] [xbp-10h]
  _DWORD *v97; // [xsp+18h] [xbp-8h]

  v5 = (unsigned int)result[908];
  v97 = result;
  if ( (unsigned int)v5 >= 0x20 )
    goto LABEL_129;
  v4 = a2;
  v6 = (__int64 *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v5));
  v7 = a3;
  if ( a2 == (char *)&init_task )
    v8 = &vendor_data_pad;
  else
    v8 = a2 + 5184;
  result = (_DWORD *)walt_update_task_ravg((unsigned __int64)a2, result, 4u, a4, nullptr);
  v10 = v8[2];
  v11 = v6[8];
  if ( v10 != v11 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      result = (_DWORD *)printk_deferred(
                           "WALT-BUG CPU%d: %s event=%d task %s(%d)'s ws=%llu not equal to rq %d's ws=%llu",
                           *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                           "transfer_busy_time",
                           v7,
                           v4 + 2320,
                           *((_DWORD *)v4 + 450),
                           v10,
                           v97[908],
                           v11);
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_12;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_12;
    }
    if ( v4 )
      result = (_DWORD *)walt_task_dump((unsigned __int64 *)v4);
    if ( !in_sched_bug )
    {
      in_sched_bug = 1;
      walt_dump();
      __break(0x800u);
      goto LABEL_134;
    }
  }
LABEL_12:
  v12 = v8[21];
  if ( *((_BYTE *)v8 + 360) )
  {
    v13 = v8[21];
    if ( walt_clock_suspended == 1 )
      v14 = sched_clock_last;
    else
      v14 = sched_clock(result, v9);
    result = (_DWORD *)migrate_busy_time_addition(v4, (unsigned int)v97[908], v14);
    v12 = v13;
    *((_BYTE *)v8 + 360) = 0;
  }
  v15 = v6 + 22;
  v16 = (unsigned __int64 *)(v6 + 18);
  if ( v7 )
  {
    v17 = v6[22];
    v18 = *((unsigned int *)v8 + 33);
    if ( v17 >= v18 || (sysctl_panic_on_walt_bug & 0xFFFFFF00) != 0x4544DE00 )
      goto LABEL_24;
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      v85 = v12;
      result = (_DWORD *)printk_deferred(
                           "WALT-BUG WALT-UG pid=%u CPU=%d event=%d src_crs=%llu is lesser than task_contrib=%u",
                           *((_DWORD *)v4 + 450),
                           v5,
                           1,
                           v17,
                           v18);
      v12 = v85;
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_24;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_24;
    }
    if ( v4 )
    {
      v19 = v12;
      result = (_DWORD *)walt_task_dump((unsigned __int64 *)v4);
      v12 = v19;
    }
    v20 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( in_sched_bug )
    {
LABEL_24:
      v21 = v6 + 23;
      v22 = *((unsigned int *)v8 + 34);
      v23 = v6[23];
      if ( v23 < v22 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
      {
        if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
        {
          v86 = v12;
          result = (_DWORD *)printk_deferred(
                               "WALT-BUG pid=%u CPU=%d event=%d src_prs=%llu is lesser than task_contrib=%u",
                               *((_DWORD *)v4 + 450),
                               v5,
                               1,
                               v23,
                               v22);
          v12 = v86;
          if ( (sysctl_panic_on_walt_bug & 2) != 0 )
          {
LABEL_28:
            if ( v4 )
            {
              v24 = v12;
              result = (_DWORD *)walt_task_dump((unsigned __int64 *)v4);
              v12 = v24;
            }
            v25 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            if ( in_sched_bug )
              goto LABEL_31;
            goto LABEL_135;
          }
        }
        else if ( (sysctl_panic_on_walt_bug & 2) != 0 )
        {
          goto LABEL_28;
        }
      }
LABEL_31:
      v26 = *((unsigned int *)v8 + 33);
      if ( v12 > 0x5F5E0FF )
      {
        v71 = *v15 - v26;
        if ( *v15 < v26 )
          v71 = 0;
        *v15 = v71;
        goto LABEL_93;
      }
      v27 = v6[24];
      if ( v27 >= v26 || (sysctl_panic_on_walt_bug & 0xFFFFFF00) != 0x4544DE00 )
        goto LABEL_39;
      if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
      {
        v88 = v12;
        result = (_DWORD *)printk_deferred(
                             "WALT-BUG pid=%u CPU=%d event=%d src_nt_crs=%llu is lesser than task_contrib=%u",
                             *((_DWORD *)v4 + 450),
                             v5,
                             1,
                             v27,
                             v26);
        v12 = v88;
        if ( (sysctl_panic_on_walt_bug & 2) == 0 )
          goto LABEL_39;
      }
      else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
      {
        goto LABEL_39;
      }
      if ( v4 )
      {
        v28 = v12;
        result = (_DWORD *)walt_task_dump((unsigned __int64 *)v4);
        v12 = v28;
      }
      v29 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      if ( in_sched_bug )
      {
LABEL_39:
        v21 = v6 + 25;
        v30 = *((unsigned int *)v8 + 34);
        v31 = v6[25];
        if ( v31 < v30 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
        {
          if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
          {
            v89 = v12;
            result = (_DWORD *)printk_deferred(
                                 "WALT-BUG pid=%u CPU=%d event=%d src_nt_prs=%llu is lesser than task_contrib=%u",
                                 *((_DWORD *)v4 + 450),
                                 v5,
                                 1,
                                 v31,
                                 v30);
            v12 = v89;
            if ( (sysctl_panic_on_walt_bug & 2) != 0 )
            {
LABEL_43:
              if ( v4 )
              {
                v32 = v12;
                result = (_DWORD *)walt_task_dump((unsigned __int64 *)v4);
                v12 = v32;
              }
              v33 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
              if ( in_sched_bug )
                goto LABEL_46;
              goto LABEL_139;
            }
          }
          else if ( (sysctl_panic_on_walt_bug & 2) != 0 )
          {
            goto LABEL_43;
          }
        }
LABEL_46:
        v34 = v6[22];
        v35 = v6[23];
        v36 = *((unsigned int *)v8 + 33);
        v37 = v34 >= v36;
        v38 = v34 - v36;
        if ( !v37 )
          v38 = 0;
        v6[22] = v38;
        v39 = *((unsigned int *)v8 + 34);
        v37 = v35 >= v39;
        v40 = v35 - v39;
        if ( !v37 )
          v40 = 0;
        v6[23] = v40;
        v41 = v6[24];
        v42 = *((unsigned int *)v8 + 33);
        v37 = v41 >= v42;
        v43 = v41 - v42;
        if ( !v37 )
          v43 = 0;
        v6[24] = v43;
LABEL_93:
        v72 = *((unsigned int *)v8 + 34);
        v73 = _cpu_possible_mask;
        v74 = v6 + 19;
        v75 = v6 + 20;
        v76 = *v21 - v72;
        v77 = v6 + 21;
        if ( *v21 < v72 )
          v76 = 0;
        *v21 = v76;
        if ( v73 )
        {
          do
          {
            v78 = __clz(__rbit64(v73));
            if ( v78 > 7 )
              goto LABEL_129;
            *((_DWORD *)v8 + v78 + 17) = 0;
            *((_DWORD *)v8 + v78 + 25) = 0;
            v73 = (unsigned int)(-2LL << v78) & _cpu_possible_mask;
          }
          while ( (_DWORD)v73 );
        }
        a3 = 0;
        v15 = v6 + 18;
        goto LABEL_105;
      }
LABEL_138:
      *((_DWORD *)v29 + 815) = 1;
      walt_dump();
      __break(0x800u);
LABEL_139:
      *((_DWORD *)v33 + 815) = 1;
      walt_dump();
      __break(0x800u);
LABEL_140:
      *((_DWORD *)v57 + 815) = 1;
      walt_dump();
      __break(0x800u);
LABEL_141:
      *((_DWORD *)v61 + 815) = 1;
      v94 = walt_dump();
      __break(0x800u);
      return (_DWORD *)set_preferred_cluster(v94, v95);
    }
LABEL_134:
    *((_DWORD *)v20 + 815) = 1;
    walt_dump();
    __break(0x800u);
LABEL_135:
    *((_DWORD *)v25 + 815) = 1;
    walt_dump();
    __break(0x800u);
LABEL_136:
    *((_DWORD *)v47 + 815) = 1;
    walt_dump();
    __break(0x800u);
LABEL_137:
    *((_DWORD *)v53 + 815) = 1;
    walt_dump();
    __break(0x800u);
    goto LABEL_138;
  }
  if ( (unsigned int)v5 > 7 )
    goto LABEL_129;
  v44 = (char *)v8 + 68;
  v45 = *((unsigned int *)v8 + v5 + 17);
  if ( *v16 < v45 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      v87 = v12;
      printk_deferred(
        "WALT-BUG pid=%u CPU=%d event=%d src_crs=%llu is lesser than task_contrib=%u",
        *((_DWORD *)v4 + 450),
        v5,
        0,
        *v16,
        v45);
      v12 = v87;
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_61;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_61;
    }
    if ( v4 )
    {
      v46 = v12;
      walt_task_dump((unsigned __int64 *)v4);
      v12 = v46;
    }
    v47 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( !in_sched_bug )
      goto LABEL_136;
  }
LABEL_61:
  v48 = v6 + 19;
  v49 = (char *)v8 + 100;
  v50 = v6[19];
  v51 = *((unsigned int *)v8 + v5 + 25);
  if ( v50 < v51 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      v96 = v12;
      printk_deferred(
        "WALT-BUG pid=%u CPU=%d event=%d src_prs=%llu is lesser than task_contrib=%u",
        *((_DWORD *)v4 + 450),
        v5,
        0,
        v50,
        v51);
      v12 = v96;
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_68;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_68;
    }
    if ( v4 )
    {
      v52 = v12;
      walt_task_dump((unsigned __int64 *)v4);
      v12 = v52;
    }
    v53 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( !in_sched_bug )
      goto LABEL_137;
  }
LABEL_68:
  v54 = *(unsigned int *)&v44[4 * v5];
  if ( v12 > 0x5F5E0FF )
  {
    v79 = *v16 - v54;
    if ( *v16 < v54 )
      v79 = 0;
    *v16 = v79;
    goto LABEL_102;
  }
  v55 = v6[20];
  if ( v55 < v54 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      v90 = v12;
      printk_deferred(
        "WALT-BUG pid=%u CPU=%d event=%d src_nt_crs=%llu is lesser than task_contrib=%u",
        *((_DWORD *)v4 + 450),
        v5,
        0,
        v55,
        v54);
      v12 = v90;
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_76;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_76;
    }
    if ( v4 )
    {
      v56 = v12;
      walt_task_dump((unsigned __int64 *)v4);
      v12 = v56;
    }
    v57 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( !in_sched_bug )
      goto LABEL_140;
  }
LABEL_76:
  v48 = v6 + 21;
  v58 = *(unsigned int *)&v49[4 * v5];
  v59 = v6[21];
  if ( v59 < v58 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      v91 = v12;
      printk_deferred(
        "WALT-BUG pid=%u CPU=%d event=%d src_nt_prs=%llu is lesser than task_contrib=%u",
        *((_DWORD *)v4 + 450),
        v5,
        0,
        v59,
        v58);
      v12 = v91;
      if ( (sysctl_panic_on_walt_bug & 2) != 0 )
      {
LABEL_80:
        if ( v4 )
        {
          v60 = v12;
          walt_task_dump((unsigned __int64 *)v4);
          v12 = v60;
        }
        v61 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
        if ( !in_sched_bug )
          goto LABEL_141;
      }
    }
    else if ( (sysctl_panic_on_walt_bug & 2) != 0 )
    {
      goto LABEL_80;
    }
  }
  v62 = v6[18];
  v63 = v6[19];
  v64 = *(unsigned int *)&v44[4 * v5];
  v37 = v62 >= v64;
  v65 = v62 - v64;
  if ( !v37 )
    v65 = 0;
  v6[18] = v65;
  v66 = *(unsigned int *)&v49[4 * v5];
  v37 = v63 >= v66;
  v67 = v63 - v66;
  if ( !v37 )
    v67 = 0;
  v6[19] = v67;
  v68 = v6[20];
  v69 = *(unsigned int *)&v44[4 * v5];
  v37 = v68 >= v69;
  v70 = v68 - v69;
  if ( !v37 )
    v70 = 0;
  v6[20] = v70;
LABEL_102:
  v80 = *(unsigned int *)&v49[4 * v5];
  v74 = v6 + 23;
  v75 = v6 + 24;
  v81 = *v48 - v80;
  v77 = v6 + 25;
  if ( *v48 < v80 )
    v81 = 0;
  *v48 = v81;
  v82 = v12;
  result = (_DWORD *)update_cluster_load_subtractions(v4, v5, v6[8], v12 < 0x5F5E100);
  v12 = v82;
  a3 = 1;
LABEL_105:
  *v15 += *((unsigned int *)v8 + 33);
  *v74 += *((unsigned int *)v8 + 34);
  if ( v12 <= 0x5F5E0FF )
  {
    v83 = *v77;
    *v75 += *((unsigned int *)v8 + 33);
    *v77 = v83 + *((unsigned int *)v8 + 34);
  }
  if ( (unsigned int)v5 <= 7 )
  {
    v84 = (char *)v8 + 4 * v5;
    *((_DWORD *)v84 + 17) = *((_DWORD *)v8 + 33);
    *((_DWORD *)v84 + 25) = *((_DWORD *)v8 + 34);
    return result;
  }
LABEL_129:
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    result = (_DWORD *)_traceiter_sched_migration_update_sum(0, v4, a3, v97);
    v93 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v93;
    if ( !v93 || !*(_QWORD *)(StatusReg + 16) )
      return (_DWORD *)preempt_schedule_notrace(result);
  }
  return result;
}
