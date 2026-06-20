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
  v3 = *(_QWORD *)(a1 + 18048);
  v4 = *(_QWORD *)(a1 + 18040);
  v5 = *(unsigned int *)(a1 + 18056);
  *(_DWORD *)(a1 + 18272) = *(_DWORD *)(a1 + 18072);
  dp_ipa_get_shared_mem_info(v2, a1 + 18208, v3, v4, v5);
  dp_ipa_get_shared_mem_info(
    *(_QWORD *)(a1 + 24),
    a1 + 18280,
    *(_QWORD *)(a1 + 18088),
    *(_QWORD *)(a1 + 18080),
    *(unsigned int *)(a1 + 18096));
  dp_ipa_get_shared_mem_info(
    *(_QWORD *)(a1 + 24),
    a1 + 18344,
    *(_QWORD *)(a1 + 18144),
    *(_QWORD *)(a1 + 18136),
    *(unsigned int *)(a1 + 18152));
  dp_ipa_get_shared_mem_info(
    *(_QWORD *)(a1 + 24),
    a1 + 18408,
    *(_QWORD *)(a1 + 18176),
    *(_QWORD *)(a1 + 18168),
    *(unsigned int *)(a1 + 18184));
  v6 = 8;
  if ( !*(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) )
    v6 = 0;
  if ( *(_QWORD *)(a1 + 18208 + v6) && *(_QWORD *)(a1 + 18280 + v6) && *(_QWORD *)(a1 + 18344 + v6) )
    return 16 * (unsigned int)(*(_QWORD *)(a1 + 18408 + v6) == 0);
  else
    return 16;
}
