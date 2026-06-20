__int64 __fastcall dsi_panel_get_mode_count(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, const char *); // x8
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 (*v5)(void); // x8
  int v6; // w3
  _DWORD *v8; // x8
  __int64 v9; // x0
  __int64 v10; // x21
  int v11; // w22
  int v12; // w25
  unsigned int v13; // w27
  unsigned int v14; // w24
  unsigned int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w8
  __int64 (__fastcall *v18)(__int64, __int64); // x9
  __int64 (__fastcall *v19)(__int64, const char *); // x8
  __int64 (__fastcall *v20)(__int64, const char *); // x8
  int v21; // w8
  _DWORD *v22; // x8
  const char *v23; // x0
  _BOOL4 v24; // w23
  __int64 (__fastcall *v25)(__int64, const char *); // x8
  unsigned int v26; // w0
  unsigned int v27; // w28
  int v28; // w20
  int v29; // w22
  unsigned __int64 v30; // x26
  __int64 v31; // x25
  _DWORD *v32; // x8
  __int64 v33; // x0
  unsigned __int64 v34; // x8
  unsigned int v35; // w9
  __int64 v36; // x9
  int v37; // w8
  int v38; // w8
  __int64 v39; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
  v2 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1896);
  v3 = *(_QWORD *)(a1 + 1816);
  *(_DWORD *)(a1 + 1432) = 0;
  if ( *((_DWORD *)v2 - 1) != 387453051 )
    __break(0x8228u);
  v4 = v2(v3, "qcom,mdss-dsi-display-timings");
  if ( !v4 && (*(_BYTE *)(a1 + 1274) & 1) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: no display timing nodes defined\n");
    return 4294967274LL;
  }
  v5 = *(__int64 (**)(void))(a1 + 1904);
  if ( *((_DWORD *)v5 - 1) != -1880641320 )
    __break(0x8228u);
  v6 = v5();
  if ( v6 )
  {
    if ( v6 >= 33 )
    {
LABEL_10:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid count of timing nodes: %d\n", v6);
      return 4294967274LL;
    }
  }
  else if ( (*(_BYTE *)(a1 + 1274) & 1) == 0 )
  {
    goto LABEL_10;
  }
  if ( *(_DWORD *)(a1 + 1352) != 2 && (*(_BYTE *)(a1 + 1274) & 1) == 0 && !*(_BYTE *)(a1 + 1356) )
    v6 = 1;
  v8 = *(_DWORD **)(a1 + 1920);
  *(_DWORD *)(a1 + 1432) = v6;
  if ( *(v8 - 1) != -816260946 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD))v8)(v4, 0);
  if ( v9 )
  {
    v10 = v9;
    v11 = 0;
    v12 = 0;
    _ReadStatusReg(SP_EL0);
    v39 = v4;
    while ( 1 )
    {
      v19 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
      if ( *((_DWORD *)v19 - 1) != -834495637 )
        __break(0x8228u);
      if ( (v19(v10, "qcom,mdss-dsi-video-mode") & 1) != 0 )
        break;
      v20 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
      if ( *((_DWORD *)v20 - 1) != -834495637 )
        __break(0x8228u);
      if ( (v20(v10, "qcom,mdss-dsi-cmd-mode") & 1) != 0 || (v21 = *(_DWORD *)(a1 + 1352), v21 == 2) )
      {
        ++v12;
      }
      else if ( v21 == 1 )
      {
        break;
      }
LABEL_41:
      v22 = *(_DWORD **)(a1 + 1832);
      if ( *(v22 - 1) != -1612502898 )
        __break(0x8228u);
      v23 = (const char *)((__int64 (__fastcall *)(__int64, const char *, _QWORD))v22)(v10, "qcom,compression-mode", 0);
      if ( v23 )
        v24 = strcmp(v23, "dsc") == 0;
      else
        v24 = 0;
      v25 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1928);
      if ( *((_DWORD *)v25 - 1) != 1473856103 )
        __break(0x8228u);
      v26 = v25(v10, "qcom,display-topology");
      if ( v26 )
      {
        v27 = v26;
        v13 = 0;
        if ( v26 > 0xF )
        {
          v14 = 0;
        }
        else
        {
          v14 = 0;
          if ( !(v26 % 3) )
          {
            v28 = v11;
            v29 = v12;
            v30 = 4 * v26;
            v31 = _kmalloc_noprof(v30, 3520);
            if ( v31 )
            {
              v32 = *(_DWORD **)(a1 + 1872);
              if ( *(v32 - 1) != 905330014 )
                __break(0x8228u);
              v33 = ((__int64 (__fastcall *)(__int64, const char *, __int64, _QWORD))v32)(
                      v10,
                      "qcom,display-topology",
                      v31,
                      v27);
              if ( (_DWORD)v33 )
              {
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: unable to read the display topologies, rc = %d\n",
                  v33);
              }
              else if ( (unsigned __int8)v27 >= 3u )
              {
                v34 = 0;
                v13 = 0;
                v14 = 0;
                v35 = (unsigned __int8)v27 / 3u;
                if ( v35 <= 1 )
                  v35 = 1;
                v36 = 12LL * v35;
                while ( v30 > v34 )
                {
                  if ( v14 <= *(_DWORD *)(v31 + v34) )
                    v14 = *(_DWORD *)(v31 + v34);
                  if ( v24 )
                  {
                    if ( v30 <= v34 + 4 )
                      break;
                    if ( v13 <= *(_DWORD *)(v31 + v34 + 4) )
                      v13 = *(_DWORD *)(v31 + v34 + 4);
                  }
                  v34 += 12LL;
                  if ( v36 == v34 )
                    goto LABEL_59;
                }
                __break(1u);
                return dsi_panel_parse_dms_info(v33);
              }
              v13 = 0;
              v14 = 0;
LABEL_59:
              kfree(v31);
            }
            else
            {
              v13 = 0;
              v14 = 0;
            }
            v12 = v29;
            v11 = v28;
            v4 = v39;
          }
        }
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v15 = *(_DWORD *)(a1 + 2204);
      v16 = *(_DWORD *)(a1 + 2208);
      if ( v13 > v15 )
        v15 = v13;
      *(_DWORD *)(a1 + 2204) = v15;
      if ( v14 <= v16 )
        v17 = v16;
      else
        v17 = v14;
      v18 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1920);
      *(_DWORD *)(a1 + 2208) = v17;
      if ( *((_DWORD *)v18 - 1) != -816260946 )
        __break(0x8229u);
      v10 = v18(v4, v10);
      if ( !v10 )
        goto LABEL_77;
    }
    ++v11;
    goto LABEL_41;
  }
  v12 = 0;
  v11 = 0;
LABEL_77:
  if ( *(_BYTE *)(a1 + 1388) == 1 )
    v37 = *(_DWORD *)(a1 + 1384);
  else
    v37 = 1;
  v38 = v37 * v11;
  if ( *(_DWORD *)(a1 + 1352) == 1 )
  {
    if ( *(_BYTE *)(a1 + 1356) )
      v12 = 1;
  }
  *(_DWORD *)(a1 + 1436) = v12 + v38;
  return 0;
}
