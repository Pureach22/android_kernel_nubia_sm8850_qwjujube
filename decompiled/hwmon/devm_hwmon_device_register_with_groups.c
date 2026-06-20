__int64 __fastcall devm_hwmon_device_register_with_groups(__int64 a1, char *a2, _QWORD *a3, __int64 a4)
{
  __int64 v8; // x0
  _QWORD *v9; // x23
  const char **v10; // x0
  __int64 v11; // x19
  const char **v13; // x20

  if ( !a1 )
    return -22;
  v8 = _devres_alloc_node(devm_hwmon_release, 8, 3264, 0xFFFFFFFFLL, "devm_hwmon_release");
  if ( !v8 )
    return -12;
  if ( !a2 )
  {
    v11 = -22;
    goto LABEL_9;
  }
  v9 = (_QWORD *)v8;
  v10 = _hwmon_device_register(a1, a2, a3, nullptr, a4);
  if ( (unsigned __int64)v10 > 0xFFFFFFFFFFFFF000LL )
  {
    v11 = (__int64)v10;
    v8 = (__int64)v9;
LABEL_9:
    devres_free(v8);
    return v11;
  }
  *v9 = v10;
  v13 = v10;
  devres_add(a1, v9);
  return (__int64)v13;
}
