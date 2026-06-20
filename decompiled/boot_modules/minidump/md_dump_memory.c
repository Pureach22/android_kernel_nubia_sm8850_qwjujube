__int64 md_dump_memory()
{
  __int64 v0; // x19
  __int64 v1; // x0
  __int64 v2; // x28
  __int64 v3; // x23
  __int64 v4; // x26
  __int64 v5; // x8
  __int64 v6; // x27
  __int64 v7; // x25
  __int64 v8; // x21
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x19
  _QWORD *i; // x26
  const char *v16; // x19
  unsigned __int64 v17; // x21
  __int64 v18; // x9
  void *v19; // x10
  unsigned __int64 StatusReg; // x22
  __int64 v21; // x28
  __int64 v22; // x24
  _QWORD *v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned __int64 v27; // x21
  __int64 v28; // x8
  __int64 v29; // x25
  unsigned __int64 v30; // x8
  __int64 v31; // x8
  _QWORD *v32; // x8
  __int64 v33; // x8
  __int64 v34; // x22
  _QWORD *v35; // x0
  _QWORD *v36; // x26
  unsigned int page_owner_handle; // w0
  __int64 v38; // x1
  unsigned __int64 v39; // x8
  unsigned int v40; // w24
  int v41; // w25
  const char *v42; // x9
  __int64 v43; // x9
  int v44; // w28
  __int64 v45; // x10
  __int64 v46; // x9
  __int64 v47; // x9
  __int64 v48; // x8
  int v49; // w22
  _UNKNOWN **v50; // x20
  size_t v51; // x0
  char *v52; // x9
  unsigned __int64 v53; // x13
  int v54; // w14
  __int64 v55; // x1
  int v56; // w0
  int v57; // w28
  int v58; // w20
  bool v59; // zf
  unsigned __int64 v60; // x23
  __int64 v61; // x8
  __int64 v62; // x9
  __int64 v63; // x22
  int v64; // w0
  __int64 v65; // x9
  __int64 v66; // x8
  int v67; // w0
  __int64 result; // x0
  unsigned __int64 v69; // x8
  __int64 v70; // x1
  int v71; // w19
  __int64 v72; // x1
  void *lock; // x0
  __int64 v74; // x25
  __int64 v75; // x24
  int v76; // w22
  __int64 v77; // x8
  _QWORD *v78; // x26
  _QWORD *v79; // x8
  __int64 v80; // x0
  __int64 v81; // x27
  __int64 v82; // x0
  __int64 v83; // x1
  __int64 v84; // x19
  __int64 v85; // x20
  int v86; // w21
  __int64 v87; // x0
  __int64 *v88; // x22
  __int64 v89; // x24
  _QWORD *v90; // x8
  __int64 v91; // x11
  __int64 v92; // x1
  int v93; // [xsp+24h] [xbp-BCh]
  __int64 v94; // [xsp+28h] [xbp-B8h]
  __int64 v95; // [xsp+38h] [xbp-A8h]
  __int64 v96; // [xsp+38h] [xbp-A8h]
  __int64 v97; // [xsp+40h] [xbp-A0h]
  unsigned __int64 v98; // [xsp+40h] [xbp-A0h]
  __int64 v99; // [xsp+48h] [xbp-98h] BYREF
  __int64 v100; // [xsp+50h] [xbp-90h]
  __int64 v101; // [xsp+58h] [xbp-88h]
  __int64 *v102; // [xsp+60h] [xbp-80h] BYREF
  __int64 v103; // [xsp+68h] [xbp-78h]
  __int64 v104; // [xsp+70h] [xbp-70h]
  size_t v105; // [xsp+78h] [xbp-68h]
  __int64 v106; // [xsp+80h] [xbp-60h]
  __int64 v107; // [xsp+88h] [xbp-58h]
  __int64 v108; // [xsp+90h] [xbp-50h]
  __int64 v109; // [xsp+98h] [xbp-48h]
  __int64 v110; // [xsp+A0h] [xbp-40h]
  __int64 v111; // [xsp+A8h] [xbp-38h]
  __int64 v112; // [xsp+B0h] [xbp-30h]
  __int64 v113; // [xsp+B8h] [xbp-28h]
  __int64 v114; // [xsp+C0h] [xbp-20h]
  __int64 v115; // [xsp+C8h] [xbp-18h]
  __int64 v116; // [xsp+D0h] [xbp-10h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = md_meminfo_seq_buf;
  if ( md_meminfo_seq_buf )
  {
    v114 = 0;
    v115 = 0;
    v112 = 0;
    v113 = 0;
    v110 = 0;
    v111 = 0;
    v108 = 0;
    v109 = 0;
    v106 = 0;
    v107 = 0;
    v104 = 0;
    v105 = 0;
    v102 = nullptr;
    v103 = 0;
    si_meminfo(&v102);
    v1 = si_swapinfo(&v102);
    v2 = vm_node_stat[0] & ~(vm_node_stat[0] >> 63);
    v3 = vm_node_stat[1] & ~(vm_node_stat[1] >> 63);
    v4 = vm_node_stat[2] & ~(vm_node_stat[2] >> 63);
    v5 = (vm_node_stat[19] & ~(vm_node_stat[19] >> 63)) - ((vm_node_stat[42] & ~(vm_node_stat[42] >> 63)) + v109);
    v6 = vm_node_stat[3] & ~(vm_node_stat[3] >> 63);
    v7 = v5 & ~(v5 >> 63);
    v95 = vm_node_stat[4] & ~(vm_node_stat[4] >> 63);
    v8 = si_mem_available(v1);
    v9 = vm_node_stat[5] & ~(vm_node_stat[5] >> 63);
    v97 = vm_node_stat[6] & ~(vm_node_stat[6] >> 63);
    seq_buf_printf(v0, "%s : %ld KB\n", "MemTotal:       ", 4 * v106);
    seq_buf_printf(v0, "%s : %ld KB\n", "MemFree:        ", 4 * v107);
    seq_buf_printf(v0, "%s : %ld KB\n", "MemAvailable:   ", 4 * v8);
    seq_buf_printf(v0, "%s : %ld KB\n", "Buffers:        ", 4 * v109);
    seq_buf_printf(v0, "%s : %ld KB\n", "Cached:         ", 4 * v7);
    seq_buf_printf(v0, "%s : %ld KB\n", "SwapCached:     ", 4 * (vm_node_stat[42] & ~(vm_node_stat[42] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "Active:         ", 4 * (v6 + v3));
    seq_buf_printf(v0, "%s : %ld KB\n", "Inactive:       ", 4 * (v4 + v2));
    seq_buf_printf(v0, "%s : %ld KB\n", "Active(anon):   ", 4 * v3);
    seq_buf_printf(v0, "%s : %ld KB\n", "Inactive(anon): ", 4 * v2);
    seq_buf_printf(v0, "%s : %ld KB\n", "Active(file):   ", 4 * v6);
    seq_buf_printf(v0, "%s : %ld KB\n", "Inactive(file): ", 4 * v4);
    seq_buf_printf(v0, "%s : %ld KB\n", "Unevictable:    ", 4 * v95);
    seq_buf_printf(v0, "%s : %ld KB\n", "Mlocked:        ", 4 * (page_ext_get[0] & ~(page_ext_get[0] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "SwapTotal:      ", 4 * v110);
    seq_buf_printf(v0, "%s : %ld KB\n", "SwapFree:       ", 4 * v111);
    seq_buf_printf(v0, "%s : %ld KB\n", "Dirty:          ", 4 * (vm_node_stat[20] & ~(vm_node_stat[20] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "Writeback:      ", 4 * (vm_node_stat[21] & ~(vm_node_stat[21] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "AnonPages:      ", 4 * (vm_node_stat[17] & ~(vm_node_stat[17] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "Mapped:         ", 4 * (vm_node_stat[18] & ~(vm_node_stat[18] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "Shmem:          ", 4 * v108);
    seq_buf_printf(v0, "%s : %ld KB\n", "KReclaimable:   ", 4 * ((vm_node_stat[34] & ~(vm_node_stat[34] >> 63)) + v9));
    seq_buf_printf(v0, "%s : %ld KB\n", "Slab:           ", 4 * (v97 + v9));
    seq_buf_printf(v0, "%s : %ld KB\n", "SReclaimable:   ", 4 * v9);
    seq_buf_printf(v0, "%s : %ld KB\n", "SUnreclaim:     ", 4 * v97);
    seq_buf_printf(v0, "KernelStack:    %8lu kB\n", vm_node_stat[37] & ~(vm_node_stat[37] >> 63));
    seq_buf_printf(v0, "ShadowCallStack:%8lu kB\n", vm_node_stat[38] & ~(vm_node_stat[38] >> 63));
    seq_buf_printf(v0, "%s : %ld KB\n", "PageTables:     ", 4 * (vm_node_stat[39] & ~(vm_node_stat[39] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "Bounce:         ", 4 * (page_ext_get[1] & ~(page_ext_get[1] >> 63)));
    seq_buf_printf(v0, "%s : %ld KB\n", "WritebackTmp:   ", 4 * (vm_node_stat[22] & ~(vm_node_stat[22] >> 63)));
    v10 = seq_buf_printf(v0, "VmallocTotal:   %8lu kB\n", 261087232);
    v11 = vmalloc_nr_pages(v10);
    v12 = seq_buf_printf(v0, "%s : %ld KB\n", "VmallocUsed: ", 4 * v11);
    v13 = pcpu_nr_pages(v12);
    seq_buf_printf(v0, "%s : %ld KB\n", "Percpu:         ", 4 * v13);
    seq_buf_printf(v0, "%s : %ld KB\n", "AnonHugePages:  ", (vm_node_stat[28] & ~(vm_node_stat[28] >> 63)) << 11);
    seq_buf_printf(v0, "%s : %ld KB\n", "ShmemHugePages: ", (vm_node_stat[24] & ~(vm_node_stat[24] >> 63)) << 11);
    seq_buf_printf(v0, "%s : %ld KB\n", "ShmemPmdMapped: ", (vm_node_stat[25] & ~(vm_node_stat[25] >> 63)) << 11);
    seq_buf_printf(v0, "%s : %ld KB\n", "FileHugePages:  ", (vm_node_stat[26] & ~(vm_node_stat[26] >> 63)) << 11);
    seq_buf_printf(v0, "%s : %ld KB\n", "FilePmdMapped:  ", (vm_node_stat[27] & ~(vm_node_stat[27] >> 63)) << 11);
    seq_buf_printf(v0, "%s : %ld KB\n", "CmaTotal:       ", 4LL * *(_QWORD *)md_debug_totalcma_pages);
    seq_buf_printf(v0, "%s : %ld KB\n", "CmaFree:        ", 4 * (page_ext_get[3] & ~(page_ext_get[3] >> 63)));
  }
  v14 = md_slabinfo_seq_buf;
  if ( md_slabinfo_seq_buf )
  {
    if ( md_debug_slab_caches )
    {
      if ( md_debug_slab_mutex )
      {
        v108 = 0;
        v109 = 0;
        v106 = 0;
        v107 = 0;
        v104 = 0;
        v105 = 0;
        v102 = nullptr;
        v103 = 0;
        if ( (unsigned int)mutex_trylock() )
        {
          seq_buf_printf(v14, "# name            <active_objs> <num_objs> <objsize> <objperslab> <pagesperslab>");
          seq_buf_printf(v14, " : tunables <limit> <batchcount> <sharedfactor>");
          seq_buf_printf(v14, " : slabdata <active_slabs> <num_slabs> <sharedavail>");
          seq_buf_printf(v14, "\n");
          for ( i = *(_QWORD **)md_debug_slab_caches; i != (_QWORD *)md_debug_slab_caches; i = (_QWORD *)*i )
          {
            v108 = 0;
            v109 = 0;
            v106 = 0;
            v107 = 0;
            v104 = 0;
            v105 = 0;
            v102 = nullptr;
            v103 = 0;
            get_slabinfo(i - 13, &v102);
            seq_buf_printf(
              v14,
              "%-17s %6lu %6lu %6u %4u %4d",
              (const char *)*(i - 1),
              v102,
              v103,
              *((_DWORD *)i - 20),
              HIDWORD(v108),
              1 << v109);
            seq_buf_printf(v14, " : tunables %4u %4u %4u", v107, HIDWORD(v107), v108);
            seq_buf_printf(v14, " : slabdata %6lu %6lu %6lu", v104, v105, v106);
            seq_buf_printf(v14, "\n");
          }
          mutex_unlock(md_debug_slab_mutex);
        }
      }
    }
  }
  v16 = (const char *)md_pageowner_dump_addr;
  if ( md_pageowner_dump_addr && md_debug_min_low_pfn && md_debug_max_pfn )
  {
    v17 = *(_QWORD *)md_debug_min_low_pfn;
    v18 = md_pageowner_dump_size;
    v19 = page_owner_handles_size;
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = v18 - (_QWORD)v19;
    while ( 1 )
    {
      if ( v17 >> 52 || v17 >> 36 )
      {
        LODWORD(v22) = 0;
        goto LABEL_17;
      }
      v23 = (_QWORD *)mem_section;
      if ( mem_section )
      {
        v23 = *(_QWORD **)(mem_section + ((v17 >> 19) & 0x1FFFFFFFFFF8LL));
        if ( v23 )
          v23 += 4 * ((v17 >> 15) & 0x7F);
      }
      ++*(_DWORD *)(StatusReg + 16);
      if ( v23 && (*v23 & 2) != 0 )
      {
        if ( (*v23 & 8) != 0 )
        {
          LODWORD(v22) = 1;
        }
        else
        {
          v25 = v23[1];
          if ( v25 )
            v22 = (*(_QWORD *)(v25 + 16) >> (v17 >> 9)) & 1LL;
          else
            LODWORD(v22) = 0;
        }
        v26 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v26;
        if ( v26 && *(_QWORD *)(StatusReg + 16) )
          goto LABEL_17;
      }
      else
      {
        v24 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v24;
        if ( v24 )
        {
          LODWORD(v22) = 0;
          if ( *(_QWORD *)(StatusReg + 16) )
            goto LABEL_17;
        }
        else
        {
          LODWORD(v22) = 0;
        }
      }
      preempt_schedule();
LABEL_17:
      v59 = (v17++ & 0x3FF) == 0;
      if ( v59 || (_DWORD)v22 )
      {
        v27 = v17 - 1;
        if ( v27 >= *(_QWORD *)md_debug_max_pfn )
          break;
        v98 = _ReadStatusReg(SP_EL0);
LABEL_44:
        if ( (v27 & 0x3FF) != 0 )
        {
LABEL_45:
          v29 = (v27 << 6) - ((__int64)memstart_addr >> 12 << 6) - 0x140000000LL;
          if ( *(unsigned __int8 *)((v27 << 6) - ((__int64)memstart_addr >> 12 << 6) - 0x13FFFFFCDLL) == 240 )
          {
            v30 = *(_QWORD *)((v27 << 6) - ((__int64)memstart_addr >> 12 << 6) - 0x13FFFFFD8LL);
            if ( v30 < 0xA )
              v31 = ~(-1LL << v30);
            else
              v31 = 0;
            v27 += v31;
LABEL_43:
            if ( ++v27 >= *(_QWORD *)md_debug_max_pfn )
              break;
            goto LABEL_44;
          }
          v35 = (_QWORD *)((__int64 (__fastcall *)(unsigned __int64))page_ext_get[0])((v27 << 6)
                                                                                    - ((__int64)memstart_addr >> 12 << 6) - 0x140000000LL);
          v36 = v35;
          if ( !v35 || (*v35 & 1) == 0 || (*v35 & 2) == 0 || (page_owner_handle = get_page_owner_handle(v35, v27)) == 0 )
          {
LABEL_129:
            page_ext_put(v36);
            goto LABEL_43;
          }
          v99 = 0;
          v39 = page_owner_filter;
          if ( !page_owner_filter )
            goto LABEL_127;
          v40 = page_owner_handle;
          v96 = v21;
          if ( page_owner_filter == 15 )
          {
LABEL_66:
            v21 = v96;
            v41 = stack_depot_fetch(v40, &v99);
            v42 = (const char *)(md_pageowner_dump_addr + md_pageowner_dump_size - (_QWORD)page_owner_handles_size);
            if ( v42 >= v16 )
            {
              if ( nr_page_owner_handles < 1 )
              {
                v52 = (char *)&v42[4 * nr_page_owner_handles];
LABEL_112:
                if ( (unsigned __int64)v52 >= md_pageowner_dump_addr + md_pageowner_dump_size )
                {
                  if ( (unsigned int)__ratelimit(&found_stack__rs, "found_stack") )
                    printk(&unk_1127AC, v55);
                }
                else
                {
                  *(_DWORD *)v52 = v40;
                  ++nr_page_owner_handles;
                }
              }
              else
              {
                if ( *(_DWORD *)v42 == v40 )
                {
LABEL_69:
                  v39 = (int)scnprintf(v16, v96, "%lu %u %u\n", v27, v40, 0);
                  goto LABEL_127;
                }
                v53 = 0;
                do
                {
                  if ( (unsigned int)nr_page_owner_handles - 1LL == v53 )
                  {
                    v52 = (char *)&v42[4 * nr_page_owner_handles];
                    goto LABEL_112;
                  }
                  v54 = *(_DWORD *)(md_pageowner_dump_addr
                                  + md_pageowner_dump_size
                                  - (_QWORD)page_owner_handles_size
                                  + 4
                                  + 4 * v53++);
                }
                while ( v54 != v40 );
                if ( v53 < (unsigned int)nr_page_owner_handles )
                  goto LABEL_69;
              }
            }
            v56 = scnprintf(v16, v96, "%lu %u %u\n", v27, v40, v41);
            v39 = v56;
            if ( v96 - 1 != v56 && v41 )
            {
              v57 = 0;
              v58 = v56;
              do
              {
                v58 += scnprintf(&v16[v58], v96 - v58, "%p\n", *(_QWORD *)(v99 + 8LL * v57));
                v39 = v58;
                v59 = v96 - 1 == v58 || v41 - 1 == v57++;
              }
              while ( !v59 );
              v21 = v96;
            }
LABEL_127:
            if ( v39 == v21 - 1 )
            {
              printk(&unk_11293A, v38);
              page_ext_put(v36);
              break;
            }
            v21 -= v39;
            v16 += v39;
            goto LABEL_129;
          }
          v43 = 1;
          v44 = 1;
          while ( 2 )
          {
            if ( (v43 & v39) != 0 )
            {
              if ( v44 > 3 )
              {
                if ( v44 == 4 )
                {
                  if ( (*(_BYTE *)(v29 + 2) & 4) != 0 )
                    goto LABEL_66;
                  goto LABEL_74;
                }
                if ( v44 == 8 )
                {
                  if ( (*(_BYTE *)v29 & 0x20) != 0 )
                    goto LABEL_66;
LABEL_126:
                  v21 = v96;
                  v39 = 0;
                  goto LABEL_127;
                }
              }
              else if ( v44 == 1 )
              {
                if ( (*(_DWORD *)v29 & 0x40020) == 0 )
                {
                  v47 = *(_QWORD *)(v29 + 8);
                  v48 = v29;
                  if ( (v47 & 1) != 0 )
                    v48 = v47 - 1;
                  if ( *(unsigned __int8 *)(v48 + 51) << 24 != -184549376 )
                  {
                    v102 = nullptr;
                    v93 = stack_depot_fetch(v40, &v102);
                    if ( !v93 )
                      goto LABEL_66;
                    v49 = 0;
                    while ( v96 - 1 != (int)scnprintf(v16, v96, "%pS\n", (const void *)v102[v49]) )
                    {
                      v50 = &accounted_call_site_list;
                      v94 = raw_spin_lock_irqsave(&accounted_call_site_lock);
                      while ( 1 )
                      {
                        v50 = (_UNKNOWN **)*v50;
                        if ( v50 == &accounted_call_site_list )
                          break;
                        v51 = strlen(v16);
                        if ( strnstr(v16, v50 + 2, v51) )
                        {
                          raw_spin_unlock_irqrestore(&accounted_call_site_lock, v94);
                          goto LABEL_98;
                        }
                      }
                      raw_spin_unlock_irqrestore(&accounted_call_site_lock, v94);
                      if ( ++v49 == v93 )
                        goto LABEL_66;
                    }
                  }
                }
              }
              else if ( v44 == 2 )
              {
                v45 = *(_QWORD *)(v29 + 8);
                v46 = v29;
                if ( (v45 & 1) != 0 )
                  v46 = v45 - 1;
                if ( *(unsigned __int8 *)(v46 + 51) << 24 == -184549376 )
                  goto LABEL_66;
LABEL_74:
                v44 *= 2;
                v43 = v44;
                if ( v39 < v44 )
                  goto LABEL_126;
                continue;
              }
            }
            break;
          }
          if ( v44 > 7 )
            goto LABEL_126;
LABEL_98:
          v39 = page_owner_filter;
          goto LABEL_74;
        }
        if ( !(v27 >> 52) && !(v27 >> 36) )
        {
          v32 = (_QWORD *)mem_section;
          if ( mem_section )
          {
            v32 = *(_QWORD **)(mem_section + ((v27 >> 19) & 0x1FFFFFFFFFF8LL));
            if ( v32 )
              v32 += 4 * ((v27 >> 15) & 0x7F);
          }
          ++*(_DWORD *)(v98 + 16);
          if ( v32 && (*v32 & 2) != 0 )
          {
            if ( (*v32 & 8) != 0 )
            {
              LODWORD(v34) = 1;
            }
            else
            {
              v33 = v32[1];
              if ( v33 )
                v34 = (*(_QWORD *)(v33 + 16) >> ((v27 >> 9) & 0x3E)) & 1LL;
              else
                LODWORD(v34) = 0;
            }
            v59 = *(_QWORD *)(v98 + 16) == 1;
            --*(_DWORD *)(v98 + 16);
            if ( !v59 && *(_QWORD *)(v98 + 16) )
            {
              if ( (_DWORD)v34 )
                goto LABEL_45;
              goto LABEL_42;
            }
LABEL_131:
            preempt_schedule();
            if ( (_DWORD)v34 )
              goto LABEL_45;
            goto LABEL_42;
          }
          v28 = *(_QWORD *)(v98 + 16) - 1LL;
          *(_DWORD *)(v98 + 16) = v28;
          if ( !v28 || !*(_QWORD *)(v98 + 16) )
          {
            LODWORD(v34) = 0;
            goto LABEL_131;
          }
        }
LABEL_42:
        v27 |= 0x3FFu;
        goto LABEL_43;
      }
    }
  }
  if ( md_slabowner_dump_addr )
  {
    v60 = 0;
    v61 = 0;
    v62 = md_slabowner_dump_size - (_QWORD)slab_owner_handles_size;
    v102 = (__int64 *)md_slabowner_dump_addr;
    v103 = md_slabowner_dump_size - (_QWORD)slab_owner_handles_size;
    v104 = 0;
    while ( 1 )
    {
      if ( (((unsigned __int64)slab_owner_filter >> v60) & 1) != 0 && (v63 = kmalloc_caches[v60]) != 0 )
      {
        v64 = scnprintf((char *)v102 + v61, v62 - v61, "%s\n", *(const char **)(v63 + 96));
        v65 = v103;
        v104 += v64;
        v66 = v104;
        if ( v104 == v103 - 1 )
          break;
        if ( (*(_BYTE *)(v63 + 8) & 0x80) != 0 )
        {
          if ( (unsigned int)get_each_kmemcache_object(v63, dump_tracking, &v102) == -34 )
            break;
          v65 = v103;
          v66 = v104;
        }
        v67 = scnprintf((char *)v102 + v66, v65 - v66, "\n");
        v62 = v103;
        v104 += v67;
        v61 = v104;
        if ( v104 == v103 - 1 || v60 >= 0xD )
          break;
      }
      else if ( v60 > 0xC )
      {
        break;
      }
      ++v60;
    }
  }
  result = md_dma_buf_info_addr;
  if ( md_dma_buf_info_addr )
  {
    v103 = 0;
    v104 = 0;
    v69 = _ReadStatusReg(SP_EL0);
    v70 = md_dma_buf_info_size;
    if ( (*(_DWORD *)(v69 + 16) & 0xFF0100) == 0 && !*(_DWORD *)(v69 + 16) && (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      v99 = result;
      v100 = v70;
      v101 = 0;
      v102 = &v99;
      LODWORD(v104) = 0;
      v105 = 0;
      v71 = scnprintf(result, v70, "\nDma-buf Objects:\n");
      v101 = (int)(scnprintf(
                     v99 + v71,
                     v100 - v71,
                     "%-8s\t%-8s\t%-8s\t%-8s\texp_name\t%-8s\n",
                     "size",
                     "flags",
                     "mode",
                     "count",
                     "ino")
                 + v71);
      if ( (unsigned int)get_dmabuf_debugfs_data(dump_bufinfo, &v102) )
        printk(&unk_1135C3, v72);
      result = scnprintf(v99 + v101, v100 - v101, "\nTotal %d objects, %zu bytes\n", v104, v105);
    }
  }
  if ( md_dma_buf_procs_addr )
  {
    v99 = md_dma_buf_procs_addr;
    v102 = &v99;
    v103 = 0;
    v104 = 0;
    v105 = 0;
    v100 = md_dma_buf_procs_size;
    v101 = 0;
    lock = (void *)_rcu_read_lock();
    v74 = init_task[199];
    v75 = v74 - 1592;
    if ( (_QWORD *)(v74 - 1592) == init_task )
    {
LABEL_175:
      result = _rcu_read_unlock(lock);
      goto LABEL_177;
    }
    v76 = 0;
    while ( 1 )
    {
      v103 = v75;
      v77 = *(_QWORD *)(v74 + 800);
      v78 = *(_QWORD **)(v77 + 16);
      if ( v78 != (_QWORD *)(v77 + 16) )
        break;
LABEL_157:
      v74 = *(_QWORD *)(v75 + 1592);
      v75 = v74 - 1592;
      if ( (_QWORD *)(v74 - 1592) == init_task )
        goto LABEL_175;
    }
    raw_spin_lock(v78 + 70);
    v79 = *(_QWORD **)(v74 + 272);
    v80 = v78[49];
    v81 = v79[296];
    if ( v80 && (v78 - 247 == v79 || v81 != v80) )
    {
LABEL_162:
      v76 = iterate_fd();
      goto LABEL_163;
    }
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_163:
        lock = (void *)raw_spin_unlock(v78 + 70);
        if ( v76 )
        {
LABEL_176:
          _rcu_read_unlock(lock);
          result = printk(&unk_113374, v83);
          goto LABEL_177;
        }
        v78 = (_QWORD *)*v78;
        if ( v78 == (_QWORD *)(*(_QWORD *)(v74 + 800) + 16LL) )
        {
          if ( !(_DWORD)v104 )
          {
            v76 = 0;
            goto LABEL_157;
          }
          lock = (void *)scnprintf(v99 + v101, v100 - v101, "\nTotal %d objects, %zu bytes\n", v104, v105);
          v101 += (int)lock;
          if ( v101 != v100 - 1 )
          {
            v76 = (int)lock;
            LODWORD(v104) = 0;
            v105 = 0;
            lock = memset(&dma_buf_hash, 0, 0x100000u);
            goto LABEL_157;
          }
          goto LABEL_176;
        }
        raw_spin_lock(v78 + 70);
        if ( v81 )
          break;
        v81 = *(_QWORD *)(*(_QWORD *)(v74 + 272) + 2368LL);
        v82 = v78[49];
        if ( v82 )
          goto LABEL_167;
LABEL_171:
        v76 = 0;
      }
      v82 = v78[49];
      if ( !v82 )
        goto LABEL_171;
LABEL_167:
      if ( v81 != v82 || v78 - 247 == *(_QWORD **)(v74 + 272) )
        goto LABEL_162;
      v76 = 0;
    }
  }
LABEL_177:
  v84 = md_task_memstat_addr;
  if ( md_task_memstat_addr )
  {
    v85 = md_task_memstat_size;
    v86 = scnprintf(
            md_task_memstat_addr,
            md_task_memstat_size,
            "%-8s %-8s %-10s %-8s %-16s %-16s %-16s %s\n",
            "PID",
            "RSS(KB)",
            "SWAP(KB)",
            "ADJ",
            "anon_rss(KB)",
            "file_rss(KB)",
            "shmem_rss(KB)",
            "TaskName");
    v87 = _rcu_read_lock();
    v88 = (__int64 *)init_task[199];
    if ( v88 - 199 == init_task )
    {
LABEL_184:
      result = _rcu_read_unlock(v87);
    }
    else
    {
      v89 = v86;
      while ( 1 )
      {
        v90 = (_QWORD *)v88[10];
        if ( v90 )
        {
          v91 = v90[116] & ~((__int64)v90[116] >> 63);
          v87 = scnprintf(
                  v84 + v89,
                  v85 - v89,
                  "%-8d %-8lu %-10lu %-8d %-16lu %-16lu %-16lu %s\n",
                  *((_DWORD *)v88 + 52),
                  4 * ((v90[106] & ~((__int64)v90[106] >> 63)) + (v90[101] & ~((__int64)v90[101] >> 63)) + v91),
                  4 * (v90[111] & ~((__int64)v90[111] >> 63)),
                  *(__int16 *)(v88[100] + 954),
                  4 * (v90[106] & ~((__int64)v90[106] >> 63)),
                  4 * (v90[101] & ~((__int64)v90[101] >> 63)),
                  4 * v91,
                  (const char *)v88 + 728);
          v89 += (int)v87;
          if ( v89 == v85 - 1 )
            break;
        }
        v88 = (__int64 *)*v88;
        if ( v88 - 199 == init_task )
          goto LABEL_184;
      }
      _rcu_read_unlock(v87);
      result = printk(&unk_113AD0, v92);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
