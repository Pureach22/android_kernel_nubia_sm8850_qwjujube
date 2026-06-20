__int64 __fastcall target_if_get_dbr_data(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int8 a5,
        unsigned int *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x0
  __int64 comp_private_obj; // x0
  __int64 v21; // x24
  unsigned __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x4
  unsigned __int64 v25; // x6
  __int64 v26; // x10
  __int64 v27; // x5
  unsigned int v28; // w4
  __int64 v29; // x22
  unsigned __int64 v30; // x21
  __int64 v31; // x20
  __int64 v32; // x19
  const char *v34; // x2
  unsigned int *v35; // x8

  v14 = *(_QWORD *)(a1 + 80);
  if ( v14 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v14, 8u);
    if ( comp_private_obj )
    {
      v21 = *(_QWORD *)(a2 + 16);
      v23 = *(unsigned int *)(*(_QWORD *)(a3 + 32) + 12LL * a5);
      v22 = *(unsigned int *)(*(_QWORD *)(a3 + 32) + 12LL * a5 + 4);
      v24 = (v22 >> 12) & 0x7FFFF;
      *a6 = v24;
      if ( **(_DWORD **)(a2 + 24) <= (unsigned int)v24 )
      {
        qdf_trace_msg(
          0x5Bu,
          2u,
          "%s: invalid cookie %d",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "target_if_dbr_vaddr_lookup");
      }
      else
      {
        v25 = v23 | ((v22 & 0xF) << 32);
        v26 = *(_QWORD *)(a2 + 32) + 32 * v24;
        if ( *(_QWORD *)(v26 + 8) == v25 )
        {
          v27 = *(_QWORD *)(v26 + 16) + *(unsigned __int8 *)(v26 + 24);
          *(_QWORD *)(a4 + 8) = v27;
          if ( v27 )
          {
            v28 = *a6;
            v29 = comp_private_obj;
            *(_QWORD *)(a4 + 24) = v25;
            *(_DWORD *)(a4 + 16) = v28;
            v30 = v23 | ((v22 & 0xF) << 32);
            qdf_trace_msg(
              0x5Bu,
              8u,
              "%s: Cookie = %d Vaddr look up = %pK",
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              a14,
              "target_if_get_dbr_data");
            *(_QWORD *)a4 = *(unsigned int *)(*(_QWORD *)(a3 + 32) + 12LL * a5 + 8);
            v31 = *(_QWORD *)(v29 + 8);
            v32 = *(int *)(v21 + 4);
            qdf_mem_dp_rx_skb_cnt_dec();
            qdf_mem_dp_rx_skb_dec(v32);
            qdf_mem_skb_total_dec(v32);
            dma_unmap_page_attrs(*(_QWORD *)(v31 + 40), v30, v32, 2, 0);
            return 0;
          }
          goto LABEL_13;
        }
        qdf_trace_msg(
          0x5Bu,
          8u,
          "%s: Invalid paddr, cookie %d, pool paddr %pK, paddr %pK",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "target_if_dbr_vaddr_lookup");
      }
      *(_QWORD *)(a4 + 8) = 0;
LABEL_13:
      v35 = (unsigned int *)(*(_QWORD *)(a3 + 32) + 12LL * a5);
      qdf_trace_msg(
        0x5Bu,
        8u,
        "%s: dbr vaddr lookup failed, cookie %d, hi %x, lo %x",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "target_if_get_dbr_data",
        *a6,
        v35[1],
        *v35);
      return 16;
    }
    v34 = "%s: dir buf rx psoc object is null";
  }
  else
  {
    v34 = "%s: psoc is null";
  }
  qdf_trace_msg(0x5Bu, 2u, v34, a7, a8, a9, a10, a11, a12, a13, a14, "target_if_get_dbr_data");
  return 16;
}
