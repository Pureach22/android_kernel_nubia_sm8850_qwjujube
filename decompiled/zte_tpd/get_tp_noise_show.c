__int64 __fastcall get_tp_noise_show(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v8; // x22
  void (__fastcall *v10)(_QWORD); // x8
  _QWORD *v11; // x8
  __int64 v12; // x23
  __int64 v13; // x2
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  _WORD v16[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  result = 0;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v15 = 0;
  memset(v16, 0, sizeof(v16));
  *(_QWORD *)s = 0;
  if ( !v5 )
  {
    v8 = tpd_cdev;
    mutex_lock(tpd_cdev + 2728);
    v10 = *(void (__fastcall **)(_QWORD))(v8 + 3376);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 1945898361 )
        __break(0x8228u);
      v10(v8);
    }
    v11 = *(_QWORD **)(v8 + 2720);
    if ( v11 )
    {
      v12 = snprintf(s, 0x1Eu, "%zu\n", *v11);
      printk(&unk_34C95, **(_QWORD **)(v8 + 2720), v13);
    }
    else
    {
      v12 = 0;
    }
    mutex_unlock(v8 + 2728);
    result = simple_read_from_buffer(a2, a3, a4, s, v12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
