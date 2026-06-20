__int64 __fastcall get_pages(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned __int64 v4; // x25
  __int64 v5; // x20
  unsigned __int64 v6; // x21
  __int64 v7; // x26
  unsigned __int64 v8; // x22
  __int64 v9; // x0
  unsigned __int64 v10; // x23
  int inserted; // w24
  unsigned __int64 pages; // x0
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x13
  unsigned __int64 v15; // x9
  bool v16; // cf
  unsigned __int64 v17; // x15
  unsigned __int64 v18; // x0
  __int64 aspace_device; // x0
  __int64 v20; // x19
  __int64 v21; // x8
  unsigned __int64 v22; // x20
  unsigned __int64 StatusReg; // x23
  __int64 v24; // x24

  v2 = *(_QWORD *)(a1 + 240);
  result = *(_QWORD *)(a1 + 416);
  if ( !v2 )
  {
    if ( !result )
    {
      v4 = *(_QWORD *)(a1 + 216);
      v5 = *(_QWORD *)(a1 + 8);
      v6 = v4 >> 12;
      if ( *(_QWORD *)(a1 + 536) )
      {
        v7 = *(_QWORD *)(v5 + 56);
        if ( (v6 & 0x80000000) == 0 )
        {
          v8 = 8 * ((v4 >> 12) & 0x7FFFFFFF);
          v9 = _kvmalloc_node_noprof(v8, 0, 3264, 0xFFFFFFFFLL);
          while ( v9 )
          {
            v10 = v9;
            raw_spin_lock(v7 + 5488);
            inserted = drm_mm_insert_node_in_range(v7 + 5248, *(_QWORD *)(a1 + 536), (int)v6, 0, 0, 0, -1, 0);
            raw_spin_unlock(v7 + 5488);
            if ( inserted )
            {
              kvfree(v10);
              pages = inserted;
              goto LABEL_18;
            }
            pages = v10;
            if ( (int)v6 < 1 )
              goto LABEL_18;
            v13 = 0;
            v14 = v8;
            v15 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 56LL) + 5240LL)
                + (*(_QWORD *)(*(_QWORD *)(a1 + 536) + 8LL) << 12);
            while ( v8 >= v13 )
            {
              if ( v14 < 8 )
                break;
              if ( v8 < v13 )
                break;
              v16 = v14 >= 8;
              v14 -= 8LL;
              if ( !v16 )
                break;
              v17 = v15 >> 6;
              v15 += 4096LL;
              *(_QWORD *)(v10 + v13) = (v17 & 0x3FFFFFFFFFFFFC0LL) - ((__int64)memstart_addr >> 12 << 6) - 0x140000000LL;
              v13 += 8LL;
              if ( 8 * ((v4 >> 12) & 0x7FFFFFFF) == v13 )
                goto LABEL_18;
            }
            __break(1u);
            StatusReg = _ReadStatusReg(SP_EL0);
            v24 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &get_pages_vram__alloc_tag;
            if ( (v6 & 0x80000000) != 0 )
            {
              v8 = 0;
              v9 = 0;
            }
            else
            {
              v8 = 8 * ((v4 >> 12) & 0x7FFFFFFF);
              v9 = _kvmalloc_node_noprof(v8, 0, 3264, 0xFFFFFFFFLL);
            }
            *(_QWORD *)(StatusReg + 80) = v24;
          }
        }
        v20 = -12;
        goto LABEL_30;
      }
      pages = drm_gem_get_pages(a1);
LABEL_18:
      if ( pages >= 0xFFFFFFFFFFFFF001LL )
      {
        v20 = pages;
LABEL_30:
        dev_err(*(_QWORD *)(v5 + 8), "[%s:%d] could not get pages: %ld\n", "get_pages", 107, v20);
        return v20;
      }
      *(_QWORD *)(a1 + 416) = pages;
      v18 = drm_prime_pages_to_sg(v5, pages, (unsigned int)v6);
      *(_QWORD *)(a1 + 424) = v18;
      if ( v18 >= 0xFFFFFFFFFFFFF001LL )
      {
        v21 = *(_QWORD *)(v5 + 8);
        v22 = v18;
        dev_err(v21, "[%s:%d] failed to allocate sgt\n", "get_pages", 117);
        *(_QWORD *)(a1 + 424) = 0;
        return v22;
      }
      if ( !*(_QWORD *)(a1 + 536) && (*(_BYTE *)(a1 + 370) & 6) != 0 )
      {
        aspace_device = msm_gem_get_aspace_device(*(_QWORD *)(a1 + 608));
        if ( aspace_device )
        {
          dma_map_sg_attrs(aspace_device, **(_QWORD **)(a1 + 424), *(unsigned int *)(*(_QWORD *)(a1 + 424) + 8LL), 0, 0);
          *(_DWORD *)(a1 + 368) |= 0x40000000u;
        }
        else
        {
          _drm_err("failed to get aspace_device\n");
        }
      }
    }
    return *(_QWORD *)(a1 + 416);
  }
  return result;
}
