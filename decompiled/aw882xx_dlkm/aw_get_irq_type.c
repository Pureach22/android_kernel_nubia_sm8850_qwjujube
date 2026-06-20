__int64 __fastcall aw_get_irq_type(__int64 a1, __int16 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 *v5; // x8
  __int16 v6; // w19
  __int64 v7; // x1
  __int64 v8; // x20
  __int64 *v9; // x8
  char v10; // w19
  int v11; // w21
  __int64 v12; // x1
  __int64 v13; // x20
  __int64 *v14; // x8
  char v15; // w19
  int v16; // w21
  __int64 v17; // x1
  __int64 *v18; // x8
  int v19; // w19
  __int64 v20; // x1

  v2 = a1;
  if ( (a2 & 0x4000) != 0 )
  {
    v5 = *(__int64 **)(a1 + 112);
    v6 = a2;
    v7 = v5[14];
    if ( !v7 )
      v7 = *v5;
    printk(&unk_28384, v7, "aw_get_irq_type");
    result = 1;
    v2 = a1;
    LOBYTE(a2) = v6;
    if ( (v6 & 0x800) == 0 )
    {
LABEL_3:
      if ( (a2 & 8) == 0 )
        goto LABEL_4;
      goto LABEL_12;
    }
  }
  else
  {
    result = 0;
    if ( (a2 & 0x800) == 0 )
      goto LABEL_3;
  }
  v8 = v2;
  v9 = *(__int64 **)(v2 + 112);
  v10 = a2;
  v11 = result;
  v12 = v9[14];
  if ( !v12 )
    v12 = *v9;
  printk(&unk_24871, v12, "aw_get_irq_type");
  result = v11 | 2u;
  v2 = v8;
  LOBYTE(a2) = v10;
  if ( (v10 & 8) == 0 )
  {
LABEL_4:
    if ( (a2 & 2) == 0 )
      return result;
    goto LABEL_15;
  }
LABEL_12:
  v13 = v2;
  v14 = *(__int64 **)(v2 + 112);
  v15 = a2;
  v16 = result;
  v17 = v14[14];
  if ( !v17 )
    v17 = *v14;
  printk(&unk_28E5C, v17, "aw_get_irq_type");
  result = v16 | 4u;
  v2 = v13;
  if ( (v15 & 2) != 0 )
  {
LABEL_15:
    v18 = *(__int64 **)(v2 + 112);
    v19 = result;
    v20 = v18[14];
    if ( !v20 )
      v20 = *v18;
    printk(&unk_243F3, v20, "aw_get_irq_type");
    return v19 | 8u;
  }
  return result;
}
