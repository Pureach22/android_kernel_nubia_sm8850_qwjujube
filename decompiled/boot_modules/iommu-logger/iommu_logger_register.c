__int64 __fastcall iommu_logger_register(const char **a1, const char **a2, __int64 a3)
{
  unsigned __int64 v3; // x19
  __int64 v7; // x8
  const char ***v8; // x11
  int v9; // w10
  unsigned int v10; // w25
  unsigned int v11; // w9
  unsigned int v12; // w10
  int v13; // w26
  __int64 v14; // x22
  __int64 v15; // x27
  __int64 v16; // x0
  __int64 v17; // x20
  unsigned __int64 v18; // x27
  __int64 v19; // x22
  void *v20; // x0
  void *v21; // x2

  if ( a3 )
  {
    LODWORD(v3) = -22;
    if ( a1 && a2 )
    {
      mutex_lock(&iommu_debug_attachments_lock);
      v7 = a3;
      v8 = (const char ***)iommu_debug_attachments;
      if ( iommu_debug_attachments != (_UNKNOWN *)&iommu_debug_attachments )
      {
        while ( v8[2] != a2 || *(v8 - 6) != a1 )
        {
          v8 = (const char ***)*v8;
          if ( v8 == (const char ***)&iommu_debug_attachments )
            goto LABEL_11;
        }
        goto LABEL_9;
      }
LABEL_11:
      v9 = *(_DWORD *)(a3 - 128);
      v10 = 0;
      v11 = v9 + 2;
      if ( (unsigned int)(v9 + 2) <= 4 && v9 != 1 )
        v10 = (*(_DWORD *)(a3 - 88) - 4) / ((unsigned int)__clz(__rbit64(*(_QWORD *)(a3 - 96))) - 3);
      if ( v11 > 4 || ((0x17u >> v11) & 1) == 0 || !v10 )
      {
        LODWORD(v3) = -22;
        goto LABEL_26;
      }
      v12 = v9 + 2;
      LODWORD(v3) = -22;
      if ( v12 > 4 || v12 == 3 )
        goto LABEL_26;
      v13 = dword_6444[v11];
      v14 = *(_QWORD *)(v7 - 40);
      v15 = memstart_addr;
      v3 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
      if ( v3 )
      {
        v16 = kasprintf(3264, "%s", *a2);
        if ( v16 )
        {
          v17 = v16;
          v18 = (v14 - v15) | 0xFFFFFF8000000000LL;
          v19 = iommu_group_get(a2);
          iommu_group_put();
          v20 = (void *)(v3 + 48);
          *(_QWORD *)(v3 + 48) = v3 + 48;
          *(_QWORD *)(v3 + 56) = v3 + 48;
          *(_QWORD *)v3 = a1;
          *(_QWORD *)(v3 + 8) = v19;
          *(_QWORD *)(v3 + 16) = v17;
          *(_DWORD *)(v3 + 24) = v13;
          *(_DWORD *)(v3 + 28) = v10;
          *(_QWORD *)(v3 + 32) = v18;
          *(_QWORD *)(v3 + 40) = 0;
          *(_QWORD *)(v3 + 64) = a2;
          if ( v3 >= 0xFFFFFFFFFFFFF001LL )
            goto LABEL_26;
          v21 = iommu_debug_attachments;
          if ( iommu_debug_attachments == v20
            || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)iommu_debug_attachments) != &iommu_debug_attachments )
          {
            _list_add_valid_or_report();
          }
          else
          {
            *(_QWORD *)((char *)&unk_8 + (_QWORD)iommu_debug_attachments) = v20;
            *(_QWORD *)(v3 + 48) = v21;
            *(_QWORD *)(v3 + 56) = &iommu_debug_attachments;
            iommu_debug_attachments = (_UNKNOWN *)(v3 + 48);
          }
LABEL_9:
          LODWORD(v3) = 0;
LABEL_26:
          mutex_unlock(&iommu_debug_attachments_lock);
          return (unsigned int)v3;
        }
        kfree(v3);
      }
      LODWORD(v3) = -12;
      goto LABEL_26;
    }
  }
  else
  {
    LODWORD(v3) = 0;
  }
  return (unsigned int)v3;
}
