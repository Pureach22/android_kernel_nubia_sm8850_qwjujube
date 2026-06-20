__int64 __fastcall tpd_set_one_key(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x21

  v4 = *(_QWORD *)(a1 + 3072);
  printk(unk_34878, "tpd_set_one_key", a3);
  if ( !v4 )
    return 4294967274LL;
  *(_DWORD *)(v4 + 1492) = a2;
  *(_DWORD *)(a1 + 1112) = a2;
  return 0;
}
