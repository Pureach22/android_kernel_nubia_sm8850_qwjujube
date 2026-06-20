__int64 __fastcall cam_cpastop_setup_qos_settings(__int64 a1, int a2)
{
  _QWORD *v2; // x20
  int v3; // w6
  void *v5; // x8
  int v6; // w19
  __int64 v7; // x21

  v2 = *(_QWORD **)(a1 + 3680);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v6 = a2;
    v7 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpastop_setup_qos_settings",
      1810,
      "QoS selection : hw_version=0x%x selection_mask 0x%x",
      *(_DWORD *)(a1 + 112),
      a2);
    a1 = v7;
    a2 = v6;
  }
  v3 = *(_DWORD *)(a1 + 112);
  if ( v3 == 5767424 )
  {
    if ( (a2 & 2) != 0 )
    {
      v5 = &cam580_custom_hw_info;
    }
    else
    {
      if ( (a2 & 1) == 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpastop_setup_qos_settings",
          1830,
          "Invalid selection mask 0x%x for hw 0x%x",
          a2,
          5767424);
        return 0;
      }
      v5 = &cam580_cpas100_hw_info;
    }
  }
  else
  {
    if ( v3 != 4718848 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        2,
        "cam_cpastop_setup_qos_settings",
        1834,
        "QoS selection not supported for 0x%x",
        v3);
      return 4294967274LL;
    }
    if ( (a2 & 2) != 0 )
    {
      v5 = &cam480_custom_hw_info;
    }
    else
    {
      if ( (a2 & 1) == 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpastop_setup_qos_settings",
          1820,
          "Invalid selection mask 0x%x",
          a2);
        return 0;
      }
      v5 = &cam480_cpas100_hw_info;
    }
  }
  *v2 = v5;
  return 0;
}
