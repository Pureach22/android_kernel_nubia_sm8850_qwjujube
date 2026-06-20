__int64 __fastcall target_if_cm_roam_scan_offload_ap_profile(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w21
  __int64 v14; // x8
  __int64 v15; // x0
  int v16; // w8
  __int64 result; // x0
  char v18; // w0
  int v19; // w8
  int v20; // w10
  int v21; // w9
  char v22[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(unsigned __int8 *)a3 < 6u )
  {
    v11 = a3[12];
    if ( (unsigned int)(v11 - 17) <= 1 )
    {
      v14 = *(_QWORD *)(a1 + 152);
      v22[0] = 0;
      if ( v14 && (v15 = *(_QWORD *)(v14 + 80)) != 0 )
      {
        wlan_mlme_get_roaming_offload(v15, v22);
        if ( v22[0] )
          v16 = v11;
        else
          v16 = 7;
      }
      else
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: psoc handle is NULL",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "target_if_cm_roam_scan_get_cckm_mode");
        v16 = 7;
      }
      a3[12] = v16;
    }
    v18 = wmi_service_enabled(a2, 0xACu, a4, a5, a6, a7, a8, a9, a10, a11);
    v19 = a3[16];
    if ( v19 )
    {
      if ( (v18 & 1) == 0 )
      {
        a3[16] = v19 + 96;
LABEL_16:
        v20 = a3[75] + 96;
        v21 = (unsigned __int8)(a3[73] + 96);
        a3[71] = (unsigned __int8)(a3[71] + 96);
        a3[73] = v21;
        a3[75] = (unsigned __int8)v20;
      }
    }
    else
    {
      if ( (v18 & 1) == 0 )
        goto LABEL_16;
      a3[16] = -128;
    }
    result = wmi_unified_send_roam_scan_offload_ap_cmd(a2, a3);
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Invalid vdev id:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "target_if_cm_roam_scan_offload_ap_profile");
  result = 16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
