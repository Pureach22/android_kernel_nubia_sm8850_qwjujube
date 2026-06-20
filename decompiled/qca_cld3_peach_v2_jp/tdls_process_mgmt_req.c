__int64 __fastcall tdls_process_mgmt_req(__int64 a1)
{
  unsigned int v2; // w0
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
  __int64 comp_private_obj; // x0
  __int64 v15; // x0
  unsigned int v16; // w20
  int v17; // w8
  __int16 v18; // w9
  __int64 v19; // x8
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // [xsp+0h] [xbp-50h] BYREF
  __int64 (__fastcall *v31)(); // [xsp+8h] [xbp-48h]
  __int64 v32; // [xsp+10h] [xbp-40h]
  __int64 v33; // [xsp+18h] [xbp-38h]
  __int64 v34; // [xsp+20h] [xbp-30h]
  __int64 v35; // [xsp+28h] [xbp-28h]
  __int64 v36; // [xsp+30h] [xbp-20h] BYREF
  __int64 v37; // [xsp+38h] [xbp-18h]
  __int64 v38; // [xsp+40h] [xbp-10h]
  __int64 v39; // [xsp+48h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = nullptr;
  v2 = tdls_validate_mgmt_request((__int64 *)a1);
  if ( v2 )
  {
    if ( a1 && (v3 = *(_QWORD *)a1) != 0 )
    {
      v12 = *(_QWORD *)(v3 + 152);
      v36 = *(_QWORD *)a1;
      v37 = 0;
      v38 = v2;
      if ( v12 && (v13 = *(_QWORD *)(v12 + 80)) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
        if ( comp_private_obj )
        {
          v3 = *(_QWORD *)(comp_private_obj + 264);
          if ( v3 )
          {
            v15 = *(_QWORD *)(comp_private_obj + 272);
            if ( *(_DWORD *)(v3 - 4) != 1890320457 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64 *))v3)(v15, 1, &v36);
          }
        }
        v16 = 0;
      }
      else
      {
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
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39);
        v16 = 0;
      }
    }
    else
    {
      v16 = 29;
    }
    goto LABEL_19;
  }
  v17 = *(_DWORD *)(a1 + 32);
  v30 = 13;
  v31 = tdls_send_mgmt_serialize_callback;
  v18 = *(unsigned __int8 *)(a1 + 16);
  *(_BYTE *)(a1 + 70) = v17 == 0;
  LODWORD(v33) = 4000;
  v19 = *(_QWORD *)a1;
  LODWORD(v32) = 10;
  v34 = v19;
  v35 = a1;
  *(_WORD *)(a1 + 68) = v18;
  BYTE4(v32) = 2;
  v20 = wlan_serialization_request((unsigned int *)&v30, v4, v5, v6, v7, v8, v9, v10, v11);
  qdf_trace_msg(
    0,
    8u,
    "%s: wlan_serialization_request status:%d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "tdls_process_mgmt_req",
    v20,
    v30,
    v31);
  if ( v20 > 6 )
    goto LABEL_17;
  v3 = (unsigned int)(1 << v20);
  if ( (v3 & 0x4C) != 0 )
  {
    v16 = 16;
LABEL_19:
    wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, (unsigned int *)v3, v4, v5, v6, v7, v8, v9, v10, v11);
    _qdf_mem_free(a1);
    goto LABEL_20;
  }
  v16 = 0;
  if ( (v3 & 3) == 0 )
  {
LABEL_17:
    v16 = 4;
    goto LABEL_19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v16;
}
