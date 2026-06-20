__int64 __fastcall ipahal_hw_stats_init(unsigned int a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x24
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x25
  unsigned __int64 v7; // x19
  __int64 v8; // x26
  unsigned __int64 v9; // x1
  _QWORD *v10; // x8
  bool v11; // zf
  char *v13; // x28
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v22; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_hw_stats_init", 1009, a1);
  }
  if ( a1 >= 0x1A )
  {
    printk(&unk_3AE767, "ipahal_hw_stats_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_hw_stats_init", 1012, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_hw_stats_init", 1012, a1);
    }
    result = 4294967274LL;
  }
  else
  {
    if ( a1 >= 0xF )
    {
      v3 = 0;
      v4 = 14;
      v5 = 1152;
      do
      {
        v6 = 0;
        ++v4;
        v7 = v5;
        v8 = v3;
        do
        {
          if ( (unsigned __int64)(v8 + 1440) <= 0x9C0 )
            v9 = 1056 - v8;
          else
            v9 = 0;
          if ( v9 <= 0x17 )
          {
            _fortify_panic(22, v9, 24);
LABEL_43:
            _fortify_panic(16, v9, 24);
          }
          v10 = (_QWORD *)((char *)&ipahal_hw_stats_objs + v8 + 1440);
          if ( *v10 )
            v11 = 0;
          else
            v11 = v10[1] == 0;
          if ( v11 && v10[2] == 0 )
          {
            if ( v7 <= 0x17 )
              goto LABEL_43;
            v16 = *(_QWORD *)((char *)&ipahal_hw_stats_objs + v8 + 1352);
            v17 = *(_QWORD *)((char *)&ipahal_hw_stats_objs + v8 + 1360);
            *v10 = *(_QWORD *)((char *)&ipahal_hw_stats_objs + v8 + 1344);
            v10[1] = v16;
            v10[2] = v17;
          }
          else
          {
            v13 = (char *)&ipahal_hw_stats_objs + v8;
            if ( *(_QWORD *)((char *)&ipahal_hw_stats_objs + v8 + 1448) )
            {
              if ( *((_QWORD *)v13 + 182) )
                goto LABEL_9;
LABEL_23:
              printk(&unk_3DD47B, "ipahal_hw_stats_init");
              if ( ipa3_get_ipc_logbuf() )
              {
                v14 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v14,
                  "ipahal %s:%d stat=%d parse_stats null ver=%d\n",
                  "ipahal_hw_stats_init",
                  1039,
                  v6,
                  v4);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v15 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v15,
                  "ipahal %s:%d stat=%d parse_stats null ver=%d\n",
                  "ipahal_hw_stats_init",
                  1039,
                  v6,
                  v4);
              }
              __break(0x800u);
              goto LABEL_9;
            }
            printk(&unk_3C60FF, "ipahal_hw_stats_init");
            if ( ipa3_get_ipc_logbuf() )
            {
              v18 = ipa3_get_ipc_logbuf();
              ipc_log_string(v18, "ipahal %s:%d stat=%d get_offset null ver=%d\n", "ipahal_hw_stats_init", 1033, v6, v4);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v19 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v19, "ipahal %s:%d stat=%d get_offset null ver=%d\n", "ipahal_hw_stats_init", 1033, v6, v4);
            }
            __break(0x800u);
            if ( !*((_QWORD *)v13 + 182) )
              goto LABEL_23;
          }
LABEL_9:
          ++v6;
          v8 += 24;
          v7 -= 24LL;
        }
        while ( v6 != 4 );
        v3 += 96;
        v5 -= 96;
      }
      while ( v4 != a1 );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
