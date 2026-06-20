__int64 __fastcall cam_cpas_util_vote_drv_bus_client_bw(__int64 a1, __int64 a2, __int64 a3, __int64 *a4, _QWORD *a5)
{
  __int64 *v8; // x26
  __int64 *settings; // x0
  __int64 v10; // x27
  __int64 *v11; // x28
  __int64 v12; // x24
  __int64 v13; // x25
  size_t v14; // x22
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 *v19; // x0
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x6
  unsigned __int64 v22; // x7
  int v23; // w9
  unsigned int updated; // w0
  unsigned int v25; // w21
  __int64 v26; // x0
  __int64 v27; // x7
  __int64 v28; // x8
  __int64 v29; // x6
  __int64 v30; // x4
  unsigned int v32; // w0
  __int64 v33; // x0
  __int64 v34; // x9
  __int64 v35; // x11
  __int64 v36; // x9
  __int64 v37; // x11
  __int64 v38; // x12
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x8
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // [xsp+38h] [xbp-18h]

  if ( (*(_BYTE *)a3 & 1) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_vote_drv_bus_client_bw",
      308,
      "bus client: %s not valid",
      *(const char **)(a3 + 64));
    return 4294967274LL;
  }
  mutex_lock(a3 + 8);
  if ( (unsigned __int64)(a4[1] - 1) <= 0x1FFFFE )
    a4[1] = 0x200000;
  if ( (unsigned __int64)(a4[2] - 1) <= 0x1FFFFE )
    a4[2] = 0x200000;
  v8 = a4 + 4;
  if ( (unsigned __int64)(a4[4] - 1) <= 0x1FFFFE )
    *v8 = 0x200000;
  if ( (unsigned __int64)(a4[5] - 1) <= 0x1FFFFE )
    a4[5] = 0x200000;
  settings = cam_debug_get_settings();
  v10 = a4[1];
  if ( (v10 || a4[2] || *v8 || a4[5]) && settings && *((_BYTE *)settings + 208) == 1 )
  {
    v11 = settings;
    v12 = a4[4];
    v13 = a4[5];
    v47 = a4[2];
    v14 = strlen(*(const char **)(a3 + 64));
    if ( strnstr(*(_QWORD *)(a3 + 64), "cam_ife_0_drv", v14) )
    {
      v15 = v11[11];
      if ( v15 )
        a4[1] = v15;
      v16 = v11[12];
      if ( v16 )
        a4[2] = v16;
      v17 = v11[17];
      if ( v17 )
        *v8 = v17;
      v18 = v11[18];
      if ( v18 )
        a4[5] = v18;
      if ( !v11[23] )
        goto LABEL_27;
      goto LABEL_26;
    }
    if ( strnstr(*(_QWORD *)(a3 + 64), "cam_ife_1_drv", v14) )
    {
      v39 = v11[13];
      if ( v39 )
        a4[1] = v39;
      v40 = v11[14];
      if ( v40 )
        a4[2] = v40;
      v41 = v11[19];
      if ( v41 )
        *v8 = v41;
      v42 = v11[20];
      if ( v42 )
        a4[5] = v42;
      if ( !v11[24] )
        goto LABEL_27;
      goto LABEL_26;
    }
    if ( strnstr(*(_QWORD *)(a3 + 64), "cam_ife_2_drv", v14) )
    {
      v43 = v11[15];
      if ( v43 )
        a4[1] = v43;
      v44 = v11[16];
      if ( v44 )
        a4[2] = v44;
      v45 = v11[21];
      if ( v45 )
        *v8 = v45;
      v46 = v11[22];
      if ( v46 )
        a4[5] = v46;
      if ( !v11[25] )
        goto LABEL_27;
LABEL_26:
      *v8 = 0;
      a4[5] = 0;
LABEL_27:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        3,
        "cam_cpas_process_drv_bw_overrides",
        103,
        "Overriding mnoc bw for: %s with [AB IB] high: [%llu %llu], low: [%llu %llu], curr high: [%llu %llu], curr low: [%llu %llu]",
        *(const char **)(a3 + 64),
        a4[1],
        a4[2],
        a4[4],
        a4[5],
        v10,
        v47,
        v12,
        v13);
      goto LABEL_28;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_process_drv_bw_overrides",
      96,
      "unknown mnoc port: %s, bw override failed",
      *(const char **)(a3 + 64));
  }
