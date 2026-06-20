__int64 __fastcall ipa3_usb_request_xdci_channel(__int64 *a1, int a2, unsigned int *a3)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w24
  __int64 v16; // x22
  int v17; // w8
  int v18; // w10
  int v19; // w9
  char v20; // w8
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 ipc_logbuf; // x0
  __int64 v26; // x0
  unsigned int v27; // w0
  __int64 v28; // x8
  _QWORD *v29; // x10
  _QWORD *v30; // x8
  _QWORD *v31; // x22
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x11
  __int64 v35; // x12
  __int64 v36; // x9
  __int64 v37; // x10
  __int64 v38; // x11
  __int64 v39; // x12
  __int64 result; // x0
  unsigned int v41; // w0
  unsigned int v42; // w19
  int v43; // w10
  __int64 v44; // x13
  char v45; // w8
  __int64 v46; // x12
  unsigned int hw_type; // w0
  bool v48; // zf
  char v49; // w10
  int v50; // w11
  int v51; // w10
  int v52; // w9
  char v53; // w8
  unsigned int v54; // w0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  unsigned int v58; // w19
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x20
  const char *v62; // x0
  __int64 v63; // x0
  unsigned int v64; // w8
  __int64 v65; // x19
  const char *v66; // x4
  __int64 v67; // x0
  unsigned int v68; // w8
  const char *v69; // x4
  __int64 v70; // x0
  unsigned int v71; // w8
  const char *v72; // x4
  __int64 v73; // x0
  __int64 v74; // x0
  unsigned int v75; // w20
  __int64 v76; // x0
  __int64 v77; // x0
  _QWORD v78[64]; // [xsp+0h] [xbp-200h] BYREF

  v78[63] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v78, 0, 0x1F8u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa3_usb_request_xdci_channel", 1126);
  }
  if ( !a1 || !a3 )
    goto LABEL_96;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v7,
      "ipa_usb %s:%d gevntcount_low_addr = %x\n",
      "ipa3_usb_check_chan_params",
      984,
      *((_DWORD *)a1 + 2));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v8,
      "ipa_usb %s:%d gevntcount_hi_addr = %x\n",
      "ipa3_usb_check_chan_params",
      986,
      *((unsigned __int8 *)a1 + 12));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v9 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v9, "ipa_usb %s:%d dir = %d\n", "ipa3_usb_check_chan_params", 987, *((_DWORD *)a1 + 4));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v10 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v10,
      "ipa_usb %s:%d xfer_ring_len = %d\n",
      "ipa3_usb_check_chan_params",
      988,
      *((unsigned __int16 *)a1 + 10));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v11,
      "ipa_usb %s:%d last_trb_addr_iova = %x\n",
      "ipa3_usb_check_chan_params",
      990,
      *((unsigned __int16 *)a1 + 12));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v12,
      "ipa_usb %s:%d const_buffer_size = %d\n",
      "ipa3_usb_check_chan_params",
      992,
      *((unsigned __int8 *)a1 + 26));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v13 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v13, "ipa_usb %s:%d depcmd_low_addr = %x\n", "ipa3_usb_check_chan_params", 994, *((_DWORD *)a1 + 7));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v14,
      "ipa_usb %s:%d depcmd_hi_addr = %x\n",
      "ipa3_usb_check_chan_params",
      996,
      *((unsigned __int8 *)a1 + 32));
  }
  v15 = *((_DWORD *)a1 + 1);
  if ( v15 > 5 || (*((_WORD *)a1 + 10) & 0xF) != 0 || (unsigned int)*((unsigned __int8 *)a1 + 26) - 32 <= 0xFFFFFFE0 )
  {
    printk(&unk_3FCC4E, "ipa3_usb_check_chan_params");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d Invalid params\n", "ipa3_usb_check_chan_params", 1003);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_usb %s:%d Invalid params\n", "ipa3_usb_check_chan_params", 1003);
    }
    goto LABEL_96;
  }
  if ( ((1 << v15) & 0x13) != 0 )
  {
    if ( *(_DWORD *)(ipa3_usb_ctx + 72LL * v15 + 56) == 2 )
    {
      printk(&unk_3B9A6A, "ipa3_usb_check_chan_params");
      if ( ipa3_get_ipc_logbuf() )
      {
        v61 = ipa3_get_ipc_logbuf();
        v62 = ipa3_usb_teth_prot_to_string(*((_DWORD *)a1 + 1));
        ipc_log_string(v61, "ipa_usb %s:%d %s is not initialized\n", "ipa3_usb_check_chan_params", 1016, v62);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v63 = ipa3_get_ipc_logbuf_low();
        v64 = *((_DWORD *)a1 + 1);
        v65 = v63;
        v66 = ipa3_usb_teth_prot_to_string(v64);
        ipc_log_string(v65, "ipa_usb %s:%d %s is not initialized\n", "ipa3_usb_check_chan_params", 1016, v66);
      }
LABEL_96:
      printk(&unk_3AB53C, "ipa3_usb_request_xdci_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v73 = ipa3_get_ipc_logbuf();
        ipc_log_string(v73, "ipa_usb %s:%d bad parameters\n", "ipa3_usb_request_xdci_channel", 1129);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v74 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v74, "ipa_usb %s:%d bad parameters\n", "ipa3_usb_request_xdci_channel", 1129);
      }
      result = 4294967274LL;
      goto LABEL_101;
    }
  }
  else if ( *(_DWORD *)(ipa3_usb_ctx + 72LL * v15 + 56) == 2 )
  {
    printk(&unk_3B9A6A, "ipa3_usb_check_chan_params");
    if ( ipa3_get_ipc_logbuf() )
    {
      v67 = ipa3_get_ipc_logbuf();
      v68 = *((_DWORD *)a1 + 1) - 2;
      if ( v68 > 3 )
        v69 = "unsupported";
      else
        v69 = off_1E5298[v68];
      ipc_log_string(v67, "ipa_usb %s:%d %s is not initialized\n", "ipa3_usb_check_chan_params", 1029, v69);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v70 = ipa3_get_ipc_logbuf_low();
      v71 = *((_DWORD *)a1 + 1) - 2;
      if ( v71 > 3 )
        v72 = "unsupported";
      else
        v72 = off_1E5298[v71];
      ipc_log_string(v70, "ipa_usb %s:%d %s is not initialized\n", "ipa3_usb_check_chan_params", 1029, v72);
    }
    goto LABEL_96;
  }
  if ( v15 == 4 )
    v16 = 1;
  else
    v16 = 2 * (unsigned int)(v15 == 5);
  if ( (ipa3_usb_check_legal_op(1, v16) & 1) != 0 )
  {
    memset(v78, 0, 0x1F8u);
    v17 = *((_DWORD *)a1 + 1);
    v18 = *((_DWORD *)a1 + 4);
    if ( v17 == 4 )
      v19 = 27;
    else
      v19 = 19;
    if ( v18 == 1 )
      v19 = 18;
    LODWORD(v78[24]) = v19;
    if ( v17 <= 1 )
    {
      v21 = ipa3_usb_ctx + 72LL * v15;
      if ( (unsigned int)v17 > 1 )
        goto LABEL_54;
      v78[25] = *(_QWORD *)(v21 + 40);
      if ( v18 )
        v22 = 8;
      else
        v22 = 16;
      v78[26] = *(_QWORD *)(v21 + v22);
      v20 = *(_BYTE *)(v21 + 48);
    }
    else
    {
      if ( (unsigned int)(v17 - 2) < 2 )
      {
        v24 = *(_QWORD *)(ipa3_usb_ctx + 440);
        v23 = *(_QWORD *)(ipa3_usb_ctx + 448);
        LOBYTE(v78[27]) = *(_BYTE *)(ipa3_usb_ctx + 460);
        v78[25] = v23;
        v78[26] = v24;
        goto LABEL_54;
      }
      if ( v17 == 4 )
      {
        v20 = 1;
        v78[25] = 0;
        v78[26] = 0;
      }
      else
      {
        if ( v17 != 5 )
          goto LABEL_54;
        v78[25] = *(_QWORD *)(ipa3_usb_ctx + 472);
        v78[26] = *(_QWORD *)(ipa3_usb_ctx + 464);
        v20 = *(_BYTE *)(ipa3_usb_ctx + 484);
      }
    }
    LOBYTE(v78[27]) = v20;
LABEL_54:
    v27 = ipa3_usb_smmu_map_xdci_channel(a1, 1);
    if ( v27 )
    {
      v58 = v27;
      printk(&unk_3FCC27, "ipa3_usb_request_xdci_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v59 = ipa3_get_ipc_logbuf();
        ipc_log_string(v59, "ipa_usb %s:%d failed to smmu map %d\n", "ipa3_usb_request_xdci_channel", 1198, v58);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v60 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v60, "ipa_usb %s:%d failed to smmu map %d\n", "ipa3_usb_request_xdci_channel", 1198, v58);
      }
      result = v58;
    }
    else
    {
      v28 = ipa3_usb_ctx + (v16 << 8);
      v29 = (_QWORD *)(v28 + 664);
      v30 = (_QWORD *)(v28 + 744);
      if ( a2 )
        v31 = v30;
      else
        v31 = v29;
      v32 = *a1;
      v31[1] = a1[1];
      v33 = a1[5];
      v35 = a1[2];
      v34 = a1[3];
      v31[4] = a1[4];
      v31[5] = v33;
      v31[2] = v35;
      v31[3] = v34;
      v36 = a1[8];
      v37 = a1[9];
      v39 = a1[6];
      v38 = a1[7];
      *v31 = v32;
      v31[9] = v37;
      v31[6] = v39;
      v31[7] = v38;
      v31[8] = v36;
      result = ipa_smmu_store_sgt(v31 + 8, a1[8]);
      if ( !(_DWORD)result )
      {
        v41 = ipa_smmu_store_sgt(v31 + 9, a1[9]);
        if ( v41 )
        {
          v42 = v41;
          ipa_smmu_free_sgt((_QWORD **)v31 + 8);
          result = v42;
        }
        else
        {
          v43 = *((unsigned __int16 *)a1 + 10);
          v44 = *((unsigned __int8 *)a1 + 32);
          v45 = *(_BYTE *)a1;
          v78[28] = 3;
          LODWORD(v78[29]) = 16;
          HIDWORD(v78[29]) = v43 - 16;
          v46 = *((unsigned int *)a1 + 7);
          BYTE1(v78[27]) = v45;
          v78[30] = a1[5];
          v78[31] = 0;
          v78[34] = v46 | (v44 << 32);
          LODWORD(v46) = *((_DWORD *)a1 + 2);
          LOWORD(v78[32]) = 0;
          LODWORD(v78[44]) = v46;
          LOBYTE(v46) = *((_BYTE *)a1 + 12);
          HIDWORD(v78[32]) = 0;
          BYTE4(v78[44]) = v46;
          LODWORD(v46) = *((_DWORD *)a1 + 4);
          v78[37] = 0;
          LOBYTE(v78[39]) = 1;
          v78[40] = ipa3_usb_gsi_evt_err_cb;
          v78[41] = 0;
          LODWORD(v78[45]) = 3;
          HIDWORD(v78[45]) = v46;
          LODWORD(v78[48]) = 16;
          HIDWORD(v78[48]) = v43;
          v78[50] = v78[30];
          v78[52] = 0;
          hw_type = ipa_get_hw_type();
          v48 = *((_DWORD *)a1 + 4) == 0;
          LODWORD(v78[53]) = hw_type < 0xE;
          if ( v48 )
            v49 = 5;
          else
            v49 = 4;
          v50 = *((unsigned __int16 *)a1 + 12);
          v78[56] = 0;
          v78[57] = ipa3_usb_gsi_chan_err_cb;
          LOBYTE(v78[54]) = v49;
          v51 = *((unsigned __int8 *)a1 + 26);
          v52 = *((_DWORD *)a1 + 7);
          LOBYTE(v78[51]) = 1;
          HIDWORD(v78[53]) = 0;
          v78[59] = 0;
          LODWORD(v78[60]) = v78[60] & 0xF0000 | v50 | (v51 << 27);
          v53 = *((_BYTE *)a1 + 32);
          HIDWORD(v78[60]) = v52;
          LOBYTE(v78[61]) = v53;
          if ( (unsigned int)ipa_get_hw_type() <= 0xD )
            HIWORD(v78[61]) = LODWORD(v78[48]) << (*((_DWORD *)a1 + 1) != 3);
          v54 = ipa3_request_gsi_channel((__int64)v78, a3);
          if ( v54 )
          {
            v75 = v54;
            printk(&unk_3CE45B, "ipa3_usb_request_xdci_channel");
            if ( ipa3_get_ipc_logbuf() )
            {
              v76 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v76,
                "ipa_usb %s:%d failed to allocate GSI channel\n",
                "ipa3_usb_request_xdci_channel",
                1294);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v77 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v77,
                "ipa_usb %s:%d failed to allocate GSI channel\n",
                "ipa3_usb_request_xdci_channel",
                1294);
            }
            ipa3_usb_smmu_map_xdci_channel(a1, 0);
            result = v75;
          }
          else
          {
            result = ipa3_get_ipc_logbuf_low();
            if ( result )
            {
              v55 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v55, "ipa_usb %s:%d exit\n", "ipa3_usb_request_xdci_channel", 1299);
              result = 0;
            }
          }
        }
      }
    }
    goto LABEL_101;
  }
  printk(&unk_3A5362, "ipa3_usb_request_xdci_channel");
  if ( ipa3_get_ipc_logbuf() )
  {
    v56 = ipa3_get_ipc_logbuf();
    ipc_log_string(v56, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_request_xdci_channel", 1137);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v57 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v57, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_request_xdci_channel", 1137);
  }
  result = 0xFFFFFFFFLL;
LABEL_101:
  _ReadStatusReg(SP_EL0);
  return result;
}
