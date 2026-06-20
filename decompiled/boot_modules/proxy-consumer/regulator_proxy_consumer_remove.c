__int64 __fastcall regulator_proxy_consumer_remove(__int64 *a1)
{
  int v2; // w8
  __int64 **v3; // x8
  __int64 *v4; // x9

  if ( *((_BYTE *)a1 + 32) == 1 && (unsigned int)regulator_disable(a1[2]) )
  {
    printk(&unk_6966, "regulator_proxy_consumer_remove");
    if ( !*((_DWORD *)a1 + 11) )
      goto LABEL_6;
  }
  else if ( !*((_DWORD *)a1 + 11) )
  {
    goto LABEL_6;
  }
  if ( (regulator_set_load(a1[2]) & 0x80000000) != 0 )
    printk(&unk_6B39, "regulator_proxy_consumer_remove");
LABEL_6:
  v2 = *((_DWORD *)a1 + 10);
  if ( v2 >= 1 && *((_DWORD *)a1 + 9) <= v2 && (unsigned int)regulator_set_voltage(a1[2], 0, 0x7FFFFFFF) )
    printk(&unk_6AEF, "regulator_proxy_consumer_remove");
  regulator_put(a1[2]);
  v3 = (__int64 **)a1[1];
  if ( *v3 == a1 && (v4 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
  {
    v4[1] = (__int64)v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  return kfree(a1);
}
