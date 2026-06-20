__int64 __fastcall wlan_cm_is_eht_allowed_for_current_security(__int64 a1, __int64 a2, int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w0
  __int64 v15; // x23
  unsigned int v16; // w24
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x20
  __int64 v42; // x8
  int v44; // w9
  unsigned int v45; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v46[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46[0] = 0;
  v45 = 0;
  if ( (unsigned int)wlan_mlme_is_rf_test_mode_enabled(a1, v46) )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Get rf test mode failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_is_eht_allowed_for_current_security");
    LOBYTE(v14) = 0;
    goto LABEL_14;
  }
  if ( v46[0] == 1 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: rf test mode is enabled, ignore setting",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_is_eht_allowed_for_current_security");
    LOBYTE(v14) = 1;
    goto LABEL_14;
  }
  v15 = *(_QWORD *)(a2 + 1416);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: RSN IE not present",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_is_eht_allowed_for_current_security",
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6));
    v16 = *(_DWORD *)(a2 + 1268);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: AP's security: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cm_is_eht_allowed_for_current_security",
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6),
      v16);
    if ( v16 > 1 )
      goto LABEL_13;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: allow open or none security for 11be AP",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wlan_cm_is_eht_allowed_for_current_security",
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6));
  }
  if ( (unsigned int)wlan_mlme_get_oem_eht_mlo_config(a1, &v45) )
  {
    v41 = jiffies;
    if ( wlan_cm_is_eht_allowed_for_current_security___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x68u, 2u, "OEM EHT cfg get failed", v33, v34, v35, v36, v37, v38, v39, v40);
      LOBYTE(v14) = 0;
      wlan_cm_is_eht_allowed_for_current_security___last_ticks = v41;
      goto LABEL_14;
    }
LABEL_13:
    LOBYTE(v14) = 0;
    goto LABEL_14;
  }
  v42 = *(_QWORD *)(a2 + 1824);
  if ( !v42 && (a3 & 1) != 0 )
    goto LABEL_13;
  if ( *(_BYTE *)(a2 + 1286) == 2 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x:MLO is not allowed for RSNO1 connection",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "wlan_cm_is_eht_allowed_for_current_security",
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6));
    LOBYTE(v14) = 0;
    goto LABEL_14;
  }
  v44 = *(_DWORD *)(a2 + 1268);
  if ( (*(_WORD *)(a2 + 1284) & 0x80) == 0 )
  {
    if ( (v44 & 0x19C20C00) == 0 && (v44 & 0x6000142) != 0 && (v45 & 3) != 0 )
    {
      if ( v42 )
        v14 = a3 ^ 1 | ((unsigned __int8)(v45 & 2) >> 1);
      else
        LOBYTE(v14) = v45 & 1;
    }
    else
    {
      LOBYTE(v14) = (v15 == 0) & (a3 ^ 1);
    }
    goto LABEL_14;
  }
  if ( (v44 & 0x13F00A1) != 0 )
    goto LABEL_24;
  if ( (v44 & 0x18C00C00) != 0 )
  {
    if ( (v44 & 0x18000C00) != 0 )
    {
      if ( v42 )
      {
        if ( (a3 & 1) != 0 )
        {
          if ( (v45 & 0x20000) != 0 )
            goto LABEL_24;
        }
        else if ( (v45 & 0x30000) != 0 )
        {
          goto LABEL_24;
        }
      }
      else if ( (a3 & 1) == 0 && (v45 & 0x10000) != 0 )
      {
        goto LABEL_24;
      }
      LOBYTE(v14) = util_scan_entry_sae_h2e_capable(a2);
      goto LABEL_14;
    }
LABEL_24:
    LOBYTE(v14) = 1;
    goto LABEL_14;
  }
  if ( (v44 & 0x6000142) == 0 || (v45 & 0xC) == 0 )
    goto LABEL_13;
  if ( v42 )
    v14 = a3 ^ 1 | ((unsigned __int8)(v45 & 8) >> 3);
  else
    v14 = (v45 >> 2) & 1;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v14 & 1;
}
