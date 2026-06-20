__int64 __fastcall timed_poll_check_rscc(__int64 a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  int *v5; // x8
  int v8; // w24
  __int64 v10; // x22
  _QWORD *v13; // x24
  __int64 v14; // x23
  __int64 v15; // x22
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x21

  v5 = *(int **)(a1 + 14264);
  v8 = *v5;
  v10 = a1;
  if ( (unsigned int)(*v5 - 620) > 0x28 || ((1LL << ((unsigned __int8)*v5 - 108)) & 0x10040000001LL) == 0 )
  {
    a1 = *((_QWORD *)v5 + 3);
    if ( !a1 || (a1 = strcmp((const char *)a1, "qcom,adreno-gpu-a642l"), (_DWORD)a1) )
    {
      if ( (unsigned int)(v8 - 621) > 0x2A || ((1LL << ((unsigned __int8)v8 - 109)) & 0x60000400003LL) == 0 )
        return gmu_core_timed_poll_check(v10, (unsigned int)(a2 + 144384), a3, a4, a5);
    }
  }
  v13 = (_QWORD *)(v10 - 344);
  v14 = (unsigned int)(4 * a2);
  v15 = ktime_get(a1);
  v16 = readl_0(*v13 + v14);
  v17 = v16 & a5;
  if ( ((unsigned int)v16 & a5) != a3 )
  {
    v18 = v15 + 1000000LL * a4;
    while ( ktime_get(v16) <= v18 )
    {
      usleep_range_state(26, 100, 2);
      __yield();
      v16 = readl_0(*v13 + v14);
      if ( ((unsigned int)v16 & a5) == a3 )
      {
        v17 = a3;
        goto LABEL_16;
      }
    }
    v17 = readl_0(*v13 + v14) & a5;
  }
LABEL_16:
  if ( v17 == a3 )
    return 0;
  else
    return 4294967186LL;
}
