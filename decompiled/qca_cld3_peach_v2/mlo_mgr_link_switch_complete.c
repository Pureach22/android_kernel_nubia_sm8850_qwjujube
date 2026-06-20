__int64 __fastcall mlo_mgr_link_switch_complete(__int64 a1)
{
  char is_link_recfg_in_progress; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x8
  char v12; // w20
  __int64 v13; // x21
  __int64 v14; // x23
  __int64 v15; // x24
  int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  unsigned int (__fastcall *v35)(__int64, int *); // x8
  const char *v36; // x2
  __int64 result; // x0
  __int64 v38; // x21
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int *v47; // x8
  int v48; // [xsp+Ch] [xbp-14h] BYREF
  _BOOL4 v49; // [xsp+10h] [xbp-10h]
  int v50; // [xsp+14h] [xbp-Ch]
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  is_link_recfg_in_progress = mlo_is_link_recfg_in_progress(a1);
  v11 = *(_QWORD *)(a1 + 216);
  v12 = is_link_recfg_in_progress;
  if ( v11 )
  {
    v13 = *(_QWORD *)(v11 + 80);
    v14 = *(_QWORD *)(a1 + 1360);
    if ( v14 )
      goto LABEL_3;
LABEL_11:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_dev_ctx for vdev is null vedv_id %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "mlo_mgr_link_switch_complete",
      *(unsigned __int8 *)(a1 + 168));
    result = 4;
    goto LABEL_17;
  }
  v13 = 0;
  v14 = *(_QWORD *)(a1 + 1360);
  if ( !v14 )
    goto LABEL_11;
LABEL_3:
  v15 = *(_QWORD *)(v14 + 3880);
  qdf_mutex_acquire(v14 + 1656);
  v16 = *(_DWORD *)(*(_QWORD *)(v14 + 3880) + 164LL);
  qdf_mutex_release(v14 + 1656);
  v25 = *(_DWORD *)(v15 + 168);
  v48 = *(unsigned __int8 *)(a1 + 168);
  v49 = v16 != 5;
  v50 = 1;
  if ( v25 != 65534 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: VDEV %d link switch completed, %s",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlo_mgr_link_switch_send_cnf_cmd");
    v34 = *(_QWORD *)(v13 + 2128);
    if ( v34 == -1984 || (v35 = *(unsigned int (__fastcall **)(__int64, int *))(v34 + 2048)) == nullptr )
    {
      v36 = "%s: handler is not registered";
    }
    else
    {
      if ( *((_DWORD *)v35 - 1) != 1127800684 )
        __break(0x8228u);
      if ( !v35(v13, &v48) )
        goto LABEL_14;
      v36 = "%s: Link switch status update to FW failed";
    }
    qdf_trace_msg(0x8Fu, 2u, v36, v26, v27, v28, v29, v30, v31, v32, v33, "mlo_mgr_link_switch_send_cnf_cmd");
  }
LABEL_14:
  v38 = *(_QWORD *)(a1 + 1360);
  qdf_mutex_acquire(v38 + 1656);
  *(_DWORD *)(*(_QWORD *)(v38 + 3880) + 164LL) = 0;
  qdf_mutex_release(v38 + 1656);
  v47 = (unsigned int *)(*(_DWORD *)(a1 + 64) & 0xFDFFFFFF);
  *(_DWORD *)(a1 + 64) = (_DWORD)v47;
  if ( (v12 & 1) != 0 )
    v39 = mlo_link_recfg_linksw_completion_indication(a1, 16 * (unsigned int)v49);
  wlan_objmgr_vdev_release_ref(a1, 0x5Au, v47, v39, v40, v41, v42, v43, v44, v45, v46);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
