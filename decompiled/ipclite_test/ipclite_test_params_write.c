__int64 __fastcall ipclite_test_params_write(int a1, int a2, char *s, __int64 a4)
{
  size_t v6; // x22
  char *v7; // x20
  size_t v8; // x23
  size_t v9; // x0
  size_t v10; // x2
  char *v11; // x0
  void *v12; // x0
  const char *v13; // x2
  int v15; // w23
  char *v16; // x0
  char *v17; // x0
  unsigned int v18; // w8
  __int64 v19; // x0
  int v20; // w8
  __int64 v21; // x21
  char v22; // w24
  __int64 v23; // x8
  __int64 v24; // x27
  __int64 v25; // x27
  int v26; // w22
  void *v27; // x0
  __int64 param_macro; // x0
  __int64 v29; // x0
  unsigned int v30; // w9
  char *stringp; // [xsp+8h] [xbp-38h] BYREF
  char *v32[6]; // [xsp+10h] [xbp-30h] BYREF

  v32[5] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = strlen(s) + 1;
  v7 = (char *)_kmalloc_noprof(v6, 3264);
  stringp = v7;
  if ( v7 )
  {
    v8 = strlen(s) + 1;
    v9 = strnlen(s, v8);
    if ( v9 == -1 && v8 != -1 )
    {
      _fortify_panic(2, -1, 0);
    }
    else
    {
      if ( v9 == v8 )
        v10 = v8;
      else
        v10 = v9 + 1;
      if ( v10 <= v6 )
      {
        if ( (sized_strscpy(v7, s) & 0x80000000) != 0 )
        {
          v12 = &unk_B549;
LABEL_13:
          v13 = "ipclite_test_params_write";
LABEL_17:
          printk(v12, "ipclite_test", v13);
LABEL_18:
          kfree(v7);
          goto LABEL_19;
        }
        test_params = 0x3E800000001LL;
        qword_B680 = 0x100000001LL;
        qword_B688 = 1;
        qword_B694 = 0x100000001LL;
        qword_B69C = 0xFF00000001LL;
        v11 = strsep(&stringp, " ");
        if ( !v11 )
        {
LABEL_11:
          v12 = &unk_B2D9;
LABEL_16:
          v13 = "parse_param";
          goto LABEL_17;
        }
        if ( (kstrtoint(v11, 0, (char *)&qword_B688 + 4) & 0x80000000) != 0 )
        {
LABEL_15:
          v12 = &unk_AF38;
          goto LABEL_16;
        }
        v15 = HIDWORD(qword_B688);
        if ( HIDWORD(qword_B688) == 7 )
        {
          v32[0] = stringp;
          v16 = strsep(v32, " ");
          if ( !v16 )
            goto LABEL_11;
          if ( (kstrtoint(v16, 0, (char *)&qword_B69C + 4) & 0x80000000) != 0 )
            goto LABEL_15;
          if ( HIDWORD(qword_B69C) < 2 )
          {
            if ( !HIDWORD(qword_B69C) )
            {
              v26 = 0;
              v27 = &unk_A2E6;
LABEL_61:
              printk(v27, "ipclite_test", "loopback_config");
              HIDWORD(qword_B69C) = v26;
              goto LABEL_18;
            }
          }
          else
          {
            printk(&unk_B306, "ipclite_test", "loopback_config");
            HIDWORD(qword_B69C) = 1;
          }
          v26 = 255;
          v27 = &unk_AF65;
          goto LABEL_61;
        }
        if ( (unsigned int)(HIDWORD(qword_B688) - 7) <= 0xFFFFFFF9 )
        {
          v12 = &unk_B093;
          goto LABEL_13;
        }
        v17 = strsep(&stringp, " ");
        if ( !v17 )
          goto LABEL_11;
        if ( (kstrtoint(v17, 0, (char *)&qword_B680 + 4) & 0x80000000) != 0 )
          goto LABEL_15;
        v18 = HIDWORD(qword_B680);
        if ( (unsigned int)(HIDWORD(qword_B680) - 512) <= 0xFFFFFE00 )
        {
          printk(&unk_AEC3, "ipclite_test", "ipclite_test_set_senders");
          v18 = 1;
          HIDWORD(qword_B680) = 1;
        }
        HIDWORD(qword_B694) = _sw_hweight64(v18);
        v19 = printk(&unk_ABBA, "ipclite_test", "ipclite_test_set_senders");
        if ( v15 == 4 )
          goto LABEL_37;
        if ( v15 == 3 )
        {
          if ( (unsigned int)parse_param(&stringp, &qword_B680) )
            goto LABEL_18;
          if ( (unsigned int)(qword_B680 - 4001) <= 0xFFFFF05F )
          {
            printk(&unk_B216, "ipclite_test", "ipclite_test_params_write");
            LODWORD(qword_B680) = 1;
          }
          v19 = printk(&unk_A9E5, "ipclite_test", "ipclite_test_params_write");
          goto LABEL_37;
        }
        if ( (unsigned int)parse_param(&stringp, &qword_B688) )
          goto LABEL_18;
        v19 = ipclite_test_set_receivers();
        if ( (v15 & 3) == 2 )
        {
LABEL_66:
          v20 = HIDWORD(qword_B680);
          dword_B690 = HIDWORD(qword_B680);
          if ( v15 == 2 )
          {
LABEL_39:
            v21 = 0;
            v22 = 0;
            do
            {
              while ( v21 )
              {
                if ( (((unsigned __int64)(unsigned int)dword_B690 >> v21) & 1) == 0 )
                  break;
                corestatus = 0;
                v19 = ipclite_test_msg_send((unsigned int)v21, 0xAA010100000C0000LL);
                if ( (corestatus & 1) != 0 )
                  break;
                memset(v32, 0, 40);
                init_wait_entry(v32, 0);
                v19 = prepare_to_wait_event(&thread_wq, v32, 1);
                if ( (corestatus & 1) != 0 )
                {
                  v23 = 63;
LABEL_41:
                  v24 = v23;
                  finish_wait(&thread_wq, v32);
                  v19 = v24;
                }
                else
                {
                  v23 = 63;
                  while ( !v19 )
                  {
                    v25 = schedule_timeout(v23);
                    v19 = prepare_to_wait_event(&thread_wq, v32, 1);
                    if ( ((unsigned __int8)corestatus & (v25 == 0)) != 0 )
                      v23 = 1;
                    else
                      v23 = v25;
                    if ( (corestatus & 1) != 0 || !v23 )
                      goto LABEL_41;
                  }
                }
                if ( (int)v19 >= 1 )
                  break;
                v19 = printk(&unk_AACB, "ipclite_test", "basic_ping_test");
                ++v21;
                v22 = 1;
                if ( v21 == 9 )
                  goto LABEL_18;
              }
              ++v21;
            }
            while ( v21 != 9 );
            if ( (v22 & 1) == 0 )
            {
              param_macro = get_param_macro(v19);
              v29 = ping_sel_senders(param_macro);
              ipclite_test_set_test(v29);
            }
            goto LABEL_18;
          }
LABEL_38:
          dword_B690 = qword_B688 | v20;
          goto LABEL_39;
        }
        v19 = parse_param(&stringp, (char *)&test_params + 4);
        if ( (_DWORD)v19 )
          goto LABEL_18;
        if ( HIDWORD(test_params) && (v15 != 5 ? (v30 = 200000) : (v30 = 20000), HIDWORD(test_params) <= v30) )
        {
          if ( v15 != 1 )
            goto LABEL_66;
        }
        else
        {
          v19 = printk(&unk_A6C7, "ipclite_test", "ipclite_test_params_write");
          HIDWORD(test_params) = 1;
          if ( v15 != 1 )
            goto LABEL_66;
        }
        v19 = ping_config(stringp);
        if ( (_DWORD)v19 )
          goto LABEL_18;
LABEL_37:
        v20 = HIDWORD(qword_B680);
        goto LABEL_38;
      }
    }
    _fortify_panic(7, v6, v10);
  }
  printk(&unk_AB18, "ipclite_test", "ipclite_test_params_write");
  a4 = -22;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return a4;
}
