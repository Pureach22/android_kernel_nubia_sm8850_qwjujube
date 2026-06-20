__int64 __fastcall policy_mgr_mode_specific_connection_count(__int64 a1, int a2, _DWORD *a3)
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
  unsigned int v15; // w21

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)pm_conc_connection_list == a2 )
    {
      v15 = BYTE4(qword_8D4F00);
      if ( a3 && BYTE4(qword_8D4F00) )
      {
        v15 = 1;
        *a3 = 0;
      }
    }
    else
    {
      v15 = 0;
    }
    if ( (_DWORD)qword_8D4F0C == a2 && BYTE4(qword_8D4F24) == 1 )
    {
      if ( a3 )
        a3[v15] = 1;
      ++v15;
    }
    if ( (_DWORD)qword_8D4F30 == a2 && BYTE4(qword_8D4F48) == 1 )
    {
      if ( a3 )
        a3[v15] = 2;
      ++v15;
    }
    if ( (_DWORD)qword_8D4F54 == a2 && BYTE4(qword_8D4F6C) == 1 )
    {
      if ( a3 )
        a3[v15] = 3;
      ++v15;
    }
    if ( (_DWORD)qword_8D4F78 == a2 && BYTE4(qword_8D4F90) == 1 )
    {
      if ( a3 )
        a3[v15] = 4;
      ++v15;
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
      "policy_mgr_mode_specific_connection_count");
    return 0;
  }
  return v15;
}
