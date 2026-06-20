__int64 __fastcall dp_soc_interrupt_map_calculate(__int64 a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v7; // x8
  int v8; // w24
  int v9; // w25
  int v10; // w26
  int v11; // w27
  int v12; // w28
  int rxdma2host_ring_mask; // w0
  __int64 v14; // x8
  __int64 v15; // x22
  int v16; // w19
  int v17; // w23
  int host2rxdma_mon_ring_mask; // w0
  __int64 v19; // x1
  int v20; // w21
  int host2txmon_ring_mask; // w0
  __int64 v22; // x8
  int v23; // w22
  __int64 result; // x0
  int v25; // w9
  char v26; // w8
  int v27; // w10
  int v28; // w16
  int v29; // w1
  int v30; // w2
  int v31; // w27
  int v32; // w28
  int v33; // w24
  int v34; // w25
  int v35; // w22
  int v36; // w23
  int v37; // [xsp+Ch] [xbp-54h]
  int v38; // [xsp+10h] [xbp-50h]
  int v39; // [xsp+14h] [xbp-4Ch]
  int v40; // [xsp+18h] [xbp-48h]
  int v41; // [xsp+1Ch] [xbp-44h]
  int v42; // [xsp+20h] [xbp-40h]
  int v43; // [xsp+24h] [xbp-3Ch]
  int v44; // [xsp+28h] [xbp-38h]
  unsigned int v45; // [xsp+2Ch] [xbp-34h]
  __int64 v46; // [xsp+30h] [xbp-30h]
  int v47; // [xsp+3Ch] [xbp-24h]
  int v48; // [xsp+3Ch] [xbp-24h]
  int v50; // [xsp+4Ch] [xbp-14h] BYREF
  _QWORD v51[2]; // [xsp+50h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 24);
  v51[0] = 0;
  v50 = 0;
  if ( (unsigned int)pld_get_user_msi_assignment(
                       *(_QWORD *)(v7 + 40),
                       (__int64)"DP",
                       (__int64)v51 + 4,
                       (__int64)v51,
                       (__int64)&v50) )
  {
    v47 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v8 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v9 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_mon_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v10 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_err_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_wbm_rel_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v12 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_reo_status_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    rxdma2host_ring_mask = wlan_cfg_get_rxdma2host_ring_mask(*(_QWORD *)(a1 + 40), a2);
    v14 = *(_QWORD *)(a1 + 40);
    v15 = a1;
    v46 = a1;
    v16 = rxdma2host_ring_mask;
    v17 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_cfg_get_host2rxdma_ring_mask)(v14, a2);
    host2rxdma_mon_ring_mask = wlan_cfg_get_host2rxdma_mon_ring_mask(*(_QWORD *)(v15 + 40), a2);
    v19 = a2;
    v45 = a2;
    v20 = host2rxdma_mon_ring_mask;
    host2txmon_ring_mask = wlan_cfg_get_host2txmon_ring_mask(*(_QWORD *)(v15 + 40), v19);
    v22 = *(_QWORD *)(v15 + 40);
    v23 = host2txmon_ring_mask;
    result = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_cfg_get_tx_mon_ring_mask)(v22, v45);
    v25 = 0;
    v26 = 0;
    v27 = 55;
    *(_BYTE *)(v46 + 17784) = 0;
    do
    {
      v28 = 1 << v26;
      if ( ((1 << v26) & v47) != 0 )
        a3[v25++] = v27 - 4;
      if ( (v28 & v8) != 0 )
        a3[v25++] = v27 - 27;
      if ( (v28 & v16) != 0 )
        a3[v25++] = v27 - 12;
      if ( (v28 & v17) != 0 )
        a3[v25++] = v27 - 15;
      if ( (v28 & v20) != 0 )
        a3[v25++] = v27 - 34;
      if ( (v28 & v9) != 0 )
      {
        v29 = v25 + 1;
        a3[v25] = v27 - 21;
        v30 = v25 + 2;
        v25 += 3;
        a3[v29] = v27 - 18;
        a3[v30] = v27 - 24;
      }
      if ( (v28 & v11) != 0 )
        a3[v25++] = 23;
      if ( (v28 & v10) != 0 )
        a3[v25++] = 22;
      if ( (v28 & v12) != 0 )
        a3[v25++] = 24;
      if ( (v28 & v23) != 0 )
        a3[v25++] = 56;
      if ( (v28 & (unsigned int)result) != 0 )
        a3[v25++] = v27;
      --v27;
      ++v26;
    }
    while ( v27 != 30 );
  }
  else
  {
    v37 = HIDWORD(v51[0]);
    v38 = v50;
    v48 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v44 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v43 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_mon_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v42 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_mon_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v41 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_err_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_wbm_rel_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v39 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_reo_status_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v31 = wlan_cfg_get_rxdma2host_ring_mask(*(_QWORD *)(a1 + 40), a2);
    v32 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_host2rxdma_ring_mask)(*(_QWORD *)(a1 + 40), a2);
    v33 = wlan_cfg_get_host2rxdma_mon_ring_mask(*(_QWORD *)(a1 + 40), a2);
    v34 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_near_full_grp_1_mask)(*(_QWORD *)(a1 + 40), a2);
    v35 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_near_full_grp_2_mask)(*(_QWORD *)(a1 + 40), a2);
    v36 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_ring_near_full_mask)(*(_QWORD *)(a1 + 40), a2);
    result = wlan_cfg_get_host2txmon_ring_mask(*(_QWORD *)(a1 + 40), a2);
    *(_BYTE *)(a1 + 17784) = 1;
    if ( v44 | v48 | v43 | v42 | v41 | v40 | v39 | v31 | v32 | v33 | v34 | v35 | v36 | (unsigned int)result )
    {
      result = pld_get_msi_irq(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), (int)a2 % v37 + v38);
      v25 = 1;
      *a3 = result;
    }
    else
    {
      v25 = 0;
    }
  }
  *a4 = v25;
  _ReadStatusReg(SP_EL0);
  return result;
}
