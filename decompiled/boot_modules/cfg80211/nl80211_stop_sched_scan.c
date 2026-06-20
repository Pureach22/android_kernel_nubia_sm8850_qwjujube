__int64 __fastcall nl80211_stop_sched_scan(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x1
  __int64 result; // x0
  int v5; // w9
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 48);
  if ( *(_BYTE *)(v2 + 1129) && *(_QWORD *)(*(_QWORD *)v2 + 600LL) )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 704LL) )
    {
      v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 704LL);
      v6[0] = 0;
      nla_memcpy(v6, v3, 8);
      result = _cfg80211_stop_sched_scan(v2, v6[0], 0);
    }
    else
    {
      v6[0] = *(_QWORD *)(v2 + 248);
      if ( v2 + 248 == v6[0]
        || v6[0] == 168
        || *(_QWORD *)(v6[0] - 168LL)
        || (v5 = *(_DWORD *)(v6[0] - 8LL)) != 0 && v5 != *(_DWORD *)(a2 + 4) )
      {
        result = 4294967294LL;
      }
      else
      {
        result = cfg80211_stop_sched_scan_req(v2, v6[0] - 168LL, 0);
      }
    }
  }
  else
  {
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
