__int64 __fastcall sde_power_resource_enable(__int64 a1, char a2)
{
  int v4; // w7
  _QWORD *v5; // x24
  _QWORD *v6; // x22
  __int64 v7; // x22
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  int v17; // w7
  unsigned int v18; // w0
  int v19; // w7
  _QWORD *v20; // x22
  __int64 v21; // x1
  void (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x1
  void (__fastcall *v24)(__int64, __int64); // x8
  _QWORD *v25; // x22
  _QWORD *v26; // x22
  __int64 v28; // x1
  void (__fastcall *v29)(__int64, __int64); // x8
  __int64 v30; // x1
  void (__fastcall *v31)(__int64, __int64); // x8
  unsigned int v32; // w21
  unsigned __int64 v33; // x23
  __int64 v34; // x0
  unsigned __int64 v35; // x24
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x8
  char v39; // [xsp+0h] [xbp+0h]
  char v40; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    printk(&unk_235FA2, "sde_power_resource_enable");
    return 4294967274LL;
  }
  mutex_lock(a1 + 48);
  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(a1 + 376) & 1) == 0 )
  {
    *(_QWORD *)(a1 + 368) = 0;
    *(_BYTE *)(a1 + 376) = 1;
  }
  v5 = (_QWORD *)(a1 + 344);
  if ( (a2 & 1) == 0 )
  {
    v25 = *(_QWORD **)(a1 + 344);
    for ( *(_DWORD *)(a1 + 360) = 1; v25 != v5; v25 = (_QWORD *)*v25 )
    {
      if ( (*(_BYTE *)(v25 - 1) & 1) != 0 )
      {
        v29 = (void (__fastcall *)(__int64, __int64))*(v25 - 3);
        v28 = *(v25 - 2);
        if ( *((_DWORD *)v29 - 1) != 1916394597 )
          __break(0x8228u);
        v29(1, v28);
      }
    }
    if ( *(_BYTE *)(a1 + 416) == 1 && (unsigned int)synx_enable_resources(1216, 1, 0) )
      printk(&unk_23CCB8, "sde_power_resource_enable");
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_power_resource_enable", 1201, 4, 0, 17476, -1059143953, v4, v39);
    sde_power_mmrm_reserve(a1);
    msm_dss_enable_clk(*(_QWORD *)(a1 + 40), *(_DWORD *)(a1 + 32), 0);
    sde_power_scale_reg_bus(a1, 0, 1);
    if ( (*(_BYTE *)(a1 + 378) & 1) == 0 )
      sde_power_enable_power_domain(a1, 1u, 0);
    sde_cesta_resource_disable(0);
    sde_power_enable_power_domain(a1, 0, 0);
    msm_dss_enable_vreg(*(_QWORD **)(a1 + 8), *(_DWORD *)a1, 0);
    if ( *(_DWORD *)(a1 + 336) )
      sde_power_data_bus_set_quota(a1 + 304, 0, 0);
    if ( *(_DWORD *)(a1 + 296) )
      sde_power_data_bus_set_quota(a1 + 264, 0, 0);
    if ( *(_DWORD *)(a1 + 256) )
      sde_power_data_bus_set_quota(a1 + 224, 0, 0);
    if ( *(_DWORD *)(a1 + 216) )
      sde_power_data_bus_set_quota(a1 + 184, 0, 0);
    v26 = *(_QWORD **)(a1 + 344);
    for ( *(_DWORD *)(a1 + 360) = 2; v26 != v5; v26 = (_QWORD *)*v26 )
    {
      if ( (*(_BYTE *)(v26 - 1) & 2) != 0 )
      {
        v31 = (void (__fastcall *)(__int64, __int64))*(v26 - 3);
        v30 = *(v26 - 2);
        if ( *((_DWORD *)v31 - 1) != 1916394597 )
          __break(0x8228u);
        v31(2, v30);
      }
    }
    goto LABEL_51;
  }
  v6 = *(_QWORD **)(a1 + 344);
  for ( *(_DWORD *)(a1 + 360) = 4; v6 != v5; v6 = (_QWORD *)*v6 )
  {
    if ( (*(_BYTE *)(v6 - 1) & 4) != 0 )
    {
      v22 = (void (__fastcall *)(__int64, __int64))*(v6 - 3);
      v21 = *(v6 - 2);
      if ( *((_DWORD *)v22 - 1) != 1916394597 )
        __break(0x8228u);
      v22(4, v21);
    }
  }
  v7 = a1 + 184;
  if ( !*(_DWORD *)(a1 + 216) || (v8 = sde_power_data_bus_set_quota(a1 + 184, 0, *(_QWORD *)(a1 + 384))) == 0 )
  {
    if ( *(_DWORD *)(a1 + 256) && (v9 = sde_power_data_bus_set_quota(a1 + 224, 0, *(_QWORD *)(a1 + 392))) != 0 )
    {
      v32 = v9;
      LODWORD(v33) = 1;
    }
    else if ( *(_DWORD *)(a1 + 296) && (v10 = sde_power_data_bus_set_quota(a1 + 264, 0, *(_QWORD *)(a1 + 400))) != 0 )
    {
      v32 = v10;
      LODWORD(v33) = 2;
    }
    else
    {
      if ( !*(_DWORD *)(a1 + 336) || (v11 = sde_power_data_bus_set_quota(a1 + 304, 0, *(_QWORD *)(a1 + 408))) == 0 )
      {
        v12 = msm_dss_enable_vreg(*(_QWORD **)(a1 + 8), *(_DWORD *)a1, 1);
        if ( v12 )
        {
          v32 = v12;
          printk(&unk_26D9F6, "sde_power_resource_enable");
          v33 = 4;
LABEL_77:
          v34 = v7 + 40LL * ((int)v33 - 1);
          if ( *(_DWORD *)(v34 + 32) )
          {
            sde_power_data_bus_set_quota(v34, 0, 0);
            v35 = v33 - 2;
            if ( v33 >= 2 )
            {
              v36 = v7 + 40LL * (int)v35;
              if ( *(_DWORD *)(v36 + 32) )
              {
                sde_power_data_bus_set_quota(v36, 0, 0);
                if ( v33 - 1 >= 2 )
                {
                  v37 = v7 + 40LL * (unsigned int)v33;
                  if ( *(_DWORD *)(v37 - 88) )
                  {
                    sde_power_data_bus_set_quota(v37 - 120, 0, 0);
                    if ( v35 >= 2 )
                    {
                      v38 = v7 + 40LL * (unsigned int)v33;
                      if ( *(_DWORD *)(v38 - 128) )
                        sde_power_data_bus_set_quota(v38 - 160, 0, 0);
                    }
                  }
                }
              }
            }
          }
          goto LABEL_85;
        }
        v13 = sde_power_enable_power_domain(a1, 0, 1);
        if ( v13 )
        {
          v32 = v13;
          printk(&unk_25BCF7, "sde_power_resource_enable");
LABEL_71:
          sde_power_enable_power_domain(a1, 0, 0);
          v33 = 4;
          goto LABEL_77;
        }
        v14 = sde_cesta_resource_enable();
        if ( v14 )
        {
          v32 = v14;
          printk(&unk_266709, "sde_power_resource_enable");
        }
        else
        {
          if ( (*(_BYTE *)(a1 + 378) & 1) == 0 && (v15 = sde_power_enable_power_domain(a1, 1u, 1)) != 0 )
          {
            v32 = v15;
            printk(&unk_26DA23, "sde_power_resource_enable");
            if ( (*(_BYTE *)(a1 + 378) & 1) != 0 )
              goto LABEL_70;
          }
          else
          {
            v16 = sde_power_scale_reg_bus(a1, 1u, 1);
            if ( v16 )
            {
              v32 = v16;
              printk(&unk_274A61, "sde_power_resource_enable");
            }
            else
            {
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_power_resource_enable", 1162, 4, 1, 13107, -1059143953, v17, v39);
              v18 = msm_dss_enable_clk(*(_QWORD *)(a1 + 40), *(_DWORD *)(a1 + 32), 1);
              if ( !v18 )
              {
                if ( *(_BYTE *)(a1 + 416) == 1 && (unsigned int)synx_enable_resources(1216, 1, 1) )
                {
                  printk(&unk_23CCB8, "sde_power_resource_enable");
                  *(_BYTE *)(a1 + 416) = 0;
                }
                v20 = *(_QWORD **)(a1 + 344);
                for ( *(_DWORD *)(a1 + 360) = 8; v20 != v5; v20 = (_QWORD *)*v20 )
                {
                  if ( (*(_BYTE *)(v20 - 1) & 8) != 0 )
                  {
                    v24 = (void (__fastcall *)(__int64, __int64))*(v20 - 3);
                    v23 = *(v20 - 2);
                    if ( *((_DWORD *)v24 - 1) != 1916394597 )
                      __break(0x8228u);
                    v24(8, v23);
                  }
                }
LABEL_51:
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "sde_power_resource_enable",
                  1230,
                  4,
                  a2 & 1,
                  8738,
                  -1059143953,
                  v19,
                  v40);
                mutex_unlock(a1 + 48);
                return 0;
              }
              v32 = v18;
              printk(&unk_269DC3, "sde_power_resource_enable");
              sde_power_scale_reg_bus(a1, 0, 1);
            }
            sde_cesta_resource_disable(0);
            if ( (*(_BYTE *)(a1 + 378) & 1) != 0 )
              goto LABEL_70;
          }
          sde_power_enable_power_domain(a1, 1u, 0);
        }
LABEL_70:
        msm_dss_enable_vreg(*(_QWORD **)(a1 + 8), *(_DWORD *)a1, 0);
        goto LABEL_71;
      }
      v32 = v11;
      LODWORD(v33) = 3;
    }
    printk(&unk_250E69, "sde_power_resource_enable");
    v33 = (unsigned int)v33;
    goto LABEL_77;
  }
  v32 = v8;
  printk(&unk_250E69, "sde_power_resource_enable");
LABEL_85:
  mutex_unlock(a1 + 48);
  return v32;
}
