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
  unsigned __int8 *v18; // x23
  int v19; // w26
  __int64 v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w24
  unsigned int v30; // w20
  unsigned int v31; // w25
  __int64 v32; // x8
  __int64 v33; // x8
  void (__fastcall *v34)(unsigned __int8 *, __int64); // x8
  const char *v35; // x2
  _DWORD *v36; // x8
  __int64 v37; // x9
  __int64 v38; // x0
  __int64 v39; // x3
  __int64 v40; // x1
  __int64 *v41; // x1
  char **v42; // x8
  char *v43; // x20
  char *v44; // x22
  char v45; // w8
  unsigned __int8 v46; // w8
  unsigned __int8 *v47; // x11
  int v48; // w10
  int v49; // w8
  int v50; // w9
  __int64 v51; // x0
  _BYTE *v52; // x22
  void *v53; // x0
  __int64 v55; // [xsp+0h] [xbp-30h]
  __int64 v56; // [xsp+8h] [xbp-28h]
  __int64 v57; // [xsp+10h] [xbp-20h]
  __int64 v58; // [xsp+18h] [xbp-18h]

  v6 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v6 )
  {
    v15 = v6;
    if ( a4 )
    {
      qdf_mem_copy((void *)(v6 + 504), *(const void **)a4, 6u);
      v16 = *(_BYTE *)(v15 + 512) & 0xFE | *(_BYTE *)(a4 + 8) & 1;
      *(_BYTE *)(v15 + 512) = v16;
      *(_BYTE *)(v15 + 512) = v16 & 0xFD | *(_BYTE *)(a4 + 8) & 2;
      *(_BYTE *)(v15 + 513) = *(_BYTE *)(a4 + 9);
      *(_BYTE *)(v15 + 514) = *(_BYTE *)(a4 + 10);
      *(_BYTE *)(v15 + 515) = *(_BYTE *)(a4 + 11);
    }
    v17 = *(_QWORD *)(v15 + 24);
    if ( !v17 )
      goto LABEL_29;
    v18 = *(unsigned __int8 **)(v17 + 24);
    v19 = *(_DWORD *)(v17 + 32);
    v20 = *((_QWORD *)v18 + 1);
    if ( (unsigned int)wlan_cfg_get_dp_pdev_nss_enabled(*((_QWORD *)v18 + 36)) )
      v29 = 0;
    else
      v29 = wlan_cfg_is_rx_hash_enabled(*(_QWORD *)(v20 + 40)) & 1;
    v31 = *((_DWORD *)v18 + 23981);
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
    if ( *(_DWORD *)(v15 + 408) != 2 )
    {
      v32 = *(_QWORD *)(*((_QWORD *)v18 + 1) + 20112LL);
      if ( v32 )
      {
        v33 = *(_QWORD *)(v32 + 416);
        if ( v33 )
        {
          v34 = *(void (__fastcall **)(unsigned __int8 *, __int64))(v33 + 288);
          if ( v34 )
          {
            if ( *((_DWORD *)v34 - 1) != -1878589846 )
              __break(0x8228u);
            v34(v18, v15);
            goto LABEL_26;
          }
        }
        v35 = "%s: callback not registered";
      }
      else
      {
        v35 = "%s: monitor soc is NULL";
      }
      qdf_trace_msg(0x92u, 8u, v35, v7, v8, v9, v10, v11, v12, v13, v14, "dp_monitor_peer_tx_init");
    }
LABEL_26:
    if ( !a4 && (unsigned int)dp_peer_legacy_setup(a1, (_QWORD *)v15) )
    {
      v30 = 1;
      goto LABEL_78;
    }
    if ( (*(_BYTE *)(v15 + 120) & 1) != 0 && *(_DWORD *)(v17 + 32) == 1 )
    {
LABEL_29:
      v30 = 16;
LABEL_78:
      dp_peer_unref_delete(v15, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
      return v30;
    }
    v36 = **(_DWORD ***)(a1 + 8);
    if ( v36 )
    {
      v37 = *(_QWORD *)(v15 + 24);
      v38 = *(_QWORD *)(a1 + 16);
      v39 = *(unsigned __int8 *)(v37 + 59);
      v40 = **(unsigned __int8 **)(v37 + 24);
      if ( *(v36 - 1) != -42811890 )
        __break(0x8228u);
      v7 = ((double (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v36)(
             v38,
             v40,
             v15 + 44,
             v39,
             v29,
             v31,
             0);
    }
    *(_DWORD *)(v15 + 240) = 1;
    if ( (unsigned int)dp_peer_mlo_setup(
                         a1,
                         v15,
                         *(unsigned __int8 *)(v17 + 59),
                         (__int64 *)a4,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14) )
    {
      v47 = *(unsigned __int8 **)a4;
      if ( *(_QWORD *)a4 )
      {
        v49 = *v47;
        v50 = v47[1];
        v48 = v47[2];
        LODWORD(v47) = v47[5];
      }
      else
      {
        v48 = 0;
        v49 = 0;
        v50 = 0;
      }
      LODWORD(v58) = (_DWORD)v47;
      LODWORD(v57) = v48;
      LODWORD(v56) = v50;
      LODWORD(v55) = v49;
      qdf_trace_msg(
        0x81u,
        1u,
        "%s: peer mlo setup failed for link mac : %02x:%02x:%02x:**:**:%02xMLD Mac : %02x:%02x:%02x:**:**:%02x",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_peer_setup_wifi3",
        *(unsigned __int8 *)(v15 + 44),
        *(unsigned __int8 *)(v15 + 45),
        *(unsigned __int8 *)(v15 + 46),
        *(unsigned __int8 *)(v15 + 49),
        v55,
        v56,
        v57,
        v58);
      v51 = printk(
              &unk_AAA255,
              "0",
              "dp_peer_mlo_setup_err_assert",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_peer.h");
      dump_stack(v51);
      goto LABEL_29;
    }
    if ( v19 != 4 )
    {
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 1128) + 74576LL)
        && *(_DWORD *)(v15 + 408) == 1
        && (v41 = *(__int64 **)(v15 + 416)) != nullptr )
      {
        if ( a4 && (*(_BYTE *)(a4 + 8) & 1) != 0 )
          dp_peer_rx_init((__int64)v18, v41);
      }
      else
      {
        dp_peer_rx_init_wrapper((__int64)v18, (__int64 *)v15, a4);
      }
    }
    if ( *(_DWORD *)(v15 + 408) != 1 || (v42 = *(char ***)(v15 + 416)) == nullptr )
    {
LABEL_77:
      v30 = 0;
      goto LABEL_78;
    }
    v43 = *v42;
    if ( !*v42 )
    {
      v46 = *(_BYTE *)(v15 + 426);
LABEL_76:
      LODWORD(v56) = v46;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Peer %02x:%02x:%02x:**:**:%02x txrx_peer %pK local_link_id %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_peer_set_local_link_id",
        *(unsigned __int8 *)(v15 + 44),
        *(unsigned __int8 *)(v15 + 45),
        *(unsigned __int8 *)(v15 + 46),
        *(unsigned __int8 *)(v15 + 49),
        v43,
        v56);
      goto LABEL_77;
    }
    v44 = v43 + 2228;
    if ( !v43[2228] || (unsigned int)qdf_mem_cmp((const void *)(v15 + 44), v43 + 2232, 6u) )
    {
      if ( v43[2240] && !(unsigned int)qdf_mem_cmp((const void *)(v15 + 44), v43 + 2244, 6u) )
      {
        v44 = v43 + 2240;
      }
      else if ( v43[2252] && !(unsigned int)qdf_mem_cmp((const void *)(v15 + 44), v43 + 2256, 6u) )
      {
        v44 = v43 + 2252;
      }
      else
      {
        if ( !v43[2264] || (unsigned int)qdf_mem_cmp((const void *)(v15 + 44), v43 + 2268, 6u) )
        {
          v45 = *v44;
          if ( *v44 )
          {
            if ( v43[2240] )
            {
              if ( v43[2252] )
              {
                if ( v43[2264] )
                {
                  v46 = 0;
LABEL_75:
                  *(_BYTE *)(v15 + 426) = v46;
                  goto LABEL_76;
                }
                v45 = 3;
                v44 = v43 + 2264;
              }
              else
              {
                v45 = 2;
                v44 = v43 + 2252;
              }
            }
            else
            {
              v45 = 1;
              v44 = v43 + 2240;
            }
          }
          *v44 = 1;
          v53 = v44 + 4;
          v44[1] = v45;
          v52 = v44 + 1;
          qdf_mem_copy(v53, (const void *)(v15 + 44), 6u);
LABEL_74:
          v46 = *v52 + 1;
          goto LABEL_75;
        }
        v44 = v43 + 2264;
      }
    }
    v52 = v44 + 1;
    goto LABEL_74;
  }
  return 16;
}
