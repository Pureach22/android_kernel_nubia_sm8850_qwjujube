__int64 __fastcall ipa3_get_hps_dps_areas_absolute_addr_and_sz(_DWORD *a1)
{
  int reg_n; // w21
  int v3; // w22
  int v4; // w19
  __int64 v5; // x0
  int v6; // w20
  int v7; // w26
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 reg_base; // x0
  int v11; // w25
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 result; // x0
  int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0

  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x10u )
  {
    reg_n = ipahal_read_reg_n(95, 0);
    v3 = ipahal_read_reg_n(96, 0);
    v4 = ipahal_read_reg_n(97, 0);
    result = ipahal_read_reg_n(98, 0);
    v6 = result;
    *a1 = *(_DWORD *)(ipa3_ctx + 28640) + reg_n;
    v15 = *(_DWORD *)(ipa3_ctx + 28640) + v4;
  }
  else
  {
    reg_n = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(95, 0, 0);
    v3 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(96, 0, 0);
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(97, 0, 0);
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(98, 0, 0);
    v6 = v5;
    v7 = *(_DWORD *)(ipa3_ctx + 28640);
    reg_base = ipahal_get_reg_base(v5, v8, v9);
    *a1 = v7 + reg_n + reg_base;
    v11 = *(_DWORD *)(ipa3_ctx + 28640);
    result = ipahal_get_reg_base(reg_base, v12, v13);
    v15 = v11 + v4 + result;
  }
  a1[1] = v3 - reg_n + 4;
  a1[2] = v15;
  v16 = ipa3_ctx;
  a1[3] = v6 - v4 + 4;
  if ( v16 )
  {
    v17 = *(_QWORD *)(v16 + 34152);
    if ( v17 )
    {
      ipc_log_string(
        v17,
        "ipa %s:%d dps area: start offset=0x%x end offset=0x%x\n",
        "ipa3_get_hps_dps_areas_absolute_addr_and_sz",
        13273,
        reg_n,
        v3);
      v16 = ipa3_ctx;
    }
    result = *(_QWORD *)(v16 + 34160);
    if ( result )
    {
      result = ipc_log_string(
                 result,
                 "ipa %s:%d dps area: start offset=0x%x end offset=0x%x\n",
                 "ipa3_get_hps_dps_areas_absolute_addr_and_sz",
                 13273,
                 reg_n,
                 v3);
      v16 = ipa3_ctx;
    }
    if ( v16 )
    {
      v18 = *(_QWORD *)(v16 + 34152);
      if ( v18 )
      {
        ipc_log_string(
          v18,
          "ipa %s:%d hps area: start offset=0x%x end offset=0x%x\n",
          "ipa3_get_hps_dps_areas_absolute_addr_and_sz",
          13275,
          v4,
          v6);
        v16 = ipa3_ctx;
      }
      result = *(_QWORD *)(v16 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d hps area: start offset=0x%x end offset=0x%x\n",
                 "ipa3_get_hps_dps_areas_absolute_addr_and_sz",
                 13275,
                 v4,
                 v6);
    }
  }
  return result;
}
