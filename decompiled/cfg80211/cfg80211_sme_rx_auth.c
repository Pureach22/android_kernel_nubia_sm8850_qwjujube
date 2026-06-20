_QWORD *__fastcall cfg80211_sme_rx_auth(_QWORD *result, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x1
  __int64 v5; // x8
  __int64 v6; // x16
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w10
  int v12; // w19
  int v13; // w10
  int v14; // w10
  _QWORD *v15; // x20
  __int64 v17; // x0
  int v18; // w11
  __int64 v19; // x1
  _QWORD s[79]; // [xsp+8h] [xbp-258h] BYREF

  s[74] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *result;
  if ( !*result )
  {
    __break(0x800u);
    if ( (v6 & 0x10000000000LL) != 0 )
      JUMPOUT(0x831FC);
    v2 = _traceiter_rdev_sched_scan_stop();
    v3 = s[0];
    v4 = s[78];
    v5 = *(_QWORD *)(v8 + 16) - 1LL;
    *(_DWORD *)(v8 + 16) = v5;
    if ( !v5 || (v2 = v7, !*(_QWORD *)(v8 + 16)) )
      preempt_schedule_notrace(v2, v4, v3);
    JUMPOUT(0x7D32C);
  }
  v10 = result[10];
  if ( v10 )
  {
    v11 = *(_DWORD *)(v10 + 400);
    if ( v11 != 11 )
    {
      v12 = *(unsigned __int16 *)(a2 + 28);
      if ( *(_WORD *)(a2 + 28) )
      {
        if ( v12 == 13 && *(_BYTE *)(v10 + 432) == 1 )
        {
          v13 = *(_DWORD *)(v10 + 48);
          if ( v13 != 3 )
          {
            if ( v13 == 1 )
            {
              v14 = 3;
            }
            else if ( v13 )
            {
              v14 = 0;
            }
            else if ( result[11] )
            {
              v14 = 1;
            }
            else
            {
              v14 = 3;
            }
            *(_DWORD *)(v10 + 48) = v14;
            v18 = 2;
            v10 = result[10];
            goto LABEL_19;
          }
        }
        v15 = result;
        memset(s, 0, 0x250u);
        v17 = v15[4];
        LODWORD(s[0]) = v12;
        s[15] = a2 + 16;
        result = (_QWORD *)_cfg80211_connect_result(v17, (__int64)s);
      }
      else if ( v11 == 3 )
      {
        v18 = 5;
LABEL_19:
        v19 = system_wq;
        *(_DWORD *)(v10 + 400) = v18;
        result = (_QWORD *)queue_work_on(32, v19, v9 - 688);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
