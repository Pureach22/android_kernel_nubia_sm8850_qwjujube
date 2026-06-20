__int64 __fastcall ipahal_nat_init(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x21
  __int64 v5; // x25
  __int64 v6; // x19
  __int64 v7; // x20
  __int64 v8; // x23
  unsigned __int64 v9; // x27
  __int64 v10; // x24
  const char *v11; // x0
  unsigned __int64 v12; // x1
  _QWORD *v13; // x8
  bool v14; // zf
  char *v19; // x22
  const char *v20; // x0
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x9
  const char *v26; // x0
  __int64 result; // x0
  __int64 v28; // x0
  __int64 v29; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_nat_init", 393, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_nat_init", 393, a1);
  }
  if ( a1 > 0x19 )
  {
    printk(&unk_3AE767, "ipahal_nat_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v28 = ipa3_get_ipc_logbuf();
      ipc_log_string(v28, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_nat_init", 398, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v29, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_nat_init", 398, a1);
    }
    result = 4294967274LL;
  }
  else
  {
    if ( a1 >= 0xB )
    {
      v4 = 0;
      v5 = a1;
      v6 = 10;
      v7 = 3072;
      do
      {
        v8 = 0;
        ++v6;
        v9 = v7;
        v10 = v4;
        do
        {
          if ( (unsigned __int64)(v10 + 2112) <= 0x1380 )
            v12 = 2880 - v10;
          else
            v12 = 0;
          if ( v12 <= 0x2F )
          {
            _fortify_panic(22, v12, 48);
LABEL_47:
            _fortify_panic(16, v12, 48);
          }
          v13 = (_QWORD *)((char *)&ipahal_nat_objs + v10 + 2112);
          if ( *v13 )
            v14 = 0;
          else
            v14 = v13[1] == 0;
          if ( v14 && v13[2] == 0 && v13[3] == 0 && v13[4] == 0 && v13[5] == 0 )
          {
            if ( v9 <= 0x2F )
              goto LABEL_47;
            v21 = *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 1944);
            v22 = *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 1952);
            v13[2] = *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 1936);
            v13[3] = v21;
            v23 = *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 1960);
            v24 = *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 1920);
            v25 = *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 1928);
            v13[4] = v22;
            v13[5] = v23;
            *v13 = v24;
            v13[1] = v25;
          }
          else
          {
            if ( !*v13 )
            {
              v26 = (const char *)ipahal_nat_type_str((unsigned int)v8);
              _warn_printk("%s missing entry_size for version %d\n", v26, v6);
              __break(0x800u);
            }
            v19 = (char *)&ipahal_nat_objs + v10;
            if ( *(_QWORD *)((char *)&ipahal_nat_objs + v10 + 2120) )
            {
              if ( *((_QWORD *)v19 + 267) )
                goto LABEL_11;
            }
            else
            {
              v11 = (const char *)ipahal_nat_type_str((unsigned int)v8);
              _warn_printk("%s missing is_entry_zeroed for version %d\n", v11, v6);
              __break(0x800u);
              if ( *((_QWORD *)v19 + 267) )
                goto LABEL_11;
            }
            v20 = (const char *)ipahal_nat_type_str((unsigned int)v8);
            _warn_printk("%s missing stringify_entry for version %d\n", v20, v6);
            __break(0x800u);
          }
LABEL_11:
          ++v8;
          v10 += 48;
          v9 -= 48LL;
        }
        while ( v8 != 4 );
        v4 += 192;
        v7 -= 192;
      }
      while ( v6 != v5 );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
