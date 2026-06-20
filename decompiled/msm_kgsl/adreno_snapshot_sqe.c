__int64 __fastcall adreno_snapshot_sqe(_QWORD *a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x8
  __int64 *v6; // x8
  int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 *v10; // t2

  if ( a3 > 0x1B )
  {
    *(_QWORD *)a2 = 0x50000000ELL;
    v5 = a1[1787];
    v6 = *(__int64 **)(v5 + 8);
    v7 = *((_DWORD *)v6 + 4);
    v10 = v6;
    v8 = *v6;
    v9 = v10[1];
    *(_DWORD *)(a2 + 24) = v7;
    *(_QWORD *)(a2 + 8) = v8;
    *(_QWORD *)(a2 + 16) = v9;
    return 28;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&adreno_snapshot_sqe__rs, "adreno_snapshot_sqe") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "SQE VERSION DEBUG");
    return 0;
  }
}
