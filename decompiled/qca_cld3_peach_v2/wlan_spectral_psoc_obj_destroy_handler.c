__int64 __fastcall wlan_spectral_psoc_obj_destroy_handler(
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
  _QWORD *v19; // x19

  if ( a1 )
  {
    if ( (wlan_spectral_is_feature_disabled_psoc(a1) & 1) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral feature is disabled",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_spectral_psoc_obj_destroy_handler");
      return 39;
    }
    else
    {
      result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x13u);
      if ( result )
      {
        v19 = (_QWORD *)result;
        wlan_objmgr_psoc_component_obj_detach(a1, 0x13u, result);
        v19[7] = 0;
        v19[8] = 0;
        v19[9] = 0;
        v19[10] = 0;
        v19[11] = 0;
        v19[12] = 0;
        v19[13] = 0;
        v19[14] = 0;
        v19[15] = 0;
        v19[16] = 0;
        v19[17] = 0;
        v19[18] = 0;
        v19[19] = 0;
        v19[20] = 0;
        v19[21] = 0;
        _qdf_mem_free((__int64)v19);
        return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: PSOC is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_spectral_psoc_obj_destroy_handler");
    return 16;
  }
  return result;
}
