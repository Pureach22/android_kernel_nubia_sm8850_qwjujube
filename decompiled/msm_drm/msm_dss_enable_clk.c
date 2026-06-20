__int64 __fastcall msm_dss_enable_clk(__int64 a1, int a2, int a3)
{
  __int64 v3; // x30
  __int64 v4; // x19
  __int64 v5; // x22
  __int64 v7; // x20
  __int64 v8; // x24
  __int64 v9; // x21
  unsigned int v10; // w0
  unsigned int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x24
  __int64 v14; // x21
  __int64 v15; // x23
  bool v16; // cc
  __int64 result; // x0
  unsigned int v18; // w24
  __int64 v19; // x8
  __int64 v20; // x24
  __int64 v21; // x21
  __int64 v22; // x23
  unsigned int v23; // w25

  v4 = v3;
  if ( !a3 )
  {
    v12 = (unsigned int)(a2 - 1);
    if ( a2 - 1 >= 0 )
    {
      v13 = v12 + 1;
      v14 = a1 + 120LL * (unsigned int)v12 + 8;
      do
      {
        v15 = *(_QWORD *)(v14 - 8);
        if ( v15 )
        {
          clk_disable(*(_QWORD *)(v14 - 8));
          clk_unprepare(v15);
        }
        else
        {
          printk(&unk_246903, v4);
        }
        v16 = v13-- <= 1;
        v14 -= 120;
      }
      while ( !v16 );
    }
    return 0;
  }
  if ( a2 < 1 )
    return 0;
  v5 = 0;
  v7 = a1 + 8;
  v8 = -(__int64)(unsigned int)a2;
  while ( 1 )
  {
    v9 = *(_QWORD *)(v7 - 8);
    if ( !v9 )
    {
      printk(&unk_246903, v4);
      result = 0xFFFFFFFFLL;
      goto LABEL_23;
    }
    v10 = clk_prepare(*(_QWORD *)(v7 - 8));
    if ( v10 )
    {
      v18 = v10;
      goto LABEL_22;
    }
    v11 = clk_enable(v9);
    if ( v11 )
      break;
    --v5;
    v7 += 120;
    if ( v8 == v5 )
      return 0;
  }
  v18 = v11;
  clk_unprepare(v9);
LABEL_22:
  printk(&unk_25088C, v4);
  result = v18;
LABEL_23:
  if ( v5 )
  {
    v19 = (unsigned int)~(_DWORD)v5;
    v20 = v19 + 1;
    v21 = a1 + 120LL * (unsigned int)v19 + 8;
    do
    {
      v22 = *(_QWORD *)(v21 - 8);
      v23 = result;
      if ( v22 )
      {
        clk_disable(*(_QWORD *)(v21 - 8));
        clk_unprepare(v22);
      }
      else
      {
        printk(&unk_246903, v4);
      }
      v16 = v20-- <= 1;
      v21 -= 120;
      result = v23;
    }
    while ( !v16 );
  }
  return result;
}
