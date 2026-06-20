__int64 __fastcall submit_all_buffers(int a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5, char a6)
{
  __int64 v6; // x30
  unsigned int v7; // w21
  int v8; // w22
  __int64 v12; // x27
  __int64 v13; // x28
  unsigned int v14; // w26
  __int64 v15; // x19
  __int64 v16; // x1
  __int64 v17; // x2
  unsigned int v18; // w0
  __int64 v19; // x3
  __int64 v21; // x19
  unsigned int v22; // w19
  __int64 v23; // [xsp+0h] [xbp-10h]

  v7 = a5;
  v8 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v21 = v6;
    printk(&unk_1E83A, "submit_all_buffers", 426, a4, a5);
    v6 = v21;
    if ( a3 )
      goto LABEL_3;
LABEL_16:
    printk(&unk_1905C, "submit_all_buffers", 429, v6, a5);
    return 4294967274LL;
  }
  if ( !a3 )
    goto LABEL_16;
LABEL_3:
  if ( !v8 || !v7 )
    goto LABEL_16;
  if ( (unsigned int)(a1 - 3) <= 0xFFFFFFFD )
  {
    printk(&unk_1CDF6, "submit_all_buffers", 434, v6, 2);
    return 4294967274LL;
  }
  else
  {
    v12 = a3[1];
    v13 = a3[2];
    v14 = 0;
    v15 = a3[4];
    v23 = v6;
    do
    {
      v16 = v12 + v15;
      v17 = v13 + v15;
      if ( a1 == 1 )
      {
        v18 = push_buffers_to_buff_pool(a2, v16, v17, v7, a5);
        if ( v18 )
          goto LABEL_18;
      }
      else
      {
        v18 = push_buffers_to_fw_queue(a2, v16, v17, v7, (a6 & 1) == 0);
        if ( v18 )
        {
LABEL_18:
          v22 = v18;
          printk(&unk_1C3F2, "submit_all_buffers", 452, v23, v14);
          return v22;
        }
      }
      ++v14;
      v15 += v7;
      a3[4] += v7;
    }
    while ( v8 != v14 );
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "submit_all_buffers", 461, v19, a5);
    return 0;
  }
}
