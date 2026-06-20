__int64 __fastcall save_panic_buf_data_to_nvmem(_QWORD *a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v4; // x1
  __int64 v6; // x2
  unsigned __int64 v7; // x1
  __int64 v8; // x2
  unsigned __int64 v9; // x1
  __int64 v10; // x2
  unsigned __int64 v11; // x1

  if ( !a1 )
    return printk(&unk_721D, a2, a3);
  v4 = a1[18];
  if ( v4 < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_7039, (unsigned __int8)saved_nvmem_buf[3], a3);
    nvmem_cell_write(a1[18], &saved_nvmem_buf[3], 1);
  }
  else
  {
    printk(&unk_74F7, v4, a3);
  }
  v7 = a1[17];
  if ( v7 < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_73F5, (unsigned __int8)saved_nvmem_buf[1], v6);
    nvmem_cell_write(a1[17], &saved_nvmem_buf[1], 1);
  }
  else
  {
    printk(&unk_7364, v7, v6);
  }
  v9 = a1[16];
  if ( v9 < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_7640, (unsigned __int8)saved_nvmem_buf[0], v8);
    nvmem_cell_write(a1[16], saved_nvmem_buf, 1);
  }
  else
  {
    printk(&unk_70C6, v9, v8);
  }
  v11 = a1[19];
  if ( v11 >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_741F, v11, v10);
  printk(&unk_6F73, (unsigned __int8)saved_nvmem_buf[4], (unsigned __int8)byte_5);
  return nvmem_cell_write(a1[19], &saved_nvmem_buf[4], 1);
}
