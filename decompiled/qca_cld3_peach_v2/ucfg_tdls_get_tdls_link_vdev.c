__int64 __fastcall ucfg_tdls_get_tdls_link_vdev(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20

  result = tdls_mlo_get_tdls_link_vdev(a1);
  if ( result )
  {
    v12 = result;
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(result, a2, v4, v5, v6, v7, v8, v9, v10, v11) )
      return 0;
    else
      return v12;
  }
  return result;
}
