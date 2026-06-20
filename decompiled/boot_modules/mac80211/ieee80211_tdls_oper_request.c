__int64 __fastcall ieee80211_tdls_oper_request(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( *(_DWORD *)a1 == 2 && (*(_BYTE *)(a1 + 8) & 1) != 0 )
    return cfg80211_tdls_oper_request(*(_QWORD *)(a1 - 3112));
  else
    return printk(&unk_BB729, a1 - 3080, a3, a4);
}
