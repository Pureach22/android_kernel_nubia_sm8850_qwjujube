__int64 __fastcall tdls_set_operation_mode(__int64 a1)
{
  __int64 v1; // x20
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  unsigned int v15; // w20

  if ( a1 )
  {
    v1 = *(_QWORD *)a1;
    if ( !*(_QWORD *)a1 )
    {
      v15 = 4;
LABEL_14:
      _qdf_mem_free(a1);
      return v15;
    }
    if ( wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu) )
    {
      v12 = *(_QWORD *)(v1 + 216);
      if ( v12 && (v13 = *(_QWORD *)(v12 + 80)) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
        if ( comp_private_obj )
        {
          v3 = (unsigned int *)*(unsigned int *)(v1 + 16);
          if ( ((unsigned int)v3 & 0xFFFFFFFD) == 0 )
          {
            tdls_set_current_mode(comp_private_obj, *(unsigned int *)(a1 + 8));
            v15 = 0;
LABEL_13:
            wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, v3, v4, v5, v6, v7, v8, v9, v10, v11);
            goto LABEL_14;
          }
        }
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_vdev_get_tdls_soc_obj");
      }
    }
    v15 = 16;
    goto LABEL_13;
  }
  return 4;
}
