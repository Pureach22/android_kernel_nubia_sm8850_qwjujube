__int64 __fastcall policy_mgr_get_channel(__int64 a1, unsigned int a2, _DWORD *a3)
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
  const char *v14; // x2
  __int64 v16; // x19
  __int64 *v17; // x22

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v14 = "%s: Invalid Context";
    goto LABEL_5;
  }
  if ( a2 > 6 )
  {
    v14 = "%s: incorrect mode";
LABEL_5:
    qdf_trace_msg(0x4Fu, 2u, v14, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_get_channel");
    return 0;
  }
  v16 = context;
  qdf_mutex_acquire(context + 56);
  if ( (_DWORD)pm_conc_connection_list == a2 && (!a3 || *a3 == (_DWORD)qword_8D4F00) )
  {
    v17 = &pm_conc_connection_list;
    if ( BYTE4(qword_8D4F00) == 1 )
      goto LABEL_28;
  }
  qdf_mutex_release(v16 + 56);
  qdf_mutex_acquire(v16 + 56);
  if ( (_DWORD)qword_8D4F0C == a2 && (!a3 || *a3 == (_DWORD)qword_8D4F24) )
  {
    v17 = &qword_8D4F0C;
    if ( (qword_8D4F24 & 0x100000000LL) != 0 )
      goto LABEL_28;
  }
  qdf_mutex_release(v16 + 56);
  qdf_mutex_acquire(v16 + 56);
  if ( (_DWORD)qword_8D4F30 == a2 && (!a3 || *a3 == (_DWORD)qword_8D4F48) )
  {
    v17 = &qword_8D4F30;
    if ( (qword_8D4F48 & 0x100000000LL) != 0 )
      goto LABEL_28;
  }
  if ( (qdf_mutex_release(v16 + 56), qdf_mutex_acquire(v16 + 56), (_DWORD)qword_8D4F54 == a2)
    && (!a3 || *a3 == (_DWORD)qword_8D4F6C)
    && (v17 = &qword_8D4F54, (qword_8D4F6C & 0x100000000LL) != 0)
    || (qdf_mutex_release(v16 + 56), qdf_mutex_acquire(v16 + 56), (_DWORD)qword_8D4F78 == a2)
    && (!a3 || *a3 == (_DWORD)qword_8D4F90)
    && (v17 = &qword_8D4F78, (qword_8D4F90 & 0x100000000LL) != 0) )
  {
LABEL_28:
    qdf_mutex_release(v16 + 56);
    return *((unsigned int *)v17 + 1);
  }
  qdf_mutex_release(v16 + 56);
  return 0;
}
