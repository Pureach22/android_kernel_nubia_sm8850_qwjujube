__int64 __fastcall icnss_qmi_send(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  __int64 result; // x0
  __int64 v8; // x0

  v6 = penv;
  if ( !penv )
    return 4294967277LL;
  if ( (*(_QWORD *)(penv + 1832) & 1) == 0 )
    return 4294967274LL;
  v8 = penv;
  *(_QWORD *)(penv + 5464) = a6;
  *(_QWORD *)(v6 + 5456) = a5;
  result = icnss_wlfw_get_info_send_sync(v8);
  if ( (_DWORD)result )
  {
    *(_QWORD *)(v6 + 5456) = 0;
    *(_QWORD *)(v6 + 5464) = 0;
  }
  return result;
}
