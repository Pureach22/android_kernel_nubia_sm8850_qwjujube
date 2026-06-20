__int64 __fastcall sdhci_msm_execute_tuning(__int64 a1, unsigned int a2)
{
  __int64 v4; // x8
  __int64 v5; // x24
  unsigned int v6; // w9
  unsigned int v7; // w21
  unsigned int *v8; // x24
  unsigned int v9; // t1
  int v10; // w0
  unsigned int v11; // w8
  bool v12; // zf
  __int64 result; // x0
  unsigned int v14; // w20
  _QWORD *v15; // x19
  _BYTE *v16; // x25
  int v17; // w0
  unsigned int v18; // t1
  int v19; // w0
  char v20; // w21
  int v21; // w26
  unsigned int v22; // w23
  unsigned int v23; // w22
  unsigned int v24; // w8
  __int64 v25; // x8
  unsigned int most_appropriate_phase; // w20
  __int64 v27; // x0
  _QWORD v28[3]; // [xsp+8h] [xbp-18h] BYREF

  v28[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 1864);
  v5 = *(_QWORD *)(a1 + 3416);
  v28[0] = 0;
  v28[1] = 0;
  v6 = *(unsigned __int8 *)(v4 + 1056);
  v7 = *(_DWORD *)(v4 + 1040);
  if ( v6 == 5 && (*(_BYTE *)(a1 + 2588) & 0x10) != 0 )
  {
    *(_BYTE *)(a1 + 3353) = 0;
    v16 = (_BYTE *)(a1 + 3353);
    *(_BYTE *)(a1 + 3424) = 1;
    v17 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 1816) + *(unsigned int *)(v5 + 68)));
    writel_relaxed(v17 & 0xFFC3FFFF | 0x240000, (unsigned int *)(*(_QWORD *)(a1 + 1816) + *(unsigned int *)(v5 + 68)));
    if ( (*(_BYTE *)(a1 + 2589) & 0x20) == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
  if ( *(_DWORD *)(a1 + 2612) < 0x5F5E101u || v6 > 0xA || ((1 << v6) & 0x640) == 0 || *(_BYTE *)(v4 + 1059) == 1 )
  {
    *(_BYTE *)(a1 + 3424) = 0;
    v9 = *(_DWORD *)(v5 + 60);
    v8 = (unsigned int *)(v5 + 60);
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 1816) + v9));
    v11 = v10 & 0xFFF5FFFF | 0x80000;
    v12 = v11 == v10;
    result = 0;
    if ( !v12 )
    {
      v14 = 0;
      v15 = (_QWORD *)(a1 + 1816);
LABEL_14:
      writel_relaxed(v11, (unsigned int *)(*v15 + *v8));
      result = v14;
      goto LABEL_15;
    }
    goto LABEL_15;
  }
  v16 = (_BYTE *)(a1 + 3353);
  *(_BYTE *)(a1 + 3353) = 0;
  *(_BYTE *)(a1 + 3424) = 1;
  if ( (*(_BYTE *)(a1 + 2589) & 0x20) != 0 )
  {
LABEL_10:
    sdhci_msm_hc_select_mode(a1 + 1792);
    msm_set_clock_rate_for_bus_mode(a1 + 1792, v7);
    *(_DWORD *)(a1 + 2588) &= ~0x2000u;
  }
LABEL_11:
  v18 = *(_DWORD *)(v5 + 68);
  v8 = (unsigned int *)(v5 + 68);
  v19 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 1816) + v18));
  v20 = v19;
  writel_relaxed(v19 & 0xFFFFFFFD, (unsigned int *)(*(_QWORD *)(a1 + 1816) + *v8));
  result = msm_init_cm_dll(a1 + 1792, 0);
  if ( !(_DWORD)result )
  {
    v21 = 10;
LABEL_17:
    v22 = 0;
    v23 = 0;
    while ( 1 )
    {
      result = msm_config_cm_dll_phase(a1 + 1792, v22);
      if ( (_DWORD)result )
        break;
      if ( !(unsigned int)mmc_send_tuning(a1, a2, 0) )
      {
        if ( (unsigned __int8)v23 >= 0x10u )
          __break(0x5512u);
        v25 = (unsigned __int8)v23++;
        *((_BYTE *)v28 + v25) = v22;
      }
      v24 = (unsigned __int8)v22++;
      if ( v24 >= 0xF )
      {
        if ( (_BYTE)v23 )
        {
          if ( (unsigned __int8)v23 != 16 || (--v21, !v21) )
          {
            most_appropriate_phase = msm_find_most_appropriate_phase(a1 + 1792, v28, v23);
            if ( (most_appropriate_phase & 0x80000000) != 0 )
            {
              result = most_appropriate_phase;
            }
            else
            {
              result = msm_config_cm_dll_phase(a1 + 1792, most_appropriate_phase);
              if ( !(_DWORD)result )
              {
                v27 = *(_QWORD *)(a1 + 3952);
                *(_BYTE *)(a1 + 3355) = most_appropriate_phase;
                if ( v27 && *(_BYTE *)(a1 + 3960) == 1 )
                  ipc_log_string();
                result = 0;
                *v16 = 1;
              }
            }
            break;
          }
        }
        else if ( !--v21 )
        {
          if ( *(_QWORD *)(a1 + 3952) && *(_BYTE *)(a1 + 3960) == 1 )
            ipc_log_string();
          result = 4294967291LL;
          break;
        }
        result = msm_init_cm_dll(a1 + 1792, 0);
        if ( !(_DWORD)result )
          goto LABEL_17;
        break;
      }
    }
  }
  if ( (v20 & 2) != 0 )
  {
    v15 = (_QWORD *)(a1 + 1816);
    v14 = result;
    v11 = readl_relaxed((unsigned int *)(*v15 + *v8)) | 2;
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
