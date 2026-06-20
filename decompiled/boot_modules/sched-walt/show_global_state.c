__int64 __fastcall show_global_state(__int64 a1, __int64 a2)
{
  char v3; // w9
  __int64 v4; // x25
  int v5; // w8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x24
  unsigned __int8 *v8; // x26
  __int64 v9; // x23
  __int64 v10; // x25
  __int64 v11; // x25
  __int64 v12; // x25
  __int64 v13; // x25
  __int64 v14; // x25
  __int64 v15; // x25
  __int64 v16; // x25
  __int64 v17; // x25
  __int64 v18; // x26
  int v19; // w0
  __int64 v20; // x25
  __int64 v21; // x26
  int v22; // w0
  __int64 v23; // x25

  raw_spin_lock_irq(&state_lock);
  v3 = 0;
  v4 = 0;
  v5 = _cpu_possible_mask;
  do
  {
    v6 = (unsigned int)(-1LL << v3) & v5;
    if ( !(_DWORD)v6 )
      break;
    v7 = __clz(__rbit64(v6));
    v8 = (unsigned __int8 *)&cpu_state + *((_QWORD *)&_per_cpu_offset + v7);
    v9 = *((_QWORD *)v8 + 2);
    if ( v9 && *(_BYTE *)v9 == 1 )
    {
      v10 = v4 + (int)scnprintf(a2 + v4, 4096 - v4, "CPU%u\n", v7);
      v11 = v10 + (int)scnprintf(a2 + v10, 4096 - v10, "\tCPU: %u\n", *((_DWORD *)v8 + 2));
      v12 = v11
          + (int)scnprintf(
                   a2 + v11,
                   4096 - v11,
                   "\tOnline: %u\n",
                   (*(_QWORD *)((char *)&_cpu_online_mask
                              + (((unsigned __int64)*((unsigned int *)v8 + 2) >> 3) & 0x1FFFFFF8)) >> *((_DWORD *)v8 + 2))
                 & 1);
      v13 = v12
          + (int)scnprintf(
                   a2 + v12,
                   4096 - v12,
                   "\tPaused: %u Partial Paused: %u\n",
                   (*(unsigned __int64 *)((char *)_cpu_halt_mask
                                        + (((unsigned __int64)*((unsigned int *)v8 + 2) >> 3) & 0x1FFFFFF8)) >> *((_DWORD *)v8 + 2))
                 & 1,
                   ((unsigned __int64)_cpu_partial_halt_mask[0] >> v7) & 1);
      v14 = v13 + (int)scnprintf(a2 + v13, 4096 - v13, "\tFirst CPU: %u\n", *(_DWORD *)(v9 + 144));
      v15 = v14 + (int)scnprintf(a2 + v14, 4096 - v14, "\tBusy%%: %u\n", *((_DWORD *)v8 + 1));
      v16 = v15 + (int)scnprintf(a2 + v15, 4096 - v15, "\tIs busy: %u\n", *v8);
      v17 = v16 + (int)scnprintf(a2 + v16, 4096 - v16, "\tNot preferred: %u\n", v8[12]);
      v18 = v17 + (int)scnprintf(a2 + v17, 4096 - v17, "\tNr running: %u\n", *(_DWORD *)(v9 + 140));
      v19 = _sw_hweight64(*(_DWORD *)(v9 + 80) & (unsigned int)~(LODWORD(_cpu_partial_halt_mask[0])
                                                               | LODWORD(_cpu_halt_mask[0])));
      v20 = v18 + (int)scnprintf(a2 + v18, 4096 - v18, "\tActive CPUs: %u\n", v19);
      v21 = v20 + (int)scnprintf(a2 + v20, 4096 - v20, "\tNeed CPUs: %u\n", *(_DWORD *)(v9 + 88));
      v22 = _sw_hweight64(*(_DWORD *)(v9 + 80) & ((unsigned int)cpus_part_paused_by_us | (unsigned int)cpus_paused_by_us));
      v23 = v21 + (int)scnprintf(a2 + v21, 4096 - v21, "\tCluster paused CPUs: %u\n", v22);
      v4 = v23 + (int)scnprintf(a2 + v23, 4096 - v23, "\tBoost: %u\n", *(_DWORD *)(v9 + 148));
      v5 = _cpu_possible_mask;
    }
    v3 = v7 + 1;
  }
  while ( v7 < 0x1F );
  raw_spin_unlock_irq(&state_lock);
  return v4;
}
