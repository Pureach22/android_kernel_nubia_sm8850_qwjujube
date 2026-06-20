__int64 __fastcall ois_debugfs_getaddr(__int64 a1, _QWORD *a2)
{
  *a2 = *(_QWORD *)(a1 + 16);
  printk(&unk_43E650);
  return 0;
}
