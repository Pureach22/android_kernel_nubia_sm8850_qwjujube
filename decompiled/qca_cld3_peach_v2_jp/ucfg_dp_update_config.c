__int64 __fastcall ucfg_dp_update_config(__int64 a1, unsigned __int8 *a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _BYTE *v13; // x22
  __int64 **context; // x19
  char v15; // w23
  char v16; // w8
  char v17; // w23
  __int16 v18; // w23
  __int16 v19; // w24
  __int16 v20; // w25
  __int64 values; // x0
  __int16 v22; // w21
  __int16 v23; // w26
  __int64 v24; // x0
  __int16 v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 (__fastcall *v35)(__int64 **, __int16 *); // x8
  __int64 result; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  __int16 v46; // [xsp+8h] [xbp-18h] BYREF
  char v47; // [xsp+Ah] [xbp-16h]
  char v48; // [xsp+Bh] [xbp-15h]
  int v49; // [xsp+Ch] [xbp-14h]
  int v50; // [xsp+10h] [xbp-10h]
  int v51; // [xsp+14h] [xbp-Ch]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj )
  {
    v13 = (_BYTE *)comp_private_obj;
    *(_DWORD *)(comp_private_obj + 1196) = *((_DWORD *)a2 + 1);
    context = (__int64 **)_cds_get_context(71, "ucfg_dp_update_config");
    v15 = *(_BYTE *)(cfg_psoc_get_values(a1) + 406);
    v16 = *(_BYTE *)(cfg_psoc_get_values(a1) + 407);
    v17 = v15 | (2 * v16);
    v13[216] = v16;
    v47 = *(_DWORD *)(cfg_psoc_get_values(a1) + 560);
    v48 = *(_DWORD *)(cfg_psoc_get_values(a1) + 556);
    v18 = (unsigned __int8)(v17 | (8 * *(_BYTE *)(cfg_psoc_get_values(a1) + 4168))) | ((unsigned __int8)v13[372] << 8);
    v19 = 16 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 427) & 1);
    v20 = 32 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 426) & 1);
    values = cfg_psoc_get_values(a1);
    v22 = *a2;
    v23 = (*(_BYTE *)(values + 425) & 1) << 6;
    v13[217] = *(_DWORD *)(cfg_psoc_get_values(a1) + 412) != 0;
    v24 = cfg_psoc_get_values(a1);
    v25 = 4 * (v13[217] & 1);
    v13[221] = *(_BYTE *)(v24 + 4042);
    v46 = v18 | v19 | v20 | v23 | (v22 << 9) | v25;
    cfg_psoc_get_values(a1);
    cfg_psoc_get_values(a1);
    cfg_psoc_get_values(a1);
    v49 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4000);
    v50 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4004);
    v51 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4008);
    if ( context && *context )
    {
      v34 = **context;
      if ( v34 && (v35 = *(__int64 (__fastcall **)(__int64 **, __int16 *))(v34 + 584)) != nullptr )
      {
        if ( *((_DWORD *)v35 - 1) != 1821250919 )
          __break(0x8228u);
        result = v35(context, &v46);
        if ( (_DWORD)result )
        {
          v45 = result;
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Failed to attach config parameters",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "ucfg_dp_update_config");
          result = v45;
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cdp_update_config_parameters");
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: Unable to get DP context", v5, v6, v7, v8, v9, v10, v11, v12, "ucfg_dp_update_config");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
