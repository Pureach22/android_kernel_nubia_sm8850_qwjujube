__int64 __fastcall hfi_connector_get_cmd_buf(unsigned int *a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  void *v5; // x0

  if ( a1 && *(_QWORD *)a1 && (v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
  {
    v3 = *(_QWORD *)(v2 + 8);
    if ( v3 )
      return hfi_kms_get_cmd_buf(*(_QWORD *)(v3 + 6440), a1[685], a2);
    v5 = &unk_234896;
  }
  else
  {
    v5 = &unk_242658;
  }
  printk(v5, "sde_connector_get_kms");
  printk(&unk_242658, "hfi_connector_get_cmd_buf");
  return 0;
}
