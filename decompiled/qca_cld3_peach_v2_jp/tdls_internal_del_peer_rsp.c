__int64 __fastcall tdls_internal_del_peer_rsp(
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
  __int64 v10; // x19
  unsigned int ref; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 comp_private_obj; // x0
  void (__fastcall *v25)(__int64, __int64, __int64 *); // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  const char *v35; // x2
  __int64 v36; // [xsp+0h] [xbp-20h] BYREF
  __int64 v37; // [xsp+8h] [xbp-18h]
  __int64 v38; // [xsp+10h] [xbp-10h]
  __int64 v39; // [xsp+18h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( !v10 )
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
      "tdls_internal_del_peer_rsp",
      a1,
      v36,
      v37,
      v38,
      v39);
    result = 4;
    goto LABEL_17;
  }
  ref = wlan_objmgr_vdev_try_get_ref(v10, 0x11u, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ref )
  {
    if ( *a1 )
    {
      v22 = *(_QWORD *)(*a1 + 152);
      if ( v22 )
      {
        v23 = *(_QWORD *)(v22 + 80);
        if ( v23 )
        {
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v23, 0xAu);
          if ( comp_private_obj )
          {
            v25 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
            if ( v25 )
            {
              v34 = *(_QWORD *)(comp_private_obj + 272);
              v36 = *a1;
              if ( *((_DWORD *)v25 - 1) != 1890320457 )
                __break(0x8228u);
              v25(v34, 4, &v36);
            }
          }
          goto LABEL_16;
        }
      }
      v35 = "%s: can't get psoc";
    }
    else
    {
      v35 = "%s: NULL vdev";
    }
    qdf_trace_msg(0, 2u, v35, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_vdev_get_tdls_soc_obj", v36, v37, v38, v39);
LABEL_16:
    wlan_objmgr_vdev_release_ref(v10, 0x11u, (unsigned int *)v25, v26, v27, v28, v29, v30, v31, v32, v33);
    result = 0;
    goto LABEL_17;
  }
  v20 = ref;
  qdf_trace_msg(
    0,
    2u,
    "%s: can't get vdev object",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "tdls_internal_del_peer_rsp",
    v36,
    v37,
    v38,
    v39);
  result = v20;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
