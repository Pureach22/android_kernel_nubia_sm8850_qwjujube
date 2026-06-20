__int64 __fastcall sps_bam_pipe_disable(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x19
  _QWORD *v11; // x29
  __int64 v12; // x30
  int v14; // w0
  int v15; // w8
  __int64 v16; // [xsp+8h] [xbp-28h]
  _QWORD v17[3]; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+2Ch] [xbp-4h]

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_13;
  }
  v17[0] = v11;
  v17[1] = v12;
  v17[2] = v10;
  v11 = v17;
  v10 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( (*(_BYTE *)(v10 + 86) & 0x80) == 0 )
  {
    bam_pipe_disable(a1 + 216, a2);
    goto LABEL_8;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    v18 = a2;
    v16 = a1;
    if ( !print_limit_option )
    {
LABEL_11:
      printk(&unk_238F7, "sps_bam_pipe_disable", a1 + 24);
      a1 = v16;
      a2 = *((_DWORD *)v11 + 7);
      goto LABEL_5;
    }
LABEL_13:
    v14 = __ratelimit(&sps_bam_pipe_disable__rs, "sps_bam_pipe_disable");
    a2 = *((_DWORD *)v11 + 7);
    v15 = v14;
    a1 = a10;
    if ( !v15 )
      goto LABEL_5;
    goto LABEL_11;
  }
LABEL_5:
  if ( a1 && *(_DWORD *)(a1 + 568) <= 2u )
    ipc_log_string(
      *(_QWORD *)(a1 + 544),
      "%s: sps:BAM %pa pipe %d enters disable state\n",
      "sps_bam_pipe_disable",
      (const void *)(a1 + 24),
      a2);
LABEL_8:
  *(_DWORD *)(v10 + 184) &= ~8u;
  return 0;
}
