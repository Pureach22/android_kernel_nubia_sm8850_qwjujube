void __fastcall ipa_rm_perf_profile_change(unsigned int a1)
{
  __int64 ipc_logbuf_low; // x0
  const char *v3; // x4
  int v4; // w3
  __int64 v5; // x8
  int v6; // w23
  int v7; // w22
  __int64 v8; // x24
  int v9; // w9
  __int64 v10; // x0
  unsigned int v11; // w8
  __int64 v12; // x0
  _DWORD *v13; // x8
  unsigned int v14; // w9
  unsigned int v15; // w14
  unsigned int v16; // w13
  int v17; // w3
  unsigned int v18; // w11
  unsigned int v19; // w12
  unsigned int v20; // w9
  unsigned int v21; // w10
  int v22; // w0
  int v23; // w15
  int v24; // w13
  int v25; // w12
  int v26; // w4
  unsigned int v27; // w11
  unsigned int v28; // w14
  int v29; // w16
  int v30; // w15
  int v31; // w0
  unsigned int v32; // w10
  unsigned int v33; // w16
  int v34; // w2
  int v35; // w4
  int v36; // w1
  int v37; // w17
  int v38; // w1
  int v39; // w17
  int v40; // w2
  int v41; // w4
  unsigned int v42; // w11
  unsigned int v43; // w14
  int v44; // w13
  int v45; // w13
  int v46; // w2
  int v47; // w9
  int v48; // w12
  int v49; // w11
  int v50; // w16
  int v51; // w1
  int v52; // w9
  unsigned int v53; // w19
  unsigned int v54; // w20
  __int64 v55; // x0
  int v56; // w20
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  int v60; // w19
  int v61; // w20
  __int64 v62; // x2
  __int64 v63; // x8
  __int64 ipc_logbuf; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  _QWORD v68[2]; // [xsp+0h] [xbp-10h] BYREF

  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68[0] = 0;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    if ( a1 <= 0x15 )
      v3 = resource_name_to_str[a1];
    else
      v3 = "INVALID RESOURCE";
    ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d %s\n", "ipa_rm_perf_profile_change", 672, v3);
  }
  if ( (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, a1, v68) )
  {
    printk(&unk_3E015F, "ipa_rm_perf_profile_change");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_perf_profile_change", 677);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v65 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v65, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_perf_profile_change", 677);
    }
    goto LABEL_80;
  }
  if ( a1 >= 0x17 )
    goto LABEL_86;
  v4 = *(_DWORD *)(v68[0] + 20LL);
  v5 = ipa_rm_ctx;
  v6 = *(_DWORD *)(ipa_rm_ctx + 108);
  v7 = *(_DWORD *)(ipa_rm_ctx + 200);
  v8 = ipa_rm_ctx + 112;
  if ( (unsigned int)(v4 - 1) < 2 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipa_rm %s:%d max_bw = %d, needed_bw = %d\n",
        "ipa_rm_perf_profile_change",
        691,
        *(_DWORD *)(v68[0] + 12LL),
        *(_DWORD *)(v68[0] + 16LL));
    }
    v11 = *(_DWORD *)(v68[0] + 16LL);
    if ( *(_DWORD *)(v68[0] + 12LL) < v11 )
      v11 = *(_DWORD *)(v68[0] + 12LL);
    *(_DWORD *)(v8 + 4LL * a1) = v11;
    if ( a1 != 22 )
    {
      v5 = ipa_rm_ctx;
      v9 = *(_DWORD *)(v68[0] + 8LL);
      goto LABEL_19;
    }
LABEL_86:
    __break(0x5512u);
  }
  if ( v4 && v4 != 3 )
  {
    printk(&unk_3BD046, "ipa_rm_perf_profile_change");
    if ( ipa3_get_ipc_logbuf() )
    {
      v66 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v66,
        "ipa_rm %s:%d unknown state %d\n",
        "ipa_rm_perf_profile_change",
        704,
        *(_DWORD *)(v68[0] + 20LL));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v67 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v67,
        "ipa_rm %s:%d unknown state %d\n",
        "ipa_rm_perf_profile_change",
        704,
        *(_DWORD *)(v68[0] + 20LL));
    }
LABEL_80:
    __break(0x800u);
    goto LABEL_75;
  }
  *(_DWORD *)(v8 + 4LL * a1) = 0;
  if ( a1 == 22 )
    goto LABEL_86;
  v9 = 0;
