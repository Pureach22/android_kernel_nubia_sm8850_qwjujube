__int64 init_module()
{
  __int64 node_with_property; // x0
  __int64 v1; // x20

  node_with_property = of_find_node_with_property(0, "qcom,wlan");
  if ( !node_with_property )
    return 4294967277LL;
  v1 = node_with_property;
  while ( (of_device_is_available(v1) & 1) == 0 )
  {
    v1 = of_find_node_with_property(v1, "qcom,wlan");
    if ( !v1 )
      return 4294967277LL;
  }
  return 0;
}
