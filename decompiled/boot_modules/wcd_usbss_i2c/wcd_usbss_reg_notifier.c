__int64 __fastcall wcd_usbss_reg_notifier(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 device_by_fwnode; // x0
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w8
  __int64 v10; // x0
  bool *v11; // x2
  __int64 v12; // x1
  bool v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v4 = a2 + 24;
  else
    v4 = 0;
  v14 = v3;
  device_by_fwnode = i2c_find_device_by_fwnode(v4);
  if ( !device_by_fwnode || (v6 = *(_QWORD *)(device_by_fwnode + 184)) == 0 )
  {
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  result = blocking_notifier_chain_register(v6 + 72, a1);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(v6 + 32) != 1 )
    {
LABEL_17:
      result = 0;
      goto LABEL_13;
    }
    v8 = *(_QWORD *)(v6 + 8);
    v13 = 0;
    if ( v8 )
    {
      mutex_lock(v6 + 144);
      v9 = *(_DWORD *)(v6 + 32);
      if ( v9 )
      {
        if ( v9 != 1 )
        {
LABEL_16:
          mutex_unlock(v6 + 144);
          goto LABEL_17;
        }
        v13 = (*(_BYTE *)(v6 + 368) & 0xB8) != 0;
        v10 = v6 + 72;
        v11 = &v13;
        v12 = 1;
      }
      else
      {
        v10 = v6 + 72;
        v12 = 0;
        v11 = nullptr;
      }
      blocking_notifier_call_chain(v10, v12, v11);
      goto LABEL_16;
    }
    goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
