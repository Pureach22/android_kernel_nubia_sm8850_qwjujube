__int64 init_module()
{
  __int64 node_with_property; // x0
  __int64 v1; // x1
  __int64 v2; // x19
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned __int64 dir; // x2

  node_with_property = of_find_node_with_property(0, "qcom,wlan");
  if ( node_with_property )
  {
    v2 = node_with_property;
    while ( (of_device_is_available(v2) & 1) == 0 )
    {
      v2 = of_find_node_with_property(v2, "qcom,wlan");
      if ( !v2 )
        goto LABEL_5;
    }
    v4 = _kmalloc_cache_noprof(strlen, 3520, 568);
    v5 = v4;
    if ( v4 )
    {
      *(_DWORD *)(v4 + 448) = 0;
      *(_DWORD *)(v4 + 552) = -1;
      _mutex_init(v4 + 336, "&priv->unsafe_channel_list_lock", &cnss_utils_init___key);
      _mutex_init(v5 + 464, "&priv->cnss_device_id_lock", &cnss_utils_init___key_19);
      *(_DWORD *)(v5 + 384) = 0;
      dir = debugfs_create_dir("cnss_utils", 0);
      if ( dir >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_7339, (unsigned int)dir);
      }
      else
      {
        *(_QWORD *)(v5 + 456) = dir;
        debugfs_create_file("mac_address", 384);
      }
      *(_DWORD *)(v5 + 560) = 0;
      cnss_utils_priv = v5;
      *(_BYTE *)(v5 + 556) = 0;
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
LABEL_5:
    printk(&unk_73BD, v1);
    return 4294967277LL;
  }
}
