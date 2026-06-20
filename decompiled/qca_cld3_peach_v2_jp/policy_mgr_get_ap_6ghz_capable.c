bool __fastcall policy_mgr_get_ap_6ghz_capable(__int64 a1, unsigned int a2, unsigned int *a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  unsigned int v16; // w21
  __int64 *v17; // x8
  unsigned int v18; // w24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x8
  const char *v28; // x7
  _BOOL4 v29; // w20

  if ( a3 )
    *a3 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_get_ap_6ghz_capable");
    return 0;
  }
  v15 = context;
  qdf_mutex_acquire(context + 56);
  v16 = (unsigned __int8)a2;
  if ( BYTE4(qword_81C458) == 1
    && (unsigned int)pm_conc_connection_list <= 6
    && ((1 << pm_conc_connection_list) & 0x4A) != 0
    && (v17 = &pm_conc_connection_list, (_DWORD)qword_81C458 == (unsigned __int8)a2)
    || BYTE4(qword_81C47C) == 1
    && (unsigned int)qword_81C464 <= 6
    && ((1 << qword_81C464) & 0x4A) != 0
    && (v17 = &qword_81C464, (_DWORD)qword_81C47C == (unsigned __int8)a2)
    || BYTE4(qword_81C4A0) == 1
    && (unsigned int)qword_81C488 <= 6
    && ((1 << qword_81C488) & 0x4A) != 0
    && (v17 = &qword_81C488, (_DWORD)qword_81C4A0 == (unsigned __int8)a2)
    || BYTE4(qword_81C4C4) == 1
    && (unsigned int)qword_81C4AC <= 6
    && ((1 << qword_81C4AC) & 0x4A) != 0
    && (v17 = &qword_81C4AC, (_DWORD)qword_81C4C4 == (unsigned __int8)a2)
    || BYTE4(qword_81C4E8) == 1
    && (unsigned int)qword_81C4D0 <= 6
    && ((1 << qword_81C4D0) & 0x4A) != 0
    && (v17 = &qword_81C4D0, (_DWORD)qword_81C4E8 == (unsigned __int8)a2) )
  {
    v18 = *((_DWORD *)v17 + 8);
    qdf_mutex_release(v15 + 56);
    if ( (v18 & 1) == 0 )
    {
      v27 = *(_DWORD **)(v15 + 344);
      if ( v27 )
        goto LABEL_26;
    }
  }
  else
  {
    qdf_mutex_release(v15 + 56);
    v18 = 0;
    v27 = *(_DWORD **)(v15 + 344);
    if ( v27 )
    {
LABEL_26:
      if ( *(v27 - 1) != -1682781459 )
        __break(0x8228u);
      v18 = ((__int64 (__fastcall *)(__int64, _QWORD))v27)(a1, a2) | 8;
    }
  }
  if ( (v18 & 0xF) == 0xF )
    v28 = "allowed";
  else
    v28 = "deny";
  v29 = (v18 & 0xF) == 15;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: vdev %d conn_6ghz_flag %x 6ghz capable %x 6ghz %s",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "policy_mgr_get_ap_6ghz_capable",
    v16,
    v18,
    15,
    v28);
  if ( a3 )
    *a3 = v18;
  return v29;
}
