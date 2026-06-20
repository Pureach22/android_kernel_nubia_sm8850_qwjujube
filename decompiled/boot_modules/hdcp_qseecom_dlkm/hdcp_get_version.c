__int64 __fastcall hdcp_get_version(__int64 a1)
{
  char v1; // w8
  __int64 v2; // x0
  _DWORD *v3; // x9
  __int64 result; // x0
  unsigned int v5; // w19
  int v6; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE *)(a1 + 48);
  v6 = 0;
  if ( (v1 & 1) != 0 )
  {
    printk(&unk_C07B);
    result = 0;
  }
  else
  {
    v3 = *(_DWORD **)(a1 + 56);
    v2 = *(_QWORD *)(a1 + 64);
    v7[0] = &v6;
    v7[1] = 4;
    if ( *(v3 - 1) != 816020464 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v3)(v2, 10, v7, 16);
    if ( (_DWORD)result )
    {
      v5 = result;
      printk(&unk_CF2A);
      result = v5;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
