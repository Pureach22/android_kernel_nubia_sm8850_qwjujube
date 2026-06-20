__int64 __fastcall bcl_write_vbat_tz(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x21
  int v5; // w4
  bool v6; // cc
  unsigned int v7; // w20
  unsigned int v9; // w19
  int v10; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 1048);
  v10 = 0;
  v11 = a3;
  v5 = *(_DWORD *)(v4 + 20);
  if ( v5 )
    v6 = v5 <= (int)a3;
  else
    v6 = 1;
  if ( v6 )
  {
    v7 = 1332920885 * ((a2 - a1 - 1440) >> 3);
    mutex_lock(v4 + 24);
    v9 = bcl_set_adc_value(*(_QWORD *)(v4 + 176), v7, a3, &v10);
    if ( (v9 & 0x80000000) != 0 )
    {
      printk(&unk_85F4, "bcl_pmic5", "bcl_write_vbat_tz");
    }
    else if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v4 + 176) + 1888LL) + 16LL) == 1 )
    {
      blocking_notifier_call_chain(&bcl_pmic5_notifier, (int)v7, &v11);
    }
    mutex_unlock(v4 + 24);
  }
  else
  {
    printk(&unk_8816, "bcl_pmic5", "bcl_write_vbat_tz");
    v9 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
