__int64 __fastcall hfi_kms_reg_client(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 56);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(v1 + 5920);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 8);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v1 + 8);
      if ( v4 )
      {
        v5 = *(_QWORD *)(v4 + 6440);
        if ( v5 )
        {
          *(_QWORD *)(v5 + 152) = v3;
          *(_QWORD *)(v5 + 120) = hfi_kms_process_cmd_buf;
          result = hfi_adapter_client_register(v3, v5 + 8);
          if ( !(_DWORD)result )
            return result;
          printk(&unk_24C286, "_hfi_kms_setup_hfi");
        }
        printk(&unk_242739, "hfi_kms_reg_client");
      }
      else
      {
        printk(&unk_256A7F, "hfi_kms_reg_client");
      }
    }
    else
    {
      printk(&unk_26C260, "hfi_kms_reg_client");
    }
  }
  else
  {
    printk(&unk_2157BB, "hfi_kms_reg_client");
  }
  return 0xFFFFFFFFLL;
}
