__int64 __fastcall ll_lt_sap_high_ap_availability_process(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x21
  __int64 v23; // x22
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 (__fastcall *v33)(__int64, __int64); // x8
  __int64 result; // x0
  const char *v35; // x2
  unsigned int v36; // w1
  __int64 v37; // x21
  __int64 v38; // x22
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  void (__fastcall *v48)(__int64, __int64, __int64); // x8
  __int64 v49; // x1
  __int64 v50; // x2
  unsigned __int16 v51; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "ll_sap_get_vdev_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll_sap obj null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ll_lt_sap_high_ap_availability_process",
      *(unsigned __int8 *)(a1 + 104));
LABEL_19:
    result = 4;
    goto LABEL_20;
  }
  v21 = *(_QWORD *)(a1 + 152);
  if ( v21 )
  {
    v22 = *(_QWORD *)(v21 + 80);
    v23 = comp_private_obj;
  }
  else
  {
    v23 = comp_private_obj;
    v22 = 0;
  }
  v24 = wlan_objmgr_psoc_get_comp_private_obj(v22, 0x34u);
  if ( !v24 )
  {
    v35 = "%s: psoc_ll_sap_obj is null";
LABEL_17:
    v36 = 2;
LABEL_18:
    qdf_trace_msg(0xA1u, v36, v35, v25, v26, v27, v28, v29, v30, v31, v32, "ll_lt_sap_high_ap_availability_process");
    goto LABEL_19;
  }
  v33 = *(__int64 (__fastcall **)(__int64, __int64))(v24 + 8);
  if ( !v33 )
  {
    v35 = "%s: send_oob_connect_request op is NULL";
    goto LABEL_17;
  }
  if ( *((_DWORD *)v33 - 1) != -1306282296 )
    __break(0x8228u);
  result = v33(v22, a2);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(a2 + 12) )
    {
LABEL_14:
      result = 0;
      goto LABEL_20;
    }
    v37 = v23 + 8;
    if ( *(__int16 *)(v23 + 8) == -1 )
    {
      v38 = 0;
    }
    else
    {
      if ( *(__int16 *)(v23 + 10) != -1 )
      {
        v35 = "%s: Invalid high AP availability request";
        v36 = 8;
        goto LABEL_18;
      }
      v38 = 1;
    }
    get_random_bytes(&v51, 2);
    v47 = qdf_trace_msg(
            0xA1u,
            8u,
            "%s: LL_LT_SAP vdev %d high ap availability cookie %d",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "ll_lt_sap_high_ap_availability_process",
            *(unsigned __int8 *)(a1 + 104),
            v51);
    *(_WORD *)(v37 + 2 * v38) = v51;
    result = ll_sap_get_osif_cbk(v47);
    if ( !result )
      goto LABEL_20;
    v48 = *(void (__fastcall **)(__int64, __int64, __int64))(result + 8);
    if ( v48 )
    {
      v49 = *(unsigned int *)(a2 + 12);
      v50 = v51;
      if ( *((_DWORD *)v48 - 1) != 2120861206 )
        __break(0x8228u);
      v48(a1, v49, v50);
    }
    goto LABEL_14;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
