__int64 __fastcall rmnet_ll_ipa_probe(__int64 *a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  if ( !v2 )
    return printk(&unk_2CB32, "rmnet_ll_ipa_probe");
  result = dev_get_by_name(&init_net, "rmnet_ipa0");
  *(_QWORD *)(v2 + 40) = result;
  if ( result )
  {
    *a1 = v2;
  }
  else
  {
    printk(&unk_2CD89, "rmnet_ll_ipa_probe");
    return kfree(v2);
  }
  return result;
}
