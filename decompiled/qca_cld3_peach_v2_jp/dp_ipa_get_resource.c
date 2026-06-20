__int64 __fastcall dp_ipa_get_resource(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  __int64 v6; // x8

  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0 )
    return 0;
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(a1 + 17992);
  v4 = *(_QWORD *)(a1 + 17984);
  v5 = *(unsigned int *)(a1 + 18000);
  *(_DWORD *)(a1 + 18216) = *(_DWORD *)(a1 + 18016);
  dp_ipa_get_shared_mem_info(v2, a1 + 18152, v3, v4, v5);
  dp_ipa_get_shared_mem_info(
    *(_QWORD *)(a1 + 24),
    a1 + 18224,
    *(_QWORD *)(a1 + 18032),
    *(_QWORD *)(a1 + 18024),
    *(unsigned int *)(a1 + 18040));
  dp_ipa_get_shared_mem_info(
    *(_QWORD *)(a1 + 24),
    a1 + 18288,
    *(_QWORD *)(a1 + 18088),
    *(_QWORD *)(a1 + 18080),
    *(unsigned int *)(a1 + 18096));
  dp_ipa_get_shared_mem_info(
    *(_QWORD *)(a1 + 24),
    a1 + 18352,
    *(_QWORD *)(a1 + 18120),
    *(_QWORD *)(a1 + 18112),
    *(unsigned int *)(a1 + 18128));
  v6 = 8;
  if ( !*(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) )
    v6 = 0;
  if ( *(_QWORD *)(a1 + 18152 + v6) && *(_QWORD *)(a1 + 18224 + v6) && *(_QWORD *)(a1 + 18288 + v6) )
    return 16 * (unsigned int)(*(_QWORD *)(a1 + 18352 + v6) == 0);
  else
    return 16;
}
