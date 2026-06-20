__int64 __fastcall wlan_cfr_pdev_obj_destroy_handler(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  __int64 v19; // x19
  __int64 v20; // x0
  unsigned __int64 v21; // x20

  if ( a1 )
  {
    if ( (wlan_cfr_is_feature_disabled(a1) & 1) != 0 )
    {
      qdf_trace_msg(
        0x6Au,
        4u,
        "%s: cfr is disabled",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_cfr_pdev_obj_destroy_handler");
      return 11;
    }
    else
    {
      result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
      if ( result )
      {
        v19 = result;
        qdf_runtime_lock_deinit((__int64 *)(result + 1928));
        _qdf_wake_lock_destroy(v19 + 1728);
        wlan_objmgr_pdev_component_obj_detach(a1, 0x1Eu, v19);
        v20 = *(_QWORD *)(v19 + 72);
        if ( v20 )
        {
          if ( *(_DWORD *)(v19 + 80) )
          {
            v21 = 0;
            do
              _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v19 + 72) + 8 * v21++));
            while ( v21 < *(unsigned int *)(v19 + 80) );
            v20 = *(_QWORD *)(v19 + 72);
          }
          _qdf_mem_free(v20);
        }
        _qdf_mem_free(v19);
        return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: PDEV is NULL\n", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_pdev_obj_destroy_handler");
    return 16;
  }
  return result;
}
