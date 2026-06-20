__int64 __fastcall hdcp2_app_enable_encryption_smcinvoke(__int64 a1, int a2)
{
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 result; // x0
  unsigned int v6; // w19
  int v7; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v8[3]; // [xsp+8h] [xbp-18h] BYREF

  v8[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    *(_DWORD *)(a1 + 16) = a2;
    msleep(300);
    v7 = *(_DWORD *)(a1 + 40);
    v4 = *(_DWORD **)(a1 + 56);
    v3 = *(_QWORD *)(a1 + 64);
    v8[0] = &v7;
    v8[1] = 4;
    if ( *(v4 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v4)(v3, 6, v8, 1);
    if ( (_DWORD)result )
    {
      v6 = result;
      printk(&unk_C14A);
      result = v6;
    }
    else
    {
      *(_DWORD *)(a1 + 48) |= 8u;
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
