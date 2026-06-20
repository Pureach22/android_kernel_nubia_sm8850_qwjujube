__int64 __fastcall wlan_hdd_cfg80211_change_bss(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x24
  _QWORD *context; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  __int64 v25; // x25
  unsigned int v26; // w22
  const char *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  int v37; // w0
  int v38; // w8
  int v39; // w20
  unsigned __int8 v40; // w8
  __int64 v41; // x1
  unsigned int v42; // w19
  __int64 v43; // [xsp+8h] [xbp-28h] BYREF
  __int64 v44; // [xsp+10h] [xbp-20h] BYREF
  char v45; // [xsp+18h] [xbp-18h]
  _BYTE v46[23]; // [xsp+19h] [xbp-17h]

  *(_QWORD *)&v46[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  result = _osif_vdev_sync_op_start(a2, &v43, "wlan_hdd_cfg80211_change_bss");
  if ( !(_DWORD)result )
  {
    v14 = *(_QWORD *)(a2 + 55520);
    context = _cds_get_context(71, (__int64)"__wlan_hdd_cfg80211_change_bss", v6, v7, v8, v9, v10, v11, v12, v13);
    if ( (unsigned int)hdd_get_conparam(context) == 5 )
    {
      v24 = "%s: Command not allowed in FTM mode";
    }
    else
    {
      v25 = *(_QWORD *)(a2 + 55520);
      if ( v25 )
      {
        if ( !(unsigned int)_wlan_hdd_validate_vdev_id(*(unsigned __int8 *)(v25 + 8), "__wlan_hdd_cfg80211_change_bss") )
        {
          qdf_mtrace(51, 51, 0x1Du, *(_BYTE *)(v25 + 8), *(_DWORD *)(a3 + 28));
          v26 = *(unsigned __int8 *)(v25 + 8);
          v27 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %d mode %s(%d), ap_isolate = %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_change_bss",
            v26,
            v27,
            *(unsigned int *)(a2 + 2728),
            *(unsigned int *)(a3 + 28));
          v36 = *(_QWORD *)(a2 + 2712);
          v37 = _wlan_hdd_validate_context(v36, "__wlan_hdd_cfg80211_change_bss");
          if ( !v37 )
          {
            if ( (*(_DWORD *)(a2 + 2728) | 2) == 3 )
            {
              v38 = *(_DWORD *)(a3 + 28);
              if ( v38 == -1 )
              {
                v37 = 0;
              }
              else
              {
                *(_BYTE *)(v14 + 258) = v38 != 0;
                if ( (unsigned int)sme_ap_disable_intra_bss_fwd(*(_QWORD *)(v36 + 16), *(unsigned __int8 *)(v25 + 8)) )
                  v39 = -22;
                else
                  v39 = 0;
                ucfg_ipa_set_ap_ibss_fwd(
                  *(_QWORD *)(v36 + 8),
                  *(unsigned __int8 *)(v25 + 8),
                  *(unsigned __int8 *)(v14 + 258));
                v40 = *(_BYTE *)(v14 + 258);
                v41 = *(unsigned __int8 *)(v25 + 8);
                v45 = 0;
                *(_QWORD *)v46 = 0;
                v44 = v40 ^ 1u;
                *(_QWORD *)&v46[7] = 0;
                cdp_txrx_set_vdev_param(context, v41, &v44);
                v37 = v39;
              }
            }
            else
            {
              v37 = -95;
            }
          }
          goto LABEL_16;
        }
LABEL_15:
        v37 = -22;
LABEL_16:
        v42 = v37;
        _osif_vdev_sync_op_stop(v43, "wlan_hdd_cfg80211_change_bss");
        result = v42;
        goto LABEL_17;
      }
      v24 = "%s: invalid link_info";
    }
    qdf_trace_msg(0x33u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "__wlan_hdd_cfg80211_change_bss");
    goto LABEL_15;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
