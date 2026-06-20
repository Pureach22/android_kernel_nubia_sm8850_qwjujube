__int64 __fastcall glink_adc_read_channel(__int64 *a1, __int64 a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v7; // w8
  __int64 v8; // x0
  unsigned int v9; // w22
  int v10; // w5
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  int v13; // [xsp+8h] [xbp-18h]
  unsigned int v14; // [xsp+Ch] [xbp-14h]
  int v15; // [xsp+10h] [xbp-10h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a2 + 4);
  v12 = 0x100008010LL;
  v13 = 73;
  v14 = HIWORD(v7);
  v15 = BYTE1(v7);
  v16 = (unsigned __int8)v7;
  mutex_lock(a1 + 2);
  v8 = *a1;
  *((_DWORD *)a1 + 16) = 0;
  v9 = pmic_glink_write(v8, &v12, 24);
  if ( !v9 )
  {
    if ( (unsigned int)wait_for_completion_timeout(a1 + 8, 250) )
    {
      v10 = *((_DWORD *)a1 + 35);
      if ( v10 )
      {
        dev_err(
          a1[1],
          "glink ADC read failed, bus_id=%u, pmic_id=%u, chan=%u, ret=%u\n",
          *((_DWORD *)a1 + 30),
          *((_DWORD *)a1 + 31),
          *((_DWORD *)a1 + 32),
          v10);
        v9 = -5;
      }
      else
      {
        if ( a3 )
          *a3 = *((_DWORD *)a1 + 34);
        v9 = 0;
        if ( a4 )
          *a4 = *((_DWORD *)a1 + 33);
      }
    }
    else
    {
      dev_err(a1[1], "Error, ADC conversion timed out\n");
      v9 = -110;
    }
  }
  mutex_unlock(a1 + 2);
  _ReadStatusReg(SP_EL0);
  return v9;
}
