__int64 __fastcall os_if_nan_post_ndi_create_rsp(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  int v15; // w9
  double v16; // d0
  unsigned int *v17; // x8
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  _QWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 20);
  if ( v5 )
  {
    v14 = v5;
    if ( (a3 & 1) != 0 )
      v15 = 0;
    else
      v15 = 9001;
    LODWORD(v26[0]) = (a3 & 1) == 0;
    HIDWORD(v26[0]) = v15;
    v16 = os_if_nan_datapath_event_handler(a1, v5, 1, v26);
    result = wlan_objmgr_vdev_release_ref(v14, 0x14u, v17, v16, v18, v19, v20, v21, v22, v23, v24);
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: vdev is null",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "os_if_nan_post_ndi_create_rsp");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
