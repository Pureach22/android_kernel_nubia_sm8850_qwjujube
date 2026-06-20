void __fastcall ipa3_tasklet_rx_notify(__int64 a1)
{
  void (*v2)(void); // x8
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x10
  __int64 v5; // x8
  const char *v6; // x8
  _QWORD v7[3]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v8[4]; // [xsp+20h] [xbp-20h] BYREF

  v8[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v8, 0, 24);
  *(_DWORD *)(ipa3_ctx + 31972) = 1;
  do
  {
    ipa_pm_activate(*(unsigned int *)(a1 + 1776));
    while ( !(unsigned int)ipa_poll_gsi_n_pkt(a1, v8, 1, v7) )
    {
      if ( handle_skb_completion(v8, 1, 0) )
      {
        v2 = *(void (**)(void))(a1 + 128);
        if ( *((_DWORD *)v2 - 1) != 2117430862 )
          __break(0x8228u);
        v2();
        v3 = *(void (__fastcall **)(_QWORD))(a1 + 360);
        if ( *((_DWORD *)v3 - 1) != 1136933575 )
          __break(0x8228u);
        v3(a1);
      }
    }
  }
  while ( (unsigned int)((__int64 (__fastcall *)(__int64))ipa3_rx_switch_to_intr_mode)(a1) == -13 );
  v4 = *(_QWORD *)(a1 + 1624);
  v7[1] = "ipa_dp.c";
  v7[2] = 7550;
  v5 = *(unsigned int *)(v4 + 4);
  if ( (unsigned int)v5 <= 0x85 )
    v6 = ipa_clients_strings[v5];
  else
    v6 = "Invalid Client";
  v7[0] = v6;
  ipa3_dec_client_disable_clks_no_block();
  _ReadStatusReg(SP_EL0);
}
