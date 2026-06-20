__int64 __fastcall cm_add_fw_roam_dummy_ser_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v13; // x0
  unsigned int v14; // w20
  unsigned int ref; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  __int64 result; // x0
  unsigned int v26; // w9
  __int64 v27; // x9
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x6
  bool v38; // cf
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v49)(); // [xsp+10h] [xbp-30h]
  __int64 v50; // [xsp+18h] [xbp-28h]
  __int64 v51; // [xsp+20h] [xbp-20h]
  __int64 v52; // [xsp+28h] [xbp-18h]
  __int64 v53; // [xsp+30h] [xbp-10h]
  __int64 v54; // [xsp+38h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *a10;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v14 = *(unsigned __int8 *)(v13 + 168);
  ref = wlan_objmgr_vdev_try_get_ref(v13, 0x4Du, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( ref )
  {
    v24 = ref;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: unable to get reference",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "cm_add_fw_roam_dummy_ser_cb",
      v14,
      *(unsigned int *)(a11 + 16));
    result = v24;
  }
  else
  {
    v26 = *(_DWORD *)(a11 + 16);
    LODWORD(v50) = 0;
    v48[0] = 28;
    v48[1] = v26;
    v27 = *a10;
    LODWORD(v51) = 7000;
    v49 = cm_fw_roam_ser_cb;
    v52 = v27;
    BYTE4(v50) = 3;
    v28 = wlan_serialization_request(v48, v16, v17, v18, v19, v20, v21, v22, v23);
    v37 = v28;
    v38 = v28 >= 2;
    result = 0;
    if ( v38 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: ser cmd status %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "cm_add_fw_roam_dummy_ser_cb",
        v14,
        *(unsigned int *)(a11 + 16),
        v37);
      wlan_objmgr_vdev_release_ref(*a10, 0x4Du, v39, v40, v41, v42, v43, v44, v45, v46, v47);
      result = 16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
