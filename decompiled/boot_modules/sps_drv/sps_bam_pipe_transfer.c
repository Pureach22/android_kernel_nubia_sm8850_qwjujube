__int64 __fastcall sps_bam_pipe_transfer(__int64 a1, unsigned int a2, __int64 a3)
{
  _DWORD *v6; // x22
  unsigned int v7; // w22
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x22
  _DWORD *v11; // x24
  int v12; // w5
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0x1F )
    __break(0x5512u);
  if ( *(_DWORD *)(a3 + 16) )
  {
    v13 = 0;
    v6 = *(_DWORD **)(a1 + 8LL * a2 + 256);
    if ( v6[157] || !v6[50] )
    {
      sps_bam_get_free_count(a1, a2, &v13);
      v7 = v13;
    }
    else
    {
      sps_bam_pipe_get_unused_desc_num(a1, a2, &v13);
      v7 = ~v13 + (v6[56] >> 3);
      v13 = v7;
    }
    v8 = *(_DWORD *)(a3 + 16);
    if ( v7 >= v8 )
    {
      if ( v8 - 1 < 0 )
      {
LABEL_26:
        result = 0;
        goto LABEL_27;
      }
      v10 = 0;
      v11 = (_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL);
      while ( 1 )
      {
        --v8;
        v12 = HIWORD(*v11);
        if ( v8 )
          v12 |= 0x20u;
        else
          v10 = *(_QWORD *)(a3 + 24);
        if ( (unsigned int)sps_bam_pipe_transfer_one(a1, a2, *(v11 - 1), (unsigned __int16)*v11, v10, v12) )
          break;
        v11 += 2;
        if ( v8 < 1 )
          goto LABEL_26;
      }
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_transfer__rs_211, "sps_bam_pipe_transfer")) )
      {
        printk(&unk_23927, "sps_bam_pipe_transfer", a1 + 24);
      }
      if ( a1 )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Insufficient free desc: BAM %pa pipe %d: %d\n",
          "sps_bam_pipe_transfer",
          (const void *)(a1 + 24),
          a2,
          v7);
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_transfer__rs, "sps_bam_pipe_transfer")) )
    {
      printk(&unk_22EA8, "sps_bam_pipe_transfer", a1 + 24);
    }
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:iovec count zero: BAM %pa pipe %d\n",
        "sps_bam_pipe_transfer",
        (const void *)(a1 + 24),
        a2);
  }
  result = 0xFFFFFFFFLL;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
