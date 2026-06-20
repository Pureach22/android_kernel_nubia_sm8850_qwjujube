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
    if ( BYTE4(qword_8D4EF0) == a3 && BYTE4(qword_8D4F00) == 1 )
    {
      v16 = 0;
      if ( (unsigned int)pm_conc_connection_list <= 6 && ((1 << pm_conc_connection_list) & 0x4A) != 0 )
      {
        if ( a2 )
          *a2 = qword_8D4F00;
        v16 = 1;
      }
    }
    else
    {
      v16 = 0;
    }
    if ( BYTE4(qword_8D4F14) == v15
      && BYTE4(qword_8D4F24) == 1
      && (unsigned int)qword_8D4F0C <= 6
      && ((1 << qword_8D4F0C) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_8D4F24;
      ++v16;
    }
    if ( BYTE4(qword_8D4F38) == v15
      && BYTE4(qword_8D4F48) == 1
      && (unsigned int)qword_8D4F30 <= 6
      && ((1 << qword_8D4F30) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_8D4F48;
      ++v16;
    }
    if ( BYTE4(qword_8D4F5C) == v15
      && BYTE4(qword_8D4F6C) == 1
      && (unsigned int)qword_8D4F54 <= 6
      && ((1 << qword_8D4F54) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_8D4F6C;
      ++v16;
    }
    if ( BYTE4(qword_8D4F80) == v15
      && BYTE4(qword_8D4F90) == 1
      && (unsigned int)qword_8D4F78 <= 6
      && ((1 << qword_8D4F78) & 0x4A) != 0 )
    {
      if ( a2 )
        a2[v16] = qword_8D4F90;
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
