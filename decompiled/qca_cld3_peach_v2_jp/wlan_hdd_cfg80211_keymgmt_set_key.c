__int64 __fastcall wlan_hdd_cfg80211_keymgmt_set_key(__int64 a1, __int64 a2, const void *a3, unsigned int a4)
{
  __int64 v7; // x0
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 v18; // x24
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w0
  __int64 v29; // x21
  __int64 v30; // x21
  const char *v31; // x2
  unsigned int v32; // w19
  __int64 v33; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD v34[10]; // [xsp+10h] [xbp-A0h] BYREF
  __int64 v35; // [xsp+60h] [xbp-50h]
  __int64 v36; // [xsp+68h] [xbp-48h]
  __int64 v37; // [xsp+70h] [xbp-40h]
  __int64 v38; // [xsp+78h] [xbp-38h]
  __int64 v39; // [xsp+80h] [xbp-30h]
  __int64 v40; // [xsp+88h] [xbp-28h]
  __int64 v41; // [xsp+90h] [xbp-20h]
  __int64 v42; // [xsp+98h] [xbp-18h]
  __int64 v43; // [xsp+A0h] [xbp-10h]
  __int64 v44; // [xsp+A8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 32);
  v33 = 0;
  result = _osif_vdev_sync_op_start(v7, &v33, "wlan_hdd_cfg80211_keymgmt_set_key");
  if ( !(_DWORD)result )
  {
    v17 = *(_QWORD *)(a2 + 32);
    v18 = *(_QWORD *)(v17 + 55512);
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v35 = 0;
    memset(v34, 0, sizeof(v34));
    v19 = qdf_trace_msg(
            0x33u,
            8u,
            "%s: enter(%s)",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "__wlan_hdd_cfg80211_keymgmt_set_key",
            v17 + 296);
    if ( (unsigned int)hdd_get_conparam(v19) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "__wlan_hdd_cfg80211_keymgmt_set_key");
      v28 = -1;
    }
    else
    {
      if ( a3 && a4 - 65 > 0xFFFFFFBF )
      {
        v29 = *(_QWORD *)(v17 + 2712);
        if ( v29 )
        {
          v28 = _wlan_hdd_validate_context(*(_QWORD *)(v17 + 2712), "__wlan_hdd_cfg80211_keymgmt_set_key");
          if ( !v28 )
          {
            v30 = *(_QWORD *)(v29 + 16);
            qdf_mem_set(v34, 0x98u, 0);
            BYTE6(v35) = a4;
            qdf_mem_copy((char *)&v34[2] + 6, a3, a4);
            qdf_mem_copy(v34, (const void *)(v18 + 300), 6u);
            sme_roam_set_psk_pmk(v30, v34, *(unsigned __int8 *)(*(_QWORD *)(v17 + 55512) + 8LL), 1);
            qdf_mem_set(v34, 0x98u, 0);
            v28 = 0;
          }
          goto LABEL_12;
        }
        v31 = "%s: HDD context is null";
      }
      else
      {
        v31 = "%s: Invalid data";
      }
      qdf_trace_msg(0x33u, 2u, v31, v20, v21, v22, v23, v24, v25, v26, v27, "__wlan_hdd_cfg80211_keymgmt_set_key");
      v28 = -22;
    }
LABEL_12:
    v32 = v28;
    _osif_vdev_sync_op_stop(v33, "wlan_hdd_cfg80211_keymgmt_set_key");
    result = v32;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
