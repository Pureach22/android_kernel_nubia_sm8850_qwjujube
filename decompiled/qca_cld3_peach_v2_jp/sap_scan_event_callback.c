__int64 __fastcall sap_scan_event_callback(
        __int64 a1,
        _DWORD *a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned int v24; // w21
  unsigned int v25; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x23
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = 0;
  if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(a1, 0x2Cu, a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    result = qdf_trace_msg(
               0x39u,
               2u,
               "%s: Hotspot fail, vdev ref get error",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "sap_scan_event_callback");
  }
  else
  {
    wlan_objmgr_vdev_release_ref(a1, 0x2Cu, v14, v15, v16, v17, v18, v19, v20, v21, v22);
    v24 = *(unsigned __int8 *)(a1 + 104);
    v25 = a2[5];
    result = (__int64)_cds_get_context(52, (__int64)"sap_scan_event_callback", v26, v27, v28, v29, v30, v31, v32, v33);
    if ( result )
    {
      v34 = result;
      qdf_mtrace(21, 57, a2[1], *a2, a2[5]);
      result = util_is_scan_completed((__int64)a2, v35);
      if ( (result & 1) != 0 )
        result = wlansap_pre_start_bss_acs_scan_callback(v34, a3, v24, v25, v35[0] ^ 1u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
