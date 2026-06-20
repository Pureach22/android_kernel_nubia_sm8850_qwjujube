__int64 __fastcall board_id_read_proc(__int64 a1)
{
  __int64 compatible_node; // x0
  __int64 v3; // x2
  void *v4; // x0
  int *v5; // x0
  int v6; // w2
  int v7; // w20

  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-board-id");
  if ( compatible_node )
  {
    v5 = (int *)of_iomap(compatible_node, 0);
    vendor_imem_info_addr = (__int64)v5;
    if ( v5 )
    {
      v7 = *v5;
      printk(&unk_67E5, "qcom,msm-imem-board-id", (unsigned int)*v5);
      v6 = v7;
      goto LABEL_7;
    }
    v4 = &unk_67F5;
  }
  else
  {
    v4 = &unk_6864;
  }
  printk(v4, "qcom,msm-imem-board-id", v3);
  v6 = -1;
LABEL_7:
  seq_printf(a1, "%d\n", v6);
  return 0;
}
