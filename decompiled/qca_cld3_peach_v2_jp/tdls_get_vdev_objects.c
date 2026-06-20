__int64 __fastcall tdls_get_vdev_objects(__int64 a1, __int64 *a2, __int64 *a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0

  if ( !a1 )
    return 16;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
  *a2 = comp_private_obj;
  if ( comp_private_obj )
  {
    v15 = *(_QWORD *)(a1 + 152);
    if ( v15 && (v16 = *(_QWORD *)(v15 + 80)) != 0 )
    {
      v17 = wlan_objmgr_psoc_get_comp_private_obj(v16, 0xAu);
      *a3 = v17;
      if ( v17 )
        return 16 * (unsigned int)((*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", v7, v8, v9, v10, v11, v12, v13, v14, "wlan_vdev_get_tdls_soc_obj");
      *a3 = 0;
    }
  }
  return 16;
}
