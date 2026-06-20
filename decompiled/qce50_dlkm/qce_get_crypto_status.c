__int64 __fastcall qce_get_crypto_status(__int64 a1, __int64 a2)
{
  unsigned int v4; // w19
  unsigned int v5; // w20
  unsigned int v6; // w21
  unsigned int v7; // w22
  unsigned int v8; // w23
  __int64 result; // x0
  __int64 v10; // x2
  unsigned int v11; // w24
  unsigned int v12; // w26
  const char *v13; // x1
  void *v14; // x2
  void *v15; // x0
  void *v16; // x0

  v4 = readl_relaxed(*(_QWORD *)(a1 + 80) + 106752LL);
  v5 = readl_relaxed(*(_QWORD *)(a1 + 80) + 106756LL);
  v6 = readl_relaxed(*(_QWORD *)(a1 + 80) + 106780LL);
  v7 = readl_relaxed(*(_QWORD *)(a1 + 80) + 106788LL);
  v8 = readl_relaxed(*(_QWORD *)(a1 + 80) + 106792LL);
  result = readl_relaxed(*(_QWORD *)(a1 + 80) + 106812LL);
  *(_QWORD *)a2 = 0;
  *(_BYTE *)(a2 + 8) = 0;
  if ( (v4 & 0xFFFFFFFD) != 0x2000004 )
  {
    v11 = result;
    if ( *(_DWORD *)(a1 + 404) <= 7u && *(_DWORD *)(a1 + 408) < 6u )
    {
      if ( v6 & 0xFF00 | result & 0x300 )
      {
        v16 = &unk_15BBD;
        *(_BYTE *)(a2 + 1) = 1;
      }
      else
      {
        if ( !HIBYTE(v6) && (result & 0x3000000) == 0 )
        {
          v13 = "qce_get_crypto_status";
LABEL_27:
          printk(&unk_16115, v13, v13);
          *(_BYTE *)(a2 + 3) = 1;
LABEL_34:
          printk(&unk_15D43, "dump_status_regs", v4);
          printk(&unk_14BEF, "dump_status_regs", v5);
          printk(&unk_155F4, "dump_status_regs", v6);
          printk(&unk_14C19, "dump_status_regs", v7);
          printk(&unk_16268, "dump_status_regs", v8);
          return printk(&unk_15EF7, "dump_status_regs", v11);
        }
        v16 = &unk_1541C;
        *(_BYTE *)(a2 + 2) = 1;
      }
      printk(v16, "qce_get_crypto_status", "qce_get_crypto_status");
      goto LABEL_34;
    }
    v12 = HIWORD(v6);
    if ( (v5 & 0x10000000) != 0 )
    {
      printk(&unk_15FBA, "qce_get_error_v8", v12);
      LOBYTE(result) = v11;
      if ( (v5 & 0x8000000) == 0 )
      {
LABEL_8:
        if ( (v6 & 0x10) == 0 )
        {
LABEL_9:
          if ( (v6 & 0x1000) == 0 )
          {
            if ( (v8 & 0x2000000) != 0 )
            {
              printk(&unk_1586B, "qce_get_error_v8", v12);
              *(_BYTE *)(a2 + 5) = 1;
              goto LABEL_34;
            }
            if ( (v8 & 0x400000) != 0 )
            {
              printk(&unk_149DE, "qce_get_error_v8", v10);
              *(_BYTE *)(a2 + 4) = 1;
              goto LABEL_34;
            }
            if ( (v8 & 0x4000000) != 0 || (result & 3) != 0 )
            {
              printk(&unk_15EC6, "qce_get_error_v8", v12);
              *(_BYTE *)(a2 + 6) = 1;
              goto LABEL_34;
            }
            if ( (v8 & 0x200000) != 0 )
            {
              printk(&unk_15589, "qce_get_error_v8", v12);
              *(_BYTE *)(a2 + 8) = 1;
              goto LABEL_34;
            }
            if ( (v8 & 0x100000) != 0 )
            {
              printk(&unk_155B8, "qce_get_error_v8", v12);
              *(_BYTE *)(a2 + 7) = 1;
              goto LABEL_34;
            }
            v13 = "qce_get_error_v8";
            goto LABEL_27;
          }
          v15 = &unk_157A3;
          *(_BYTE *)(a2 + 2) = 1;
LABEL_29:
          printk(v15, "qce_get_error_v8", "qce_get_error_v8");
          goto LABEL_34;
        }
LABEL_22:
        v15 = &unk_1650C;
        *(_BYTE *)(a2 + 1) = 1;
        goto LABEL_29;
      }
    }
    else if ( (v5 & 0x8000000) == 0 )
    {
      goto LABEL_8;
    }
    if ( (v7 & 0x100) != 0 )
      v14 = &unk_15387;
    else
      v14 = &unk_15AD3;
    printk(&unk_16026, "qce_get_error_v8", v14);
    LOBYTE(result) = v11;
    if ( (v6 & 0x10) == 0 )
      goto LABEL_9;
    goto LABEL_22;
  }
  *(_BYTE *)a2 = 1;
  return result;
}
