unsigned __int64 __fastcall nl80211_start_sched_scan(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v5; // x24
  __int64 v6; // x22
  unsigned __int64 result; // x0
  unsigned __int64 v8; // x22
  __int64 v9; // x8
  bool v10; // cf
  __int64 v11; // x8
  __int64 v12; // x3
  __int64 (__fastcall *v13)(__int64, __int64, unsigned __int64, __int64); // x8
  unsigned int v14; // w0
  unsigned int v15; // w19

  v2 = *(_QWORD *)(a2 + 48);
  if ( !*(_BYTE *)(v2 + 1129) || !*(_QWORD *)(*(_QWORD *)v2 + 592LL) )
    return 4294967201LL;
  v3 = *(_QWORD *)(a2 + 56);
  v5 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 2040LL);
  v6 = *(_QWORD *)(v3 + 992);
  result = cfg80211_sched_scan_req_possible(*(_QWORD *)(a2 + 48), v5 != 0);
  if ( !(_DWORD)result )
  {
    result = nl80211_parse_sched_scan(v2 + 992, v6, *(_QWORD *)(a2 + 32), *(unsigned __int8 *)(v2 + 1131));
    v8 = result;
    if ( result < 0xFFFFFFFFFFFFF001LL || (result = (unsigned int)result, !(_DWORD)v8) )
    {
      if ( v5 && *(unsigned __int8 *)(v2 + 1129) >= 2u )
      {
        v9 = *(_QWORD *)(v2 + 176);
        v10 = __CFADD__(v9, 1);
        v11 = v9 + 1;
        *(_QWORD *)(v2 + 176) = v11;
        if ( v10 )
        {
          __break(0x800u);
          v11 = *(_QWORD *)(v2 + 176) + 1LL;
          *(_QWORD *)(v2 + 176) = v11;
        }
        *(_QWORD *)v8 = v11;
      }
      v12 = *(_QWORD *)v8;
      v13 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64, __int64))(*(_QWORD *)v2 + 592LL);
      if ( *((_DWORD *)v13 - 1) != 498113852 )
        __break(0x8228u);
      v14 = v13(v2 + 992, v3, v8, v12);
      if ( v14 )
      {
        v15 = v14;
        kfree(v8);
        return v15;
      }
      else
      {
        *(_QWORD *)(v8 + 112) = v2 + 992;
        *(_QWORD *)(v8 + 120) = v3;
        if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 1632LL) )
          *(_DWORD *)(v8 + 160) = *(_DWORD *)(a2 + 4);
        cfg80211_add_sched_scan_req(v2, v8);
        nl80211_send_sched_scan((_QWORD *)v8, 0x4Bu);
        return 0;
      }
    }
  }
  return result;
}
