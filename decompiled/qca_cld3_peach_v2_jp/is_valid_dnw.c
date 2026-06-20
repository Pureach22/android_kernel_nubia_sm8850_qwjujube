bool __fastcall is_valid_dnw(
        __int64 a1,
        int a2,
        int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _BOOL4 v24; // w20
  unsigned int *comp_private_obj; // x0
  unsigned int *v26; // x8
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  if ( !(unsigned int)wlan_objmgr_pdev_try_get_ref(a1, 0x60u, a5, a6, a7, a8, a9, a10, a11, a12) )
  {
    if ( a1 )
    {
      comp_private_obj = (unsigned int *)wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Du);
      if ( comp_private_obj )
      {
        v26 = (unsigned int *)comp_private_obj[52];
        if ( (_DWORD)v26 == a2 )
        {
          v26 = (unsigned int *)comp_private_obj[53];
          if ( (_DWORD)v26 == a4 )
          {
            v26 = (unsigned int *)comp_private_obj[54];
            v24 = (_DWORD)v26 == a3;
LABEL_12:
            wlan_objmgr_pdev_release_ref(a1, 0x60u, v26, v16, v17, v18, v19, v20, v21, v22, v23);
            return v24;
          }
        }
LABEL_11:
        v24 = 0;
        goto LABEL_12;
      }
      v27 = "%s: NULL pre cac pdev priv";
    }
    else
    {
      v27 = "%s: NULL pdev";
    }
    qdf_trace_msg(0x98u, 2u, v27, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_get_dnw_pdev_info");
    qdf_trace_msg(0x98u, 2u, "%s: NULL dnw vdev info", v28, v29, v30, v31, v32, v33, v34, v35, "is_valid_dnw");
    goto LABEL_11;
  }
  qdf_trace_msg(0x98u, 2u, "%s: vdev ref fail", v16, v17, v18, v19, v20, v21, v22, v23, "is_valid_dnw");
  return 0;
}
