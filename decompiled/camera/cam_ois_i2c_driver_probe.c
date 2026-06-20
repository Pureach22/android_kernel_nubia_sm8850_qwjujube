__int64 __fastcall cam_ois_i2c_driver_probe(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  unsigned int v4; // w19

  if ( a1 )
  {
    v2 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL) + 32LL);
    if ( *((_DWORD *)v2 - 1) != 2093148950 )
      __break(0x8228u);
    if ( (v2() & 1) != 0 )
    {
      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "cam_ois_i2c_driver_probe",
          332,
          "Adding sensor ois component");
      cam_soc_util_initialize_power_domain(a1 + 32);
      result = component_add(a1 + 32, cam_ois_i2c_component_ops);
      if ( (_DWORD)result )
      {
        v4 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_i2c_driver_probe",
          338,
          "failed to add component rc: %d",
          result);
        return v4;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_i2c_driver_probe",
        328,
        "%s :: i2c_check_functionality failed",
        (const char *)(a1 + 4));
      return 4294967282LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_i2c_driver_probe",
      322,
      "Invalid Args client: %pK",
      nullptr);
    return 4294967274LL;
  }
  return result;
}
