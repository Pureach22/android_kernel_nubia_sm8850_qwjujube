__int64 __fastcall ipa_mhi_connect_pipe(__int64 a1, signed int *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w21
  int v9; // w8
  __int64 v10; // x21
  unsigned int v11; // w9
  __int64 v12; // x8
  __int64 v13; // x11
  int v14; // w10
  __int64 v15; // x12
  unsigned __int8 *v16; // x11
  __int64 v17; // x13
  unsigned __int8 *v18; // x21
  unsigned __int8 *v19; // x14
  int v20; // t1
  int v21; // w10
  int v22; // w3
  _DWORD *v23; // x22
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  long double v29; // q0
  __int64 v30; // x0
  int ch_ctx; // w0
  char v32; // w8
  __int64 v33; // x9
  int v34; // w11
  __int64 v35; // x11
  __int64 v36; // x0
  int v37; // w8
  __int64 v38; // x2
  unsigned int v39; // w0
  int v40; // w8
  char v41; // w0
  __int64 v42; // x0
  __int64 result; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  int v53; // w20
  __int64 v54; // x0
  __int64 v55; // x0
  int v56; // w20
  __int64 v57; // x0
  long double v58; // q0
  __int64 v59; // x0
  unsigned int v60; // w20
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // [xsp+18h] [xbp-88h] BYREF
  __int64 v70; // [xsp+20h] [xbp-80h]
  __int64 v71; // [xsp+28h] [xbp-78h]
  __int64 v72; // [xsp+30h] [xbp-70h]
  __int64 v73; // [xsp+38h] [xbp-68h]
  unsigned __int8 *v74; // [xsp+40h] [xbp-60h]
  __int64 v75; // [xsp+48h] [xbp-58h]
  unsigned __int8 *v76; // [xsp+50h] [xbp-50h]
  __int64 v77; // [xsp+58h] [xbp-48h]
  __int64 (__fastcall *v78)(); // [xsp+60h] [xbp-40h]
  __int64 (__fastcall *v79)(); // [xsp+68h] [xbp-38h]
  unsigned __int8 *v80; // [xsp+70h] [xbp-30h]
  __int64 v81; // [xsp+78h] [xbp-28h]
  unsigned __int8 *v82; // [xsp+80h] [xbp-20h]
  unsigned __int8 *v83; // [xsp+88h] [xbp-18h]
  __int64 v84; // [xsp+90h] [xbp-10h]
  __int64 v85; // [xsp+98h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = nullptr;
  v84 = 0;
  v81 = 0;
  v82 = nullptr;
  v79 = nullptr;
  v80 = nullptr;
  v77 = 0;
  v78 = nullptr;
  v75 = 0;
  v76 = nullptr;
  v73 = 0;
  v74 = nullptr;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_connect_pipe", 1277);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_connect_pipe", 1277);
  }
  if ( !a1 || !a2 )
  {
    printk(&unk_3B6747, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v51 = ipa3_get_ipc_logbuf();
      ipc_log_string(v51, "ipa_mhi_client %s:%d NULL args\n", "ipa_mhi_connect_pipe", 1280);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v52 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v52, "ipa_mhi_client %s:%d NULL args\n", "ipa_mhi_connect_pipe", 1280);
LABEL_98:
      result = 4294967274LL;
      goto LABEL_129;
    }
