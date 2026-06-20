__int64 __fastcall _qseecom_send_command(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  int v5; // w9
  __int64 v6; // x0
  _DWORD *v7; // x9
  __int64 result; // x0
  _BOOL4 v9; // [xsp+4h] [xbp-ACh] BYREF
  _QWORD v10[21]; // [xsp+8h] [xbp-A8h] BYREF

  v10[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 && a3 && a1 && a2 && a4 )
  {
    v5 = *(unsigned __int8 *)(a1 + 48);
    v10[0] = a2;
    v10[1] = a3;
    v10[8] = a2;
    v10[9] = a3;
    v10[2] = a4;
    v10[3] = a5;
    v9 = v5 == 2;
    v10[6] = &v9;
    v10[7] = 4;
    v7 = *(_DWORD **)(a1 + 88);
    v6 = *(_QWORD *)(a1 + 96);
    v10[10] = a4;
    v10[11] = a5;
    v10[4] = 0;
    v10[5] = 0;
    memset(&v10[12], 0, 64);
    if ( *(v7 - 1) != 816020464 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *, __int64))v7)(v6, 0, v10, 1060);
  }
  else
  {
    printk(&unk_109DA, "__qseecom_send_command", a1);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
