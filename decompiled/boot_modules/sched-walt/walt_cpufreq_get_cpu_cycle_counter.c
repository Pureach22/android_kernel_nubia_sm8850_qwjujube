__int64 __fastcall walt_cpufreq_get_cpu_cycle_counter(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w25
  __int64 v3; // x22
  _QWORD *v4; // x23
  char *v5; // x21
  __int64 v6; // x24
  __int64 v7; // x19
  __int64 v8; // x8
  unsigned int v9; // w8
  __int64 v10; // x10
  int v11; // w8
  __int64 v12; // x20

  if ( (unsigned int)a1 >= 0x20 )
    goto LABEL_14;
  v1 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a1) + 8] + 32LL);
  if ( (unsigned int)v1 >= 5 )
    goto LABEL_14;
  if ( ((16LL * *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a1) + 8] + 32LL))
      | 8uLL) > 0x40 )
    goto LABEL_13;
  v2 = a1;
  v3 = 16LL * (unsigned int)a1;
  v4 = (_QWORD *)((char *)&cpufreq_data + 16 * v1);
  v5 = (char *)&walt_cpufreq_counter + v3;
  v6 = v4[1];
  a1 = raw_spin_lock_irqsave((char *)&walt_cpufreq_counter + v3 + 12);
  v7 = a1;
  v8 = *(_BYTE *)(v6 + 8) == 1 ? (unsigned __int16)(4 * LOWORD(cpu_topology[12 * v2 + 1]) + 4) & 0xFFFCu : 0LL;
  if ( (_DWORD)v1 == 4 || (a1 = readl_relaxed(*v4 + v8 + *(unsigned int *)(v6 + 4)), (v3 | 8uLL) > 0x200) )
  {
LABEL_13:
    __break(1u);
LABEL_14:
    __break(0x5512u);
    return readl_relaxed(a1);
  }
  v9 = *((_DWORD *)v5 + 2);
  v10 = *(_QWORD *)v5;
  *((_DWORD *)v5 + 2) = a1;
  if ( (unsigned int)a1 < v9 )
    v11 = ~v9;
  else
    v11 = -v9;
  v12 = v10 + (unsigned int)(a1 + v11);
  *(_QWORD *)v5 = v12;
  raw_spin_unlock_irqrestore(v5 + 12, v7);
  return v12;
}
