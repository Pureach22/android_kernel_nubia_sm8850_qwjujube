__int64 __fastcall policy_mgr_fetch_scc_vdev_id(__int64 a1, unsigned __int8 a2, int a3)
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
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 *v24; // x22
  unsigned int v25; // w21

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_fetch_scc_vdev_id");
    return 255;
  }
  v14 = context;
  qdf_mutex_acquire(context + 56);
  v23 = a2;
  if ( (unsigned int)pm_conc_connection_list >= 4 && (_DWORD)pm_conc_connection_list != 6
    || (v24 = &pm_conc_connection_list, BYTE4(qword_81C458) != 1)
    || HIDWORD(pm_conc_connection_list) != a3
    || (_DWORD)qword_81C458 == a2 )
  {
    if ( (unsigned int)qword_81C464 >= 4 && (_DWORD)qword_81C464 != 6
      || (v24 = &qword_81C464, BYTE4(qword_81C47C) != 1)
      || HIDWORD(qword_81C464) != a3
      || (_DWORD)qword_81C47C == a2 )
    {
      if ( (unsigned int)qword_81C488 >= 4 && (_DWORD)qword_81C488 != 6
        || (v24 = &qword_81C488, BYTE4(qword_81C4A0) != 1)
        || HIDWORD(qword_81C488) != a3
        || (_DWORD)qword_81C4A0 == a2 )
      {
        if ( (unsigned int)qword_81C4AC >= 4 && (_DWORD)qword_81C4AC != 6
          || (v24 = &qword_81C4AC, BYTE4(qword_81C4C4) != 1)
          || HIDWORD(qword_81C4AC) != a3
          || (_DWORD)qword_81C4C4 == a2 )
        {
          if ( (unsigned int)qword_81C4D0 >= 4 && (_DWORD)qword_81C4D0 != 6 )
          {
            v25 = 255;
            goto LABEL_28;
          }
          v24 = &qword_81C4D0;
          v25 = 255;
          if ( BYTE4(qword_81C4E8) != 1 || HIDWORD(qword_81C4D0) != a3 || (_DWORD)qword_81C4E8 == v23 )
            goto LABEL_28;
        }
      }
    }
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Found a SCC vdev %d freq %d mode %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_fetch_scc_vdev_id");
  v25 = *((_DWORD *)v24 + 6);
LABEL_28:
  qdf_mutex_release(v14 + 56);
  return v25;
}
