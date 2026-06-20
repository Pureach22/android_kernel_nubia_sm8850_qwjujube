__int64 __fastcall f_cdev_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0

  v2 = *(_QWORD *)(a2 + 32);
  v3 = raw_spin_lock_irqsave(v2 + 1068);
  *(_BYTE *)(v2 + 1561) = 0;
  *(_BYTE *)(v2 + 1548) = 0;
  raw_spin_unlock_irqrestore(v2 + 1068, v3);
  put_device(v2 + 136);
  return 0;
}
