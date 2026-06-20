__int64 global_atomics_test_wrapper()
{
  int v0; // w23
  int v1; // w24
  int v2; // w25
  __int64 v3; // x22
  int v4; // w19
  __int16 v5; // w8
  __int64 v6; // x19
  unsigned int *v7; // x21
  int v8; // w21
  __int16 v9; // w8
  int v10; // w8
  void *v11; // x0
  unsigned int v12; // w19
  int v14; // w24
  _DWORD *v15; // x19
  __int64 v16; // x0
  __int16 v17; // w8
  int v18; // w28
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  __int64 v26; // x20
  unsigned int v27; // w8
  unsigned int v28; // w25
  unsigned int v29; // w9
  unsigned __int64 v30; // x8
  int v31; // w10
  int i; // w10
  __int64 j; // x20
  __int64 v34; // x26
  __int64 k; // x20
  __int64 v36; // x26
  bool v37; // zf
  int v38; // [xsp+0h] [xbp-40h]
  int v39; // [xsp+4h] [xbp-3Ch]
  int v40; // [xsp+Ch] [xbp-34h]
  _QWORD v41[6]; // [xsp+10h] [xbp-30h] BYREF

  v41[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)global_memory = 0;
  v0 = global_atomics_test(1);
  msleep_interruptible(10);
  v1 = global_atomics_test(2);
  msleep_interruptible(10);
  v2 = global_atomics_test(3);
  msleep_interruptible(10);
  v3 = _kmalloc_cache_noprof(MEMORY[0xCF48], 3520, 2048);
  if ( !v3 )
  {
    v4 = -12;
    goto LABEL_55;
  }
  v5 = WORD2(qword_B680);
  if ( (qword_B680 & 0x200000000LL) == 0 )
  {
LABEL_6:
    if ( (v5 & 4) != 0 )
    {
      v6 = 2;
      if ( (unsigned int)ipclite_test_msg_send(2, 0xAA01030000040300LL) )
        goto LABEL_28;
      v5 = WORD2(qword_B680);
    }
    if ( (v5 & 8) != 0 )
    {
      v6 = 3;
      if ( (unsigned int)ipclite_test_msg_send(3, 0xAA01030000040300LL) )
        goto LABEL_28;
      v5 = WORD2(qword_B680);
    }
    if ( (v5 & 0x10) != 0 )
    {
      v6 = 4;
      if ( (unsigned int)ipclite_test_msg_send(4, 0xAA01030000040300LL) )
        goto LABEL_28;
      v5 = WORD2(qword_B680);
    }
    if ( (v5 & 0x20) != 0 )
    {
      v6 = 5;
      if ( (unsigned int)ipclite_test_msg_send(5, 0xAA01030000040300LL) )
        goto LABEL_28;
      v5 = WORD2(qword_B680);
    }
    if ( (v5 & 0x40) != 0 )
    {
      v6 = 6;
      if ( (unsigned int)ipclite_test_msg_send(6, 0xAA01030000040300LL) )
        goto LABEL_28;
      v5 = WORD2(qword_B680);
    }
    if ( (v5 & 0x80) != 0 )
    {
      v6 = 7;
      if ( (unsigned int)ipclite_test_msg_send(7, 0xAA01030000040300LL) )
        goto LABEL_28;
      v5 = WORD2(qword_B680);
    }
    if ( (v5 & 0x100) == 0 || (v6 = 8, !(unsigned int)ipclite_test_msg_send(8, 0xAA01030000040300LL)) )
    {
      v7 = (unsigned int *)global_memory;
      v38 = v2;
      v39 = v1;
      printk(&unk_B0F4, "ipclite_test", "global_atomics_test_set_clear");
      if ( !(_DWORD)qword_B680 )
      {
        v40 = 0;
LABEL_142:
        v6 = 9;
        if ( (qword_B680 & 0x100000000LL) != 0 )
        {
          v1 = v39;
          v2 = v38;
          v8 = v40;
          if ( (v40 & 1) == 0 )
          {
            printk(&unk_A5FC, "ipclite_test", "global_atomics_test_set_clear");
            v8 = 0;
            v6 = 9;
          }
        }
        else
        {
          v1 = v39;
          v2 = v38;
          v8 = v40;
        }
        goto LABEL_29;
      }
      v14 = 0;
      v15 = v7 + 128;
      v40 = 0;
      while ( 1 )
      {
        v17 = WORD2(qword_B680);
        threads_completed = 0;
        if ( (qword_B680 & 0x200000000LL) != 0 )
        {
          v19 = ipclite_test_msg_send(1, 0xAA01030000040200LL);
          v17 = WORD2(qword_B680);
          v18 = v19 == 0;
          if ( (qword_B680 & 0x400000000LL) == 0 )
            goto LABEL_72;
        }
        else
        {
          v18 = 0;
          if ( (qword_B680 & 0x400000000LL) == 0 )
            goto LABEL_72;
        }
        v20 = ipclite_test_msg_send(2, 0xAA01030000040200LL);
        v17 = WORD2(qword_B680);
        if ( !v20 )
          ++v18;
LABEL_72:
        if ( (v17 & 8) != 0 )
        {
          v21 = ipclite_test_msg_send(3, 0xAA01030000040200LL);
          v17 = WORD2(qword_B680);
          if ( !v21 )
            ++v18;
          if ( (qword_B680 & 0x1000000000LL) == 0 )
          {
LABEL_74:
            if ( (v17 & 0x20) == 0 )
              goto LABEL_75;
            goto LABEL_86;
          }
        }
        else if ( (v17 & 0x10) == 0 )
        {
          goto LABEL_74;
        }
        v22 = ipclite_test_msg_send(4, 0xAA01030000040200LL);
        v17 = WORD2(qword_B680);
        if ( !v22 )
          ++v18;
        if ( (qword_B680 & 0x2000000000LL) == 0 )
        {
LABEL_75:
          if ( (v17 & 0x40) == 0 )
            goto LABEL_76;
          goto LABEL_89;
        }
LABEL_86:
        v23 = ipclite_test_msg_send(5, 0xAA01030000040200LL);
        v17 = WORD2(qword_B680);
        if ( !v23 )
          ++v18;
        if ( (qword_B680 & 0x4000000000LL) == 0 )
        {
LABEL_76:
          if ( (v17 & 0x80) == 0 )
            goto LABEL_77;
          goto LABEL_92;
        }
LABEL_89:
        v24 = ipclite_test_msg_send(6, 0xAA01030000040200LL);
        v17 = WORD2(qword_B680);
        if ( !v24 )
          ++v18;
        if ( (qword_B680 & 0x8000000000LL) == 0 )
        {
LABEL_77:
          if ( (v17 & 0x100) == 0 )
            goto LABEL_78;
          goto LABEL_95;
        }
LABEL_92:
        v25 = ipclite_test_msg_send(7, 0xAA01030000040200LL);
        LOBYTE(v17) = BYTE4(qword_B680);
        if ( !v25 )
          ++v18;
        if ( (qword_B680 & 0x10000000000LL) == 0 )
        {
LABEL_78:
          if ( (v17 & 1) == 0 )
            goto LABEL_128;
          goto LABEL_98;
        }
LABEL_95:
        if ( !(unsigned int)ipclite_test_msg_send(8, 0xAA01030000040200LL) )
          ++v18;
        if ( (qword_B680 & 0x100000000LL) == 0 )
          goto LABEL_128;
LABEL_98:
        v26 = 0;
        ++v18;
        while ( 1 )
        {
          v29 = *v7;
          if ( *v7 == -1 )
          {
            v31 = 1;
            while ( 1 )
            {
              v30 = 32LL * v31;
              if ( v30 > 0xFFF )
                break;
              v29 = v7[v31++];
              if ( v29 != -1 )
                goto LABEL_108;
            }
            v28 = 4096;
          }
          else
          {
            LODWORD(v30) = 0;
LABEL_108:
            for ( i = 0; i != 32; ++i )
            {
              if ( ((v29 >> i) & 1) == 0 )
                break;
            }
            v27 = i + v30;
            if ( v27 >= 0x1000 )
              v28 = 4096;
            else
              v28 = v27;
          }
          if ( (((unsigned __int64)(unsigned int)ipclite_global_test_and_set_bit(v28 & 0x1F, &v7[v28 >> 5]) >> (v28 & 0x1F))
              & 1) == 0 )
          {
            *(_DWORD *)(v3 + 4 * v26) = v28;
            if ( v28 > 0xFFF )
LABEL_146:
              __break(0x5512u);
            ++v26;
            v15[v28] = 0;
            if ( v26 == 512 )
              break;
          }
        }
        for ( j = 0; j != 2048; j += 4 )
        {
          v34 = *(unsigned int *)(v3 + j);
          if ( (unsigned int)v34 > 0xFFF )
            goto LABEL_146;
          if ( v15[v34] )
          {
            printk(&unk_A390, "ipclite_test", "global_atomics_test_set_clear");
            printk(&unk_ABF7, "ipclite_test", "global_atomics_test_set_clear");
            LOBYTE(v40) = 1;
          }
        }
        for ( k = 0; k != 2048; k += 4 )
        {
          if ( v7 )
            ipclite_global_test_and_clear_bit(
              *(_DWORD *)(v3 + k) & 0x1F,
              (char *)v7 + (((unsigned __int64)*(unsigned int *)(v3 + k) >> 3) & 0x1FFFFFFC));
          else
            printk(&unk_B037, "ipclite_test", "clear_index");
        }
        if ( (v40 & 1) != 0 )
        {
          printk(&unk_A846, "ipclite_test", "global_atomics_test_set_clear");
          v40 = 1;
        }
        else
        {
          v40 = 0;
          ++threads_completed;
        }
LABEL_128:
        if ( threads_completed != v18 )
        {
          memset(v41, 0, 40);
          init_wait_entry(v41, 0);
          v16 = prepare_to_wait_event(&thread_wq, v41, 1);
          v36 = 1250;
          if ( threads_completed == v18 )
          {
LABEL_63:
            finish_wait(&thread_wq, v41);
            LODWORD(v16) = v36;
          }
          else
          {
            while ( !v16 )
            {
              v36 = schedule_timeout(v36);
              v16 = prepare_to_wait_event(&thread_wq, v41, 1);
              if ( v36 )
                v37 = 0;
              else
                v37 = threads_completed == v18;
              if ( v37 )
                v36 = 1;
              if ( threads_completed == v18 || !v36 )
                goto LABEL_63;
            }
          }
          if ( (int)v16 <= 0 )
          {
            printk(&unk_A5D0, "ipclite_test", "global_atomics_test_set_clear");
            goto LABEL_142;
          }
        }
        if ( ++v14 >= (unsigned int)qword_B680 )
          goto LABEL_142;
      }
    }
LABEL_28:
    printk(&unk_AA22, "ipclite_test", "global_atomics_test_set_clear");
    v8 = 0;
LABEL_29:
    v9 = WORD2(qword_B680);
    if ( (qword_B680 & 0x200000000LL) != 0 )
    {
      ipclite_test_msg_send(1, 0xAA01030000040400LL);
      v9 = WORD2(qword_B680);
    }
    if ( v6 != 2 )
    {
      if ( (v9 & 4) != 0 )
      {
        ipclite_test_msg_send(2, 0xAA01030000040400LL);
        v9 = WORD2(qword_B680);
      }
      if ( v6 != 3 )
      {
        if ( (v9 & 8) != 0 )
        {
          ipclite_test_msg_send(3, 0xAA01030000040400LL);
          v9 = WORD2(qword_B680);
        }
        if ( v6 != 4 )
        {
          if ( (v9 & 0x10) != 0 )
          {
            ipclite_test_msg_send(4, 0xAA01030000040400LL);
            v9 = WORD2(qword_B680);
          }
          if ( v6 != 5 )
          {
            if ( (v9 & 0x20) != 0 )
            {
              ipclite_test_msg_send(5, 0xAA01030000040400LL);
              v9 = WORD2(qword_B680);
            }
            if ( v6 != 6 )
            {
              if ( (v9 & 0x40) != 0 )
              {
                ipclite_test_msg_send(6, 0xAA01030000040400LL);
                v9 = WORD2(qword_B680);
              }
              if ( v6 != 7 )
              {
                if ( (v9 & 0x80) != 0 )
                {
                  ipclite_test_msg_send(7, 0xAA01030000040400LL);
                  v9 = WORD2(qword_B680);
                }
                if ( v6 != 8 && (v9 & 0x100) != 0 )
                  ipclite_test_msg_send(8, 0xAA01030000040400LL);
              }
            }
          }
        }
      }
    }
    v4 = v8 << 31 >> 31;
    goto LABEL_54;
  }
  if ( !(unsigned int)ipclite_test_msg_send(1, 0xAA01030000040300LL) )
  {
    v5 = WORD2(qword_B680);
    goto LABEL_6;
  }
  printk(&unk_AA22, "ipclite_test", "global_atomics_test_set_clear");
  v4 = 0;
LABEL_54:
  kfree(v3);
LABEL_55:
  v10 = v1 | v0 | v2 | v4;
  if ( v10 )
    v11 = &unk_B25E;
  else
    v11 = &unk_A4AD;
  if ( v10 )
    v12 = -1;
  else
    v12 = 0;
  printk(v11, "ipclite_test", "global_atomics_test_wrapper");
  complete(&test_done);
  _ReadStatusReg(SP_EL0);
  return v12;
}
