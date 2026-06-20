__int64 __fastcall ipa3_handle_rx(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w25
  int v4; // w26
  unsigned int v5; // w8
  void (*v6)(void); // x8
  void (*v7)(void); // x8
  int v8; // w9
  int v9; // w8
  const char *v10; // x8
  __int64 result; // x0
  const char *v12; // [xsp+8h] [xbp-28h] BYREF
  char *v13; // [xsp+10h] [xbp-20h]
  __int64 v14; // [xsp+18h] [xbp-18h]
  _QWORD v15[2]; // [xsp+20h] [xbp-10h] BYREF

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _ReadStatusReg(SP_EL0);
  v15[1] = v2;
  do
  {
    ipa_pm_activate_sync(*(unsigned int *)(a1 + 1776));
    v3 = 0;
    do
    {
      v13 = nullptr;
      v14 = 0;
      v12 = nullptr;
      if ( !*(_DWORD *)(a1 + 4) )
      {
        ++v3;
        goto LABEL_23;
      }
      v4 = 0;
      while ( !(unsigned int)ipa_poll_gsi_n_pkt(a1, &v12, 1, (int *)v15) )
      {
        v5 = *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL);
        if ( v5 > 0x2F )
          goto LABEL_12;
        if ( ((1LL << v5) & 0x2A800) == 0 )
        {
          if ( ((1LL << v5) & 0xA00000000000LL) != 0 )
          {
            ipa3_dma_memcpy_notify(a1);
            goto LABEL_6;
          }
LABEL_12:
          if ( v5 != 119 )
          {
            v15[0] = 0;
            if ( handle_skb_completion(&v12, 1, v15) )
            {
              v6 = *(void (**)(void))(*(_QWORD *)((char *)&unk_50 + v15[0]) + 128LL);
              if ( *((_DWORD *)v6 - 1) != 2117430862 )
                __break(0x8228u);
              v6();
              v7 = *(void (**)(void))(*(_QWORD *)((char *)&unk_50 + v15[0]) + 360LL);
              if ( *((_DWORD *)v7 - 1) != 1136933575 )
                __break(0x8228u);
              v7();
            }
            goto LABEL_6;
          }
        }
        ipa3_wlan_wq_rx_common(a1, (__int64)&v12);
LABEL_6:
        ++v4;
        if ( !*(_DWORD *)(a1 + 4) )
          break;
      }
      if ( v4 )
        v3 = 0;
      else
        ++v3;
LABEL_23:
      usleep_range_state(1010, 1050, 2);
    }
    while ( *(_DWORD *)a1 && v3 < 41 );
  }
  while ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa3_rx_switch_to_intr_mode)(
                          a1,
                          *(unsigned int *)(*(_QWORD *)(a1 + 1624) + 4LL)) == -13 );
  v8 = 95;
  v9 = *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL);
  if ( v9 > 94 )
  {
    if ( v9 == 95 )
      goto LABEL_33;
    if ( v9 != 127 )
      goto LABEL_36;
LABEL_32:
    v8 = 127;
    goto LABEL_33;
  }
  if ( v9 == 33 )
    goto LABEL_32;
  if ( v9 == 35 )
  {
LABEL_33:
    v13 = "ipa_dp.c";
    v14 = 1251;
    goto LABEL_34;
  }
LABEL_36:
  v13 = "ipa_dp.c";
  v14 = 1251;
  v8 = v9;
  if ( (unsigned int)v9 > 0x85 )
  {
    v10 = "Invalid Client";
    goto LABEL_35;
  }
LABEL_34:
  v10 = ipa_clients_strings[v8];
LABEL_35:
  v12 = v10;
  result = ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return result;
}
