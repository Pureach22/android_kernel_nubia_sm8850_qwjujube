__int64 __fastcall wlan_util_pdev_vdevs_deschan_match(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  _QWORD v24[3]; // [xsp+8h] [xbp-18h] BYREF

  v24[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 15) & 8) == 0
      && ((v24[0] = 0, (unsigned int)wlan_objmgr_vdev_try_get_ref(a2, a3, a4, a5, a6, a7, a8, a9, a10, a11))
       || (LOBYTE(v24[0]) = 0,
           v24[1] = a2,
           wlan_objmgr_pdev_iterate_obj_list(
             a1,
             2,
             (void (__fastcall *)(__int64, __int64, __int64))wlan_pdev_chan_match,
             (__int64)v24,
             0,
             a3),
           wlan_objmgr_vdev_release_ref(a2, a3, v14, v15, v16, v17, v18, v19, v20, v21, v22),
           LOBYTE(v24[0]))) )
    {
      result = 16;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