LABEL_128:
    result = 4294967274LL;
    goto LABEL_129;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v6 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v6,
      "ipa_mhi_client %s:%d channel=%d\n",
      "ipa_mhi_connect_pipe",
      1284,
      *(unsigned __int8 *)(a1 + 256));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v7,
      "ipa_mhi_client %s:%d channel=%d\n",
      "ipa_mhi_connect_pipe",
      1284,
      *(unsigned __int8 *)(a1 + 256));
  }
  v8 = *(unsigned __int8 *)(a1 + 256);
  if ( v8 > 0x68 )
  {
    if ( *(unsigned __int8 *)(a1 + 256) > 0x6Cu )
    {
      if ( v8 != 109 )
      {
        if ( v8 != 110 )
          goto LABEL_120;
LABEL_27:
        v9 = 111;
        goto LABEL_34;
      }
    }
    else
    {
      if ( v8 != 105 )
      {
        if ( v8 != 106 )
          goto LABEL_120;
        if ( (*(_BYTE *)(ipa3_ctx + 32264) & 1) != 0 || *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
        {
          v9 = 113;
          goto LABEL_34;
        }
        goto LABEL_27;
      }
      if ( (*(_BYTE *)(ipa3_ctx + 32264) & 1) != 0 || *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
      {
        v9 = 112;
        goto LABEL_34;
      }
    }
    v9 = 110;
    goto LABEL_34;
  }
  if ( *(unsigned __int8 *)(a1 + 256) > 0x65u )
  {
    if ( v8 == 102 )
    {
      v9 = 81;
      goto LABEL_34;
    }
    if ( v8 == 103 )
    {
      v9 = 107;
      goto LABEL_34;
    }
LABEL_120:
    printk(&unk_3D11A5, "ipa3_mhi_get_client_by_chid");
    if ( ipa3_get_ipc_logbuf() )
    {
      v65 = ipa3_get_ipc_logbuf();
      ipc_log_string(v65, "ipa_mhi_client %s:%d Invalid channel = 0x%X\n", "ipa3_mhi_get_client_by_chid", 1251, v8);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v66 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v66, "ipa_mhi_client %s:%d Invalid channel = 0x%X\n", "ipa3_mhi_get_client_by_chid", 1251, v8);
    }
    *(_DWORD *)(a1 + 192) = 134;
    printk(&unk_3B0DFD, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v67 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v67,
        "ipa_mhi_client %s:%d bad param client:%d\n",
        "ipa_mhi_connect_pipe",
        1288,
        *(_DWORD *)(a1 + 192));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v68 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v68,
        "ipa_mhi_client %s:%d bad param client:%d\n",
        "ipa_mhi_connect_pipe",
        1288,
        *(_DWORD *)(a1 + 192));
      result = 4294967274LL;
      goto LABEL_129;
    }
    goto LABEL_128;
  }
  if ( v8 != 100 )
  {
    if ( v8 == 101 )
    {
      v9 = 43;
      goto LABEL_34;
    }
    goto LABEL_120;
  }
  v9 = 42;
LABEL_34:
  *(_DWORD *)(a1 + 192) = v9;
  v10 = raw_spin_lock_irqsave(ipa_mhi_client_ctx + 4);
  if ( !ipa_mhi_client_ctx || *(_DWORD *)ipa_mhi_client_ctx != 2 )
  {
    printk(&unk_3B6769, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v45 = ipa3_get_ipc_logbuf();
      ipc_log_string(v45, "ipa_mhi_client %s:%d IPA MHI was not started\n", "ipa_mhi_connect_pipe", 1301);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v46 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v46, "ipa_mhi_client %s:%d IPA MHI was not started\n", "ipa_mhi_connect_pipe", 1301);
    }
    raw_spin_unlock_irqrestore(ipa_mhi_client_ctx + 4, v10);
    result = 4294967274LL;
    goto LABEL_129;
  }
  raw_spin_unlock_irqrestore(ipa_mhi_client_ctx + 4, v10);
  v11 = *(_DWORD *)(a1 + 192);
  v12 = ipa_mhi_client_ctx;
  v13 = 40;
  if ( v11 >= 0x86 || (v11 & 1) != 0 )
    v13 = 440;
  v14 = *(unsigned __int8 *)(a1 + 256);
  if ( *(_DWORD *)(a1 + 192) < 0x86u && (*(_DWORD *)(a1 + 192) & 1) == 0 )
    v15 = 2;
  else
    v15 = 4;
  v16 = (unsigned __int8 *)(ipa_mhi_client_ctx + v13);
  v17 = v15;
  v18 = v16;
  do
  {
    if ( *v18 == 1 && v18[1] == v14 )
    {
      if ( v18 )
        goto LABEL_53;
LABEL_90:
      printk(&unk_3C579B, "ipa_mhi_connect_pipe");
      if ( ipa3_get_ipc_logbuf() )
      {
        v49 = ipa3_get_ipc_logbuf();
        ipc_log_string(v49, "ipa_mhi_client %s:%d ipa_mhi_get_channel_context failed\n", "ipa_mhi_connect_pipe", 1309);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v50 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v50, "ipa_mhi_client %s:%d ipa_mhi_get_channel_context failed\n", "ipa_mhi_connect_pipe", 1309);
        goto LABEL_98;
      }
      goto LABEL_128;
    }
    --v17;
    v18 += 200;
  }
  while ( v17 );
  v19 = v16;
  while ( 1 )
  {
    v20 = *v19;
    v19 += 200;
    if ( v20 != 1 )
      break;
    if ( v15 == ++v17 )
      goto LABEL_86;
  }
  if ( (_DWORD)v15 == (_DWORD)v17 )
  {
LABEL_86:
    printk(&unk_3E249F, "ipa_mhi_get_channel_context");
    if ( ipa3_get_ipc_logbuf() )
    {
      v47 = ipa3_get_ipc_logbuf();
      ipc_log_string(v47, "ipa_mhi_client %s:%d no more channels available\n", "ipa_mhi_get_channel_context", 776);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v48 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v48, "ipa_mhi_client %s:%d no more channels available\n", "ipa_mhi_get_channel_context", 776);
    }
    goto LABEL_90;
  }
  v18 = &v16[200 * (unsigned int)v17];
  *v18 = 1;
  v18[1] = v14;
  v21 = *(_DWORD *)(v12 + 1240);
  *(_DWORD *)(v12 + 1240) = v21 + 1;
  v18[2] = v21;
  *((_DWORD *)v18 + 1) = v11;
  *((_DWORD *)v18 + 2) = 255;
  if ( !v18 )
    goto LABEL_90;
