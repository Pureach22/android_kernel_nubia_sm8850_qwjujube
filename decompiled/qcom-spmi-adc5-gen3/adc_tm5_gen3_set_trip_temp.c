__int64 __fastcall adc_tm5_gen3_set_trip_temp(__int64 a1, int a2, int a3)
{
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x22
  __int64 v9; // x19
  int v10; // w10
  unsigned int v11; // w19
  int v12; // w8
  int v13; // w8
  __int64 v14; // x2
  int v16; // [xsp+0h] [xbp-20h] BYREF
  int v17; // [xsp+4h] [xbp-1Ch]
  __int64 v18; // [xsp+8h] [xbp-18h]
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = thermal_zone_device_priv();
  if ( !v5 )
    goto LABEL_8;
  v8 = *(_QWORD *)(v5 + 56);
  v9 = v5;
  v18 = 0;
  v19 = 0;
  if ( a3 == 0x7FFFFFFF )
    v10 = 0;
  else
    v10 = a3;
  v16 = v10;
  v17 = 0;
  if ( a2 == 0x80000000 )
  {
    if ( a3 == 0x7FFFFFFF )
    {
      printk(&unk_969B, v6, v7);
LABEL_8:
      v11 = -22;
      goto LABEL_19;
    }
  }
  else
  {
    v17 = a2;
  }
  adc_tm_scale_therm_voltage_100k_gen3(&v16, *(_QWORD *)(v5 + 64));
  mutex_lock(v8 + 96);
  if ( a3 == 0x7FFFFFFF )
  {
    v12 = 0;
  }
  else
  {
    *(_QWORD *)(v9 + 120) = v19;
    v12 = 1;
  }
  *(_DWORD *)(v9 + 100) = v12;
  if ( a2 < -2147483646 )
  {
    v13 = 0;
  }
  else
  {
    *(_QWORD *)(v9 + 112) = v18;
    v13 = 1;
  }
  *(_DWORD *)(v9 + 96) = v13;
  v11 = adc_tm5_gen3_configure(v9);
  if ( (v11 & 0x80000000) != 0 )
    printk(&unk_9A3C, v11, v14);
  mutex_unlock(v8 + 96);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v11;
}
