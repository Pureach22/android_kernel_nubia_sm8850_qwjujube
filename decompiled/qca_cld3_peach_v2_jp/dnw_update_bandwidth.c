__int64 __fastcall dnw_update_bandwidth(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 priv_fl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 comp_private_obj; // x0
  unsigned __int64 v23; // x8
  const char *v24; // x2
  const char *v25; // x3

  if ( a1 && !(unsigned int)wlan_objmgr_vdev_try_get_ref(a1, 0x60u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    priv_fl = pre_cac_vdev_get_priv_fl(a1, (__int64)"wlan_get_dnw_vdev_info", 0x24u);
    if ( priv_fl )
    {
      if ( *(_QWORD *)(a1 + 152) )
      {
        v21 = priv_fl;
        comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(*(_QWORD *)(a1 + 152), 0x2Du);
        if ( comp_private_obj )
        {
          v23 = *(unsigned __int8 *)(comp_private_obj + 17);
          if ( (_DWORD)v23 == 1 )
          {
            v23 = *(unsigned __int8 *)(v21 + 32);
            if ( (_DWORD)v23 == 1 )
            {
              v23 = *(unsigned int *)(comp_private_obj + 24);
              if ( (_DWORD)v23 == a2 )
              {
                v23 = (unsigned int)(*(_DWORD *)(comp_private_obj + 36) - 1);
                if ( (unsigned int)v23 <= 1 )
                  a2 = *(_DWORD *)(comp_private_obj + 28);
              }
            }
          }
          goto LABEL_16;
        }
        v24 = "%s: NULL pre cac pdev priv";
      }
      else
      {
        v24 = "%s: NULL pdev";
      }
      v25 = "wlan_get_dnw_pdev_info_by_vdev";
    }
    else
    {
      v24 = "%s: NULL pre cac vdev priv";
      v25 = "wlan_get_dnw_vdev_info";
    }
    qdf_trace_msg(0x98u, 2u, v24, v13, v14, v15, v16, v17, v18, v19, v20, v25);
LABEL_16:
    wlan_objmgr_vdev_release_ref(a1, 0x60u, (unsigned int *)v23, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  return a2;
}
