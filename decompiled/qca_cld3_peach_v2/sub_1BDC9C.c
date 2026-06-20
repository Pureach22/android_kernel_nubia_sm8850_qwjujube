__int64 __fastcall sub_1BDC9C(__int64 a1, __int64 a2, __int64 a3, long double a4)
{
  __int64 v4; // x11
  __int128 v5; // q10

  *(_OWORD *)(v4 - 480) = v5;
  *(long double *)(v4 - 464) = a4;
  return wlan_objmgr_unregister_vdev_create_handler(a1, a2, a3);
}
