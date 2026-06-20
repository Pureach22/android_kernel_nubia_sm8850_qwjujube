__int64 __fastcall wlan_serialization_get_scan_cmd_using_scan_id(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 pdev_obj; // x0
  __int64 v18; // x22
  __int64 v19; // x8
  __int64 cmd; // x0
  __int64 v21; // x20
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  const char *v32; // x2
  _QWORD v34[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  memset(v34, 0, sizeof(v34));
  if ( a1 )
  {
    v14 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 9);
    if ( v14 )
    {
      v15 = v14;
      v16 = *(_QWORD *)(v14 + 152);
      if ( v16 )
      {
        pdev_obj = wlan_serialization_get_pdev_obj(v16);
        if ( pdev_obj )
        {
          v18 = pdev_obj;
          wlan_serialization_acquire_lock(pdev_obj + 88);
          LODWORD(v34[0]) = 0;
          HIDWORD(v34[0]) = a3;
          if ( a4 )
            v19 = 0;
          else
            v19 = 24;
          v35 = v15;
          cmd = wlan_serialization_find_cmd(v18 + v19, 3, v34, 0, 0, v15, 0);
          if ( cmd )
            v21 = cmd + 32;
          else
            v21 = 0;
          wlan_serialization_release_lock(v18 + 88);
          goto LABEL_18;
        }
        v32 = "%s: invalid ser_pdev_obj";
      }
      else
      {
        v32 = "%s: invalid pdev";
      }
      qdf_trace_msg(0x4Cu, 2u, v32, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_serialization_get_scan_cmd_using_scan_id");
      v21 = 0;
LABEL_18:
      wlan_objmgr_vdev_release_ref(v15, 9u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      goto LABEL_19;
    }
    v31 = "%s: invalid vdev";
  }
  else
  {
    v31 = "%s: invalid psoc";
  }
  qdf_trace_msg(0x4Cu, 2u, v31, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_serialization_get_scan_cmd_using_scan_id");
  v21 = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v21;
}
