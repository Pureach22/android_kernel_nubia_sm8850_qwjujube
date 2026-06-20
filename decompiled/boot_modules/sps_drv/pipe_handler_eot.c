__int64 __fastcall pipe_handler_eot(__int64 result, __int64 a2)
{
  unsigned int v2; // w22
  __int64 v4; // x20
  int v5; // w25
  unsigned int v6; // w21
  unsigned int v7; // w9
  int v8; // w8
  __int64 v9; // x23
  int v10; // w24
  int v11; // w0
  __int64 v12; // x28
  __int64 v13; // x24
  unsigned int v14; // w22
  __int64 *v15; // x9
  _QWORD *v16; // x8
  __int64 *v17; // x10
  _QWORD *v18; // x11
  unsigned __int64 v19; // x13
  __int64 *v20; // x12
  __int64 v21; // t1
  unsigned __int64 i; // x9
  __int64 v23; // t1
  unsigned int *v24; // x27
  __int64 *v25; // x25
  const char *v26; // x9
  unsigned int v27; // w8
  int v28; // w8
  __int64 v29; // x10
  __int64 v30; // x1
  unsigned int v31; // w23
  int v32; // [xsp+1Ch] [xbp-4h]

  v2 = *(_DWORD *)(a2 + 188);
  v4 = result;
  if ( *(_DWORD *)(a2 + 632) )
  {
    if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
    {
      if ( !print_limit_option )
      {
LABEL_71:
        result = printk(&unk_2A3C3, "pipe_handler_eot", v2);
        goto LABEL_3;
      }
      result = __ratelimit(&pipe_handler_eot__rs, "pipe_handler_eot");
      if ( (_DWORD)result )
      {
        v2 = *(_DWORD *)(a2 + 188);
        goto LABEL_71;
      }
    }
LABEL_3:
    if ( v4 )
    {
      if ( !*(_DWORD *)(v4 + 568) )
        return ipc_log_string(
                 *(_QWORD *)(v4 + 528),
                 "%s: sps: still handling EOT for pipe %d\n",
                 "pipe_handler_eot",
                 *(unsigned int *)(a2 + 188));
    }
    return result;
  }
  v5 = *(_DWORD *)(a2 + 216);
  *(_DWORD *)(a2 + 632) = 1;
  result = bam_pipe_get_desc_read_offset(result + 216, v2);
  v6 = result;
  if ( !*(_DWORD *)(v4 + 568) )
  {
    if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
    {
      if ( !print_limit_option || (result = __ratelimit(&pipe_handler_eot__rs_294, "pipe_handler_eot"), (_DWORD)result) )
      {
        v31 = *(_DWORD *)(a2 + 188);
        bam_pipe_get_desc_write_offset(v4 + 216, v2);
        result = printk(&unk_25EC2, "pipe_handler_eot", v31);
      }
    }
    if ( v4 && !*(_DWORD *)(v4 + 568) )
    {
      v9 = *(_QWORD *)(v4 + 528);
      v10 = *(_DWORD *)(a2 + 188);
      v11 = bam_pipe_get_desc_write_offset(v4 + 216, v2);
      result = ipc_log_string(
                 v9,
                 "%s: sps: pipe index:%d; read pointer:0x%x; write pointer:0x%x; sys.acked_offset:0x%x\n",
                 "pipe_handler_eot",
                 v10,
                 v6,
                 v11,
                 *(_DWORD *)(a2 + 244));
    }
  }
  if ( !v5 && *(_BYTE *)(a2 + 208) == 1 )
  {
    v7 = v6;
    if ( !v6 )
      v6 = *(_DWORD *)(a2 + 224);
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 232) + v6 - 1LL) & 0x40) != 0 )
      v6 = v7;
    else
      v6 -= 8;
  }
  v8 = *(_DWORD *)(a2 + 628);
  if ( *(_DWORD *)(a2 + 624) )
  {
    if ( !v8 )
      *(_DWORD *)(a2 + 244) = v6;
    *(_DWORD *)(a2 + 632) = 0;
    if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
    {
      if ( !print_limit_option || (result = __ratelimit(&pipe_handler_eot__rs_297, "pipe_handler_eot"), (_DWORD)result) )
        result = printk(&unk_24410, "pipe_handler_eot", *(unsigned int *)(a2 + 188));
    }
    if ( v4 && !*(_DWORD *)(v4 + 568) )
      return ipc_log_string(
               *(_QWORD *)(v4 + 528),
               "%s: sps: pipe %d has no queue\n",
               "pipe_handler_eot",
               *(unsigned int *)(a2 + 188));
  }
  else
  {
    if ( v8 )
      v12 = 256;
    else
      v12 = 244;
    v13 = *(unsigned int *)(a2 + v12);
    if ( (_DWORD)v13 == v6 )
    {
      *(_DWORD *)(a2 + 632) = 0;
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
      {
        if ( !print_limit_option
          || (result = __ratelimit(&pipe_handler_eot__rs_300, "pipe_handler_eot"), (_DWORD)result) )
        {
          result = printk(&unk_251EC, "pipe_handler_eot", *(unsigned int *)(a2 + 188));
        }
      }
      if ( v4 && !*(_DWORD *)(v4 + 568) )
        return ipc_log_string(
                 *(_QWORD *)(v4 + 528),
                 "%s: sps: there is no completed desc to process for pipe %d\n",
                 "pipe_handler_eot",
                 *(unsigned int *)(a2 + 188));
    }
    else
    {
      v32 = (*(_DWORD *)(a2 + 196) << 9) & 0x4000;
      v14 = v32 | ((*(_DWORD *)(a2 + 196) & 1) << 15);
      if ( !v5 )
      {
        v15 = *(__int64 **)(a2 + 232);
        v16 = *(_QWORD **)(a2 + 248);
        v17 = (__int64 *)((char *)v15 + v13);
        v18 = (_QWORD *)((char *)v16 + v13);
        if ( v6 >= (unsigned int)v13 )
        {
          v16 = (_QWORD *)((char *)v16 + v13);
          v20 = (__int64 *)((char *)v15 + v13);
        }
        else
        {
          v19 = (unsigned __int64)v15 + *(unsigned int *)(a2 + 224);
          v20 = *(__int64 **)(a2 + 232);
          if ( (unsigned __int64)v17 < v19 )
          {
            do
            {
              v21 = *v17++;
              *v18++ = v21;
            }
            while ( (unsigned __int64)v17 < v19 );
            v15 = *(__int64 **)(a2 + 232);
            v16 = *(_QWORD **)(a2 + 248);
            v20 = v15;
          }
        }
        for ( i = (unsigned __int64)v15 + v6; (unsigned __int64)v20 < i; ++v16 )
        {
          v23 = *v20++;
          *v16 = v23;
        }
      }
      v24 = (unsigned int *)(*(_QWORD *)(a2 + 248) + v13);
      v25 = (__int64 *)(*(_QWORD *)(a2 + 264) + ((unsigned int)v13 & 0xFFFFFFF8));
      while ( 1 )
      {
        if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
        {
          if ( !print_limit_option
            || (result = __ratelimit(&pipe_handler_eot__rs_303, "pipe_handler_eot"), (_DWORD)result) )
          {
            result = printk(&unk_28362, "pipe_handler_eot", *(unsigned int *)(a2 + 188));
          }
        }
        if ( v4 && !*(_DWORD *)(v4 + 568) )
        {
          v26 = "not";
          if ( !*v25 )
            v26 = (const char *)&unk_24626;
          result = ipc_log_string(
                     *(_QWORD *)(v4 + 528),
                     "%s: sps: pipe index:%d; iovec addr:0x%pK; size:0x%x; flags:0x%x; enabled:0x%x; *user is %s NULL\n",
                     "pipe_handler_eot",
                     *(unsigned int *)(a2 + 188),
                     *v24,
                     (unsigned __int16)v24[1],
                     HIWORD(v24[1]),
                     v14,
                     v26);
        }
        if ( (unsigned int)(v13 + 8) >= *(_DWORD *)(a2 + 224) )
          LODWORD(v13) = 0;
        else
          LODWORD(v13) = v13 + 8;
        *(_DWORD *)(a2 + v12) = v13;
        v27 = HIWORD(v24[1]);
        if ( *v25 || (v27 & v14) != 0 )
        {
          *(_QWORD *)(a2 + 608) = 0;
          *(_QWORD *)(a2 + 616) = 0;
          *(_QWORD *)(a2 + 592) = 0;
          *(_QWORD *)(a2 + 600) = 0;
          *(_QWORD *)(a2 + 576) = 0;
          *(_QWORD *)(a2 + 584) = 0;
          if ( (v27 & v32) != 0 )
            v28 = 1;
          else
            v28 = 2;
          *(_QWORD *)(a2 + 608) = *(_QWORD *)v24;
          v29 = *v25;
          v30 = a2 + 272 + 32LL * (unsigned int)(v28 - 1);
          *(_DWORD *)(a2 + 600) = v28;
          *(_QWORD *)(a2 + 616) = v29;
          *(_QWORD *)(a2 + 592) = *(_QWORD *)(v30 + 24);
          result = trigger_event(v4, v30, a2 + 576);
        }
        if ( (_DWORD)v13 == v6 )
          break;
        if ( (_DWORD)v13 )
        {
          v24 += 2;
          ++v25;
        }
        else
        {
          v24 = *(unsigned int **)(a2 + 248);
          v25 = *(__int64 **)(a2 + 264);
        }
      }
      *(_DWORD *)(a2 + 632) = 0;
    }
  }
  return result;
}
