__int64 __fastcall hdd_wmm_free_context(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v11; // x20
  _QWORD *v12; // x8
  __int64 v13; // x9

  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: Entered, context %pK",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hdd_wmm_free_context",
             a1);
  if ( a1 && *(_DWORD *)(a1 + 72) == 1464683864 )
  {
    v11 = *(_QWORD *)(a1 + 24);
    mutex_lock(v11 + 1832);
    v12 = *(_QWORD **)(a1 + 8);
    *(_DWORD *)(a1 + 72) = 0;
    if ( *v12 == a1 && (v13 = *(_QWORD *)a1, *(_QWORD *)(*(_QWORD *)a1 + 8LL) == a1) )
    {
      *(_QWORD *)(v13 + 8) = v12;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
    }
    *(_QWORD *)a1 = 0xDEAD000000000100LL;
    *(_QWORD *)(a1 + 8) = 0xDEAD000000000122LL;
    mutex_unlock(v11 + 1832);
    return _qdf_mem_free(a1);
  }
  return result;
}
