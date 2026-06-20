__int64 __fastcall cm_akm_roam_allowed(__int64 a1, __int64 a2)
{
  unsigned int param; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 psoc_ext_obj_fl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  const char *v22; // x2
  __int64 result; // x0

  param = wlan_crypto_get_param(a2, 7u);
  qdf_trace_msg(0x68u, 8u, "%s: akm %x", v4, v5, v6, v7, v8, v9, v10, v11, "cm_akm_roam_allowed", param);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  if ( (param & 0xC0000) != 0 && *(_BYTE *)(psoc_ext_obj_fl + 2713) != 1 )
  {
    v22 = "%s: FILS Roaming not suppprted by fw";
    goto LABEL_27;
  }
  v21 = *(_DWORD *)(psoc_ext_obj_fl + 2144);
  if ( (param & 0x400000) != 0 && (v21 & 0x10) == 0 )
  {
    v22 = "%s: OWE Roaming not suppprted by fw";
LABEL_27:
    qdf_trace_msg(0x68u, 4u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "cm_akm_roam_allowed");
    return 11;
  }
  if ( (param & 0x400) != 0 && (v21 & 8) == 0 )
  {
    v22 = "%s: Roaming not suppprted for SAE connection";
    goto LABEL_27;
  }
  if ( (param & 0x18000000) != 0 && (v21 & 0x40) == 0 )
  {
    v22 = "%s: Roaming not supported for SAE EXT akm";
    goto LABEL_27;
  }
  if ( (param & 0x30000) != 0 && (v21 & 0x20) == 0 )
  {
    v22 = "%s: Roaming not supported for SUITEB connection";
    goto LABEL_27;
  }
  if ( (param & 0x800) != 0 && (v21 & 1) == 0 )
  {
    v22 = "%s: Roaming not suppprted for FT SAE akm";
    goto LABEL_27;
  }
  if ( (param & 0x1000000) != 0 && (v21 & 2) == 0 )
  {
    v22 = "%s: Roaming not suppprted for FT Suite-B akm";
    goto LABEL_27;
  }
  result = 0;
  if ( (param & 0x300000) != 0 && (v21 & 4) == 0 )
  {
    v22 = "%s: Roaming not suppprted for FT FILS akm";
    goto LABEL_27;
  }
  return result;
}
