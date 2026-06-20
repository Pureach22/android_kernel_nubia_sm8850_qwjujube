__int64 __fastcall syna_tcm_switch_fw_mode(__int64 a1, char a2, __int64 a3)
{
  int v3; // w19
  void (*v4)(void); // x8
  void *v6; // x0
  __int64 v7; // x20
  char v8; // w21
  __int64 v9; // x20
  __int64 (*v10)(void); // x8
  __int64 v11; // x20
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 v14; // x2
  __int64 v15; // x2
  void *v16; // x0
  const char *v17; // x1
  void *v18; // x0
  __int64 v19; // x20
  __int64 (*v20)(void); // x8
  unsigned int v21; // w0

  if ( !a1 )
  {
    v6 = &unk_3365A;
LABEL_22:
    printk(v6, "syna_tcm_switch_fw_mode", a3);
    return 4294967055LL;
  }
  if ( (_DWORD)a3 )
  {
    if ( *(_DWORD *)(a1 + 488) <= (unsigned int)a3 )
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
    printk(&unk_3AD14, "syna_tcm_switch_fw_mode", a3);
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
        printk(&unk_3BA3F, "syna_tcm_run_bootloader_fw", a3);
        a1 = v19;
      }
      v20 = *(__int64 (**)(void))(a1 + 920);
      v11 = a1;
      if ( *((_DWORD *)v20 - 1) != 606091918 )
        __break(0x8228u);
      v21 = v20();
      if ( (v21 & 0x80000000) != 0 )
      {
        v13 = v21;
        printk(&unk_39AB7, "syna_tcm_run_bootloader_fw", 31);
      }
      else
      {
        v15 = *(unsigned __int8 *)(v11 + 9);
        if ( (_DWORD)v15 == 11 )
        {
          v16 = &unk_3C787;
          v17 = "syna_tcm_run_bootloader_fw";
          goto LABEL_43;
        }
        printk(&unk_3850E, "syna_tcm_run_bootloader_fw", v15);
        v13 = -242;
      }
      v18 = &unk_3632F;
      goto LABEL_47;
    }
LABEL_15:
    v4 = *(void (**)(void))(a1 + 944);
    if ( !v4 )
      return 0;
LABEL_16:
    if ( *((_DWORD *)v4 - 1) != -713399031 )
      __break(0x8228u);
    v4();
    return 0;
  }
  if ( a2 != 1 )
  {
    v6 = &unk_36CA0;
    goto LABEL_22;
  }
  if ( *(_BYTE *)(a1 + 9) == 1 )
    goto LABEL_15;
  if ( !v3 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
  {
    v9 = a1;
    printk(&unk_3BA3F, "syna_tcm_run_application_fw", a3);
    a1 = v9;
  }
  v10 = *(__int64 (**)(void))(a1 + 920);
  v11 = a1;
  if ( *((_DWORD *)v10 - 1) != 606091918 )
    __break(0x8228u);
  v12 = v10();
  if ( (v12 & 0x80000000) == 0 )
  {
    v15 = *(unsigned __int8 *)(v11 + 9);
    if ( (_DWORD)v15 != 1 )
    {
      printk(&unk_35061, "syna_tcm_run_application_fw", v15);
      v13 = -242;
      goto LABEL_35;
    }
    v16 = &unk_3AD6E;
    v17 = "syna_tcm_run_application_fw";
LABEL_43:
    printk(v16, v17, v15);
    v4 = *(void (**)(void))(v11 + 944);
    if ( !v4 )
      return 0;
    goto LABEL_16;
  }
  v13 = v12;
  printk(&unk_39AB7, "syna_tcm_run_application_fw", 20);
LABEL_35:
  v18 = &unk_3B3A9;
LABEL_47:
  printk(v18, "syna_tcm_switch_fw_mode", v14);
  return v13;
}
