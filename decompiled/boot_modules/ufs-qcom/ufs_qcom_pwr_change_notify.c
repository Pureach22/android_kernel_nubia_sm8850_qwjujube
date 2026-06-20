__int64 __fastcall ufs_qcom_pwr_change_notify(__int64 a1, unsigned int a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int *v7; // x22
  __int64 v8; // x23
  __int64 v9; // x8
  int v10; // w8
  unsigned int v11; // w9
  __int64 v12; // x10
  unsigned int *v13; // x12
  __int64 v14; // x11
  __int64 v15; // x13
  __int64 v16; // x9
  __int64 v17; // x11
  __int64 v18; // x10
  int v19; // w8
  int v20; // w8
  unsigned int v21; // w8
  unsigned int v22; // w8
  __int64 v23; // x0
  unsigned int v24; // w11
  unsigned int v25; // w12
  unsigned int v26; // w10
  unsigned int v27; // w11
  unsigned int v28; // w11
  unsigned int v29; // w9
  int v30; // w8
  int v31; // w8
  unsigned int v32; // w8
  unsigned int v33; // w8
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 v36; // x3
  __int64 v37; // x8
  unsigned int v38; // w23
  unsigned int v39; // w26
  __int64 v40; // x24
  int tx_hs_equalizer; // w0
  int i; // w23
  __int64 v44; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v46; // x25
  __int64 (__fastcall *v47)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v48; // x0
  __int64 v49; // t1
  __int64 v50; // x8
  unsigned int v51; // [xsp+0h] [xbp-10h]
  unsigned int v52; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = v9;
  if ( !a1 )
  {
LABEL_77:
    __break(0x800u);
    v51 = v9;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v46 = qword_17478;
      if ( qword_17478 )
      {
        do
        {
          v47 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v46;
          v48 = *(_QWORD *)(v46 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v46 - 4LL) != 267372693 )
            __break(0x8228u);
          a1 = v47(v48, v5, v4, (unsigned int)v6, v51, (unsigned int)v7, (unsigned int)v8);
          v49 = *(_QWORD *)(v46 + 24);
          v46 += 24;
        }
        while ( v49 );
      }
      v50 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v50;
      if ( !v50 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(a1);
    }
    goto LABEL_67;
  }
  v6 = *(_QWORD *)(a1 + 184);
  v7 = a4;
  v4 = a2;
  v5 = a1;
  if ( a4 )
  {
    if ( a2 != 1 )
    {
      if ( a2 )
      {
        LODWORD(v8) = -22;
        v23 = *(_QWORD *)(v6 + 656);
        if ( !v23 )
          goto LABEL_67;
      }
      else
      {
        v10 = *(_DWORD *)(v6 + 352);
        v11 = a3[4];
        v12 = v6 + 304;
        if ( v10 != 2 )
        {
          v14 = 24;
          v15 = 4;
          v13 = (unsigned int *)(v6 + 304);
LABEL_25:
          v24 = *(_DWORD *)(v12 + v14);
          v25 = *v13;
          v26 = *(_DWORD *)(v12 + v15);
          a4[4] = v24;
          a4[5] = v24;
          v27 = a3[3];
          if ( v25 < v26 )
            v26 = v25;
          if ( v27 >= *(_DWORD *)(v6 + 324) )
            v27 = *(_DWORD *)(v6 + 324);
          a4[3] = v27;
          v28 = a3[2];
          if ( v28 >= *(_DWORD *)(v6 + 320) )
            v28 = *(_DWORD *)(v6 + 320);
          a4[2] = v28;
          if ( v11 != 1 || v10 == 2 )
          {
            v29 = *a3;
            if ( *a3 >= a3[1] )
              v29 = a3[1];
            if ( v29 >= v26 )
              v29 = v26;
            *a4 = v29;
            a4[1] = v29;
            if ( v10 != 2 || (*(_BYTE *)(v6 + 3140) & 1) == 0 )
              goto LABEL_40;
            dev_info(*(_QWORD *)(*(_QWORD *)(v6 + 16) + 64LL), "Gear limit active: setting to UFS_HS_G1\n");
            v26 = 1;
          }
          *v7 = v26;
          v7[1] = v26;
LABEL_40:
          v7[6] = *(_DWORD *)(v6 + 344);
          v30 = *(_DWORD *)(v5 + 2708);
          if ( v30 != 4 && v30 != 1 || (v31 = *(_DWORD *)(v5 + 2712), v31 != 1) && v31 != 4 )
          {
            v32 = v7[4];
            if ( v32 == 4 || v32 == 1 )
            {
              v33 = v7[5];
              if ( v33 == 4 || v33 == 1 )
              {
                v34 = *(_QWORD *)(v6 + 160);
                if ( v34 )
                {
                  if ( (*(_BYTE *)(v6 + 168) & 1) == 0 )
                  {
                    v35 = readl_relaxed(v34);
                    writel_relaxed(*(_DWORD *)(v6 + 180) | v35, *(_QWORD *)(v6 + 160));
                    readl(*(unsigned int **)(v6 + 160));
                    usleep_range_state(50, 60, 2);
                    *(_BYTE *)(v6 + 168) = 1;
                  }
                }
              }
            }
          }
          if ( *(unsigned __int8 *)(v6 + 174) >= 4u )
          {
            if ( v7[1] > 3 )
              v36 = 1;
            else
              v36 = 3;
            ufshcd_dme_set_attr(v5, 366215168, 0, v36, 0);
          }
          if ( (*(_BYTE *)(v5 + 222) & 2) != 0 )
          {
            v37 = *(_QWORD *)(v5 + 184);
            v38 = v7[1];
            v39 = v7[3];
            v52 = 0;
            v40 = *(_QWORD *)(v37 + 8);
            if ( (unsigned int)ufs_qcom_phy_tx_hs_equalizer_config(v40) )
            {
              tx_hs_equalizer = ufs_qcom_phy_get_tx_hs_equalizer(v40, v38, &v52);
              if ( v39 )
              {
                if ( !tx_hs_equalizer )
                {
                  for ( i = 0; i != v39; ++i )
                  {
                    if ( (unsigned int)ufshcd_dme_set_attr(v5, (unsigned __int16)i | 0x370000u, 0, v52, 0) )
                      dev_err(*(_QWORD *)(v5 + 64), "%s: failed equalizer lane %d\n", "ufs_qcom_set_tx_hs_equalizer", i);
                  }
                }
              }
            }
          }
          goto LABEL_64;
        }
        if ( v11 == 1 )
        {
          v13 = (unsigned int *)(v6 + 312);
          v14 = 32;
          v15 = 12;
          goto LABEL_25;
        }
        printk(&unk_1954D, "ufs_qcom_get_pwr_dev_param");
        dev_err(*(_QWORD *)(v5 + 64), "%s: failed to determine capabilities\n", "ufs_qcom_pwr_change_notify");
        LODWORD(v8) = -95;
        v23 = *(_QWORD *)(v6 + 656);
        if ( !v23 )
          goto LABEL_67;
      }
LABEL_65:
      if ( *(_BYTE *)(v6 + 664) == 1 )
        ipc_log_string(
          v23,
          ",%d,@,%d,%d,%d,%d,%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
          v4,
          *v7,
          v7[4],
          v7[6],
          v8);
      goto LABEL_67;
    }
    v8 = *(_QWORD *)(v6 + 8);
    ufs_qcom_cfg_timers(a1, 0);
    ufs_qcom_phy_set_tx_lane_enable(v8, (unsigned int)~(-1 << v7[3]));
    v17 = *((_QWORD *)v7 + 1);
    v16 = *((_QWORD *)v7 + 2);
    v18 = *(_QWORD *)v7;
    *(_DWORD *)(v6 + 88) = v7[6];
    *(_QWORD *)(v6 + 72) = v17;
    *(_QWORD *)(v6 + 80) = v16;
    *(_QWORD *)(v6 + 64) = v18;
    a1 = ((__int64 (__fastcall *)(__int64))ufs_qcom_icc_update_bw)(v6);
    v19 = *(_DWORD *)(v5 + 2708);
    if ( v19 == 4 || v19 == 1 )
    {
      v20 = *(_DWORD *)(v5 + 2712);
      if ( v20 == 4 || v20 == 1 )
      {
        if ( (v21 = v7[4], v21 != 4) && v21 != 1 || (v22 = v7[5], v22 != 1) && v22 != 4 )
          a1 = ufs_qcom_dev_ref_clk_ctrl(v6, 0);
      }
    }
    if ( (override_ber_threshold & 1) != 0 )
    {
LABEL_64:
      LODWORD(v8) = 0;
      v23 = *(_QWORD *)(v6 + 656);
      if ( !v23 )
        goto LABEL_67;
      goto LABEL_65;
    }
    v9 = *v7;
    if ( (unsigned int)v9 >= 6 )
    {
      __break(0x5512u);
    }
    else if ( ((8 * v9) | 4uLL) <= 0x30 )
    {
      LODWORD(v8) = 0;
      ber_threshold = ber_table[2 * v9 + 1];
      v23 = *(_QWORD *)(v6 + 656);
      if ( !v23 )
        goto LABEL_67;
      goto LABEL_65;
    }
    __break(1u);
    goto LABEL_77;
  }
  printk(&unk_19FF9, "ufs_qcom_pwr_change_notify");
  v44 = *(_QWORD *)(v6 + 656);
  if ( v44 && *(_BYTE *)(v6 + 664) == 1 )
    ipc_log_string(v44, ",%d,@,%d,%d,%d,%d,%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40), v4, 0, 0, 0, -22);
  LODWORD(v8) = -22;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v8;
}
