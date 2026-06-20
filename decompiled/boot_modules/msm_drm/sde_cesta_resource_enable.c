__int64 __fastcall sde_cesta_resource_enable(int a1)
{
  __int64 result; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  unsigned int v5; // w0
  __int64 v6; // x8
  unsigned int v7; // w19
  void *v8; // x0
  _QWORD v9[4]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  result = 0;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[3] = 0;
  v10 = 0;
  v9[2] = 0;
  if ( !a1 )
  {
    v3 = cesta_list_0;
    if ( cesta_list_0 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_cesta_resource_enable",
        960,
        -1,
        0,
        *(unsigned __int8 *)(cesta_list_0 + 920),
        *(_DWORD *)(cesta_list_0 + 488),
        -1059143953,
        v9[0]);
      v4 = msm_dss_enable_clk(*(_QWORD *)(v3 + 56), *(_DWORD *)(v3 + 48), 1);
      if ( v4 )
      {
        v7 = v4;
        v8 = &unk_27EC11;
        goto LABEL_11;
      }
      v5 = sde_power_enable_power_domain(v3 + 16, 1u, 1);
      if ( v5 )
      {
        v7 = v5;
        v8 = &unk_274D75;
        goto LABEL_11;
      }
      if ( *(_BYTE *)(v3 + 920) == 1 )
      {
        v6 = 1000LL * *(_QWORD *)(v3 + 1136);
        LODWORD(v10) = 4;
        v9[0] = 0;
        v9[1] = v6;
        v7 = sde_cesta_sw_client_update(0, (__int64)v9, 6);
        result = 0;
        if ( v7 )
        {
          v8 = &unk_22BE1D;
LABEL_11:
          printk(v8, "sde_cesta_resource_enable");
          result = v7;
        }
      }
      else
      {
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
