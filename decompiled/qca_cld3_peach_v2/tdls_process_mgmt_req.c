__int64 __fastcall tdls_process_mgmt_req(__int64 a1)
{
  int v2; // w0
  __int64 v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x9
  __int64 v13; // x0
  int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w20
  __int64 v24; // x9
  __int64 comp_private_obj; // x0
  __int64 v26; // x0
  unsigned int v27; // w20
  int v28; // w8
  __int16 v29; // w9
  __int64 v30; // x8
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v41; // [xsp+0h] [xbp-50h] BYREF
  __int64 (__fastcall *v42)(); // [xsp+8h] [xbp-48h]
  __int64 v43; // [xsp+10h] [xbp-40h]
  __int64 v44; // [xsp+18h] [xbp-38h]
  __int64 v45; // [xsp+20h] [xbp-30h]
  __int64 v46; // [xsp+28h] [xbp-28h]
  __int64 v47; // [xsp+30h] [xbp-20h] BYREF
  __int64 v48; // [xsp+38h] [xbp-18h]
  int v49; // [xsp+40h] [xbp-10h]
  int v50; // [xsp+44h] [xbp-Ch]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = nullptr;
  v2 = tdls_validate_mgmt_request((__int64 *)a1);
  if ( v2 )
  {
    if ( a1 )
    {
      v3 = *(_QWORD *)a1;
      if ( *(_QWORD *)a1 )
      {
        v12 = *(_QWORD *)(v3 + 216);
        v47 = *(_QWORD *)a1;
        v48 = 0;
        v50 = 0;
        v49 = v2;
        if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
        {
LABEL_19:
          qdf_trace_msg(
            0,
            2u,
            "%s: can't get psoc",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "wlan_vdev_get_tdls_soc_obj",
            v41,
            v42);
          v27 = 0;
          goto LABEL_25;
        }
LABEL_12:
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
        if ( comp_private_obj )
        {
          v3 = *(_QWORD *)(comp_private_obj + 264);
          if ( v3 )
          {
            v26 = *(_QWORD *)(comp_private_obj + 272);
            if ( *(_DWORD *)(v3 - 4) != 1890320457 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64 *))v3)(v26, 1, &v47);
          }
        }
        v27 = 0;
        goto LABEL_25;
      }
    }
    goto LABEL_18;
  }
  v14 = tdls_set_link_mode((unsigned __int8 *)a1, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( v14 )
  {
    v23 = v14;
    qdf_trace_msg(
      0,
      2u,
      "%s: failed to set link:%d active",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "tdls_process_mgmt_req",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 93LL),
      v41,
      v42,
      v43,
      v44,
      v45,
      v46);
    if ( a1 )
    {
      v3 = *(_QWORD *)a1;
      if ( *(_QWORD *)a1 )
      {
        v24 = *(_QWORD *)(v3 + 216);
        v47 = *(_QWORD *)a1;
        v48 = 0;
        v50 = 0;
        v49 = v23;
        if ( !v24 )
          goto LABEL_19;
        v13 = *(_QWORD *)(v24 + 80);
        if ( !v13 )
          goto LABEL_19;
        goto LABEL_12;
      }
    }
LABEL_18:
    v27 = 29;
LABEL_25:
    wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, (unsigned int *)v3, v4, v5, v6, v7, v8, v9, v10, v11);
    _qdf_mem_free(a1);
    goto LABEL_26;
  }
  v28 = *(_DWORD *)(a1 + 32);
  v41 = 13;
  v42 = tdls_send_mgmt_serialize_callback;
  v29 = *(unsigned __int8 *)(a1 + 16);
  *(_BYTE *)(a1 + 70) = v28 == 0;
  LODWORD(v44) = 4000;
  v30 = *(_QWORD *)a1;
  LODWORD(v43) = 10;
  v45 = v30;
  v46 = a1;
  *(_WORD *)(a1 + 68) = v29;
  BYTE4(v43) = 2;
  v31 = wlan_serialization_request((unsigned int *)&v41, v15, v16, v17, v18, v19, v20, v21, v22);
  qdf_trace_msg(
    0,
    8u,
    "%s: wlan_serialization_request status:%d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "tdls_process_mgmt_req",
    v31,
    v41,
    v42);
  if ( v31 > 6 )
    goto LABEL_24;
  v3 = (unsigned int)(1 << v31);
  if ( (v3 & 0x4C) != 0 )
  {
    v27 = 16;
    goto LABEL_25;
  }
  v27 = 0;
  if ( (v3 & 3) == 0 )
  {
LABEL_24:
    v27 = 4;
    goto LABEL_25;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v27;
}
