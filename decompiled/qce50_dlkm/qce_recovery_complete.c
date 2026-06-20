__int64 __fastcall qce_recovery_complete(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  if ( a1 && (v3 = *(_QWORD *)(a1 + 80)) != 0 )
    return complete(v3 + 69888);
  else
    return printk(&unk_15F68, "qce_recovery_complete", a3);
}
