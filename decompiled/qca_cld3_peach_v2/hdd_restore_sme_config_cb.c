__int64 __fastcall hdd_restore_sme_config_cb(
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
  __int64 v9; // x19
  __int64 v10; // x20
  __int64 *context; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  unsigned int v21; // w21
  const char *v22; // x2
  __int64 v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w23
  _DWORD *v34; // x25
  int v35; // w8
  _DWORD *v36; // x9

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 8);
    if ( v9 )
    {
      v10 = *(_QWORD *)v9;
      if ( !*(_QWORD *)v9 )
      {
        _qdf_mem_free(0);
        v21 = 16;
        goto LABEL_12;
      }
      context = _cds_get_context(51, (__int64)"hdd_restore_sme_config_cb", a2, a3, a4, a5, a6, a7, a8, a9);
      if ( (unsigned int)_wlan_hdd_validate_context(context, "hdd_restore_sme_config_cb") )
        goto LABEL_5;
      v20 = (__int64)_cds_get_context(52, (__int64)"hdd_restore_sme_config_cb", v12, v13, v14, v15, v16, v17, v18, v19);
      if ( !v20 )
        goto LABEL_6;
      if ( !*context )
      {
LABEL_5:
        v20 = 0;
      }
      else
      {
        v24 = v20;
        v20 = _qdf_mem_malloc(0x4E4u, "hdd_restore_sme_config_cb", 2575);
        if ( v20 )
        {
          v33 = *(unsigned __int8 *)(v10 + 168);
          v34 = (_DWORD *)v20;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev id %d is_restore %d bonding_mode %d chwdith %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "hdd_restore_sme_config_cb",
            *(unsigned __int8 *)(v10 + 168),
            *(unsigned __int8 *)(v9 + 12),
            *(unsigned int *)(v9 + 16),
            *(unsigned int *)(v9 + 8));
          sme_get_config_param(v24, v34);
          if ( *(_BYTE *)(v9 + 12) == 1 )
          {
            v34[1] = *(_DWORD *)(cfg_psoc_get_values(*context) + 7424);
            v35 = *(_DWORD *)(cfg_psoc_get_values(*context) + 7420);
            v36 = v34;
          }
          else
          {
            v35 = *(_DWORD *)(v9 + 16);
            v36 = v34;
            v34[1] = v35;
          }
          *v36 = v35;
          sme_update_config(v24, v34);
          sme_set_he_bw_cap(context[2], v33, *(unsigned int *)(v9 + 8));
          sme_set_eht_bw_cap(context[2], v33, *(unsigned int *)(v9 + 8));
          v20 = (__int64)v34;
          v21 = 0;
          goto LABEL_7;
        }
      }
LABEL_6:
      v21 = 16;
LABEL_7:
      _qdf_mem_free(v20);
      _hdd_objmgr_put_vdev_by_user(v10, 5, "hdd_restore_sme_config_cb");
LABEL_12:
      _qdf_mem_free(v9);
      return v21;
    }
    v22 = "%s: bodyptr is null";
  }
  else
  {
    v22 = "%s: msg is null";
  }
  qdf_trace_msg(0x33u, 8u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_restore_sme_config_cb");
  return 4;
}
