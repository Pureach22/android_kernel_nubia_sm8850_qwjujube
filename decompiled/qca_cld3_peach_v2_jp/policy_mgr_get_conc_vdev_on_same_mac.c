__int64 __fastcall policy_mgr_get_conc_vdev_on_same_mac(__int64 a1, int a2, unsigned __int8 a3)
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
    if ( BYTE4(qword_81C458) != 1 || (v16 = qword_81C458, (_DWORD)qword_81C458 == a2) || BYTE4(qword_81C448) != v15 )
    {
      if ( BYTE4(qword_81C47C) != 1 || (v16 = qword_81C47C, (_DWORD)qword_81C47C == a2) || BYTE4(qword_81C46C) != v15 )
      {
        if ( BYTE4(qword_81C4A0) != 1 || (v16 = qword_81C4A0, (_DWORD)qword_81C4A0 == a2) || BYTE4(qword_81C490) != v15 )
        {
          if ( BYTE4(qword_81C4C4) != 1
            || (v16 = qword_81C4C4, (_DWORD)qword_81C4C4 == a2)
            || BYTE4(qword_81C4B4) != v15 )
          {
            if ( BYTE4(qword_81C4E8) != 1
              || (v16 = qword_81C4E8, (_DWORD)qword_81C4E8 == a2)
              || BYTE4(qword_81C4D8) != v15 )
            {
              v16 = 255;
            }
          }
        }
      }
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
      "policy_mgr_get_conc_vdev_on_same_mac");
    return 255;
  }
  return v16;
}
