unsigned int *__fastcall print_hfi_packet_info(unsigned int *result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  unsigned int v5; // w8
  unsigned __int64 v6; // x4
  int v7; // w8
  unsigned __int64 v8; // x25
  unsigned int v9; // w19
  void *v10; // x0
  __int64 v11; // x2
  unsigned int *v12; // x19
  __int64 v13; // x20

  if ( !result )
  {
    v10 = &unk_1C5F8;
    v11 = 441;
    return (unsigned int *)printk(v10, "print_hfi_packet_info", v11, v4);
  }
  v5 = result[4];
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v12 = result;
    v13 = v4;
    printk(&unk_1C7D9, "print_hfi_packet_info", 474, *result);
    v5 = v12[4];
    result = v12;
    v4 = v13;
  }
  if ( v5 - 1 < 2 )
  {
    v6 = result[5];
    if ( !*((_QWORD *)result + 3) || (unsigned int)v6 <= 3 )
      return (unsigned int *)printk(&unk_193F5, "print_u32_payload", 424, v4);
    v7 = msm_hfi_core_debug_level;
    v8 = v6 >> 2;
    v9 = 0;
    do
    {
      if ( (~v7 & 0x10001) == 0 )
      {
        result = (unsigned int *)printk(&unk_1F2DA, "print_u32_payload", 430, v9);
        v7 = msm_hfi_core_debug_level;
      }
      ++v9;
    }
    while ( (_DWORD)v8 != v9 );
    return result;
  }
  if ( v5 )
  {
    v10 = &unk_1ACC9;
    v11 = 487;
    return (unsigned int *)printk(v10, "print_hfi_packet_info", v11, v4);
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    return (unsigned int *)printk(&unk_1BE07, "print_hfi_packet_info", 479, a4);
  return result;
}
