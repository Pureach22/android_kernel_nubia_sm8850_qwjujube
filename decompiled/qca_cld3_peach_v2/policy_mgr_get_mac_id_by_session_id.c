__int64 __fastcall policy_mgr_get_mac_id_by_session_id(__int64 a1, unsigned __int8 a2, _BYTE *a3)
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
  __int64 *v15; // x9

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)qword_8D4F00 == a2 && (v15 = &pm_conc_connection_list, BYTE4(qword_8D4F00) == 1)
      || (_DWORD)qword_8D4F24 == a2 && (v15 = &qword_8D4F0C, (qword_8D4F24 & 0x100000000LL) != 0)
      || (_DWORD)qword_8D4F48 == a2 && (v15 = &qword_8D4F30, (qword_8D4F48 & 0x100000000LL) != 0)
      || (_DWORD)qword_8D4F6C == a2 && (v15 = &qword_8D4F54, (qword_8D4F6C & 0x100000000LL) != 0)
      || (_DWORD)qword_8D4F90 == a2 && (v15 = &qword_8D4F78, (qword_8D4F90 & 0x100000000LL) != 0) )
    {
      *a3 = *((_BYTE *)v15 + 12);
      qdf_mutex_release(v14 + 56);
      return 0;
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
      "policy_mgr_get_mac_id_by_session_id");
  }
  return 16;
}
