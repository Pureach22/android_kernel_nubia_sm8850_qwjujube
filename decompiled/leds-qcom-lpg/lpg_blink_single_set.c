__int64 __fastcall lpg_blink_single_set(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v5; // x20

  v5 = (_QWORD *)(a1 - 8);
  mutex_lock(*(_QWORD *)(a1 - 8) + 16LL);
  lpg_blink_set(v5, a2, a3);
  mutex_unlock(*v5 + 16LL);
  return 0;
}
