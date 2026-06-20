__int64 __fastcall sde_kms_setup_hfi(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w20

  if ( a1 && a2 )
  {
    if ( (unsigned int)hfi_msm_drv_hfi_init(a1) )
      printk(&unk_2496C1, "sde_kms_setup_hfi");
    result = hfi_kms_reg_client(a2);
    if ( (_DWORD)result )
    {
      v5 = result;
      printk(&unk_231C44, "sde_kms_setup_hfi");
      kfree(*(_QWORD *)(a1 + 5920));
      return v5;
    }
  }
  else
  {
    printk(&unk_26CC17, "sde_kms_setup_hfi");
    return 4294967274LL;
  }
  return result;
}
