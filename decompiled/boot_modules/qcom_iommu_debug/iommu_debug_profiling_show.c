__int64 __fastcall iommu_debug_profiling_show(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x0
  _UNKNOWN **v4; // x19
  __int64 v5; // x27
  const char *v6; // x2
  void *v7; // t1
  unsigned __int64 v8; // x25
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x23
  __int64 v11; // x24
  __int64 v12; // x26
  unsigned __int64 v13; // x28
  __int64 v14; // x28
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x28
  __int64 v18; // x0
  _UNKNOWN **v19; // x20
  __int64 v20; // x27
  __int64 v21; // t1
  __int64 v22; // x0
  unsigned __int64 v23; // x19
  unsigned __int64 v24; // x25
  unsigned __int64 v25; // x22
  __int64 v26; // x20
  __int64 v27; // x26
  __int64 v28; // x28
  __int64 v29; // x0
  __int64 v30; // x24
  __int64 v31; // x23
  __int64 v32; // x0
  unsigned __int64 v33; // x24
  _UNKNOWN **v34; // x20
  const char *v35; // x2
  _QWORD *v36; // x23
  unsigned int v37; // w19
  _UNKNOWN **v39; // [xsp+0h] [xbp-30h]
  __int64 v41; // [xsp+10h] [xbp-20h]
  _QWORD *v42; // [xsp+18h] [xbp-18h] BYREF
  __int64 v43; // [xsp+20h] [xbp-10h]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 128);
  mutex_lock(v1 + 56);
  v41 = v1;
  if ( iommu_debug_usecase_reset(v1) )
  {
    v2 = *(_QWORD *)(v1 + 40);
    seq_printf(a1, "(average over %d iterations)\n", *(_DWORD *)(v1 + 144));
    v3 = seq_printf(a1, "%8s %19s %16s\n", "size", "iommu_map", "iommu_unmap");
    v4 = &off_C428;
    v5 = 4096;
    while ( 1 )
    {
      if ( *(_DWORD *)(v41 + 144) )
      {
        v8 = 0;
        v9 = 0;
        v10 = 0;
        v11 = -1LL << -(char)__clz(v5 - 1);
        v12 = 0xFFFF - v11;
        do
        {
          v14 = ktime_get(v3);
          v15 = iommu_map(v2, v12 & v11, (v5 + 0x7FFFFFFF) & -v5, v5, 3, 3264);
          if ( (_DWORD)v15 )
          {
            v3 = seq_write(a1, "Failed to map\n", 14);
          }
          else
          {
            v16 = ktime_get(v15);
            v10 += v16 - v14;
            v17 = ktime_get(v16);
            v18 = iommu_unmap(v2, v12 & v11, v5);
            if ( v18 == v5 )
            {
              v3 = ktime_get(v18);
              v9 = v9 - v17 + v3;
            }
            else
            {
              v3 = seq_printf(a1, "Only unmapped %zx instead of %zx\n", v18, v5);
            }
          }
          ++v8;
          v13 = *(unsigned int *)(v41 + 144);
        }
        while ( v8 < v13 );
      }
      else
      {
        v10 = 0;
        v9 = 0;
        v13 = 0;
      }
      if ( v5 >= 0x200000 )
      {
        if ( v5 <= 20971519 )
        {
          if ( v5 == 0x200000 )
          {
            v6 = (const char *)&unk_D4E7;
          }
          else
          {
            if ( v5 != 12582912 )
            {
LABEL_35:
              printk(&unk_D4EA, "_size_to_string");
              v6 = "unknown size";
              goto LABEL_4;
            }
            v6 = "12M";
          }
        }
        else
        {
          switch ( v5 )
          {
            case 0x1400000LL:
              v6 = (const char *)&unk_D811;
              break;
            case 0x1800000LL:
              v6 = (const char *)&unk_CCCB;
              break;
            case 0x2000000LL:
              v6 = "32M";
              break;
            default:
              goto LABEL_35;
          }
        }
      }
      else if ( v5 < 0x4000 )
      {
        v6 = "4K";
        if ( v5 != 4096 )
        {
          if ( v5 != 0x2000 )
            goto LABEL_35;
          v6 = "8K";
        }
      }
      else
      {
        switch ( v5 )
        {
          case 0x4000LL:
            v6 = "16K";
            break;
          case 0x10000LL:
            v6 = (const char *)&unk_D68A;
            break;
          case 0x100000LL:
            v6 = (const char *)&unk_D80E;
            break;
          default:
            goto LABEL_35;
        }
      }
LABEL_4:
      v3 = seq_printf(
             a1,
             "%8s %12lld.%03d us %9lld.%03d us\n",
             v6,
             v10 / v13 / 0x3E8,
             v10 / v13 % 0x3E8,
             v9 / v13 / 0x3E8,
             v9 / v13 % 0x3E8);
      v7 = v4[1];
      ++v4;
      v5 = (__int64)v7;
      if ( !v7 )
      {
        seq_putc(a1, 10);
        seq_printf(a1, "%8s %19s %16s\n", "size", "iommu_map_sg", "iommu_unmap");
        v19 = &off_C428;
        v20 = 4096;
        while ( 1 )
        {
          v42 = nullptr;
          v43 = 0;
          v22 = ((__int64 (__fastcall *)(_QWORD **, __int64))iommu_debug_build_phoney_sg_table)(&v42, v20);
          if ( (_DWORD)v22 )
          {
            seq_write(a1, "couldn't build phoney sg table! bailing...\n", 43);
            goto LABEL_76;
          }
          v39 = v19;
          if ( *(_DWORD *)(v41 + 144) )
            break;
          v25 = 0;
          v24 = 0;
          v33 = 0;
          if ( v20 < 0x200000 )
            goto LABEL_45;
LABEL_51:
          v34 = v39;
          if ( v20 <= 20971519 )
          {
            if ( v20 == 0x200000 )
            {
              v35 = (const char *)&unk_D4E7;
              goto LABEL_69;
            }
            if ( v20 == 12582912 )
            {
              v35 = "12M";
              goto LABEL_69;
            }
          }
          else
          {
            switch ( v20 )
            {
              case 0x1400000LL:
                v35 = (const char *)&unk_D811;
                goto LABEL_69;
              case 0x1800000LL:
                v35 = (const char *)&unk_CCCB;
                goto LABEL_69;
              case 0x2000000LL:
                v35 = "32M";
                goto LABEL_69;
            }
          }
LABEL_74:
          printk(&unk_D4EA, "_size_to_string");
          v35 = "unknown size";
LABEL_69:
          seq_printf(
            a1,
            "%8s %12lld.%03d us %9lld.%03d us\n",
            v35,
            v25 / v33 / 0x3E8,
            v25 / v33 % 0x3E8,
            v24 / v33 / 0x3E8,
            v24 / v33 % 0x3E8);
LABEL_70:
          if ( (_DWORD)v43 )
          {
            v36 = v42;
            v37 = 0;
            do
            {
              _free_pages(*v36 & 0xFFFFFFFFFFFFFFFCLL, 0);
              ++v37;
              v36 = (_QWORD *)sg_next(v36);
            }
            while ( v37 < (unsigned int)v43 );
          }
          sg_free_table(&v42);
          v21 = (__int64)v34[1];
          v19 = v34 + 1;
          v20 = v21;
          if ( !v21 )
            goto LABEL_76;
        }
        v23 = 0;
        v24 = 0;
        v25 = 0;
        v26 = -1LL << -(char)__clz(v20 - 1);
        v27 = 0xFFFF - v26;
        do
        {
          v28 = ktime_get(v22);
          v29 = iommu_map_sg(v2, v27 & v26, v42, HIDWORD(v43), 3, 3264);
          if ( v29 != v20 )
          {
            seq_write(a1, "Failed to map_sg\n", 17);
            v34 = v39;
            goto LABEL_70;
          }
          v30 = ktime_get(v29);
          v31 = ktime_get(v30);
          v32 = iommu_unmap(v2, v27 & v26, v20);
          if ( v32 != v20 )
          {
            seq_printf(a1, "Only unmapped %zx instead of %zx\n", v32, v20);
            v34 = v39;
            goto LABEL_70;
          }
          v25 = v30 + v25 - v28;
          v22 = ktime_get(v32);
          ++v23;
          v33 = *(unsigned int *)(v41 + 144);
          v24 = v22 + v24 - v31;
        }
        while ( v23 < v33 );
        if ( v20 >= 0x200000 )
          goto LABEL_51;
LABEL_45:
        v34 = v39;
        if ( v20 < 0x4000 )
        {
          v35 = "4K";
          if ( v20 == 4096 )
            goto LABEL_69;
          if ( v20 == 0x2000 )
          {
            v35 = "8K";
            goto LABEL_69;
          }
        }
        else
        {
          switch ( v20 )
          {
            case 0x4000LL:
              v35 = "16K";
              goto LABEL_69;
            case 0x10000LL:
              v35 = (const char *)&unk_D68A;
              goto LABEL_69;
            case 0x100000LL:
              v35 = (const char *)&unk_D80E;
              goto LABEL_69;
          }
        }
        goto LABEL_74;
      }
    }
  }
LABEL_76:
  mutex_unlock(v41 + 56);
  _ReadStatusReg(SP_EL0);
  return 0;
}
