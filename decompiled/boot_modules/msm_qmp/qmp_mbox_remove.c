__int64 __fastcall qmp_mbox_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  _QWORD *v3; // x19
  _QWORD *i; // x20
  _QWORD *v5; // t1

  v1 = *(_QWORD *)(a1 + 168);
  result = disable_irq(*(unsigned int *)(v1 + 60));
  v5 = *(_QWORD **)(v1 + 16);
  v3 = (_QWORD *)(v1 + 16);
  for ( i = v5; i != v3; i = (_QWORD *)*i )
  {
    mbox_controller_unregister(i + 2);
    result = kfree(i[25]);
  }
  return result;
}
