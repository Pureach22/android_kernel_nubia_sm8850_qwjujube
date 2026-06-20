__int64 __fastcall suspend_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  _BOOL8 v6; // x2
  _DWORD *v7; // x8
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = tpd_cdev;
  v8 = 0;
  if ( (unsigned int)kstrtouint_from_user(a2, a3, 10, &v8) )
  {
    v3 = -22;
  }
  else
  {
    v6 = v8 != 0;
    v8 = v8 != 0;
    printk(&unk_328A8, "suspend_store", v6);
    mutex_lock(v4 + 2728);
    if ( v8 == *(unsigned __int8 *)(v4 + 22) )
    {
      printk(&unk_3C9F3, "suspend_store", v8);
    }
    else
    {
      v7 = *(_DWORD **)(v4 + 3240);
      *(_BYTE *)(v4 + 22) = v8 != 0;
      if ( v7 )
      {
        if ( *(v7 - 1) != 953529488 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v7)(v4, 0);
      }
    }
    mutex_unlock(v4 + 2728);
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
