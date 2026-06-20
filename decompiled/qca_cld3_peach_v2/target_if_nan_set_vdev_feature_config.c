__int64 __fastcall target_if_nan_set_vdev_feature_config(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    v12 = a2;
    if ( a2 >= 6u )
    {
      result = qdf_trace_msg(
                 0x49u,
                 2u,
                 "%s: vdev_id: %d is invalid, reject the req: param id %d",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "target_if_nan_set_vdev_feature_config",
                 a2,
                 163);
    }
    else
    {
      ucfg_get_nan_feature_config(a1, &v30, a3, a4, a5, a6, a7, a8, a9, a10);
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: vdev_id:%d NAN features:0x%x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "target_if_nan_set_vdev_feature_config",
        v12,
        v30);
      result = wmi_unified_vdev_set_param_send(v11);
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0x49u,
                   2u,
                   "%s: failed to set NAN_CONFIG_FEATURES(status = %d)",
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   "target_if_nan_set_vdev_feature_config",
                   (unsigned int)result);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x49u,
               2u,
               "%s: Invalid wmi handle",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "target_if_nan_set_vdev_feature_config");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
