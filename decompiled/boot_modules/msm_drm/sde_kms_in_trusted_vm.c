__int64 __fastcall sde_kms_in_trusted_vm(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 152);
    if ( v1 )
      LOBYTE(v1) = *(_BYTE *)(v1 + 20120);
    return v1 & 1;
  }
  else
  {
    printk(&unk_234896, "sde_kms_in_trusted_vm");
    return 0;
  }
}
