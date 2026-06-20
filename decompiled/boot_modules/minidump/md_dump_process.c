void md_dump_process()
{
  __int64 v0; // x18
  __int64 v1; // x21
  __int64 v2; // x22
  __int64 v3; // x23
  __int64 v4; // x24
  __int64 v5; // x26
  __int64 v6; // x27
  __int64 v7; // x28
  int v9; // w8
  unsigned int v14; // w11
  unsigned __int64 StatusReg; // x19
  void *v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x13
  __int64 v30; // x14
  __int64 v31; // x15
  __int64 v32; // x16
  __int64 v33; // x17
  __int64 v34; // x30
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  char v37; // w8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x23
  _QWORD *v40; // x8
  __int64 v41; // x20
  __int64 v42; // x28
  __int64 v43; // x21
  __int64 v44; // x24
  __int64 v46; // x0
  __int64 v47; // x1
  __int64 v48; // x2
  __int64 v49; // x3
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  __int64 v54; // x19
  char v55; // w8
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x22
  char v58; // w8
  __int64 v59; // x0
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x26
  char *v62; // x23
  __int64 v63; // x27
  __int64 v64; // x20
  __int64 v65; // x0
  int v66; // w8
  __int64 v67; // x28
  int v68; // w20
  unsigned __int64 *v69; // x27
  __int64 v70; // x28
  unsigned __int64 v71; // x20
  unsigned __int64 v72; // x8
  char *v73; // x23
  int next_bit; // w0
  char *v75; // x22
  char *i; // x24
  _QWORD *j; // x20
  __int64 v78; // x8
  __int64 *v79; // x25
  int v80; // w9
  int v81; // w8
  unsigned int v82; // w9
  unsigned int v83; // w8
  _QWORD *v84; // x22
  __int64 v85; // x0
  _QWORD *v86; // x25
  __int64 v87; // x8
  __int64 v88; // x8
  __int64 *v89; // x19
  __int64 *v90; // t1
  __int64 v91; // x0
  _QWORD v92[44]; // [xsp+0h] [xbp-160h] BYREF
  __int64 vars0; // [xsp+160h] [xbp+0h] BYREF

  v92[42] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (md_in_oops_handler & 1) != 0 )
    goto LABEL_81;
  _X9 = &md_handle_done;
  v9 = md_handle_done;
  do
  {
    if ( v9 == 1 )
      goto LABEL_81;
    __asm { PRFM            #0x11, [X9] }
    while ( 1 )
    {
      v14 = __ldxr((unsigned int *)&md_handle_done);
      if ( v14 != v9 )
        break;
      if ( !__stlxr(v9 + 1, (unsigned int *)&md_handle_done) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v14 == v9;
    v9 = v14;
  }
  while ( !_ZF );
  md_in_oops_handler = 1;
  if ( md_cntxt_seq_buf )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( *(_DWORD *)(StatusReg + 40) != die_cpu )
    {
      v16 = memset(v92, 0, 0x150u);
      v92[0] = v16;
      v92[1] = v17;
      v92[2] = v18;
      v92[3] = v19;
      v92[4] = v20;
      v92[5] = v21;
      v92[6] = v22;
      v92[7] = v23;
      v92[8] = v24;
      v92[9] = v25;
      v92[10] = v26;
      v92[11] = v27;
      v92[12] = v28;
      v92[13] = v29;
      v92[14] = v30;
      v92[15] = v31;
      v92[16] = v32;
      v92[17] = v33;
      v92[18] = v0;
      v92[19] = StatusReg;
      v92[20] = v92;
      v92[21] = v1;
      v92[22] = v2;
      v92[23] = v3;
      v92[24] = v4;
      v92[25] = &loc_F000;
      v92[26] = v5;
      v92[27] = v6;
      v92[28] = v7;
      v92[29] = &vars0;
      v92[30] = v34;
      v92[31] = v92;
      v35 = _ReadStatusReg(CurrentEL);
      v36 = v35 | _ReadStatusReg(SPSel);
      v92[32] = &loc_73A0;
      v92[33] = v36
              | _ReadStatusReg(DAIF)
              | ((unsigned __int64)_VF << 28)
              | ((unsigned __int64)_CF << 29)
              | ((unsigned __int64)_ZF << 30)
              | ((unsigned __int64)_NF << 31);
      seq_buf_printf(md_cntxt_seq_buf, "PANIC CPU : %d\n", *(_DWORD *)(StatusReg + 40));
      if ( (v92[33] & 0xF) != 0 )
      {
        if ( v92[32] )
        {
          md_dump_data(v92[32] - 128LL, "PC");
          md_dump_data(v92[30] - 128LL, "LR");
          md_dump_data(v92[31] - 128LL, &unk_11357E);
        }
      }
    }
    v37 = 0;
    do
    {
      v38 = (unsigned int)(-1LL << v37) & _cpu_possible_mask;
      if ( !(_DWORD)v38 )
        break;
      v39 = __clz(__rbit64(v38));
      v40 = (_QWORD *)((char *)&regs_before_stop + _per_cpu_offset[v39]);
      v41 = v40[30];
      v42 = v40[31];
      v44 = v40[32];
      v43 = v40[33];
      seq_buf_printf(md_cntxt_seq_buf, "\nSTOPPED CPU : %d\n", v39);
      _ZF = (v43 & 0xF) == 0 || v44 == 0;
      if ( !_ZF )
      {
        md_dump_data(v44 - 128, "PC");
        md_dump_data(v41 - 128, "LR");
        md_dump_data(v42 - 128, &unk_11357E);
      }
      v37 = v39 + 1;
    }
    while ( v39 < 0x1F );
  }
  v46 = debug_symbol_lookup_name("tick_cpu_device");
  if ( v46 )
  {
    v54 = v46;
    v55 = 0;
    do
    {
      v56 = (unsigned int)(-1LL << v55) & _cpu_possible_mask;
      if ( !(_DWORD)v56 )
        break;
      v57 = __clz(__rbit64(v56));
      if ( *(_QWORD *)(_per_cpu_offset[v57] + v54) )
        printk(&unk_113583, (unsigned int)v57);
      else
        printk(&unk_113CFA, (unsigned int)v57);
      v55 = v57 + 1;
    }
    while ( v57 < 0x1F );
  }
  if ( !md_runq_seq_buf )
    goto LABEL_69;
  v58 = 0;
  while ( 1 )
  {
    v59 = md_runq_seq_buf;
    v60 = (unsigned int)(-1LL << v58) & _cpu_possible_mask;
    if ( !(_DWORD)v60 )
      break;
    v61 = __clz(__rbit64(v60));
    v62 = (char *)&runqueues + _per_cpu_offset[v61];
    seq_buf_printf(
      md_runq_seq_buf,
      "CPU%d has %d process, current is pid %d\n",
      v61,
      *((_DWORD *)v62 + 1),
      *(_DWORD *)(*((_QWORD *)v62 + 418) + 1800LL));
    seq_buf_printf(md_runq_seq_buf, "CFS has %d process\n", *((_DWORD *)v62 + 132));
    v63 = *(_QWORD *)((char *)&runqueues + _per_cpu_offset[v61] + 3344);
    md_dump_cgroup_state("curr", *((_QWORD *)v62 + 74), v63);
    md_dump_cgroup_state("next", *((_QWORD *)v62 + 75), v63);
    v64 = *((_QWORD *)v62 + 73);
    v65 = rb_first(v62 + 576);
    if ( v64 && v65 )
    {
      v66 = -199;
      do
      {
        v67 = v65;
        v68 = v66;
        md_dump_cgroup_state("pend", v65 - 16, v63);
        v65 = rb_next(v67);
        if ( !v65 )
          break;
        v66 = v68 + 1;
      }
      while ( v68 );
    }
    v69 = (unsigned __int64 *)(v62 + 1024);
    seq_buf_printf(md_runq_seq_buf, "RT has %d process\n", *((_DWORD *)v62 + 660));
    v70 = *(_QWORD *)((char *)&runqueues + _per_cpu_offset[v61] + 3344);
    if ( find_first_bit(v62 + 1024, 100) != 100 )
    {
      if ( *v69 )
      {
        v71 = __clz(__rbit64(*v69));
        goto LABEL_45;
      }
      v72 = __clz(__rbit64(*((_QWORD *)v62 + 129)));
      if ( v72 <= 0x23 )
      {
        v71 = v72 + 64;
LABEL_45:
        v73 = v62 + 1040;
        do
        {
          if ( v71 >= 0x65 )
          {
            __break(0x5512u);
LABEL_83:
            __break(1u);
          }
          v75 = &v73[16 * v71];
          for ( i = *(char **)v75; i != v75; i = *(char **)i )
            md_dump_task_info(i - 512, "pend", v70);
          next_bit = find_next_bit(v69, 100, v71 + 1);
          v71 = (unsigned int)next_bit;
        }
        while ( next_bit < 100 );
      }
    }
    seq_buf_printf(md_runq_seq_buf, "\n");
    v58 = v61 + 1;
    if ( v61 >= 0x1F )
    {
      v59 = md_runq_seq_buf;
      break;
    }
  }
  seq_buf_printf(v59, "%-15s", "Task name");
  seq_buf_printf(md_runq_seq_buf, "%*s", 6, "PID");
  seq_buf_printf(md_runq_seq_buf, "%*s", 16, "Exec_started_at");
  seq_buf_printf(md_runq_seq_buf, "%*s", 16, "Last_queued_at");
  seq_buf_printf(md_runq_seq_buf, "%*s", 16, "Total_wait_time");
  seq_buf_printf(md_runq_seq_buf, "%*s", 12, "Exec_times");
  seq_buf_printf(md_runq_seq_buf, "%*s", 4, "CPU");
  seq_buf_printf(md_runq_seq_buf, "%*s", 5, "Prio");
  seq_buf_printf(md_runq_seq_buf, "%*s", 6, "State");
  seq_buf_printf(md_runq_seq_buf, "%*s", 17, "Last_enqueued_ts");
  seq_buf_printf(md_runq_seq_buf, "%*s", 16, "Last_sleep_ts");
  seq_buf_printf(md_runq_seq_buf, "\n");
  for ( j = (_QWORD *)init_task[199]; j - 199 != init_task; j = (_QWORD *)*j )
  {
    v78 = j[100];
    v79 = *(__int64 **)(v78 + 16);
    if ( v79 != (__int64 *)(v78 + 16) )
    {
      v80 = task_info;
      do
      {
        if ( v80 || !*((_DWORD *)v79 - 482) )
        {
          seq_buf_printf(md_runq_seq_buf, "%-15s", (const char *)v79 + 344);
          seq_buf_printf(md_runq_seq_buf, "%6d", *((_DWORD *)v79 - 44));
          seq_buf_printf(md_runq_seq_buf, "%16lld", *(v79 - 50));
          seq_buf_printf(md_runq_seq_buf, "%16lld", *(v79 - 49));
          seq_buf_printf(md_runq_seq_buf, "%16lld", *(v79 - 51));
          seq_buf_printf(md_runq_seq_buf, "%12ld", *(v79 - 52));
          seq_buf_printf(md_runq_seq_buf, "%4d", *((_DWORD *)v79 - 484));
          seq_buf_printf(md_runq_seq_buf, "%5d", *((_DWORD *)v79 - 457));
          v81 = *((_DWORD *)v79 - 482);
          v82 = 32 - __clz(((unsigned __int8)*((_DWORD *)v79 - 70) | (unsigned __int8)v81) & 0x7F);
          if ( v81 == 1026 )
            v83 = 8;
          else
            v83 = v82;
          if ( v83 > 8 )
            goto LABEL_83;
          seq_buf_printf(md_runq_seq_buf, "%*s", 6, task_state_array[v83]);
          if ( v79 - 247 == init_task )
            v84 = &vendor_data_pad;
          else
            v84 = v79 + 401;
          seq_buf_printf(md_runq_seq_buf, "%17llu", v84[29]);
          seq_buf_printf(md_runq_seq_buf, "%16llu", v84[26]);
          seq_buf_printf(md_runq_seq_buf, "\n");
          v80 = task_info;
          v78 = j[100];
        }
        else
        {
          v80 = 0;
        }
        v79 = (__int64 *)*v79;
      }
      while ( v79 != (__int64 *)(v78 + 16) );
    }
  }
LABEL_69:
  v85 = md_ktask_stack_buf;
  if ( md_ktask_stack_buf )
  {
    v86 = (_QWORD *)init_task[199];
    if ( v86 - 199 != init_task )
    {
      do
      {
        v87 = v86[100];
        v90 = *(__int64 **)(v87 + 16);
        v88 = v87 + 16;
        v89 = v90;
        while ( v89 != (__int64 *)v88 )
        {
          v91 = md_ktask_stack_buf;
          if ( (*(_DWORD *)(v89 - 241) & 0x502) == 2 )
          {
            seq_buf_printf(md_ktask_stack_buf, "Task blocked for %ld seconds!", (jiffies - v89[47]) / 0xFAuLL);
            v91 = md_ktask_stack_buf;
          }
          seq_buf_printf(v91, "%d [%s]\n", *((_DWORD *)v89 - 44), (const char *)v89 + 344);
          arch_stack_walk(dump_trace, 0, v89 - 247, 0);
          seq_buf_printf(md_ktask_stack_buf, "\n");
          v89 = (__int64 *)*v89;
          v88 = v86[100] + 16LL;
        }
        v86 = (_QWORD *)*v86;
      }
      while ( v86 - 199 != init_task );
      v85 = md_ktask_stack_buf;
    }
    v85 = seq_buf_printf(v85, "---ktask stack end---\n");
  }
  md_dump_memory(
    v85,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v92[0],
    v92[1],
    v92[2],
    v92[3],
    v92[4],
    v92[5],
    v92[6],
    v92[7],
    v92[8],
    v92[9],
    v92[10],
    v92[11],
    v92[12],
    v92[13],
    v92[14],
    v92[15],
    v92[16],
    v92[17],
    v92[18],
    v92[19],
    v92[20],
    v92[21]);
  dump_stack_minidump(0);
  md_in_oops_handler = 0;
LABEL_81:
  _ReadStatusReg(SP_EL0);
}
