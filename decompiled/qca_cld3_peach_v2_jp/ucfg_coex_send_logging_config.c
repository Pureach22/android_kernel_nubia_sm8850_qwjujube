__int64 __fastcall ucfg_coex_send_logging_config(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4
  __int64 v21; // x19
  unsigned int v22; // w20
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *a2 == 12 )
  {
    v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 0, 106);
    if ( v11 )
    {
      v20 = (unsigned int)*a2;
      v21 = v11;
      qdf_trace_msg(
        0x70u,
        8u,
        "%s: send logging_config arg: %u for vdev %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ucfg_coex_send_logging_config",
        v20);
      v22 = wlan_coex_config_send();
      wlan_objmgr_vdev_release_ref(v21, 0x6Au, v23, v24, v25, v26, v27, v28, v29, v30, v31);
      result = v22;
    }
    else
    {
      qdf_trace_msg(
        0x70u,
        2u,
        "%s: vdev is null",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ucfg_coex_send_logging_config");
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(0x70u, 2u, "%s: invalid cmd %d", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_coex_send_logging_config");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
