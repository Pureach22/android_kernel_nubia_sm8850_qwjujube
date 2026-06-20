__int64 __fastcall free_event_data(__int64 a1)
{
  __int64 v2; // x9
  __int64 v3; // x0
  void (__fastcall *v4)(_QWORD); // x9
  __int64 v5; // x0
  char v6; // w8
  unsigned __int64 v7; // x8
  __int64 v8; // x23
  unsigned __int64 v9; // x20
  __int64 v10; // x24
  _QWORD **v11; // x0

  if ( *(_QWORD *)(a1 + 48) )
  {
    if ( !*(_DWORD *)(a1 + 32) )
    {
      __break(0x800u);
      v5 = *(unsigned int *)(a1 + 56);
      if ( !(_DWORD)v5 )
        goto LABEL_8;
      goto LABEL_7;
    }
    v2 = **(_QWORD **)(coresight_get_sink(*(_QWORD *)(_per_cpu_offset[__clz(__rbit64(*(unsigned int *)(a1 + 32)))]
                                                    + *(_QWORD *)(a1 + 64)))
                     + 24);
    v3 = *(_QWORD *)(a1 + 48);
    v4 = *(void (__fastcall **)(_QWORD))(v2 + 24);
    if ( *((_DWORD *)v4 - 1) != 251140989 )
      __break(0x8229u);
    v4(v3);
  }
  v5 = *(unsigned int *)(a1 + 56);
  if ( (_DWORD)v5 )
LABEL_7:
    v5 = cscfg_deactivate_config();
LABEL_8:
  v6 = 0;
  do
  {
    v7 = (unsigned int)(-1LL << v6) & *(_DWORD *)(a1 + 32);
    if ( !(_DWORD)v7 )
      break;
    v8 = *(_QWORD *)(a1 + 64);
    v9 = __clz(__rbit64(v7));
    v10 = _per_cpu_offset[v9];
    v11 = *(_QWORD ***)(v10 + v8);
    if ( v11 && (unsigned __int64)v11 <= 0xFFFFFFFFFFFFF000LL )
      coresight_release_path(v11);
    *(_QWORD *)(v8 + v10) = 0;
    v5 = coresight_trace_id_put_cpu_id((unsigned int)v9);
    v6 = v9 + 1;
  }
  while ( v9 < 0x1F );
  coresight_trace_id_perf_stop(v5);
  free_percpu(*(_QWORD *)(a1 + 64));
  return kfree(a1);
}
