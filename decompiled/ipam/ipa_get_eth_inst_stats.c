__int64 __fastcall ipa_get_eth_inst_stats(unsigned __int64 a1)
{
  unsigned int *v1; // x24
  int v3; // w8
  __int64 v4; // x21
  unsigned int *v5; // x0
  int v6; // w8
  __int64 v7; // x11
  _DWORD *v8; // x25
  unsigned int *v9; // x23
  unsigned int v10; // w8
  unsigned int *v11; // x27
  unsigned int *v12; // x19
  unsigned int v13; // w9
  unsigned __int64 v14; // x22
  unsigned __int64 v15; // x8
  unsigned int v16; // w8
  int v17; // w8
  unsigned int *v18; // x0
  unsigned int v19; // w8
  unsigned int v20; // w28
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  signed int v27; // w22
  unsigned int *v28; // x24
  unsigned int v29; // w8
  int *v30; // x28
  unsigned int *v31; // x1
  int v32; // w2
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned int *v38; // x27
  unsigned int ep_mapping; // w0
  unsigned int v40; // w0
  unsigned int v41; // w0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v46; // x9
  __int64 v47; // x0
  unsigned __int64 v48; // x9
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  unsigned __int64 v57; // x9
  __int64 result; // x0
  __int64 v59; // x0
  __int64 ipc_logbuf; // x0
  __int64 v61; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  unsigned __int64 v74; // [xsp+0h] [xbp-100h]
  __int64 v75; // [xsp+8h] [xbp-F8h]
  unsigned int *v76; // [xsp+10h] [xbp-F0h]
  __int64 v77; // [xsp+18h] [xbp-E8h]
  __int64 v78; // [xsp+20h] [xbp-E0h] BYREF
  __int64 v79; // [xsp+28h] [xbp-D8h]
  __int64 v80; // [xsp+30h] [xbp-D0h]
  __int64 v81; // [xsp+38h] [xbp-C8h]
  __int64 v82; // [xsp+40h] [xbp-C0h]
  __int64 v83; // [xsp+48h] [xbp-B8h]
  __int64 v84; // [xsp+50h] [xbp-B0h]
  __int64 v85; // [xsp+58h] [xbp-A8h]
  __int64 v86; // [xsp+60h] [xbp-A0h]
  __int64 v87; // [xsp+68h] [xbp-98h]
  __int64 v88; // [xsp+70h] [xbp-90h]
  __int64 v89; // [xsp+78h] [xbp-88h]
  __int64 v90; // [xsp+80h] [xbp-80h]
  __int64 v91; // [xsp+88h] [xbp-78h]
  __int64 v92; // [xsp+90h] [xbp-70h]
  __int64 v93; // [xsp+98h] [xbp-68h]
  __int64 v94; // [xsp+A0h] [xbp-60h]
  __int64 v95; // [xsp+A8h] [xbp-58h]
  __int64 v96; // [xsp+B0h] [xbp-50h]
  __int64 v97; // [xsp+B8h] [xbp-48h]
  __int64 v98; // [xsp+C0h] [xbp-40h]
  __int64 v99; // [xsp+C8h] [xbp-38h]
  __int64 v100; // [xsp+D0h] [xbp-30h]
  __int64 v101; // [xsp+D8h] [xbp-28h]
  __int64 v102; // [xsp+E0h] [xbp-20h]
  char v103; // [xsp+E8h] [xbp-18h]
  __int64 v104; // [xsp+F0h] [xbp-10h]

  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v103 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v78 = 0;
  if ( (dword_2011F8 & 8) == 0 )
  {
    v59 = printk(&unk_3F5B97, "ipa_get_eth_inst_stats");
    ipc_logbuf = ipa3_get_ipc_logbuf(v59);
    if ( ipc_logbuf )
    {
      v61 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v61, "ipa-lnx-stats %s:%d Log type ETH mask not set\n", "ipa_get_eth_inst_stats", 808);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v63 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v63, "ipa-lnx-stats %s:%d Log type ETH mask not set\n", "ipa_get_eth_inst_stats", 808);
    }
    goto LABEL_95;
  }
  v3 = 24 * dword_20120C + 8;
  if ( dword_20120C )
  {
    if ( (unsigned int)(dword_20120C - 3) < 0xFFFFFFFE )
    {
LABEL_71:
      __break(0x5512u);
LABEL_72:
      if ( (v75 & 0x80000000) != 0 )
      {
        __break(0x800u);
      }
      else
      {
        _check_object_size(v1, v75, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v46 = v74, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v46 = v74 & ((__int64)(v74 << 8) >> 8);
        v47 = 1;
        if ( 0x8000000000LL - v75 >= v46 )
        {
          v48 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v54 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v54 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v54);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v48);
          v47 = _arch_copy_to_user(v74 & 0xFF7FFFFFFFFFFFFFLL, v1, v75);
          v55 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v57 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v57 - 4096);
          _WriteStatusReg(TTBR1_EL1, v57);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v55);
        }
        if ( !v47 )
        {
          kfree(v1);
          result = 0;
LABEL_96:
          _ReadStatusReg(SP_EL0);
          return result;
        }
      }
      v69 = printk(&unk_3B576A, "ipa_get_eth_inst_stats");
      v70 = ipa3_get_ipc_logbuf(v69);
      if ( v70 )
      {
        v71 = ipa3_get_ipc_logbuf(v70);
        v70 = ipc_log_string(v71, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_eth_inst_stats", 1094);
      }
      v72 = ipa3_get_ipc_logbuf_low(v70);
      if ( v72 )
      {
        v73 = ipa3_get_ipc_logbuf_low(v72);
        ipc_log_string(v73, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_eth_inst_stats", 1094);
      }
LABEL_94:
      kfree(v1);
LABEL_95:
      result = 4294967282LL;
      goto LABEL_96;
    }
    v3 += 56 * HIDWORD(qword_2012CC) + 48 * dword_2012D4 + 120 * qword_2012CC;
    if ( dword_20120C != 1 )
      v3 += 56 * HIDWORD(qword_20130C) + 48 * dword_201314 + 120 * qword_20130C;
  }
  v4 = v3;
  v5 = (unsigned int *)memdup_user(a1, v3);
  if ( (unsigned __int64)v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    v64 = printk(&unk_3C7866, "ipa_get_eth_inst_stats");
    v65 = ipa3_get_ipc_logbuf(v64);
    if ( v65 )
    {
      v66 = ipa3_get_ipc_logbuf(v65);
      v65 = ipc_log_string(v66, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_eth_inst_stats", 828);
    }
    v67 = ipa3_get_ipc_logbuf_low(v65);
    if ( v67 )
    {
      v68 = ipa3_get_ipc_logbuf_low(v67);
      ipc_log_string(v68, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_eth_inst_stats", 828);
    }
    result = 4294967284LL;
    goto LABEL_96;
  }
  v74 = a1;
  v75 = v4;
  if ( (unsigned int)v4 >= 4 )
  {
    v6 = dword_20120C;
    v1 = v5;
    *v5 = dword_20120C;
    if ( v6 )
    {
      v7 = 0;
      v8 = &unk_2012B4;
      v9 = v5 + 2;
      v76 = v5;
      while ( 1 )
      {
        v77 = v7;
        *v9 = v7;
        if ( v7 == 2 )
          goto LABEL_71;
        v11 = v9 + 6;
        v12 = &ipa_lnx_agent_ctx[16 * v7];
        v9[3] = v12[55];
        v9[4] = v12[56];
        v13 = v12[57];
        v9[5] = v13;
        if ( v12[56] )
          break;
        v15 = 0;
LABEL_36:
        v26 = 14 * v15;
        if ( v13 )
        {
          v27 = 0;
          v28 = &v11[v26];
          do
          {
            v29 = v9[1];
            if ( v29 > 5 )
            {
              v33 = printk(&unk_3E6DB1, "ipa_get_eth_inst_stats");
              v34 = ipa3_get_ipc_logbuf(v33);
              if ( v34 )
              {
                v35 = ipa3_get_ipc_logbuf(v34);
                v34 = ipc_log_string(
                        v35,
                        "ipa-lnx-stats %s:%d Eth rx client type not found",
                        "ipa_get_eth_inst_stats",
                        1057);
              }
              v36 = ipa3_get_ipc_logbuf_low(v34);
              if ( v36 )
              {
                v37 = ipa3_get_ipc_logbuf_low(v36);
                ipc_log_string(v37, "ipa-lnx-stats %s:%d Eth rx client type not found", "ipa_get_eth_inst_stats", 1057);
              }
            }
            else
            {
              v30 = (int *)&v28[12 * v27];
              if ( ((1 << v29) & 0x33) != 0 )
              {
                v31 = &v28[12 * v27];
                if ( (v29 & 0xFFFFFFFE) == 4 )
                  v32 = 48;
                else
                  v32 = 102;
                *v30 = v32;
              }
              else
              {
                v31 = &v28[12 * v27];
                *v30 = 108;
              }
              *(_QWORD *)(v30 + 1) = v78;
              *(_QWORD *)(v30 + 3) = v79;
              *(_QWORD *)(v30 + 5) = (unsigned int)v80;
              ipa_lnx_calculate_gsi_ring_summay(0, v31);
              *(_QWORD *)(v30 + 9) = 0;
              *(_QWORD *)(v30 + 7) = 0;
            }
            v13 = v12[57];
            ++v27;
          }
          while ( v27 < v13 );
          v1 = v76;
          v26 = 14LL * v12[56];
        }
        v38 = &v11[12 * v13 + v26];
        if ( v9[3] )
        {
          ep_mapping = ipa_get_ep_mapping(v12[43]);
          if ( ep_mapping == -1 )
            goto LABEL_94;
          v38[19] = ep_mapping;
          if ( ep_mapping > 0x24 )
            goto LABEL_71;
          ipa_get_gsi_pipe_info(v38, ipa3_ctx + 480LL * ep_mapping + 168);
          v10 = v9[3];
          if ( v10 >= 2 )
          {
            v40 = ipa_get_ep_mapping(v12[44]);
            if ( v40 == -1 )
              goto LABEL_94;
            v38[49] = v40;
            if ( v40 > 0x24 )
              goto LABEL_71;
            ipa_get_gsi_pipe_info(v38 + 30, ipa3_ctx + 480LL * v40 + 168);
            v10 = v9[3];
            if ( v10 >= 3 )
            {
              v41 = ipa_get_ep_mapping(v12[45]);
              if ( v41 == -1 )
                goto LABEL_94;
              v38[79] = v41;
              if ( v41 > 0x24 )
                goto LABEL_71;
              ipa_get_gsi_pipe_info(v38 + 60, ipa3_ctx + 480LL * v41 + 168);
              v10 = v9[3];
              if ( v10 >= 4 )
              {
                v42 = ipa_get_ep_mapping(v12[46]);
                if ( v42 == -1 )
                  goto LABEL_94;
                v38[109] = v42;
                if ( v42 > 0x24 )
                  goto LABEL_71;
                ipa_get_gsi_pipe_info(v38 + 90, ipa3_ctx + 480LL * v42 + 168);
                v10 = v9[3];
                if ( v10 >= 5 )
                {
                  v43 = ipa_get_ep_mapping(v12[47]);
                  if ( v43 == -1 )
                    goto LABEL_94;
                  v38[139] = v43;
                  if ( v43 > 0x24 )
                    goto LABEL_71;
                  ipa_get_gsi_pipe_info(v38 + 120, ipa3_ctx + 480LL * v43 + 168);
                  v10 = v9[3];
                  if ( v10 >= 6 )
                  {
                    v44 = ipa_get_ep_mapping(v12[48]);
                    if ( v44 == -1 )
                      goto LABEL_94;
                    v38[169] = v44;
                    if ( v44 > 0x24 )
                      goto LABEL_71;
                    ipa_get_gsi_pipe_info(v38 + 150, ipa3_ctx + 480LL * v44 + 168);
                    v10 = v9[3];
                    if ( v10 > 6 )
                      goto LABEL_71;
                  }
                }
              }
            }
          }
        }
        else
        {
          v10 = 0;
        }
        v8 += 16;
        v7 = v77 + 1;
        v9 = &v38[30 * v10];
        if ( v77 + 1 >= (unsigned __int64)*v1 )
          goto LABEL_72;
      }
      v14 = 0;
      while ( 1 )
      {
        if ( v14 == 3 )
          goto LABEL_71;
        v16 = v8[v14];
        v9[1] = v16;
        if ( v16 > 5 )
        {
          v21 = printk(&unk_3B5737, "ipa_get_eth_inst_stats");
          v22 = ipa3_get_ipc_logbuf(v21);
          if ( v22 )
          {
            v23 = ipa3_get_ipc_logbuf(v22);
            v22 = ipc_log_string(v23, "ipa-lnx-stats %s:%d Eth tx client type not found", "ipa_get_eth_inst_stats", 976);
          }
          v24 = ipa3_get_ipc_logbuf_low(v22);
          if ( v24 )
          {
            v25 = ipa3_get_ipc_logbuf_low(v24);
            ipc_log_string(v25, "ipa-lnx-stats %s:%d Eth tx client type not found", "ipa_get_eth_inst_stats", 976);
          }
          goto LABEL_17;
        }
        v17 = 1 << v16;
        if ( (v17 & 0x23) != 0 )
        {
          if ( !(unsigned int)ipa3_get_aqc_gsi_stats(&v78) )
            goto LABEL_25;
        }
        else if ( (v17 & 0xC) != 0 )
        {
          if ( !(unsigned int)ipa3_get_rtk_gsi_stats((__int64)&v78) )
          {
            v9[2] = ((__int64 (__fastcall *)(__int64))ipa_pm_get_pm_clnt_throughput)(109);
            v18 = v11;
            *v11 = 109;
            *(_QWORD *)(v11 + 1) = v83;
            *(_QWORD *)(v11 + 3) = v84;
            v19 = v85;
LABEL_29:
            v11[5] = v19;
            ipa_lnx_calculate_gsi_ring_summay(v18, 0);
            *((_QWORD *)v11 + 4) = 0;
            *((_QWORD *)v11 + 5) = 0;
            *((_QWORD *)v11 + 3) = 0;
            goto LABEL_17;
          }
        }
        else if ( !(unsigned int)ipa3_get_ntn_gsi_stats(&v78) )
        {
LABEL_25:
          if ( (v9[1] & 0xFFFFFFFE) == 4 )
            v20 = 49;
          else
            v20 = 103;
          *v11 = v20;
          v9[2] = ((__int64 (__fastcall *)(_QWORD))ipa_pm_get_pm_clnt_throughput)(v20);
          v18 = v11;
          v11[1] = HIDWORD(v80);
          *((_QWORD *)v11 + 1) = v81;
          v11[4] = v82;
          v19 = HIDWORD(v82);
          goto LABEL_29;
        }
        v9 += 30 * v9[3] + 14 * v9[4] + 12 * v9[5] + 6;
LABEL_17:
        v15 = v12[56];
        ++v14;
        v11 += 14;
        if ( v14 >= v15 )
        {
          v13 = v12[57];
          v11 = v9 + 6;
          goto LABEL_36;
        }
      }
    }
    goto LABEL_72;
  }
  __break(1u);
  return ipa_get_usb_inst_stats(v5);
}
