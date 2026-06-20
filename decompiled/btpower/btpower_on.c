__int64 __fastcall btpower_on(int a1)
{
  int v2; // w25
  int v3; // w26
  int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w19
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x27
  __int64 v10; // x23
  __int64 v11; // x22
  __int64 v12; // x1
  unsigned int v13; // w0
  unsigned int v14; // w23
  void *v15; // x0
  int v16; // w9
  __int64 v17; // x0

  v2 = *(_DWORD *)(pwr_data + 288);
  mutex_lock(pwr_data + 224);
  v3 = *(_DWORD *)(pwr_data + 276);
  mutex_unlock(pwr_data + 224);
  if ( (v3 | 2) != 3 )
  {
    if ( !v2 )
    {
LABEL_3:
      if ( a1 )
        v4 = 2;
      else
        v4 = 1;
      result = power_enable(v4);
      if ( !(_DWORD)result )
      {
        mutex_lock(pwr_data + 224);
        v6 = *(_DWORD *)(pwr_data + 272);
        mutex_unlock(pwr_data + 224);
        return v6;
      }
      return result;
    }
LABEL_30:
    printk(&unk_11081, "btpower_on");
    return 0xFFFFFFFFLL;
  }
  v7 = *(unsigned int *)(pwr_data + 144);
  if ( !(_DWORD)v7 )
  {
    printk(&unk_12C11, "platform_regulators_pwr");
    goto LABEL_26;
  }
  printk(&unk_1241F, "platform_regulators_pwr");
  if ( (int)v7 < 1 )
  {
LABEL_26:
    mutex_lock(pwr_data + 224);
    if ( v3 == 1 )
      v16 = 2;
    else
      v16 = 4;
    v17 = pwr_data + 224;
    *(_DWORD *)(pwr_data + 276) = v16;
    mutex_unlock(v17);
    if ( !v2 )
      goto LABEL_3;
    goto LABEL_30;
  }
  v8 = pwr_data;
  v9 = 0;
  do
  {
    v10 = *(_QWORD *)(v8 + 80);
    if ( !(v10 + v9) || *(_BYTE *)(v10 + v9 + 28) != 1 || *(_BYTE *)(v10 + v9 + 29) != 1 )
    {
      result = 0;
      goto LABEL_13;
    }
    v11 = v10 + v9;
    v12 = *(unsigned int *)(v10 + v9 + 16);
    if ( (_DWORD)v12 )
    {
      if ( *(_DWORD *)(v11 + 20) )
      {
        v13 = regulator_set_voltage(*(_QWORD *)(v10 + v9), v12);
        if ( (v13 & 0x80000000) != 0 )
        {
          v14 = v13;
          v15 = &unk_13848;
          goto LABEL_24;
        }
      }
    }
    result = regulator_set_load(*(_QWORD *)v11, *(unsigned int *)(v11 + 24));
    if ( (result & 0x80000000) != 0 )
    {
      v14 = result;
      v15 = &unk_132AE;
LABEL_24:
      printk(v15, "vreg_configure");
      result = v14;
    }
    v8 = pwr_data;
LABEL_13:
    v9 += 48;
  }
  while ( 48 * v7 != v9 );
  if ( (result & 0x80000000) == 0 )
    goto LABEL_26;
  return result;
}
