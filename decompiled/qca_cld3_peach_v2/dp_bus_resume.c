__int64 __fastcall dp_bus_resume(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  unsigned int multiplier; // w0
  __int64 v13; // x8
  __int64 v14; // x8
  void (__fastcall *v15)(__int64, __int64); // x8
  const char *v16; // x2
  _DWORD *v17; // x8

  if ( a2 || !*(_QWORD *)(a1 + 72) )
  {
    qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_bus_resume");
    return 4;
  }
  if ( *(_BYTE *)(a1 + 17840) == 2 )
  {
    v11 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    mod_timer(a1 + 17784, v11 + 2LL * multiplier);
  }
  v13 = *(_QWORD *)(a1 + 20112);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v13 + 416);
    if ( v14 )
    {
      v15 = *(void (__fastcall **)(__int64, __int64))(v14 + 528);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != 460609471 )
          __break(0x8228u);
        v15(a1, 4);
        goto LABEL_14;
      }
    }
    v16 = "%s: callback not registered";
  }
  else
  {
    v16 = "%s: monitor soc is NULL";
  }
  qdf_trace_msg(0x92u, 8u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_reap_timer_start");
LABEL_14:
  v17 = *(_DWORD **)(a1 + 1816);
  if ( *(v17 - 1) != 357773931 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v17)(a1, 0);
  return 0;
}
