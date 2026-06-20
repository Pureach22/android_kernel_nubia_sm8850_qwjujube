__int64 __fastcall cfg80211_stop_sched_scan_req(__int64 *a1, __int64 *a2, char a3)
{
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x8
  _QWORD *v7; // x0
  _DWORD *v8; // x8
  __int64 result; // x0
  __int64 **v10; // x8
  __int64 **v11; // x0
  __int64 *v12; // x9

  if ( (a3 & 1) != 0 )
    goto LABEL_5;
  v4 = a2[15];
  v5 = *a2;
  v6 = *a1;
  v7 = a1 + 124;
  v8 = *(_DWORD **)(v6 + 600);
  if ( *(v8 - 1) != 485556379 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v8)(v7, v4, v5);
  if ( !(_DWORD)result )
  {
LABEL_5:
    nl80211_send_sched_scan(a2, 0x4Eu);
    v10 = (__int64 **)a2[22];
    v11 = (__int64 **)(a2 + 21);
    if ( *v10 == a2 + 21 && (v12 = *v11, (__int64 **)(*v11)[1] == v11) )
    {
      v12[1] = (__int64)v10;
      *v10 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(v11);
    }
    a2[22] = 0xDEAD000000000122LL;
    if ( a2 )
      kvfree_call_rcu(a2 + 18, a2);
    return 0;
  }
  return result;
}
