__int64 __fastcall uaudio_iommu_unmap(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  unsigned int v9; // w21

  if ( a2 && a3 )
  {
    if ( (_DWORD)result == 2 )
    {
      v6 = a3;
      v7 = uaudio_qdev + 64;
      v8 = uaudio_qdev + 80;
LABEL_7:
      v9 = result;
      uaudio_put_iova(a2, v6, v7, v8);
      result = v9;
      if ( !a4 )
        return result;
      goto LABEL_8;
    }
    if ( (_DWORD)result == 1 )
    {
      v6 = a3;
      v7 = uaudio_qdev + 32;
      v8 = uaudio_qdev + 48;
      goto LABEL_7;
    }
    if ( *(_BYTE *)(uaudio_qdev + 104) == 1 )
    {
      *(_BYTE *)(uaudio_qdev + 104) = 0;
      if ( a4 )
      {
LABEL_8:
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: type %d: unmap iova 0x%08lx size %zu\n",
          (const char *)&unk_B13E,
          "uaudio_iommu_unmap",
          result,
          a2,
          a4);
        printk("%s%s: type %d: unmap iova 0x%08lx size %zu\n", &unk_B8A7);
        result = iommu_unmap(*(_QWORD *)(uaudio_qdev + 24), a2, a4);
        if ( result != a4 )
        {
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: unmapped size %zu for iova 0x%08lx of mapped size %zu\n",
            (const char *)&unk_B13E,
            "uaudio_iommu_unmap",
            result,
            a2,
            a4);
          return printk("%s%s: unmapped size %zu for iova 0x%08lx of mapped size %zu\n", &unk_B45D);
        }
      }
    }
  }
  return result;
}
