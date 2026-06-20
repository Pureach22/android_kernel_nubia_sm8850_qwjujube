__int64 __fastcall tp_fold_state_read(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v8; // x22
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  int v12; // w0
  char s[32]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  result = 0;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v14 = 0;
  *(_QWORD *)s = 0;
  if ( !v5 )
  {
    v8 = tpd_cdev;
    v10 = *(void (__fastcall **)(_QWORD))(tpd_cdev + 3584);
    if ( v10 )
    {
      v11 = tpd_cdev;
      /* CFI check removed */
      v10(v11);
    }
    printk(unk_34061, "tp_fold_state_read", *(unsigned int *)(v8 + 1148));
    v12 = snprintf(s, 0xAu, "%u\n", *(_DWORD *)(v8 + 1148));
    result = simple_read_from_buffer(a2, a3, a4, s, v12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