LABEL_28:
  if ( debug_drv )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_util_vote_drv_bus_client_bw",
      343,
      "Bus_client: %s, DRV vote high=[%llu %llu] low=[%llu %llu]",
      *(const char **)(a3 + 64),
      a4[1],
      a4[2],
      a4[4],
      a4[5]);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_util_vote_drv_bus_client_bw",
      348,
      "Bus_client: %s, DRV vote high=[%llu %llu] low=[%llu %llu]",
      *(const char **)(a3 + 64),
      a4[1],
      a4[2],
      a4[4],
      a4[5]);
  v19 = cam_debug_get_settings();
  if ( *(_BYTE *)(a3 + 241) != 1
    || (v20 = *(_QWORD *)(a1 + 1056)) == 0
    || debug_disable_rt_clk_bw_limit
    || v19 && (v19[26] & 1) != 0 )
  {
LABEL_66:
    updated = cam_soc_bus_client_update_bw(*(_QWORD *)(a3 + 232), a4[1], a4[2], 1);
    if ( updated )
    {
      v25 = updated;
      v26 = cam_soc_bus_path_data_to_str(1);
      v27 = a4[1];
      v28 = a4[2];
      v29 = v26;
      v30 = 357;
    }
    else
    {
      v32 = cam_soc_bus_client_update_bw(*(_QWORD *)(a3 + 232), a4[4], a4[5], 2);
      if ( !v32 )
      {
        if ( a5 )
        {
          v34 = a4[2];
          v25 = 0;
          v35 = *a4;
          a5[1] = a4[1];
          a5[2] = v34;
          *a5 = v35;
          v36 = a4[6];
          v37 = a4[3];
          v38 = a4[4];
          a5[5] = a4[5];
          a5[6] = v36;
          a5[3] = v37;
          a5[4] = v38;
        }
        else
        {
          v25 = 0;
        }
        goto LABEL_72;
      }
      v25 = v32;
      v33 = cam_soc_bus_path_data_to_str(2);
      v27 = a4[4];
      v28 = a4[5];
      v29 = v33;
      v30 = 366;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_vote_drv_bus_client_bw",
      v30,
      "Update bw failed, Bus path: %s ab[%llu] ib[%llu]",
      v29,
      v27,
      v28);
LABEL_72:
    mutex_unlock(a3 + 8);
    return v25;
  }
  v21 = a4[1];
  v22 = a4[2];
  v23 = *(_DWORD *)(a2 + 2780);
  if ( !v23 )
  {
LABEL_63:
    if ( v21 > v20 || v22 > v20 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        2,
        "cam_cpas_util_validate_rt_bw",
        295,
        "Requested RT BW[AB IB]: [%llu %llu] exceeds max supported value: %llu curr client: %s",
        v21,
        v22,
        *(_QWORD *)(a1 + 1056),
        *(const char **)(a3 + 64));
    goto LABEL_66;
  }
  if ( (unsigned int)(v23 - 7) >= 0xFFFFFFFA )
  {
    if ( (*(_BYTE *)(a2 + 3345) & 1) != 0 && *(_QWORD *)(a2 + 3336) != *(_QWORD *)(a3 + 232) )
    {
      v21 += *(_QWORD *)(a2 + 3456);
      v22 += *(_QWORD *)(a2 + 3464);
    }
    if ( v23 != 1 )
    {
      if ( *(_BYTE *)(a2 + 3753) == 1 && *(_QWORD *)(a2 + 3744) != *(_QWORD *)(a3 + 232) )
      {
        v21 += *(_QWORD *)(a2 + 3864);
        v22 += *(_QWORD *)(a2 + 3872);
      }
      if ( v23 != 2 )
      {
        if ( *(_BYTE *)(a2 + 4161) == 1 && *(_QWORD *)(a2 + 4152) != *(_QWORD *)(a3 + 232) )
        {
          v21 += *(_QWORD *)(a2 + 4272);
          v22 += *(_QWORD *)(a2 + 4280);
        }
        if ( v23 != 3 )
        {
          if ( *(_BYTE *)(a2 + 4569) == 1 && *(_QWORD *)(a2 + 4560) != *(_QWORD *)(a3 + 232) )
          {
            v21 += *(_QWORD *)(a2 + 4680);
            v22 += *(_QWORD *)(a2 + 4688);
          }
          if ( v23 != 4 )
          {
            if ( *(_BYTE *)(a2 + 4977) == 1 && *(_QWORD *)(a2 + 4968) != *(_QWORD *)(a3 + 232) )
            {
              v21 += *(_QWORD *)(a2 + 5088);
              v22 += *(_QWORD *)(a2 + 5096);
            }
            if ( v23 != 5 && *(_BYTE *)(a2 + 5385) == 1 && *(_QWORD *)(a2 + 5376) != *(_QWORD *)(a3 + 232) )
            {
              v21 += *(_QWORD *)(a2 + 5496);
              v22 += *(_QWORD *)(a2 + 5504);
            }
          }
        }
      }
    }
    goto LABEL_63;
  }
  __break(0x5512u);
  return cam_cpas_print_smart_qos_priority(v19);
}
