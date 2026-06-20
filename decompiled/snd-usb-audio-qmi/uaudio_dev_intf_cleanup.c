__int64 __fastcall uaudio_dev_intf_cleanup(__int64 a1, __int64 a2)
{
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x1
  __int64 v9; // x3
  __int64 v10; // x2
  __int64 result; // x0

  if ( a2 )
  {
    uaudio_iommu_unmap(1, *(_QWORD *)a2, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 8));
    v4 = *(_QWORD *)(a2 + 16);
    v5 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)a2 = 0;
    *(_QWORD *)(a2 + 8) = 0;
    uaudio_iommu_unmap(1, v4, v5, v5);
    v6 = *(_QWORD *)(a2 + 32);
    v7 = *(_QWORD *)(a2 + 40);
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    uaudio_iommu_unmap(2, v6, v7, v7);
    v8 = *(_QWORD *)(a2 + 40);
    v9 = *(_QWORD *)(a2 + 48);
    v10 = *(_QWORD *)(a2 + 64);
    *(_QWORD *)(a2 + 32) = 0;
    result = usb_free_coherent(a1, v8, v10, v9);
    *(_QWORD *)(a2 + 64) = 0;
    *(_BYTE *)(a2 + 76) = 0;
    *(_QWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 48) = 0;
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: info is NULL\n",
      (const char *)&unk_B13E,
      "uaudio_dev_intf_cleanup");
    return printk("%s%s: info is NULL\n", &unk_B45D);
  }
  return result;
}
