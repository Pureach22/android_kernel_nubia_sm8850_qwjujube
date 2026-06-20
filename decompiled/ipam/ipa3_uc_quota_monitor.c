__int64 __fastcall ipa3_uc_quota_monitor(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x9
  __int16 v5; // w8
  unsigned int v6; // w23
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h] BYREF
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  if ( (*(_BYTE *)(ipa3_ctx + 45387) & 1) != 0 )
  {
    LODWORD(v19) = 30;
    v2 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34224), 30, &v18, 3264, 0);
    v17 = v2;
    if ( v2 )
    {
      *(_QWORD *)(v2 + 4) = a1;
      *(_DWORD *)v2 = 4;
      v3 = v2;
      v4 = ipa3_ctx;
      *(_BYTE *)(v2 + 12) = 4;
      *(_WORD *)(v2 + 14) = *(_WORD *)(**(_QWORD **)(v4 + 34176) + 320LL) + 16 * *(unsigned __int8 *)(v4 + 45388) - 8;
      *(_WORD *)(v2 + 16) = *(_WORD *)(**(_QWORD **)(v4 + 34176) + 320LL) + 16 * *(unsigned __int8 *)(v4 + 45388) + 24;
      *(_WORD *)(v2 + 18) = *(_WORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 320LL)
                          + 16 * *(unsigned __int8 *)(ipa3_ctx + 45389)
                          - 8;
      v5 = *(_WORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 320LL) + 16 * *(unsigned __int8 *)(ipa3_ctx + 45389);
      *(_BYTE *)(v2 + 13) = 5;
      *(_WORD *)(v2 + 20) = v5 + 24;
      ipa3_inc_client_enable_clks();
      v6 = ipa3_uc_send_cmd_64b_param(v18, 0, 199, 192, 0, 2500);
      if ( v6 )
      {
        printk(&unk_3A4243, "ipa3_uc_quota_monitor");
        v14 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v15 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v15 )
          {
            ipc_log_string(
              v15,
              "ipa %s:%d  faile to set quota %llu, number offset %d\n",
              "ipa3_uc_quota_monitor",
              1786,
              *(_QWORD *)(v3 + 4),
              *(unsigned __int8 *)(v3 + 12));
            v14 = ipa3_ctx;
          }
          v16 = *(_QWORD *)(v14 + 34160);
          if ( v16 )
            ipc_log_string(
              v16,
              "ipa %s:%d  faile to set quota %llu, number offset %d\n",
              "ipa3_uc_quota_monitor",
              1786,
              *(_QWORD *)(v3 + 4),
              *(unsigned __int8 *)(v3 + 12));
        }
      }
      else
      {
        v7 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v8 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v8 )
          {
            ipc_log_string(
              v8,
              "ipa %s:%d  offest1 %d offest2 %d offest3 %d offest4 %d\n",
              "ipa3_uc_quota_monitor",
              1794,
              *(unsigned __int16 *)(v3 + 14),
              *(unsigned __int16 *)(v3 + 16),
              *(unsigned __int16 *)(v3 + 18),
              *(unsigned __int16 *)(v3 + 20));
            v7 = ipa3_ctx;
          }
          v9 = *(_QWORD *)(v7 + 34160);
          if ( v9 )
            ipc_log_string(
              v9,
              "ipa %s:%d  offest1 %d offest2 %d offest3 %d offest4 %d\n",
              "ipa3_uc_quota_monitor",
              1794,
              *(unsigned __int16 *)(v3 + 14),
              *(unsigned __int16 *)(v3 + 16),
              *(unsigned __int16 *)(v3 + 18),
              *(unsigned __int16 *)(v3 + 20));
        }
      }
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v19, v17, v18, 0);
      ipa3_dec_client_disable_clks();
      result = v6;
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    printk(&unk_3D8D77, "ipa3_uc_quota_monitor");
    v11 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_17;
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d fnr_info not valid!\n", "ipa3_uc_quota_monitor", 1740);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d fnr_info not valid!\n", "ipa3_uc_quota_monitor", 1740);
      result = 4294967274LL;
    }
    else
    {
LABEL_17:
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
