__int64 __fastcall tz_handler(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  char v8; // w8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8

  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 160) + 744LL), "qcom,kgsl-3d0") )
    return 4294967274LL;
  result = 0;
  if ( a2 > 3 )
  {
    if ( a2 == 4 )
    {
      v7 = *(_QWORD *)(a1 + 1184);
      if ( v7 )
      {
        v8 = *(_BYTE *)(v7 + 148);
        __dmb(2u);
        if ( (v8 & 1) != 0 )
        {
          qcom_scm_dcvs_reset(0);
        }
        else
        {
          v9 = raw_spin_lock(&tz_lock);
          qcom_scm_io_reset(v9);
          raw_spin_unlock(&tz_lock);
        }
        *(_QWORD *)(v7 + 24) = 0;
        *(_QWORD *)(v7 + 32) = 0;
      }
      v10 = raw_spin_lock(&suspend_lock);
      v11 = (unsigned __int128)(ktime_get(v10) * (__int128)0x431BDE82D7B634DBLL) >> 64;
      suspend_start = (v11 >> 18) + ((unsigned __int64)v11 >> 63);
    }
    else
    {
      if ( a2 != 5 )
        return result;
      v5 = raw_spin_lock(&suspend_lock);
      v6 = suspend_start;
      if ( suspend_start )
        v6 = ktime_get(v5) / 1000000 - suspend_start;
      suspend_start = 0;
      suspend_time += v6;
    }
    raw_spin_unlock(&suspend_lock);
    return 0;
  }
  if ( a2 == 1 )
  {
    result = _tz_init(a1);
    if ( (_DWORD)result )
      return result;
    device_create_file(a1 + 64, &dev_attr_gpu_load);
    device_create_file(a1 + 64, &dev_attr_suspend_time);
    device_create_file(a1 + 64, &dev_attr_mod_percent);
    return 0;
  }
  if ( a2 == 2 )
  {
    raw_spin_lock(&suspend_lock);
    suspend_start = 0;
    raw_spin_unlock(&suspend_lock);
    device_remove_file(a1 + 64, &dev_attr_gpu_load);
    device_remove_file(a1 + 64, &dev_attr_suspend_time);
    device_remove_file(a1 + 64, &dev_attr_mod_percent);
    *(_QWORD *)(a1 + 1184) = 0;
    return 0;
  }
  return result;
}
