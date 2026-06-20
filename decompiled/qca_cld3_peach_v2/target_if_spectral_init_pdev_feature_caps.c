__int64 __fastcall target_if_spectral_init_pdev_feature_caps(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x19
  char i; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w9
  __int64 v15; // x0
  char v16; // w28
  __int64 v17; // x8
  __int64 (*v18)(void); // x8
  __int64 v19; // x23
  __int64 v20; // x8
  __int64 (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  char v25; // w0
  int v26; // w8
  __int64 (*v27)(void); // x8
  __int64 v28; // x23
  __int64 v29; // x8
  __int64 v30; // x0
  _DWORD *v31; // x8
  unsigned int v32; // w10
  _DWORD *v33; // x9
  __int64 v34; // x10
  __int64 v35; // x9
  _DWORD *v36; // x9
  unsigned int v37; // w8
  unsigned int v38; // w10
  __int64 v39; // x9
  int v40; // w11
  int v41; // w12
  __int64 v42; // x13
  int v43; // w8
  bool v44; // cc
  int v45; // w15
  int v46; // w11
  int v47; // w12
  int v48; // w13
  int v49; // w14
  unsigned int v50; // w16
  unsigned int v51; // w17
  unsigned int v52; // w16
  unsigned int v53; // w17
  const char *v54; // x2
  const char *v55; // x3

  if ( a1 )
  {
    v10 = "%s: psoc is null";
    for ( i = 1; ; i = 0 )
    {
      v15 = *(_QWORD *)(a1 + 80);
      if ( !v15 )
      {
        v54 = "%s: psoc is null";
        goto LABEL_85;
      }
      v16 = i;
      v17 = *(_QWORD *)(v15 + 2136);
      if ( (v16 & 1) == 0 )
        break;
      if ( !v17 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: rx_ops is null",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "target_if_spectral_is_feature_disabled_psoc");
LABEL_37:
        v26 = *(_DWORD *)(a1 + 16);
LABEL_38:
        v14 = v26 | 0x10;
        goto LABEL_6;
      }
      v18 = *(__int64 (**)(void))(v17 + 312);
      if ( !v18 )
        goto LABEL_37;
      if ( *((_DWORD *)v18 - 1) != -1548408 )
        __break(0x8228u);
      if ( (v18() & 1) != 0 )
        goto LABEL_37;
      v19 = *(_QWORD *)(a1 + 80);
      if ( !v19 )
        goto LABEL_84;
      v20 = *(_QWORD *)(v19 + 2136);
      if ( !v20 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: rx_ops is null",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "get_target_if_spectral_handle_from_psoc");
        v10 = "%s: psoc spectral object is null";
        goto LABEL_84;
      }
      v21 = *(__int64 (__fastcall **)(_QWORD))(v20 + 264);
      v22 = *(_QWORD *)(a1 + 80);
      if ( *((_DWORD *)v21 - 1) != -373219892 )
        __break(0x8228u);
      if ( !v21(v22) )
      {
        v10 = "%s: psoc spectral object is null";
        goto LABEL_84;
      }
      v23 = *(_QWORD *)(v19 + 2800);
      if ( !v23 || (v24 = *(_QWORD *)(v23 + 16)) == 0 )
      {
        v10 = "%s: wmi handle is null";
LABEL_84:
        qdf_trace_msg(0x56u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_get_normal_mode_cap");
        v54 = "%s: Failed to get normal spectral scan caps";
        goto LABEL_85;
      }
      v25 = wmi_service_enabled(v24, 0xE1u, a2, a3, a4, a5, a6, a7, a8, a9);
      v26 = *(_DWORD *)(a1 + 16);
      if ( (v25 & 1) != 0 )
        goto LABEL_38;
      v14 = v26 & 0xFFFFFFEF;
LABEL_6:
      *(_DWORD *)(a1 + 16) = v14;
      if ( (v16 & 1) == 0 )
        return 0;
    }
    if ( !v17 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: rx_ops is null",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "target_if_spectral_is_feature_disabled_psoc");
LABEL_78:
      *(_DWORD *)(a1 + 16) |= 0x1E0u;
      return 0;
    }
    v27 = *(__int64 (**)(void))(v17 + 312);
    if ( !v27 )
      goto LABEL_78;
    if ( *((_DWORD *)v27 - 1) != -1548408 )
      __break(0x8228u);
    if ( (v27() & 1) != 0 )
      goto LABEL_78;
    v28 = *(_QWORD *)(a1 + 80);
    if ( !v28 )
      goto LABEL_76;
    v29 = *(_QWORD *)(v28 + 2800);
    if ( !v29 || (v30 = *(_QWORD *)(v29 + 16)) == 0 )
    {
      v10 = "%s: wmi handle is null";
      goto LABEL_76;
    }
    if ( (wmi_service_enabled(v30, 0x5Cu, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
      goto LABEL_3;
    v31 = *(_DWORD **)(v28 + 2800);
    if ( !v31 )
    {
      v10 = "%s: target_psoc_info is null";
      goto LABEL_76;
    }
    v32 = v31[126];
    v33 = v31 + 268;
    if ( v32 <= 0xA )
    {
      if ( *v33 == v32 )
      {
        v34 = 0;
      }
      else if ( v31[332] == v32 )
      {
        v34 = 1;
      }
      else if ( v31[396] == v32 )
      {
        v34 = 2;
      }
      else if ( v31[460] == v32 )
      {
        v34 = 3;
      }
      else if ( v31[524] == v32 )
      {
        v34 = 4;
      }
      else if ( v31[588] == v32 )
      {
        v34 = 5;
      }
      else if ( v31[652] == v32 )
      {
        v34 = 6;
      }
      else
      {
        if ( v31[716] != v32 )
          goto LABEL_80;
        v34 = 7;
      }
      v33 += 64 * v34;
    }
    if ( !v33 )
    {
LABEL_80:
      v10 = "%s: mac phy cap array is null";
LABEL_76:
      qdf_trace_msg(0x56u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_get_agile_mode_cap");
      v54 = "%s: Failed to get agile Spectral capability";
LABEL_85:
      v55 = "target_if_spectral_init_pdev_feature_cap_per_mode";
      goto LABEL_86;
    }
    v35 = (unsigned int)v33[64 * (unsigned __int64)*(unsigned __int8 *)(a1 + 40) + 53];
    if ( (unsigned int)v35 >= 6 )
    {
      __break(0x5512u);
      return target_if_spectral_send_intf_found_msg();
    }
    v36 = &v31[4 * v35];
    v37 = v36[213];
    if ( !v37 )
    {
LABEL_3:
      v12 = *(_DWORD *)(a1 + 16) | 0x20;
      goto LABEL_4;
    }
    v38 = v37 - 1;
    v39 = *((_QWORD *)v36 + 107);
    if ( v37 == 1 )
    {
      v40 = 0;
      v41 = 0;
    }
    else
    {
      v40 = 0;
      if ( (_BYTE)v37 )
      {
        v44 = v38 > 0xFF;
        v41 = 0;
        v38 = 0;
        if ( !v44 )
        {
          v45 = 0;
          v46 = 0;
          v47 = 0;
          v48 = 0;
          v49 = 0;
          v38 = v37 & 0x1FE;
          do
          {
            v50 = v45 & 0xFE;
            v45 += 2;
            v51 = v50 | 1;
            v52 = *(unsigned __int8 *)(v39 + 8LL * v50);
            v53 = *(unsigned __int8 *)(v39 + 8LL * v51);
            v48 |= v52 >> 6;
            v46 |= v52 >> 7;
            v49 |= v53 >> 6;
            v47 |= v53 >> 7;
          }
          while ( v38 != v45 );
          v40 = v47 | v46;
          v41 = v49 | v48;
          if ( v37 == v38 )
          {
LABEL_60:
            v43 = *(_DWORD *)(a1 + 16);
            if ( (v41 & 1) != 0 )
            {
              v12 = v43 & 0xFFFFFFDF;
              if ( (v40 & 1) != 0 )
                goto LABEL_70;
            }
            else
            {
              v12 = v43 | 0x20;
              if ( (v40 & 1) != 0 )
              {
LABEL_70:
                v13 = v12 & 0xFFFFFF3F;
                goto LABEL_5;
              }
            }
LABEL_4:
            v13 = v12 | 0xC0;
LABEL_5:
            v14 = v13 | 0x100;
            goto LABEL_6;
          }
        }
      }
      else
      {
        v41 = 0;
        v38 = 0;
      }
    }
    do
    {
      v42 = (unsigned __int8)v38++;
      LODWORD(v42) = *(unsigned __int8 *)(v39 + 8 * v42);
      v41 |= (unsigned int)v42 >> 6;
      v40 |= (unsigned int)v42 >> 7;
    }
    while ( v37 > (unsigned __int8)v38 );
    goto LABEL_60;
  }
  v54 = "%s: pdev is NULL!";
  v55 = "target_if_spectral_init_pdev_feature_caps";
LABEL_86:
  qdf_trace_msg(0x56u, 2u, v54, a2, a3, a4, a5, a6, a7, a8, a9, v55);
  return 4;
}
