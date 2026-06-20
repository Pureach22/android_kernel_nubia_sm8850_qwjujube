__int64 __fastcall st21nfc_suspend(__int64 a1)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 516) == 1 && !(unsigned int)irq_set_irq_wake(*(unsigned int *)(a1 + 916), 1) )
    *(_BYTE *)(v1 + 517) = 1;
  v2 = *(_QWORD *)(v1 + 968);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    *(_DWORD *)(v1 + 548) = gpiod_get_value(v2);
  return 0;
}
