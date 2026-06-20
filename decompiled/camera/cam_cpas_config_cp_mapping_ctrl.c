__int64 __fastcall cam_cpas_config_cp_mapping_ctrl(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x22
  unsigned int client_env_object; // w0
  __int64 v6; // x6
  const char *v7; // x5
  __int64 v8; // x4
  unsigned int v9; // w20
  const char *v10; // x5
  __int64 v11; // x4
  __int64 result; // x0
  unsigned int v13; // w0
  __int64 v14; // x0
  __int64 (__fastcall *v15)(__int64, _QWORD, int **, __int64); // x9
  unsigned int v16; // w0
  __int64 v17; // x6
  const char *v18; // x5
  __int64 v19; // x4
  int v20; // w21
  unsigned int v21; // w0
  const char *v22; // x5
  __int64 v23; // x4
  __int64 v24; // x20
  __int64 (__fastcall *v25)(__int64, __int64, int **, __int64); // x23
  int v26; // w9
  int v27; // w10
  int v28; // w0
  const char *v29; // x5
  __int64 v30; // x4
  __int64 v31; // x0
  void (__fastcall *v32)(__int64, __int64, _QWORD, _QWORD); // x8
  int v33; // w0
  unsigned int v34; // w0
  __int64 v35; // x0
  __int64 (__fastcall *v36)(__int64, __int64, _QWORD, _QWORD); // x8
  unsigned int v37; // w0
  unsigned int v38; // w0
  __int64 (__fastcall *v39)(__int64, _QWORD, int **, __int64); // [xsp+8h] [xbp-158h] BYREF
  __int64 v40; // [xsp+10h] [xbp-150h]
  int v41; // [xsp+1Ch] [xbp-144h] BYREF
  _DWORD s[70]; // [xsp+20h] [xbp-140h] BYREF
  int *v43; // [xsp+138h] [xbp-28h] BYREF
  __int64 v44; // [xsp+140h] [xbp-20h]
  __int64 (__fastcall *v45)(__int64, __int64, int **, __int64); // [xsp+148h] [xbp-18h]
  __int64 v46; // [xsp+150h] [xbp-10h]
  __int64 v47; // [xsp+158h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = nullptr;
  v40 = 0;
  memset(s, 0, sizeof(s));
  if ( a1 )
  {
    if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
    {
      v2 = *(_QWORD *)(g_cpas_intf + 480);
      v3 = *(_QWORD *)(v2 + 112);
      if ( v3 )
      {
        v4 = *(_QWORD *)(v3 + 3680);
        mutex_lock(*(_QWORD *)(v2 + 112));
        if ( !*(_DWORD *)(v4 + 2792) )
        {
          v13 = cam_cpas_util_vote_default_ahb_axi(v3, 1);
          if ( v13 )
          {
            v9 = v13;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_config_cp_mapping_ctrl",
              1546,
              "failed to vote for the default ahb/axi clock, rc=%d",
              v13);
            goto LABEL_39;
          }
          v21 = cam_cpas_soc_enable_resources(v3 + 96);
          if ( v21 )
          {
            v22 = "failed in soc_enable_resources, rc=%d";
            v23 = 1553;
            v9 = v21;
            goto LABEL_24;
          }
        }
        client_env_object = get_client_env_object(&v39);
        if ( client_env_object )
        {
          v6 = client_env_object;
          v7 = "Failed getting mink env object, rc: %d";
          v8 = 1560;
LABEL_8:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_config_cp_mapping_ctrl",
            v8,
            v7,
            v6);
          v9 = -22;
          if ( *(_DWORD *)(v4 + 2792) )
            goto LABEL_39;
          goto LABEL_37;
        }
        v15 = v39;
        v14 = v40;
        v41 = 283;
        v45 = nullptr;
        v46 = 0;
        v43 = &v41;
        v44 = 4;
        if ( *((_DWORD *)v39 - 1) != 816020464 )
          __break(0x8229u);
        v16 = v15(v14, 0, &v43, 4097);
        if ( v16 )
        {
          v17 = v16;
          v18 = "Failed getting mink sc_object, rc: %d";
          v19 = 1567;
LABEL_21:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_config_cp_mapping_ctrl",
            v19,
            v18,
            v17);
          v20 = -22;
          goto LABEL_34;
        }
        v25 = v45;
        v24 = v46;
        if ( *(_DWORD *)a1 == 3 )
        {
          v26 = *(_DWORD *)(a1 + 4);
          v27 = *(unsigned __int8 *)(a1 + 8);
          s[0] = 2;
          s[1] = v26;
          s[2] = v27;
          v28 = ((__int64 (__fastcall *)(__int64, _DWORD *))cam_cpas_get_scm_port_info)(a1, s);
          if ( !v28 )
          {
            v43 = s;
            v44 = 280;
            if ( *((_DWORD *)v25 - 1) != 816020464 )
              __break(0x8237u);
            v33 = v25(v24, 4, &v43, 1);
            if ( !v33 )
            {
              if ( *((_DWORD *)v25 - 1) != 816020464 )
                __break(0x8237u);
              v34 = v25(v24, 0xFFFF, nullptr, 0);
              if ( !v34 )
              {
                v36 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v39;
                v35 = v40;
                if ( *((_DWORD *)v39 - 1) != 816020464 )
                  __break(0x8228u);
                v37 = v36(v35, 0xFFFF, 0, 0);
                if ( !v37 )
                {
                  if ( *(_DWORD *)(v4 + 2792) )
                  {
                    v9 = 0;
                    goto LABEL_39;
                  }
                  v38 = cam_cpas_soc_disable_resources(v3 + 96, 1u, 1u);
                  if ( !v38 )
                  {
                    v9 = cam_cpas_util_vote_default_ahb_axi(v3, 0);
                    if ( v9 )
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        4,
                        1,
                        "cam_cpas_config_cp_mapping_ctrl",
                        1628,
                        "failed remove the vote on ahb/axi clock, rc=%d",
                        v9);
                    goto LABEL_39;
                  }
                  v9 = v38;
                  v22 = "failed in soc_disable_resources, rc=%d";
                  v23 = 1621;
LABEL_24:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    4,
                    1,
                    "cam_cpas_config_cp_mapping_ctrl",
                    v23,
                    v22);
                  if ( !*(_DWORD *)(v4 + 2792) )
                    goto LABEL_38;
                  goto LABEL_39;
                }
                v6 = v37;
                v7 = "Failed releasing mink env object, rc: %d";
                v8 = 1613;
                goto LABEL_8;
              }
              v17 = v34;
              v18 = "Failed releasing secure camera object, rc: %d";
              v19 = 1606;
              goto LABEL_21;
            }
            if ( v33 == 10 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                4,
                1,
                "cam_cpas_config_cp_mapping_ctrl",
                1595,
                "Dynamic port config not allowed",
                10);
              v20 = -1;
            }
            else
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                4,
                1,
                "cam_cpas_config_cp_mapping_ctrl",
                1598,
                "Dynamic port config failed, rc: %d",
                v33);
              v20 = -22;
            }
