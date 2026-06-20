void *__fastcall snapshot_preemption_record(_QWORD *a1, _QWORD *a2, _QWORD *a3, size_t a4, size_t a5)
{
  size_t v5; // x8
  size_t v6; // x19
  size_t v7; // x8
  bool v8; // cf
  _QWORD *v9; // x20
  void *result; // x0
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  _QWORD *v16; // x21
  _QWORD *v17; // x22
  size_t v18; // x23
  __int64 v19; // x10
  __int64 v20; // x9

  v5 = a3[5];
  if ( a1[1414] >= a5 )
    v6 = a5;
  else
    v6 = a1[1414];
  v8 = v5 >= v6;
  v7 = v5 - v6;
  v8 = v8 && v7 >= a4;
  if ( !v8 )
  {
    v9 = a3;
    result = (void *)__ratelimit(&snapshot_preemption_record__rs, "snapshot_preemption_record");
    if ( (_DWORD)result )
    {
      result = (void *)_warn_printk(
                         "Invalid preemption context record size: md_size: 0x%llx, ctxt_record_size: 0x%llx\n",
                         v9[5],
                         v6);
      __break(0x800u);
    }
    return result;
  }
  if ( a2[12] >= v6 + 36 )
  {
    v12 = a2[11];
    *(_DWORD *)v12 = 184724429;
    *(_DWORD *)(v12 + 4) = v6 + 36;
    *(_QWORD *)(v12 + 28) = v6 >> 2;
    *(_QWORD *)(v12 + 12) = a3[3] + a4;
    v13 = a1[9];
    if ( v13 )
    {
      v14 = *(_QWORD *)(v13 + 96);
      if ( v14 )
      {
        v15 = *(__int64 (**)(void))(v14 + 48);
        v16 = a2;
        if ( v15 )
        {
          v17 = a3;
          v18 = a4;
          if ( *((_DWORD *)v15 - 1) != 1831526433 )
            __break(0x8228u);
          v13 = v15();
          a4 = v18;
          a3 = v17;
          goto LABEL_22;
        }
      }
      else
      {
        v16 = a2;
      }
      v13 = 0;
    }
    else
    {
      v16 = a2;
    }
LABEL_22:
    *(_QWORD *)(v12 + 20) = v13;
    *(_DWORD *)(v12 + 8) = 5;
    result = memcpy((void *)(v12 + 36), (const void *)(a3[1] + a4), v6);
    v19 = v16[10];
    v20 = v16[12];
    v16[11] += *(unsigned int *)(v12 + 4);
    v16[12] = v20 - *(unsigned int *)(v12 + 4);
    v16[10] = v19 + *(unsigned int *)(v12 + 4);
    return result;
  }
  result = (void *)__ratelimit(&snapshot_preemption_record__rs_9, "snapshot_preemption_record");
  if ( (_DWORD)result )
    return (void *)dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "PREEMPTION RECORD");
  return result;
}
