__int64 wlan_queue_logmsg_for_app()
{
  _QWORD **v0; // x11
  __int64 result; // x0
  __int64 *v2; // x1
  _QWORD *v3; // x10
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  __int64 v6; // x11

  v0 = (_QWORD **)&off_826C08;
  *(_BYTE *)(qword_826C70 + *(unsigned int *)(qword_826C70 + 24) + 32) = 0;
  *(_WORD *)(qword_826C70 + 28) = 89;
  *(_WORD *)(qword_826C70 + 30) = *(_DWORD *)(qword_826C70 + 24);
  result = qword_826C70;
  v2 = (__int64 *)qword_826C10;
  if ( (_UNKNOWN **)qword_826C70 == &off_826C08
    || qword_826C10 == qword_826C70
    || *(_UNKNOWN ***)qword_826C10 != &off_826C08 )
  {
    result = _list_add_valid_or_report(qword_826C70, qword_826C10);
  }
  else
  {
    qword_826C10 = qword_826C70;
    *(_QWORD *)qword_826C70 = &off_826C08;
    *(_QWORD *)(result + 8) = v2;
    *v2 = result;
  }
  v3 = &unk_826000;
  v4 = (_QWORD *)qword_826BF8;
  if ( (__int64 *)qword_826BF8 == &qword_826BF8 )
  {
    v4 = *v0;
    if ( *v0 == v0 )
      goto LABEL_13;
    qword_826C70 = (__int64)*v0;
    ++dword_826C6C;
  }
  else
  {
    qword_826C70 = qword_826BF8;
  }
  v5 = (_QWORD *)v4[1];
  if ( (_QWORD *)*v5 == v4 && (v6 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
  {
    *(_QWORD *)(v6 + 8) = v5;
    *v5 = v6;
  }
  else
  {
    result = _list_del_entry_valid_or_report(v4);
  }
  *v4 = v4;
  v4[1] = v4;
LABEL_13:
  *(_DWORD *)(v3[398] + 24LL) = 0;
  return result;
}
