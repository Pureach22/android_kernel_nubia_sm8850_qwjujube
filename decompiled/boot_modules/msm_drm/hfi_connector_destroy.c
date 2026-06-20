__int64 __fastcall hfi_connector_destroy(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 5136);
  if ( !v1 )
    return printk(&unk_242658, "hfi_connector_destroy");
  kfree(*(_QWORD *)(v1 + 56));
  kfree(*(_QWORD *)(v1 + 64));
  return kfree(v1);
}
