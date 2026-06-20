unsigned __int64 __fastcall thermal_pause_register_cdev(unsigned __int64 result)
{
  unsigned __int64 v1; // x19

  if ( (*(_DWORD *)(result - 56) & ~_cpu_online_mask) == 0 )
  {
    v1 = result;
    result = thermal_of_cooling_device_register(*(_QWORD *)(result - 32), v1 - 24, v1 - 72, thermal_pause_cooling_ops);
    *(_QWORD *)(v1 - 40) = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      result = printk(&unk_6B49, "thermal_pause", "thermal_pause_register_cdev", v1 - 24, result);
      *(_QWORD *)(v1 - 40) = 0;
    }
  }
  return result;
}
