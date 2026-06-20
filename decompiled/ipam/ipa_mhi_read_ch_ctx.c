__int64 __fastcall ipa_mhi_read_ch_ctx(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 result; // x0
  __int64 v44; // x0
  unsigned int v45; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v48; // x0
  __int64 v49; // x0

  v2 = ipa_mhi_read_write_host(1, a1 + 64, *(_QWORD *)(a1 + 56), 44);
  if ( v2 )
  {
    v45 = v2;
    printk(&unk_3EABAB, "ipa_mhi_read_ch_ctx");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed %d\n",
        "ipa_mhi_read_ch_ctx",
        858,
        v45);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed %d\n",
        "ipa_mhi_read_ch_ctx",
        858,
        v45);
    }
    return v45;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v3 = ipa3_get_ipc_logbuf();
    ipc_log_string(v3, "ipa_mhi_client %s:%d ch_id %d\n", "ipa_mhi_dump_ch_ctx", 823, *(unsigned __int8 *)(a1 + 1));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v4 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v4, "ipa_mhi_client %s:%d ch_id %d\n", "ipa_mhi_dump_ch_ctx", 823, *(unsigned __int8 *)(a1 + 1));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_mhi_client %s:%d chstate 0x%x\n", "ipa_mhi_dump_ch_ctx", 824, *(unsigned __int8 *)(a1 + 64));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa_mhi_client %s:%d chstate 0x%x\n", "ipa_mhi_dump_ch_ctx", 824, *(unsigned __int8 *)(a1 + 64));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(v7, "ipa_mhi_client %s:%d brstmode 0x%x\n", "ipa_mhi_dump_ch_ctx", 825, *(_BYTE *)(a1 + 65) & 3);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v8, "ipa_mhi_client %s:%d brstmode 0x%x\n", "ipa_mhi_dump_ch_ctx", 825, *(_BYTE *)(a1 + 65) & 3);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v9 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v9,
      "ipa_mhi_client %s:%d pollcfg 0x%x\n",
      "ipa_mhi_dump_ch_ctx",
      826,
      *(unsigned __int8 *)(a1 + 65) >> 2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v10 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v10,
      "ipa_mhi_client %s:%d pollcfg 0x%x\n",
      "ipa_mhi_dump_ch_ctx",
      826,
      *(unsigned __int8 *)(a1 + 65) >> 2);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v11 = ipa3_get_ipc_logbuf();
    ipc_log_string(v11, "ipa_mhi_client %s:%d chtype 0x%x\n", "ipa_mhi_dump_ch_ctx", 827, *(_DWORD *)(a1 + 68));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v12, "ipa_mhi_client %s:%d chtype 0x%x\n", "ipa_mhi_dump_ch_ctx", 827, *(_DWORD *)(a1 + 68));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(v13, "ipa_mhi_client %s:%d erindex 0x%x\n", "ipa_mhi_dump_ch_ctx", 828, *(_DWORD *)(a1 + 72));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v14, "ipa_mhi_client %s:%d erindex 0x%x\n", "ipa_mhi_dump_ch_ctx", 828, *(_DWORD *)(a1 + 72));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(v15, "ipa_mhi_client %s:%d rbase 0x%llx\n", "ipa_mhi_dump_ch_ctx", 829, *(_QWORD *)(a1 + 76));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v16, "ipa_mhi_client %s:%d rbase 0x%llx\n", "ipa_mhi_dump_ch_ctx", 829, *(_QWORD *)(a1 + 76));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v17 = ipa3_get_ipc_logbuf();
    ipc_log_string(v17, "ipa_mhi_client %s:%d rlen 0x%llx\n", "ipa_mhi_dump_ch_ctx", 830, *(_QWORD *)(a1 + 84));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v18 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v18, "ipa_mhi_client %s:%d rlen 0x%llx\n", "ipa_mhi_dump_ch_ctx", 830, *(_QWORD *)(a1 + 84));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v19 = ipa3_get_ipc_logbuf();
    ipc_log_string(v19, "ipa_mhi_client %s:%d rp 0x%llx\n", "ipa_mhi_dump_ch_ctx", 831, *(_QWORD *)(a1 + 92));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v20 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v20, "ipa_mhi_client %s:%d rp 0x%llx\n", "ipa_mhi_dump_ch_ctx", 831, *(_QWORD *)(a1 + 92));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v21 = ipa3_get_ipc_logbuf();
    ipc_log_string(v21, "ipa_mhi_client %s:%d wp 0x%llx\n", "ipa_mhi_dump_ch_ctx", 832, *(_QWORD *)(a1 + 100));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v22 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v22, "ipa_mhi_client %s:%d wp 0x%llx\n", "ipa_mhi_dump_ch_ctx", 832, *(_QWORD *)(a1 + 100));
  }
  *(_QWORD *)(a1 + 112) = *(_QWORD *)(ipa_mhi_client_ctx + 1288) + 44LL * *(unsigned int *)(a1 + 72);
  if ( ipa3_get_ipc_logbuf() )
  {
    v23 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v23,
      "ipa_mhi_client %s:%d ch %d event_context_addr 0x%llx\n",
      "ipa_mhi_read_ch_ctx",
      868,
      *(unsigned __int8 *)(a1 + 1),
      *(_QWORD *)(a1 + 112));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v24 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v24,
      "ipa_mhi_client %s:%d ch %d event_context_addr 0x%llx\n",
      "ipa_mhi_read_ch_ctx",
      868,
      *(unsigned __int8 *)(a1 + 1),
      *(_QWORD *)(a1 + 112));
  }
  v25 = ipa_mhi_read_write_host(1, a1 + 120, *(_QWORD *)(a1 + 112), 44);
  if ( v25 )
  {
    v45 = v25;
    printk(&unk_3EABAB, "ipa_mhi_read_ch_ctx");
    if ( ipa3_get_ipc_logbuf() )
    {
      v48 = ipa3_get_ipc_logbuf();
      ipc_log_string(v48, "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed %d\n", "ipa_mhi_read_ch_ctx", 874, v45);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v49 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v49, "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed %d\n", "ipa_mhi_read_ch_ctx", 874, v45);
    }
    return v45;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v26 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v26,
      "ipa_mhi_client %s:%d ch_id %d event id %d\n",
      "ipa_mhi_dump_ev_ctx",
      838,
      *(unsigned __int8 *)(a1 + 1),
      *(_DWORD *)(a1 + 72));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v27 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v27,
      "ipa_mhi_client %s:%d ch_id %d event id %d\n",
      "ipa_mhi_dump_ev_ctx",
      838,
      *(unsigned __int8 *)(a1 + 1),
      *(_DWORD *)(a1 + 72));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v28 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v28,
      "ipa_mhi_client %s:%d intmodc 0x%x\n",
      "ipa_mhi_dump_ev_ctx",
      840,
      *(unsigned __int16 *)(a1 + 120));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v29 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v29,
      "ipa_mhi_client %s:%d intmodc 0x%x\n",
      "ipa_mhi_dump_ev_ctx",
      840,
      *(unsigned __int16 *)(a1 + 120));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v30 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v30,
      "ipa_mhi_client %s:%d intmodt 0x%x\n",
      "ipa_mhi_dump_ev_ctx",
      841,
      *(unsigned __int16 *)(a1 + 122));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v31 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v31,
      "ipa_mhi_client %s:%d intmodt 0x%x\n",
      "ipa_mhi_dump_ev_ctx",
      841,
      *(unsigned __int16 *)(a1 + 122));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v32 = ipa3_get_ipc_logbuf();
    ipc_log_string(v32, "ipa_mhi_client %s:%d ertype 0x%x\n", "ipa_mhi_dump_ev_ctx", 842, *(_DWORD *)(a1 + 124));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v33 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v33, "ipa_mhi_client %s:%d ertype 0x%x\n", "ipa_mhi_dump_ev_ctx", 842, *(_DWORD *)(a1 + 124));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v34 = ipa3_get_ipc_logbuf();
    ipc_log_string(v34, "ipa_mhi_client %s:%d msivec 0x%x\n", "ipa_mhi_dump_ev_ctx", 843, *(_DWORD *)(a1 + 128));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v35 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v35, "ipa_mhi_client %s:%d msivec 0x%x\n", "ipa_mhi_dump_ev_ctx", 843, *(_DWORD *)(a1 + 128));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v36 = ipa3_get_ipc_logbuf();
    ipc_log_string(v36, "ipa_mhi_client %s:%d rbase 0x%llx\n", "ipa_mhi_dump_ev_ctx", 844, *(_QWORD *)(a1 + 132));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v37 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v37, "ipa_mhi_client %s:%d rbase 0x%llx\n", "ipa_mhi_dump_ev_ctx", 844, *(_QWORD *)(a1 + 132));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v38 = ipa3_get_ipc_logbuf();
    ipc_log_string(v38, "ipa_mhi_client %s:%d rlen 0x%llx\n", "ipa_mhi_dump_ev_ctx", 845, *(_QWORD *)(a1 + 140));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v39 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v39, "ipa_mhi_client %s:%d rlen 0x%llx\n", "ipa_mhi_dump_ev_ctx", 845, *(_QWORD *)(a1 + 140));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v40 = ipa3_get_ipc_logbuf();
    ipc_log_string(v40, "ipa_mhi_client %s:%d rp 0x%llx\n", "ipa_mhi_dump_ev_ctx", 846, *(_QWORD *)(a1 + 148));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v41 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v41, "ipa_mhi_client %s:%d rp 0x%llx\n", "ipa_mhi_dump_ev_ctx", 846, *(_QWORD *)(a1 + 148));
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v42 = ipa3_get_ipc_logbuf();
    ipc_log_string(v42, "ipa_mhi_client %s:%d wp 0x%llx\n", "ipa_mhi_dump_ev_ctx", 847, *(_QWORD *)(a1 + 156));
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v44 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v44, "ipa_mhi_client %s:%d wp 0x%llx\n", "ipa_mhi_dump_ev_ctx", 847, *(_QWORD *)(a1 + 156));
    return 0;
  }
  return result;
}
