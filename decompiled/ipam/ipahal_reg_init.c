__int64 __fastcall ipahal_reg_init(unsigned int a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x22
  unsigned __int64 v4; // x26
  unsigned __int64 v5; // x20
  __int64 v6; // x27
  unsigned __int64 v7; // x19
  unsigned __int64 v8; // x1
  _QWORD *v9; // x24
  bool v10; // zf
  _BOOL4 v15; // w8
  __int64 v16; // x28
  const char *v17; // x0
  __int64 v18; // x28
  const char *v19; // x0
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x28
  const char *v24; // x0
  __int64 v25; // x28
  const char *v26; // x0
  __int64 v27; // x28
  const char *v28; // x0
  __int64 v29; // x28
  const char *v30; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v33; // x0
  __int64 v34; // [xsp+8h] [xbp-48h]
  unsigned __int64 v35; // [xsp+10h] [xbp-40h]
  __int64 v36; // [xsp+18h] [xbp-38h]

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_reg_init", 5391, a1);
  }
  if ( a1 >= 0x1A )
  {
    printk(&unk_3AE767, "ipahal_reg_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_reg_init", 5394, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v33 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v33, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_reg_init", 5394, a1);
    }
    result = 4294967274LL;
  }
  else
  {
    if ( a1 >= 0xB )
    {
      v3 = 0;
      v4 = 10;
      v5 = 106240;
      v34 = a1;
      do
      {
        v6 = 0;
        v7 = v4 + 1;
        v35 = v5;
        v36 = v3;
        do
        {
          if ( (unsigned __int64)(v3 + 73040) <= 0x2A260 )
            v8 = 99600 - v3;
          else
            v8 = 0;
          if ( v8 <= 0x27 )
          {
            _fortify_panic(22, v8, 40);
LABEL_61:
            _fortify_panic(16, v8, 40);
          }
          v9 = (_QWORD *)((char *)&ipahal_reg_objs + v3 + 73040);
          if ( *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 73040) )
            v10 = 0;
          else
            v10 = *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 73048) == 0;
          if ( !v10
            || *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 73056) != 0
            || *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 73064) != 0
            || *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 73072) != 0 )
          {
            v15 = v4 < 0x14 || v6 != 130;
            if ( !*(_DWORD *)((char *)&ipahal_reg_objs + v3 + 73056) && v15 )
            {
              ipahal_reg_name_str(v6);
              printk(&unk_3D7731, "ipahal_reg_init");
              if ( ipa3_get_ipc_logbuf() )
              {
                v23 = ipa3_get_ipc_logbuf();
                v24 = ipahal_reg_name_str(v6);
                ipc_log_string(
                  v23,
                  "ipahal %s:%d reg=%s with zero offset ipa_ver=%d\n",
                  "ipahal_reg_init",
                  5415,
                  v24,
                  v7);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v25 = ipa3_get_ipc_logbuf_low();
                v26 = ipahal_reg_name_str(v6);
                ipc_log_string(
                  v25,
                  "ipahal %s:%d reg=%s with zero offset ipa_ver=%d\n",
                  "ipahal_reg_init",
                  5415,
                  v26,
                  v7);
              }
              __break(0x800u);
              if ( *v9 )
                goto LABEL_36;
            }
            else if ( *v9 )
            {
LABEL_36:
              if ( !*(_QWORD *)((char *)&ipahal_reg_objs + v3 + 73048) )
              {
                ipahal_reg_name_str(v6);
                printk(&unk_3BFC6B, "ipahal_reg_init");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v16 = ipa3_get_ipc_logbuf();
                  v17 = ipahal_reg_name_str(v6);
                  ipc_log_string(
                    v16,
                    "ipahal %s:%d reg=%s with NULL parse func ipa_ver=%d\n",
                    "ipahal_reg_init",
                    5427,
                    v17,
                    v7);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v18 = ipa3_get_ipc_logbuf_low();
                  v19 = ipahal_reg_name_str(v6);
                  ipc_log_string(
                    v18,
                    "ipahal %s:%d reg=%s with NULL parse func ipa_ver=%d\n",
                    "ipahal_reg_init",
                    5427,
                    v19,
                    v7);
                }
                __break(0x800u);
              }
              goto LABEL_9;
            }
            ipahal_reg_name_str(v6);
            printk(&unk_3C2CB1, "ipahal_reg_init");
            if ( ipa3_get_ipc_logbuf() )
            {
              v27 = ipa3_get_ipc_logbuf();
              v28 = ipahal_reg_name_str(v6);
              ipc_log_string(
                v27,
                "ipahal %s:%d reg=%s with NULL construct func ipa_ver=%d\n",
                "ipahal_reg_init",
                5421,
                v28,
                v7);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v29 = ipa3_get_ipc_logbuf_low();
              v30 = ipahal_reg_name_str(v6);
              ipc_log_string(
                v29,
                "ipahal %s:%d reg=%s with NULL construct func ipa_ver=%d\n",
                "ipahal_reg_init",
                5421,
                v30,
                v7);
            }
            __break(0x800u);
            goto LABEL_36;
          }
          if ( v5 <= 0x27 )
            goto LABEL_61;
          v20 = *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 66416);
          v21 = *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 66424);
          v9[4] = *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 66432);
          v9[2] = v20;
          v9[3] = v21;
          v22 = *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 66408);
          *v9 = *(_QWORD *)((char *)&ipahal_reg_objs + v3 + 66400);
          v9[1] = v22;
LABEL_9:
          ++v6;
          v3 += 40;
          v5 -= 40LL;
        }
        while ( v6 != 166 );
        ++v4;
        v3 = v36 + 6640;
        v5 = v35 - 6640;
      }
      while ( v7 != v34 );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
