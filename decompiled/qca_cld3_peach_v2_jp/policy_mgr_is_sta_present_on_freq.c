__int64 __fastcall policy_mgr_is_sta_present_on_freq(__int64 a1, _BYTE *a2, int a3, _DWORD *a4)
{
  __int64 context; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  __int64 *v17; // x8
  unsigned int v18; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v16 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_81C458) == 1
      && ((unsigned int)pm_conc_connection_list | 2) == 2
      && (v17 = &pm_conc_connection_list, HIDWORD(pm_conc_connection_list) == a3)
      || BYTE4(qword_81C47C) == 1
      && ((unsigned int)qword_81C464 | 2) == 2
      && (v17 = &qword_81C464, HIDWORD(qword_81C464) == a3)
      || BYTE4(qword_81C4A0) == 1
      && ((unsigned int)qword_81C488 | 2) == 2
      && (v17 = &qword_81C488, HIDWORD(qword_81C488) == a3)
      || BYTE4(qword_81C4C4) == 1
      && ((unsigned int)qword_81C4AC | 2) == 2
      && (v17 = &qword_81C4AC, HIDWORD(qword_81C4AC) == a3)
      || BYTE4(qword_81C4E8) == 1
      && ((unsigned int)qword_81C4D0 | 2) == 2
      && (v17 = &qword_81C4D0, HIDWORD(qword_81C4D0) == a3) )
    {
      *a2 = *((_DWORD *)v17 + 6);
      *a4 = *((_DWORD *)v17 + 2);
      v18 = 1;
    }
    else
    {
      v18 = 0;
    }
    qdf_mutex_release(v16 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_is_sta_present_on_freq");
    return 0;
  }
  return v18;
}
