__int64 __fastcall hdcp2_force_encryption_smcinvoke(__int64 a1, int a2)
{
  int v4; // w9
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 result; // x0
  unsigned int v8; // w19
  _DWORD v9[2]; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 48) == 8 )
      msleep(200);
    v4 = *(_DWORD *)(a1 + 40);
    v10[0] = v9;
    v10[1] = 8;
    v6 = *(_DWORD **)(a1 + 56);
    v5 = *(_QWORD *)(a1 + 64);
    v9[0] = v4;
    v9[1] = a2;
    if ( *(v6 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v6)(v5, 16, v10, 1);
    if ( (_DWORD)result )
    {
      v8 = result;
      printk(&unk_C95E);
      result = v8;
    }
  }
  else
  {
    printk(&unk_C11E);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
