__int64 __fastcall set_finger_lock_flag(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  _BOOL8 v6; // x2
  _BOOL4 v7; // w8
  _BOOL4 v8; // [xsp+4h] [xbp-Ch] BYREF
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
    v6 = v8;
    v8 = v8;
    printk(&unk_374F7, "set_finger_lock_flag", v6);
    v7 = v8;
    *(_DWORD *)(v4 + 1140) = v8;
    if ( v7 )
    {
      if ( (unsigned __int8)word_314C0 == 1 )
        complete(&dword_314A0);
      if ( !*(_DWORD *)(v4 + 1112) )
      {
        msleep(100);
        ((void (__fastcall *)(_QWORD))report_ufp_uevent)(0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
