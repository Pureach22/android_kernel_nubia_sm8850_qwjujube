__int64 __fastcall ieee80211_link_use_reserved_context(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x19
  int v5; // w9
  bool v6; // zf
  __int64 result; // x0
  unsigned int v8; // w2

  v1 = *(_QWORD *)(a1 + 368);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 944) + 832LL);
  if ( v2 )
    v3 = v2 - 152;
  else
    v3 = 0;
  if ( !v1 || *(_DWORD *)(v1 + 64) == 1 || *(_BYTE *)(a1 + 441) == 1 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 1616LL);
  *(_BYTE *)(a1 + 441) = 1;
  v5 = *(_DWORD *)(v1 + 64);
  if ( !v5 )
  {
    if ( v3 )
      return ieee80211_link_use_reserved_reassign(a1);
    else
      return ieee80211_link_use_reserved_assign(a1);
  }
  v6 = v5 == 2;
  if ( !v3 )
    goto LABEL_11;
  if ( v5 != 2 )
  {
    v6 = *(_DWORD *)(v3 + 64) == 1;
LABEL_11:
    if ( !v6 )
      return 0;
  }
  v8 = ieee80211_vif_use_reserved_switch(v4);
  result = 0;
  if ( v8 != -11 && v8 )
  {
    if ( *(_DWORD *)(v1 + 64) != 2 )
    {
      dev_info(*(_QWORD *)(v4 + 72) + 392LL, "depending in-place reservation failed (err=%d)\n", v8);
      return 0;
    }
    return v8;
  }
  return result;
}
