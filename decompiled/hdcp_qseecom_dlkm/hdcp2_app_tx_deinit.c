__int64 __fastcall hdcp2_app_tx_deinit(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 result; // x0
  void *v6; // x0
  unsigned int v7; // w19
  int v8; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v9[3]; // [xsp+8h] [xbp-18h] BYREF

  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 48);
  if ( (v1 & 1) == 0 )
  {
    v6 = &unk_C241;
LABEL_10:
    printk(v6);
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( (v1 & 4) == 0 )
  {
    v6 = &unk_C91F;
    goto LABEL_10;
  }
  v8 = *(_DWORD *)(a1 + 40);
  v4 = *(_DWORD **)(a1 + 56);
  v3 = *(_QWORD *)(a1 + 64);
  v9[0] = &v8;
  v9[1] = 4;
  if ( *(v4 - 1) != 816020464 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v4)(v3, 3, v9, 1);
  if ( (_DWORD)result )
  {
    v7 = result;
    printk(&unk_C845);
    result = v7;
  }
  else
  {
    *(_DWORD *)(a1 + 48) &= ~4u;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
