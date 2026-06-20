__int64 __fastcall aw9620x_irq_handle_func(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x8
  __int64 result; // x0
  unsigned int v7; // w27
  char v8; // w26
  __int64 v9; // x28
  __int64 v10; // x8
  int v11; // w21
  int v12; // w8
  int v13; // w8
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v2 = aw9620x_i2c_read(a1, 17424, (char *)v14 + 4);
  if ( (v2 & 0x80000000) != 0 )
  {
    result = dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] i2c IO error\n", "aw9620x_irq_handle_func", 2657);
    goto LABEL_26;
  }
  if ( (v14[0] & 0x100000000LL) != 0 )
  {
    v5 = *(unsigned int *)(a1 + 8);
    if ( (unsigned int)v5 >= 2 )
    {
      __break(0x5512u);
      return aw9620x_i2c_read(v2, v3, v4);
    }
    aw_init_irq_flag[v5] = 1;
  }
  result = aw9620x_i2c_read(a1, 6680, v14);
  if ( (result & 0x80000000) != 0 )
  {
    result = dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] i2c IO error\n", "aw9620x_irq_handle_func", 2667);
    goto LABEL_26;
  }
  v7 = v14[0];
  v8 = 0;
  v9 = -384;
  while ( 1 )
  {
    v10 = *(_QWORD *)(a1 + 512);
    if ( !*(_BYTE *)(v10 + v9 + 384) )
      goto LABEL_9;
    v11 = (v7 >> v8) & 1 | (2 * ((v7 >> (v8 | 8)) & 1));
    if ( *(_DWORD *)(v10 + v9 + 388) == v11 )
      goto LABEL_9;
    if ( v11 != 3 )
      break;
    input_event(*(_QWORD *)(v10 + v9 + 392), 3, 25, 3);
LABEL_8:
    result = input_event(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v9 + 392), 0, 0, 0);
    *(_DWORD *)(*(_QWORD *)(a1 + 512) + v9 + 388) = v11;
LABEL_9:
    v9 += 48;
    ++v8;
    if ( !v9 )
      goto LABEL_26;
  }
  if ( v11 == 1 )
  {
    input_event(*(_QWORD *)(v10 + v9 + 392), 3, 25, 1);
    v13 = *(_DWORD *)(a1 + 8);
    if ( v13 == 1 )
    {
      input_event(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v9 + 392), 1, 66, 1);
      dev_printk(
        &unk_13D4F,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] TRIGGER_TH0: F8 event report\n",
        "aw9620x_irq_handle_func",
        2701);
    }
    else if ( !v13 )
    {
      input_event(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v9 + 392), 1, 65, 1);
      dev_printk(
        &unk_13D4F,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] TRIGGER_TH0: F7 event report\n",
        "aw9620x_irq_handle_func",
        2697);
    }
    goto LABEL_8;
  }
  if ( !v11 )
  {
    input_event(*(_QWORD *)(v10 + v9 + 392), 3, 25, 0);
    v12 = *(_DWORD *)(a1 + 8);
    if ( v12 == 1 )
    {
      input_event(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v9 + 392), 1, 66, 0);
      dev_printk(
        &unk_13D4F,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] TRIGGER_FAR: F8 event report\n",
        "aw9620x_irq_handle_func",
        2690);
    }
    else if ( !v12 )
    {
      input_event(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v9 + 392), 1, 65, 0);
      dev_printk(
        &unk_13D4F,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] TRIGGER_FAR: F7 event report\n",
        "aw9620x_irq_handle_func",
        2685);
    }
    goto LABEL_8;
  }
  result = dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] error abs distance\n", "aw9620x_irq_handle_func", 2708);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
