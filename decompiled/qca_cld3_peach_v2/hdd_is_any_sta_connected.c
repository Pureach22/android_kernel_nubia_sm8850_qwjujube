bool __fastcall hdd_is_any_sta_connected(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int first_connected_sta_cli_vdev_id; // w0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  first_connected_sta_cli_vdev_id = hdd_get_first_connected_sta_cli_vdev_id(a1, &v11, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  _ReadStatusReg(SP_EL0);
  return first_connected_sta_cli_vdev_id == 0;
}
