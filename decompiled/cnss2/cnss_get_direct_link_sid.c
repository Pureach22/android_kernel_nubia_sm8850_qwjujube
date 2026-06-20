__int64 __fastcall cnss_get_direct_link_sid(__int64 a1, _WORD *a2)
{
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 compatible_node; // x0
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  const char *v8; // x1
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x6
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  const char *v16; // x5
  __int16 v17; // w9
  const char *v18; // x8
  __int16 v19; // w9
  const char *v20; // x8
  __int64 result; // x0
  __int16 v22; // w9
  const char *v23; // x8
  char v24; // [xsp+0h] [xbp-60h]
  __int64 v25; // [xsp+8h] [xbp-58h] BYREF
  int v26; // [xsp+10h] [xbp-50h]
  int v27; // [xsp+14h] [xbp-4Ch]
  __int64 v28; // [xsp+18h] [xbp-48h]
  __int64 v29; // [xsp+20h] [xbp-40h]
  __int64 v30; // [xsp+28h] [xbp-38h]
  __int64 v31; // [xsp+30h] [xbp-30h]
  __int64 v32; // [xsp+38h] [xbp-28h]
  __int64 v33; // [xsp+40h] [xbp-20h]
  __int64 v34; // [xsp+48h] [xbp-18h]
  __int64 v35; // [xsp+50h] [xbp-10h]
  __int64 v36; // [xsp+58h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v25 = 0;
  v27 = 0;
  v26 = 1;
  if ( !cnss_bus_dev_to_plat_priv(a1, (__int64)a2) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v15;
    }
    v16 = "plat priv is not available";
    goto LABEL_24;
  }
  compatible_node = of_find_compatible_node(0, 0, "qcom,cnss-direct-link");
  if ( !compatible_node )
  {
    v10 = _ReadStatusReg(SP_EL0);
    v7 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(v10 + 16);
      v20 = (const char *)(v10 + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v20;
    }
    v16 = "Unable to get direct link node";
    goto LABEL_24;
  }
  if ( (unsigned int)_of_parse_phandle_with_args(compatible_node, "iommus", "#iommu-cells", 0xFFFFFFFFLL, 0, &v25) )
  {
    v6 = _ReadStatusReg(SP_EL0);
    v7 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v6 + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(v6 + 16);
      v18 = (const char *)(v6 + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v18;
    }
    v16 = "Unable to parse iommus property";
LABEL_24:
    cnss_debug_ipc_log_print(v7, v8, "cnss_get_direct_link_sid", 3u, 3u, v16, v3, v4, v24);
    result = 4294967277LL;
    goto LABEL_25;
  }
  v11 = v27 & 0x1F;
  v12 = _ReadStatusReg(SP_EL0);
  *a2 = v11;
  if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
  {
    v13 = "irq";
  }
  else
  {
    v22 = *(_DWORD *)(v12 + 16);
    v23 = (const char *)(v12 + 2320);
    if ( (v22 & 0xFF00) != 0 )
      v13 = "soft_irq";
    else
      v13 = v23;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v13,
    "cnss_get_direct_link_sid",
    7u,
    7u,
    "Direct link SID value:%u",
    v11,
    v4,
    v24);
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
