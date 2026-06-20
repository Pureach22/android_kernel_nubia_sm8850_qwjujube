__int64 __fastcall ipa_component_config_update(
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
  _DWORD *v10; // x8
  __int64 v11; // x0
  unsigned int ipa_config; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x9
  __int64 v22; // x8
  __int64 result; // x0

  v10 = (_DWORD *)g_ipa_config;
  if ( !g_ipa_config )
  {
    v11 = _qdf_mem_malloc(0x28u, "ipa_config_mem_alloc", 79);
    if ( !v11 )
      return qdf_trace_msg(
               0x61u,
               2u,
               "%s: Failed to alloc g_ipa_config",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "ipa_component_config_update");
    v10 = (_DWORD *)v11;
    g_ipa_config = v11;
  }
  if ( g_ipa_pld_enable == 1 && g_ipa_cap_offload == 1 )
  {
    ipa_config = get_ipa_config(a1);
    *(_DWORD *)g_ipa_config = ipa_config;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: IPA ini configuration: 0x%x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ipa_component_config_update",
      ipa_config);
  }
  else
  {
    *v10 = 0;
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: IPA disabled from platform driver",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ipa_component_config_update");
  }
  *(_DWORD *)(g_ipa_config + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1116);
  v21 = *(unsigned int *)(cfg_psoc_get_values(a1) + 1136);
  v22 = 1LL << ~(unsigned __int8)__clz(v21);
  if ( (v21 ^ (v21 - 1)) > v21 - 1 )
    LODWORD(v22) = v21;
  *(_DWORD *)(g_ipa_config + 8) = v22;
  *(_DWORD *)(g_ipa_config + 24) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1120);
  *(_DWORD *)(g_ipa_config + 28) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1124);
  *(_DWORD *)(g_ipa_config + 32) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1128);
  *(_DWORD *)(g_ipa_config + 12) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4148);
  *(_DWORD *)(g_ipa_config + 16) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4152);
  *(_DWORD *)(g_ipa_config + 20) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4156);
  *(_BYTE *)(g_ipa_config + 36) = *(_BYTE *)(cfg_psoc_get_values(a1) + 1132);
  *(_BYTE *)(g_ipa_config + 37) = *(_BYTE *)(cfg_psoc_get_values(a1) + 1140);
  result = cfg_psoc_get_values(a1);
  *(_BYTE *)(g_ipa_config + 38) = *(_BYTE *)(result + 1141);
  return result;
}
