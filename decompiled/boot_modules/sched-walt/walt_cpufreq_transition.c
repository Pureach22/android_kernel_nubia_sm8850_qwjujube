__int64 __fastcall walt_cpufreq_transition(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x20
  char v5; // w9
  __int64 v6; // x9
  unsigned __int64 v7; // x25
  char *v8; // x21
  __int64 v9; // x0
  int v10; // w8
  char v11; // w10
  int v12; // w8
  unsigned __int64 v13; // x10
  unsigned __int64 v14; // x10
  __int64 v15; // x11
  bool v16; // cf

  result = sched_clock(a1, a2);
  v4 = result;
  v5 = 0;
  while ( 1 )
  {
    v6 = -1LL << v5;
    if ( ((unsigned int)v6 & *(_DWORD *)(a2 + 8)) == 0 )
      break;
    v7 = __clz(__rbit64((unsigned int)v6 & *(_DWORD *)(a2 + 8)));
    v8 = (char *)&walt_cc + *((_QWORD *)&_per_cpu_offset + v7);
    v9 = raw_write_lock_irqsave(v8);
    *((_QWORD *)v8 + 1) += ((v4 - *((_QWORD *)v8 + 2)) * (unsigned __int64)*((unsigned int *)v8 + 7)) >> 20;
    *((_QWORD *)v8 + 2) = v4;
    result = raw_write_unlock_irqrestore(v8, v9);
    v10 = *(_DWORD *)(a2 + 60);
    v5 = v7 + 1;
    *((_DWORD *)v8 + 6) = v10;
    if ( v7 >= 0x1F )
      goto LABEL_6;
  }
  v10 = *(_DWORD *)(a2 + 60);
LABEL_6:
  v11 = 0;
  v12 = ((16 * ((274877907 * (unsigned __int64)(unsigned int)(v10 << 10)) >> 32)) & 0xFFFFFC00) / 0x3E8;
  do
  {
    v13 = (unsigned int)(-1LL << v11) & *(_DWORD *)(a2 + 8);
    if ( !(_DWORD)v13 )
      break;
    v14 = __clz(__rbit64(v13));
    v15 = *((_QWORD *)&_per_cpu_offset + v14);
    v16 = v14 >= 0x1F;
    v11 = v14 + 1;
    *(_DWORD *)((char *)&walt_cc + v15 + 28) = v12;
  }
  while ( !v16 );
  return result;
}
