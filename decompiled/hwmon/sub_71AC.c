__int64 __fastcall sub_71AC(int a1)
{
  __asm { STTR            D18, [X27,#-0x54] }
  return hwmon_device_register_for_thermal(a1);
}
