unsigned __int64 __fastcall cpu_hot_register_cdev(__int64 a1)
{
  unsigned __int64 result; // x0

  result = thermal_of_cooling_device_register(*(_QWORD *)(a1 - 32), a1 - 24, a1 - 64, cpu_hot_cooling_ops);
  *(_QWORD *)(a1 - 40) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_685E, a1 - 24, result);
    *(_QWORD *)(a1 - 40) = 0;
  }
  return result;
}
