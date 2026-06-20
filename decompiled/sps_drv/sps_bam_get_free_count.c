__int64 __fastcall sps_bam_get_free_count(__int64 a1, __int64 a2, unsigned int *a3)
{
  int v4; // w20
  __int64 v5; // x8
  __int64 v6; // x21
  unsigned int v7; // w8
  __int64 result; // x0
  unsigned int v9; // w10
  unsigned int v10; // w8
  int v11; // w9
  unsigned int v12; // w9
  bool v13; // cf
  unsigned int v14; // w8
  unsigned int v15; // w9
  int v16; // w8
  __int64 v17; // [xsp+18h] [xbp-18h]

  if ( (unsigned int)a2 >= 0x1F )
  {
    __break(0x5512u);
    return sps_bam_pipe_inject_zlt(a1, a2);
  }
  else
  {
    v4 = a2;
    v5 = *(_QWORD *)(a1 + 8LL * (unsigned int)a2 + 256);
    if ( (*(_BYTE *)(v5 + 184) & 0x50) != 0 )
    {
      if ( logging_option != 1 )
      {
        if ( (unsigned __int8)print_limit_option < 3u
          || (v17 = a1, v16 = __ratelimit(&sps_bam_get_free_count__rs, "sps_bam_get_free_count"), a1 = v17, v16) )
        {
          v6 = a1;
          printk(&unk_243D1, "sps_bam_get_free_count", a1 + 24);
          a1 = v6;
        }
      }
      if ( a1 )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Free count on BAM-to-BAM or remote: BAM %pa pipe %d\n",
          "sps_bam_get_free_count",
          (const void *)(a1 + 24),
          v4);
      v7 = 0;
      result = 0xFFFFFFFFLL;
    }
    else
    {
      v9 = *(_DWORD *)(v5 + 224);
      result = 0;
      v11 = *(_DWORD *)(v5 + 240);
      v10 = *(_DWORD *)(v5 + 244);
      v12 = v11 + 8;
      if ( v12 >= v9 )
        v12 = 0;
      v13 = v10 >= v12;
      v14 = v10 - v12;
      if ( v13 )
        v15 = 0;
      else
        v15 = v9;
      v7 = (v14 + v15) >> 3;
    }
    *a3 = v7;
  }
  return result;
}
