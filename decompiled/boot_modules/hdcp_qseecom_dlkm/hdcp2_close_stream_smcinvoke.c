__int64 __fastcall hdcp2_close_stream_smcinvoke(__int64 a1, int a2)
{
  int v2; // w8
  int v3; // w9
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 result; // x0
  void *v7; // x0
  unsigned int v8; // w19
  _DWORD v9[2]; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v7 = &unk_C11E;
LABEL_12:
    printk(v7);
    result = 4294967274LL;
    goto LABEL_8;
  }
  v2 = *(_DWORD *)(a1 + 48);
  if ( (v2 & 2) == 0 )
  {
    v7 = &unk_C788;
    goto LABEL_12;
  }
  if ( (v2 & 4) == 0 )
  {
    v7 = &unk_C91F;
    goto LABEL_12;
  }
  v3 = *(_DWORD *)(a1 + 120);
  v10[0] = v9;
  v10[1] = 8;
  v5 = *(_DWORD **)(a1 + 56);
  v4 = *(_QWORD *)(a1 + 64);
  v9[0] = v3;
  v9[1] = a2;
  if ( *(v5 - 1) != 816020464 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v5)(v4, 15, v10, 1);
  if ( (_DWORD)result )
  {
    v8 = result;
    printk(&unk_CBB5);
    result = v8;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
