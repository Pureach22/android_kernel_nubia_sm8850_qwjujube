__int64 __fastcall sde_cesta_sw_client_update(int a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v5; // x21
  char v6; // w20
  unsigned int v8; // w0
  int v9; // w8
  __int64 v10; // x0
  unsigned int v11; // w0
  unsigned int v12; // w20
  int v13; // w23
  __int64 v14; // x25
  int v15; // w24
  __int64 v16; // x27
  unsigned int v17; // w0
  unsigned int v18; // w5
  void *v19; // x0
  __int64 v20; // [xsp+28h] [xbp-18h] BYREF
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  result = 0;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  if ( !a1 )
  {
    v5 = cesta_list_0;
    if ( cesta_list_0 )
    {
      v6 = a3;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_cesta_sw_client_update",
        667,
        -1,
        0,
        a3,
        *(_QWORD *)(a2 + 16),
        *(_QWORD *)(a2 + 24),
        *(_QWORD *)a2);
      mutex_lock(v5 + 800);
      if ( (v6 & 2) != 0 )
      {
        icc_set_tag(*(_QWORD *)(v5 + 1072), 1);
        v8 = icc_set_bw(*(_QWORD *)(v5 + 1072), *(_QWORD *)a2 / 0x3E8uLL, *(_QWORD *)(a2 + 8) / 0x3E8uLL);
        if ( v8 )
        {
          v18 = v8;
          v19 = &unk_244035;
          goto LABEL_26;
        }
        *(_QWORD *)(v5 + 1080) = *(_QWORD *)a2;
        *(_QWORD *)(v5 + 1088) = *(_QWORD *)(a2 + 8);
      }
      if ( (v6 & 4) != 0 && *(_DWORD *)v5 <= 0x402FFu )
      {
        v9 = *(_DWORD *)(a2 + 32);
        v10 = *(_QWORD *)(v5 + 1120);
        BYTE4(v21) = 1;
        LODWORD(v21) = v9;
        v20 = 0;
        v11 = crm_write_perf_ol(v10, 1, 0, &v20);
        if ( v11 )
        {
          v12 = v11;
          printk(&unk_240509, "sde_cesta_sw_client_update");
          goto LABEL_20;
        }
        *(_DWORD *)(v5 + 1112) = *(_DWORD *)(a2 + 32);
      }
      if ( (v6 & 1) == 0 )
      {
        v12 = 0;
LABEL_20:
        mutex_unlock(v5 + 800);
        result = v12;
        goto LABEL_21;
      }
      v13 = *(_DWORD *)(v5 + 48);
      if ( !v13 )
        goto LABEL_22;
      v14 = *(_QWORD *)(v5 + 56);
      v15 = 0;
      while ( 1 )
      {
        v16 = v14 + 120LL * v15;
        if ( !strcmp((const char *)(v16 + 8), "core_clk") )
          break;
        if ( v13 == ++v15 )
          goto LABEL_22;
      }
      if ( !*(_QWORD *)v16 )
      {
LABEL_22:
        printk(&unk_221DCE, "sde_cesta_sw_client_update");
        v12 = -22;
        goto LABEL_20;
      }
      v17 = qcom_clk_crmb_set_rate();
      if ( !v17 )
      {
        *(_QWORD *)(v5 + 1096) = *(_QWORD *)(a2 + 16);
        v12 = 0;
        *(_QWORD *)(v5 + 1104) = *(_QWORD *)(a2 + 24);
        goto LABEL_20;
      }
      v18 = v17;
      v19 = &unk_213964;
LABEL_26:
      v12 = v18;
      printk(v19, "sde_cesta_sw_client_update");
      goto LABEL_20;
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
