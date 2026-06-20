__int64 __fastcall sub_1CA7E8(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { STTR            Q26, [X28,#-0x6A] }
  return wlan_vdev_get_next_active_vdev_of_pdev(a1, a2, a3, a4);
}
