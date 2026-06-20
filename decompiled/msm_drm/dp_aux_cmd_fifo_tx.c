__int64 __fastcall dp_aux_cmd_fifo_tx(__int64 a1, unsigned int *a2)
{
  char v3; // w11
  __int64 v4; // x5
  __int64 v5; // x6
  const char *v7; // x3
  void *v8; // x4
  unsigned __int8 *v9; // x23
  int v10; // w25
  unsigned int v11; // w24
  unsigned int v12; // w20
  int v13; // w8
  void (*v14)(void); // x8
  void (*v15)(void); // x8
  void (*v16)(void); // x8
  void (*v17)(void); // x8
  __int64 v18; // x22
  int v19; // t1
  void (*v20)(void); // x8
  void (*v21)(void); // x8
  void (*v22)(void); // x8
  int v23; // w8
  int v24; // w8
  void (*v25)(void); // x8
  unsigned int v26; // w8
  unsigned __int64 StatusReg; // x20
  const char *v28; // x3
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_BYTE *)a2 + 4);
  v4 = *a2;
  v5 = *((_QWORD *)a2 + 2);
  if ( (v3 & 4) != 0 )
    v7 = "I2C";
  else
    v7 = "NAT";
  v36 = 0;
  v37 = 0;
  if ( (v3 & 1) != 0 )
    v8 = &unk_21C0AE;
  else
    v8 = &unk_233DF0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  *(_QWORD *)s = 0;
  v31 = 0;
  snprintf(s, 0x40u, "%s %s %4xh(%2zu): ", v7, v8, v4, v5);
  *(_DWORD *)(a1 + 200) = 0;
  v9 = *((unsigned __int8 **)a2 + 1);
  if ( (*(_BYTE *)(a1 + 1812) & 1) != 0 )
  {
    v10 = *a2;
    v11 = a2[4];
    v12 = 4;
    v13 = HIWORD(*a2) & 0xF | 0x10;
LABEL_12:
    **(_DWORD **)(a1 + 128) = (v13 << 8) | 0x80000000;
    v14 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 16LL);
    if ( *((_DWORD *)v14 - 1) != -52717133 )
      __break(0x8228u);
    v14();
    if ( v12 != 1 )
    {
      **(_DWORD **)(a1 + 128) = v10 & 0xFF00;
      v15 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 16LL);
      if ( *((_DWORD *)v15 - 1) != -52717133 )
        __break(0x8228u);
      v15();
      if ( v12 != 2 )
      {
        **(_DWORD **)(a1 + 128) = (unsigned __int8)v10 << 8;
        v16 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 16LL);
        if ( *((_DWORD *)v16 - 1) != -52717133 )
          __break(0x8228u);
        v16();
        if ( v12 != 3 )
        {
          **(_DWORD **)(a1 + 128) = (((_WORD)v11 << 8) - 256) & 0xFF00;
          v17 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 16LL);
          if ( *((_DWORD *)v17 - 1) != -52717133 )
            __break(0x8228u);
          v17();
          if ( v12 != 4 )
          {
            v18 = v12 - 4LL;
            do
            {
              v19 = *v9++;
              **(_DWORD **)(a1 + 128) = v19 << 8;
              v20 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 16LL);
              if ( *((_DWORD *)v20 - 1) != -52717133 )
                __break(0x8228u);
              v20();
              --v18;
            }
            while ( v18 );
          }
        }
      }
    }
    goto LABEL_28;
  }
  v11 = a2[4];
  v12 = v11 + 4;
  if ( v11 + 4 >= 0x81 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 24), "[e][%-4d]buf len error\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26F0D9, "dp_aux_write");
LABEL_54:
    ipc_log_string(
      *(_QWORD *)(a1 + 24),
      "[e][%-4d]DP AUX write failed: %s\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      s);
    printk(&unk_22316F, "dp_aux_cmd_fifo_tx");
LABEL_55:
    v12 = -22;
    goto LABEL_56;
  }
  if ( v11 != -4 )
  {
    v10 = *a2;
    v13 = HIWORD(*a2) & 0xF;
    goto LABEL_12;
  }
LABEL_28:
  v21 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 32LL);
  if ( *((_DWORD *)v21 - 1) != 1710788455 )
    __break(0x8228u);
  v21();
  v22 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 80LL);
  if ( *((_DWORD *)v22 - 1) != -1040530234 )
    __break(0x8228u);
  v22();
  if ( (*(_BYTE *)(a1 + 1811) & 1) != 0 )
  {
    v23 = 512;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 1813) )
      v24 = 1280;
    else
      v24 = 256;
    if ( *(_BYTE *)(a1 + 1814) )
      v24 |= 0x800u;
    v23 = v24 | 0x200;
  }
  **(_DWORD **)(a1 + 128) = v23;
  v25 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 24LL);
  if ( *((_DWORD *)v25 - 1) != -52717133 )
    __break(0x8228u);
  v25();
  if ( !v12 )
    goto LABEL_54;
  if ( (unsigned int)wait_for_completion_timeout(a1 + 200, 62) )
  {
    v26 = *(_DWORD *)(a1 + 1824);
    if ( v26 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( v26 < 0xFFFFFFFB )
        v28 = "unknown";
      else
        v28 = off_280CF8[(int)v26 + 5];
      ipc_log_string(*(_QWORD *)(a1 + 24), "[w][%-4d]aux err [%s] during [%s]\n", *(_DWORD *)(StatusReg + 1800), v28, s);
      if ( (unsigned int)__ratelimit(&dp_aux_cmd_fifo_tx__rs_19, "dp_aux_cmd_fifo_tx") )
        printk(&unk_252552, "dp_aux_cmd_fifo_tx");
      goto LABEL_55;
    }
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 24),
      "[w][%-4d]aux timeout during [%s]\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      s);
    if ( (unsigned int)__ratelimit(&dp_aux_cmd_fifo_tx__rs, "dp_aux_cmd_fifo_tx") )
      printk(&unk_22D092, "dp_aux_cmd_fifo_tx");
    v12 = -110;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v12;
}
