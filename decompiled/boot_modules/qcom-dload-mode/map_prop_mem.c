__int64 map_prop_mem()
{
  __int64 compatible_node; // x0
  __int64 result; // x0
  void *v2; // x0

  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-dload-type");
  if ( !compatible_node )
  {
    v2 = &unk_7211;
LABEL_6:
    printk(v2, "qcom,msm-imem-dload-type");
    return 0;
  }
  result = of_iomap(compatible_node, 0);
  if ( !result )
  {
    v2 = &unk_71C1;
    goto LABEL_6;
  }
  return result;
}
