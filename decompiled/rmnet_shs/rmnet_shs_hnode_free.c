__int64 __fastcall rmnet_shs_hnode_free(__int64 a1)
{
  __int64 v1; // x19

  v1 = a1 - 96;
  kfree(*(_QWORD *)(a1 - 8));
  return kfree(v1);
}
