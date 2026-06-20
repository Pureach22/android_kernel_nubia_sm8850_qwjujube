__int64 __fastcall hdcp2_app_start_smcinvoke(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  int v5; // w8
  _DWORD *v6; // x8
  int v7; // w10
  __int64 v8; // x0
  unsigned int v9; // w0
  int v10; // w9
  void *v11; // x0
  unsigned int v12; // w19
  int v13; // [xsp+0h] [xbp-30h] BYREF
  int v14; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v15[5]; // [xsp+8h] [xbp-28h] BYREF

  v15[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v11 = &unk_C11E;
LABEL_14:
    printk(v11);
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  v2 = _kmalloc_cache_noprof(get_client_env_object, 3264, 534);
  *(_QWORD *)(a1 + 8) = v2;
  if ( !v2 )
    goto LABEL_15;
  v3 = _kmalloc_cache_noprof(qseecom_send_command, 3264, 129);
  *(_QWORD *)(a1 + 24) = v3;
  if ( !v3 )
    goto LABEL_15;
  result = hdcp2_app_load_0(a1);
  if ( (_DWORD)result )
    goto LABEL_16;
  v5 = *(_DWORD *)(a1 + 48);
  v13 = 0;
  if ( (v5 & 1) == 0 )
  {
    v11 = &unk_BEBF;
    goto LABEL_14;
  }
  if ( (v5 & 2) != 0 )
  {
    printk(&unk_CB0D);
  }
  else
  {
    v6 = *(_DWORD **)(a1 + 56);
    if ( v6 )
    {
      v7 = *(_DWORD *)(a1 + 124);
      v8 = *(_QWORD *)(a1 + 64);
      v15[0] = &v14;
      v15[1] = 4;
      v14 = v7;
      v15[2] = &v13;
      v15[3] = 4;
      if ( *(v6 - 1) != 816020464 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v6)(v8, 11, v15, 17);
      if ( v9 )
      {
        v12 = v9;
        printk(&unk_C985);
        result = v12;
        goto LABEL_16;
      }
      v10 = *(_DWORD *)(a1 + 48);
      *(_DWORD *)(a1 + 120) = v13;
      *(_DWORD *)(a1 + 48) = v10 | 2;
    }
    else
    {
      printk(&unk_CA68);
    }
  }
  result = hdcp2_app_tx_init_0(a1);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
