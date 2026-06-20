__int64 **__fastcall wlan_dp_txrx_soc_attach(__int64 *a1, _BYTE *a2)
{
  __int64 context; // x21
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x24
  __int64 **result; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 (*v22)(void); // x8
  __int64 **v23; // x23
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 (*v32)(void); // x8
  __int64 **v33; // x20
  __int64 v34; // x0
  __int64 **v35; // x19
  __int64 v36; // x8
  void (*v37)(void); // x8
  __int64 v38; // [xsp+0h] [xbp-40h] BYREF
  __int64 v39; // [xsp+8h] [xbp-38h]
  __int64 v40; // [xsp+10h] [xbp-30h]
  __int64 v41; // [xsp+18h] [xbp-28h]
  __int64 v42; // [xsp+20h] [xbp-20h]
  __int64 v43; // [xsp+28h] [xbp-18h]
  __int64 v44; // [xsp+30h] [xbp-10h]
  __int64 v45; // [xsp+38h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(62, "wlan_dp_txrx_soc_attach");
  v5 = _cds_get_context(64, "wlan_dp_txrx_soc_attach");
  v6 = gp_dp_ctx;
  v7 = _cds_get_context(61, "wlan_dp_txrx_soc_attach");
  v8 = *((unsigned int *)a1 + 4);
  v9 = v7;
  result = nullptr;
  if ( (unsigned int)v8 > 0x2B )
    goto LABEL_41;
  if ( ((1LL << v8) & 0xD2480000000LL) == 0 )
  {
    if ( ((1LL << v8) & 0x18A00000) != 0 )
    {
      v42 = 65533;
      v25 = *a1;
      v24 = a1[1];
      v43 = 0;
      v44 = 0;
      v38 = v9;
      v39 = context;
      v40 = v5;
      v41 = v25;
      result = (__int64 **)dp_soc_attach_wifi3(v24, &v38);
      if ( !result )
        goto LABEL_24;
      if ( !*result )
        goto LABEL_30;
      v26 = **result;
      if ( !v26 )
        goto LABEL_40;
      v22 = *(__int64 (**)(void))(v26 + 400);
      if ( !v22 )
        goto LABEL_31;
      v23 = result;
    }
    else
    {
      if ( v8 != 38 )
        goto LABEL_41;
      v42 = 49136;
      v29 = *a1;
      v28 = a1[1];
      v43 = 0;
      v44 = 0;
      v38 = v9;
      v39 = context;
      v40 = v5;
      v41 = v29;
      result = (__int64 **)dp_soc_attach_wifi3(v28, &v38);
      if ( !result )
        goto LABEL_24;
      if ( !*result )
        goto LABEL_30;
      v30 = **result;
      if ( !v30 )
        goto LABEL_40;
      v22 = *(__int64 (**)(void))(v30 + 400);
      if ( !v22 )
        goto LABEL_31;
      v23 = result;
    }
LABEL_14:
    if ( *((_DWORD *)v22 - 1) != 1753485351 )
      __break(0x8228u);
    v27 = v22();
    result = v23;
    if ( !v27 )
      goto LABEL_31;
    goto LABEL_24;
  }
  v42 = 45054;
  v12 = *a1;
  v11 = a1[1];
  v43 = 0;
  v44 = 0;
  v38 = v9;
  v39 = context;
  v40 = v5;
  v41 = v12;
  result = (__int64 **)dp_soc_attach_wifi3(v11, &v38);
  if ( result )
  {
    if ( *result )
    {
      v21 = **result;
      if ( v21 )
      {
        v22 = *(__int64 (**)(void))(v21 + 400);
        if ( v22 )
        {
          v23 = result;
          goto LABEL_14;
        }
LABEL_31:
        if ( *result )
        {
          v36 = **result;
          if ( v36 )
          {
            v37 = *(void (**)(void))(v36 + 384);
            if ( v37 )
            {
              if ( *((_DWORD *)v37 - 1) != -1106481425 )
                __break(0x8228u);
              v37();
            }
          }
        }
        else
        {
          qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v13, v14, v15, v16, v17, v18, v19, v20, "cdp_soc_detach");
        }
      }
LABEL_40:
      result = nullptr;
      goto LABEL_41;
    }
LABEL_30:
    v35 = result;
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v13, v14, v15, v16, v17, v18, v19, v20, "cdp_soc_init");
    result = v35;
    goto LABEL_31;
  }
LABEL_24:
  *a2 = 1;
  if ( result )
  {
    *(_QWORD *)(v6 + 240) = result;
    v31 = **result;
    if ( v31 && (v32 = *(__int64 (**)(void))(v31 + 936)) != nullptr )
    {
      v33 = result;
      if ( *((_DWORD *)v32 - 1) != 1994779534 )
        __break(0x8228u);
      v34 = v32();
    }
    else
    {
      v33 = result;
      v34 = 0;
    }
    *(_QWORD *)(v6 + 1488) = v34;
    wlan_dp_svc_init(v6);
    wlan_dp_resource_mgr_attach(v6);
    result = v33;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
