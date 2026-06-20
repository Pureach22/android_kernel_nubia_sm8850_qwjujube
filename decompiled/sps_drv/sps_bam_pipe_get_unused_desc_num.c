__int64 __fastcall sps_bam_pipe_get_unused_desc_num(__int64 a1, unsigned int a2, unsigned int *a3)
{
  unsigned int *v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v7; // x23
  _QWORD *v8; // x29
  __int64 v9; // x30
  __int64 v10; // x24
  __int64 v11; // x8
  const void *v12; // x3
  int v13; // w22
  unsigned int v14; // w8
  int v15; // w10
  int v17; // w24
  int v18; // w8
  _QWORD v19[8]; // [xsp+10h] [xbp-40h] BYREF

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_20;
  }
  v19[0] = v8;
  v19[1] = v9;
  v19[3] = v7;
  v19[4] = v6;
  v19[5] = v5;
  v19[6] = v4;
  v19[7] = v3;
  v8 = v19;
  LODWORD(v5) = a2;
  v6 = a1;
  v10 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( !v10 )
    return (unsigned int)-1;
  LODWORD(v7) = *(_DWORD *)(v10 + 224);
  v3 = a3;
  LODWORD(v4) = bam_pipe_get_desc_read_offset(a1 + 216, a2);
  if ( (*(_BYTE *)(v6 + 17) & 4) != 0 && (*(_BYTE *)(v10 + 184) & 0x10) == 0 )
  {
    LODWORD(a1) = *(_DWORD *)(v10 + 240);
    if ( (unsigned __int8)logging_option < 2u || (unsigned __int8)debug_level_option < 4u )
    {
LABEL_6:
      if ( v6 && !*(_DWORD *)(v6 + 568) )
      {
        v11 = *(_QWORD *)(v6 + 528);
        v12 = (const void *)(v6 + 24);
        v13 = a1;
        ipc_log_string(
          v11,
          "%s: sps:BAM %pa pipe %d: peer offset in cache:0x%x\n",
          "sps_bam_pipe_get_unused_desc_num",
          v12,
          v5,
          a1);
        LODWORD(a1) = v13;
      }
      goto LABEL_10;
    }
    if ( !print_limit_option )
    {
LABEL_18:
      *((_DWORD *)v8 - 1) = a1;
      printk(&unk_25AA4, "sps_bam_pipe_get_unused_desc_num", v6 + 24);
      LODWORD(a1) = *((_DWORD *)v8 - 1);
      goto LABEL_6;
    }
LABEL_20:
    v17 = a1;
    v18 = __ratelimit(&sps_bam_pipe_get_unused_desc_num__rs, "sps_bam_pipe_get_unused_desc_num");
    LODWORD(a1) = v17;
    if ( !v18 )
      goto LABEL_6;
    goto LABEL_18;
  }
  LODWORD(a1) = bam_pipe_get_desc_write_offset(v6 + 216, v5);
LABEL_10:
  v14 = 0;
  if ( (unsigned int)a1 >= (unsigned int)v4 )
    v15 = 0;
  else
    v15 = v7;
  *v3 = (unsigned int)(a1 - v4 + v15) >> 3;
  return v14;
}
