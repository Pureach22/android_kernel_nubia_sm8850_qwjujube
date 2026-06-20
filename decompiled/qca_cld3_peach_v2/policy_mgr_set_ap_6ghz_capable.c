__int64 __fastcall policy_mgr_set_ap_6ghz_capable(__int64 a1, unsigned __int8 a2, char a3, unsigned int a4)
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
  __int64 v16; // x22
  __int64 *v17; // x8
  unsigned int v18; // w23
  int v19; // w9
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x5

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
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
             "policy_mgr_set_ap_6ghz_capable");
  v16 = context;
  qdf_mutex_acquire(context + 56);
  if ( BYTE4(qword_8D4F00) == 1
    && (unsigned int)pm_conc_connection_list <= 6
    && ((1 << pm_conc_connection_list) & 0x4A) != 0 )
  {
    v17 = &pm_conc_connection_list;
    if ( (_DWORD)qword_8D4F00 == a2 )
      goto LABEL_22;
  }
  if ( BYTE4(qword_8D4F24) == 1 && (unsigned int)qword_8D4F0C <= 6 && ((1 << qword_8D4F0C) & 0x4A) != 0 )
  {
    v17 = &qword_8D4F0C;
    if ( (_DWORD)qword_8D4F24 == a2 )
      goto LABEL_22;
  }
  if ( BYTE4(qword_8D4F48) == 1 && (unsigned int)qword_8D4F30 <= 6 && ((1 << qword_8D4F30) & 0x4A) != 0 )
  {
    v17 = &qword_8D4F30;
    if ( (_DWORD)qword_8D4F48 == a2 )
      goto LABEL_22;
  }
  if ( BYTE4(qword_8D4F6C) == 1 && (unsigned int)qword_8D4F54 <= 6 && ((1 << qword_8D4F54) & 0x4A) != 0 )
  {
    v17 = &qword_8D4F54;
    if ( (_DWORD)qword_8D4F6C == a2 )
      goto LABEL_22;
  }
  if ( BYTE4(qword_8D4F90) != 1 )
    goto LABEL_27;
  v18 = 0;
  if ( (unsigned int)qword_8D4F78 <= 6 && ((1 << qword_8D4F78) & 0x4A) != 0 )
  {
    v17 = &qword_8D4F78;
    if ( (_DWORD)qword_8D4F90 == a2 )
    {
LABEL_22:
      if ( (a3 & 1) != 0 )
        v19 = *((_DWORD *)v17 + 8) | a4;
      else
        v19 = v17[4] & ~a4;
      v18 = v19 | 1;
      *((_DWORD *)v17 + 8) = v19 | 1;
      goto LABEL_28;
    }
LABEL_27:
    v18 = 0;
  }
LABEL_28:
  qdf_mutex_release(v16 + 56);
  if ( (a3 & 1) != 0 )
    v29 = "set";
  else
    v29 = "clr";
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: vdev %d %s conn_6ghz_flag %x new %x",
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           "policy_mgr_set_ap_6ghz_capable",
           a2,
           v29,
           a4,
           v18);
}
