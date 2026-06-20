__int64 __fastcall sde_cesta_resource_disable(int a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  unsigned int v4; // w0
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int v7; // w19
  void *v8; // x0
  int v9; // w2
  __int64 v10; // x0
  unsigned int v11; // w0
  unsigned int v12; // w0
  _QWORD *v13; // x19
  __int64 (__fastcall *v14)(_QWORD); // x8
  int v15; // w0
  __int64 (__fastcall *v16)(_QWORD); // x8
  int v17; // w0
  __int64 (__fastcall *v18)(_QWORD); // x8
  int v19; // w0
  __int64 (__fastcall *v20)(_QWORD); // x8
  int v21; // w0
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w0
  __int64 (__fastcall *v24)(_QWORD); // x8
  int v25; // w0
  __int64 (__fastcall *v26)(_QWORD); // x8
  int v27; // w0
  __int64 (__fastcall *v28)(_QWORD); // x8
  int v29; // w0
  __int64 (__fastcall *v30)(_QWORD); // x8
  int v31; // w0
  __int64 (__fastcall *v32)(_QWORD); // x8
  int v33; // w0
  int v34; // w6
  int v35; // w5
  unsigned int v36; // w24
  char v37; // w23
  __int64 v38; // x8
  _QWORD *i; // x25
  _DWORD *v40; // x8
  __int64 v41; // x1
  __int64 (__fastcall *v42)(_QWORD); // x8
  int v43; // w0
  __int64 (__fastcall *v44)(_QWORD); // x8
  int v45; // w20
  int v46; // w0
  int v47; // w7
  int v48; // w20
  char v49; // [xsp+0h] [xbp-50h]
  char v50; // [xsp+0h] [xbp-50h]
  _QWORD v51[4]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v52; // [xsp+30h] [xbp-20h]
  __int64 v53; // [xsp+38h] [xbp-18h] BYREF
  __int64 v54; // [xsp+40h] [xbp-10h]
  __int64 v55; // [xsp+48h] [xbp-8h]

  result = 0;
  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  memset(v51, 0, sizeof(v51));
  if ( !a1 )
  {
    v3 = cesta_list_0;
    if ( cesta_list_0 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_cesta_resource_disable",
        878,
        -1,
        0,
        *(unsigned __int8 *)(cesta_list_0 + 920),
        4369,
        *(_DWORD *)(cesta_list_0 + 488),
        239);
      v4 = sde_power_enable_power_domain(v3 + 16, 1u, 0);
      if ( v4 )
      {
        v7 = v4;
        v8 = &unk_26DD37;
        goto LABEL_52;
      }
      if ( *(_BYTE *)(v3 + 920) == 1 )
      {
        v5 = *(_QWORD *)(v3 + 528);
        LODWORD(v52) = 0;
        if ( v5 )
        {
          v6 = regulator_set_mode(v5, 1);
          if ( v6 )
          {
            v7 = v6;
            v8 = &unk_23643D;
LABEL_52:
            printk(v8, "sde_cesta_resource_disable");
            result = v7;
            goto LABEL_75;
          }
        }
        else
        {
          v10 = *(_QWORD *)(v3 + 536);
          if ( v10 )
          {
            _pm_runtime_idle(v10, 4);
          }
          else if ( *(_DWORD *)(v3 + 488) >= 2u )
          {
            v11 = sde_power_enable_power_domain(v3 + 16, 0, 0);
            if ( v11 )
            {
              v7 = v11;
              v8 = &unk_26DD81;
              goto LABEL_52;
            }
          }
        }
        v9 = 6;
        *(_BYTE *)(v3 + 920) = 0;
      }
      else
      {
        v9 = 2;
      }
      v12 = sde_cesta_sw_client_update(0, (__int64)v51, v9);
      if ( v12 )
      {
        v7 = v12;
        v8 = &unk_27EBCB;
        goto LABEL_52;
      }
      sde_power_mmrm_reserve(v3 + 16);
      msm_dss_enable_clk(*(_QWORD *)(v3 + 56), *(_DWORD *)(v3 + 48), 0);
      v13 = (_QWORD *)cesta_list_0;
      v14 = *(__int64 (__fastcall **)(_QWORD))(cesta_list_0 + 912);
      if ( !v14 )
      {
LABEL_74:
        usleep_range_state(500, 510, 2);
        result = 0;
        goto LABEL_75;
      }
      if ( *((_DWORD *)v14 - 1) != 722369561 )
        __break(0x8228u);
      v15 = v14(v13);
      if ( (v15 & 0x1000) != 0 )
      {
        v34 = v15;
        v35 = 0;
      }
      else
      {
        _const_udelay(214750);
        v16 = (__int64 (__fastcall *)(_QWORD))v13[114];
        if ( *((_DWORD *)v16 - 1) != 722369561 )
          __break(0x8228u);
        v17 = v16(v13);
        if ( (v17 & 0x1000) != 0 )
        {
          v34 = v17;
          v35 = 1;
        }
        else
        {
          _const_udelay(214750);
          v18 = (__int64 (__fastcall *)(_QWORD))v13[114];
          if ( *((_DWORD *)v18 - 1) != 722369561 )
            __break(0x8228u);
          v19 = v18(v13);
          if ( (v19 & 0x1000) != 0 )
          {
            v34 = v19;
            v35 = 2;
          }
          else
          {
            _const_udelay(214750);
            v20 = (__int64 (__fastcall *)(_QWORD))v13[114];
            if ( *((_DWORD *)v20 - 1) != 722369561 )
              __break(0x8228u);
            v21 = v20(v13);
            if ( (v21 & 0x1000) != 0 )
            {
              v34 = v21;
              v35 = 3;
            }
            else
            {
              _const_udelay(214750);
              v22 = (__int64 (__fastcall *)(_QWORD))v13[114];
              if ( *((_DWORD *)v22 - 1) != 722369561 )
                __break(0x8228u);
              v23 = v22(v13);
              if ( (v23 & 0x1000) != 0 )
              {
                v34 = v23;
                v35 = 4;
              }
              else
              {
                _const_udelay(214750);
                v24 = (__int64 (__fastcall *)(_QWORD))v13[114];
                if ( *((_DWORD *)v24 - 1) != 722369561 )
                  __break(0x8228u);
                v25 = v24(v13);
                if ( (v25 & 0x1000) != 0 )
                {
                  v34 = v25;
                  v35 = 5;
                }
                else
                {
                  _const_udelay(214750);
                  v26 = (__int64 (__fastcall *)(_QWORD))v13[114];
                  if ( *((_DWORD *)v26 - 1) != 722369561 )
                    __break(0x8228u);
                  v27 = v26(v13);
                  if ( (v27 & 0x1000) != 0 )
                  {
                    v34 = v27;
                    v35 = 6;
                  }
                  else
                  {
                    _const_udelay(214750);
                    v28 = (__int64 (__fastcall *)(_QWORD))v13[114];
                    if ( *((_DWORD *)v28 - 1) != 722369561 )
                      __break(0x8228u);
                    v29 = v28(v13);
                    if ( (v29 & 0x1000) != 0 )
                    {
                      v34 = v29;
                      v35 = 7;
                    }
                    else
                    {
                      _const_udelay(214750);
                      v30 = (__int64 (__fastcall *)(_QWORD))v13[114];
                      if ( *((_DWORD *)v30 - 1) != 722369561 )
                        __break(0x8228u);
                      v31 = v30(v13);
                      if ( (v31 & 0x1000) != 0 )
                      {
                        v34 = v31;
                        v35 = 8;
                      }
                      else
                      {
                        _const_udelay(214750);
                        v32 = (__int64 (__fastcall *)(_QWORD))v13[114];
                        if ( *((_DWORD *)v32 - 1) != 722369561 )
                          __break(0x8228u);
                        v33 = v32(v13);
                        v34 = v33;
                        if ( (v33 & 0x1000) == 0 )
                        {
                          v48 = v33;
                          _const_udelay(214750);
                          printk(&unk_2636C4, "_sde_cesta_check_mode2_entry_status");
                          sde_evtlog_log(
                            sde_dbg_base_evtlog,
                            "_sde_cesta_check_mode2_entry_status",
                            146,
                            -1,
                            0,
                            10,
                            v48,
                            60333,
                            239);
                          v37 = 0;
                          v36 = -16;
                          goto LABEL_61;
                        }
                        v35 = 9;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      sde_evtlog_log(sde_dbg_base_evtlog, "_sde_cesta_check_mode2_entry_status", 151, -1, 0, v35, v34, -1059143953, v49);
      v36 = 0;
      v37 = 1;
LABEL_61:
      v38 = v13[109];
      v53 = 0;
      v54 = 0;
      if ( v38 && v13[110] && v13[114] )
      {
        mutex_lock(v13 + 100);
        for ( i = (_QWORD *)v13[98]; i != v13 + 98; i = (_QWORD *)*i )
        {
          v40 = (_DWORD *)v13[109];
          v41 = *((unsigned int *)i - 26);
          if ( *(v40 - 1) != -1476338332 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, __int64, __int64 *))v40)(v13, v41, &v53);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_cesta_log_status",
            114,
            -1,
            *((_DWORD *)i - 26),
            v53,
            SHIDWORD(v53),
            v54,
            SBYTE4(v54));
        }
        mutex_unlock(v13 + 100);
        v42 = (__int64 (__fastcall *)(_QWORD))v13[110];
        if ( *((_DWORD *)v42 - 1) != 722369561 )
          __break(0x8228u);
        v43 = v42(v13);
        v44 = (__int64 (__fastcall *)(_QWORD))v13[114];
        v45 = v43;
        if ( *((_DWORD *)v44 - 1) != 722369561 )
          __break(0x8228u);
        v46 = v44(v13);
        sde_evtlog_log(sde_dbg_base_evtlog, "_sde_cesta_log_status", 122, -1, v45, v46, -1059143953, v47, v50);
      }
      if ( (v37 & 1) == 0 )
      {
        printk(&unk_266B45, "sde_cesta_resource_disable");
        result = v36;
        goto LABEL_75;
      }
      goto LABEL_74;
    }
  }
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
