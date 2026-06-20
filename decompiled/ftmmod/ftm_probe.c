__int64 __fastcall ftm_probe(__int64 a1)
{
  __int64 compatible_node; // x0
  __int64 v3; // x1
  void *v4; // x0
  __int64 v5; // x2
  unsigned int group; // w19

  printk(&unk_673A, "ftm_probe");
  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-efs-golden-copy");
  if ( compatible_node )
  {
    ftm_sysdev_priv_data_2 = of_iomap(compatible_node, 0);
    if ( ftm_sysdev_priv_data_2 )
      goto LABEL_6;
    v4 = &unk_66CA;
  }
  else
  {
    v4 = &unk_6837;
  }
  printk(v4, v3);
LABEL_6:
  ftm_sysdev_priv_data_0 = 1;
  if ( arm64_use_ng_mappings )
    v5 = 0x68000000000F13LL;
  else
    v5 = 0x68000000000713LL;
  ftm_sysdev_priv_data_1 = ioremap_prot(360448, 4096, v5);
  if ( ftm_sysdev_priv_data_1 )
  {
    group = sysfs_create_group(a1 + 16, ftm_attr_grp);
    if ( group )
      printk(&unk_66FB, group);
    else
      printk(&unk_66B5, "ftm_probe");
  }
  else
  {
    printk(&unk_6699, "ftm_probe");
    return (unsigned int)-12;
  }
  return group;
}
