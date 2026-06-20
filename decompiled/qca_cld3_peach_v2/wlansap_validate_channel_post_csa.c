__int64 __fastcall wlansap_validate_channel_post_csa(__int64 a1, unsigned int *a2)
{
  _BYTE *v2; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v2 = *((_BYTE **)a2 + 193);
  if ( v2 && *v2 )
  {
    v5 = *(_QWORD *)(a1 + 21624);
  }
  else
  {
    if ( (policy_mgr_restrict_sap_on_unsafe_chan(*(_QWORD *)(a1 + 21624)) & 1) == 0 )
      return 1;
    v5 = *(_QWORD *)(a1 + 21624);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 2800);
      if ( v6 )
      {
        if ( (*(_BYTE *)(v6 + 994) & 2) != 0 )
          return 1;
      }
    }
  }
  if ( (policy_mgr_is_sap_freq_allowed(v5, *(_DWORD *)(*((_QWORD *)a2 + 2) + 16LL), *a2) & 1) == 0
    || wlan_reg_is_disable_for_pwrmode(*(_QWORD *)(a1 + 21632), *a2, 0, v7, v8, v9, v10, v11, v12, v13, v14) )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sap vdev %d on unsafe ch freq %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlansap_validate_channel_post_csa",
      *((unsigned __int8 *)a2 + 12),
      *a2);
    return 0;
  }
  return 1;
}
