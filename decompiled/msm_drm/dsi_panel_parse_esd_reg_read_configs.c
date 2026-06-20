__int64 __fastcall dsi_panel_parse_esd_reg_read_configs(__int64 a1)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x21
  unsigned int v4; // w22
  unsigned int v5; // w22
  int v6; // w10
  unsigned int v7; // w11
  unsigned int v8; // w12
  unsigned int v9; // w23
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  unsigned int v13; // w22
  int v14; // w11
  int v15; // w12
  int *v16; // x13
  __int64 v17; // x14
  int v18; // w15
  int v19; // w16
  int *v20; // x8
  __int64 v21; // x9
  int v22; // t1
  __int64 (__fastcall *v23)(__int64, const char *, unsigned int *); // x8
  __int64 v24; // x0
  unsigned __int64 v25; // x0
  unsigned int v26; // w9
  unsigned int v27; // w8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x2
  __int64 v34; // x3
  unsigned int (__fastcall *v35)(__int64, const char *, __int64, __int64); // x8
  unsigned int v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid Params\n");
LABEL_10:
    v5 = -22;
    goto LABEL_38;
  }
  dsi_panel_parse_cmd_sets_sub(a1 + 1728, 15, a1 + 1816);
  if ( !*(_DWORD *)(a1 + 1736) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: panel status command parsing failed\n");
    goto LABEL_10;
  }
  v2 = (_QWORD *)(a1 + 1768);
  if ( (dsi_panel_parse_esd_status_len(a1 + 1816, "qcom,mdss-dsi-panel-status-read-length", a1 + 1768) & 1) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid status read length\n");
    v5 = -22;
LABEL_37:
    kfree(*(_QWORD *)(a1 + 1744));
    goto LABEL_38;
  }
  v3 = (_QWORD *)(a1 + 1776);
  if ( (dsi_panel_parse_esd_status_len(a1 + 1816, "qcom,mdss-dsi-panel-status-valid-params", a1 + 1776) & 1) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 1736);
    if ( v4 )
    {
      if ( *(_DWORD *)*v3 > *(_DWORD *)*v2 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: ignore valid params\n");
LABEL_35:
        v5 = -22;
LABEL_36:
        kfree(*v3);
        kfree(*v2);
        goto LABEL_37;
      }
      v6 = 1;
      while ( v4 != v6 )
      {
        v7 = *(_DWORD *)(*v3 + 4LL * v6);
        v8 = *(_DWORD *)(*v2 + 4LL * v6++);
        if ( v7 > v8 )
        {
          v9 = v6 - 1;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: ignore valid params\n");
          if ( v9 < v4 )
            goto LABEL_35;
          break;
        }
      }
    }
  }
  v10 = *v3;
  if ( *v3 )
  {
    v11 = *(unsigned int *)(a1 + 1736);
    if ( !(_DWORD)v11 )
      goto LABEL_35;
  }
  else
  {
    v10 = *v2;
    v11 = *(unsigned int *)(a1 + 1736);
    if ( !(_DWORD)v11 )
      goto LABEL_35;
  }
  if ( (_DWORD)v11 == 1 )
  {
    v12 = 0;
    v13 = 0;
LABEL_25:
    v20 = (int *)(v10 + 4 * v12);
    v21 = v11 - v12;
    do
    {
      v22 = *v20++;
      --v21;
      v13 += v22;
    }
    while ( v21 );
    goto LABEL_27;
  }
  v12 = (unsigned int)v11 & 0xFFFFFFFE;
  v14 = 0;
  v15 = 0;
  v16 = (int *)(v10 + 4);
  v17 = v12;
  do
  {
    v18 = *(v16 - 1);
    v19 = *v16;
    v17 -= 2;
    v16 += 2;
    v14 += v18;
    v15 += v19;
  }
  while ( v17 );
  v13 = v15 + v14;
  if ( v12 != v11 )
    goto LABEL_25;
LABEL_27:
  if ( !v13 )
    goto LABEL_35;
  v23 = *(__int64 (__fastcall **)(__int64, const char *, unsigned int *))(a1 + 1912);
  v24 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v23 - 1) != -1265043226 )
    __break(0x8228u);
  v25 = v23(v24, "qcom,mdss-dsi-panel-status-value", &v36);
  v26 = v36;
  v27 = v36 >> 2;
  v36 >>= 2;
  if ( !v25 || v25 > 0xFFFFFFFFFFFFF000LL || v26 < 4 || v27 % v13 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: error parse panel-status-value\n");
    goto LABEL_35;
  }
  *(_DWORD *)(a1 + 1808) = v27 / v13;
  v29 = _kmalloc_noprof(4 * *(unsigned int *)(a1 + 1808) * (unsigned __int64)v13, 3520);
  *(_QWORD *)(a1 + 1784) = v29;
  if ( !v29 )
  {
    v5 = -12;
    goto LABEL_36;
  }
  v30 = _kmalloc_noprof(*(_DWORD *)(a1 + 1808) * v13, 3520);
  *(_QWORD *)(a1 + 1792) = v30;
  if ( !v30 )
  {
LABEL_49:
    kfree(*(_QWORD *)(a1 + 1784));
    v5 = -12;
    goto LABEL_36;
  }
  v31 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  *(_QWORD *)(a1 + 1800) = v31;
  if ( !v31 )
  {
    kfree(*(_QWORD *)(a1 + 1792));
    goto LABEL_49;
  }
  v32 = *(_QWORD *)(a1 + 1816);
  v33 = *(_QWORD *)(a1 + 1784);
  v34 = *(_DWORD *)(a1 + 1808) * v13;
  v35 = *(unsigned int (__fastcall **)(__int64, const char *, __int64, __int64))(a1 + 1872);
  if ( *((_DWORD *)v35 - 1) != 905330014 )
    __break(0x8228u);
  if ( v35(v32, "qcom,mdss-dsi-panel-status-value", v33, v34) )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: error reading panel status values\n");
    memset(*(void **)(a1 + 1784), 0, *(_DWORD *)(a1 + 1808) * v13);
  }
  v5 = 0;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v5;
}
