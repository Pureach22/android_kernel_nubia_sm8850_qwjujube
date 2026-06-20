__int64 __fastcall hdcp2_open_stream_smcinvoke(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, _DWORD *a4)
{
  int v4; // w8
  int v5; // w9
  __int64 v7; // x0
  _DWORD *v8; // x9
  __int64 result; // x0
  void *v10; // x0
  unsigned int v11; // w19
  int v12; // [xsp+4h] [xbp-3Ch] BYREF
  _DWORD v13[4]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v14[5]; // [xsp+18h] [xbp-28h] BYREF

  v14[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  if ( !a1 )
  {
    v10 = &unk_C11E;
LABEL_12:
    printk(v10);
    result = 4294967274LL;
    goto LABEL_8;
  }
  v4 = *(_DWORD *)(a1 + 48);
  if ( (v4 & 2) == 0 )
  {
    v10 = &unk_C788;
    goto LABEL_12;
  }
  if ( (v4 & 4) == 0 )
  {
    v10 = &unk_C91F;
    goto LABEL_12;
  }
  v5 = *(_DWORD *)(a1 + 120);
  v14[0] = v13;
  v14[1] = 16;
  v13[0] = v5;
  v13[1] = a2;
  v13[2] = a3;
  v13[3] = 0;
  v8 = *(_DWORD **)(a1 + 56);
  v7 = *(_QWORD *)(a1 + 64);
  v14[2] = &v12;
  v14[3] = 4;
  if ( *(v8 - 1) != 816020464 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v8)(v7, 14, v14, 17);
  if ( (_DWORD)result )
  {
    v11 = result;
    printk(&unk_C888);
    result = v11;
  }
  else
  {
    *a4 = v12;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
