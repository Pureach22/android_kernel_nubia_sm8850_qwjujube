__int64 __fastcall hdcp2_app_init_0(__int64 a1)
{
  char v1; // w8
  __int64 v2; // x0
  _DWORD *v3; // x10
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w19
  int v7; // [xsp+0h] [xbp-30h] BYREF
  int v8; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v9[5]; // [xsp+8h] [xbp-28h] BYREF

  v9[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE *)(a1 + 48);
  v7 = 0;
  if ( (v1 & 1) != 0 )
  {
    printk(&unk_C07B);
  }
  else
  {
    v3 = *(_DWORD **)(a1 + 56);
    v2 = *(_QWORD *)(a1 + 64);
    v8 = 131328;
    v9[0] = &v8;
    v9[1] = 4;
    v9[2] = &v7;
    v9[3] = 4;
    if ( *(v3 - 1) != 816020464 )
      __break(0x822Au);
    v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v3)(v2, 8, v9, 17);
    if ( v4 )
    {
      v6 = v4;
      printk(&unk_C098);
      result = v6;
      goto LABEL_11;
    }
    if ( BYTE1(v7) != 1 )
    {
      printk(&unk_BE6A);
      result = 0xFFFFFFFFLL;
      goto LABEL_11;
    }
    printk(&unk_CF48);
    printk(&unk_BF78);
  }
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
