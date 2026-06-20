__int64 __fastcall dp_reo_desc_free(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w8
  unsigned __int64 v14; // x5
  unsigned __int64 v15; // x21
  __int64 v16; // x0
  _QWORD *v17; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x11
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x22
  __int64 v26; // x25
  __int64 v27; // x21
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x10
  unsigned int v31; // w11
  __int64 v32; // x14
  unsigned __int64 v33; // t2
  __int64 v34; // x9
  unsigned __int64 *v35; // x9
  __int64 v36; // t1

  v13 = *(_DWORD *)(a3 + 4);
  v14 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
  if ( v13 && v13 != 255 )
  {
    v15 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: Rx tid HW desc flush failed(%d): tid %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_reo_desc_free",
      a1,
      v13,
      *(unsigned int *)(a2 + 24));
    v14 = v15;
  }
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: %pK: %lu hw_qdesc_paddr: %pK, tid:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_reo_desc_free",
    a1,
    v14,
    *(_QWORD *)(a2 + 80),
    *(unsigned int *)(a2 + 24));
  if ( *(_DWORD *)(a1 + 56) )
  {
    v16 = _qdf_mem_malloc(0x30u, "dp_reo_desc_defer_free_enqueue", 434);
    if ( v16 )
    {
      v17 = (_QWORD *)v16;
      *(_QWORD *)(v16 + 32) = *(_QWORD *)(a2 + 80);
      *(_DWORD *)(v16 + 40) = *(_DWORD *)(a2 + 88);
      *(_QWORD *)(v16 + 24) = *(_QWORD *)(a2 + 56);
      *(_QWORD *)(v16 + 16) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 19984);
      }
      else
      {
        raw_spin_lock_bh(a1 + 19984);
        *(_QWORD *)(a1 + 19992) |= 1uLL;
      }
      if ( (*(_BYTE *)(a1 + 20000) & 1) != 0 )
      {
        qdf_list_insert_back((_QWORD *)(a1 + 19960), v17);
        v19 = *(_QWORD *)(a1 + 19992);
        if ( (v19 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 19992) = v19 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 19984);
        }
        else
        {
          raw_spin_unlock(a1 + 19984);
        }
        return _qdf_mem_free(a2);
      }
      _qdf_mem_free((__int64)v17);
      v20 = *(_QWORD *)(a1 + 19992);
      if ( (v20 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 19992) = v20 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 19984);
      }
      else
      {
        raw_spin_unlock(a1 + 19984);
      }
    }
  }
  v21 = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 132LL);
  if ( (_DWORD)v21 )
  {
    v22 = 56LL * *(unsigned int *)(a1 + 20168);
    *(_QWORD *)(*(_QWORD *)(a1 + 20152) + v22) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    *(_QWORD *)(*(_QWORD *)(a1 + 20152) + v22 + 8) = *(_QWORD *)(a2 + 80);
    *(_QWORD *)(*(_QWORD *)(a1 + 20152) + v22 + 16) = *(_QWORD *)(a2 + 64);
    *(_QWORD *)(*(_QWORD *)(a1 + 20152) + v22 + 24) = *(_QWORD *)(a2 + 56);
    v23 = *(_QWORD *)(a1 + 20168);
    if ( v23 + 1 == v21 )
      v24 = 0;
    else
      v24 = v23 + 1;
    *(_QWORD *)(a1 + 20168) = v24;
  }
  v25 = *(int *)(a2 + 88);
  v26 = *(_QWORD *)(a1 + 24);
  v27 = *(_QWORD *)(a2 + 80);
  qdf_mem_skb_total_dec(v25);
  dma_unmap_page_attrs(*(_QWORD *)(v26 + 40), v27, v25, 0, 0);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 40) + 132LL) )
  {
    v28 = *(_QWORD *)(a1 + 20168);
    if ( v28 )
    {
      v29 = 0;
      v30 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
      v31 = 1;
      do
      {
        v32 = *(_QWORD *)(a1 + 20152);
        HIDWORD(v33) = **(_DWORD **)(v32 + 56 * v29 + 24) + 1379995772;
        LODWORD(v33) = HIDWORD(v33);
        if ( (unsigned int)(v33 >> 28) <= 3 )
        {
          v34 = v32 + 56 * v29;
          v36 = *(_QWORD *)(v34 + 48);
          v35 = (unsigned __int64 *)(v34 + 48);
          if ( !v36 )
          {
            *v35 = v30;
            v28 = *(_QWORD *)(a1 + 20168);
          }
        }
        v29 = v31++;
      }
      while ( v28 > v29 );
    }
  }
  **(_DWORD **)(a2 + 56) = 0;
  _qdf_mem_free(*(_QWORD *)(a2 + 56));
  return _qdf_mem_free(a2);
}
