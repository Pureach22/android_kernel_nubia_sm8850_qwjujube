__int64 __fastcall power_enable(int a1)
{
  int v2; // w22
  unsigned int v3; // w19
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w9
  void *v7; // x0

  mutex_lock(pwr_data + 224);
  v2 = *(_DWORD *)(pwr_data + 272);
  mutex_unlock(pwr_data + 224);
  v3 = 0;
  if ( v2 <= 1 )
  {
    if ( v2 )
    {
      if ( v2 == 1 )
      {
        if ( a1 != 1 )
        {
          v4 = 1;
LABEL_9:
          v3 = ((__int64 (__fastcall *)(__int64, __int64))power_regulators)(v4, 1);
          mutex_lock(pwr_data + 224);
          v5 = pwr_data;
          v6 = 3;
LABEL_20:
          *(_DWORD *)(v5 + 272) = v6;
          goto LABEL_21;
        }
        v7 = &unk_11B1B;
        goto LABEL_17;
      }
      return v3;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64))platform_regulators_pwr)(1) )
    {
      printk(&unk_1224B, "power_regulators");
      if ( a1 == 1 )
        goto LABEL_12;
    }
    else if ( a1 == 1 )
    {
LABEL_12:
      v3 = ((__int64 (__fastcall *)(_QWORD, __int64))power_regulators)(0, 1);
      mutex_lock(pwr_data + 224);
      v5 = pwr_data;
      *(_DWORD *)(pwr_data + 272) = a1;
LABEL_21:
      mutex_unlock(v5 + 224);
      return v3;
    }
    v3 = ((__int64 (__fastcall *)(__int64, __int64))power_regulators)(1, 1);
    mutex_lock(pwr_data + 224);
    v5 = pwr_data;
    v6 = 2;
    goto LABEL_20;
  }
  if ( v2 == 2 )
  {
    if ( a1 != 2 )
    {
      v4 = 0;
      goto LABEL_9;
    }
    v7 = &unk_1260F;
    goto LABEL_17;
  }
  if ( v2 == 3 )
  {
    v7 = &unk_13005;
LABEL_17:
    printk(v7, "power_enable");
    return 0;
  }
  return v3;
}
