__int64 __fastcall ce_completed_recv_next_nolock_srng(
        _QWORD *a1,
        _QWORD *a2,
        _QWORD *a3,
        __int64 a4,
        unsigned int *a5,
        _DWORD *a6,
        unsigned int *a7)
{
  __int64 v7; // x19
  __int64 v8; // x24
  __int64 v10; // x25
  __int64 v15; // x20
  int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  __int64 *v29; // x14
  __int64 v30; // x16
  __int64 v31; // x15
  __int64 v32; // x25
  unsigned int v33; // w17
  int v34; // w10
  __int64 v35; // x20
  _QWORD *v36; // x19
  unsigned int v37; // w11
  __int64 v38; // x22
  __int64 v39; // x5
  __int64 v40; // x4
  __int64 v41; // x9
  unsigned int v42; // w21
  __int64 v43; // x9
  char v44; // w13
  unsigned int *v45; // x24
  unsigned int v46; // w9
  __int64 v47; // x12
  __int64 v49; // x0
  __int64 v50; // x8
  unsigned __int64 v51; // x13
  __int64 v52; // x9
  __int64 v53; // x8
  __int64 v54; // x26
  unsigned int v55; // w28
  __int64 v56; // x1
  unsigned int v62; // w23
  __int64 v63; // x22
  __int64 v64; // x8
  __int64 v65; // [xsp+0h] [xbp-30h]
  __int64 *v66; // [xsp+8h] [xbp-28h]
  __int64 v67; // [xsp+10h] [xbp-20h]
  __int64 v68; // [xsp+18h] [xbp-18h]

  v8 = a1[18];
  v7 = a1[19];
  v10 = *a1;
  v16 = *(_DWORD *)(v8 + 4);
  v15 = *(unsigned int *)(v8 + 8);
  if ( (unsigned int)hal_srng_access_start_1(*(_QWORD *)(*a1 + 2560LL)) )
    return 16;
  v26 = *(_QWORD *)(v7 + 80);
  v67 = v8;
  v68 = v15;
  v27 = *(unsigned int *)(v26 + 120);
  if ( (_DWORD)v27 == *(_DWORD *)(v26 + 136)
    || (v28 = *(_QWORD *)(v26 + 16), (v29 = (__int64 *)(v28 + 4 * v27)) == nullptr) )
  {
    v43 = *(_QWORD *)(v26 + 88);
    if ( (v43 & 1) != 0 )
    {
      *(_QWORD *)(v26 + 88) = v43 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v26 + 80);
    }
    else
    {
      raw_spin_unlock(v26 + 80);
    }
    return 16;
  }
  else
  {
    v30 = *v29;
    v31 = v10;
    v32 = v7;
    v66 = (__int64 *)(v28 + 4 * v27);
    v33 = WORD1(*v29);
    if ( WORD1(*v29) )
    {
      v35 = v31;
      v44 = *(_BYTE *)(v26 + 78);
      v45 = a5;
      v46 = *(_DWORD *)(v26 + 44) + v27;
      v36 = a1;
      v47 = *(_QWORD *)(v31 + 2560);
      if ( v46 == *(_DWORD *)(v26 + 36) )
        v46 = 0;
      *(_DWORD *)(v26 + 120) = v46;
      if ( (v44 & 4) != 0 )
      {
        _X9 = v28 + 4LL * v46;
        v49 = *(_QWORD *)(*(_QWORD *)(v47 + 8) + 40LL);
        if ( (*(_BYTE *)(v49 + 844) & 0x40) == 0 )
        {
          v50 = _X9 << 8 >> 8;
          v65 = _X9;
          v51 = (unsigned __int64)(v50 + 0x8000000000LL) >> 38;
          v52 = memstart_addr + v50 + 0x8000000000LL;
          v53 = v50 - kimage_voffset;
          v54 = v30;
          v55 = WORD1(v30);
          if ( v51 )
            v56 = v53;
          else
            v56 = v52;
          _dma_sync_single_for_cpu(v49, v56);
          _X9 = v65;
          v29 = v66;
          v33 = v55;
          v30 = v54;
        }
        __asm { PRFM            #0, [X9] }
      }
      *v29 &= 0xFFFFFFFF0000FFFFLL;
      *v45 = v33;
      *a6 = WORD2(v30);
      *a7 = ((unsigned int)v30 >> 9) & 1;
      if ( a2 )
        *a2 = v36[12];
      if ( a3 )
        *a3 = *(_QWORD *)(*(_QWORD *)(v67 + 88) + 8 * v68);
      v62 = (v68 + 1) & v16;
      *(_QWORD *)(*(_QWORD *)(v67 + 88) + 8 * v68) = 0;
      *(_DWORD *)(v67 + 8) = v62;
      v63 = *(_QWORD *)(v32 + 80);
      if ( v63 )
      {
        if ( (*(_DWORD *)(v63 + 76) & 0x80000000) != 0 )
          **(_DWORD **)(v63 + 144) = *(_DWORD *)(v63 + 120);
        else
          hal_delayed_reg_write(
            *(_QWORD *)(v35 + 2560),
            *(unsigned __int8 **)(v32 + 80),
            *(_QWORD *)(v63 + 144),
            *(_DWORD *)(v63 + 120));
        v64 = *(_QWORD *)(v63 + 88);
        if ( (v64 & 1) != 0 )
        {
          *(_QWORD *)(v63 + 88) = v64 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v63 + 80);
        }
        else
        {
          raw_spin_unlock(v63 + 80);
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Error: Invalid hal_ring\n",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "hal_srng_access_end");
      }
      ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD))hif_record_ce_srng_desc_event)(
        v35,
        *((unsigned int *)v36 + 2),
        37,
        0,
        *(_QWORD *)(*(_QWORD *)(v67 + 88) + 8LL * v62),
        *(unsigned int *)(v67 + 8));
      v42 = 0;
    }
    else
    {
      v34 = *(_DWORD *)(v26 + 116);
      v35 = v31;
      v36 = a1;
      v37 = **(_DWORD **)(v26 + 128);
      v38 = jiffies;
      if ( ce_completed_recv_next_nolock_srng___last_ticks - jiffies + 125 < 0 )
      {
        if ( v34 )
          v39 = (unsigned int)v27;
        else
          v39 = v37;
        if ( v34 )
          v40 = v37;
        else
          v40 = (unsigned int)v27;
        qdf_trace_msg(
          0x3Du,
          4u,
          "%s: No data to reap, hp %d tp %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "ce_completed_recv_next_nolock_srng",
          v40,
          v39);
        v26 = *(_QWORD *)(v32 + 80);
        ce_completed_recv_next_nolock_srng___last_ticks = v38;
      }
      v41 = *(_QWORD *)(v26 + 88);
      if ( (v41 & 1) != 0 )
      {
        *(_QWORD *)(v26 + 88) = v41 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v26 + 80);
      }
      else
      {
        raw_spin_unlock(v26 + 80);
      }
      v42 = 16;
    }
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64 *, _QWORD, __int64))hif_record_ce_srng_desc_event)(
      v35,
      *((unsigned int *)v36 + 2),
      38,
      v66,
      0,
      0xFFFFFFFFLL);
    return v42;
  }
}
