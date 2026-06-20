__int64 wlan_queue_logmsg_for_app()
{
  _QWORD **v0; // x11
  __int64 result; // x0
  __int64 *v2; // x1
  __int64 *v3; // x10
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  __int64 v6; // x11

  v0 = (_QWORD **)&off_76E160;
  *(_BYTE *)(qword_76E1C8 + *(unsigned int *)(qword_76E1C8 + 24) + 32) = 0;
  *(_WORD *)(qword_76E1C8 + 28) = 89;
  *(_WORD *)(qword_76E1C8 + 30) = *(_DWORD *)(qword_76E1C8 + 24);
  result = qword_76E1C8;
  v2 = (__int64 *)qword_76E168;
  if ( (_UNKNOWN **)qword_76E1C8 == &off_76E160
    || qword_76E168 == qword_76E1C8
    || *(_UNKNOWN ***)qword_76E168 != &off_76E160 )
  {
    result = _list_add_valid_or_report(qword_76E1C8, qword_76E168);
  }
  else
  {
    qword_76E168 = qword_76E1C8;
    *(_QWORD *)qword_76E1C8 = &off_76E160;
    *(_QWORD *)(result + 8) = v2;
    *v2 = result;
  }
  v3 = &reg_get_max_eirp___last_ticks;
  v4 = (_QWORD *)qword_76E150;
  if ( (__int64 *)qword_76E150 == &qword_76E150 )
  {
    v4 = *v0;
    if ( *v0 == v0 )
      goto LABEL_13;
    qword_76E1C8 = (__int64)*v0;
    ++dword_76E1C4;
  }
  else
  {
    qword_76E1C8 = qword_76E150;
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
  *(_DWORD *)(v3[57] + 24) = 0;
  return result;
}
