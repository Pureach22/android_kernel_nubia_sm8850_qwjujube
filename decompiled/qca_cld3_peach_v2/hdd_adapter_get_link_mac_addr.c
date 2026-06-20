__int64 *__fastcall hdd_adapter_get_link_mac_addr(
        __int64 *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 *v10; // x8
  __int64 *v11; // x20
  char is_mlo_vdev; // w8

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v9 = *result;
    v10 = result;
    if ( (*(_BYTE *)(*result + 52800) & 1) == 0
      || (result += 9, !(*((_DWORD *)v10 + 18) | *((unsigned __int16 *)v10 + 38)))
      || *((unsigned __int8 *)v10 + 8) != 255
      && (v11 = result,
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v10[4], a2, a3, a4, a5, a6, a7, a8, a9),
          result = v11,
          (is_mlo_vdev & 1) == 0) )
    {
      result = (__int64 *)(v9 + 1617);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
