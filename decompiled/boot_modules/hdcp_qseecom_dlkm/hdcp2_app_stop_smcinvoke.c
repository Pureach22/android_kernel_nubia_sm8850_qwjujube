__int64 __fastcall hdcp2_app_stop_smcinvoke(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x0
  __int64 (__fastcall *v4)(__int64, __int64, int **, __int64); // x8
  unsigned int v5; // w0
  int v6; // w8
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64, __int64, int **, __int64); // x8
  unsigned int v9; // w20
  void *v10; // x0
  void *v11; // x8
  int v13; // [xsp+4h] [xbp-1Ch] BYREF
  int *v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v10 = &unk_C11E;
LABEL_19:
    printk(v10);
    v9 = -22;
    goto LABEL_22;
  }
  v1 = *(_DWORD *)(a1 + 48);
  if ( (v1 & 1) == 0 )
  {
    v10 = &unk_C241;
    goto LABEL_19;
  }
  if ( (v1 & 4) == 0 )
  {
    v10 = &unk_C91F;
    goto LABEL_19;
  }
  v13 = *(_DWORD *)(a1 + 40);
  v4 = *(__int64 (__fastcall **)(__int64, __int64, int **, __int64))(a1 + 56);
  v3 = *(_QWORD *)(a1 + 64);
  v14 = &v13;
  v15 = 4;
  if ( *((_DWORD *)v4 - 1) != 816020464 )
    __break(0x8228u);
  v5 = v4(v3, 3, &v14, 1);
  if ( v5 )
  {
    v11 = &unk_C845;
LABEL_21:
    v9 = v5;
    printk(v11);
    goto LABEL_22;
  }
  v6 = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 48) = v6 & 0xFFFFFFFB;
  if ( (v6 & 1) == 0 )
  {
    v10 = &unk_BEBF;
    goto LABEL_19;
  }
  if ( (v6 & 2) == 0 )
  {
    v10 = &unk_C788;
    goto LABEL_19;
  }
  v13 = *(_DWORD *)(a1 + 120);
  v8 = *(__int64 (__fastcall **)(__int64, __int64, int **, __int64))(a1 + 56);
  v7 = *(_QWORD *)(a1 + 64);
  v14 = &v13;
  v15 = 4;
  if ( *((_DWORD *)v8 - 1) != 816020464 )
    __break(0x8228u);
  v5 = v8(v7, 12, &v14, 1);
  if ( v5 )
  {
    v11 = &unk_BFFF;
    goto LABEL_21;
  }
  *(_DWORD *)(a1 + 48) &= ~2u;
  v9 = hdcp2_app_unload_0(a1);
  kfree(*(_QWORD *)(a1 + 8));
  kfree(*(_QWORD *)(a1 + 24));
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v9;
}
