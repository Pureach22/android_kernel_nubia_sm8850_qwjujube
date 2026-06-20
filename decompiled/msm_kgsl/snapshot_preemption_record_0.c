size_t __fastcall snapshot_preemption_record_0(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  size_t v5; // x2
  size_t v6; // x19
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 v11; // x20
  size_t v12; // x22
  __int64 v13; // x21

  if ( a1[1414] >= *(_QWORD *)(a4 + 40) )
    v5 = *(_QWORD *)(a4 + 40);
  else
    v5 = a1[1414];
  v6 = v5 + 28;
  if ( v5 + 28 <= a3 )
  {
    *(_QWORD *)(a2 + 20) = v5 >> 2;
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(a4 + 24);
    v8 = a1[9];
    if ( v8 )
    {
      v9 = *(_QWORD *)(v8 + 96);
      if ( v9 && (v10 = *(__int64 (**)(void))(v9 + 48)) != nullptr )
      {
        v11 = a4;
        v12 = v5;
        v13 = a2;
        if ( *((_DWORD *)v10 - 1) != 1831526433 )
          __break(0x8228u);
        v8 = v10();
        a2 = v13;
        v5 = v12;
        a4 = v11;
      }
      else
      {
        v8 = 0;
      }
    }
    *(_QWORD *)(a2 + 12) = v8;
    *(_DWORD *)a2 = 5;
    memcpy((void *)(a2 + 28), *(const void **)(a4 + 8), v5);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&snapshot_preemption_record__rs_0, "snapshot_preemption_record") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "PREEMPTION RECORD");
    return 0;
  }
  return v6;
}
