__int64 __fastcall dp_process_wow_ack_rsp(
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
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  const char *v18; // x2
  const char *v19; // x3
  unsigned int v20; // w0
  unsigned int v21; // w1

  if ( a2 || !*(_QWORD *)(a1 + 72) )
  {
    v18 = "%s: pdev is NULL";
    v19 = "dp_process_wow_ack_rsp";
    v20 = 69;
    v21 = 2;
    return qdf_trace_msg(v20, v21, v18, a3, a4, a5, a6, a7, a8, a9, a10, v19);
  }
  v10 = *(_QWORD *)(a1 + 20056);
  if ( !v10 )
  {
    v18 = "%s: monitor soc is NULL";
    goto LABEL_17;
  }
  v11 = *(_QWORD *)(v10 + 416);
  if ( !v11 || (v12 = *(__int64 (**)(void))(v11 + 536)) == nullptr )
  {
    v18 = "%s: callback not registered";
LABEL_17:
    v19 = "dp_monitor_reap_timer_stop";
LABEL_18:
    v20 = 146;
    v21 = 8;
    return qdf_trace_msg(v20, v21, v18, a3, a4, a5, a6, a7, a8, a9, a10, v19);
  }
  if ( *((_DWORD *)v12 - 1) != 460609471 )
    __break(0x8228u);
  result = v12();
  if ( (result & 1) != 0 )
  {
    v15 = *(_QWORD *)(a1 + 20056);
    if ( v15 )
    {
      v16 = *(_QWORD *)(v15 + 416);
      if ( v16 )
      {
        v17 = *(__int64 (__fastcall **)(__int64, __int64))(v16 + 240);
        if ( v17 )
        {
          if ( *((_DWORD *)v17 - 1) != -1990423103 )
            __break(0x8228u);
          return v17(a1, 1024);
        }
      }
      v18 = "%s: callback not registered";
    }
    else
    {
      v18 = "%s: monitor soc is NULL";
    }
    v19 = "dp_monitor_service_mon_rings";
    goto LABEL_18;
  }
  return result;
}
