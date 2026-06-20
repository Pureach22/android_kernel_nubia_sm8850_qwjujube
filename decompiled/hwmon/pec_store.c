__int64 __fastcall pec_store(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  __int64 child; // x0
  __int64 v8; // x21
  _DWORD *v9; // x8
  __int64 v10; // x4
  int v11; // w0
  int v12; // w22
  __int16 v13; // w8
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  LODWORD(result) = kstrtobool(a3, v14);
  if ( (result & 0x80000000) != 0 )
  {
    result = (int)result;
  }
  else
  {
    child = device_find_child(a1, 0, hwmon_match_device);
    if ( child )
    {
      v8 = child;
      mutex_lock(&hwmon_pec_mutex);
      v9 = *(_DWORD **)(**(_QWORD **)(v8 + 912) + 24LL);
      if ( !v9 )
        goto LABEL_8;
      v10 = v14[0];
      if ( *(v9 - 1) != -1027269393 )
        __break(0x8228u);
      v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, __int64))v9)(v8, 0, 13, 0, v10);
      if ( !v11 || (v12 = v11, v11 == -95) )
      {
LABEL_8:
        v12 = a4;
        if ( v14[0] )
          v13 = 4;
        else
          v13 = 0;
        *(_WORD *)(a1 - 32) = *(_WORD *)(a1 - 32) & 0xFFFB | v13;
      }
      mutex_unlock(&hwmon_pec_mutex);
      put_device(v8);
      result = v12;
    }
    else
    {
      result = -19;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
