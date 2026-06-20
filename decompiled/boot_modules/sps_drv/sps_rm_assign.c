__int64 __fastcall sps_rm_assign(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w8
  int v4; // w8
  __int64 v5; // x9
  __int64 v7; // x8
  int v8; // w8
  __int64 v9; // x10
  __int64 v10; // x19
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x13
  __int64 v16; // x14
  __int64 v17; // x11
  __int64 v18; // x13
  __int64 v19; // x14
  __int64 v20; // x19
  __int64 v21; // x20
  __int64 v22; // x19
  __int64 v23; // x20
  int v24; // w0
  int v25; // w8

  if ( !*(_DWORD *)(a1 + 76) )
  {
    if ( !*(_QWORD *)(a2 + 168) )
    {
      v7 = *(_QWORD *)(a2 + 48);
      if ( v7 )
      {
        *(_QWORD *)(a2 + 168) = a1;
        *(_QWORD *)(a1 + 24) = v7;
        v8 = *(_DWORD *)(a1 + 152);
        *(_DWORD *)(a1 + 188) = *(_DWORD *)(a2 + 32);
        if ( v8 != -858993460 )
          *(_DWORD *)(a2 + 36) = v8;
        v4 = *(_DWORD *)(a1 + 156);
        if ( v4 == -858993460 )
          goto LABEL_21;
        v5 = 40;
        goto LABEL_20;
      }
      goto LABEL_27;
    }
LABEL_9:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_assign__rs, "sps_rm_assign")) )
    {
      printk(&unk_2B24F, "sps_rm_assign", "sps_rm_assign");
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:%s:The end point is already connected\n",
        "sps_rm_assign",
        "sps_rm_assign");
    return 0xFFFFFFFFLL;
  }
  if ( *(_QWORD *)(a2 + 176) )
    goto LABEL_9;
  v2 = *(_QWORD *)(a2 + 88);
  if ( !v2 )
  {
LABEL_27:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_assign__rs_25, "sps_rm_assign")) )
    {
      printk(&unk_2A8A5, "sps_rm_assign", "sps_rm_assign");
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:%s:The end point is empty\n", "sps_rm_assign", "sps_rm_assign");
    return 0xFFFFFFFFLL;
  }
  *(_QWORD *)(a2 + 176) = a1;
  *(_QWORD *)(a1 + 24) = v2;
  v3 = *(_DWORD *)(a1 + 152);
  *(_DWORD *)(a1 + 188) = *(_DWORD *)(a2 + 72);
  if ( v3 != -858993460 )
    *(_DWORD *)(a2 + 76) = v3;
  v4 = *(_DWORD *)(a1 + 156);
  if ( v4 == -858993460 )
    goto LABEL_21;
  v5 = 80;
LABEL_20:
  *(_DWORD *)(a2 + v5) = v4;
LABEL_21:
  *(_QWORD *)(a1 + 176) = a2;
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( !print_limit_option
      || (v22 = a1,
          v23 = a2,
          v24 = __ratelimit(&sps_rm_assign__rs_28, "sps_rm_assign"),
          a2 = v23,
          v25 = v24,
          a1 = v22,
          v25) )
    {
      v20 = a1;
      v21 = a2;
      printk(&unk_26509, "sps_rm_assign", "sps_rm_assign");
      a2 = v21;
      a1 = v20;
    }
  }
  v9 = *(_QWORD *)(a1 + 24);
  if ( v9 && !*(_DWORD *)(v9 + 568) )
  {
    v10 = a1;
    v11 = a2;
    ipc_log_string(
      *(_QWORD *)(v9 + 528),
      "%s: sps:%s.bam %pa.pipe_index=%d\n",
      "sps_rm_assign",
      "sps_rm_assign",
      (const void *)(v9 + 24),
      *(_DWORD *)(a1 + 188));
    v9 = *(_QWORD *)(v10 + 24);
    a2 = v11;
    a1 = v10;
  }
  *(_DWORD *)(a1 + 48) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a1 + 72) = *(_DWORD *)(a2 + 72);
  if ( (*(_BYTE *)(v9 + 17) & 2) != 0 )
  {
    v13 = *(_QWORD *)(a1 + 104);
    v12 = *(_QWORD *)(a1 + 136);
  }
  else
  {
    v12 = 0;
    v13 = 0;
  }
  v14 = *(_QWORD *)(a2 + 120);
  v15 = *(_QWORD *)(a2 + 96);
  v16 = *(_QWORD *)(a2 + 104);
  *(_QWORD *)(a1 + 104) = *(_QWORD *)(a2 + 112);
  *(_QWORD *)(a1 + 112) = v14;
  *(_QWORD *)(a1 + 88) = v15;
  *(_QWORD *)(a1 + 96) = v16;
  v17 = *(_QWORD *)(a2 + 152);
  v18 = *(_QWORD *)(a2 + 128);
  v19 = *(_QWORD *)(a2 + 136);
  *(_QWORD *)(a1 + 136) = *(_QWORD *)(a2 + 144);
  *(_QWORD *)(a1 + 144) = v17;
  *(_QWORD *)(a1 + 120) = v18;
  *(_QWORD *)(a1 + 128) = v19;
  if ( (*(_BYTE *)(v9 + 17) & 2) != 0 )
  {
    *(_QWORD *)(a1 + 104) = v13;
    *(_QWORD *)(a1 + 136) = v12;
  }
  *(_DWORD *)(a1 + 16) = 22237267;
  return 0;
}
