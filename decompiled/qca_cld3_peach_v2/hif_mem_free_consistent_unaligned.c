__int64 __fastcall hif_mem_free_consistent_unaligned(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        char a6)
{
  __int64 (__fastcall *v6)(_QWORD); // x8

  if ( !a6 )
    return _qdf_mem_free_consistent(*(_QWORD *)(a1 + 576), *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), a2, a3, a4, a5);
  v6 = *(__int64 (__fastcall **)(_QWORD))(a1 + 2528);
  if ( !v6 )
    return qdf_trace_msg(69, 3, "%s: dp_prealloc_put_consistent_unligned NULL", "hif_mem_free_consistent_unaligned");
  if ( *((_DWORD *)v6 - 1) != 251140989 )
    __break(0x8228u);
  return v6(a3);
}
