__int64 __fastcall print_bam_pipe_reg(__int64 result, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v4; // x8
  __int64 v5; // x8
  int v6; // w9
  int v7; // w22
  __int64 v8; // x9
  unsigned int v9; // w19
  unsigned int v10; // w27
  int v11; // w9
  int v12; // w21
  __int64 v13; // x8
  int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x8
  int v17; // w21
  __int64 v18; // x8
  int v19; // w8
  int v20; // [xsp+8h] [xbp-8h]
  unsigned int v21; // [xsp+Ch] [xbp-4h]

  if ( !result )
    return result;
  v2 = result;
  if ( sps )
  {
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s: \nsps:<pipe-begin> --- Content of Pipe %d registers ---\n",
               "print_bam_pipe_reg",
               a2);
    v4 = sps;
    if ( sps )
    {
      if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_24009, "print_bam_pipe_reg", a2), (v4 = sps) != 0) )
      {
        result = ipc_log_string(
                   *(_QWORD *)(v4 + 280),
                   "%s: %s",
                   "print_bam_pipe_reg",
                   "-- Pipe Management Registers --\n");
        if ( sps )
        {
          if ( !*(_QWORD *)(sps + 280) )
            result = printk(&unk_2919C, "print_bam_pipe_reg", "-- Pipe Management Registers --\n");
        }
      }
    }
  }
  v21 = a2;
  v5 = sps;
  if ( bam_type == 2 )
    v6 = 77824;
  else
    v6 = 4096;
  v7 = v6 + (a2 << 12);
  v8 = sps;
  v20 = a2 << 12;
  v9 = v7 | 0x80;
  do
  {
    while ( 1 )
    {
      if ( !v8 )
        goto LABEL_14;
      result = ipc_log_string(
                 *(_QWORD *)(v8 + 280),
                 "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                 "print_bam_pipe_reg",
                 v7,
                 *(_DWORD *)(v2 + 4LL * (v7 >> 2)),
                 *(_DWORD *)(v2 + 4 * (((__int64)v7 >> 2) | 1)),
                 *(_DWORD *)(v2 + 4 * (((__int64)v7 >> 2) | 2)),
                 *(_DWORD *)(v2 + 4 * (((__int64)v7 >> 2) | 3)));
      v5 = sps;
      if ( sps )
        break;
      v7 += 16;
      v8 = 0;
      if ( v7 >= v9 )
      {
        v10 = v21;
        if ( bam_type == 2 )
          v14 = 79872;
        else
          v14 = 6144;
        v12 = v14 + v20;
LABEL_35:
        v13 = sps;
        if ( !sps )
          return result;
        goto LABEL_36;
      }
    }
    v8 = sps;
    if ( !*(_QWORD *)(sps + 280) )
    {
      result = printk(&unk_28B50, "print_bam_pipe_reg", (unsigned int)v7);
      v5 = sps;
      v8 = sps;
    }
LABEL_14:
    v7 += 16;
  }
  while ( v7 < v9 );
  v10 = v21;
  if ( !v5 )
  {
LABEL_23:
    if ( bam_type == 2 )
      v11 = 79872;
    else
      v11 = 6144;
    v12 = v11 + v20;
    if ( sps )
    {
      result = ipc_log_string(
                 *(_QWORD *)(sps + 280),
                 "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                 "print_bam_pipe_reg",
                 v12,
                 *(_DWORD *)(v2 + 4LL * (v12 >> 2)),
                 *(_DWORD *)(v2 + 4 * (((__int64)v12 >> 2) | 1)),
                 *(_DWORD *)(v2 + 4 * (((__int64)v12 >> 2) | 2)),
                 *(_DWORD *)(v2 + 4 * (((__int64)v12 >> 2) | 3)));
      if ( !sps )
        return result;
      if ( !*(_QWORD *)(sps + 280) )
      {
        result = printk(&unk_28B50, "print_bam_pipe_reg", (unsigned int)v12);
        v13 = sps;
        if ( !sps )
          return result;
        goto LABEL_36;
      }
    }
    goto LABEL_35;
  }
  result = ipc_log_string(
             *(_QWORD *)(v5 + 280),
             "%s: %s",
             "print_bam_pipe_reg",
             "-- Pipe Configuration and Internal State Registers --\n");
  if ( sps )
  {
    if ( !*(_QWORD *)(sps + 280) )
      result = printk(&unk_2919C, "print_bam_pipe_reg", "-- Pipe Configuration and Internal State Registers --\n");
    goto LABEL_23;
  }
  if ( bam_type == 2 )
    v19 = 79872;
  else
    v19 = 6144;
  v12 = v19 + v20;
  v13 = sps;
  if ( !sps )
    return result;
LABEL_36:
  result = ipc_log_string(
             *(_QWORD *)(v13 + 280),
             "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
             "print_bam_pipe_reg",
             v12 | 0x10u,
             *(_DWORD *)(v2 + 4LL * ((v12 | 0x10) >> 2)),
             *(_DWORD *)(v2 + 4 * (((__int64)(v12 | 0x10) >> 2) | 1)),
             *(_DWORD *)(v2 + 4 * (((__int64)(v12 | 0x10) >> 2) | 2)),
             *(_DWORD *)(v2 + 4 * (((__int64)(v12 | 0x10) >> 2) | 3)));
  v15 = sps;
  if ( sps )
  {
    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_28B50, "print_bam_pipe_reg", v12 | 0x10u), (v15 = sps) != 0) )
    {
      result = ipc_log_string(
                 *(_QWORD *)(v15 + 280),
                 "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                 "print_bam_pipe_reg",
                 v12 | 0x20u,
                 *(_DWORD *)(v2 + 4LL * ((v12 | 0x20) >> 2)),
                 *(_DWORD *)(v2 + 4 * (((__int64)(v12 | 0x20) >> 2) | 1)),
                 *(_DWORD *)(v2 + 4 * (((__int64)(v12 | 0x20) >> 2) | 2)),
                 *(_DWORD *)(v2 + 4 * (((__int64)(v12 | 0x20) >> 2) | 3)));
      v16 = sps;
      if ( sps )
      {
        if ( *(_QWORD *)(sps + 280)
          || (result = printk(&unk_28B50, "print_bam_pipe_reg", v12 | 0x20u), (v16 = sps) != 0) )
        {
          v17 = v12 | 0x30;
          result = ipc_log_string(
                     *(_QWORD *)(v16 + 280),
                     "%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                     "print_bam_pipe_reg",
                     v17,
                     *(_DWORD *)(v2 + 4LL * (v17 >> 2)),
                     *(_DWORD *)(v2 + 4 * (((__int64)v17 >> 2) | 1)),
                     *(_DWORD *)(v2 + 4 * (((__int64)v17 >> 2) | 2)),
                     *(_DWORD *)(v2 + 4 * (((__int64)v17 >> 2) | 3)));
          if ( sps )
          {
            if ( *(_QWORD *)(sps + 280) )
            {
              v18 = sps;
              if ( !sps )
                return result;
            }
            else
            {
              result = printk(&unk_28B50, "print_bam_pipe_reg", (unsigned int)v17);
              v18 = sps;
              if ( !sps )
                return result;
            }
            result = ipc_log_string(
                       *(_QWORD *)(v18 + 280),
                       "%s: \nsps:<pipe-end> --- Content of Pipe %d registers ---\n",
                       "print_bam_pipe_reg",
                       v10);
            if ( sps )
            {
              if ( !*(_QWORD *)(sps + 280) )
                return printk(&unk_2AFB4, "print_bam_pipe_reg", v10);
            }
          }
        }
      }
    }
  }
  return result;
}
