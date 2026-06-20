__int64 __fastcall wma_set_and_update_mac_id(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        __int64 a5,
        unsigned int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  const char *v15; // x2
  const char *v16; // x3
  __int64 v17; // x4
  __int64 result; // x0
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 v26; // x8
  int v27; // w8
  __int64 v28; // x23
  unsigned __int64 v29; // x8
  __int64 v30; // x24
  char v31; // w22
  __int64 v32; // x21
  unsigned int v33; // w20
  __int64 v34; // [xsp+0h] [xbp-20h] BYREF
  __int64 v35; // [xsp+8h] [xbp-18h]
  unsigned int v36; // [xsp+10h] [xbp-10h]
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a6 >= 2 )
  {
    v15 = "%s: Invalid mac_id %d";
    v16 = "wma_set_and_update_mac_id";
    v17 = a6;
LABEL_27:
    result = qdf_trace_msg(0x36u, 2u, v15, a7, a8, a9, a10, a11, a12, a13, a14, v16, v17, v34);
    goto LABEL_28;
  }
  wlan_mlme_set_vdev_mac_id(*(_QWORD *)(a1 + 32), *a4, a6);
  result = *(_QWORD *)(a3 + 520);
  if ( *(_DWORD *)(result + 16) == 1
    && (result = wlan_vdev_mlme_is_mlo_vdev(result, a7, a8, a9, a10, a11, a12, a13, a14), (result & 1) != 0) )
  {
    v17 = *a4;
  }
  else
  {
    v17 = *a4;
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488 * v17 + 164) != 4 )
      goto LABEL_16;
  }
  if ( a5 && *(_QWORD *)a5 && (v24 = *(_QWORD *)(*(_QWORD *)a5 + 64LL)) != 0 )
  {
    v25 = *(_DWORD **)(v24 + 128);
    if ( v25 )
    {
      if ( *(v25 - 1) != 1944199495 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v25)(a5, (unsigned int)v17, a6);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               1u,
               "%s invalid instance",
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               "cdp_update_mac_id",
               v17);
  }
  v17 = *a4;
LABEL_16:
  if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)v17 )
  {
    v15 = "%s: Invalid vdev_id %hu";
    v16 = "wma_is_vdev_in_ap_mode";
    goto LABEL_27;
  }
  v26 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned int)v17;
  if ( *(_DWORD *)(v26 + 164) == 1 )
  {
    v27 = *(_DWORD *)(v26 + 168);
    if ( v27 == 3 || !v27 )
    {
      if ( (unsigned int)v17 >= 6 )
        goto LABEL_63;
      v36 = 0;
      v28 = a2 + 14993;
      v34 = 0;
      v35 = 0;
      *(_BYTE *)(a2 + 14993 + (unsigned int)v17) = 0;
      v29 = *a4;
      if ( v29 >= 6 )
        goto LABEL_63;
      v30 = a2 + 14987;
      v31 = *(_BYTE *)(a2 + 14987 + v29);
      result = policy_mgr_get_sap_go_count_on_mac(*(_QWORD *)(a2 + 21624), &v34, a6);
      if ( (_DWORD)result )
      {
        v17 = (unsigned int)v34;
        if ( (unsigned int)v34 > 5 )
          goto LABEL_63;
        if ( *(_BYTE *)(v28 + (unsigned int)v34) == 1 )
        {
LABEL_25:
          v15 = "%s: vdev %d: does not finish restart";
          v16 = "wma_dcs_wlan_interference_mitigation_enable";
          goto LABEL_27;
        }
        v31 = (v31 & 1) != 0 ? 1 : *(_BYTE *)(v30 + (unsigned int)v34);
        if ( (_DWORD)result != 1 )
        {
          v17 = HIDWORD(v34);
          if ( HIDWORD(v34) > 5 )
            goto LABEL_63;
          if ( (*(_BYTE *)(v28 + HIDWORD(v34)) & 1) != 0 )
            goto LABEL_25;
          v31 = (v31 & 1) != 0 ? 1 : *(_BYTE *)(v30 + HIDWORD(v34));
          if ( (_DWORD)result != 2 )
          {
            v17 = (unsigned int)v35;
            if ( (unsigned int)v35 > 5 )
              goto LABEL_63;
            if ( (*(_BYTE *)(v28 + (unsigned int)v35) & 1) != 0 )
              goto LABEL_25;
            v31 = (v31 & 1) != 0 ? 1 : *(_BYTE *)(v30 + (unsigned int)v35);
            if ( (_DWORD)result != 3 )
            {
              v17 = HIDWORD(v35);
              if ( HIDWORD(v35) > 5 )
                goto LABEL_63;
              if ( (*(_BYTE *)(v28 + HIDWORD(v35)) & 1) != 0 )
                goto LABEL_25;
              v31 = (v31 & 1) != 0 ? 1 : *(_BYTE *)(v30 + HIDWORD(v35));
              if ( (_DWORD)result != 4 )
              {
                v17 = v36;
                if ( v36 > 5 )
                  goto LABEL_63;
                if ( (*(_BYTE *)(v28 + v36) & 1) != 0 )
                  goto LABEL_25;
                v31 = (v31 & 1) != 0 ? 1 : *(_BYTE *)(v30 + v36);
                if ( (_DWORD)result != 5 )
LABEL_63:
                  __break(0x5512u);
              }
            }
          }
        }
      }
      if ( (v31 & 1) != 0 )
        result = ucfg_config_dcs_event_data(*(_QWORD *)(a2 + 21624), a6, 1);
      if ( !*((_DWORD *)a4 + 3) )
      {
        ucfg_config_dcs_enable(*(_QWORD *)(a2 + 21624), a6, 2);
        v32 = *(_QWORD *)(a2 + 21624);
        v33 = *a4;
        if ( (target_if_vdev_level_dcs_is_supported(v32) & 1) != 0 )
          result = ucfg_wlan_dcs_cmd_for_vdev(v32, a6, v33);
        else
          result = ucfg_wlan_dcs_cmd(v32, a6, 1);
      }
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
