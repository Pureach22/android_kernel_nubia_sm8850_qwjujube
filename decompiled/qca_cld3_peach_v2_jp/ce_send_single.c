__int64 __fastcall ce_send_single(__int64 a1, __int64 a2, int a3, unsigned __int16 a4)
{
  _QWORD *v7; // x19
  __int64 v8; // x28
  unsigned int v9; // w23
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x25
  int v13; // w20
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned int v17; // w27
  unsigned int v18; // w26
  __int64 v19; // x8
  int v20; // w0
  int v21; // w27
  __int64 v22; // x26
  __int64 v23; // x9
  __int64 v24; // x8
  _DWORD *v25; // x3
  __int64 v26; // x8
  int v27; // w2
  unsigned int v28; // w2
  __int64 result; // x0
  __int64 v30; // [xsp+10h] [xbp-20h]
  _QWORD v32[2]; // [xsp+20h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD **)a1;
  v8 = *(_QWORD *)(a1 + 136);
  v9 = *(_DWORD *)(a1 + 16);
  v10 = *(_QWORD *)(*(_QWORD *)a1 + 624LL);
  v11 = *(_QWORD *)(v8 + 40);
  v12 = *(_QWORD *)a1 + 28672LL;
  v13 = *(_DWORD *)(v8 + 4);
  v32[0] = 0;
  v30 = v11;
  v14 = *(_DWORD *)(v10 + 24) + v9;
  v15 = v7[3840];
  v16 = v7[5] + v14;
  if ( *(_BYTE *)(v12 + 2417) == 1 && (v17 = v16 - v15, (unsigned int)(v16 - v15) >> 19) )
  {
    pld_lock_reg_window(v7[3845], v32);
    v18 = (v17 >> 19) & 0x3F | 0x40000000;
    writel_1(v18, v7[3840] + 12920LL);
    v19 = v7[3840];
    *(_DWORD *)(v12 + 2420) = (v17 >> 19) & 0x3F;
    v20 = readl_1(v19 + 12920);
    if ( v20 != v18 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v18,
        v20,
        12920);
    v21 = readl_1(v7[3840] + (*(_QWORD *)&v17 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(v7[3845], v32);
  }
  else
  {
    v21 = readl_1(v16);
  }
  v22 = *(unsigned int *)(v8 + 12);
  *(_DWORD *)(v8 + 8) = v21;
  if ( ((v21 + ~(_DWORD)v22) & v13) != 0 )
  {
    v23 = 80;
    v24 = 8 * v22;
    if ( (*(_BYTE *)(a2 + 68) & 4) == 0 )
      v23 = 40;
    v25 = (_DWORD *)(v30 + v24);
    *v25 = *(_QWORD *)(a2 + v23);
    v25[1] = a4 | (a3 << 20);
    *(_QWORD *)(*(_QWORD *)(v8 + 88) + 8 * v22) = a2;
    v26 = *(unsigned __int8 *)(v30 + v24 + 6);
    if ( (v26 & 1) != 0 )
    {
      v27 = 2;
    }
    else
    {
      v26 = 3;
      if ( *(_DWORD *)(a1 + 20) == 2 )
        v27 = 3;
      else
        v27 = 4;
    }
    hif_record_ce_desc_event((__int64)v7, *(_DWORD *)(a1 + 8), v27, (__int64)v25, a2, v22, v26);
    v28 = (v22 + 1) & v13;
    *(_DWORD *)(v8 + 12) = v28;
    war_ce_src_ring_write_idx_set((__int64)v7, v9, v28);
    result = 0;
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: ce send fail %d %d %d", "ce_send_single", v13, v22, v21);
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
