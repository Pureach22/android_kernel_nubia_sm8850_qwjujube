__int64 __fastcall ois_debugfs_setaddr(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 16) = a2;
  printk(&unk_43E650);
  return 0;
}
