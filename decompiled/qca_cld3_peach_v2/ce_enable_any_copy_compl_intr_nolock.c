__int64 __fastcall ce_enable_any_copy_compl_intr_nolock(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x24
  __int64 v4; // x27
  __int64 v5; // x20
  int v6; // w28
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x22
  unsigned int v13; // w21
  unsigned int v14; // w23
  __int64 v15; // x8
  int v16; // w0
  unsigned int v17; // w23
  __int64 v18; // x8
  int v19; // w9
  int v20; // w21
  __int64 v21; // x8
  unsigned int v22; // w27
  unsigned int v23; // w22
  __int64 v24; // x8
  int v25; // w0
  __int64 v26; // x8
  int v27; // w9
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x8
  __int64 v31; // x22
  unsigned int v32; // w20
  unsigned int v33; // w23
  __int64 v34; // x8
  int v35; // w0
  unsigned int v36; // w23
  _DWORD *v37; // x8
  int v38; // w11
  int v39; // w13
  int v40; // w9
  __int64 v41; // x8
  int v42; // w20
  unsigned int v43; // w21
  unsigned int v44; // w22
  __int64 v45; // x8
  int v46; // w0
  _QWORD v47[2]; // [xsp+10h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = hif_target_sleep_state_adjust(a1, 0, 1);
  if ( (result & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(a1 + 656) )
    {
      v3 = 0;
      v4 = a1 + 480;
      do
      {
        if ( v3 == 12 )
          __break(0x5512u);
        v5 = *(_QWORD *)(v4 + 8 * v3);
        v6 = *(_DWORD *)(v5 + 16);
        if ( !*(_DWORD *)(v5 + 128) && (*(_QWORD *)(v5 + 72) || *(_QWORD *)(v5 + 88)) )
        {
          v7 = *(_QWORD *)(a1 + 624);
          v8 = *(unsigned __int8 *)(a1 + 31089);
          v9 = *(_QWORD *)(a1 + 40);
          v47[0] = 0;
          v10 = (unsigned int)(*(_DWORD *)(v7 + 76) + v6);
          v11 = *(_QWORD *)(a1 + 30720);
          v12 = v9 + v10;
          if ( v8 == 1 && (v13 = v12 - v11, (unsigned int)(v12 - v11) >> 19) )
          {
            pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v47);
            v14 = (v13 >> 19) & 0x3F | 0x40000000;
            writel_1(v14, *(_QWORD *)(a1 + 30720) + 12920LL);
            v15 = *(_QWORD *)(a1 + 30720);
            *(_DWORD *)(a1 + 31092) = (v13 >> 19) & 0x3F;
            v16 = readl_1(v15 + 12920);
            if ( v16 != v14 )
              qdf_trace_msg(
                61,
                2,
                "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                "hif_reg_write_result_check",
                v14,
                v16,
                12920);
            v17 = readl_1(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v13 & 0x7FFFFLL) + 0x80000);
            pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v47);
          }
          else
          {
            v17 = readl_1(v9 + v10);
          }
          v18 = *(_QWORD *)(a1 + 624);
          v19 = *(unsigned __int8 *)(a1 + 31089);
          v47[0] = 0;
          v20 = *(_DWORD *)(v18 + 84);
          v21 = *(_QWORD *)(a1 + 30720);
          if ( v19 == 1 && (v22 = v12 - v21, (unsigned int)(v12 - v21) >> 19) )
          {
            pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v47);
            v23 = (v22 >> 19) & 0x3F | 0x40000000;
            writel_1(v23, *(_QWORD *)(a1 + 30720) + 12920LL);
            v24 = *(_QWORD *)(a1 + 30720);
            *(_DWORD *)(a1 + 31092) = (v22 >> 19) & 0x3F;
            v25 = readl_1(v24 + 12920);
            if ( v25 != v23 )
              qdf_trace_msg(
                61,
                2,
                "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                "hif_reg_write_result_check",
                v23,
                v25,
                12920);
            writel_1(v20 | v17, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v22 & 0x7FFFFLL) + 0x80000);
            pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v47);
          }
          else
          {
            writel_1(v20 | v17, v12);
          }
          v4 = a1 + 480;
        }
        if ( *(_QWORD *)(v5 + 112) )
        {
          v26 = *(_QWORD *)(a1 + 624);
          v27 = *(unsigned __int8 *)(a1 + 31089);
          v28 = *(_QWORD *)(a1 + 40);
          v47[0] = 0;
          v29 = (unsigned int)(*(_DWORD *)(v26 + 76) + v6);
          v30 = *(_QWORD *)(a1 + 30720);
          v31 = v28 + v29;
          if ( v27 == 1 && (v32 = v31 - v30, (unsigned int)(v31 - v30) >> 19) )
          {
            pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v47);
            v33 = (v32 >> 19) & 0x3F | 0x40000000;
            writel_1(v33, *(_QWORD *)(a1 + 30720) + 12920LL);
            v34 = *(_QWORD *)(a1 + 30720);
            *(_DWORD *)(a1 + 31092) = (v32 >> 19) & 0x3F;
            v35 = readl_1(v34 + 12920);
            if ( v35 != v33 )
              qdf_trace_msg(
                61,
                2,
                "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                "hif_reg_write_result_check",
                v33,
                v35,
                12920);
            v36 = readl_1(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v32 & 0x7FFFFLL) + 0x80000);
            pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v47);
          }
          else
          {
            v36 = readl_1(v28 + v29);
          }
          v37 = *(_DWORD **)(a1 + 624);
          v38 = *(unsigned __int8 *)(a1 + 31089);
          v47[0] = 0;
          v39 = v37[10];
          v40 = v37[9] | v37[8] | v37[11];
          v41 = *(_QWORD *)(a1 + 30720);
          v42 = v40 | v39;
          if ( v38 == 1 && (v43 = v31 - v41, (unsigned int)(v31 - v41) >> 19) )
          {
            pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v47);
            v44 = (v43 >> 19) & 0x3F | 0x40000000;
            writel_1(v44, *(_QWORD *)(a1 + 30720) + 12920LL);
            v45 = *(_QWORD *)(a1 + 30720);
            *(_DWORD *)(a1 + 31092) = (v43 >> 19) & 0x3F;
            v46 = readl_1(v45 + 12920);
            if ( v46 != v44 )
              qdf_trace_msg(
                61,
                2,
                "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                "hif_reg_write_result_check",
                v44,
                v46,
                12920);
            writel_1(v42 | v36, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v43 & 0x7FFFFLL) + 0x80000);
            pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v47);
          }
          else
          {
            writel_1(v42 | v36, v31);
          }
        }
        ++v3;
      }
      while ( v3 < *(unsigned int *)(a1 + 656) );
    }
    result = hif_target_sleep_state_adjust(a1, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
