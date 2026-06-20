__int64 __fastcall hfi_plane_destroy(__int64 a1)
{
  _QWORD *v1; // x19

  if ( !a1 )
    return printk(&unk_226FC0, "hfi_plane_destroy");
  v1 = *(_QWORD **)(a1 + 4272);
  kfree(v1[8]);
  kfree(v1[9]);
  kfree(v1[10]);
  return kfree(v1);
}
