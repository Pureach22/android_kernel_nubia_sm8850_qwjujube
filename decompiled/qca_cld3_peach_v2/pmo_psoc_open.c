__int64 __fastcall pmo_psoc_open(
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
  __int64 comp_private_obj; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w8
  __int64 values; // x8
  __int64 result; // x0
  _BYTE v22[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    *(_BYTE *)(comp_private_obj + 2) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10514);
    *(_DWORD *)(comp_private_obj + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10516);
    *(_BYTE *)(comp_private_obj + 11) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10520);
    *(_BYTE *)(comp_private_obj + 8) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10521);
    *(_BYTE *)(comp_private_obj + 9) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10521);
    *(_BYTE *)(comp_private_obj + 25) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10524);
    *(_DWORD *)(comp_private_obj + 92) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10588);
    *(_BYTE *)(comp_private_obj + 26) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10528);
    *(_BYTE *)(comp_private_obj + 27) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10532);
    *(_BYTE *)(comp_private_obj + 28) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10536);
    *(_BYTE *)(comp_private_obj + 12) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10541);
    *(_DWORD *)(comp_private_obj + 44) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10544);
    *(_BYTE *)(comp_private_obj + 30) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10540);
    *(_BYTE *)(comp_private_obj + 82) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10580);
    *(_BYTE *)(comp_private_obj + 81) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10581);
    *(_BYTE *)(comp_private_obj + 83) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10582);
    *(_BYTE *)(comp_private_obj + 84) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10583);
    if ( (ipa_config_is_enabled() & 1) != 0 && (wlan_ipa_config_is_opt_wifi_dp_enabled() & 1) == 0 )
    {
      qdf_trace_msg(
        0x4Du,
        4u,
        "%s: ipa is enabled and hence disable sap/go d3 wow",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_pmo_init_cfg");
      *(_WORD *)(comp_private_obj + 83) = 0;
    }
    *(_DWORD *)(comp_private_obj + 48) = *(_DWORD *)(comp_private_obj + 44);
    *(_BYTE *)(comp_private_obj + 24) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10548);
    *(_DWORD *)(comp_private_obj + 40) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10552);
    *(_DWORD *)(comp_private_obj + 32) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10612);
    *(_DWORD *)(comp_private_obj + 36) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10616);
    *(_DWORD *)(comp_private_obj + 52) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10556);
    *(_BYTE *)(comp_private_obj + 1) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10493);
    *(_BYTE *)(comp_private_obj + 13) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10560);
    *(_BYTE *)(comp_private_obj + 64) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10488);
    *(_BYTE *)(comp_private_obj + 10) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10492) ^ 1;
    *(_DWORD *)(comp_private_obj + 56) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10620);
    *(_DWORD *)(comp_private_obj + 60) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10564);
    *(_BYTE *)(comp_private_obj + 65) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10513);
    *(_BYTE *)(comp_private_obj + 66) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10568);
    *(_BYTE *)(comp_private_obj + 67) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10572);
    *(_DWORD *)(comp_private_obj + 68) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10496);
    *(_DWORD *)(comp_private_obj + 72) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10500);
    *(_BYTE *)(comp_private_obj + 116) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10504);
    *(_DWORD *)(comp_private_obj + 120) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10508);
    *(_BYTE *)(comp_private_obj + 124) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10512);
    v19 = *(_DWORD *)(cfg_psoc_get_values(a1) + 7492);
    v22[0] = 0;
    *(_BYTE *)(comp_private_obj + 80) = v19;
    if ( !(unsigned int)ucfg_fwol_get_is_rate_limit_enabled(a1, v22) )
      *(_BYTE *)(comp_private_obj + 16) = v22[0];
    *(_WORD *)(comp_private_obj + 18) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10576);
    *(_BYTE *)(comp_private_obj + 96) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10522);
    *(_BYTE *)(comp_private_obj + 97) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10584);
    *(_BYTE *)(comp_private_obj + 98) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10592);
    *(_DWORD *)(comp_private_obj + 100) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10596);
    *(_BYTE *)(comp_private_obj + 104) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10600);
    *(_DWORD *)(comp_private_obj + 108) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10604);
    *(_DWORD *)(comp_private_obj + 112) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10608);
    values = cfg_psoc_get_values(a1);
    result = 0;
    *(_BYTE *)(comp_private_obj + 17) = *(_BYTE *)(values + 1794);
  }
  else
  {
    qdf_trace_msg(0x4Du, 2u, "%s: null psoc", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_psoc_open");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
