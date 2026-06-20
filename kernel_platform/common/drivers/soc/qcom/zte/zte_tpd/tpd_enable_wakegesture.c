__int64 __fastcall tpd_enable_wakegesture(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 3072);
  if ( *(_DWORD *)(v3 + 1404) == 1 )
  {
    *(_DWORD *)(v3 + 1476) = a2;
    return 0;
  }
  else
  {
    printk(unk_3B5E0, "tpd_enable_wakegesture", a3);
    return 0;
  }
}
