__int64 __fastcall ois_debugfs_datatype_s(__int64 a1, __int64 a2)
{
  if ( (unsigned __int64)(a2 - 1) < 4 )
    *(_DWORD *)(a1 + 8) = a2;
  printk(&unk_407BE4);
  return 0;
}
