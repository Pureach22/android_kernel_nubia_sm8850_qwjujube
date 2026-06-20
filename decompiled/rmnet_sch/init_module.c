__int64 init_module()
{
  printk(&unk_6BE9, "1.2");
  return register_qdisc(&rmnet_sch_qdisc_ops);
}
