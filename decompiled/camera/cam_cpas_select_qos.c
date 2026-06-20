__int64 __fastcall cam_cpas_select_qos(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  unsigned int v5; // w20
  _DWORD *v6; // x8

  v2 = *(_QWORD *)(a1 + 3680);
  mutex_lock(a1);
  if ( *(_DWORD *)(a1 + 92) == 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_select_qos",
      4134,
      "Hw already in power up state, can't change QoS settings");
    v5 = -22;
  }
  else
  {
    v6 = *(_DWORD **)(v2 + 8048);
    if ( v6 )
    {
      if ( *(v6 - 1) != -1929499818 )
        __break(0x8228u);
      v5 = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(a1, a2);
      if ( v5 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_select_qos",
          4143,
          "Failed in changing QoS %d",
          v5);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        2,
        "cam_cpas_select_qos",
        4145,
        "No ops for qos_settings");
      v5 = 0;
    }
  }
  mutex_unlock(a1);
  return v5;
}
