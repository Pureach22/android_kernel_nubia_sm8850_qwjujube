__int64 __fastcall ipclite_intr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x5
  __int64 v9; // x22
  char v10; // w8
  __int64 v11; // x19
  unsigned int v12; // w8
  __int64 v13; // x9
  __int64 v14; // x5
  unsigned int v15; // w19
  const char *v16; // x0
  __int64 (*v17)(void); // x8
  void (*v18)(void); // x8
  __int64 (*v19)(void); // x8
  void (*v20)(void); // x8
  void (__fastcall *v21)(__int64, _QWORD, __int64); // x8
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x2
  __int64 v25; // x3
  const char *v26; // x0
  const char *v27; // x1
  char v28; // w8
  const char *v29; // x0
  __int64 (*v30)(void); // x8
  void (*v31)(void); // x8
  __int64 (*v32)(void); // x8
  void (*v33)(void); // x8
  void (__fastcall *v34)(__int64, _QWORD, __int64); // x8
  __int64 v35; // x0
  __int64 v36; // x2
  unsigned int v37; // w20
  __int64 v38; // x19
  __int64 v39; // x19
  __int64 v40; // x19
  char v42; // [xsp+0h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  v8 = *(int *)(a2 + 68);
  v9 = a2 - 104LL * (int)v8;
  v10 = ipclite_debug_control;
  if ( (ipclite_debug_level & 8) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_5;
      goto LABEL_4;
    }
    v38 = a2;
    a1 = printk(&unk_109EC, "ipclite", "ipclite_intr");
    v10 = ipclite_debug_control;
    a2 = v38;
    if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_4:
      v11 = a2;
      a1 = ipclite_inmem_log(
             "APPS:%s:Interrupt received from Core : %d Signal : %d\n",
             (__int64)&unk_1039F,
             *(unsigned int *)(v9 - 32),
             *(unsigned int *)(a2 + 68),
             a5,
             v8,
             a7,
             a8,
             v42);
      v10 = ipclite_debug_control;
      a2 = v11;
    }
  }
LABEL_5:
  if ( (v10 & 2) == 0 )
    goto LABEL_9;
  if ( (debug_status & 1) == 0 )
  {
    v39 = a2;
    printk(&unk_EEDB, "ipclite", "is_debug_config");
    a2 = v39;
LABEL_9:
    v14 = *(unsigned int *)(a2 + 68);
    if ( (int)v14 > 1 )
    {
      if ( (_DWORD)v14 == 2 )
      {
        if ( (ipclite_debug_level & 0x10) == 0 )
          goto LABEL_95;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_10D5F, "ipclite", "ipclite_intr");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_95;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_95;
        }
        v29 = "APPS:%s:Versioning is not enabled using IPCC signals\n";
LABEL_67:
        ipclite_inmem_log(v29, (__int64)"LOW", a3, a4, a5, v14, a7, a8, v42);
        goto LABEL_95;
      }
      if ( (_DWORD)v14 != 3 )
        goto LABEL_38;
      v17 = *(__int64 (**)(void))(*(_QWORD *)(v9 - 16) + 32LL);
      if ( *((_DWORD *)v17 - 1) != -1899415283 )
        __break(0x8228u);
      if ( (v17() & 0xFFFFFFF8LL) != 0 )
      {
        do
        {
          v42 = 0;
          v20 = *(void (**)(void))(*(_QWORD *)(v9 - 16) + 40LL);
          if ( *((_DWORD *)v20 - 1) != -1927346431 )
            __break(0x8228u);
          v20();
          if ( test_client_2 == 1 )
          {
            v21 = (void (__fastcall *)(__int64, _QWORD, __int64))test_client_0;
            if ( test_client_0 )
            {
              v22 = *(unsigned int *)(v9 - 32);
              v23 = test_client_1;
              if ( *((_DWORD *)test_client_0 - 1) != -402135140 )
                __break(0x8228u);
              v21(v22, 0, v23);
            }
          }
          v18 = *(void (**)(void))(*(_QWORD *)(v9 - 16) + 48LL);
          if ( *((_DWORD *)v18 - 1) != -306834612 )
            __break(0x8228u);
          v18();
          v19 = *(__int64 (**)(void))(*(_QWORD *)(v9 - 16) + 32LL);
          if ( *((_DWORD *)v19 - 1) != -1899415283 )
            __break(0x8228u);
        }
        while ( (v19() & 0xFFFFFFF8LL) != 0 );
      }
      if ( (ipclite_debug_level & 0x10) == 0 )
        goto LABEL_95;
      v28 = ipclite_debug_control;
      if ( (ipclite_debug_control & 1) != 0 )
        goto LABEL_70;
    }
    else
    {
      if ( (_DWORD)v14 )
      {
        if ( (_DWORD)v14 == 1 )
        {
          if ( !ipclite || *(_BYTE *)(ipclite + 6440) != 1 )
          {
            if ( (ipclite_debug_level & 1) != 0 )
            {
              if ( (ipclite_debug_control & 1) != 0 )
              {
                printk(&unk_104B4, "ipclite", "ipclite_intr");
                if ( (ipclite_debug_control & 4) == 0 )
                  goto LABEL_95;
              }
              else if ( (ipclite_debug_control & 4) == 0 )
              {
                goto LABEL_95;
              }
              ipclite_inmem_log(
                "APPS:%s:ipclite probe failed, can't loop back init signal\n",
                (__int64)"ERR",
                a3,
                a4,
                a5,
                v14,
                a7,
                a8,
                v42);
              goto LABEL_95;
            }
            goto LABEL_95;
          }
          v15 = *(_DWORD *)(v9 - 32);
          if ( v15 >= 9 )
          {
            if ( (ipclite_debug_level & 1) != 0 )
            {
              if ( (ipclite_debug_control & 1) != 0 )
              {
                printk(&unk_10BAC, "ipclite", "ipclite_init_update");
                if ( (ipclite_debug_control & 4) == 0 )
                  goto LABEL_95;
                goto LABEL_18;
              }
              if ( (ipclite_debug_control & 4) != 0 )
              {
LABEL_18:
                v16 = "APPS:%s:Invalid proc_id %d\n";
LABEL_19:
                ipclite_inmem_log(v16, (__int64)"ERR", v15, a4, a5, v14, a7, a8, v42);
              }
            }
LABEL_95:
            _ReadStatusReg(SP_EL0);
            return 1;
          }
          if ( !*(_DWORD *)(v9 + 664) )
          {
            if ( (ipclite_debug_level & 1) == 0 )
              goto LABEL_95;
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_10A78, "ipclite", "ipclite_init_update");
              if ( (ipclite_debug_control & 4) == 0 )
                goto LABEL_95;
            }
            else if ( (ipclite_debug_control & 4) == 0 )
            {
              goto LABEL_95;
            }
            v16 = "APPS:%s:Cannot Send, Core %d is Inactive\n";
            goto LABEL_19;
          }
          v37 = mbox_send_message(*(_QWORD *)(v9 + 160), 0);
          if ( (v37 & 0x80000000) != 0 )
          {
            if ( (ipclite_debug_level & 1) == 0 )
              goto LABEL_95;
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_1122F, "ipclite", "ipclite_init_update");
              if ( (ipclite_debug_control & 4) == 0 )
                goto LABEL_95;
            }
            else if ( (ipclite_debug_control & 4) == 0 )
            {
              goto LABEL_95;
            }
            v26 = "APPS:%s:init signal send failed to core: %d ret: %d\n";
            v27 = "ERR";
          }
          else
          {
            mbox_client_txdone(*(_QWORD *)(v9 + 160), 0);
            if ( (ipclite_debug_level & 0x10) == 0 )
              goto LABEL_95;
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_E79D, "ipclite", "ipclite_init_update");
              if ( (ipclite_debug_control & 4) == 0 )
                goto LABEL_95;
            }
            else if ( (ipclite_debug_control & 4) == 0 )
            {
              goto LABEL_95;
            }
            v26 = "APPS:%s:init signal send completed to core: %d ret: %d\n";
            v27 = "LOW";
          }
          v24 = v15;
          v25 = v37;
