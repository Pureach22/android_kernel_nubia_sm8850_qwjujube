__int64 __fastcall sps_bam_pipe_disconnect(__int64 a1, unsigned int a2)
{
  __int64 *v2; // x21
  __int64 v3; // x23
  __int64 v4; // x24
  unsigned int v7; // w22
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 **v10; // x8
  __int64 v11; // x9
  __int64 *v12; // x10
  int v13; // w8
  int v14; // w22
  __int64 v15; // x0
  size_t v16; // x2

  if ( *(_DWORD *)(a1 + 48) > a2 )
  {
    if ( a2 >= 0x1F )
    {
      __break(0x5512u);
    }
    else
    {
      v3 = a2;
      v4 = a1 + 256;
      v2 = *(__int64 **)(a1 + 256 + 8LL * a2);
      v7 = -1;
      if ( v2 == (__int64 *)-2290649225LL || !v2 )
      {
LABEL_30:
        if ( !v2 || v2 == (__int64 *)-2290649225LL )
        {
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_bam_pipe_disconnect__rs_158, "sps_bam_pipe_disconnect")) )
          {
            printk(&unk_25109, "sps_bam_pipe_disconnect", a1 + 24);
          }
          if ( a1 )
            ipc_log_string(
              *(_QWORD *)(a1 + 552),
              "%s: sps:BAM %pa pipe %d already disconnected\n",
              "sps_bam_pipe_disconnect",
              a1 + 24,
              a2);
        }
        return v7;
      }
      v8 = 1LL << a2;
      if ( ((1LL << a2) & *(unsigned int *)(a1 + 248)) != 0 )
      {
        v9 = raw_spin_lock_irqsave(a1 + 228);
        v10 = (__int64 **)v2[1];
        v11 = v9;
        if ( *v10 == v2 && (v12 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
        {
          v12[1] = (__int64)v10;
          *v10 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        v13 = *(_DWORD *)(a1 + 248) & ~(_DWORD)v8;
        v14 = ~(_DWORD)v8;
        *(_DWORD *)(a1 + 248) = v13;
        raw_spin_unlock_irqrestore(a1 + 228, v11);
      }
      else
      {
        v14 = ~(_DWORD)v8;
      }
      *(_DWORD *)(a1 + 252) &= v14;
      if ( (*((_BYTE *)v2 + 86) & 0x80) == 0 )
      {
        bam_pipe_exit(a1 + 216, a2, *(_DWORD *)(a1 + 128));
LABEL_22:
        v15 = v2[31];
        if ( v15 )
        {
          v16 = (unsigned int)(*((_DWORD *)v2 + 56) + 8 * *((_DWORD *)v2 + 55));
          if ( (unsigned int)v16 > 0x1000 )
          {
            vfree();
          }
          else if ( (*(_BYTE *)(a1 + 17) & 1) != 0 )
          {
            memset((void *)v2[31], 0, v16);
          }
          else
          {
            kfree(v15);
          }
          v2[31] = 0;
        }
        *(_QWORD *)(v4 + 8 * v3) = -2290649225LL;
        *v2 = (__int64)v2;
        v2[1] = (__int64)v2;
        v2[23] = 0xFFFFFFFF00000000LL;
        v2[24] = 0;
        v2[27] = 0xFFFFFFFFLL;
        *((_DWORD *)v2 + 56) = 0;
        *((_BYTE *)v2 + 640) = 0;
        *((_BYTE *)v2 + 208) = 0;
        memset(v2 + 29, 0, 0x198u);
        v7 = 0;
        v2[70] = (__int64)(v2 + 70);
        v2[71] = (__int64)(v2 + 70);
        goto LABEL_30;
      }
      if ( (unsigned __int8)logging_option < 2u || (unsigned __int8)debug_level_option < 2u )
      {
LABEL_19:
        if ( a1 && *(_DWORD *)(a1 + 568) <= 2u )
          ipc_log_string(
            *(_QWORD *)(a1 + 544),
            "%s: sps:BAM %pa pipe %d exits\n",
            "sps_bam_pipe_disconnect",
            (const void *)(a1 + 24),
            a2);
        goto LABEL_22;
      }
      if ( !print_limit_option )
      {
LABEL_45:
        printk(&unk_2ABD9, "sps_bam_pipe_disconnect", a1 + 24);
        goto LABEL_19;
      }
    }
    if ( !(unsigned int)__ratelimit(&sps_bam_pipe_disconnect__rs_155, "sps_bam_pipe_disconnect") )
      goto LABEL_19;
    goto LABEL_45;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_bam_pipe_disconnect__rs, "sps_bam_pipe_disconnect")) )
  {
    printk(&unk_2AF0B, "sps_bam_pipe_disconnect", a1 + 24);
  }
  v7 = -1;
  if ( a1 )
    ipc_log_string(*(_QWORD *)(a1 + 552), "%s: sps:Invalid BAM %pa pipe: %d\n", "sps_bam_pipe_disconnect", a1 + 24, a2);
  return v7;
}
