__int64 __fastcall sub_2A603C(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0xB, unk_34C2E4 }
  return cam_sensor_core_power_up(a1, a2, a3);
}
