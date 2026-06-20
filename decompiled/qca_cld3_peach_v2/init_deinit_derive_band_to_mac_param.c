__int64 __fastcall init_deinit_derive_band_to_mac_param(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 result; // x0
  unsigned int v14; // w8
  __int64 v15; // x21
  _DWORD *v16; // x26
  __int64 v17; // x8
  const char *v18; // x2
  unsigned __int64 v19; // x27
  _DWORD *v20; // x28
  _DWORD *i; // x22
  int v22; // w8
  const char *v23; // x2

  if ( !a10 )
  {
    v18 = "%s: target_psoc_info is null ";
    return qdf_trace_msg(0x49u, 2u, v18, a1, a2, a3, a4, a5, a6, a7, a8, "init_deinit_derive_band_to_mac_param");
  }
  result = ucfg_reg_get_hal_reg_cap();
  if ( !result )
  {
    v18 = "%s: reg cap is NULL";
    return qdf_trace_msg(0x49u, 2u, v18, a1, a2, a3, a4, a5, a6, a7, a8, "init_deinit_derive_band_to_mac_param");
  }
  v14 = *(_DWORD *)(a10 + 504);
  v15 = result;
  v16 = (_DWORD *)(a10 + 1072);
  if ( v14 <= 0xA )
  {
    if ( *v16 == v14 )
    {
      v17 = 0;
    }
    else if ( *(_DWORD *)(a10 + 1328) == v14 )
    {
      v17 = 1;
    }
    else if ( *(_DWORD *)(a10 + 1584) == v14 )
    {
      v17 = 2;
    }
    else if ( *(_DWORD *)(a10 + 1840) == v14 )
    {
      v17 = 3;
    }
    else if ( *(_DWORD *)(a10 + 2096) == v14 )
    {
      v17 = 4;
    }
    else if ( *(_DWORD *)(a10 + 2352) == v14 )
    {
      v17 = 5;
    }
    else if ( *(_DWORD *)(a10 + 2608) == v14 )
    {
      v17 = 6;
    }
    else
    {
      if ( *(_DWORD *)(a10 + 2864) != v14 )
      {
LABEL_40:
        v18 = "%s: mac_phy_cap is NULL";
        return qdf_trace_msg(0x49u, 2u, v18, a1, a2, a3, a4, a5, a6, a7, a8, "init_deinit_derive_band_to_mac_param");
      }
      v17 = 7;
    }
    v16 += 64 * v17;
  }
  if ( !v16 )
    goto LABEL_40;
  if ( *(_BYTE *)(a10 + 5652) != 1
    || *(_DWORD *)(a10 + 5656) != 1
    || (result = wmi_service_enabled(*(_QWORD *)(a10 + 16), 85), (result & 1) != 0) )
  {
    *(_DWORD *)(a11 + 28) = *(unsigned __int8 *)(a10 + 487);
  }
  if ( *(_BYTE *)(a10 + 487) )
  {
    v19 = 0;
    v20 = (_DWORD *)(a11 + 40);
    for ( i = (_DWORD *)(v15 + 44); ; i += 12 )
    {
      v22 = v16[6];
      if ( v22 == 1 )
        break;
      if ( v22 != 2 )
      {
        if ( v22 == 3 )
        {
          result = qdf_trace_msg(
                     0x49u,
                     8u,
                     "%s: Supports both 2G and 5G",
                     a1,
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     "init_deinit_derive_band_to_mac_param");
          *(v20 - 2) = v16[1];
          *(v20 - 1) = *(i - 3);
          *v20 = *i;
        }
        goto LABEL_31;
      }
      *(_DWORD *)(v15 + 48LL * (unsigned int)v16[2] + 32) = 0;
      *(_DWORD *)(v15 + 48LL * (unsigned int)v16[2] + 36) = 0;
      if ( *(_DWORD *)(a11 + 28) )
      {
        v23 = "%s: 5G radio -pdev_id = %d start_freq = %d end_freq =%d\n";
        *(v20 - 2) = v16[1];
        *(v20 - 1) = *(i - 1);
        *v20 = *i;
LABEL_30:
        result = qdf_trace_msg(0x49u, 8u, v23, a1, a2, a3, a4, a5, a6, a7, a8, "init_deinit_derive_band_to_mac_param");
      }
LABEL_31:
      ++v19;
      v16 += 64;
      v20 += 3;
      if ( v19 >= *(unsigned __int8 *)(a10 + 487) )
        return result;
    }
    *(_DWORD *)(v15 + 48LL * (unsigned int)v16[2] + 40) = 0;
    *(_DWORD *)(v15 + 48LL * (unsigned int)v16[2] + 44) = 0;
    if ( !*(_DWORD *)(a11 + 28) )
      goto LABEL_31;
    v23 = "%s: 2G radio - pdev_id = %d start_freq = %d end_freq= %d";
    *(v20 - 2) = v16[1];
    *(v20 - 1) = *(i - 3);
    *v20 = *(i - 2);
    goto LABEL_30;
  }
  return result;
}
