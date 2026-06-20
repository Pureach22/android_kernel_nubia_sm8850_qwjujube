__int64 init_module()
{
  __int64 node_with_property; // x0
  __int64 v1; // x20
  unsigned int v2; // w19
  _BYTE *v4; // x8
  __int64 v5; // x11

  node_with_property = of_find_node_with_property(0, "qcom,wlan");
  if ( node_with_property )
  {
    v1 = node_with_property;
    while ( (of_device_is_available(v1) & 1) == 0 )
    {
      v1 = of_find_node_with_property(v1, "qcom,wlan");
      if ( !v1 )
        return (unsigned int)-19;
    }
    memset(&nl_ops, 0, 0x8C0u);
    printk(&unk_70E3);
    v4 = &unk_662E;
    v5 = 1;
    do
    {
      *(v4 - 2) = v5++;
      *(_QWORD *)(v4 - 46) = cld80211_doit;
      *v4 = 1;
      v4 += 56;
    }
    while ( v5 != 41 );
    v2 = genl_register_family(&cld80211_fam);
    if ( v2 )
      printk(&unk_70AF);
  }
  else
  {
    return (unsigned int)-19;
  }
  return v2;
}
