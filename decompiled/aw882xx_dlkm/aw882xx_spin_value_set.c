__int64 __fastcall aw882xx_spin_value_set(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned int v10; // w0
  unsigned int v11; // w20
  __int64 *v13; // x8
  __int64 v14; // x1
  void *v15; // x0
  __int64 *v16; // x8

  mutex_lock(&g_spin_lock);
  v6 = g_spin_mode & 0xFFFFFFFE;
  if ( (a3 & 1) == 0 )
  {
    if ( v6 == 2 )
    {
      v7 = a1;
      v8 = a2;
      v9 = 0;
      goto LABEL_6;
    }
    v13 = *(__int64 **)(a1 + 112);
    v14 = v13[14];
    if ( !v14 )
      v14 = *v13;
    v15 = &unk_25FCC;
LABEL_17:
    printk(v15, v14, "aw882xx_spin_value_set");
    v11 = 0;
    goto LABEL_10;
  }
  if ( v6 != 2 )
  {
    if ( g_spin_mode == 1 )
    {
      v10 = aw882xx_dsp_write_spin(a2);
      goto LABEL_9;
    }
    v16 = *(__int64 **)(a1 + 112);
    v14 = v16[14];
    if ( !v14 )
      v14 = *v16;
    v15 = &unk_249AB;
    goto LABEL_17;
  }
  v7 = a1;
  v8 = a2;
  v9 = 1;
LABEL_6:
  v10 = aw_reg_write_spin(v7, v8, v9);
LABEL_9:
  v11 = v10;
LABEL_10:
  g_spin_value = a2;
  mutex_unlock(&g_spin_lock);
  return v11;
}
