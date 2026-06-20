__int64 __fastcall wlan_dcs_psoc_open(
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
  __int64 comp_private_obj; // x0
  __int64 v11; // x20
  __int64 i; // x21
  __int64 v13; // x22
  int v14; // w8
  unsigned int v15; // w19
  const char *v16; // x2

  if ( !a1 )
  {
    v15 = 4;
    v16 = "%s: psoc is NULL";
LABEL_8:
    qdf_trace_msg(0x74u, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dcs_psoc_open");
    return v15;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !comp_private_obj )
  {
    v15 = 16;
    v16 = "%s: dcs psoc private object is NULL";
    goto LABEL_8;
  }
  v11 = comp_private_obj;
  for ( i = 0; i != 1152; i += 384 )
  {
    v13 = v11 + i;
    v14 = *(_DWORD *)(cfg_psoc_get_values(a1) + 804);
    *(_BYTE *)(v13 + 2) = 0;
    *(_BYTE *)v13 = v14;
    *(_DWORD *)(v13 + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 808);
    *(_DWORD *)(v13 + 8) = *(_DWORD *)(cfg_psoc_get_values(a1) + 824);
    *(_DWORD *)(v13 + 12) = *(_DWORD *)(cfg_psoc_get_values(a1) + 828);
    *(_DWORD *)(v13 + 16) = *(_DWORD *)(cfg_psoc_get_values(a1) + 836);
    *(_DWORD *)(v13 + 20) = *(_DWORD *)(cfg_psoc_get_values(a1) + 812);
    *(_DWORD *)(v13 + 24) = *(_DWORD *)(cfg_psoc_get_values(a1) + 816);
    *(_DWORD *)(v13 + 28) = *(_DWORD *)(cfg_psoc_get_values(a1) + 832);
    *(_DWORD *)(v13 + 32) = *(_DWORD *)(cfg_psoc_get_values(a1) + 840);
    *(_DWORD *)(v13 + 36) = *(_DWORD *)(cfg_psoc_get_values(a1) + 844);
    *(_DWORD *)(v13 + 40) = *(_DWORD *)(cfg_psoc_get_values(a1) + 820);
    *(_BYTE *)(v13 + 3) = *(_BYTE *)(cfg_psoc_get_values(a1) + 856);
    *(_BYTE *)(v13 + 176) = *(_DWORD *)(cfg_psoc_get_values(a1) + 848);
    *(_DWORD *)(v13 + 180) = *(_DWORD *)(cfg_psoc_get_values(a1) + 852);
    *(_BYTE *)(v13 + 49) = *(_DWORD *)(cfg_psoc_get_values(a1) + 860);
    *(_BYTE *)(v13 + 53) = *(_DWORD *)(cfg_psoc_get_values(a1) + 864);
    *(_BYTE *)(v13 + 50) = BYTE1(*(_DWORD *)(cfg_psoc_get_values(a1) + 860));
    *(_BYTE *)(v13 + 54) = BYTE1(*(_DWORD *)(cfg_psoc_get_values(a1) + 864));
    *(_BYTE *)(v13 + 51) = *(_WORD *)(cfg_psoc_get_values(a1) + 862);
    *(_BYTE *)(v13 + 55) = *(_WORD *)(cfg_psoc_get_values(a1) + 866);
    *(_BYTE *)(v13 + 52) = *(_BYTE *)(cfg_psoc_get_values(a1) + 863);
    *(_BYTE *)(v13 + 56) = *(_BYTE *)(cfg_psoc_get_values(a1) + 867);
  }
  return 0;
}
