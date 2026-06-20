__int64 __fastcall ipa_connect_channels(_QWORD *a1)
{
  _QWORD *v2; // x24
  __int64 v3; // x8
  __int64 *v4; // x25
  __int64 result; // x0
  __int64 v6; // x8
  unsigned int v7; // w19
  unsigned int v8; // w0
  unsigned int v9; // w23
  __int64 v10; // x0
  int v11; // w8
  char v12; // w10
  int v13; // w11
  __int16 v14; // w9
  int v15; // w10
  __int64 v16; // x9
  __int64 v17; // x9
  int v18; // w9
  char v19; // w10
  __int64 v20; // x0
  unsigned int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x0
  int v24; // w9
  char v25; // w10
  int v26; // w8
  int v27; // w9
  __int16 v28; // w10
  int v29; // w8
  __int64 v30; // x9
  __int64 v31; // x9
  char v32; // w9
  int v33; // w10
  char v34; // w8
  int v35; // w10
  int v36; // w11
  unsigned int v37; // w8
  int v38; // w9
  int v39; // w10
  int v40; // w8
  __int64 v41; // x8
  int v42; // w8
  _DWORD *v43; // x8
  int v44; // w0
  int v45; // w21
  __int64 v46; // x0
  __int64 v47; // x0
  int v48; // w9
  int v49; // w10
  int v50; // w11
  int v51; // w9
  int v52; // w10
  __int64 v53; // [xsp+0h] [xbp-50h] BYREF
  int v54; // [xsp+8h] [xbp-48h]
  __int64 v55; // [xsp+10h] [xbp-40h] BYREF
  int v56; // [xsp+18h] [xbp-38h]
  __int64 v57; // [xsp+20h] [xbp-30h] BYREF
  __int64 v58; // [xsp+28h] [xbp-28h]
  __int64 v59; // [xsp+30h] [xbp-20h]
  __int64 v60; // [xsp+38h] [xbp-18h]
  _QWORD *v61; // [xsp+40h] [xbp-10h]
  __int64 v62; // [xsp+48h] [xbp-8h]

  v2 = a1 - 38;
  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(a1 - 32);
  v60 = 0;
  v61 = nullptr;
  v58 = 0;
  v59 = 0;
  v4 = *(__int64 **)(v3 + 48);
  v57 = 0;
  v56 = 0;
  v55 = 0;
  v54 = 0;
  v53 = 0;
  if ( a1 != qword_130 )
    ipc_log_string(a1[130], "IN: num_bufs:=%zu, buf_len=%zu\n", a1[4], a1[5]);
  msm_ep_set_mode(*a1, 2);
  result = usb_gsi_ep_op(*a1, a1 + 2, 9);
  if ( (_DWORD)result )
  {
    if ( v2 )
    {
      v6 = a1[130];
      v7 = result;
      ipc_log_string(v6, "%s: GSI_EP_OP_PREPARE_TRBS failed: %d\n", "ipa_connect_channels", result);
      printk(&unk_10522, "ipa_connect_channels");
      result = v7;
    }
    goto LABEL_50;
  }
  v8 = usb_gsi_ep_op(*a1, a1 + 2, 1);
  if ( v8 )
  {
    v9 = v8;
    if ( v2 )
    {
      ipc_log_string(a1[130], "%s: GSI_EP_OP_STARTXFER failed: %d\n", "ipa_connect_channels", v8);
      printk(&unk_1135F, "ipa_connect_channels");
    }
    goto LABEL_49;
  }
  *((_DWORD *)a1 + 59) = usb_gsi_ep_op(*a1, 0, 8);
  v10 = *a1;
  a1[69] = 0;
  a1[70] = 0;
  a1[71] = 0;
  a1[72] = 0;
  a1[73] = 0;
  a1[74] = 0;
  a1[75] = 0;
  a1[76] = 0;
  a1[77] = 0;
  a1[78] = 0;
  v61 = a1 + 2;
  usb_gsi_ep_op(v10, &v57, 7);
  if ( v2 )
    ipc_log_string(a1[130], "%s: USB GSI IN OPS Completed", "ipa_connect_channels");
  v11 = *((_DWORD *)a1 - 20);
  v12 = v59;
  v13 = *((_DWORD *)a1 + 8);
  *((_DWORD *)a1 + 140) = HIDWORD(v58);
  v14 = v57;
  *((_DWORD *)a1 + 139) = v11;
  LOWORD(v11) = WORD1(v59);
  *((_BYTE *)a1 + 564) = v12;
  v15 = *((_DWORD *)a1 + 10);
  *((_WORD *)a1 + 288) = v14;
  v16 = v60;
  *((_WORD *)a1 + 286) = v11;
  a1[74] = v16;
  v17 = a1[3];
  *((_DWORD *)a1 + 142) = 0;
  *((_DWORD *)a1 + 150) = v13 * v15;
  a1[76] = v17;
  a1[77] = a1 + 9;
  a1[78] = a1 + 11;
  if ( v2 )
    ipc_log_string(a1[130], "%s(): IN: sgt_xfer_rings:%pK sgt_data_buff:%pK\n", "ipa_connect_channels", a1 + 9, a1 + 11);
  v18 = HIDWORD(v57);
  v19 = v58;
  v20 = a1[1];
  *((_BYTE *)a1 + 578) = BYTE2(v57);
  *((_DWORD *)a1 + 145) = v18;
  *((_BYTE *)a1 + 584) = v19;
  if ( v20 )
  {
    if ( v2 )
    {
      ipc_log_string(a1[130], "OUT: num_bufs:=%zu, buf_len=%zu\n", a1[15], a1[16]);
      v20 = a1[1];
    }
    msm_ep_set_mode(v20, 2);
    v21 = usb_gsi_ep_op(a1[1], a1 + 13, 9);
    if ( v21 )
    {
      v9 = v21;
      if ( v2 )
      {
        ipc_log_string(a1[130], "%s: GSI_EP_OP_PREPARE_TRBS failed: %d\n", "ipa_connect_channels", v21);
        printk(&unk_10522, "ipa_connect_channels");
      }
      goto LABEL_48;
    }
    v22 = usb_gsi_ep_op(a1[1], a1 + 13, 1);
    if ( v22 )
    {
      v9 = v22;
      if ( v2 )
      {
        ipc_log_string(a1[130], "%s: GSI_EP_OP_STARTXFER failed: %d\n", "ipa_connect_channels", v22);
        printk(&unk_1135F, "ipa_connect_channels");
      }
      goto LABEL_46;
    }
    *((_DWORD *)a1 + 60) = usb_gsi_ep_op(a1[1], 0, 8);
    v23 = a1[1];
    a1[79] = 0;
    a1[80] = 0;
    a1[81] = 0;
    a1[82] = 0;
    a1[83] = 0;
    a1[84] = 0;
    a1[85] = 0;
    a1[86] = 0;
    a1[87] = 0;
    a1[88] = 0;
    v61 = a1 + 13;
    usb_gsi_ep_op(v23, &v57, 7);
    if ( v2 )
      ipc_log_string(a1[130], "%s: USB GSI OUT OPS Completed", "ipa_connect_channels");
    v24 = HIDWORD(v58);
    v25 = v59;
    *((_DWORD *)a1 + 159) = *((_DWORD *)a1 - 20);
    v26 = *((_DWORD *)a1 + 32);
    *((_DWORD *)a1 + 160) = v24;
    v27 = *((_DWORD *)a1 + 30);
    *((_BYTE *)a1 + 644) = v25;
    v28 = WORD1(v59);
    v29 = v27 * v26;
    v30 = v60;
    *((_DWORD *)a1 + 162) = 1;
    *((_WORD *)a1 + 326) = v28;
    a1[84] = v30;
    v31 = a1[14];
    *((_DWORD *)a1 + 170) = v29;
    a1[86] = v31;
    a1[87] = a1 + 20;
    a1[88] = a1 + 22;
    if ( v2 )
      ipc_log_string(
        a1[130],
        "%s(): OUT: sgt_xfer_rings:%pK sgt_data_buff:%pK\n",
        "ipa_connect_channels",
        a1 + 20,
        a1 + 22);
    v32 = BYTE2(v57);
    v33 = HIDWORD(v57);
    *((_WORD *)a1 + 328) = v57;
    v34 = v58;
    *((_BYTE *)a1 + 658) = v32;
    *((_DWORD *)a1 + 165) = v33;
    *((_BYTE *)a1 + 664) = v34;
  }
  v35 = *((_DWORD *)a1 + 60);
  v36 = *((_DWORD *)a1 - 20);
  v37 = *(_DWORD *)(*v4 + 72);
  *((_BYTE *)a1 + 716) = *((_DWORD *)a1 + 59);
  *((_BYTE *)a1 + 718) = v35;
  *((_BYTE *)a1 + 717) = 1;
  v38 = *((_DWORD *)a1 + 62);
  v39 = *((_DWORD *)a1 + 63);
  *((_DWORD *)a1 + 180) = v36;
  *((_DWORD *)a1 + 181) = v39;
  if ( v37 <= 4 )
    v40 = 512;
  else
    v40 = 1024;
  *((_DWORD *)a1 + 183) = v38;
  *((_DWORD *)a1 + 178) = v40;
  *((_BYTE *)a1 + 719) = v36 != 4;
  *((_DWORD *)a1 + 182) = 15;
  v41 = *v4;
  v56 = 0;
  v55 = 0;
  LODWORD(v41) = *(_DWORD *)(v41 + 72);
  v54 = 0;
  v53 = 0;
  if ( (unsigned int)v41 <= 4 )
    v42 = 400;
  else
    v42 = 3600;
  *((_DWORD *)a1 + 184) = v42;
  if ( !(unsigned int)wait_for_completion_timeout(&wait_for_ipa_ready, 1250) )
  {
    if ( v2 )
    {
      ipc_log_string(a1[130], "%s: ipa ready timeout", "ipa_connect_channels");
      printk(&unk_11A63, "ipa_connect_channels");
    }
    v44 = -110;
    goto LABEL_44;
  }
  if ( v2 )
    ipc_log_string(a1[130], "%s: Calling xdci_connect", "ipa_connect_channels");
  v43 = *(_DWORD **)(a1[93] + 8LL);
  if ( *(v43 - 1) != -1599109752 )
    __break(0x8228u);
  v44 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *, __int64 *, __int64 *, _QWORD *))v43)(
          a1 + 79,
          a1 + 69,
          &v53,
          &v55,
          a1 + 89);
  if ( v44 )
  {
    if ( v2 )
    {
      v45 = v44;
      ipc_log_string(a1[130], "%s: IPA connect failed %d", "ipa_connect_channels", v44);
      printk(&unk_11D74, "ipa_connect_channels");
      v44 = v45;
    }
LABEL_44:
    v9 = v44;
    v46 = a1[1];
    if ( !v46 )
    {
LABEL_48:
      usb_gsi_ep_op(*a1, 0, 6);
LABEL_49:
      usb_gsi_ep_op(*a1, a1 + 2, 10);
      result = v9;
      goto LABEL_50;
    }
    usb_gsi_ep_op(v46, 0, 6);
LABEL_46:
    v47 = a1[1];
    if ( v47 )
      usb_gsi_ep_op(v47, a1 + 13, 10);
    goto LABEL_48;
  }
  if ( v2 )
  {
    ipc_log_string(a1[130], "%s: xdci_connect done", "ipa_connect_channels");
    ipc_log_string(a1[130], "%s: IN CH HDL %x", "ipa_connect_channels", v55);
    ipc_log_string(a1[130], "%s: IN CH DBL addr %x", "ipa_connect_channels", HIDWORD(v55));
    ipc_log_string(a1[130], "%s: OUT CH HDL %x", "ipa_connect_channels", v53);
    ipc_log_string(a1[130], "%s: OUT CH DBL addr %x", "ipa_connect_channels", HIDWORD(v53));
  }
  v48 = HIDWORD(v55);
  v49 = *((_DWORD *)a1 - 20);
  v50 = v56;
  result = 0;
  *((_DWORD *)a1 + 57) = v55;
  *((_DWORD *)a1 + 12) = v48;
  *((_DWORD *)a1 + 16) = v50;
  if ( v49 != 4 )
  {
    v51 = HIDWORD(v53);
    v52 = v54;
    *((_DWORD *)a1 + 58) = v53;
    *((_DWORD *)a1 + 34) = v51;
    *((_DWORD *)a1 + 38) = v52;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
