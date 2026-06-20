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
  __int64 context; // x0
  __int64 result; // x0
  const char *v14; // x2
  __int64 v15; // x22
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  unsigned int v26; // w24
  __int64 v27; // x1
  int v28; // w21
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  unsigned int v39; // w23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w20
  _BYTE v49[4]; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v50[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v51; // [xsp+C0h] [xbp-10h]
  __int64 v52; // [xsp+C8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 152);
  v51 = 0;
  memset(v50, 0, sizeof(v50));
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v14 = "%s: Invalid psoc";
LABEL_7:
    qdf_trace_msg(0x4Fu, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_validate_sta_start");
    result = 0;
    goto LABEL_8;
  }
  context = policy_mgr_get_context(*(_QWORD *)(v9 + 80));
  if ( !context )
  {
    v14 = "%s: Invalid pm_ctx";
    goto LABEL_7;
  }
  if ( *(_DWORD *)(a1 + 16) )
    goto LABEL_5;
  v15 = context;
  v16 = policy_mgr_get_context(v10);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "policy_mgr_get_connection_count");
    result = 1;
    goto LABEL_8;
  }
  v25 = v16;
  qdf_mutex_acquire(v16 + 56);
  v26 = BYTE4(qword_81C47C) + BYTE4(qword_81C458) + BYTE4(qword_81C4A0) + BYTE4(qword_81C4C4) + BYTE4(qword_81C4E8);
  qdf_mutex_release(v25 + 56);
  if ( v26 < 2 )
  {
LABEL_5:
    result = 1;
    goto LABEL_8;
  }
  qdf_mutex_acquire(v15 + 56);
  v27 = *(unsigned __int8 *)(a1 + 104);
  v49[0] = 0;
  ((void (__fastcall *)(__int64, __int64, _QWORD *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    v10,
    v27,
    v50,
    v49);
  v28 = v49[0];
  v29 = policy_mgr_get_context(v10);
  if ( !v29 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "policy_mgr_get_connection_count");
LABEL_18:
    v48 = 1;
    goto LABEL_19;
  }
  v38 = v29;
  qdf_mutex_acquire(v29 + 56);
  v39 = BYTE4(qword_81C47C) + BYTE4(qword_81C458) + BYTE4(qword_81C4A0) + BYTE4(qword_81C4C4) + BYTE4(qword_81C4E8);
  qdf_mutex_release(v38 + 56);
  if ( v39 < 2
    || (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
          v10,
          0,
          0,
          0,
          0,
          *(unsigned __int8 *)(a1 + 104))
      & 1) != 0 )
  {
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: sta 3 port conc check fail, can't allow sta",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "policy_mgr_validate_sta_start");
  v48 = 0;
LABEL_19:
  if ( v28 )
    policy_mgr_restore_deleted_conn_info(v10, (unsigned int *)v50, v28, v40, v41, v42, v43, v44, v45, v46, v47);
  qdf_mutex_release(v15 + 56);
  result = v48;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
