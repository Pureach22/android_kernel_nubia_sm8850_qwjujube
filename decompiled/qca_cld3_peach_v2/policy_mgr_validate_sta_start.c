__int64 __fastcall policy_mgr_validate_sta_start(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 v11; // x20
  __int64 context; // x0
  __int64 v13; // x22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  unsigned int v24; // w24
  __int64 result; // x0
  const char *v26; // x2
  __int64 v27; // x1
  unsigned int v28; // w8
  unsigned int v29; // w21
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x24
  unsigned int v42; // w23
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w9
  _BYTE v52[4]; // [xsp+8h] [xbp-D8h] BYREF
  unsigned __int16 v53; // [xsp+Ch] [xbp-D4h] BYREF
  __int64 v54; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v55; // [xsp+18h] [xbp-C8h]
  _QWORD v56[22]; // [xsp+20h] [xbp-C0h] BYREF
  int v57; // [xsp+D0h] [xbp-10h]
  __int64 v58; // [xsp+D8h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 216);
  v57 = 0;
  memset(v56, 0, sizeof(v56));
  v54 = 0;
  v55 = 0;
  v53 = 0;
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v26 = "%s: Invalid psoc";
LABEL_10:
    qdf_trace_msg(0x4Fu, 2u, v26, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_validate_sta_start");
    result = 0;
    goto LABEL_11;
  }
  v11 = a1;
  context = policy_mgr_get_context(*(_QWORD *)(v9 + 80));
  if ( !context )
  {
    v26 = "%s: Invalid pm_ctx";
    goto LABEL_10;
  }
  if ( *(_DWORD *)(v11 + 16) || (*(_BYTE *)(v11 + 60) & 2) != 0 )
    goto LABEL_8;
  v13 = context;
  v14 = policy_mgr_get_context(v10);
  if ( !v14 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_get_connection_count");
    result = 1;
    goto LABEL_11;
  }
  v23 = v14;
  qdf_mutex_acquire(v14 + 56);
  v24 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
  qdf_mutex_release(v23 + 56);
  if ( v24 < 2 )
  {
LABEL_8:
    result = 1;
    goto LABEL_11;
  }
  mlo_get_ml_vdev_list(v11, &v53, &v54);
  qdf_mutex_acquire(v13 + 56);
  v27 = *(unsigned __int8 *)(v11 + 168);
  v52[0] = 0;
  ((void (__fastcall *)(__int64, __int64, _QWORD *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    v10,
    v27,
    v56,
    v52);
  v28 = v53;
  v29 = v52[0];
  if ( v53 )
  {
    if ( v54 && v54 != v11 && v52[0] <= 4u )
    {
      v30 = *(unsigned __int8 *)(v54 + 168);
      v52[0] = 0;
      ((void (__fastcall *)(__int64, __int64, char *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
        v10,
        v30,
        (char *)v56 + 36 * v29,
        v52);
      v28 = v53;
      LOBYTE(v29) = v52[0] + v29;
    }
    if ( v28 >= 2 )
    {
      if ( v55 && v55 != v11 && (unsigned __int8)v29 <= 4u )
      {
        v31 = *(unsigned __int8 *)(v55 + 168);
        v52[0] = 0;
        ((void (__fastcall *)(__int64, __int64, char *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
          v10,
          v31,
          (char *)v56 + 36 * (unsigned __int8)v29,
          v52);
        v28 = v53;
        LOBYTE(v29) = v52[0] + v29;
      }
      if ( v28 > 2 )
        goto LABEL_40;
    }
  }
  v32 = policy_mgr_get_context(v10);
  if ( v32 )
  {
    v41 = v32;
    qdf_mutex_acquire(v32 + 56);
    v42 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
    qdf_mutex_release(v41 + 56);
    if ( v42 >= 2
      && (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
            v10,
            0,
            0,
            0,
            0,
            *(unsigned __int8 *)(v11 + 168))
        & 1) == 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: sta 3 port conc check fail, can't allow sta",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "policy_mgr_validate_sta_start");
      LODWORD(v11) = 0;
      goto LABEL_31;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "policy_mgr_get_connection_count");
  }
  LODWORD(v11) = 1;
LABEL_31:
  if ( (_BYTE)v29 )
    policy_mgr_restore_deleted_conn_info(v10, (unsigned int *)v56, v29, v43, v44, v45, v46, v47, v48, v49, v50);
  qdf_mutex_release(v13 + 56);
  v51 = v53;
  if ( !v53 )
    goto LABEL_41;
  if ( v54 )
  {
    mlo_release_vdev_ref(v54);
    v51 = v53;
  }
  result = (unsigned int)v11;
  if ( v51 >= 2 )
  {
    if ( v55 )
    {
      mlo_release_vdev_ref(v55);
      v51 = v53;
      result = (unsigned int)v11;
    }
    if ( v51 > 2 )
    {
LABEL_40:
      __break(0x5512u);
LABEL_41:
      result = (unsigned int)v11;
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
