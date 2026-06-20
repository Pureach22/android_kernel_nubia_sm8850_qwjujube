__int64 __fastcall uaudio_iommu_map(int a1, char a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 result; // x0
  __int64 v13; // x26
  unsigned int v14; // w27
  __int64 v15; // x22
  __int64 v16; // x25
  __int64 v17; // x0
  __int64 v18; // x24
  int v19; // w19
  __int64 v20; // x0
  __int64 v21; // x23
  int v22; // w0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // [xsp+8h] [xbp-28h]
  __int64 v26; // [xsp+10h] [xbp-20h]
  __int64 v27; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v28[2]; // [xsp+20h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v8 = 7;
  else
    v8 = 3;
  v28[0] = a3;
  v27 = 0;
  if ( a1 == 2 )
  {
    v9 = uaudio_qdev + 88;
    v10 = uaudio_qdev + 80;
    v11 = uaudio_qdev + 64;
  }
  else
  {
    if ( a1 != 1 )
    {
      result = 4096;
      if ( (*(_BYTE *)(uaudio_qdev + 104) & 1) != 0 )
        goto LABEL_20;
      goto LABEL_10;
    }
    v9 = uaudio_qdev + 56;
    v10 = uaudio_qdev + 48;
    v11 = uaudio_qdev + 32;
  }
  result = uaudio_get_iova(v9, v10, v11, a4);
LABEL_10:
  if ( result )
  {
    if ( a5 )
    {
      v25 = a4;
      v26 = result;
      if ( *(_DWORD *)(a5 + 8) )
      {
        v13 = *(_QWORD *)a5;
        v14 = 0;
        v15 = 0;
        v16 = result;
        while ( 1 )
        {
          v17 = *(_QWORD *)(uaudio_qdev + 24);
          v18 = (*(_DWORD *)(v13 + 8) + *(_DWORD *)(v13 + 12) + 4095) & 0xFFFFF000;
          v27 = (((*(_QWORD *)v13 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
          v19 = iommu_map(v17, v16, v27, v18, v8, 3264);
          v20 = *(_QWORD *)(uaudio_svc + 24);
          if ( v19 )
            break;
          ipc_log_string(
            v20,
            "%s%s: type:%d map pa:%pa to iova:0x%08lx len:%zu offset:%u\n",
            (const char *)&unk_B13E,
            "uaudio_iommu_map",
            a1,
            &v27,
            v16,
            v18,
            *(_DWORD *)(v13 + 8));
          printk("%s%s: type:%d map pa:%pa to iova:0x%08lx len:%zu offset:%u\n", &unk_B8A7);
          v16 += v18;
          v15 += v18;
          ++v14;
          v13 = sg_next(v13);
          if ( v14 >= *(_DWORD *)(a5 + 8) )
            goto LABEL_18;
        }
        ipc_log_string(v20, "%s%s: mapping failed ret%d\n", (const char *)&unk_B13E, "uaudio_iommu_map", v19);
        printk("%s%s: mapping failed ret%d\n", &unk_B45D);
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: type:%d, pa:%pa iova:0x%08lx sg_len:%zu\n",
          (const char *)&unk_B13E,
          "uaudio_iommu_map",
          a1,
          &v27,
          v16,
          v18);
        printk("%s%s: type:%d, pa:%pa iova:0x%08lx sg_len:%zu\n", &unk_B45D);
        v24 = v25;
        v23 = v26;
        goto LABEL_26;
      }
      v15 = 0;
LABEL_18:
      if ( v15 != v25 )
      {
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: iova size %zu != mapped iova size %zu\n",
          (const char *)&unk_B13E,
          "uaudio_iommu_map",
          v25,
          v15);
        printk("%s%s: iova size %zu != mapped iova size %zu\n", &unk_B45D);
        v23 = v26;
        v24 = v25;
LABEL_26:
        uaudio_iommu_unmap(2, v23, v24, v15);
        result = 0;
        goto LABEL_20;
      }
      result = v26;
    }
    else
    {
      v21 = result;
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: type:%d map pa:%pa to iova:0x%08lx size:%zu\n",
        (const char *)&unk_B13E,
        "uaudio_iommu_map",
        a1,
        v28,
        result,
        a4);
      printk("%s%s: type:%d map pa:%pa to iova:0x%08lx size:%zu\n", &unk_B8A7);
      v22 = iommu_map(*(_QWORD *)(uaudio_qdev + 24), v21, v28[0], a4, v8, 3264);
      if ( v22 )
      {
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: failed to map pa:%pa iova:0x%lx type:%d ret:%d\n",
          (const char *)&unk_B13E,
          "uaudio_iommu_map",
          v28,
          v21,
          a1,
          v22);
        printk("%s%s: failed to map pa:%pa iova:0x%lx type:%d ret:%d\n", &unk_B45D);
      }
      result = v21;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
