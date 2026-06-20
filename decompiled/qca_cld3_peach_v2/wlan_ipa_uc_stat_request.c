__int64 __fastcall wlan_ipa_uc_stat_request(__int64 a1, unsigned __int8 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 v13; // x8
  void (*v14)(void); // x8

  qdf_mutex_acquire(a1 + 7224);
  if ( wlan_ipa_is_fw_wdi_activated(a1) && (*(_BYTE *)(a1 + 3720) & 1) == 0 )
  {
    v12 = *(_QWORD *)(a1 + 1456);
    *(_DWORD *)(a1 + 4120) = a2;
    if ( v12 && *(_QWORD *)v12 && (v13 = *(_QWORD *)(*(_QWORD *)v12 + 152LL)) != 0 )
    {
      v14 = *(void (**)(void))(v13 + 56);
      if ( v14 )
      {
        if ( *((_DWORD *)v14 - 1) != 261447488 )
          __break(0x8228u);
        v14();
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v4, v5, v6, v7, v8, v9, v10, v11, "cdp_ipa_get_stat");
    }
  }
  return qdf_mutex_release(a1 + 7224);
}
