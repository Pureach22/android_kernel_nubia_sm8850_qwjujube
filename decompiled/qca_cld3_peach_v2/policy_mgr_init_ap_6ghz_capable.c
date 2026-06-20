__int64 __fastcall policy_mgr_init_ap_6ghz_capable(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 *v15; // x8
  unsigned int v16; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "policy_mgr_init_ap_6ghz_capable");
  v14 = context;
  qdf_mutex_acquire(context + 56);
  if ( BYTE4(qword_8D4F00) == 1
    && ((_DWORD)pm_conc_connection_list == 6 || (_DWORD)pm_conc_connection_list == 1)
    && (v15 = &pm_conc_connection_list, (_DWORD)qword_8D4F00 == a2)
    || BYTE4(qword_8D4F24) == 1
    && ((_DWORD)qword_8D4F0C == 6 || (_DWORD)qword_8D4F0C == 1)
    && (v15 = &qword_8D4F0C, (_DWORD)qword_8D4F24 == a2)
    || BYTE4(qword_8D4F48) == 1
    && ((_DWORD)qword_8D4F30 == 6 || (_DWORD)qword_8D4F30 == 1)
    && (v15 = &qword_8D4F30, (_DWORD)qword_8D4F48 == a2)
    || BYTE4(qword_8D4F6C) == 1
    && ((_DWORD)qword_8D4F54 == 6 || (_DWORD)qword_8D4F54 == 1)
    && (v15 = &qword_8D4F54, (_DWORD)qword_8D4F6C == a2)
    || BYTE4(qword_8D4F90) == 1
    && ((_DWORD)qword_8D4F78 == 6 || (_DWORD)qword_8D4F78 == 1)
    && (v15 = &qword_8D4F78, (_DWORD)qword_8D4F90 == a2) )
  {
    v16 = a3 | 1;
    *((_DWORD *)v15 + 8) = a3 | 1;
  }
  else
  {
    v16 = 0;
  }
  qdf_mutex_release(v14 + 56);
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: vdev %d init conn_6ghz_flag %x new %x",
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           "policy_mgr_init_ap_6ghz_capable",
           a2,
           a3,
           v16);
}
