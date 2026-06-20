_QWORD *__fastcall target_if_spectral_get_vdev(
        __int64 *a1,
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
  __int64 v10; // x19
  const char *v11; // x2
  _QWORD *result; // x0
  int v13; // w1
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *v31; // [xsp+0h] [xbp-10h] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = nullptr;
  if ( !a1 )
  {
    v11 = "%s: spectral variable in null.";
LABEL_7:
    qdf_trace_msg(0x56u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_spectral_get_vdev", v31, v32);
    goto LABEL_8;
  }
  v10 = *a1;
  if ( !*a1 )
  {
    v11 = "%s: pdev variable in null.";
    goto LABEL_7;
  }
  if ( a2 >= 2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_get_vdev",
      a2);
LABEL_8:
    result = nullptr;
    goto LABEL_9;
  }
  v13 = *((unsigned __int8 *)a1 + a2 + 360);
  if ( v13 != 255 )
  {
    result = wlan_objmgr_get_vdev_by_id_from_pdev(*a1, v13, 0x1Bu);
    goto LABEL_9;
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(*a1, 0x1Bu, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v11 = "%s: Unable to get pdev reference.";
    goto LABEL_7;
  }
  wlan_objmgr_pdev_iterate_obj_list(
    v10,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))target_if_spectral_get_firstvdev_pdev,
    (__int64)&v31,
    0,
    0x1Bu);
  wlan_objmgr_pdev_release_ref(v10, 0x1Bu, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  result = v31;
  if ( v31 )
  {
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref((__int64)v31, 0x1Bu, v23, v24, v25, v26, v27, v28, v29, v30) )
      result = nullptr;
    else
      result = v31;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
