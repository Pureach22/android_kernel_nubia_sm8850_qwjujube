__int64 __fastcall gyro_y_axial_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( (unsigned int)kstrtoint(a3, 0, &v7) )
  {
    a4 = -22;
  }
  else
  {
    if ( SENSORS_SENS_LOG_LEVEL >= 2 )
      printk(&unk_7364, "NUBIA_SENSORS_SENS", "gyro_y_axial_store", 283);
    if ( v7 >= 0xC9 )
    {
      printk(&unk_74C8, "NUBIA_SENSORS_SENS", "gyro_y_axial_store", 285);
      a4 = -22;
    }
    else
    {
      *(_DWORD *)(v5 + 88) = v7;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