LABEL_31:
            if ( *((_DWORD *)v25 - 1) != 816020464 )
              __break(0x8237u);
            v25(v24, 0xFFFF, nullptr, 0);
LABEL_34:
            v32 = (void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v39;
            v31 = v40;
            if ( *((_DWORD *)v39 - 1) != 816020464 )
              __break(0x8228u);
            v32(v31, 0xFFFF, 0, 0);
            v9 = v20;
            if ( *(_DWORD *)(v4 + 2792) )
              goto LABEL_39;
LABEL_37:
            cam_cpas_soc_disable_resources(v3 + 96, 1u, 1u);
            if ( !*(_DWORD *)(v4 + 2792) )
LABEL_38:
              cam_cpas_util_vote_default_ahb_axi(v3, 0);
LABEL_39:
            mutex_unlock(v3);
            result = v9;
            goto LABEL_13;
          }
          v29 = "Failed to get SCM port info, rc: %d";
          v30 = 1587;
          v20 = v28;
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_scm_device_type",
            1475,
            "unsupported dev type %d for DCP SCM call",
            *(_DWORD *)a1);
          v29 = "Failed to get SCM device type, rc: %d";
          v30 = 1574;
          v20 = -22;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_config_cp_mapping_ctrl",
          v30,
          v29);
        goto LABEL_31;
      }
      v10 = "cpas_hw handle not initialized";
      v11 = 1534;
    }
    else
    {
      v10 = "cpas intf not initialized";
      v11 = 1528;
    }
  }
  else
  {
    v10 = "Invalid CP mapping config";
    v11 = 1523;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_config_cp_mapping_ctrl",
    v11,
    v10);
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
