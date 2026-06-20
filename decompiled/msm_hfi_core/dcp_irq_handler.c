__int64 __fastcall dcp_irq_handler(unsigned int a1, unsigned int *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  int v7; // w8
  __int64 v8; // x4
  __int64 v9; // x2
  _DWORD *v10; // x8
  unsigned int *v12; // x22
  __int64 v13; // x23
  unsigned int *v14; // x20
  __int64 v15; // x21
  void *v16; // x0
  __int64 v17; // x2
  __int64 v18; // x3

  v7 = msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v12 = a2;
    v13 = v5;
    printk(&unk_1E83A, "dcp_irq_handler", 237, a4, a5);
    v7 = msm_hfi_core_debug_level;
    v5 = v13;
    a2 = v12;
  }
  if ( (~v7 & 0x10002) == 0 )
  {
    v14 = a2;
    v15 = v5;
    printk(&unk_1C2A5, "dcp_irq_handler", 238, a1, a5);
    v5 = v15;
    a2 = v14;
    if ( v14 )
      goto LABEL_5;
LABEL_21:
    v16 = &unk_1CC9C;
    v17 = 241;
    goto LABEL_22;
  }
  if ( !a2 )
    goto LABEL_21;
LABEL_5:
  v8 = *a2;
  if ( (unsigned int)(v8 - 4) <= 0xFFFFFFFC )
  {
    v16 = &unk_1D5EB;
    v17 = 248;
    v18 = v5;
    goto LABEL_24;
  }
  if ( a2[20] == a1 )
  {
    v9 = 2;
    v10 = *((_DWORD **)a2 + 30);
    if ( v10 )
    {
LABEL_8:
      if ( *(v10 - 1) != 1209183092 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, _QWORD, __int64))v10)(0, (unsigned int)v8, v9);
    }
    return 1;
  }
  if ( a2[29] == a1 )
  {
LABEL_18:
    v9 = 1;
    v10 = *((_DWORD **)a2 + 30);
    if ( v10 )
      goto LABEL_8;
    return 1;
  }
  if ( a2[42] == a1 || a2[51] == a1 )
  {
    if ( (hfi_core_loop_back_mode_enable & 1) != 0 )
    {
      if ( a2[51] == a1 )
        LODWORD(v8) = 3;
      goto LABEL_18;
    }
    v16 = &unk_1F4B0;
    v17 = 261;
  }
  else
  {
    v16 = &unk_1F0F3;
    v17 = 269;
  }
LABEL_22:
  v18 = v5;
  v8 = a1;
LABEL_24:
  printk(v16, "dcp_irq_handler", v17, v18, v8);
  return 0;
}
