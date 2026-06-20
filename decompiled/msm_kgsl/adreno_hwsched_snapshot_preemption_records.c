__int64 __fastcall adreno_hwsched_snapshot_preemption_records(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x20
  unsigned __int64 v6; // x19
  __int64 v9; // x2
  _QWORD *v10; // x0
  __int64 v11; // x1
  unsigned __int64 v12; // x3
  unsigned __int64 v13; // x4
  unsigned __int64 v17; // x20

  v3 = a1[1783];
  if ( (*(_BYTE *)(v3 + 35) & 1) != 0 )
  {
    ((void (*)(void))snapshot_preemption_record)();
    snapshot_preemption_record(a1, a2, a1[2932], 0, *(_QWORD *)(a1[2932] + 40LL));
    snapshot_preemption_record(a1, a2, a1[2933], 0, *(_QWORD *)(a1[2933] + 40LL));
    v9 = a1[2934];
    v10 = a1;
    v11 = a2;
    v12 = 0;
    v13 = *(_QWORD *)(v9 + 40);
  }
  else
  {
    v4 = *(_QWORD *)(a3 + 40);
    v5 = (a1[3065] + 4095LL) & 0xFFFFFFFFFFFFF000LL;
    if ( v4 == 4 * v5 )
    {
      v6 = v4 >> 2;
    }
    else
    {
      v5 -= (*(_QWORD *)(v3 + 64) + 4095LL) & 0xFFFFFFFFFFFFF000LL;
      v6 = (v4 - v5) / 3;
    }
    snapshot_preemption_record(a1, a2, a3, 0, v5);
    snapshot_preemption_record(a1, a2, a3, v5, v6);
    v17 = v5 + v6;
    snapshot_preemption_record(a1, a2, a3, v17, v6);
    v12 = v17 + v6;
    v10 = a1;
    v11 = a2;
    v9 = a3;
    v13 = v6;
  }
  return snapshot_preemption_record(v10, v11, v9, v12, v13);
}
