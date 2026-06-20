__int64 __fastcall sysstats_meminfo_user_cmd(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 lock; // x0
  __int64 v9; // x25
  _QWORD *v10; // x24
  __int64 v11; // x19
  __int64 v12; // x20
  _QWORD *v13; // x26
  _QWORD *v14; // x27
  __int64 v15; // x0
  int v16; // w22
  __int64 (__fastcall *v17)(__int64); // x8
  __int64 v18; // x28
  __int64 v19; // x27
  _QWORD *v20; // x20
  const char *v21; // x25
  int v22; // w0
  _QWORD *v23; // x12
  _QWORD *v24; // x8
  _QWORD *v25; // x9
  _QWORD *v26; // x10
  _QWORD *v27; // x11
  int v28; // w0
  int v29; // w0
  int v30; // w0
  __int64 v31; // x1
  int v32; // w0
  __int64 v33; // [xsp+8h] [xbp-118h]
  __int64 v34; // [xsp+10h] [xbp-110h]
  _QWORD *v35; // [xsp+60h] [xbp-C0h]
  __int64 v36; // [xsp+90h] [xbp-90h] BYREF
  unsigned __int64 v37; // [xsp+98h] [xbp-88h]
  _QWORD v38[4]; // [xsp+A0h] [xbp-80h] BYREF
  __int64 v39; // [xsp+C0h] [xbp-60h]
  __int64 v40; // [xsp+C8h] [xbp-58h]
  __int64 v41; // [xsp+D0h] [xbp-50h]
  __int64 v42; // [xsp+D8h] [xbp-48h]
  __int64 v43; // [xsp+E0h] [xbp-40h]
  __int64 v44; // [xsp+E8h] [xbp-38h]
  __int64 v45; // [xsp+F0h] [xbp-30h]
  __int64 v46; // [xsp+F8h] [xbp-28h]
  __int64 v47; // [xsp+100h] [xbp-20h]
  __int64 v48; // [xsp+108h] [xbp-18h]
  __int64 v49; // [xsp+110h] [xbp-10h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  result = prepare_reply(a2, 4, &v36, 292);
  if ( (result & 0x80000000) == 0 )
  {
    v4 = v36;
    v5 = nla_reserve(v36, 4, 288);
    if ( v5 )
    {
      v33 = a2;
      v34 = v5;
      v6 = v5;
      v35 = (_QWORD *)(v5 + 260);
      memset((void *)(v5 + 4), 0, 0x120u);
      v47 = 0;
      v48 = 0;
      v45 = 0;
      v46 = 0;
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      v39 = 0;
      v40 = 0;
      memset(v38, 0, sizeof(v38));
      v7 = si_meminfo(v38);
      *(_QWORD *)(v6 + 60) = 0;
      *(_QWORD *)(v6 + 36) = 0;
      *(_QWORD *)(v6 + 44) = 0;
      *(_QWORD *)(v6 + 4) = 4 * v39;
      *(_QWORD *)(v6 + 12) = 4 * (MEMORY[0x9370] & ~((__int64)MEMORY[0x9370] >> 63));
      lock = _rcu_read_lock(v7);
      v9 = init_task[199];
      v10 = (_QWORD *)(v9 - 1592);
      if ( (_QWORD *)(v9 - 1592) != init_task )
      {
        v11 = 0;
        while ( 1 )
        {
          raw_spin_lock(v9 + 944);
          v37 = 0;
          v12 = 0;
          v13 = (_QWORD *)(*(_QWORD *)(v9 + 800) + 16LL);
          do
          {
            v13 = (_QWORD *)*v13;
            if ( v13 == (_QWORD *)(*(_QWORD *)(v9 + 800) + 16LL) )
              break;
            v14 = v13 - 247;
            if ( v13 - 247 != v10 )
              raw_spin_lock(v13 + 70);
            if ( v12 )
            {
              v15 = v13[49];
              if ( !v15 )
                goto LABEL_17;
            }
            else
            {
              v12 = *(_QWORD *)(*(_QWORD *)(v9 + 272) + 2368LL);
              v15 = v13[49];
              if ( !v15 )
                goto LABEL_17;
            }
            if ( v12 != v15 || v14 == *(_QWORD **)(v9 + 272) )
            {
              v16 = iterate_fd();
              if ( v14 == v10 )
                continue;
LABEL_18:
              raw_spin_unlock(v13 + 70);
              continue;
            }
LABEL_17:
            v16 = 0;
            if ( v14 != v10 )
              goto LABEL_18;
          }
          while ( !v16 );
          v11 += v37 >> 12;
          lock = raw_spin_unlock(v9 + 944);
          v9 = v10[199];
          v10 = (_QWORD *)(v9 - 1592);
          if ( (_QWORD *)(v9 - 1592) == init_task )
            goto LABEL_23;
        }
      }
      v11 = 0;
LABEL_23:
      _rcu_read_unlock(lock);
      v17 = (__int64 (__fastcall *)(__int64))sysstats_kgsl_get_stats;
      if ( *((_DWORD *)sysstats_kgsl_get_stats - 1) != -1593946263 )
        __break(0x8228u);
      v18 = 0;
      v19 = 0;
      *(_QWORD *)(v34 + 20) = 4 * (v11 + ((unsigned __int64)v17(0xFFFFFFFFLL) >> 12));
      *(_QWORD *)(v34 + 52) = 4 * v42;
      *(_QWORD *)(v34 + 68) = 4 * (mem_alloc_profiling_key[37] & ~(mem_alloc_profiling_key[37] >> 63));
      *(_QWORD *)(v34 + 76) = 4 * (mem_alloc_profiling_key[0] & ~(mem_alloc_profiling_key[0] >> 63));
      *(_QWORD *)(v34 + 84) = 4 * (mem_alloc_profiling_key[1] & ~(mem_alloc_profiling_key[1] >> 63));
      *(_QWORD *)(v34 + 92) = 4 * (pid_nr_ns & ~((__int64)pid_nr_ns >> 63));
      *(_QWORD *)(v34 + 100) = 4 * (mem_alloc_profiling_key[13] & ~(mem_alloc_profiling_key[13] >> 63));
      *(_QWORD *)(v34 + 116) = mem_alloc_profiling_key[32] & ~(mem_alloc_profiling_key[32] >> 63);
      *(_QWORD *)(v34 + 108) = 4 * (mem_alloc_profiling_key[34] & ~(mem_alloc_profiling_key[34] >> 63));
      *(_QWORD *)(v34 + 124) = 4 * v41;
      do
      {
        v20 = (_QWORD *)((char *)&contig_page_data + v18);
        if ( *(_QWORD *)((char *)&contig_page_data + v18 + 144) )
        {
          v21 = (const char *)v20[21];
          v19 += v20[201] & ~((__int64)v20[201] >> 63);
          v22 = strcmp(v21, "DMA");
          v23 = (_QWORD *)(v34 + 132);
          v24 = (_QWORD *)(v34 + 140);
          v25 = (_QWORD *)(v34 + 148);
          v26 = (_QWORD *)(v34 + 156);
          v27 = (_QWORD *)(v34 + 164);
          if ( !v22 )
            goto LABEL_26;
          v28 = strcmp(v21, "Normal");
          v24 = (_QWORD *)(v34 + 180);
          v23 = (_QWORD *)(v34 + 172);
          v27 = (_QWORD *)(v34 + 204);
          v26 = (_QWORD *)(v34 + 196);
          v25 = (_QWORD *)(v34 + 188);
          if ( !v28 )
            goto LABEL_26;
          v29 = strcmp(v21, "HighMem");
          v23 = (_QWORD *)(v34 + 252);
          v24 = v35;
          v27 = v35 + 3;
          v26 = v35 + 2;
          v25 = v35 + 1;
          if ( !v29
            || (v30 = strcmp(v21, "Movable"),
                v24 = (_QWORD *)(v34 + 220),
                v23 = (_QWORD *)(v34 + 212),
                v27 = (_QWORD *)(v34 + 244),
                v26 = (_QWORD *)(v34 + 236),
                v25 = (_QWORD *)(v34 + 228),
                !v30) )
          {
LABEL_26:
            *v23 = 4 * (v20[192] & ~((__int64)v20[192] >> 63));
            *v24 = 4
                 * (*(_QWORD *)((_BYTE *)&contig_page_data + v18 + 1552)
                  & ~(*(__int64 *)((char *)&contig_page_data + v18 + 1552) >> 63));
            *v25 = 4
                 * (*(_QWORD *)((_BYTE *)&contig_page_data + v18 + 1544)
                  & ~(*(__int64 *)((char *)&contig_page_data + v18 + 1544) >> 63));
            *v26 = 4
                 * (*(_QWORD *)((_BYTE *)&contig_page_data + v18 + 1568)
                  & ~(*(__int64 *)((char *)&contig_page_data + v18 + 1568) >> 63));
            *v27 = 4
                 * (*(_QWORD *)((_BYTE *)&contig_page_data + v18 + 1560)
                  & ~(*(__int64 *)((char *)&contig_page_data + v18 + 1560) >> 63));
          }
        }
        v18 += 1664;
      }
      while ( v18 < 4992 );
      v31 = v36;
      *(_QWORD *)(v34 + 28) = 4 * v19;
      **(_DWORD **)((char *)&off_E0 + v31) = *(int *)((char *)&dword_D8 + v31)
                                           + *(int *)((char *)&dword_D0 + v31)
                                           - (unsigned int)*(_UNKNOWN **)((char *)&off_E0 + v31);
      v32 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(v33 + 40) + 288LL), v31, *(unsigned int *)(v33 + 4), 64);
      result = v32 & (unsigned int)(v32 >> 31);
    }
    else
    {
      sk_skb_reason_drop(0, v4, 2);
      result = 4294967206LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
