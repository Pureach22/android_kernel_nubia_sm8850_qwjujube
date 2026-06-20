__int64 __fastcall ieee80211_ifa_changed(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x27
  __int64 *v4; // x8
  __int64 v5; // x19
  __int64 v6; // x9
  __int64 v7; // x22
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x10
  int v16; // w9

  v4 = *(__int64 **)(a3 + 24);
  v5 = *v4;
  v6 = *(_QWORD *)(*v4 + 992);
  if ( !v6 )
    return 0;
  if ( *(_QWORD *)v6 != *(_QWORD *)(a1 - 5032) )
    return 0;
  if ( *(_BYTE *)(v6 + 67) != 1 )
    return 0;
  if ( *(_DWORD *)(v5 + 7408) != 2 )
    return 0;
  v7 = *(_QWORD *)(*(_QWORD *)(v5 + 4296) + 968LL);
  if ( !v7 )
    return 0;
  v9 = mutex_lock(*(_QWORD *)(a1 - 5032));
  v10 = *(_QWORD *)(v7 + 16);
  if ( !v10 )
  {
    v16 = 0;
    v12 = a1;
LABEL_21:
    *(_DWORD *)(v5 + 7444) = v16;
    if ( (*(_BYTE *)(v5 + 5165) & 8) != 0 )
    {
      ieee80211_vif_cfg_change_notify(v5 + 2688, 4096);
      v12 = a1;
    }
    mutex_unlock(*(_QWORD *)(v12 - 5032));
    return 1;
  }
  *(_DWORD *)(v5 + 7428) = *(_DWORD *)(v10 + 52);
  v11 = *(_QWORD *)(v10 + 16);
  v12 = a1;
  if ( !v11 )
  {
    v16 = 1;
    goto LABEL_21;
  }
  *(_DWORD *)(v5 + 7432) = *(_DWORD *)(v11 + 52);
  v13 = *(_QWORD *)(v11 + 16);
  if ( !v13 )
  {
    v16 = 2;
    goto LABEL_21;
  }
  *(_DWORD *)(v5 + 7436) = *(_DWORD *)(v13 + 52);
  v14 = *(_QWORD *)(v13 + 16);
  if ( !v14 )
  {
    v16 = 3;
    goto LABEL_21;
  }
  *(_DWORD *)(v5 + 7440) = *(_DWORD *)(v14 + 52);
  v15 = *(_QWORD *)(v14 + 16);
  if ( !v15 )
  {
    v16 = 4;
    goto LABEL_21;
  }
  v16 = 4;
  while ( v16 > 3 )
  {
    v15 = *(_QWORD *)(v15 + 16);
    ++v16;
    if ( !v15 )
      goto LABEL_21;
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return ieee80211_ifa6_changed(v9);
}
