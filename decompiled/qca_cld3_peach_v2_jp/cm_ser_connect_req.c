__int64 __fastcall cm_ser_connect_req(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w8
  __int64 result; // x0
  __int64 v14; // x0
  unsigned int v15; // w20
  unsigned int ref; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  unsigned int v26; // w19
  unsigned int v27; // w9
  __int64 v28; // x8
  int v29; // w10
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x6
  bool v40; // cf
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v51)(); // [xsp+10h] [xbp-30h]
  __int64 v52; // [xsp+18h] [xbp-28h]
  __int64 v53; // [xsp+20h] [xbp-20h]
  __int64 v54; // [xsp+28h] [xbp-18h]
  __int64 v55; // [xsp+30h] [xbp-10h]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a2[3];
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  if ( v11 == 17 || v11 == 15 )
  {
    result = wlan_sm_dispatch(*(_QWORD *)(a1 + 72), 7u, 4u, (__int64)a2, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  else
  {
    v14 = *(_QWORD *)a1;
    v15 = *(unsigned __int8 *)(v14 + 104);
    ref = wlan_objmgr_vdev_try_get_ref(v14, 0x4Du, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( ref )
    {
      v25 = *a2;
      v26 = ref;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: unable to get reference",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "cm_ser_connect_req",
        v15,
        v25);
      result = v26;
    }
    else
    {
      v27 = *a2;
      LODWORD(v52) = 0;
      v50[0] = 23;
      v50[1] = v27;
      v28 = *(_QWORD *)a1;
      v51 = cm_ser_connect_cb;
      v29 = *(_DWORD *)(a1 + 196);
      v54 = v28;
      LODWORD(v53) = v29;
      BYTE4(v52) = 2;
      v30 = wlan_serialization_request(v50, v17, v18, v19, v20, v21, v22, v23, v24);
      v39 = v30;
      v40 = v30 >= 2;
      result = 0;
      if ( v40 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: ser cmd status %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "cm_ser_connect_req",
          v15,
          *a2,
          v39);
        wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x4Du, v41, v42, v43, v44, v45, v46, v47, v48, v49);
        result = 16;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
