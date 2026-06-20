__int64 __fastcall hdcp2_app_tx_init_0(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x0
  _DWORD *v4; // x9
  __int64 result; // x0
  int v6; // w9
  unsigned int v7; // w19
  int v8; // [xsp+0h] [xbp-30h] BYREF
  int v9; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v10[5]; // [xsp+8h] [xbp-28h] BYREF

  v10[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 48);
  v8 = 0;
  if ( (v1 & 2) != 0 )
  {
    if ( (v1 & 4) != 0 )
    {
      printk(&unk_BDDE);
      result = 0;
    }
    else
    {
      v9 = *(_DWORD *)(a1 + 120);
      v4 = *(_DWORD **)(a1 + 56);
      v3 = *(_QWORD *)(a1 + 64);
      v10[0] = &v9;
      v10[1] = 4;
      v10[2] = &v8;
      v10[3] = 4;
      if ( *(v4 - 1) != 816020464 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v4)(v3, 2, v10, 17);
      if ( (_DWORD)result )
      {
        v7 = result;
        printk(&unk_CB2C);
        result = v7;
      }
      else
      {
        v6 = *(_DWORD *)(a1 + 48);
        *(_DWORD *)(a1 + 40) = v8;
        *(_DWORD *)(a1 + 48) = v6 | 4;
      }
    }
  }
  else
  {
    printk(&unk_C788);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
