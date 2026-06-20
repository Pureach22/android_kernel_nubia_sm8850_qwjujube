__int64 __fastcall icnss_get_temperature(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned __int64 zone_by_name; // x0
  unsigned __int64 v4; // x19
  const char *v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  v5[0] = nullptr;
  result = of_property_read_string(*(_QWORD *)(v1 + 760), "tsens", v5);
  if ( !(_DWORD)result )
  {
    ipc_log_string(icnss_ipc_log_context, "icnss2: Thermal Sensor is %s\n", v5[0]);
    zone_by_name = thermal_zone_get_zone_by_name(v5[0]);
    if ( zone_by_name && zone_by_name < 0xFFFFFFFFFFFFF001LL )
    {
      result = thermal_zone_get_temp();
      if ( !(_DWORD)result )
        goto LABEL_5;
      v4 = (unsigned int)result;
      printk("%sicnss2: Fail to get temperature. ret: %d", byte_130B32, result);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Fail to get temperature. ret: %d", (const char *)&unk_12DBF3, v4);
    }
    else
    {
      v4 = zone_by_name;
      printk("%sicnss2: Fail to get thermal zone. ret: %ld", byte_130B32, zone_by_name);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Fail to get thermal zone. ret: %ld",
        (const char *)&unk_12DBF3,
        v4);
    }
    result = v4;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
