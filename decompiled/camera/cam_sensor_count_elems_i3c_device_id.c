__int64 __fastcall cam_sensor_count_elems_i3c_device_id(__int64 a1, int *a2, __int64 a3)
{
  int v5; // w7
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x4

  if ( !a2 )
  {
    v7 = "Num_entries ptr is null";
    v8 = 24;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_count_elems_i3c_device_id",
      v8,
      v7);
    return 4294967274LL;
  }
  if ( !a1 )
  {
    v7 = "dev ptr is null";
    v8 = 29;
    goto LABEL_10;
  }
  if ( !a3 )
  {
    v7 = "sensor_id_table_str ptr is null";
    v8 = 34;
    goto LABEL_10;
  }
  v5 = of_property_count_elems_of_size(a1, a3, 4);
  *a2 = v5;
  if ( v5 <= 0 )
  {
    result = 4294967294LL;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_count_elems_i3c_device_id",
        42,
        "Failed while reading the property for dev: %s num_entries:%d",
        *(const char **)(a1 + 16),
        v5);
      return 4294967294LL;
    }
  }
  else if ( (unsigned int)v5 < 0x20 )
  {
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_count_elems_i3c_device_id",
      49,
      "Num_entries are more than MAX_I3C_DEVICE_ID_ENTRIES for dev: %s",
      *(const char **)(a1 + 16));
    return 4294967284LL;
  }
  return result;
}
