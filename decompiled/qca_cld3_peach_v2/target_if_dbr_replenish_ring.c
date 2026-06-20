__int64 __fastcall target_if_dbr_replenish_ring(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 v15; // x22
  __int64 v16; // x24
  __int64 *comp_private_obj; // x0
  __int64 v19; // x20
  __int64 v20; // x21
  __int64 v21; // x23
  const char **v22; // x22
  char v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v33; // x2
  const char *v34; // x2
  const char *v35; // x3
  unsigned int v36; // w0
  const char *v37; // x0
  const char *v38; // x2
  __int64 v39; // x0
  __int64 v40; // x22
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int64 StatusReg; // x8
  int v50; // w9
  int v51; // w8
  __int64 v52; // x9
  __int64 v54; // x0
  __int64 v55; // x8
  unsigned __int64 v56; // x13
  __int64 v57; // x10
  __int64 v58; // x8
  __int64 v59; // x1
  __int64 v65; // x8
  unsigned int v66; // w9
  __int64 v67; // x10
  _DWORD *v68; // x8
  __int64 v69; // x8
  char v70; // [xsp+1Ch] [xbp+1Ch]

  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v33 = "%s: psoc is null";
LABEL_12:
    qdf_trace_msg(0x5Bu, 2u, v33, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_dbr_replenish_ring");
    return 16;
  }
  v13 = a2[3];
  if ( *(_DWORD *)v13 <= a4 )
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: invalid cookie %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_dbr_replenish_ring",
      a4);
    return 4;
  }
  v15 = a2[2];
  v16 = a2[4];
  comp_private_obj = (__int64 *)wlan_objmgr_psoc_get_comp_private_obj(v12, 8u);
  if ( !comp_private_obj )
  {
    v33 = "%s: dir buf rx psoc object is null";
    goto LABEL_12;
  }
  if ( a3 )
  {
    v19 = *(_QWORD *)(v13 + 56);
    v20 = *comp_private_obj;
    v21 = *(int *)(v15 + 4);
    v22 = *(const char ***)(comp_private_obj[1] + 40);
    v23 = is_vmalloc_addr(a3);
    if ( (v23 & 1) != 0 && (dma_map_single_attrs___already_done_3 & 1) == 0 )
    {
      v70 = v23;
      dma_map_single_attrs___already_done_3 = 1;
      v37 = (const char *)dev_driver_string(v22);
      v38 = v22[14];
      if ( !v38 )
        v38 = *v22;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v37, v38);
      __break(0x800u);
      if ( (v70 & 1) != 0 )
        goto LABEL_8;
    }
    else if ( (v23 & 1) != 0 )
    {
LABEL_8:
      qdf_trace_msg(
        0x5Bu,
        2u,
        "%s: mem map failed status = %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "target_if_dbr_replenish_ring",
        16);
      return 16;
    }
    v39 = dma_map_page_attrs(
            v22,
            ((unsigned __int64)((a3 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            a3 & 0xFFF,
            v21,
            2,
            0);
    if ( v39 == -1 )
      goto LABEL_8;
    v40 = v39;
    qdf_mem_dp_rx_skb_cnt_inc();
    qdf_mem_dp_rx_skb_inc(v21);
    qdf_mem_skb_total_inc(v21);
    *(_QWORD *)(v16 + 32LL * a4 + 8) = v40;
    if ( v19 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v19 + 80);
      }
      else
      {
        raw_spin_lock_bh(v19 + 80);
        *(_QWORD *)(v19 + 88) |= 1uLL;
      }
      v50 = *(_DWORD *)(v19 + 116);
      v51 = **(_DWORD **)(v19 + 128);
      *(_DWORD *)(v19 + 136) = v51;
      if ( v50 )
      {
        if ( (*(_BYTE *)(v19 + 78) & 4) != 0 )
        {
          v52 = *(unsigned int *)(v19 + 120);
          if ( (_DWORD)v52 != v51 )
          {
            _X23 = *(_QWORD *)(v19 + 16) + 4 * v52;
            if ( _X23 )
            {
              v54 = *(_QWORD *)(*(_QWORD *)(v20 + 8) + 40LL);
              if ( (*(_BYTE *)(v54 + 844) & 0x40) == 0 )
              {
                v55 = _X23 << 8 >> 8;
                v56 = (unsigned __int64)(v55 + 0x8000000000LL) >> 38;
                v57 = memstart_addr + v55 + 0x8000000000LL;
                v58 = v55 - kimage_voffset;
                if ( v56 )
                  v59 = v58;
                else
                  v59 = v57;
                _dma_sync_single_for_cpu(v54, v59);
              }
              __asm { PRFM            #0, [X23] }
            }
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Error: Invalid hal_ring\n",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hal_le_srng_access_start_in_cpu_order");
    }
    v65 = *(unsigned int *)(v19 + 120);
    v66 = (unsigned int)(*(_DWORD *)(v19 + 44) + v65) % *(_DWORD *)(v19 + 36);
    if ( v66 == *(_DWORD *)(v19 + 136)
      || (v67 = *(_QWORD *)(v19 + 16),
          *(_DWORD *)(v19 + 120) = v66,
          *(_DWORD *)(v19 + 124) = v66,
          (v68 = (_DWORD *)(v67 + 4 * v65)) == nullptr) )
    {
      v68 = nullptr;
    }
    *v68 = v40;
    v68[1] = BYTE4(v40) & 0xF | ((a4 & 0x7FFFF) << 12);
    if ( v19 )
    {
      if ( (*(_DWORD *)(v19 + 76) & 0x80000000) != 0 )
        **(_DWORD **)(v19 + 144) = *(_DWORD *)(v19 + 120);
      else
        hal_delayed_reg_write(v20, (unsigned __int8 *)v19, *(_QWORD *)(v19 + 144), *(_DWORD *)(v19 + 120));
      v69 = *(_QWORD *)(v19 + 88);
      if ( (v69 & 1) != 0 )
      {
        *(_QWORD *)(v19 + 88) = v69 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v19 + 80);
      }
      else
      {
        raw_spin_unlock(v19 + 80);
      }
      return 0;
    }
    v34 = "%s: Error: Invalid hal_ring\n";
    v35 = "hal_srng_access_end";
    v36 = 56;
  }
  else
  {
    v34 = "%s: aligned vaddr is null";
    v35 = "target_if_dbr_replenish_ring";
    v36 = 91;
  }
  qdf_trace_msg(v36, 2u, v34, a5, a6, a7, a8, a9, a10, a11, a12, v35);
  return 0;
}
