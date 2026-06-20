__int64 __fastcall i2c_pmic_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x24
  __int64 v4; // x25
  int v5; // w2
  int v6; // w23
  int v7; // w0
  __int64 v8; // x23
  int v9; // w0
  int v10; // w2
  int v11; // w3
  unsigned int v13; // w20
  int v14; // w21

  v1 = *(_QWORD *)(a1 + 152);
  if ( (*(_DWORD *)(v1 + 100) & 0x80000000) != 0 )
    return 0;
  if ( *(int *)(v1 + 96) >= 1 )
  {
    v3 = 0;
    v4 = 0;
    while ( 1 )
    {
      v8 = *(_QWORD *)(v1 + 24) + v3;
      v9 = regmap_write(*(_QWORD *)(v1 + 8), *(unsigned __int16 *)(v8 + 8) | 0x16u, 255);
      if ( v9 < 0 )
      {
        v5 = *(unsigned __int16 *)(v8 + 8);
        v6 = v9;
        dev_err(a1, "Couldn't clear 0x%04x irqs rc=%d\n", v5, v9);
      }
      else
      {
        v7 = regmap_write(*(_QWORD *)(v1 + 8), *(unsigned __int16 *)(v8 + 8) | 0x15u, *(unsigned __int8 *)(v8 + 19));
        if ( (v7 & 0x80000000) == 0 )
          goto LABEL_6;
        v10 = *(unsigned __int16 *)(v8 + 8);
        v11 = *(unsigned __int8 *)(v8 + 19);
        v6 = v7;
        dev_err(a1, "Couldn't restore 0x%04x synced irqs 0x%02x rc=%d\n", v10, v11, v7);
      }
      v7 = v6;
LABEL_6:
      ++v4;
      v3 += 72;
      if ( v4 >= *(int *)(v1 + 96) )
        goto LABEL_12;
    }
  }
  v7 = 0;
LABEL_12:
  v13 = v7;
  mutex_lock(v1 + 40);
  v14 = *(unsigned __int8 *)(v1 + 105);
  *(_BYTE *)(v1 + 104) = 1;
  mutex_unlock(v1 + 40);
  if ( v14 == 1 )
  {
    i2c_pmic_irq_handler(*(_DWORD *)(v1 + 100), (_QWORD *)v1);
    enable_irq(*(unsigned int *)(v1 + 100));
  }
  return v13;
}
