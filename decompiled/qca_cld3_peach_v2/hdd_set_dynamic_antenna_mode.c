__int64 __fastcall hdd_set_dynamic_antenna_mode(__int64 *a1, unsigned __int8 a2, unsigned __int8 a3)
{
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 vdev_by_user; // x0
  __int64 v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 dynamic_vdev_config; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  const char *v46; // x2
  const char *v47; // x2
  __int64 v48; // [xsp+0h] [xbp-40h] BYREF
  __int64 v49; // [xsp+8h] [xbp-38h]
  __int64 v50; // [xsp+10h] [xbp-30h]
  __int64 v51; // [xsp+18h] [xbp-28h]
  __int64 v52; // [xsp+20h] [xbp-20h]
  __int64 v53; // [xsp+28h] [xbp-18h]
  __int64 v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v7 = *(_QWORD *)(v6 + 24);
  v49 = 0;
  v50 = 0;
  v48 = 0;
  result = _wlan_hdd_validate_context(v7, "hdd_set_dynamic_antenna_mode");
  if ( (_DWORD)result )
    goto LABEL_19;
  v17 = *(_QWORD *)(v7 + 16);
  if ( !v17 )
  {
    v47 = "%s: NULL MAC handle";
LABEL_15:
    qdf_trace_msg(
      0x33u,
      2u,
      v47,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "hdd_set_dynamic_antenna_mode",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55);
    goto LABEL_18;
  }
  if ( (hdd_is_vdev_in_conn_state(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev (id %d) not in connected/started state, cannot accept command",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_set_dynamic_antenna_mode",
      *((unsigned __int8 *)a1 + 8),
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55);
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_set_dynamic_antenna_mode");
  if ( !vdev_by_user )
  {
    v47 = "%s: vdev is NULL";
    goto LABEL_15;
  }
  v27 = vdev_by_user;
  qdf_mem_set(&v48, 0x38u, 0);
  LODWORD(v49) = a2;
  LODWORD(v48) = a3;
  dynamic_vdev_config = mlme_get_dynamic_vdev_config(v27, v28, v29, v30, v31, v32, v33, v34, v35);
  if ( !dynamic_vdev_config )
    goto LABEL_16;
  if ( *(_DWORD *)(dynamic_vdev_config + 24) > (unsigned int)a2
    || *(_DWORD *)(dynamic_vdev_config + 16) > (unsigned int)a3 )
  {
    goto LABEL_11;
  }
  HIDWORD(v49) = a2;
  HIDWORD(v48) = a3;
  v45 = mlme_get_dynamic_vdev_config(v27, v37, v38, v39, v40, v41, v42, v43, v44);
  if ( !v45 )
  {
LABEL_16:
    v46 = "%s: nss chain dynamic config NULL";
    goto LABEL_17;
  }
  if ( *(_DWORD *)(v45 + 28) > (unsigned int)a2 || *(_DWORD *)(v45 + 20) > (unsigned int)a3 )
  {
LABEL_11:
    v46 = "%s: Chains less than nss, configure correct nss first.";
LABEL_17:
    qdf_trace_msg(0x33u, 2u, v46, v37, v38, v39, v40, v41, v42, v43, v44, "hdd_populate_vdev_chains");
    _hdd_objmgr_put_vdev_by_user(v27, 6, "hdd_set_dynamic_antenna_mode");
    goto LABEL_18;
  }
  _hdd_objmgr_put_vdev_by_user(v27, 6, "hdd_set_dynamic_antenna_mode");
  if ( (unsigned int)sme_nss_chains_update(v17, &v48, *((unsigned __int8 *)a1 + 8)) )
    result = 4294967274LL;
  else
    result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
