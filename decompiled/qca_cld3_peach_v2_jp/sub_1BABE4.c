__int64 __fastcall sub_1BABE4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { SYSL            X2, #1, c7, c1, #2 }
  return wlan_serialization_remove_cmd_from_vdev_queue(a1, a2, a3, a4);
}
