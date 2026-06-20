__int64 __fastcall qcedev_control_clocks(__int64 a1, char a2)
{
  int v2; // w8
  int v4; // w10
  __int64 result; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // w19
  void *v11; // x0
  unsigned int v12; // w0
  __int64 v13; // x2
  __int64 v14; // x3
  int v15; // w8
  __int64 v16; // x2
  __int64 v17; // x3
  unsigned int v18; // w8
  unsigned int v19; // w0
  __int64 v20; // x2
  __int64 v21; // x3

  if ( (a2 & 1) != 0 )
    v2 = 2;
  else
    v2 = 3;
  if ( (a2 & 1) != 0 )
    v4 = 1;
  else
    v4 = 4;
  if ( !*(_BYTE *)(a1 + 44) )
    v2 = v4;
  if ( v2 > 2 )
  {
    if ( v2 == 3 )
    {
      v12 = qce_disable_clk(*(_QWORD *)(a1 + 224));
      if ( v12 )
      {
        v10 = v12;
        v11 = &unk_127C1;
        goto LABEL_30;
      }
      v15 = icc_set_bw(*(_QWORD *)(a1 + 64), 0, 0);
      result = 0;
      if ( !v15 )
        return result;
      printk(&unk_12D8C, "qcedev_control_clocks", v13, v14);
      result = qce_enable_clk(*(_QWORD *)(a1 + 224));
      if ( !(_DWORD)result )
        return result;
LABEL_19:
      v10 = result;
      v11 = &unk_12012;
      goto LABEL_30;
    }
    v19 = icc_set_bw(*(_QWORD *)(a1 + 64), 0, 0);
    if ( v19 )
    {
      v10 = v19;
      v11 = &unk_12D8C;
      goto LABEL_30;
    }
    result = qce_disable_clk(*(_QWORD *)(a1 + 224));
    if ( !(_DWORD)result )
      return result;
    printk(&unk_127C1, "qcedev_control_clocks", v20, v21);
    result = icc_set_bw(*(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 72), *(unsigned int *)(a1 + 76));
    if ( !(_DWORD)result )
      return result;
LABEL_27:
    v10 = result;
    v11 = &unk_12402;
    goto LABEL_30;
  }
  if ( v2 != 1 )
  {
    LODWORD(result) = icc_set_bw(*(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 72), *(unsigned int *)(a1 + 76));
    if ( !(_DWORD)result )
    {
      result = qce_enable_clk(*(_QWORD *)(a1 + 224));
      if ( (_DWORD)result )
      {
        printk(&unk_12012, "qcedev_control_clocks", v16, v17);
        v18 = icc_set_bw(*(_QWORD *)(a1 + 64), 0, 0);
        result = 0;
        if ( v18 )
        {
          v11 = &unk_12D8C;
          v10 = v18;
          goto LABEL_30;
        }
      }
      return result;
    }
    goto LABEL_27;
  }
  LODWORD(result) = qce_enable_clk(*(_QWORD *)(a1 + 224));
  if ( (_DWORD)result )
    goto LABEL_19;
  result = icc_set_bw(*(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 72), *(unsigned int *)(a1 + 76));
  if ( (_DWORD)result )
  {
    printk(&unk_12402, "qcedev_control_clocks", v8, v9);
    result = qce_disable_clk(*(_QWORD *)(a1 + 224));
    if ( (_DWORD)result )
    {
      v10 = result;
      v11 = &unk_12CD1;
LABEL_30:
      printk(v11, "qcedev_control_clocks", v6, v7);
      return v10;
    }
  }
  return result;
}
