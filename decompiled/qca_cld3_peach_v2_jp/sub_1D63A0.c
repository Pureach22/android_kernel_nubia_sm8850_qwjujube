__int64 __fastcall sub_1D63A0(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { LDLAR           X0, [X24] }
  return wlan_util_vdev_get_param(_X0, a2, a3);
}
