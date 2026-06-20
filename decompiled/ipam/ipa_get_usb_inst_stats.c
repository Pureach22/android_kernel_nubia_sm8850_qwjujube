__int64 __fastcall ipa_get_usb_inst_stats(unsigned __int64 a1)
{
  int v2; // w8
  __int64 v3; // x22
  unsigned int *v4; // x0
  __int64 v5; // x1
  int v6; // w8
  unsigned int *v7; // x20
  unsigned __int64 v8; // x25
  _DWORD *v9; // x21
  int *v10; // x26
  __int64 v11; // x8
  __int64 v12; // x22
  _DWORD *v13; // x22
  unsigned int v14; // w8
  _DWORD *v15; // x23
  int v16; // w9
  _DWORD *v17; // x23
  unsigned int v18; // w8
  unsigned int ep_mapping; // w0
  unsigned int v20; // w0
  unsigned int v21; // w0
  unsigned int v22; // w0
  unsigned int v23; // w0
  unsigned int v24; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x0
  unsigned __int64 v28; // x9
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v37; // x9
  __int64 result; // x0
  __int64 v39; // x0
  __int64 ipc_logbuf; // x0
  __int64 v41; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  unsigned __int64 v54; // [xsp+0h] [xbp-F0h]
  __int64 v55; // [xsp+8h] [xbp-E8h]
  __int64 v56; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v57; // [xsp+18h] [xbp-D8h]
  __int64 v58; // [xsp+20h] [xbp-D0h]
  __int64 v59; // [xsp+28h] [xbp-C8h]
  __int64 v60; // [xsp+30h] [xbp-C0h]
  __int64 v61; // [xsp+38h] [xbp-B8h]
  __int64 v62; // [xsp+40h] [xbp-B0h]
  __int64 v63; // [xsp+48h] [xbp-A8h]
  __int64 v64; // [xsp+50h] [xbp-A0h]
  __int64 v65; // [xsp+58h] [xbp-98h]
  __int64 v66; // [xsp+60h] [xbp-90h]
  __int64 v67; // [xsp+68h] [xbp-88h]
  __int64 v68; // [xsp+70h] [xbp-80h]
  __int64 v69; // [xsp+78h] [xbp-78h]
  __int64 v70; // [xsp+80h] [xbp-70h]
  __int64 v71; // [xsp+88h] [xbp-68h]
  __int64 v72; // [xsp+90h] [xbp-60h]
  __int64 v73; // [xsp+98h] [xbp-58h]
  __int64 v74; // [xsp+A0h] [xbp-50h]
  __int64 v75; // [xsp+A8h] [xbp-48h]
  __int64 v76; // [xsp+B0h] [xbp-40h]
  __int64 v77; // [xsp+B8h] [xbp-38h]
  __int64 v78; // [xsp+C0h] [xbp-30h]
  __int64 v79; // [xsp+C8h] [xbp-28h]
  __int64 v80; // [xsp+D0h] [xbp-20h]
  char v81; // [xsp+D8h] [xbp-18h]
  __int64 v82; // [xsp+E0h] [xbp-10h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
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
  v57 = 0;
  v58 = 0;
  v56 = 0;
  if ( (dword_2011F8 & 0x10) == 0 )
  {
    v39 = printk(&unk_3A4172, "ipa_get_usb_inst_stats");
    ipc_logbuf = ipa3_get_ipc_logbuf(v39);
    if ( ipc_logbuf )
    {
      v41 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v41,
                     "ipa-lnx-stats %s:%d Log type USB mask not set\n",
                     "ipa_get_usb_inst_stats",
                     1120);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v43 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v43, "ipa-lnx-stats %s:%d Log type USB mask not set\n", "ipa_get_usb_inst_stats", 1120);
    }
    goto LABEL_68;
  }
  v2 = 24 * dword_201210 + 8;
  if ( dword_201210 )
  {
    if ( (unsigned int)(dword_201210 - 3) < 0xFFFFFFFE )
LABEL_70:
      __break(0x5512u);
    v2 += 56 * dword_201350 + 48 * dword_201354 + 120 * dword_20134C;
    if ( dword_201210 != 1 )
      v2 += 56 * dword_201390 + 48 * dword_201394 + 120 * dword_20138C;
  }
  v3 = v2;
  v4 = (unsigned int *)memdup_user(a1, v2);
  if ( (unsigned __int64)v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    v44 = printk(&unk_3C7866, "ipa_get_usb_inst_stats");
    v45 = ipa3_get_ipc_logbuf(v44);
    if ( v45 )
    {
      v46 = ipa3_get_ipc_logbuf(v45);
      v45 = ipc_log_string(v46, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_usb_inst_stats", 1140);
    }
    v47 = ipa3_get_ipc_logbuf_low(v45);
    if ( v47 )
    {
      v48 = ipa3_get_ipc_logbuf_low(v47);
      ipc_log_string(v48, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_usb_inst_stats", 1140);
    }
    result = 4294967284LL;
    goto LABEL_69;
  }
  v54 = a1;
  v55 = v3;
  if ( (unsigned int)v3 >= 4 )
  {
    v6 = dword_201210;
    v7 = v4;
    *v4 = dword_201210;
    if ( v6 )
    {
      v8 = 0;
      v9 = v4 + 2;
      v10 = &dword_201354;
      do
      {
        *v9 = v8;
        if ( v8 == 2 )
          goto LABEL_70;
        v9[1] = ipa_lnx_agent_ctx[v8];
        v9[2] = ((__int64 (__fastcall *)(_QWORD))ipa_pm_get_pm_clnt_throughput)((unsigned int)*(v10 - 8));
        v9[3] = *(v10 - 2);
        v9[4] = *(v10 - 1);
        v9[5] = *v10;
        v13 = v9 + 6;
        if ( (unsigned int)ipa3_get_usb_gsi_stats(&v56) )
        {
          v11 = (__int64)&v13[14 * v9[4] + 12 * v9[5]];
          v12 = 120LL * (unsigned int)v9[3];
          goto LABEL_11;
        }
        if ( *(v10 - 1) )
        {
          *v13 = *(v10 - 8);
          v9[7] = HIDWORD(v58);
          *((_QWORD *)v9 + 4) = v59;
          *((_QWORD *)v9 + 5) = v60;
          ipa_lnx_calculate_gsi_ring_summay(v9 + 6, 0);
          *((_QWORD *)v9 + 7) = 0;
          *((_QWORD *)v9 + 8) = 0;
          *((_QWORD *)v9 + 6) = 0;
          v14 = *(v10 - 1);
          if ( v14 >= 2 )
          {
            v9[20] = *(v10 - 7);
            *(_QWORD *)(v9 + 21) = v61;
            *(_QWORD *)(v9 + 23) = v62;
            v9[25] = v63;
            ipa_lnx_calculate_gsi_ring_summay(v9 + 20, 0);
            *((_QWORD *)v9 + 14) = 0;
            *((_QWORD *)v9 + 15) = 0;
            *((_QWORD *)v9 + 13) = 0;
            v14 = *(v10 - 1);
            if ( v14 >= 3 )
            {
              v9[34] = *(v10 - 6);
              v9[35] = HIDWORD(v63);
              *((_QWORD *)v9 + 18) = v64;
              *((_QWORD *)v9 + 19) = v65;
              ipa_lnx_calculate_gsi_ring_summay(v9 + 34, 0);
              *((_QWORD *)v9 + 21) = 0;
              *((_QWORD *)v9 + 22) = 0;
              *((_QWORD *)v9 + 20) = 0;
              v14 = *(v10 - 1);
              if ( v14 > 3 )
                goto LABEL_70;
            }
          }
          if ( *v10 )
          {
LABEL_19:
            v15 = &v13[14 * v14];
            *v15 = *(v10 - 5);
            *(_QWORD *)(v15 + 1) = v56;
            *(_QWORD *)(v15 + 3) = v57;
            *(_QWORD *)(v15 + 5) = (unsigned int)v58;
            ipa_lnx_calculate_gsi_ring_summay(0, v15);
            *(_QWORD *)(v15 + 9) = 0;
            *(_QWORD *)(v15 + 7) = 0;
            v16 = *v10;
            if ( (unsigned int)*v10 >= 2 )
            {
              v15[12] = *(v10 - 4);
              v15[13] = HIDWORD(v58);
              *((_QWORD *)v15 + 7) = v59;
              v15[16] = v60;
              *(_QWORD *)(v15 + 17) = HIDWORD(v60);
              ipa_lnx_calculate_gsi_ring_summay(0, v15 + 12);
              *(_QWORD *)(v15 + 21) = 0;
              *(_QWORD *)(v15 + 19) = 0;
              v16 = *v10;
              if ( (unsigned int)*v10 >= 3 )
              {
                v15[24] = *(v10 - 3);
                v17 = v15 + 24;
                *(_QWORD *)(v17 + 1) = v61;
                *(_QWORD *)(v17 + 3) = v62;
                *(_QWORD *)(v17 + 5) = (unsigned int)v63;
                ipa_lnx_calculate_gsi_ring_summay(0, v17);
                *(_QWORD *)(v17 + 9) = 0;
                *(_QWORD *)(v17 + 7) = 0;
                v16 = *v10;
                if ( (unsigned int)*v10 > 3 )
                  goto LABEL_70;
              }
            }
            v14 = *(v10 - 1);
            goto LABEL_25;
          }
        }
        else
        {
          v14 = 0;
          if ( *v10 )
            goto LABEL_19;
        }
        v16 = 0;
LABEL_25:
        v12 = (__int64)&v13[14 * v14 + 12 * v16];
        v18 = v9[3];
        if ( v18 )
        {
          ep_mapping = ipa_get_ep_mapping((unsigned int)*(v10 - 14));
          if ( ep_mapping == -1 )
            goto LABEL_67;
          *(_DWORD *)(v12 + 76) = ep_mapping;
          if ( ep_mapping > 0x24 )
            goto LABEL_70;
          ipa_get_gsi_pipe_info(v12, ipa3_ctx + 480LL * ep_mapping + 168);
          v18 = v9[3];
          if ( v18 >= 2 )
          {
            v20 = ipa_get_ep_mapping((unsigned int)*(v10 - 13));
            if ( v20 == -1 )
              goto LABEL_67;
            *(_DWORD *)(v12 + 196) = v20;
            if ( v20 > 0x24 )
              goto LABEL_70;
            ipa_get_gsi_pipe_info(v12 + 120, ipa3_ctx + 480LL * v20 + 168);
            v18 = v9[3];
            if ( v18 >= 3 )
            {
              v21 = ipa_get_ep_mapping((unsigned int)*(v10 - 12));
              if ( v21 == -1 )
                goto LABEL_67;
              *(_DWORD *)(v12 + 316) = v21;
              if ( v21 > 0x24 )
                goto LABEL_70;
              ipa_get_gsi_pipe_info(v12 + 240, ipa3_ctx + 480LL * v21 + 168);
              v18 = v9[3];
              if ( v18 >= 4 )
              {
                v22 = ipa_get_ep_mapping((unsigned int)*(v10 - 11));
                if ( v22 == -1 )
                  goto LABEL_67;
                *(_DWORD *)(v12 + 436) = v22;
                if ( v22 > 0x24 )
                  goto LABEL_70;
                ipa_get_gsi_pipe_info(v12 + 360, ipa3_ctx + 480LL * v22 + 168);
                v18 = v9[3];
                if ( v18 >= 5 )
                {
                  v23 = ipa_get_ep_mapping((unsigned int)*(v10 - 10));
                  if ( v23 == -1 )
                    goto LABEL_67;
                  *(_DWORD *)(v12 + 556) = v23;
                  if ( v23 > 0x24 )
                    goto LABEL_70;
                  ipa_get_gsi_pipe_info(v12 + 480, ipa3_ctx + 480LL * v23 + 168);
                  v18 = v9[3];
                  if ( v18 >= 6 )
                  {
                    v24 = ipa_get_ep_mapping((unsigned int)*(v10 - 9));
                    if ( v24 == -1 )
                      goto LABEL_67;
                    *(_DWORD *)(v12 + 676) = v24;
                    if ( v24 > 0x24 )
                      goto LABEL_70;
                    ipa_get_gsi_pipe_info(v12 + 600, ipa3_ctx + 480LL * v24 + 168);
                    v18 = v9[3];
                    if ( v18 > 6 )
                      goto LABEL_70;
                  }
                }
              }
            }
          }
        }
        v11 = 120 * v18;
LABEL_11:
        ++v8;
        v9 = (_DWORD *)(v11 + v12);
        v10 += 16;
      }
      while ( v8 < *v7 );
    }
    if ( (v55 & 0x80000000) != 0 )
    {
      __break(0x800u);
    }
    else
    {
      _check_object_size(v7, v55, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v26 = v54, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v26 = v54 & ((__int64)(v54 << 8) >> 8);
      v27 = 1;
      if ( 0x8000000000LL - v55 >= v26 )
      {
        v28 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v34 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v34 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v34);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v28);
        v27 = _arch_copy_to_user(v54 & 0xFF7FFFFFFFFFFFFFLL, v7, v55);
        v35 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v37 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v37 - 4096);
        _WriteStatusReg(TTBR1_EL1, v37);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v35);
      }
      if ( !v27 )
      {
        kfree(v7);
        result = 0;
LABEL_69:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
    v49 = printk(&unk_3B576A, "ipa_get_usb_inst_stats");
    v50 = ipa3_get_ipc_logbuf(v49);
    if ( v50 )
    {
      v51 = ipa3_get_ipc_logbuf(v50);
      v50 = ipc_log_string(v51, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_usb_inst_stats", 1273);
    }
    v52 = ipa3_get_ipc_logbuf_low(v50);
    if ( v52 )
    {
      v53 = ipa3_get_ipc_logbuf_low(v52);
      ipc_log_string(v53, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_usb_inst_stats", 1273);
    }
LABEL_67:
    kfree(v7);
LABEL_68:
    result = 4294967282LL;
    goto LABEL_69;
  }
  __break(1u);
  return ipa_lnx_calculate_gsi_ring_summay(v4, v5);
}
