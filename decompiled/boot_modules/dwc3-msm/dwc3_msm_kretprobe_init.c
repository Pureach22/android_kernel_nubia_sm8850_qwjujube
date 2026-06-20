__int64 dwc3_msm_kretprobe_init()
{
  if ( (register_kretprobe(&dwc3_msm_probes) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_5B8) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_660) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_708) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_7B0) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_858) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_900) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_9A8) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_A50) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_AF8) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_BA0) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_C48) & 0x80000000) != 0 )
    printk(&unk_178F4);
  if ( (register_kretprobe(&unk_CF0) & 0x80000000) != 0 )
    printk(&unk_178F4);
  return 0;
}
