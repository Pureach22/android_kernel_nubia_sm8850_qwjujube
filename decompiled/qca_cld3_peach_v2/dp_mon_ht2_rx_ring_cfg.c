void __fastcall dp_mon_ht2_rx_ring_cfg(__int64 a1, unsigned __int8 *a2, int a3, int *a4)
{
  int num_mac_rings; // w0
  __int64 *v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int (*v18)(void); // x8
  unsigned int (*v19)(void); // x8
  int v20; // w24
  unsigned __int8 *v21; // x28
  int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w8
  __int64 v32; // x4
  int v33; // w3
  __int64 v34; // x2
  int v35; // w0
  int v36; // w27
  int v37; // w0
  int v38; // w26
  int v39; // w23
  unsigned int v40; // w26
  __int64 v41; // x8
  int v42; // w3
  __int64 *v43; // x8
  __int64 v44; // x2
  __int64 *v45; // [xsp+0h] [xbp-30h]
  int target_type; // [xsp+20h] [xbp-10h]
  int v47; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  num_mac_rings = wlan_cfg_get_num_mac_rings(*((_QWORD *)a2 + 36));
  v9 = *(__int64 **)(a1 + 1128);
  v47 = num_mac_rings;
  target_type = hal_get_target_type(v9);
  if ( a3 == 1 )
  {
    v19 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
    if ( !v19 )
      goto LABEL_15;
    if ( *((_DWORD *)v19 - 1) != 1696218653 )
      __break(0x8228u);
    if ( !v19() && (*(_BYTE *)(a1 + 20272) & 0x10) != 0 )
      v47 = 1;
    else
LABEL_15:
      dp_update_num_mac_rings_for_dbs(a1, &v47, v10, v11, v12, v13, v14, v15, v16, v17);
LABEL_16:
    qdf_trace_msg(
      0x73u,
      5u,
      "%s: %pK: srng type %d Max_mac_rings %d ",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_mon_ht2_rx_ring_cfg",
      a1,
      (unsigned int)a3,
      (unsigned int)v47);
    if ( v47 < 1 )
      goto LABEL_72;
    v21 = a2 + 112;
    v20 = *a2;
    v22 = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40));
    v31 = v20;
    if ( v22 )
    {
      if ( v20 )
        goto LABEL_74;
      v31 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 72) + 1LL);
    }
    v45 = (__int64 *)(a1 + 80);
    if ( a3 > 1 )
    {
      if ( a3 == 2 )
      {
        if ( v31 <= 1 )
        {
          v32 = 1664;
          v33 = 16;
          v34 = *(_QWORD *)(a1 + 480 + 80LL * v31);
          if ( !v34 )
            goto LABEL_41;
          goto LABEL_40;
        }
      }
      else
      {
        if ( a3 != 3 )
          goto LABEL_72;
        if ( v31 <= 1 )
        {
          v32 = 1664;
          v33 = 18;
          v34 = *(_QWORD *)(a1 + 640 + 80LL * v31);
          if ( !v34 )
            goto LABEL_41;
          goto LABEL_40;
        }
      }
    }
    else if ( a3 )
    {
      if ( a3 != 1 )
        goto LABEL_72;
      if ( v31 <= 1 )
      {
        v32 = 1408;
        v33 = 17;
        v34 = *(_QWORD *)(a1 + 800 + 80LL * v31);
        if ( !v34 )
          goto LABEL_41;
        goto LABEL_40;
      }
    }
    else if ( target_type == 36 )
    {
      if ( !v31 )
      {
        v32 = 1664;
        v33 = 14;
        v34 = *v45;
        if ( !*v45 )
          goto LABEL_41;
        goto LABEL_40;
      }
    }
    else if ( v31 <= 1 )
    {
      v32 = 1664;
      v33 = 14;
      v34 = *(_QWORD *)&v21[80 * v31];
      if ( !v34 )
      {
LABEL_41:
        if ( v47 < 2 )
          goto LABEL_72;
        v36 = 1;
        while ( 1 )
        {
          if ( *a2 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Both mac_id and pdev_id cannot be non zero",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "dp_get_mac_id_for_pdev",
              v32);
            v38 = *a2;
            v39 = 0;
          }
          else
          {
            v38 = 0;
            v39 = v36;
          }
          if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40)) )
          {
            if ( v38 )
              goto LABEL_74;
            v40 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 72) + 1LL);
          }
          else if ( v38 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Both mac_id and pdev_id cannot be non zero",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "dp_get_lmac_id_for_pdev_id");
            v40 = 0;
          }
          else
          {
            v40 = v36;
          }
          if ( a3 > 1 )
            break;
          if ( a3 )
          {
            _const_udelay(429500);
            if ( v40 > 1 )
              goto LABEL_74;
            v41 = a1 + 800;
            v32 = 1408;
            v42 = 17;
            goto LABEL_66;
          }
          if ( target_type == 36 )
          {
            if ( v40 )
              goto LABEL_74;
            v43 = (__int64 *)(a1 + 80);
          }
          else
          {
            if ( v40 > 1 )
              goto LABEL_74;
            v43 = (__int64 *)&v21[80 * v40];
          }
          v32 = 1664;
          v42 = 14;
          v44 = *v43;
          if ( *v43 )
          {
LABEL_43:
            htt_h2t_rx_ring_cfg(*(_QWORD **)(a1 + 48), v39, v44, v42, v32, a4);
            if ( v37 )
              goto LABEL_72;
          }
LABEL_44:
          if ( ++v36 >= v47 )
            goto LABEL_72;
        }
        if ( a3 == 2 )
        {
          if ( v40 > 1 )
            goto LABEL_74;
          v41 = a1 + 480;
          v32 = 1664;
          v42 = 16;
        }
        else
        {
          if ( v40 > 1 )
            goto LABEL_74;
          v41 = a1 + 640;
          v32 = 1664;
          v42 = 18;
        }
LABEL_66:
        v44 = *(_QWORD *)(v41 + 80LL * v40);
        if ( v44 )
          goto LABEL_43;
        goto LABEL_44;
      }
LABEL_40:
      htt_h2t_rx_ring_cfg(*(_QWORD **)(a1 + 48), v20, v34, v33, v32, a4);
      if ( v35 )
        goto LABEL_72;
      goto LABEL_41;
    }
LABEL_74:
    __break(0x5512u);
  }
  if ( a3 )
    goto LABEL_16;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 817LL) != 1 )
    goto LABEL_16;
  v18 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
  if ( !v18 )
    goto LABEL_16;
  if ( *((_DWORD *)v18 - 1) != 1696218653 )
    __break(0x8228u);
  if ( v18() || (*(_BYTE *)(a1 + 20272) & 0x10) != 0 )
    goto LABEL_16;
  qdf_trace_msg(
    0x73u,
    5u,
    "%s: skip rxdma_buf filter cfg for lpc mode",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "dp_mon_ht2_rx_ring_cfg");
LABEL_72:
  _ReadStatusReg(SP_EL0);
}
