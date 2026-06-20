__int64 __fastcall policy_mgr_get_sap_go_count_on_mac(__int64 a1, _DWORD *a2, unsigned __int8 a3)
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
  int v15; // w22
  unsigned int v16; // w21

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    v15 = a3;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_81C448) == a3 && BYTE4(qword_81C458) == 1 )
    {
      v16 = 0;
      if ( (unsigned int)pm_conc_connection_list <= 6 && ((1 << pm_conc_connection_list) & 0x4A) != 0 )
      {
        if ( a2 )
          *a2 = qword_81C458;
        v16 = 1;
      }
    }
    else
    {
      v16 = 0;
    }
    if ( BYTE4(qword_81C46C) == v15
      && BYTE4(qword_81C47C) == 1
      && (unsigned int)qword_81C464 <= 6
      && ((1 << qword_81C464) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_81C47C;
      ++v16;
    }
    if ( BYTE4(qword_81C490) == v15
      && BYTE4(qword_81C4A0) == 1
      && (unsigned int)qword_81C488 <= 6
      && ((1 << qword_81C488) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_81C4A0;
      ++v16;
    }
    if ( BYTE4(qword_81C4B4) == v15
      && BYTE4(qword_81C4C4) == 1
      && (unsigned int)qword_81C4AC <= 6
      && ((1 << qword_81C4AC) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_81C4C4;
      ++v16;
    }
    if ( BYTE4(qword_81C4D8) == v15
      && BYTE4(qword_81C4E8) == 1
      && (unsigned int)qword_81C4D0 <= 6
      && ((1 << qword_81C4D0) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_81C4E8;
      ++v16;
    }
    qdf_mutex_release(v14 + 56);
  }
  else
  {
    qdf_trace_msg(
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
      "policy_mgr_get_sap_go_count_on_mac");
    return 0;
  }
  return v16;
}
