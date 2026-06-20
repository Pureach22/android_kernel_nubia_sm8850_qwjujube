__int64 __fastcall set_hfi_buffer_device_queue(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x20
  __int64 vring; // x0
  __int64 v9; // x4
  __int64 v10; // x21
  unsigned int vring_size; // w0
  __int64 v12; // x4
  __int16 v13; // w5
  __int64 result; // x0
  __int64 v15; // x8

  v5 = v3;
  vring = virtqueue_get_vring(*(_QWORD *)(a1 + 1080));
  if ( vring )
  {
    if ( a2 && a3 == 24 )
    {
      v10 = vring;
      vring_size = virtqueue_get_vring_size(*(_QWORD *)(a1 + 1080));
      v12 = *(unsigned int *)(a2 + 20);
      v13 = vring_size;
      if ( (unsigned int)v12 >= vring_size )
      {
        printk(&unk_18D40, "set_hfi_buffer_device_queue", 477, v5, v12);
        return 4294967274LL;
      }
      else
      {
        result = 0;
        v15 = *(_QWORD *)(v10 + 24) + 8LL * (unsigned __int16)(*(_WORD *)(*(_QWORD *)(v10 + 24) + 2LL) & (v13 - 1));
        *(_DWORD *)(v15 + 4) = v12;
        *(_DWORD *)(v15 + 8) = *(_DWORD *)(a2 + 16);
        ++*(_WORD *)(*(_QWORD *)(v10 + 24) + 2LL);
      }
    }
    else
    {
      printk(&unk_1D0A2, "set_hfi_buffer_device_queue", 471, v5, a2);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1902A, "set_hfi_buffer_device_queue", 466, v5, v9);
    return 4294967274LL;
  }
  return result;
}
