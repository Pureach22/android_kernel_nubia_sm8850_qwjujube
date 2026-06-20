__int64 __fastcall hfi_kms_set_reg_dma_buffer(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *cmd_buf; // x0
  int v6; // w9
  __int64 v7; // x19
  void *v8; // x0
  unsigned int v9; // w19
  _DWORD v10[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  result = 4294967274LL;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  if ( !a1 || !a2 )
    goto LABEL_7;
  cmd_buf = hfi_adapter_get_cmd_buf(a1 + 8);
  if ( !cmd_buf )
  {
    v8 = &unk_237EB0;
LABEL_10:
    printk(v8, "hfi_kms_set_reg_dma_buffer");
    result = 4294967274LL;
    goto LABEL_7;
  }
  v6 = *(_DWORD *)(a2 + 20);
  v7 = (__int64)cmd_buf;
  v10[1] = *(_QWORD *)(a2 + 24);
  v10[2] = v6;
  if ( (unsigned int)hfi_adapter_add_set_property((__int64)cmd_buf, 16777228, 0, 2u, (__int64)v10, 0xCu, 0) )
  {
    v8 = &unk_22068D;
    goto LABEL_10;
  }
  result = hfi_adapter_set_cmd_buf(v7);
  if ( (_DWORD)result )
  {
    v9 = result;
    printk(&unk_21D19D, "hfi_kms_set_reg_dma_buffer");
    result = v9;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
