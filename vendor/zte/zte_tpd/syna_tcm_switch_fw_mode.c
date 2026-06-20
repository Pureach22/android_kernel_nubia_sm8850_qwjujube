__int64 __fastcall syna_tcm_switch_fw_mode(__int64 a1, int a2, unsigned int a3)
{
  int v3; // w19
  __int64 (*v4)(__int64); // x8
  void *v6; // x0
  __int64 v7; // x20
  int v8; // w21
  __int64 v9; // x20
  __int64 (*v10)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int); // x8
  __int64 v11; // x20
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 v14; // x2
  __int64 v15; // x2
  void *v16; // x0
  const char *v17; // x1
  void *v18; // x0
  __int64 v19; // x20
  __int64 (*v20)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int); // x8
  unsigned int v21; // w0

  if ( !a1 )
  {
    v6 = unk_3365A;
LABEL_22:
    printk(v6, "syna_tcm_switch_fw_mode", (unsigned long long)a3);
    return 4294967055LL;
  }
  if ( a3 )
  {
    if ( *(_DWORD *)(a1 + 488) <= a3 )
      v3 = a3;
    else
      v3 = *(_DWORD *)(a1 + 488);
  }
  else if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 488);
    v7 = a1;
    v8 = a2;
    printk(unk_3AD14, "syna_tcm_switch_fw_mode", (unsigned long long)a3);
    a2 = v8;
    a1 = v7;
  }
  if ( a2 == 11 )
  {
    if ( *(_BYTE *)(a1 + 9) != 11 )
    {
      if ( !v3 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
      {
        v19 = a1;
        printk(unk_3BA3F, "syna_tcm_run_bootloader_fw", (unsigned long long)a3);
        a1 = v19;
      }
      v20 = *(__int64 (**)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int))(a1 + 920);
      v11 = a1;
      /* CFI check removed */
      v21 = v20(a1, 31, NULL, 0, NULL, v3);
      if ( (v21 & 0x80000000) != 0 )
      {
        v13 = v21;
        printk(unk_39AB7, "syna_tcm_run_bootloader_fw", 31);
      }
      else
      {
        v15 = *(unsigned __int8 *)(v11 + 9);
        if ( (_DWORD)v15 == 11 )
        {
          v16 = unk_3C787;
          v17 = "syna_tcm_run_bootloader_fw";
          goto LABEL_43;
        }
        printk(unk_3850E, "syna_tcm_run_bootloader_fw", v15);
        v13 = -242;
      }
      v18 = unk_3632F;
      goto LABEL_47;
    }
 LABEL_15:
    v4 = *(__int64 (**)(__int64))(a1 + 944);
    if ( !v4 )
      return 0;
 LABEL_16:
    if ( *((_DWORD *)v4 - 1) != -713399031 )
      __break(0x8228u);
    v4(a1);
    return 0;
  }
  if ( a2 != 1 )
  {
    v6 = unk_36CA0;
    goto LABEL_22;
  }
  if ( *(_BYTE *)(a1 + 9) == 1 )
    goto LABEL_15;
  if ( !v3 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
  {
    v9 = a1;
    printk(unk_3BA3F, "syna_tcm_run_application_fw", (unsigned long long)a3);
    a1 = v9;
  }
  v10 = *(__int64 (**)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int))(a1 + 920);
  v11 = a1;
  /* CFI check removed */
  v12 = v10(a1, 20, NULL, 0, NULL, v3);
  if ( (v12 & 0x80000000) == 0 )
  {
    v15 = *(unsigned __int8 *)(v11 + 9);
    if ( (_DWORD)v15 != 1 )
    {
      printk(unk_35061, "syna_tcm_run_application_fw", v15);
      v13 = -242;
      goto LABEL_35;
    }
    v16 = unk_3AD6E;
    v17 = "syna_tcm_run_application_fw";
LABEL_43:
    printk(v16, v17, v15);
    v4 = *(__int64 (**)(__int64))(v11 + 944);
    if ( !v4 )
      return 0;
    goto LABEL_16;
  }
  v13 = v12;
  printk(unk_39AB7, "syna_tcm_run_application_fw", 20);
LABEL_35:
  v18 = unk_3B3A9;
LABEL_47:
  v14 = *(unsigned __int8 *)(v11 + 9);
  printk(v18, "syna_tcm_switch_fw_mode", v14);
  return v13;
}
