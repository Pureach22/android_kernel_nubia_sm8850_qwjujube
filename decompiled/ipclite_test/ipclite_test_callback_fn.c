__int64 __fastcall ipclite_test_callback_fn(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  _BYTE *v4; // x0
  unsigned int v5; // w19
  char v6; // w21
  char *v7; // x9
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x10
  unsigned int v11; // w9
  void *v13; // x0
  const char *v14; // x2
  void *v15; // x0

  if ( HIBYTE(a2) != 170 )
  {
    printk(&unk_B514, "ipclite_test", "ipclite_test_callback_fn");
    return 4294967274LL;
  }
  v2 = (a2 >> 16) & 0xFFFFF;
  v3 = BYTE1(a2);
  if ( BYTE5(a2) <= 3u )
  {
    if ( (unsigned int)BYTE5(a2) - 1 >= 2 )
    {
      if ( BYTE5(a2) == 3 )
      {
        if ( v2 != 4 )
        {
          v4 = &thread_wq;
          threads_completed += 2;
          goto LABEL_54;
        }
        if ( (unsigned __int8)a2 == 2 )
        {
          if ( ++threads_completed == HIDWORD(qword_B694) )
          {
            v4 = &thread_wq;
LABEL_54:
            _wake_up(v4, 1, 1, 0);
            return 0;
          }
          return 0;
        }
        if ( (unsigned int)a1 < 0xA )
        {
          printk(&unk_ADC2, "ipclite_test", "atomic_callback");
          return 0;
        }
LABEL_71:
        __break(0x5512u);
        JUMPOUT(0xA038);
      }
      goto LABEL_56;
    }
LABEL_12:
    if ( (_DWORD)v2 == 11 )
    {
      if ( th_arr )
      {
        if ( (unsigned int)a1 < 0xA )
        {
          v9 = th_arr + 120 * ((a2 >> 36) & 0xF);
          v10 = v9 + 4LL * (unsigned int)a1;
          v11 = *(_DWORD *)(v10 + 52) + 1;
          *(_DWORD *)(v10 + 52) = v11;
          if ( (_DWORD)a1 != 9 )
          {
            if ( !(_DWORD)test_params || v11 % (unsigned int)test_params && v11 != *(_DWORD *)(v9 + 12) )
              return 0;
            v4 = (_BYTE *)(v9 + 88);
            goto LABEL_54;
          }
        }
        goto LABEL_71;
      }
      v13 = &unk_A33D;
      v14 = "ping_callback";
LABEL_58:
      printk(v13, "ipclite_test", v14);
      return 0;
    }
    if ( (_DWORD)v2 == 10 )
    {
      ipclite_test_msg_send(a1, a2 & 0xFFF000000000LL | 0xAA010000000B0000LL);
      return 0;
    }
    if ( (unsigned __int8)a2 == 1 )
    {
      if ( (unsigned int)a1 > 9 )
        goto LABEL_71;
      printk(&unk_A740, "ipclite_test", "ping_callback");
    }
    else if ( (unsigned __int8)a2 == 2 )
    {
      if ( (unsigned int)a1 >= 0xA )
        goto LABEL_71;
      printk(&unk_AE95, "ipclite_test", "ping_callback");
      ++cores_completed;
    }
    if ( v3 != 1 )
    {
      if ( (_DWORD)v2 == 12 )
      {
        v4 = &thread_wq;
        corestatus = 1;
        goto LABEL_54;
      }
      return 0;
    }
    if ( HIDWORD(qword_B688) == 5 )
    {
      v4 = &unk_B7A0;
LABEL_48:
      v4[24] = 1;
      goto LABEL_54;
    }
    if ( cores_completed != HIDWORD(qword_B694) )
      return 0;
LABEL_53:
    v4 = &unk_B708;
    goto LABEL_54;
  }
  if ( BYTE5(a2) == 6 )
  {
    v5 = a1;
    if ( BYTE1(a2) == 2 )
    {
      v6 = a2;
      if ( !(unsigned int)ipclite_hw_mutex_release() )
        *(_DWORD *)global_memory = 0;
      ipclite_test_msg_send(v5, 0xAA01060000010100LL);
      LOBYTE(a2) = v6;
    }
    if ( (unsigned __int8)a2 == 1 )
    {
      if ( v5 > 9 )
        goto LABEL_71;
      v15 = &unk_A78C;
    }
    else
    {
      if ( (unsigned __int8)a2 != 2 )
      {
        if ( (_DWORD)v3 != 1 )
          return 0;
        goto LABEL_22;
      }
      if ( v5 >= 0xA )
        goto LABEL_71;
      v15 = &unk_A761;
    }
    printk(v15, "ipclite_test", "hw_mutex_callback");
    if ( (_DWORD)v3 != 1 )
      return 0;
LABEL_22:
    byte_B720 = 1;
    if ( (qword_B680 & 0x100000000LL) != 0 )
      return 0;
    goto LABEL_53;
  }
  if ( BYTE5(a2) != 5 )
  {
    if ( BYTE5(a2) != 4 )
    {
LABEL_56:
      v13 = &unk_AA4C;
      v14 = "ipclite_test_callback_fn";
      goto LABEL_58;
    }
    goto LABEL_12;
  }
  if ( (_DWORD)v2 == 2 )
  {
    if ( BYTE1(a2) != 1 )
      return 0;
    byte_B7B8 = 1;
    if ( (unsigned int)a1 <= 9 )
    {
      printk(&unk_A3F1, "ipclite_test", "ssr_callback");
      v4 = &unk_B7A0;
      goto LABEL_54;
    }
    goto LABEL_71;
  }
  if ( (_DWORD)v2 == 11 )
  {
    v4 = &unk_B818;
    goto LABEL_48;
  }
  if ( (_DWORD)v2 != 10 )
    return 0;
  if ( (unsigned int)a1 >= 0xA )
    goto LABEL_71;
  v7 = (char *)&m_thread + 4 * (unsigned int)a1;
  v8 = *((_DWORD *)v7 + 13) + 1;
  *((_DWORD *)v7 + 13) = v8;
  if ( (_DWORD)a1 == 9 )
    goto LABEL_71;
  if ( v8 == HIDWORD(test_params) )
  {
    printk(&unk_A7B7, "ipclite_test", "ssr_callback");
    printk(&unk_AA68, "ipclite_test", "ssr_callback");
    byte_B7B8 = 1;
    _wake_up(&unk_B7A0, 1, 1, 0);
    v4 = &unk_B818;
    byte_B830 = 1;
    goto LABEL_54;
  }
  return 0;
}
