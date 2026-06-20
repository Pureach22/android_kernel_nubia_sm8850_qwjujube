__int64 __fastcall target_if_cm_roam_oem_eht_mlo_bitmap(
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
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x19
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  _DWORD v24[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 216);
  v24[0] = 0;
  if ( v9 && (v10 = *(_QWORD *)(v9 + 80)) != 0 )
  {
    v11 = *(__int64 **)(v9 + 1240);
    if ( v11 && (v12 = *v11) != 0 )
    {
      result = wlan_mlme_get_oem_eht_mlo_config(v10, v24);
      if ( !(_DWORD)result )
      {
        v24[1] = *(unsigned __int8 *)(a1 + 168);
        v24[2] = 10;
        v24[3] = v24[0];
        result = wmi_unified_roam_set_param_send(v12);
        if ( (_DWORD)result )
        {
          v23 = result;
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: Failed to set roam oem eht bitmap",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "target_if_cm_roam_oem_eht_mlo_bitmap");
          result = v23;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi_handle is null",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "target_if_cm_roam_get_wmi_handle_from_vdev");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc handle is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_cm_roam_oem_eht_mlo_bitmap");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
