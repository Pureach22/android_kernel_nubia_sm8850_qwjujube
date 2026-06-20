__int64 request_board_id()
{
  __int64 compatible_node; // x0
  __int64 v1; // x2
  void *v2; // x0
  unsigned int *v3; // x0
  unsigned int v5; // w19

  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-board-id");
  if ( !compatible_node )
  {
    v2 = &unk_6864;
LABEL_5:
    printk(v2, "qcom,msm-imem-board-id", v1);
    return 0xFFFFFFFFLL;
  }
  v3 = (unsigned int *)of_iomap(compatible_node, 0);
  vendor_imem_info_addr = (__int64)v3;
  if ( !v3 )
  {
    v2 = &unk_67F5;
    goto LABEL_5;
  }
  v5 = *v3;
  printk(&unk_67E5, "qcom,msm-imem-board-id", *v3);
  return v5;
}
