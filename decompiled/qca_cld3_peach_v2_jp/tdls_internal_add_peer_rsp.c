__int64 __fastcall tdls_internal_add_peer_rsp(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  unsigned int ref; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 comp_private_obj; // x0
  void (__fastcall *v24)(__int64, __int64, __int64 *); // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  __int64 v34; // [xsp+0h] [xbp-20h] BYREF
  __int64 v35; // [xsp+8h] [xbp-18h]
  __int64 v36; // [xsp+10h] [xbp-10h]
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v35 = 0;
  v36 = 0;
  v34 = 0;
  if ( v9 )
  {
    ref = wlan_objmgr_vdev_try_get_ref(v9, 0x10u, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( ref )
    {
      v19 = ref;
      qdf_trace_msg(
        0,
        2u,
        "%s: can't get vdev object",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tdls_internal_add_peer_rsp",
        v34,
        v35,
        v36,
        v37);
      result = v19;
    }
    else
    {
      v21 = *(_QWORD *)(v9 + 152);
      if ( v21 && (v22 = *(_QWORD *)(v21 + 80)) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v22, 0xAu);
        if ( comp_private_obj )
        {
          v24 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
          if ( v24 )
          {
            v33 = *(_QWORD *)(comp_private_obj + 272);
            v34 = v9;
            LODWORD(v36) = 16;
            if ( *((_DWORD *)v24 - 1) != 1890320457 )
              __break(0x8228u);
            v24(v33, 3, &v34);
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: can't get psoc",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "wlan_vdev_get_tdls_soc_obj",
          v34,
          v35,
          v36,
          v37);
      }
      wlan_objmgr_vdev_release_ref(v9, 0x10u, (unsigned int *)v24, v25, v26, v27, v28, v29, v30, v31, v32);
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: req: %pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tdls_internal_add_peer_rsp",
      a1,
      v34,
      v35,
      v36,
      v37);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
