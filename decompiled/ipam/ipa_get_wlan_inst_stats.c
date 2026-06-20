__int64 __fastcall ipa_get_wlan_inst_stats(unsigned __int64 a1)
{
  int v2; // w8
  __int64 v3; // x22
  unsigned int *v4; // x0
  unsigned int *v5; // x21
  unsigned __int64 v6; // x25
  int *v7; // x26
  _DWORD *v8; // x20
  __int64 v9; // x22
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int v12; // w11
  int v13; // w10
  int v14; // w9
  _DWORD *v15; // x22
  unsigned int v16; // w8
  _DWORD *v17; // x23
  int v18; // w9
  _DWORD *v19; // x23
  unsigned int v20; // w8
  unsigned int ep_mapping; // w0
  unsigned int v22; // w0
  unsigned int v23; // w0
  unsigned int v24; // w0
  unsigned int v25; // w0
  unsigned int v26; // w0
  __int64 v27; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x9
  __int64 result; // x0
  __int64 v41; // x0
  __int64 ipc_logbuf; // x0
  __int64 v43; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  unsigned __int64 v56; // [xsp+0h] [xbp-F0h]
  __int64 v57; // [xsp+8h] [xbp-E8h]
  __int64 v58; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v59; // [xsp+18h] [xbp-D8h]
  __int64 v60; // [xsp+20h] [xbp-D0h]
  __int64 v61; // [xsp+28h] [xbp-C8h]
  __int64 v62; // [xsp+30h] [xbp-C0h]
  __int64 v63; // [xsp+38h] [xbp-B8h]
  __int64 v64; // [xsp+40h] [xbp-B0h]
  __int64 v65; // [xsp+48h] [xbp-A8h]
  __int64 v66; // [xsp+50h] [xbp-A0h]
  __int64 v67; // [xsp+58h] [xbp-98h]
  __int64 v68; // [xsp+60h] [xbp-90h]
  __int64 v69; // [xsp+68h] [xbp-88h]
  __int64 v70; // [xsp+70h] [xbp-80h]
  __int64 v71; // [xsp+78h] [xbp-78h]
  __int64 v72; // [xsp+80h] [xbp-70h]
  __int64 v73; // [xsp+88h] [xbp-68h]
  __int64 v74; // [xsp+90h] [xbp-60h]
  __int64 v75; // [xsp+98h] [xbp-58h]
  __int64 v76; // [xsp+A0h] [xbp-50h]
  __int64 v77; // [xsp+A8h] [xbp-48h]
  __int64 v78; // [xsp+B0h] [xbp-40h]
  __int64 v79; // [xsp+B8h] [xbp-38h]
  __int64 v80; // [xsp+C0h] [xbp-30h]
  __int64 v81; // [xsp+C8h] [xbp-28h]
  __int64 v82; // [xsp+D0h] [xbp-20h]
  char v83; // [xsp+D8h] [xbp-18h]
  __int64 v84; // [xsp+E0h] [xbp-10h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v58 = 0;
  if ( (dword_2011F8 & 4) == 0 )
  {
    v41 = printk(&unk_3CA2EB, "ipa_get_wlan_inst_stats");
    ipc_logbuf = ipa3_get_ipc_logbuf(v41);
    if ( ipc_logbuf )
    {
      v43 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v43,
                     "ipa-lnx-stats %s:%d Log type WLAN mask not set\n",
                     "ipa_get_wlan_inst_stats",
                     623);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v45 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v45, "ipa-lnx-stats %s:%d Log type WLAN mask not set\n", "ipa_get_wlan_inst_stats", 623);
    }
    goto LABEL_84;
  }
  v2 = 40 * dword_201208 + 8;
  if ( dword_201208 )
  {
    if ( (unsigned int)(dword_201208 - 3) < 0xFFFFFFFE )
LABEL_86:
      __break(0x5512u);
    v2 += 56 * HIDWORD(qword_20124C) + 48 * dword_201254 + 120 * qword_20124C;
    if ( dword_201208 != 1 )
      v2 += 56 * dword_201290 + 48 * dword_201294 + 120 * dword_20128C;
  }
  v3 = v2;
  v4 = (unsigned int *)memdup_user(a1, v2);
  if ( (unsigned __int64)v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    v46 = printk(&unk_3C7866, "ipa_get_wlan_inst_stats");
    v47 = ipa3_get_ipc_logbuf(v46);
    if ( v47 )
    {
      v48 = ipa3_get_ipc_logbuf(v47);
      v47 = ipc_log_string(v48, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_wlan_inst_stats", 643);
    }
    v49 = ipa3_get_ipc_logbuf_low(v47);
    if ( v49 )
    {
      v50 = ipa3_get_ipc_logbuf_low(v49);
      ipc_log_string(v50, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_wlan_inst_stats", 643);
    }
    result = 4294967284LL;
    goto LABEL_85;
  }
  v5 = v4;
  v56 = a1;
  v57 = v3;
  if ( !dword_201208 )
  {
LABEL_61:
    v27 = v57;
    if ( (v57 & 0x80000000) != 0 )
    {
      __break(0x800u);
    }
    else
    {
      _check_object_size(v5, v57, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v29 = v56, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v29 = v56 & ((__int64)(v56 << 8) >> 8);
      if ( 0x8000000000LL - v57 >= v29 )
      {
        v30 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v36 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v36 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v36);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v30);
        v27 = _arch_copy_to_user(v56 & 0xFF7FFFFFFFFFFFFFLL, v5, v57);
        v37 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v39 - 4096);
        _WriteStatusReg(TTBR1_EL1, v39);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v37);
      }
      if ( !v27 )
      {
        kfree(v5);
        result = 0;
LABEL_85:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
    v51 = printk(&unk_3B576A, "ipa_get_wlan_inst_stats");
    v52 = ipa3_get_ipc_logbuf(v51);
    if ( v52 )
    {
      v53 = ipa3_get_ipc_logbuf(v52);
      v52 = ipc_log_string(v53, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_wlan_inst_stats", 782);
    }
    v54 = ipa3_get_ipc_logbuf_low(v52);
    if ( v54 )
    {
      v55 = ipa3_get_ipc_logbuf_low(v54);
      ipc_log_string(v55, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_wlan_inst_stats", 782);
    }
LABEL_83:
    kfree(v5);
LABEL_84:
    result = 4294967282LL;
    goto LABEL_85;
  }
  if ( (unsigned int)v3 >= 4 )
  {
    v6 = 0;
    v7 = &dword_201254;
    *v4 = dword_201208;
    v8 = v4 + 2;
    while ( 1 )
    {
      if ( v6 == 2 )
        goto LABEL_86;
      v8[6] = *(v7 - 2);
      v8[8] = *(v7 - 1);
      v8[9] = *v7;
      if ( (unsigned int)ipa3_get_wdi3_gsi_stats(&v58) )
      {
        v9 = 120LL * (unsigned int)v8[6];
        v10 = (__int64)&v8[14 * v8[8] + 10 + 12 * v8[9]];
        goto LABEL_11;
      }
      *v8 = v6;
      v8[1] = ipa_get_wdi_version();
      v11 = ipa3_ctx + 28672;
      v12 = (unsigned __int8)(*(_BYTE *)(ipa3_ctx + 32388) - *(_BYTE *)(ipa3_ctx + 32392));
      v13 = (unsigned __int8)(*(_DWORD *)(ipa3_ctx + 32396) - *(_DWORD *)(ipa3_ctx + 32400));
      if ( v12 <= 2 )
        break;
      if ( v12 != 3 )
      {
        if ( v12 == 4 )
        {
          v14 = 6;
          goto LABEL_30;
        }
LABEL_23:
        if ( (unsigned __int8)(*(_BYTE *)(ipa3_ctx + 32388) - *(_BYTE *)(ipa3_ctx + 32392)) > 4u )
          v14 = 6;
        else
          v14 = 7;
        goto LABEL_30;
      }
      if ( v13 == 1 )
        v14 = 5;
      else
        v14 = 4;
LABEL_30:
      v8[2] = v14;
      v8[3] = *(unsigned __int8 *)(v11 + 3594);
      v8[4] = ipa_wdi_is_tx1_used() & 1;
      v8[5] = ((__int64 (__fastcall *)(_QWORD))ipa_pm_get_pm_clnt_throughput)((unsigned int)*(v7 - 8));
      v15 = v8 + 10;
      if ( *(v7 - 1) )
      {
        *v15 = *(v7 - 8);
        v8[11] = HIDWORD(v60);
        *((_QWORD *)v8 + 6) = v61;
        *((_QWORD *)v8 + 7) = v62;
        ipa_lnx_calculate_gsi_ring_summay(v8 + 10, 0);
        *((_QWORD *)v8 + 9) = 0;
        *((_QWORD *)v8 + 10) = 0;
        *((_QWORD *)v8 + 8) = 0;
        v16 = *(v7 - 1);
        if ( v16 >= 2 )
        {
          v8[24] = *(v7 - 7);
          *(_QWORD *)(v8 + 25) = v63;
          *(_QWORD *)(v8 + 27) = v64;
          v8[29] = v65;
          ipa_lnx_calculate_gsi_ring_summay(v8 + 24, 0);
          *((_QWORD *)v8 + 16) = 0;
          *((_QWORD *)v8 + 17) = 0;
          *((_QWORD *)v8 + 15) = 0;
          v16 = *(v7 - 1);
          if ( v16 >= 3 )
          {
            v8[38] = *(v7 - 6);
            v8[39] = HIDWORD(v65);
            *((_QWORD *)v8 + 20) = v66;
            *((_QWORD *)v8 + 21) = v67;
            ipa_lnx_calculate_gsi_ring_summay(v8 + 38, 0);
            *((_QWORD *)v8 + 23) = 0;
            *((_QWORD *)v8 + 24) = 0;
            *((_QWORD *)v8 + 22) = 0;
            v16 = *(v7 - 1);
            if ( v16 > 3 )
              goto LABEL_86;
          }
        }
        if ( *v7 )
        {
LABEL_35:
          v17 = &v15[14 * v16];
          *v17 = *(v7 - 5);
          *(_QWORD *)(v17 + 1) = v58;
          *(_QWORD *)(v17 + 3) = v59;
          *(_QWORD *)(v17 + 5) = (unsigned int)v60;
          ipa_lnx_calculate_gsi_ring_summay(0, v17);
          *(_QWORD *)(v17 + 9) = 0;
          *(_QWORD *)(v17 + 7) = 0;
          v18 = *v7;
          if ( (unsigned int)*v7 >= 2 )
          {
            v17[12] = *(v7 - 4);
            v17[13] = HIDWORD(v60);
            *((_QWORD *)v17 + 7) = v61;
            v17[16] = v62;
            *(_QWORD *)(v17 + 17) = HIDWORD(v62);
            ipa_lnx_calculate_gsi_ring_summay(0, v17 + 12);
            *(_QWORD *)(v17 + 21) = 0;
            *(_QWORD *)(v17 + 19) = 0;
            v18 = *v7;
            if ( (unsigned int)*v7 >= 3 )
            {
              v17[24] = *(v7 - 3);
              v19 = v17 + 24;
              *(_QWORD *)(v19 + 1) = v63;
              *(_QWORD *)(v19 + 3) = v64;
              *(_QWORD *)(v19 + 5) = (unsigned int)v65;
              ipa_lnx_calculate_gsi_ring_summay(0, v19);
              *(_QWORD *)(v19 + 9) = 0;
              *(_QWORD *)(v19 + 7) = 0;
              v18 = *v7;
              if ( (unsigned int)*v7 > 3 )
                goto LABEL_86;
            }
          }
          v16 = *(v7 - 1);
          goto LABEL_41;
        }
      }
      else
      {
        v16 = 0;
        if ( *v7 )
          goto LABEL_35;
      }
      v18 = 0;
LABEL_41:
      v9 = (__int64)&v15[14 * v16 + 12 * v18];
      v20 = v8[6];
      if ( v20 )
      {
        ep_mapping = ipa_get_ep_mapping((unsigned int)*(v7 - 14));
        if ( ep_mapping == -1 )
          goto LABEL_83;
        *(_DWORD *)(v9 + 76) = ep_mapping;
        if ( ep_mapping > 0x24 )
          goto LABEL_86;
        ipa_get_gsi_pipe_info(v9, ipa3_ctx + 480LL * ep_mapping + 168);
        v20 = v8[6];
        if ( v20 >= 2 )
        {
          v22 = ipa_get_ep_mapping((unsigned int)*(v7 - 13));
          if ( v22 == -1 )
            goto LABEL_83;
          *(_DWORD *)(v9 + 196) = v22;
          if ( v22 > 0x24 )
            goto LABEL_86;
          ipa_get_gsi_pipe_info(v9 + 120, ipa3_ctx + 480LL * v22 + 168);
          v20 = v8[6];
          if ( v20 >= 3 )
          {
            v23 = ipa_get_ep_mapping((unsigned int)*(v7 - 12));
            if ( v23 == -1 )
              goto LABEL_83;
            *(_DWORD *)(v9 + 316) = v23;
            if ( v23 > 0x24 )
              goto LABEL_86;
            ipa_get_gsi_pipe_info(v9 + 240, ipa3_ctx + 480LL * v23 + 168);
            v20 = v8[6];
            if ( v20 >= 4 )
            {
              v24 = ipa_get_ep_mapping((unsigned int)*(v7 - 11));
              if ( v24 == -1 )
                goto LABEL_83;
              *(_DWORD *)(v9 + 436) = v24;
              if ( v24 > 0x24 )
                goto LABEL_86;
              ipa_get_gsi_pipe_info(v9 + 360, ipa3_ctx + 480LL * v24 + 168);
              v20 = v8[6];
              if ( v20 >= 5 )
              {
                v25 = ipa_get_ep_mapping((unsigned int)*(v7 - 10));
                if ( v25 == -1 )
                  goto LABEL_83;
                *(_DWORD *)(v9 + 556) = v25;
                if ( v25 > 0x24 )
                  goto LABEL_86;
                ipa_get_gsi_pipe_info(v9 + 480, ipa3_ctx + 480LL * v25 + 168);
                v20 = v8[6];
                if ( v20 >= 6 )
                {
                  v26 = ipa_get_ep_mapping((unsigned int)*(v7 - 9));
                  if ( v26 == -1 )
                    goto LABEL_83;
                  *(_DWORD *)(v9 + 676) = v26;
                  if ( v26 > 0x24 )
                    goto LABEL_86;
                  ipa_get_gsi_pipe_info(v9 + 600, ipa3_ctx + 480LL * v26 + 168);
                  v20 = v8[6];
                  if ( v20 > 6 )
                    goto LABEL_86;
                }
              }
            }
          }
        }
      }
      v10 = 120 * v20;
LABEL_11:
      ++v6;
      v8 = (_DWORD *)(v10 + v9);
      v7 += 16;
      if ( v6 >= *v5 )
        goto LABEL_61;
    }
    if ( v12 == 1 )
    {
      v14 = 2 * (v13 == 1);
      goto LABEL_30;
    }
    if ( v12 == 2 )
    {
      if ( v13 == 1 )
        v14 = 3;
      else
        v14 = 1;
      goto LABEL_30;
    }
    goto LABEL_23;
  }
  __break(1u);
  return ipa_get_eth_inst_stats(v4);
}
