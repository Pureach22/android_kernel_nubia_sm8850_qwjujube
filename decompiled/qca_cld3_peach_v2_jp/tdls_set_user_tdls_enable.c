__int64 __fastcall tdls_set_user_tdls_enable(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 comp_private_obj; // x0
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  result = wlan_objmgr_vdev_try_get_ref(a1, 0x11u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    if ( a1 && wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu) )
    {
      v21 = *(_QWORD *)(a1 + 152);
      if ( v21 && (v22 = *(_QWORD *)(v21 + 80)) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v22, 0xAu);
        if ( comp_private_obj && (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
        {
          *(_BYTE *)(comp_private_obj + 625) = a2 & 1;
          qdf_trace_msg(
            0,
            8u,
            "%s: TDLS enable:%d via userspace",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "tdls_set_user_tdls_enable",
            a2 & 1);
          return wlan_objmgr_vdev_release_ref(a1, 0x11u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
        }
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_vdev_get_tdls_soc_obj");
      }
    }
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to get TDLS objects",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tdls_set_user_tdls_enable");
    return wlan_objmgr_vdev_release_ref(a1, 0x11u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
  }
  return result;
}
