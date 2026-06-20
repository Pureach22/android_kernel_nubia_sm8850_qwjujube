_DWORD *__fastcall print_bam_reg(_DWORD *result)
{
  __int64 v1; // x8
  _DWORD *v2; // x19
  __int64 v3; // x9
  __int64 v4; // x10
  unsigned int v5; // w22
  unsigned int v6; // w21
  unsigned int v7; // w20
  unsigned __int64 v8; // x20
  unsigned __int64 v9; // x26
  __int64 v10; // x9
  int v11; // w25
  int v12; // w21
  int v13; // w26
  __int64 v14; // x9

  if ( !result )
    return result;
  v1 = sps;
  v2 = result;
  v3 = 1026;
  if ( bam_type == 2 )
  {
    v4 = 1024;
  }
  else
  {
    v3 = 15;
    v4 = 1;
  }
  if ( sps )
  {
    v5 = *result;
    v6 = result[v4];
    v7 = result[v3];
    result = (_DWORD *)ipc_log_string(
                         *(_QWORD *)(sps + 280),
                         "%s: %s",
                         "print_bam_reg",
                         "\nsps:<bam-begin> --- Content of BAM-level registers---\n");
    v1 = sps;
    if ( sps )
    {
      if ( *(_QWORD *)(sps + 280)
        || (result = (_DWORD *)printk(
                                 &unk_2919C,
                                 "print_bam_reg",
                                 "\nsps:<bam-begin> --- Content of BAM-level registers---\n"),
            (v1 = sps) != 0) )
      {
        result = (_DWORD *)ipc_log_string(*(_QWORD *)(v1 + 280), "%s: BAM_CTRL: 0x%x\n", "print_bam_reg", v5);
        v1 = sps;
        if ( sps )
        {
          if ( *(_QWORD *)(sps + 280) || (result = (_DWORD *)printk(&unk_27646, "print_bam_reg", v5), (v1 = sps) != 0) )
          {
            result = (_DWORD *)ipc_log_string(*(_QWORD *)(v1 + 280), "%s: BAM_REVISION: 0x%x\n", "print_bam_reg", v6);
            v1 = sps;
            if ( sps )
            {
              if ( *(_QWORD *)(sps + 280)
                || (result = (_DWORD *)printk(&unk_2531C, "print_bam_reg", v6), (v1 = sps) != 0) )
              {
                result = (_DWORD *)ipc_log_string(*(_QWORD *)(v1 + 280), "%s: NUM_PIPES: 0x%x\n", "print_bam_reg", v7);
                v1 = sps;
                if ( sps )
                {
                  if ( !*(_QWORD *)(sps + 280) )
                  {
                    result = (_DWORD *)printk(&unk_2657F, "print_bam_reg", v7);
                    v1 = sps;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v8 = 0;
  if ( bam_type == 2 )
    v9 = 12316;
  else
    v9 = 128;
  v10 = v1;
  do
  {
    if ( v10 )
    {
      result = (_DWORD *)ipc_log_string(
                           *(_QWORD *)(v10 + 280),
                           "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                           "print_bam_reg",
                           v8,
                           v2[v8 / 4],
                           v2[v8 / 4 + 1],
                           v2[v8 / 4 + 2],
                           v2[v8 / 4 + 3]);
      v1 = sps;
      if ( sps )
      {
        v10 = sps;
        if ( !*(_QWORD *)(sps + 280) )
        {
          result = (_DWORD *)printk(&unk_28B50, "print_bam_reg", (unsigned int)v8);
          v1 = sps;
          v10 = sps;
        }
      }
      else
      {
        v10 = 0;
      }
    }
    v8 += 16LL;
  }
  while ( v8 < v9 );
  v11 = 1;
  if ( bam_type == 2 )
    v12 = 12288;
  else
    v12 = 2048;
  if ( bam_type == 2 )
    v13 = 4096;
  else
    v13 = 128;
  v14 = v1;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !v14 )
        goto LABEL_36;
      result = (_DWORD *)ipc_log_string(
                           *(_QWORD *)(v14 + 280),
                           "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                           "print_bam_reg",
                           v12,
                           v2[v12 >> 2],
                           v2[((__int64)v12 >> 2) | 1],
                           v2[((__int64)v12 >> 2) | 2],
                           v2[((__int64)v12 >> 2) | 3]);
      v1 = sps;
      if ( sps )
        break;
      if ( ++v11 == 9 )
        return result;
      v1 = 0;
      v14 = 0;
      v12 += v13;
    }
    v14 = sps;
    if ( !*(_QWORD *)(sps + 280) )
    {
      result = (_DWORD *)printk(&unk_28B50, "print_bam_reg", (unsigned int)v12);
      v1 = sps;
      v14 = sps;
    }
LABEL_36:
    if ( ++v11 == 9 )
      break;
    v12 += v13;
  }
  if ( v1 )
  {
    result = (_DWORD *)ipc_log_string(
                         *(_QWORD *)(v1 + 280),
                         "%s: %s",
                         "print_bam_reg",
                         "\nsps:<bam-begin> --- Content of BAM-level registers ---\n");
    if ( sps )
    {
      if ( !*(_QWORD *)(sps + 280) )
        return (_DWORD *)printk(
                           &unk_2919C,
                           "print_bam_reg",
                           "\nsps:<bam-begin> --- Content of BAM-level registers ---\n");
    }
  }
  return result;
}
