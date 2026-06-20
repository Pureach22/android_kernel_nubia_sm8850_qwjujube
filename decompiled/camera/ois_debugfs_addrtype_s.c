__int64 __fastcall ois_debugfs_addrtype_s(__int64 a1, __int64 a2)
{
  if ( (unsigned __int64)(a2 - 1) <= 3 )
    *(_DWORD *)(a1 + 12) = a2;
  printk(&unk_413D62);
  return 0;
}
