__int64 __fastcall sde_debugfs_core_irq_init(__int64 a1, __int64 a2)
{
  __int64 file; // x8

  file = debugfs_create_file("core_irq", 256, a2, a1 + 1904, &sde_debugfs_core_irq_fops);
  *(_QWORD *)(a1 + 1944) = file;
  return 0;
}
