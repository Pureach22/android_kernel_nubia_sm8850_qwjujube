__int64 __fastcall get_finger_lock_flag(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x22
  int v10; // w0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  result = 0;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v12 = 0;
  *(_QWORD *)s = 0;
  if ( !v5 )
  {
    v6 = tpd_cdev;
    printk(&unk_3A127, "get_finger_lock_flag", *(unsigned int *)(tpd_cdev + 1140));
    v10 = snprintf(s, 0xAu, "%u\n", *(_DWORD *)(v6 + 1140));
    result = simple_read_from_buffer(a2, a3, a4, s, v10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
