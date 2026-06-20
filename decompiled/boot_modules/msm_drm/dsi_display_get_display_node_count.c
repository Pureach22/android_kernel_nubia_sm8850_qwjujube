__int64 dsi_display_get_display_node_count()
{
  __int64 compatible_node; // x0
  unsigned int i; // w19
  __int64 v2; // x21

  compatible_node = of_find_compatible_node(0, 0, "qcom,dsi-display");
  for ( i = 0; compatible_node; compatible_node = of_find_compatible_node(v2, 0, "qcom,dsi-display") )
  {
    v2 = compatible_node;
    i += of_device_is_available(compatible_node) & 1;
  }
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: qcom,dsi-display node count %d\n", i);
  return i;
}
