__int64 __fastcall dp_enable_mon_reap_timer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        char a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  const char *v14; // x2
  __int64 v15; // x8
  char v16; // w0
  const char *v17; // x3

  v11 = *(_QWORD *)(a1 + 20112);
  if ( (a11 & 1) == 0 )
  {
    if ( v11 )
    {
      v15 = *(_QWORD *)(v11 + 416);
      if ( v15 )
      {
        v13 = *(__int64 (**)(void))(v15 + 536);
        if ( v13 )
          goto LABEL_9;
      }
      v14 = "%s: callback not registered";
    }
    else
    {
      v14 = "%s: monitor soc is NULL";
    }
    v17 = "dp_monitor_reap_timer_stop";
    goto LABEL_17;
  }
  if ( !v11 )
  {
    v14 = "%s: monitor soc is NULL";
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(v11 + 416);
  if ( !v12 || (v13 = *(__int64 (**)(void))(v12 + 528)) == nullptr )
  {
    v14 = "%s: callback not registered";
LABEL_14:
    v17 = "dp_monitor_reap_timer_start";
LABEL_17:
    qdf_trace_msg(0x92u, 8u, v14, a2, a3, a4, a5, a6, a7, a8, a9, v17);
    v16 = 0;
    return v16 & 1;
  }
LABEL_9:
  if ( *((_DWORD *)v13 - 1) != 460609471 )
    __break(0x8228u);
  v16 = v13();
  return v16 & 1;
}
