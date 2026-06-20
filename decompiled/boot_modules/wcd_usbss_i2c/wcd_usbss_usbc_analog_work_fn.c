__int64 __fastcall wcd_usbss_usbc_analog_work_fn(__int64 a1)
{
  __int64 v1; // x8
  int v3; // w8
  __int64 v4; // x0
  bool *v5; // x2
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 result; // x0
  bool v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 40 )
  {
    result = printk(&unk_B957);
    goto LABEL_11;
  }
  v1 = *(_QWORD *)(a1 - 32);
  v9 = 0;
  if ( v1 )
  {
    mutex_lock(a1 + 104);
    v3 = *(_DWORD *)(a1 - 8);
    if ( v3 )
    {
      if ( v3 != 1 )
      {
LABEL_9:
        mutex_unlock(a1 + 104);
        v7 = *(_QWORD *)(a1 - 32);
        goto LABEL_10;
      }
      v9 = (*(_BYTE *)(a1 + 328) & 0xB8) != 0;
      v4 = a1 + 32;
      v5 = &v9;
      v6 = 1;
    }
    else
    {
      v4 = a1 + 32;
      v6 = 0;
      v5 = nullptr;
    }
    blocking_notifier_call_chain(v4, v6, v5);
    goto LABEL_9;
  }
  v7 = 0;
LABEL_10:
  result = pm_relax(v7);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
