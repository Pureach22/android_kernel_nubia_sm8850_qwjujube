__int64 __fastcall devm_hwmon_device_register_with_info(__int64 a1, char *a2, _QWORD *a3, _QWORD *a4, __int64 a5)
{
  __int64 v10; // x0
  unsigned __int64 v11; // x8
  _QWORD *v12; // x24
  unsigned __int64 v14; // x19
  unsigned __int64 v15; // x20

  if ( !a1 )
    return -22;
  v10 = _devres_alloc_node(devm_hwmon_release, 8, 3264, 0xFFFFFFFFLL, "devm_hwmon_release");
  if ( !v10 )
    return -12;
  v11 = -22;
  if ( a2 && a4 )
  {
    if ( *a4 && *(_QWORD *)*a4 && a4[1] )
    {
      v12 = (_QWORD *)v10;
      v11 = (unsigned __int64)_hwmon_device_register(a1, a2, a3, a4, a5);
      if ( v11 <= 0xFFFFFFFFFFFFF000LL )
      {
        *v12 = v11;
        v15 = v11;
        devres_add(a1, v12);
        return v15;
      }
      v10 = (__int64)v12;
    }
    else
    {
      v11 = -22;
    }
  }
  v14 = v11;
  devres_free(v10);
  return v14;
}
