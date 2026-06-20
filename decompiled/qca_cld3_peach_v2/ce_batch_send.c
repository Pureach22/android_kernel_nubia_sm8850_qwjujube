__int64 *__fastcall ce_batch_send(__int64 a1, __int64 *a2, int a3, unsigned int a4, int a5)
{
  int v5; // w25
  _QWORD *v7; // x19
  __int64 v8; // x27
  unsigned int v9; // w22
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x23
  int v13; // w28
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned int v17; // w21
  unsigned int v18; // w24
  __int64 v19; // x8
  int v20; // w0
  int v21; // w26
  unsigned int v22; // w24
  __int64 *v23; // x20
  _QWORD *v24; // x23
  int v25; // w8
  __int64 *v26; // x26
  __int64 *v27; // x25
  int v28; // w8
  __int64 *v29; // x21
  __int64 v30; // x10
  unsigned int v31; // w13
  __int64 v32; // x9
  __int64 *result; // x0
  int v34; // [xsp+8h] [xbp-38h]
  int v35; // [xsp+Ch] [xbp-34h]
  __int64 v36; // [xsp+10h] [xbp-30h]
  __int64 *v39; // [xsp+20h] [xbp-20h]
  _QWORD v41[2]; // [xsp+30h] [xbp-10h] BYREF

  v5 = a3;
  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD **)a1;
  v8 = *(_QWORD *)(a1 + 136);
  v9 = *(_DWORD *)(a1 + 16);
  v10 = *(_QWORD *)(*(_QWORD *)a1 + 624LL);
  v11 = *(_QWORD *)(v8 + 40);
  v12 = *(_QWORD *)a1 + 28672LL;
  v13 = *(_DWORD *)(v8 + 4);
  v41[0] = 0;
  v36 = v11;
  v14 = *(_DWORD *)(v10 + 24) + v9;
  v15 = v7[3840];
  v16 = v7[5] + v14;
  if ( *(_BYTE *)(v12 + 2417) == 1 && (v17 = v16 - v15, (unsigned int)(v16 - v15) >> 19) )
  {
    pld_lock_reg_window(v7[3845], v41);
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
    pld_unlock_reg_window(v7[3845], v41);
    v5 = a3;
  }
  else
  {
    v21 = readl_1(v16);
  }
  v22 = *(_DWORD *)(v8 + 12);
  *(_DWORD *)(v8 + 8) = v21;
  if ( a2 )
  {
    v39 = a2;
    v23 = nullptr;
    v24 = nullptr;
    v25 = (v21 + ~v22) & v13;
    v34 = v5 << 20;
    v35 = 0;
    while ( 2 )
    {
      v26 = v39;
      while ( 1 )
      {
        v27 = (__int64 *)*v26;
        if ( v25 > 1 )
          break;
        if ( a5 )
        {
          result = v39;
          goto LABEL_25;
        }
        qdf_trace_msg(61, 2, "%s: Out of descriptors", "ce_batch_send");
        *(_DWORD *)(v8 + 12) = v22;
        war_ce_src_ring_write_idx_set((__int64)v7, v9, v22);
        v28 = *(_DWORD *)(v8 + 8);
        v22 = *(_DWORD *)(v8 + 12);
        v29 = v26;
        if ( v24 )
        {
          v29 = v23;
          *v24 = v26;
        }
        *v26 = 0;
        v23 = v29;
        v24 = v26;
        v26 = v27;
        v25 = (v28 + ~v22) & v13;
        if ( !v27 )
          goto LABEL_23;
      }
      v30 = 10;
      v31 = a4;
      v32 = 8LL * v22;
      if ( (*((_BYTE *)v26 + 68) & 4) == 0 )
        v30 = 5;
      *(_DWORD *)(v36 + 8LL * v22) = v26[v30];
      if ( a4 >= *((_DWORD *)v26 + 28) )
        v31 = *((_DWORD *)v26 + 28);
      *(_DWORD *)(v36 + v32 + 4) = (unsigned __int16)v31 | v35 & 0xC0000 | v34;
      v22 = (v22 + 1) & v13;
      *(_QWORD *)(*(_QWORD *)(v8 + 88) + v32) = v26;
      if ( a5 )
      {
        v29 = v23;
      }
      else
      {
        v29 = v23;
        v35 = (unsigned __int16)v31 | v35 & 0xC0000 | v34;
        a4 = v31;
        *v26 = 0;
        v39 = v27;
        if ( v27 )
          continue;
      }
      break;
    }
  }
  else
  {
    v29 = nullptr;
  }
LABEL_23:
  *(_DWORD *)(v8 + 12) = v22;
  war_ce_src_ring_write_idx_set((__int64)v7, v9, v22);
  result = v29;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
