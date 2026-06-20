__int64 __fastcall arm_tbu_trigger_atos(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x20
  unsigned __int64 v16; // x0
  int v17; // w0

  v4 = *(_QWORD *)(a1 + 32);
  v9 = readq_relaxed_0((_QWORD *)v4);
  writeq_relaxed_0(v9 & 0xFFFFFFFFFFFFFC00LL | a3 & 0x3FF, (_QWORD *)v4);
  writeq_relaxed_0(a2, (_QWORD *)(v4 + 8));
  writeq_relaxed_0(0xFF000000000LL, (_QWORD *)(v4 + 48));
  if ( (a4 & 1) != 0 )
    v10 = 190;
  else
    v10 = 188;
  v11 = writeq_relaxed_0((a4 << 6) & 0x100LL | ((((unsigned __int64)a4 >> 1) & 1) << 6) | v10 | 1, (_QWORD *)(v4 + 24));
  v12 = ktime_get(v11) + 100000;
  do
  {
    if ( (readl_relaxed_1((unsigned int *)(v4 + 32)) & 1) != 0 )
    {
      v13 = readl_relaxed_1((unsigned int *)(v4 + 40));
      if ( (v13 & 1) == 0 )
        continue;
    }
    v16 = readq_relaxed_0((_QWORD *)(v4 + 40));
    v14 = v16;
    if ( (v16 & 1) == 0 )
    {
      v15 = (v16 >> 12) & 0xFFFFFFFFFLL;
      goto LABEL_14;
    }
    goto LABEL_15;
  }
  while ( ktime_get(v13) <= v12 );
  v14 = readq_relaxed_0((_QWORD *)(v4 + 40));
  if ( (v14 & 1) != 0 )
  {
LABEL_15:
    dev_err(*(_QWORD *)(a1 + 16), "ECATS generated a fault interrupt! PAR = %llx, SID=0x%x\n", v14, a3);
    v15 = 0;
    goto LABEL_14;
  }
  if ( (unsigned int)__ratelimit(&arm_tbu_trigger_atos__rs, "arm_tbu_trigger_atos") )
    dev_err(*(_QWORD *)(a1 + 16), "ECATS translation timed out!\n");
  v15 = 0;
LABEL_14:
  writeq_relaxed_0(0, (_QWORD *)(v4 + 24));
  writeq_relaxed_0(0, (_QWORD *)(v4 + 8));
  v17 = readl_relaxed_1((unsigned int *)v4);
  writel_relaxed_1(v17 & 0xFFFFFC00, (unsigned int *)v4);
  return v15;
}
