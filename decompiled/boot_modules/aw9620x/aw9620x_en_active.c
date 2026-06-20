__int64 __fastcall aw9620x_en_active(__int64 a1)
{
  __int64 v2; // x1
  int v3; // w0
  __int64 v4; // x1
  int v5; // w6

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_en_active", 2949);
  if ( (unsigned int)aw9620x_i2c_write(a1, 0x4408u, 2) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write REG_CMD err\n", "aw9620x_en_active", 2954);
    return 0xFFFFFFFFLL;
  }
  v2 = *(_QWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 16) = 2;
  dev_printk(&unk_142BB, v2, "[%s:%d] addr: 0x%x data: 0x%x\n", "aw9620x_en_active", 2958, 17416, 1);
  v3 = aw9620x_i2c_write(a1, 0x4414u, *(_DWORD *)(a1 + 20));
  v4 = *(_QWORD *)(a1 + 48);
  v5 = *(_DWORD *)(a1 + 20);
  if ( v3 )
  {
    dev_printk(&unk_142BB, v4, "[%s:%d] addr: 0x%x data: 0x%x\n", "aw9620x_en_active", 2963, 17428, v5);
    return 0xFFFFFFFFLL;
  }
  dev_printk(&unk_142BB, v4, "[%s:%d] addr: 0x%x data: 0x%x\n", "aw9620x_en_active", 2966, 17428, v5);
  if ( *(_BYTE *)(a1 + 5) != 1 )
    return 0;
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enable_irq ok!!!\n", "aw9620x_en_active", 2969);
  enable_irq(*(unsigned int *)(a1 + 28));
  *(_BYTE *)(a1 + 5) = 0;
  return 0;
}
