_DWORD *__fastcall sps_bam_pipe_free(_DWORD *result, unsigned int a2)
{
  _DWORD *v2; // x20
  char *v4; // x8
  __int64 v5; // x21
  _QWORD **v6; // x22
  _QWORD *v7; // x0
  _QWORD *v8; // x8
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x9

  v2 = result;
  if ( result[12] <= a2 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = (_DWORD *)__ratelimit(&sps_bam_pipe_free__rs, "sps_bam_pipe_free"), (_DWORD)result) )
      {
        result = (_DWORD *)printk(&unk_2AF0B, "sps_bam_pipe_free", v2 + 6);
      }
    }
    if ( v2 )
      return (_DWORD *)ipc_log_string(
                         *((_QWORD *)v2 + 69),
                         "%s: sps:Invalid BAM %pa pipe: %d\n",
                         "sps_bam_pipe_free",
                         v2 + 6,
                         a2);
  }
  else if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    return (_DWORD *)pipe_clear();
  }
  else
  {
    v4 = (char *)&result[2 * a2];
    v5 = *((_QWORD *)v4 + 32);
    *((_QWORD *)v4 + 32) = 0;
    if ( v5 != -2290649225LL )
    {
      if ( v5 )
      {
        v6 = (_QWORD **)(v5 + 560);
        if ( *(_QWORD *)(v5 + 560) != v5 + 560 )
        {
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_bam_pipe_free__rs_112, "sps_bam_pipe_free")) )
          {
            printk(&unk_2AB9F, "sps_bam_pipe_free", v2 + 6);
          }
          if ( v2 )
            ipc_log_string(
              *((_QWORD *)v2 + 69),
              "%s: sps:Disconnect BAM %pa pipe %d with events pending\n",
              "sps_bam_pipe_free",
              v2 + 6,
              a2);
          v7 = *v6;
          if ( *v6 != v6 )
          {
            v8 = (_QWORD *)v7[1];
            if ( (_QWORD *)*v8 == v7 && (v9 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
            {
              *(_QWORD *)(v9 + 8) = v8;
              *v8 = v9;
            }
            else
            {
              _list_del_entry_valid_or_report(v7);
              v7 = v12;
            }
            *v7 = 0xDEAD000000000100LL;
            v7[1] = 0xDEAD000000000122LL;
            kfree(v7);
            if ( v5 != 0xDEACFFFFFFFFFED0LL )
            {
              while ( 1 )
              {
                v10 = (_QWORD *)MEMORY[0xDEAD000000000108];
                if ( *MEMORY[0xDEAD000000000108] == 0xDEAD000000000100LL
                  && (v11 = MEMORY[0xDEAD000000000100],
                      *(_QWORD *)(MEMORY[0xDEAD000000000100] + 8LL) == 0xDEAD000000000100LL) )
                {
                  *(_QWORD *)(MEMORY[0xDEAD000000000100] + 8LL) = MEMORY[0xDEAD000000000108];
                  *v10 = v11;
                }
                else
                {
                  _list_del_entry_valid_or_report(0xDEAD000000000100LL);
                }
                MEMORY[0xDEAD000000000100] = 0xDEAD000000000100LL;
                MEMORY[0xDEAD000000000108] = 0xDEAD000000000122LL;
                kfree(0xDEAD000000000100LL);
              }
            }
          }
        }
        *(_QWORD *)v5 = v5;
        *(_QWORD *)(v5 + 8) = v5;
        *(_QWORD *)(v5 + 184) = 0xFFFFFFFF00000000LL;
        *(_QWORD *)(v5 + 192) = 0;
        *(_QWORD *)(v5 + 216) = 0xFFFFFFFFLL;
        *(_DWORD *)(v5 + 224) = 0;
        *(_BYTE *)(v5 + 640) = 0;
        *(_BYTE *)(v5 + 208) = 0;
        result = memset((void *)(v5 + 232), 0, 0x198u);
        *(_QWORD *)(v5 + 560) = v6;
        *(_QWORD *)(v5 + 568) = v6;
      }
      else
      {
        if ( logging_option != 1 )
        {
          if ( (unsigned __int8)print_limit_option < 3u
            || (result = (_DWORD *)__ratelimit(&sps_bam_pipe_free__rs_109, "sps_bam_pipe_free"), (_DWORD)result) )
          {
            result = (_DWORD *)printk(&unk_232B3, "sps_bam_pipe_free", a2);
          }
        }
        if ( v2 )
          return (_DWORD *)ipc_log_string(
                             *((_QWORD *)v2 + 69),
                             "%s: sps:Attempt to free unallocated pipe %d on BAM %pa\n",
                             "sps_bam_pipe_free",
                             a2,
                             v2 + 6);
      }
    }
  }
  return result;
}
