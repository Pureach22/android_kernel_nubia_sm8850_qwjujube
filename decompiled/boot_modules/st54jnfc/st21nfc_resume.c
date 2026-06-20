__int64 __fastcall st21nfc_resume(__int64 a1)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x0
  int value; // w0
  int v4; // w8

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 517) == 1 && !(unsigned int)irq_set_irq_wake(*(unsigned int *)(a1 + 916), 0) )
    *(_BYTE *)(v1 + 517) = 0;
  v2 = *(_QWORD *)(v1 + 968);
  if ( v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (value = gpiod_get_value(v2), *(_DWORD *)(v1 + 548) != value)
      || (v4 = *(_DWORD *)(v1 + 536), value) && !v4
      || !value && v4 == 1 )
    {
      queue_work_on(32, *(_QWORD *)(v1 + 712), v1 + 720);
    }
  }
  return 0;
}
