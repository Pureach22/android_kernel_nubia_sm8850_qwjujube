__int64 __fastcall cam_cpas_util_apply_client_ahb_vote(__int64 a1, __int64 a2, _DWORD *a3, unsigned int *a4)
{
  __int64 v4; // x22
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x20
  __int64 v9; // x24
  __int64 v10; // x23
  unsigned __int64 freq_ceil; // x0
  unsigned __int64 v12; // x7
  unsigned int v13; // w20
  __int64 v14; // x6
  const char *v15; // x5
  __int64 v16; // x1
  __int64 v17; // x4
  __int64 result; // x0
  __int64 v19; // x21
  __int64 v20; // x23
  __int64 voltage; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  unsigned int v24; // w21
  __int64 v25; // x9
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x9
  int v29; // w8
  unsigned int *v30; // x10
  unsigned int v31; // w0
  unsigned int v32; // w0
  int v33; // [xsp+0h] [xbp-30h]
  unsigned int v34; // [xsp+8h] [xbp-28h]
  int v35; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v36[2]; // [xsp+20h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 3680);
  v35 = 0;
  if ( (*(_BYTE *)(v4 + 2856) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_apply_client_ahb_vote",
      2648,
      "AHB Bus client not valid");
    result = 4294967274LL;
LABEL_45:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *a3 == 1 )
  {
    v6 = *(_QWORD *)(a2 + 136);
    v7 = *((_QWORD *)a3 + 1);
    v8 = *(_QWORD *)(a1 + 3392);
    v36[0] = v7;
    if ( !v6 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_get_ahb_level",
        2610,
        "Invalid params %pK, %pK",
        nullptr,
        &v35);
      result = 4294967274LL;
      goto LABEL_45;
    }
    v9 = a2;
    v10 = a1;
    freq_ceil = dev_pm_opp_find_freq_ceil(v6, v36);
    v12 = freq_ceil;
    if ( freq_ceil < 0xFFFFFFFFFFFFF001LL )
    {
      voltage = dev_pm_opp_get_voltage(freq_ceil);
      v28 = *(unsigned int *)(v8 + 904);
      v29 = voltage;
      if ( (_DWORD)v28 )
      {
        if ( (unsigned int)(v28 - 17) < 0xFFFFFFF0 )
          goto LABEL_51;
        a1 = v10;
        a2 = v9;
        v30 = (unsigned int *)(v8 + 912);
        v13 = 2;
        do
        {
          if ( *(v30 - 1) == v29 )
            v13 = *v30;
          --v28;
          v30 += 2;
        }
        while ( v28 );
      }
      else
      {
        v13 = 2;
        a1 = v10;
        a2 = v9;
      }
      if ( (debug_mdl & 4) != 0 && !debug_priority )
      {
        v12 = v36[0];
        v15 = "From OPP table : freq=[%ld][%ld], corner=%d, level=%d";
        v16 = debug_mdl & 4;
        v17 = 2630;
        v14 = v7;
        v34 = v13;
        v33 = v29;
        goto LABEL_50;
      }
    }
    else
    {
      v13 = 9;
      if ( (debug_mdl & 4) != 0 )
      {
        a1 = v10;
        a2 = v9;
        if ( !debug_priority )
        {
          v14 = v36[0];
          v15 = "OPP Ceil not available for freq :%ld, %pK";
          v16 = debug_mdl & 4;
          v17 = 2617;
LABEL_50:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, int, unsigned int))cam_print_log)(
            3,
            v16,
            4,
            "cam_cpas_util_get_ahb_level",
            v17,
            v15,
            v14,
            v12,
            v33,
            v34);
          a2 = v9;
          a1 = v10;
        }
      }
      else
      {
        a1 = v10;
        a2 = v9;
      }
    }
  }
  else
  {
    v13 = a3[2];
  }
  if ( *(_DWORD *)(a2 + 172) == v13 )
  {
    result = 0;
    goto LABEL_45;
  }
  v19 = a1;
  v20 = a2;
  voltage = mutex_lock(v4 + 2864);
  *(_DWORD *)(v20 + 172) = v13;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    voltage = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 4,
                4,
                "cam_cpas_util_apply_client_ahb_vote",
                2669,
                "Client[%s] required level[%d], curr_level[%d]",
                *(const char **)(v4 + 2920),
                v13,
                *(_DWORD *)(v4 + 2912));
  if ( v13 == *(_DWORD *)(v4 + 2912) )
  {
    v24 = 0;
LABEL_44:
    mutex_unlock(v4 + 2864);
    result = v24;
    goto LABEL_45;
  }
  v25 = *(unsigned int *)(v4 + 2776);
  if ( !(_DWORD)v25 )
  {
    v26 = v19;
LABEL_33:
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_util_apply_client_ahb_vote",
        2681,
        "Required highest_level[%d]",
        v13);
      v26 = v19;
    }
    if ( (*(_BYTE *)(v4 + 8144) & 1) != 0
      || (v31 = cam_cpas_util_vote_bus_client_level(v4 + 2856, v13), v26 = v19, !v31) )
    {
      if ( *(_DWORD *)(v4 + 2792)
        && (v32 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, __int64))cam_soc_util_set_clk_rate_level)(
                    v26 + 96,
                    0xFFFFFFFFLL,
                    v13,
                    0,
                    1)) != 0 )
      {
        v24 = v32;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_apply_client_ahb_vote",
          2699,
          "Failed in scaling clock rate level %d for AHB",
          v13);
      }
      else
      {
        v24 = 0;
        if ( a4 )
          *a4 = v13;
      }
    }
    else
    {
      v24 = v31;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_apply_client_ahb_vote",
        2688,
        "Failed in ahb vote, level=%d, rc=%d",
        v13);
    }
    goto LABEL_44;
  }
  if ( (unsigned int)(v25 - 44) >= 0xFFFFFFD5 )
  {
    v26 = v19;
    v27 = v4 + 320;
    do
    {
      if ( *(_QWORD *)v27 && v13 <= *(_DWORD *)(*(_QWORD *)v27 + 172LL) )
        v13 = *(_DWORD *)(*(_QWORD *)v27 + 172LL);
      --v25;
      v27 += 8;
    }
    while ( v25 );
    goto LABEL_33;
  }
LABEL_51:
  __break(0x5512u);
  return cam_cpas_util_create_vote_all_paths(voltage, v22, v23);
}
