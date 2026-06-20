__int64 __fastcall qcedev_unmap_buffer(__int64 result, _DWORD *a2, _QWORD *a3, __int64 a4)
{
  __int64 v5; // x2
  __int64 v6; // x3

  if ( *a2 )
  {
    printk(&unk_1233D, "qcedev_unmap_buffer", a3, a4);
    return printk(&unk_1263A, "qcedev_unmap_buffer", v5, v6);
  }
  else if ( *(_QWORD *)(*(_QWORD *)result + 320LL) != *(_QWORD *)result + 320LL )
  {
    dma_buf_unmap_attachment_unlocked(a3[5], a3[4], 0);
    dma_buf_detach(a3[6], a3[5]);
    return dma_buf_put(a3[6]);
  }
  return result;
}
