unsigned __int64 __fastcall nl80211_set_mac_acl(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  int v4; // w9
  __int64 v6; // x21
  unsigned __int64 v7; // x19
  unsigned __int64 result; // x0
  __int64 (__fastcall *v9)(__int64, __int64, unsigned __int64); // x8
  unsigned int v10; // w20

  v2 = *(_QWORD *)(a2 + 56);
  v3 = *(_QWORD *)(v2 + 992);
  v4 = *(_DWORD *)(v3 + 8);
  if ( v4 != 9 && v4 != 3 )
    return 4294967201LL;
  if ( !*(_DWORD *)(v3 + 400) )
    return 4294967274LL;
  v6 = *(_QWORD *)(a2 + 48);
  result = parse_acl_data(v6 + 992, a2);
  v7 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)result;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64))(*(_QWORD *)v6 + 672LL);
  if ( *((_DWORD *)v9 - 1) != -449291048 )
    __break(0x8228u);
  v10 = v9(v6 + 992, v2, result);
  kfree(v7);
  return v10;
}
