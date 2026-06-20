__int64 __fastcall get_hfi_buffer_device_queue(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  __int64 vring; // x0
  __int64 v9; // x4
  unsigned int v10; // w21
  __int64 v11; // x20
  __int64 result; // x0
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x8

  v5 = v3;
  vring = virtqueue_get_vring(*(_QWORD *)(a1 + 1080));
  if ( vring )
  {
    if ( a2 && a3 == 24 )
    {
      v10 = *(_DWORD *)(a1 + 1088);
      v11 = vring;
      if ( v10 == *(unsigned __int16 *)(*(_QWORD *)(vring + 16) + 2LL) )
      {
        return 4294967235LL;
      }
      else
      {
        v13 = *(_QWORD *)(a1 + 1080);
        *(_DWORD *)(a1 + 1088) = v10 + 1;
        v14 = virtqueue_get_vring_size(v13) - 1;
        result = 0;
        v15 = *(unsigned __int16 *)(*(_QWORD *)(v11 + 16) + 2LL * (v14 & v10) + 4);
        *(_QWORD *)a2 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 16 * v15);
        *(_QWORD *)(a2 + 8) = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 16 * v15);
        *(_DWORD *)(a2 + 16) = *(_DWORD *)(*(_QWORD *)(v11 + 8) + 16 * v15 + 8);
        *(_DWORD *)(a2 + 20) = v15;
      }
    }
    else
    {
      printk(&unk_1D0A2, "get_hfi_buffer_device_queue", 506, v5, a2);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1902A, "get_hfi_buffer_device_queue", 501, v5, v9);
    return 4294967274LL;
  }
  return result;
}
