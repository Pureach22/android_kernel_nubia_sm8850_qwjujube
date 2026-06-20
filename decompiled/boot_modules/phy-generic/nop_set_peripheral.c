__int64 __fastcall nop_set_peripheral(__int64 a1, __int64 a2)
{
  int v2; // w8

  if ( !a1 )
    return 4294967277LL;
  if ( a2 )
  {
    v2 = *(_DWORD *)(a1 + 40);
    *(_QWORD *)(a1 + 32) = a2;
    if ( v2 == 3 )
      atomic_notifier_call_chain(*(_QWORD *)(a1 + 16) + 224LL, 1, a2);
    else
      *(_DWORD *)(a1 + 40) = 1;
    return 0;
  }
  else
  {
    *(_QWORD *)(a1 + 32) = 0;
    return 4294967277LL;
  }
}
