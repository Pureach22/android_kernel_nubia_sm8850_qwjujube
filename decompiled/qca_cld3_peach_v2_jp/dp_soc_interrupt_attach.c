__int64 __fastcall dp_soc_interrupt_attach(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x24
  __int64 v4; // x0
  char v5; // w23
  char host2rxdma_mon_ring_mask; // w26
  int v7; // w28
  int v8; // w25
  int v9; // w20
  char host2txmon_ring_mask; // w27
  char v11; // w22
  unsigned int (*v12)(void); // x8
  unsigned int (*v13)(void); // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  unsigned int v23; // w20
  unsigned __int8 napi_scale_factor; // w0
  unsigned __int8 v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  __int64 result; // x0
  __int64 v36; // [xsp+8h] [xbp-A8h]
  unsigned __int64 v37; // [xsp+10h] [xbp-A0h]
  char v38; // [xsp+1Ch] [xbp-94h]
  char rxdma2host_ring_mask; // [xsp+20h] [xbp-90h]
  char v40; // [xsp+24h] [xbp-8Ch]
  char v41; // [xsp+28h] [xbp-88h]
  char v42; // [xsp+2Ch] [xbp-84h]
  char v43; // [xsp+30h] [xbp-80h]
  char v44; // [xsp+34h] [xbp-7Ch]
  char v45; // [xsp+38h] [xbp-78h]
  unsigned int v46; // [xsp+3Ch] [xbp-74h] BYREF
  _QWORD v47[12]; // [xsp+40h] [xbp-70h] BYREF
  int v48; // [xsp+A0h] [xbp-10h]
  __int64 v49; // [xsp+A8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v36 = a1 + 11400;
  qdf_mem_set((void *)(a1 + 11400), 8u, -1);
  if ( (int)wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40)) < 1 )
  {
LABEL_24:
    ((void (__fastcall *)(_QWORD))hif_configure_ext_group_interrupts)(*(_QWORD *)(a1 + 64));
    result = 0;
  }
  else
  {
    v2 = 0;
    v37 = 0;
    v3 = a1 + 7800;
    while ( 1 )
    {
      v4 = *(_QWORD *)(a1 + 40);
      v48 = 0;
      memset(v47, 0, sizeof(v47));
      v45 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_cfg_get_tx_ring_mask)(v4, (unsigned int)v2);
      v44 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_ring_mask)(*(_QWORD *)(a1 + 40), (unsigned int)v2);
      v5 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_mon_ring_mask)(
             *(_QWORD *)(a1 + 40),
             (unsigned int)v2);
      v43 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_mon_ring_mask)(
              *(_QWORD *)(a1 + 40),
              (unsigned int)v2);
      v42 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_err_ring_mask)(
              *(_QWORD *)(a1 + 40),
              (unsigned int)v2);
      v41 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_wbm_rel_ring_mask)(
              *(_QWORD *)(a1 + 40),
              (unsigned int)v2);
      v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_reo_status_ring_mask)(
              *(_QWORD *)(a1 + 40),
              (unsigned int)v2);
      rxdma2host_ring_mask = wlan_cfg_get_rxdma2host_ring_mask(*(_QWORD *)(a1 + 40), (unsigned int)v2);
      v38 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_host2rxdma_ring_mask)(
              *(_QWORD *)(a1 + 40),
              (unsigned int)v2);
      host2rxdma_mon_ring_mask = wlan_cfg_get_host2rxdma_mon_ring_mask(*(_QWORD *)(a1 + 40), (unsigned int)v2);
      v7 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_near_full_grp_1_mask)(
             *(_QWORD *)(a1 + 40),
             (unsigned int)v2);
      v8 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_near_full_grp_2_mask)(
             *(_QWORD *)(a1 + 40),
             (unsigned int)v2);
      v9 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_ring_near_full_mask)(
             *(_QWORD *)(a1 + 40),
             (unsigned int)v2);
      host2txmon_ring_mask = wlan_cfg_get_host2txmon_ring_mask(*(_QWORD *)(a1 + 40), (unsigned int)v2);
      v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_umac_reset_intr_mask)(
              *(_QWORD *)(a1 + 40),
              (unsigned int)v2);
      v12 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
      if ( *((_DWORD *)v12 - 1) != 1696218653 )
        __break(0x8228u);
      if ( v12() != 4 )
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 817LL) != 1 )
          goto LABEL_13;
        v13 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
        if ( !v13 )
          goto LABEL_13;
        if ( *((_DWORD *)v13 - 1) != 1696218653 )
          __break(0x8228u);
        if ( v13() || (*(_BYTE *)(a1 + 20216) & 0x10) != 0 )
LABEL_13:
          v5 = 0;
      }
      if ( v2 == 18 )
LABEL_27:
        __break(0x5512u);
      *(_BYTE *)(v3 + 32) = v2;
      *(_BYTE *)(v3 + 1) = v44;
      *(_BYTE *)v3 = v45;
      *(_BYTE *)(v3 + 3) = v42;
      *(_BYTE *)(v3 + 2) = v5;
      *(_BYTE *)(v3 + 8) = host2rxdma_mon_ring_mask;
      *(_BYTE *)(v3 + 6) = rxdma2host_ring_mask;
      *(_BYTE *)(v3 + 7) = v38;
      *(_BYTE *)(v3 + 9) = v7;
      *(_BYTE *)(v3 + 10) = v8;
      *(_BYTE *)(v3 + 5) = v40;
      *(_BYTE *)(v3 + 4) = v41;
      *(_BYTE *)(v3 + 11) = v9;
      *(_BYTE *)(v3 + 13) = v43;
      *(_BYTE *)(v3 + 12) = host2txmon_ring_mask;
      *(_BYTE *)(v3 + 192) = v11;
      *(_QWORD *)(v3 + 16) = a1;
      v46 = 0;
      dp_soc_interrupt_map_calculate(a1, v2, v47, &v46);
      v22 = v8 | v7 | v9;
      v23 = 0;
      if ( !v22 )
      {
        napi_scale_factor = wlan_cfg_get_napi_scale_factor(*(_QWORD *)(a1 + 40));
        if ( napi_scale_factor )
          v25 = napi_scale_factor;
        else
          v25 = 4;
        v23 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD *, __int64 (__fastcall *)(__int64), __int64, const char *, _QWORD, _QWORD))hif_register_ext_group)(
                *(_QWORD *)(a1 + 64),
                v46,
                v47,
                dp_service_srngs_wrapper,
                v3,
                "dp_intr",
                0,
                v25);
      }
      qdf_trace_msg(
        0x45u,
        8u,
        "%s:  int ctx %u num_irq %u irq_id_map %u %u",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "dp_soc_interrupt_attach",
        (unsigned int)v2,
        v46,
        LODWORD(v47[0]),
        HIDWORD(v47[0]));
      if ( v23 )
        break;
      hif_event_history_init(*(_QWORD *)(a1 + 64), v2);
      v34 = *(unsigned __int8 *)(v3 + 2);
      *(_QWORD *)(v3 + 24) = 0;
      if ( v34 )
      {
        if ( v37 > 1 )
          goto LABEL_27;
        *(_DWORD *)(v36 + 4 * v37++) = v2;
      }
      ++v2;
      v3 += 200;
      if ( v2 >= (int)wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40)) )
        goto LABEL_24;
    }
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: failed, ret = %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "dp_soc_interrupt_attach",
      a1,
      v23);
    ((void (__fastcall *)(__int64))dp_soc_interrupt_detach)(a1);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
