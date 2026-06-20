__int64 __fastcall fastrpc_sysfs_domain_remove(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  if ( (*(_BYTE *)(a1 + 140) & 1) != 0 )
    kobject_put(a1 + 80);
  return printk(&unk_24BB8, "fastrpc_sysfs_domain_remove", a1 + 20, a4, a5, a6);
}
