__int64 __fastcall cam_sensor_get_ois_dev(__int64 a1, __int64 a2)
{
  __int64 device_by_node; // x0
  __int64 result; // x0
  const char *v5; // x5
  __int64 v6; // x1
  __int64 v7; // x4
  _QWORD v8[11]; // [xsp+8h] [xbp-58h] BYREF

  v8[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v5 = "of_node is null";
    v6 = 0x800000000LL;
    v7 = 121;
    goto LABEL_11;
  }
  memset(v8, 0, 80);
  if ( !(unsigned int)_of_parse_phandle_with_args(a1, "ois-src", 0, 0, 0, v8) && v8[0] )
  {
    device_by_node = of_find_device_by_node();
    *(_QWORD *)(a2 + 7904) = device_by_node;
    if ( device_by_node )
    {
      result = 0;
      goto LABEL_12;
    }
    v5 = ": can't find the device by node";
    v6 = 32;
    v7 = 132;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v6,
      1,
      "cam_sensor_get_ois_dev",
      v7,
      v5);
    result = 4294967274LL;
    goto LABEL_12;
  }
  result = 0;
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_get_ois_dev",
      128,
      "ois src_node NULL");
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