LABEL_42:
          ipclite_inmem_log(v26, (__int64)v27, v24, v25, a5, v14, a7, a8, v42);
          goto LABEL_95;
        }
LABEL_38:
        if ( (ipclite_debug_level & 1) == 0 )
          goto LABEL_95;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          v40 = a2;
          printk(&unk_F3B2, "ipclite", "ipclite_intr");
          a2 = v40;
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_95;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_95;
        }
        v24 = *(unsigned int *)(v9 - 32);
        v25 = *(unsigned int *)(a2 + 68);
        v26 = "APPS:%s:Wrong Interrupt Signal from core : %d signal : %d\n";
        v27 = "ERR";
        goto LABEL_42;
      }
      v30 = *(__int64 (**)(void))(*(_QWORD *)(v9 - 16) + 32LL);
      if ( *((_DWORD *)v30 - 1) != -1899415283 )
        __break(0x8228u);
      if ( (v30() & 0xFFFFFFF8LL) != 0 )
      {
        do
        {
          v42 = 0;
          v33 = *(void (**)(void))(*(_QWORD *)(v9 - 16) + 40LL);
          if ( *((_DWORD *)v33 - 1) != -1927346431 )
            __break(0x8228u);
          v33();
          if ( synx_client_2 == 1 )
          {
            v34 = (void (__fastcall *)(__int64, _QWORD, __int64))synx_client_0;
            if ( synx_client_0 )
            {
              v35 = *(unsigned int *)(v9 - 32);
              v36 = synx_client_1;
              if ( *((_DWORD *)synx_client_0 - 1) != -402135140 )
                __break(0x8228u);
              v34(v35, 0, v36);
            }
          }
          v31 = *(void (**)(void))(*(_QWORD *)(v9 - 16) + 48LL);
          if ( *((_DWORD *)v31 - 1) != -306834612 )
            __break(0x8228u);
          v31();
          v32 = *(__int64 (**)(void))(*(_QWORD *)(v9 - 16) + 32LL);
          if ( *((_DWORD *)v32 - 1) != -1899415283 )
            __break(0x8228u);
        }
        while ( (v32() & 0xFFFFFFF8LL) != 0 );
      }
      if ( (ipclite_debug_level & 0x10) == 0 )
        goto LABEL_95;
      v28 = ipclite_debug_control;
      if ( (ipclite_debug_control & 1) != 0 )
      {
LABEL_70:
        printk(&unk_11200, "ipclite", "ipclite_intr");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_95;
LABEL_46:
        v29 = "APPS:%s:checking messages in rx_fifo done\n";
        goto LABEL_67;
      }
    }
    if ( (v28 & 4) == 0 )
      goto LABEL_95;
    goto LABEL_46;
  }
  v12 = *(_DWORD *)(v9 - 32);
  if ( v12 < 9 )
  {
    v13 = ipclite_dbg_struct;
    ++*(_DWORD *)(ipclite_dbg_struct + 60LL * v12 + 48);
    *(_DWORD *)(v13 + 12) = *(_DWORD *)(v9 - 32);
    *(_DWORD *)(v13 + 20) = *(_DWORD *)(a2 + 68);
    goto LABEL_9;
  }
  __break(0x5512u);
  return ipclite_tx(a1, a2, a3);
}
