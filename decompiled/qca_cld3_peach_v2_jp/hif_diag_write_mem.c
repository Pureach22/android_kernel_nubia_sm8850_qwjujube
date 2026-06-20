__int64 __fastcall hif_diag_write_mem(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 v4; // x23
  __int64 v7; // x20
  unsigned int v8; // w22
  unsigned int v10; // w24
  __int64 v11; // x26
  __int64 v12; // x0
  __int64 v13; // x21
  unsigned int v14; // w27
  __int64 v15; // x8
  int v16; // w9
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x8
  __int64 v20; // x0
  unsigned int v21; // w27
  unsigned int v22; // w26
  __int64 v23; // x8
  int v24; // w0
  int v25; // w26
  unsigned int v26; // w28
  __int64 v27; // x8
  int v28; // w10
  __int64 v29; // x11
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x0
  unsigned int v33; // w27
  unsigned int v34; // w26
  __int64 v35; // x8
  int v36; // w0
  int v37; // w26
  __int64 v38; // x25
  unsigned int v39; // w27
  unsigned int v40; // w0
  int v41; // w28
  int v42; // w28
  int v44; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v45; // [xsp+10h] [xbp-30h] BYREF
  int v46; // [xsp+1Ch] [xbp-24h] BYREF
  int v47; // [xsp+20h] [xbp-20h] BYREF
  int v48; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v49; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v50[2]; // [xsp+30h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 29152);
  v49 = 0;
  v48 = 0;
  v46 = 0;
  v47 = 0;
  v45 = 0;
  v44 = 0;
  if ( !v4 )
  {
    qdf_trace_msg(61, 2, "%s: DIAG CE not present", "hif_diag_write_mem");
    v26 = 4;
    goto LABEL_47;
  }
  v7 = a4;
  v8 = a4;
  v10 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 632) + 232LL);
  v11 = a2;
  v12 = _qdf_mem_alloc_consistent(
          *(_QWORD *)(a1 + 576),
          *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
          a4,
          &v45,
          "hif_diag_write_mem",
          373);
  if ( !v12 )
  {
    v26 = 2;
LABEL_46:
    qdf_trace_msg(61, 2, "%s: Failure (0x%llx)", "hif_diag_write_mem", v11);
    goto LABEL_47;
  }
  v13 = v12;
  qdf_mem_copy(v12, a3, v8);
  qdf_mem_dma_sync_single_for_device(*(_QWORD *)(a1 + 576), v45, v7, 1);
  v14 = *(_DWORD *)(hif_get_target_info_handle(a1) + 4);
  if ( (hif_target_sleep_state_adjust(a1, 0, 1) & 0x80000000) != 0 )
    goto LABEL_43;
  if ( v14 <= 0x11 && ((1 << v14) & 0x28200) != 0 )
  {
    v15 = *(_QWORD *)(a1 + 616);
    v16 = *(unsigned __int8 *)(a1 + 31089);
    v17 = *(_QWORD *)(a1 + 40);
    v50[0] = 0;
    v18 = *(unsigned int *)(v15 + 316);
    v19 = *(_QWORD *)(a1 + 30720);
    v20 = v17 + v18;
    if ( v16 != 1 )
      goto LABEL_13;
    v21 = v20 - v19;
    if ( (unsigned int)(v20 - v19) >> 19 )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v50);
      v22 = (v21 >> 19) & 0x3F | 0x40000000;
      writel(v22, *(_QWORD *)(a1 + 30720) + 12920LL);
      v23 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v21 >> 19) & 0x3F;
      v24 = readl(v23 + 12920);
      if ( v24 != v22 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v22,
          v24,
          12920);
      v25 = readl(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v21 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v50);
    }
    else
    {
LABEL_13:
      v25 = readl(v20);
    }
  }
  else
  {
    v27 = *(_QWORD *)(a1 + 616);
    v28 = *(unsigned __int8 *)(a1 + 31089);
    v29 = *(_QWORD *)(a1 + 40);
    v50[0] = 0;
    v30 = (unsigned int)(*(_DWORD *)(v27 + 276) | *(_DWORD *)(v27 + 272));
    v31 = *(_QWORD *)(a1 + 30720);
    v32 = v29 + v30;
    if ( v28 != 1 )
      goto LABEL_19;
    v33 = v32 - v31;
    if ( (unsigned int)(v32 - v31) >> 19 )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v50);
      v34 = (v33 >> 19) & 0x3F | 0x40000000;
      writel(v34, *(_QWORD *)(a1 + 30720) + 12920LL);
      v35 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v33 >> 19) & 0x3F;
      v36 = readl(v35 + 12920);
      if ( v36 != v34 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v34,
          v36,
          12920);
      v37 = readl(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v33 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v50);
    }
    else
    {
LABEL_19:
      v37 = readl(v32);
    }
    v25 = v37 << 21;
  }
  v11 = a2 & 0xFFFFF | v25 | 0x100000;
  if ( (hif_target_sleep_state_adjust(a1, 1, 0) & 0x80000000) != 0 )
  {
LABEL_43:
    v26 = 16;
  }
  else
  {
    if ( !v8 )
    {
LABEL_42:
      v26 = 0;
      goto LABEL_45;
    }
    v38 = v45;
    while ( 2 )
    {
      if ( v8 >= 0x800 )
        v39 = 2048;
      else
        v39 = v8;
      v40 = ce_recv_buf_enqueue(v4, 0);
      if ( v40 || (v40 = ce_send(v4, 0, v38, v39, v10, 0, 0)) != 0 )
      {
        v26 = v40;
      }
      else
      {
        v41 = 12;
        while ( (unsigned int)ce_completed_send_next(v4, 0, 0, &v49, &v48, &v47, 0, 0, &v44) )
        {
          _const_udelay(4295000);
          if ( !--v41 )
          {
LABEL_44:
            v26 = 8;
            goto LABEL_45;
          }
        }
        v26 = 16;
        if ( v39 == v48 && v49 == v38 )
        {
          v42 = 12;
          while ( (unsigned int)ce_completed_recv_next(v4, 0, 0, &v49, &v48, &v47, &v46) )
          {
            _const_udelay(4295000);
            if ( !--v42 )
              goto LABEL_44;
          }
          v26 = 16;
          if ( v39 == v48 && v49 == v11 )
          {
            v38 += v39;
            v8 -= v39;
            if ( v8 )
              continue;
            goto LABEL_42;
          }
        }
      }
      break;
    }
  }
LABEL_45:
  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 576), *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v7, v13, v45, 0);
  if ( v26 )
    goto LABEL_46;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v26;
}
