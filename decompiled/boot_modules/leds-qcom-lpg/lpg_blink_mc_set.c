__int64 __fastcall lpg_blink_mc_set(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x20

  v3 = (_QWORD *)(a1 - 456);
  mutex_lock(*(_QWORD *)(a1 - 456) + 16LL);
  lpg_blink_set(v3, a2, a3);
  mutex_unlock(*v3 + 16LL);
  return 0;
}
