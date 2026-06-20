__int64 __fastcall hdcp2_app_load_0(__int64 a1)
{
  unsigned int app; // w0
  char v3; // w8
  __int64 v4; // x0
  _DWORD *v5; // x9
  unsigned int v6; // w0
  __int64 result; // x0
  void *v8; // x0
  void *v9; // x8
  unsigned int v10; // w19
  unsigned int v11; // w19
  void *v12; // x0
  int v13; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 48) & 1) != 0 )
  {
    printk(&unk_C07B);
    result = 0;
    goto LABEL_12;
  }
  app = load_app(
          (__int64)"hdcp2p2",
          (int **)(a1 + 56),
          (__int64 (__fastcall **)(__int64, __int64, int **, __int64))(a1 + 72));
  if ( app )
  {
    v9 = &unk_C685;
LABEL_21:
    v10 = app;
    printk(v9);
    result = v10;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(a1 + 56) )
  {
    v8 = &unk_C2DD;
    goto LABEL_19;
  }
  app = load_app(
          (__int64)"hdcpsrm",
          (int **)(a1 + 88),
          (__int64 (__fastcall **)(__int64, __int64, int **, __int64))(a1 + 104));
  if ( !app )
  {
    if ( *(_QWORD *)(a1 + 88) )
      goto LABEL_6;
    goto LABEL_15;
  }
  if ( app != 16 )
  {
    v9 = &unk_C1CC;
    goto LABEL_21;
  }
  printk(&unk_C4B3);
  if ( !*(_QWORD *)(a1 + 88) )
  {
LABEL_15:
    v8 = &unk_CE14;
LABEL_19:
    printk(v8);
    result = 4294967274LL;
    goto LABEL_12;
  }
LABEL_6:
  v3 = *(_BYTE *)(a1 + 48);
  v13 = 0;
  if ( (v3 & 1) != 0 )
  {
    printk(&unk_C07B);
  }
  else
  {
    v5 = *(_DWORD **)(a1 + 56);
    v4 = *(_QWORD *)(a1 + 64);
    v14[0] = &v13;
    v14[1] = 4;
    if ( *(v5 - 1) != 816020464 )
      __break(0x8229u);
    v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v5)(v4, 10, v14, 16);
    if ( v6 )
    {
      v11 = v6;
      printk(&unk_CF2A);
      v12 = &unk_C7C0;
      goto LABEL_25;
    }
  }
  result = hdcp2_app_init_0(a1);
  if ( (_DWORD)result )
  {
    v11 = result;
    v12 = &unk_C210;
LABEL_25:
    printk(v12);
    result = v11;
    goto LABEL_12;
  }
  *(_DWORD *)(a1 + 48) |= 1u;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
