__int64 __fastcall policy_mgr_mode_get_macid_by_vdev_id(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  int v14; // w21
  __int64 *v15; // x8
  unsigned int v16; // w21

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_mode_get_macid_by_vdev_id");
    return a2;
  }
  v13 = context;
  v14 = policy_mgr_con_mode_by_vdev_id(a1, a2);
  qdf_mutex_acquire(v13 + 56);
  if ( (_DWORD)pm_conc_connection_list != v14
    || (v15 = &pm_conc_connection_list, BYTE4(qword_8D4F00) != 1)
    || (_DWORD)qword_8D4F00 != a2 )
  {
    if ( (_DWORD)qword_8D4F0C != v14 || (v15 = &qword_8D4F0C, BYTE4(qword_8D4F24) != 1) || (_DWORD)qword_8D4F24 != a2 )
    {
      if ( (_DWORD)qword_8D4F30 != v14 || (v15 = &qword_8D4F30, BYTE4(qword_8D4F48) != 1) || (_DWORD)qword_8D4F48 != a2 )
      {
        if ( (_DWORD)qword_8D4F54 != v14
          || (v15 = &qword_8D4F54, BYTE4(qword_8D4F6C) != 1)
          || (_DWORD)qword_8D4F6C != a2 )
        {
          if ( (_DWORD)qword_8D4F78 != v14 )
          {
            v16 = 255;
            goto LABEL_18;
          }
          v15 = &qword_8D4F78;
          v16 = 255;
          if ( BYTE4(qword_8D4F90) != 1 || (_DWORD)qword_8D4F90 != a2 )
            goto LABEL_18;
        }
      }
    }
  }
  v16 = *((unsigned __int8 *)v15 + 12);
LABEL_18:
  qdf_mutex_release(v13 + 56);
  return v16;
}
