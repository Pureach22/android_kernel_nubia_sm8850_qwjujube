_QWORD *__fastcall adreno_hwsched_replay(_QWORD *result)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x24
  __int64 v3; // x19
  __int64 v4; // x23
  int v5; // w25
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  _QWORD *v7; // x28
  __int64 v8; // x22
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  bool v11; // w21
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x20
  void (__fastcall *v15)(__int64, __int64); // x8
  __int64 v16; // x1
  unsigned __int64 v23; // x10
  unsigned __int64 v26; // x9

  v1 = (_QWORD *)result[2846];
  v2 = result + 2846;
  v3 = (__int64)result;
  v4 = *(_QWORD *)(result[1783] + 40LL);
  if ( v1 == result + 2846 )
  {
    v11 = 1;
    v12 = result[2855];
    if ( !v12 )
      goto LABEL_14;
  }
  else
  {
    v5 = 0;
    do
    {
      v7 = (_QWORD *)*v1;
      v8 = *(v1 - 1);
      if ( (adreno_hwsched_drawobj_replay(v3, v8) & 1) != 0 )
      {
        v6 = **(__int64 (__fastcall ***)(__int64, __int64))(v3 + 22784);
        if ( *((_DWORD *)v6 - 1) != -1013122788 )
          __break(0x8228u);
        result = (_QWORD *)v6(v3, v8);
      }
      else
      {
        v9 = (_QWORD *)v1[1];
        if ( (_QWORD *)*v9 == v1 && (v10 = (_QWORD *)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
        {
          v10[1] = v9;
          *v9 = v10;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
        }
        *v1 = v1;
        ++v5;
        v1[1] = v1;
        result = (_QWORD *)kmem_cache_free(obj_cache, v1 - 1);
        --*(_DWORD *)(v3 + 22504);
      }
      v1 = v7;
    }
    while ( v7 != v2 );
    v11 = v5 == 0;
    v12 = *(_QWORD *)(v3 + 22840);
    if ( !v12 )
    {
LABEL_14:
      if ( v11 )
        return result;
      return (_QWORD *)kgsl_process_event_groups(v3);
    }
  }
  v13 = *(_QWORD *)(v12 + 8);
  if ( !v13 || (*(_QWORD *)(v13 + 32) & 4) != 0 )
  {
    _X8 = (unsigned __int64 *)(v12 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
    _X8 = (unsigned __int64 *)(*(_QWORD *)(v3 + 22840) + 56LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 | 0x40, _X8) );
    v14 = 4;
  }
  else
  {
    v14 = 3;
  }
  v15 = *(void (__fastcall **)(__int64, __int64))(v4 + 224);
  v16 = *(_QWORD *)(v3 + 22840);
  if ( *((_DWORD *)v15 - 1) != -348536088 )
    __break(0x8228u);
  v15(v3, v16);
  result = (_QWORD *)srcu_notifier_call_chain(v3 + 13424, v14, 0);
  if ( !v11 )
    return (_QWORD *)kgsl_process_event_groups(v3);
  return result;
}
