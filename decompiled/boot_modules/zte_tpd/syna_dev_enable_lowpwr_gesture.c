__int64 __fastcall syna_dev_enable_lowpwr_gesture(_QWORD *a1, char a2, unsigned int a3)
{
  _QWORD *v4; // x23
  unsigned int v5; // w20
  char v6; // w24
  unsigned int v7; // w19
  void *v8; // x22
  unsigned int v9; // w21
  __int64 v10; // x2
  unsigned int v11; // w0
  const char *v12; // x2
  unsigned int v13; // w19
  unsigned int v14; // w0
  __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x2

  if ( *((_BYTE *)a1 + 1409) != 1 )
    return 0;
  v4 = a1;
  if ( (a2 & 1) == 0 )
  {
    v6 = a2;
    v7 = a3;
    if ( !*((_BYTE *)a1 + 756) )
    {
      v5 = 0;
      goto LABEL_10;
    }
    v9 = 0;
    v5 = 0;
    v8 = &unk_35A56;
    goto LABEL_8;
  }
  v5 = 1;
  v6 = a2;
  v7 = a3;
  if ( (*((_BYTE *)a1 + 756) & 1) == 0 )
  {
    v8 = &unk_36AB5;
    v9 = 1;
LABEL_8:
    irq_set_irq_wake(*(unsigned int *)(a1[78] + 184LL), v9);
    printk(v8, "syna_dev_enable_lowpwr_gesture", v10);
    a1 = v4;
    *((_BYTE *)v4 + 756) = v9;
  }
LABEL_10:
  v11 = syna_tcm_set_dynamic_config(*a1, 9, v5, v7);
  if ( (v11 & 0x80000000) != 0 )
  {
    if ( (v6 & 1) != 0 )
      v12 = "enable";
    else
      v12 = "disable";
    v13 = v11;
    printk(&unk_335DA, "syna_dev_enable_lowpwr_gesture", v12);
  }
  else
  {
    v14 = syna_tcm_set_dynamic_config(
            *v4,
            254,
            (unsigned int)(*((_DWORD *)v4 + 369) | (*((_DWORD *)v4 + 364) << 13)),
            v7);
    if ( (v14 & 0x80000000) != 0 )
    {
      v13 = v14;
      printk(&unk_3B058, "syna_dev_enable_lowpwr_gesture", v15);
    }
    else
    {
      printk(&unk_329E0, "syna_dev_enable_lowpwr_gesture", *((unsigned int *)v4 + 364));
      if ( *((_DWORD *)v4 + 366) )
        v16 = 3;
      else
        v16 = 0;
      v13 = syna_tcm_set_dynamic_config(*v4, 212, v16, v7);
      if ( (v13 & 0x80000000) != 0 )
        printk(&unk_3B058, "syna_dev_enable_lowpwr_gesture", v17);
      else
        printk(&unk_3D131, "syna_dev_enable_lowpwr_gesture", *((unsigned int *)v4 + 364));
    }
  }
  return v13;
}
