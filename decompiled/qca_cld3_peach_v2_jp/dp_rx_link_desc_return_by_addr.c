__int64 __fastcall dp_rx_link_desc_return_by_addr(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v12; // x19
  __int64 v13; // x20
  void (__fastcall *v16)(unsigned int *, unsigned __int64 *); // x10
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x9
  unsigned __int64 StatusReg; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w9
  int v36; // w8
  __int64 v37; // x9
  __int64 v39; // x0
  __int64 v40; // x8
  unsigned __int64 v41; // x13
  __int64 v42; // x10
  __int64 v43; // x8
  __int64 v44; // x1
  __int64 v50; // x9
  unsigned int v51; // w10
  __int64 v52; // x24
  __int64 v53; // x22
  unsigned int v54; // w21
  __int64 v55; // x8
  __int64 v57; // x8
  __int64 v58; // x1
  _DWORD *v59; // x8
  __int64 v60; // x27
  unsigned __int64 v61; // [xsp+8h] [xbp-18h] BYREF
  __int64 v62; // [xsp+10h] [xbp-10h]
  __int64 v63; // [xsp+18h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 **)(a1 + 7720);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x82u,
      2u,
      "%s: %pK: WBM RELEASE RING not initialized",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_rx_link_desc_return_by_addr",
      a1);
    v54 = 16;
    goto LABEL_30;
  }
  v13 = *(_QWORD *)(a1 + 1128);
  v16 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(*(_QWORD *)(v13 + 74392) + 1456LL);
  v61 = *a2 | ((unsigned __int64)*((unsigned __int8 *)a2 + 4) << 32);
  v62 = 0;
  if ( *((_DWORD *)v16 - 1) != -621572614 )
    __break(0x822Au);
  v16(a2, &v61);
  if ( v61 == *(_QWORD *)(a1 + 18832) )
  {
    if ( dp_rx_link_desc_refill_duplicate_check___last_ticks - jiffies + 125 < 0 )
    {
      v60 = jiffies;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: duplicate link desc addr: %llu, cookie: 0x%x",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "dp_rx_link_desc_refill_duplicate_check");
      dp_rx_link_desc_refill_duplicate_check___last_ticks = v60;
    }
    if ( a1 )
      ++*(_DWORD *)(a1 + 14112);
  }
  v25 = v62;
  *(_QWORD *)(a1 + 18832) = v61;
  *(_QWORD *)(a1 + 18840) = v25;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v12 + 80);
  }
  else
  {
    raw_spin_lock_bh(v12 + 80);
    *((_QWORD *)v12 + 11) |= 1uLL;
  }
  v35 = *((_DWORD *)v12 + 29);
  v36 = **((_DWORD **)v12 + 16);
  *((_DWORD *)v12 + 34) = v36;
  if ( v35 )
  {
    if ( (v12[78] & 4) != 0 )
    {
      v37 = *((unsigned int *)v12 + 30);
      if ( (_DWORD)v37 != v36 )
      {
        _X25 = *((_QWORD *)v12 + 2) + 4 * v37;
        if ( _X25 )
        {
          v39 = *(_QWORD *)(*(_QWORD *)(v13 + 8) + 40LL);
          if ( (*(_BYTE *)(v39 + 844) & 0x40) == 0 )
          {
            v40 = _X25 << 8 >> 8;
            v41 = (unsigned __int64)(v40 + 0x8000000000LL) >> 38;
            v42 = memstart_addr + v40 + 0x8000000000LL;
            v43 = v40 - kimage_voffset;
            if ( v41 )
              v44 = v43;
            else
              v44 = v42;
            _dma_sync_single_for_cpu(v39, v44);
          }
          __asm { PRFM            #0, [X25] }
          v36 = *((_DWORD *)v12 + 34);
        }
      }
    }
  }
  v50 = *((unsigned int *)v12 + 30);
  v51 = (unsigned int)(*((_DWORD *)v12 + 11) + v50) % *((_DWORD *)v12 + 9);
  if ( v51 != v36 )
  {
    v57 = *((_QWORD *)v12 + 2);
    *((_DWORD *)v12 + 30) = v51;
    *((_DWORD *)v12 + 31) = v51;
    v58 = v57 + 4 * v50;
    if ( v58 )
    {
      v59 = *(_DWORD **)(*(_QWORD *)(v13 + 74392) + 1448LL);
      if ( v59 )
      {
        if ( *(v59 - 1) != -137706528 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, unsigned int *, _QWORD))v59)(v13, v58, a2, a3);
      }
      v54 = 0;
      if ( (*((_DWORD *)v12 + 19) & 0x80000000) != 0 )
        goto LABEL_37;
LABEL_27:
      hal_delayed_reg_write(v13, v12, *((_QWORD *)v12 + 18), *((unsigned int *)v12 + 30));
      v55 = *((_QWORD *)v12 + 11);
      if ( (v55 & 1) != 0 )
      {
LABEL_38:
        *((_QWORD *)v12 + 11) = v55 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v12 + 80);
        goto LABEL_30;
      }
      goto LABEL_28;
    }
  }
  if ( a1 )
    ++*(_DWORD *)(a1 + 13772);
  v52 = jiffies;
  if ( dp_rx_link_desc_return_by_addr___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: WBM Release Ring (Id %d) Full(Fail CNT %u)",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "dp_rx_link_desc_return_by_addr",
      *v12,
      *(unsigned int *)(a1 + 13772));
    dp_rx_link_desc_return_by_addr___last_ticks = v52;
  }
  v53 = jiffies;
  if ( dp_rx_link_desc_return_by_addr___last_ticks_4 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: HP 0x%x Reap HP 0x%x TP 0x%x Cached TP 0x%x",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "dp_rx_link_desc_return_by_addr",
      **((unsigned int **)v12 + 18),
      *((unsigned int *)v12 + 31),
      **((unsigned int **)v12 + 16),
      *((unsigned int *)v12 + 34));
    dp_rx_link_desc_return_by_addr___last_ticks_4 = v53;
  }
  v54 = 16;
  if ( (*((_DWORD *)v12 + 19) & 0x80000000) == 0 )
    goto LABEL_27;
LABEL_37:
  **((_DWORD **)v12 + 18) = *((_DWORD *)v12 + 30);
  v55 = *((_QWORD *)v12 + 11);
  if ( (v55 & 1) != 0 )
    goto LABEL_38;
LABEL_28:
  raw_spin_unlock(v12 + 80);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v54;
}
