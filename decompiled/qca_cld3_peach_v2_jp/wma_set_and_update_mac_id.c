__int64 __fastcall wma_set_and_update_mac_id(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w19
  const char *v14; // x2
  const char *v15; // x3
  __int64 result; // x0
  __int64 v21; // x8
  _DWORD *v22; // x8
  __int64 v23; // x8
  int v24; // w8
  __int64 v25; // x23
  unsigned __int64 v26; // x8
  __int64 v27; // x24
  char v28; // w22
  __int64 v29; // x21
  unsigned int v30; // w20
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  __int64 v32; // [xsp+8h] [xbp-18h]
  unsigned int v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v13 = a5;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)a5 >= 2 )
  {
    v14 = "%s: Invalid mac_id %d";
    v15 = "wma_set_and_update_mac_id";
    a5 = (unsigned int)a5;
LABEL_24:
    result = qdf_trace_msg(0x36u, 2u, v14, a6, a7, a8, a9, a10, a11, a12, a13, v15, a5, v31);
    goto LABEL_25;
  }
  result = (__int64)wlan_mlme_set_vdev_mac_id(*(_QWORD *)(a1 + 32), *a3, a5);
  a5 = *a3;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488 * a5 + 164) == 4 )
  {
    if ( a4 && *(_QWORD *)a4 && (v21 = *(_QWORD *)(*(_QWORD *)a4 + 64LL)) != 0 )
    {
      v22 = *(_DWORD **)(v21 + 128);
      if ( v22 )
      {
        if ( *(v22 - 1) != 1944199495 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v22)(a4, (unsigned int)a5, v13);
      }
    }
    else
    {
      result = qdf_trace_msg(0x45u, 1u, "%s invalid instance", a6, a7, a8, a9, a10, a11, a12, a13, "cdp_update_mac_id");
    }
    a5 = *a3;
  }
  if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)a5 )
  {
    v14 = "%s: Invalid vdev_id %hu";
    v15 = "wma_is_vdev_in_ap_mode";
    goto LABEL_24;
  }
  v23 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned int)a5;
  if ( *(_DWORD *)(v23 + 164) == 1 )
  {
    v24 = *(_DWORD *)(v23 + 168);
    if ( v24 == 3 || !v24 )
    {
      if ( (unsigned int)a5 >= 6 )
        goto LABEL_60;
      v33 = 0;
      v25 = a2 + 14921;
      v31 = 0;
      v32 = 0;
      *(_BYTE *)(a2 + 14921 + (unsigned int)a5) = 0;
      v26 = *a3;
      if ( v26 >= 6 )
        goto LABEL_60;
      v27 = a2 + 14915;
      v28 = *(_BYTE *)(a2 + 14915 + v26);
      result = policy_mgr_get_sap_go_count_on_mac(*(_QWORD *)(a2 + 21552), &v31, v13);
      if ( (_DWORD)result )
      {
        a5 = (unsigned int)v31;
        if ( (unsigned int)v31 > 5 )
          goto LABEL_60;
        if ( *(_BYTE *)(v25 + (unsigned int)v31) == 1 )
        {
LABEL_22:
          v14 = "%s: vdev %d: does not finish restart";
          v15 = "wma_dcs_wlan_interference_mitigation_enable";
          goto LABEL_24;
        }
        v28 = (v28 & 1) != 0 ? 1 : *(_BYTE *)(v27 + (unsigned int)v31);
        if ( (_DWORD)result != 1 )
        {
          a5 = HIDWORD(v31);
          if ( HIDWORD(v31) > 5 )
            goto LABEL_60;
          if ( (*(_BYTE *)(v25 + HIDWORD(v31)) & 1) != 0 )
            goto LABEL_22;
          v28 = (v28 & 1) != 0 ? 1 : *(_BYTE *)(v27 + HIDWORD(v31));
          if ( (_DWORD)result != 2 )
          {
            a5 = (unsigned int)v32;
            if ( (unsigned int)v32 > 5 )
              goto LABEL_60;
            if ( (*(_BYTE *)(v25 + (unsigned int)v32) & 1) != 0 )
              goto LABEL_22;
            v28 = (v28 & 1) != 0 ? 1 : *(_BYTE *)(v27 + (unsigned int)v32);
            if ( (_DWORD)result != 3 )
            {
              a5 = HIDWORD(v32);
              if ( HIDWORD(v32) > 5 )
                goto LABEL_60;
              if ( (*(_BYTE *)(v25 + HIDWORD(v32)) & 1) != 0 )
                goto LABEL_22;
              v28 = (v28 & 1) != 0 ? 1 : *(_BYTE *)(v27 + HIDWORD(v32));
              if ( (_DWORD)result != 4 )
              {
                a5 = v33;
                if ( v33 > 5 )
                  goto LABEL_60;
                if ( (*(_BYTE *)(v25 + v33) & 1) != 0 )
                  goto LABEL_22;
                v28 = (v28 & 1) != 0 ? 1 : *(_BYTE *)(v27 + v33);
                if ( (_DWORD)result != 5 )
LABEL_60:
                  __break(0x5512u);
              }
            }
          }
        }
      }
      if ( (v28 & 1) != 0 )
        result = ucfg_config_dcs_event_data(*(_QWORD *)(a2 + 21552), v13, 1);
      if ( !*((_DWORD *)a3 + 3) )
      {
        ucfg_config_dcs_enable(*(_QWORD *)(a2 + 21552), v13, 2);
        v29 = *(_QWORD *)(a2 + 21552);
        v30 = *a3;
        if ( (target_if_vdev_level_dcs_is_supported(v29) & 1) != 0 )
          result = ucfg_wlan_dcs_cmd_for_vdev(v29, v13, v30);
        else
          result = ucfg_wlan_dcs_cmd(v29, v13, 1);
      }
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