LABEL_19:
  *(_DWORD *)(v5 + 4LL * a1 + 20) = v9;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v12,
      "ipa_rm %s:%d resource bandwidth: %d voltage: %d\n",
      "ipa_rm_perf_profile_change",
      709,
      *(_DWORD *)(v8 + 4LL * a1),
      *(_DWORD *)(v68[0] + 8LL));
  }
  v13 = (_DWORD *)ipa_rm_ctx;
  v14 = *(_DWORD *)(ipa_rm_ctx + 20);
  v15 = *(_DWORD *)(ipa_rm_ctx + 52);
  v16 = *(_DWORD *)(ipa_rm_ctx + 64);
  if ( *(_DWORD *)(ipa_rm_ctx + 24) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 24);
  v17 = *(_DWORD *)(ipa_rm_ctx + 132);
  if ( *(_DWORD *)(ipa_rm_ctx + 28) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 28);
  if ( *(_DWORD *)(ipa_rm_ctx + 32) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 32);
  if ( *(_DWORD *)(ipa_rm_ctx + 36) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 36);
  if ( *(_DWORD *)(ipa_rm_ctx + 40) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 40);
  if ( *(_DWORD *)(ipa_rm_ctx + 44) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 44);
  if ( *(_DWORD *)(ipa_rm_ctx + 48) > v14 )
    v14 = *(_DWORD *)(ipa_rm_ctx + 48);
  if ( v15 <= v14 )
    v15 = v14;
  if ( *(_DWORD *)(ipa_rm_ctx + 56) > v15 )
    v15 = *(_DWORD *)(ipa_rm_ctx + 56);
  v19 = *(_DWORD *)(ipa_rm_ctx + 68);
  v18 = *(_DWORD *)(ipa_rm_ctx + 72);
  if ( *(_DWORD *)(ipa_rm_ctx + 60) > v15 )
    v15 = *(_DWORD *)(ipa_rm_ctx + 60);
  if ( v16 <= v15 )
    v16 = v15;
  v21 = *(_DWORD *)(ipa_rm_ctx + 76);
  v20 = *(_DWORD *)(ipa_rm_ctx + 80);
  if ( v19 <= v16 )
    v19 = v16;
  v22 = *(_DWORD *)(ipa_rm_ctx + 116) + *(_DWORD *)(ipa_rm_ctx + 124);
  v23 = *(_DWORD *)(ipa_rm_ctx + 112) + *(_DWORD *)(ipa_rm_ctx + 120);
  if ( v18 <= v19 )
    v18 = v19;
  v24 = *(_DWORD *)(ipa_rm_ctx + 144) + *(_DWORD *)(ipa_rm_ctx + 152);
  v25 = *(_DWORD *)(ipa_rm_ctx + 148) + *(_DWORD *)(ipa_rm_ctx + 156);
  v26 = *(_DWORD *)(ipa_rm_ctx + 140);
  if ( v21 <= v18 )
    v21 = v18;
  v27 = *(_DWORD *)(ipa_rm_ctx + 84);
  v28 = *(_DWORD *)(ipa_rm_ctx + 88);
  v29 = *(_DWORD *)(ipa_rm_ctx + 128) + *(_DWORD *)(ipa_rm_ctx + 136);
  *(_DWORD *)(ipa_rm_ctx + 108) = v21;
  if ( v20 <= v21 )
    v20 = v21;
  v30 = v23 + v29;
  v13[27] = v20;
  v31 = v22 + v17 + v26;
  if ( v27 <= v20 )
    v27 = v20;
  v33 = v13[23];
  v32 = v13[24];
  v34 = v13[42];
  v35 = v13[43];
  v37 = v13[44];
  v36 = v13[45];
  v13[27] = v27;
  if ( v28 <= v27 )
    v28 = v27;
  v38 = v35 + v36;
  v39 = v34 + v37;
  v40 = v13[40];
  v41 = v13[41];
  if ( v33 <= v28 )
    v33 = v28;
  v13[27] = v28;
  v42 = v13[25];
  v43 = v13[26];
  v44 = v24 + v40;
  v13[27] = v33;
  if ( v32 <= v33 )
    v32 = v33;
  v45 = v30 + v44;
  v47 = v13[46];
  v46 = v13[47];
  v13[27] = v32;
  v48 = v31 + v25 + v41;
  if ( v42 > v32 )
    v32 = v42;
  v49 = v13[48];
  v50 = v13[49];
  v51 = v38 + v46;
  v52 = v39 + v47;
  v13[27] = v32;
  if ( v43 > v32 )
    v32 = v43;
  v13[27] = v32;
  v53 = v48 + v51 + v50;
  v54 = v45 + v52 + v49;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v55 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v55,
      "ipa_rm %s:%d all prod bandwidth: %d all cons bandwidth: %d\n",
      "ipa_rm_perf_profile_change",
      728,
      v54,
      v53);
  }
  if ( v54 < v53 )
    v53 = v54;
  v56 = *(_DWORD *)(ipa_rm_ctx + 108);
  *(_DWORD *)(ipa_rm_ctx + 200) = v53;
  v57 = ipa3_get_ipc_logbuf_low();
  if ( v56 == v6 && v53 == v7 )
  {
    if ( v57 )
    {
      v58 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v58, "ipa_rm %s:%d same voting\n", "ipa_rm_perf_profile_change", 733);
    }
  }
  else
  {
    if ( v57 )
    {
      v59 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v59,
        "ipa_rm %s:%d new voting: voltage %d bandwidth %d\n",
        "ipa_rm_perf_profile_change",
        739,
        *(_DWORD *)(ipa_rm_ctx + 108),
        *(_DWORD *)(ipa_rm_ctx + 200));
    }
    v60 = *(_DWORD *)(ipa_rm_ctx + 108);
    v61 = *(_DWORD *)(ipa_rm_ctx + 200);
    v62 = _kmalloc_cache_noprof(ipc_log_string, 2336, 40);
    if ( v62 )
    {
      *(_QWORD *)v62 = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v62 + 8) = v62 + 8;
      *(_QWORD *)(v62 + 16) = v62 + 8;
      *(_QWORD *)(v62 + 24) = ipa_rm_perf_profile_notify_to_ipa_work;
      v63 = ipa_rm_ctx;
      *(_DWORD *)(v62 + 32) = v60;
      *(_DWORD *)(v62 + 36) = v61;
      queue_work_on(32, *(_QWORD *)(v63 + 8), v62);
    }
  }
LABEL_75:
  _ReadStatusReg(SP_EL0);
}
