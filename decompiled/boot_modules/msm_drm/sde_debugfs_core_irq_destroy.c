__int64 __fastcall sde_debugfs_core_irq_destroy(__int64 a1)
{
  __int64 result; // x0

  result = debugfs_remove(*(_QWORD *)(a1 + 1944));
  *(_QWORD *)(a1 + 1944) = 0;
  return result;
}
