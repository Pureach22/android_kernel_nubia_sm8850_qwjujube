__int64 is_qpace_dev_available()
{
  __int64 v0; // x1
  __int64 v1; // x2

  if ( of_find_node_by_name(0, "qcom,qpace") && (of_device_is_available() & 1) != 0 )
    return 1;
  printk(&unk_7DAF, v0, v1);
  return 0;
}
