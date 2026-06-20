__int64 __fastcall policy_mgr_get_bw_by_session_id(__int64 a1, unsigned __int8 a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 *v13; // x9
  int v14; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)qword_81C458 == a2 && (v13 = &pm_conc_connection_list, BYTE4(qword_81C458) == 1)
      || (_DWORD)qword_81C47C == a2 && (v13 = &qword_81C464, (qword_81C47C & 0x100000000LL) != 0)
      || (_DWORD)qword_81C4A0 == a2 && (v13 = &qword_81C488, (qword_81C4A0 & 0x100000000LL) != 0)
      || (_DWORD)qword_81C4C4 == a2 && (v13 = &qword_81C4AC, (qword_81C4C4 & 0x100000000LL) != 0)
      || (_DWORD)qword_81C4E8 == a2 && (v13 = &qword_81C4D0, (qword_81C4E8 & 0x100000000LL) != 0) )
    {
      v14 = *((_DWORD *)v13 + 2);
    }
    else
    {
      v14 = 0;
    }
    qdf_mutex_release(v12 + 56);
    return policy_mgr_get_ch_width(v14, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_bw_by_session_id");
    return 8;
  }
}
