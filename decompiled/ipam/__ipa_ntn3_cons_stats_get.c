__int64 __fastcall _ipa_ntn3_cons_stats_get(__int64 a1, unsigned int a2)
{
  __int64 v2; // x28
  int v3; // s9
  int v4; // s13
  __int64 result; // x0
  __int64 v8; // x3
  unsigned int v9; // w21
  __int64 v10; // x20
  __int64 v11; // x3
  __int64 v12; // x3
  __int64 v13; // x3
  __int64 v14; // x3
  __int64 v15; // x3
  __int64 v16; // x3

  _ReadStatusReg(SP_EL0);
  ipa3_inc_client_enable_clks();
  result = ipa_get_ep_mapping(a2);
  if ( (_DWORD)result == -1 )
    goto LABEL_4;
  if ( (unsigned int)result < 0x24 )
  {
    v9 = result;
    v10 = *(_QWORD *)(ipa3_ctx + 480LL * (unsigned int)result + 176);
    *(_BYTE *)(a1 + 8) = (unsigned int)gsi_ntn3_client_stats_get(result, 4, (unsigned int)v10, v8) != 0;
    *(_DWORD *)(a1 + 12) = gsi_ntn3_client_stats_get(v9, 5, (unsigned int)v10, v11);
    *(_DWORD *)(a1 + 16) = gsi_ntn3_client_stats_get(v9, 6, (unsigned int)v10, v12);
    *(_DWORD *)(a1 + 20) = gsi_ntn3_client_stats_get(v9, 7, (unsigned int)v10, v13);
    *(_DWORD *)(a1 + 24) = gsi_ntn3_client_stats_get(v9, 8, (unsigned int)v10, v14);
    *(_DWORD *)(a1 + 28) = gsi_ntn3_client_stats_get(v9, 9, (unsigned int)v10, v15);
    *(_DWORD *)(a1 + 32) = gsi_ntn3_client_stats_get(v9, 0xFFFFFFFFLL, (unsigned int)v10, v16);
    *(_DWORD *)(a1 + 4) = gsi_get_refetch_reg((int)v10, 0);
    *(_DWORD *)a1 = gsi_get_refetch_reg((int)v10, 1);
    result = ipa3_dec_client_disable_clks();
LABEL_4:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  *(_DWORD *)(v2 - 44) = v4;
  *(_DWORD *)(v2 - 40) = v3;
  return ipa_eth_ntn3_get_status();
}