LABEL_53:
  v23 = v18 + 8;
  v22 = *((_DWORD *)v18 + 2);
  if ( v22 && v22 != 255 )
  {
    printk(&unk_3B67C7, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v63 = ipa3_get_ipc_logbuf();
      ipc_log_string(v63, "ipa_mhi_client %s:%d Invalid channel state %d\n", "ipa_mhi_connect_pipe", 1315, *v23);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v64 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v64, "ipa_mhi_client %s:%d Invalid channel state %d\n", "ipa_mhi_connect_pipe", 1315, *v23);
    }
    result = 4294967282LL;
    goto LABEL_129;
  }
  *((_QWORD *)v18 + 7) = *(_QWORD *)(v12 + 1280) + 44LL * v18[1];
  if ( ipa3_get_ipc_logbuf() )
  {
    v24 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v24,
      "ipa_mhi_client %s:%d client %d channelIndex %d channelID %d, state %d\n",
      "ipa_mhi_connect_pipe",
      1326,
      *((_DWORD *)v18 + 1),
      v18[2],
      v18[1],
      *((_DWORD *)v18 + 2));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v25 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v25,
      "ipa_mhi_client %s:%d client %d channelIndex %d channelID %d, state %d\n",
      "ipa_mhi_connect_pipe",
      1326,
      *((_DWORD *)v18 + 1),
      v18[2],
      v18[1],
      *((_DWORD *)v18 + 2));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v26 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v26,
      "ipa_mhi_client %s:%d channel_context_addr 0x%llx cached_gsi_evt_ring_hdl %lu\n",
      "ipa_mhi_connect_pipe",
      1329,
      *((_QWORD *)v18 + 7),
      *((_QWORD *)v18 + 24));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v27 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v27,
      "ipa_mhi_client %s:%d channel_context_addr 0x%llx cached_gsi_evt_ring_hdl %lu\n",
      "ipa_mhi_connect_pipe",
      1329,
      *((_QWORD *)v18 + 7),
      *((_QWORD *)v18 + 24));
  }
  ipa3_inc_client_enable_clks();
  mutex_lock(&mhi_client_general_mutex);
  if ( ipa3_get_ipc_logbuf() )
  {
    v28 = ipa3_get_ipc_logbuf();
    ipc_log_string(v28, "ipa_mhi_client %s:%d reading ch/ev context from host\n", "ipa_mhi_connect_pipe", 1335);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v30 = ipa3_get_ipc_logbuf_low();
    v29 = ipc_log_string(v30, "ipa_mhi_client %s:%d reading ch/ev context from host\n", "ipa_mhi_connect_pipe", 1335);
  }
  ch_ctx = ipa_mhi_read_ch_ctx(v18, v29);
  if ( ch_ctx )
  {
    v53 = ch_ctx;
    printk(&unk_3BC800, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v54 = ipa3_get_ipc_logbuf();
      ipc_log_string(v54, "ipa_mhi_client %s:%d ipa_mhi_read_ch_ctx failed %d\n", "ipa_mhi_connect_pipe", 1338, v53);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v55 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v55, "ipa_mhi_client %s:%d ipa_mhi_read_ch_ctx failed %d\n", "ipa_mhi_connect_pipe", 1338, v53);
    }
    goto LABEL_108;
  }
  v32 = *(_BYTE *)(a1 + 256);
  v33 = *((_QWORD *)v18 + 14);
  v69 = a1;
  LOBYTE(v70) = v32;
  v34 = *((_DWORD *)v18 + 2);
  v75 = v33;
  v76 = v18 + 64;
  LODWORD(v72) = v34;
  v35 = *((_QWORD *)v18 + 7);
  v73 = ipa_mhi_client_ctx + 1244;
  v74 = v18 + 120;
  LOBYTE(v33) = *(_BYTE *)(ipa_mhi_client_ctx + 1304);
  v77 = v35;
  v78 = ipa_mhi_gsi_ch_err_cb;
  v79 = ipa_mhi_gsi_ev_err_cb;
  v80 = v18;
  LOBYTE(v81) = v33;
  v82 = v18 + 165;
  v83 = v18 + 192;
  LOBYTE(v84) = v18[2];
  v36 = ipa3_connect_mhi_pipe(&v69, a2);
  if ( (_DWORD)v36 )
  {
    v56 = v36;
    printk(&unk_3C256A, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v57 = ipa3_get_ipc_logbuf();
      ipc_log_string(v57, "ipa_mhi_client %s:%d ipa_connect_mhi_pipe failed %d\n", "ipa_mhi_connect_pipe", 1364, v56);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v59 = ipa3_get_ipc_logbuf_low();
      v58 = ipc_log_string(
              v59,
              "ipa_mhi_client %s:%d ipa_connect_mhi_pipe failed %d\n",
              "ipa_mhi_connect_pipe",
              1364,
              v56);
    }
    ipa_mhi_reset_channel(v18, 1, v58);
LABEL_108:
    mutex_unlock(&mhi_client_general_mutex);
    ipa3_dec_client_disable_clks();
    result = 0xFFFFFFFFLL;
    goto LABEL_129;
  }
  v37 = *(_DWORD *)(v18 + 173);
  v38 = *((_QWORD *)v18 + 7);
  *((_DWORD *)v18 + 2) = 2;
  v18[164] = (v37 & 0x80) != 0;
  v39 = ipa_mhi_read_write_host(v36, v18 + 8, v38, 1);
  if ( v39 )
  {
    v60 = v39;
    printk(&unk_3F64BC, "ipa_mhi_connect_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v61 = ipa3_get_ipc_logbuf();
      ipc_log_string(v61, "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n", "ipa_mhi_connect_pipe", 1376);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v62 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v62, "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n", "ipa_mhi_connect_pipe", 1376);
    }
    mutex_unlock(&mhi_client_general_mutex);
    ipa3_dec_client_disable_clks();
    result = v60;
  }
  else
  {
    v40 = *(_DWORD *)(a1 + 192);
    if ( v40 == 110 )
    {
      v41 = 2;
LABEL_74:
      ipa3_update_mhi_ctrl_state(v41, 1);
    }
    else if ( v40 == 111 )
    {
      v41 = 4;
      goto LABEL_74;
    }
    mutex_unlock(&mhi_client_general_mutex);
    if ( (*(_BYTE *)(a1 + 217) & 1) == 0 )
      ipa3_dec_client_disable_clks();
    if ( ipa3_get_ipc_logbuf() )
    {
      v42 = ipa3_get_ipc_logbuf();
      ipc_log_string(v42, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_connect_pipe", 1393);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v44 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v44, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_connect_pipe", 1393);
      result = 0;
    }
  }
LABEL_129:
  _ReadStatusReg(SP_EL0);
  return result;
}
