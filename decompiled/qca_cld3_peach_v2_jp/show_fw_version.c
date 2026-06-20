__int64 __fastcall show_fw_version(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w0
  __int64 v32[2]; // [xsp+40h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"show_fw_version", a1, a2, a3, a4, a5, a6, a7, a8);
  v32[0] = 0;
  v21 = _wlan_hdd_validate_context((__int64)context, (__int64)"show_fw_version", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !v21 )
  {
    v21 = _osif_psoc_sync_op_start(context[12], v32, (__int64)"show_fw_version");
    if ( !v21 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Rcvd req for FW version",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__show_fw_version");
      scnprintf(
        a11,
        4096,
        "FW:%d.%d.%d.%d.%d.%d HW:%s Board version: %x Ref design id: %x Customer id: %x Project id: %x Board Data Rev: %x\n",
        *((_DWORD *)context + 135),
        *((_DWORD *)context + 136),
        *((_DWORD *)context + 137),
        *((_DWORD *)context + 139),
        *((_DWORD *)context + 140),
        *((_DWORD *)context + 138),
        (const char *)context + 572,
        *((_DWORD *)context + 876),
        *((_DWORD *)context + 877),
        *((_DWORD *)context + 878),
        *((_DWORD *)context + 879),
        *((_DWORD *)context + 880));
      v21 = v30;
      _osif_psoc_sync_op_stop(v32[0], (__int64)"show_fw_version");
    }
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
