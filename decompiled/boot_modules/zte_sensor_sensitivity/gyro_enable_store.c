__int64 __fastcall gyro_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w8
  char v7; // w21
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  if ( (unsigned int)kstrtoint(a3, 0, &v9) )
    goto LABEL_2;
  if ( SENSORS_SENS_LOG_LEVEL < 2 )
  {
    v6 = v9;
    if ( v9 )
      goto LABEL_5;
LABEL_8:
    v7 = 0;
    goto LABEL_9;
  }
  printk(&unk_73A9, "NUBIA_SENSORS_SENS", "gyro_enable_store", 215);
  v6 = v9;
  if ( !v9 )
    goto LABEL_8;
LABEL_5:
  if ( v6 == 1 )
  {
    v7 = 1;
LABEL_9:
    mutex_lock(v5 + 16);
    *(_BYTE *)(v5 + 80) = v7;
    mutex_unlock(v5 + 16);
    goto LABEL_10;
  }
LABEL_2:
  a4 = -22;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return a4;
}
