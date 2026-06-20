__int64 __fastcall qce_enable_clk(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x20
  unsigned int v4; // w0
  __int64 v5; // x2
  unsigned int v6; // w0
  __int64 v7; // x20
  unsigned int v8; // w0
  __int64 v9; // x2
  unsigned int v10; // w0
  __int64 v11; // x20
  unsigned int v12; // w0
  __int64 v13; // x2
  unsigned int v14; // w0
  __int64 v15; // x20
  unsigned int v16; // w0
  __int64 v17; // x2
  unsigned int v18; // w21
  unsigned int v19; // w19
  __int64 v20; // x20
  __int64 v21; // x20
  __int64 v22; // x19

  if ( (*(_BYTE *)(a1 + 70249) & 1) != 0 )
    return 0;
  v2 = *(_QWORD *)(a1 + 96);
  if ( v2 )
  {
    v4 = clk_prepare(*(_QWORD *)(a1 + 96));
    if ( v4 )
    {
      v19 = v4;
    }
    else
    {
      v6 = clk_enable(v2);
      if ( !v6 )
        goto LABEL_6;
      v19 = v6;
      clk_unprepare(v2);
    }
    printk(&unk_149A7, "qce_enable_clk", v5);
    return v19;
  }
LABEL_6:
  if ( (*(_BYTE *)(a1 + 71) & 1) != 0 )
    return 0;
  v7 = *(_QWORD *)(a1 + 104);
  if ( !v7 )
  {
LABEL_10:
    v11 = *(_QWORD *)(a1 + 112);
    if ( !v11 )
      goto LABEL_13;
    v12 = clk_prepare(*(_QWORD *)(a1 + 112));
    if ( v12 )
    {
      v18 = v12;
    }
    else
    {
      v14 = clk_enable(v11);
      if ( !v14 )
      {
LABEL_13:
        v15 = *(_QWORD *)(a1 + 120);
        if ( v15 )
        {
          v16 = clk_prepare(*(_QWORD *)(a1 + 120));
          if ( v16 )
          {
            v18 = v16;
          }
          else
          {
            result = clk_enable(v15);
            if ( !(_DWORD)result )
              return result;
            v18 = result;
            clk_unprepare(v15);
          }
          printk(&unk_16309, "qce_enable_clk", v17);
          v20 = *(_QWORD *)(a1 + 112);
          if ( v20 )
          {
            clk_disable(*(_QWORD *)(a1 + 112));
            clk_unprepare(v20);
          }
          goto LABEL_31;
        }
        return 0;
      }
      v18 = v14;
      clk_unprepare(v11);
    }
    printk(&unk_164D8, "qce_enable_clk", v13);
LABEL_31:
    v21 = *(_QWORD *)(a1 + 104);
    if ( v21 )
    {
      clk_disable(*(_QWORD *)(a1 + 104));
      clk_unprepare(v21);
    }
    goto LABEL_33;
  }
  v8 = clk_prepare(*(_QWORD *)(a1 + 104));
  if ( v8 )
  {
    v18 = v8;
  }
  else
  {
    v10 = clk_enable(v7);
    if ( !v10 )
      goto LABEL_10;
    v18 = v10;
    clk_unprepare(v7);
  }
  printk(&unk_15827, "qce_enable_clk", v9);
LABEL_33:
  v22 = *(_QWORD *)(a1 + 96);
  if ( v22 )
  {
    clk_disable(v22);
    clk_unprepare(v22);
  }
  return v18;
}
