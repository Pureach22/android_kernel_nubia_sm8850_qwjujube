bool __fastcall stm_heartbeat_hrtimer_handler(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0

  v2 = stm_source_write(a1 - 48, 0, "heartbeat stm source driver is here to serve you", 49);
  if ( !*(_DWORD *)(a1 + 64) )
    return 0;
  v3 = 1000000LL * interval_ms;
  v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 48) + 48LL);
  if ( *((_DWORD *)v4 - 1) != -432005955 )
    __break(0x8228u);
  v5 = v4(v2);
  hrtimer_forward(a1, v5, v3);
  return *(_DWORD *)(a1 + 64) != 0;
}
