__int64 __fastcall cfg80211_sme_scan_done(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 *bss; // x0
  __int64 v7; // x8
  int v8; // w10
  __int64 *v9; // x20
  __int64 v10; // x9

  v3 = *(_QWORD *)(result + 992);
  v4 = *(_QWORD *)v3;
  if ( *(_QWORD *)v3 )
  {
    v5 = *(_QWORD *)(v3 + 80);
    if ( v5 && *(_DWORD *)(v5 + 400) <= 1u )
    {
      bss = _cfg80211_get_bss(
              *(_QWORD *)v3,
              *(_DWORD **)v5,
              *(_QWORD *)(v5 + 16),
              *(void **)(v5 + 32),
              *(_QWORD *)(v5 + 40),
              *(_DWORD *)(v3 + 96),
              *(unsigned __int8 *)(v5 + 72) ^ 1u,
              1);
      if ( bss )
      {
        v7 = *(_QWORD *)(v3 + 80);
        v8 = *((_DWORD *)bss + 18);
        v9 = bss;
        *(_WORD *)(v7 + 408) = *((_WORD *)bss + 38);
        *(_DWORD *)(v7 + 404) = v8;
        *(_QWORD *)(v7 + 16) = v7 + 404;
        v10 = *bss;
        *(_DWORD *)(v7 + 400) = 2;
        *(_QWORD *)v7 = v10;
        queue_work_on(32, system_wq, v4 - 688);
        return cfg80211_put_bss(v4, v9);
      }
      else
      {
        return queue_work_on(32, system_wq, v4 - 688);
      }
    }
  }
  else
  {
    __break(0x800u);
    return cfg80211_sme_rx_auth(result, a2, a3);
  }
  return result;
}
