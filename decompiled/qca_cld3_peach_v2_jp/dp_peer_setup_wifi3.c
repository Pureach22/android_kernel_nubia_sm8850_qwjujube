__int64 __fastcall dp_peer_setup_wifi3(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, __int64 a4)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  char v16; // w9
  __int64 v17; // x27
  unsigned __int8 *v18; // x22
  int v19; // w26
  __int64 v20; // x25
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w23
  unsigned int v30; // w20
  unsigned int v31; // w24
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  __int64 v41; // x8
  void (__fastcall *v42)(unsigned __int8 *, __int64); // x8
  const char *v43; // x2
  _DWORD *v44; // x8
  __int64 v45; // x9
  __int64 v46; // x0
  __int64 v47; // x3
  __int64 v48; // x1

  v6 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v6 )
  {
    v15 = v6;
    if ( a4 )
    {
      qdf_mem_copy((void *)(v6 + 408), *(const void **)a4, 6u);
      v16 = *(_BYTE *)(v15 + 416) & 0xFE | *(_BYTE *)(a4 + 8) & 1;
      *(_BYTE *)(v15 + 416) = v16;
      *(_BYTE *)(v15 + 416) = v16 & 0xFD | *(_BYTE *)(a4 + 8) & 2;
      *(_BYTE *)(v15 + 417) = *(_BYTE *)(a4 + 9);
      *(_BYTE *)(v15 + 418) = *(_BYTE *)(a4 + 10);
      *(_BYTE *)(v15 + 419) = *(_BYTE *)(a4 + 11);
    }
    v17 = *(_QWORD *)(v15 + 24);
    if ( !v17 )
    {
LABEL_30:
      v30 = 16;
      goto LABEL_38;
    }
    v18 = *(unsigned __int8 **)(v17 + 24);
    v19 = *(_DWORD *)(v17 + 32);
    v20 = *((_QWORD *)v18 + 1);
    if ( (unsigned int)wlan_cfg_get_dp_pdev_nss_enabled(*((_QWORD *)v18 + 36)) )
      v29 = 0;
    else
      v29 = wlan_cfg_is_rx_hash_enabled(*(_QWORD *)(v20 + 40)) & 1;
    v31 = *((_DWORD *)v18 + 23757);
    if ( (unsigned int)(*(_DWORD *)(v17 + 36) - 1) >= 3 && (wlan_cfg_is_ipa_enabled(*(_QWORD *)(v20 + 40)) & 1) != 0 )
    {
      if ( (dp_ipa_is_mdm_platform() & 1) != 0 )
      {
        v31 = 4;
        if ( *(_DWORD *)(v17 + 32) == 1 )
          v29 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: opt_dp: default HOST reo ring is set",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "dp_peer_setup_get_reo_hash");
      }
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: pdev: %d vdev :%d opmode:%u peer %pK (%02x:%02x:%02x:**:**:%02x) hash-based-steering:%d default-reo_dest:%u",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dp_peer_setup_wifi3",
      *v18,
      *(unsigned __int8 *)(v17 + 59),
      *(unsigned int *)(v17 + 32),
      v15,
      *(unsigned __int8 *)(v15 + 44),
      *(unsigned __int8 *)(v15 + 45),
      *(unsigned __int8 *)(v15 + 46),
      *(unsigned __int8 *)(v15 + 49),
      v29,
      v31);
    v40 = *(_QWORD *)(*((_QWORD *)v18 + 1) + 20056LL);
    if ( v40 )
    {
      v41 = *(_QWORD *)(v40 + 416);
      if ( v41 )
      {
        v42 = *(void (__fastcall **)(unsigned __int8 *, __int64))(v41 + 288);
        if ( v42 )
        {
          if ( *((_DWORD *)v42 - 1) != -1878589846 )
            __break(0x8228u);
          v42(v18, v15);
          if ( !a4 )
          {
LABEL_26:
            if ( (unsigned int)dp_peer_legacy_setup(a1, v15) )
            {
              v30 = 1;
LABEL_38:
              dp_peer_unref_delete(v15, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
              return v30;
            }
          }
LABEL_28:
          if ( (*(_BYTE *)(v15 + 120) & 1) == 0 || *(_DWORD *)(v17 + 32) != 1 )
          {
            v44 = **(_DWORD ***)(a1 + 8);
            if ( v44 )
            {
              v45 = *(_QWORD *)(v15 + 24);
              v46 = *(_QWORD *)(a1 + 16);
              v47 = *(unsigned __int8 *)(v45 + 59);
              v48 = **(unsigned __int8 **)(v45 + 24);
              if ( *(v44 - 1) != -42811890 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v44)(
                v46,
                v48,
                v15 + 44,
                v47,
                v29,
                v31,
                0);
            }
            *(_DWORD *)(v15 + 232) = 1;
            if ( v19 != 4 )
              dp_peer_rx_init_wrapper((__int64)v18, (__int64 *)v15);
            v30 = 0;
            goto LABEL_38;
          }
          goto LABEL_30;
        }
      }
      v43 = "%s: callback not registered";
    }
    else
    {
      v43 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v43, v32, v33, v34, v35, v36, v37, v38, v39, "dp_monitor_peer_tx_init");
    if ( !a4 )
      goto LABEL_26;
    goto LABEL_28;
  }
  return 16;
}
