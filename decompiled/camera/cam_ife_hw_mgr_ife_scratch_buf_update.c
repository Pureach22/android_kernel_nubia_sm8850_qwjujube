__int64 __fastcall cam_ife_hw_mgr_ife_scratch_buf_update(
        int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        _DWORD *a6)
{
  int v6; // w7
  int v7; // w6
  __int64 result; // x0
  _QWORD *v9; // x25
  int v10; // w6
  unsigned int v11; // w7
  unsigned __int64 v12; // x27
  int v13; // w19
  unsigned int *v14; // x8
  unsigned int v15; // w9
  signed int v16; // w28
  int v17; // w20
  _DWORD *v18; // x9
  __int64 v19; // x6
  __int64 v20; // x8
  __int64 v21; // x26
  __int64 v22; // x8
  unsigned int v23; // w10
  int v24; // w23
  int v25; // w0
  __int64 v26; // x3
  __int64 v27; // x9
  __int64 v28; // x21
  _QWORD *v29; // x19
  __int64 v30; // x25
  __int64 v31; // x8
  __int64 *v32; // x26
  __int64 v33; // t1
  unsigned int v34; // w9
  int v35; // w23
  int v36; // w0
  __int64 v37; // x22
  __int64 v38; // x21
  __int64 v39; // x9
  __int64 v40; // x24
  _QWORD *v41; // x19
  int v42; // w25
  unsigned int v43; // w19
  __int64 v44; // x20
  _DWORD *v45; // x21
  __int64 v46; // [xsp+10h] [xbp-30h]
  int v47; // [xsp+18h] [xbp-28h]
  int v48; // [xsp+1Ch] [xbp-24h]
  __int64 v49; // [xsp+20h] [xbp-20h]
  __int64 v50; // [xsp+28h] [xbp-18h]
  int v51; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+38h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a6[3];
  v7 = ~(-1 << *a6);
  if ( v6 != v7 )
  {
    if ( a1 == 1 )
    {
      result = 0;
      *(_DWORD *)(*(_QWORD *)(a5 + 9368) + 4LL) = v6;
      goto LABEL_40;
    }
    if ( a1 != 2 )
    {
LABEL_39:
      result = 0;
      goto LABEL_40;
    }
    v9 = &unk_393000;
    v50 = a5;
    v49 = a4;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v43 = a2;
      v44 = a3;
      v45 = a6;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_ife_scratch_buf_update",
        15365,
        "Adding IFE scratch buffer cfg_mask expected: 0x%x actual: 0x%x ctx_idx: %u",
        v7,
        v6,
        *(_DWORD *)(a5 + 56));
      a4 = v49;
      a5 = v50;
      a2 = v43;
      a6 = v45;
      a3 = v44;
      if ( v43 < 0xB )
        goto LABEL_9;
    }
    else if ( a2 < 0xB )
    {
LABEL_9:
      v10 = *(_DWORD *)(a4 + 40);
      v11 = *(_DWORD *)(a4 + 24);
      v12 = (unsigned int)a6[3];
      v51 = 0;
      v13 = *(_DWORD *)(a5 + 12LL * a2 + 8584);
      if ( v10 + 1 >= v11 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_ife_add_scratch_buffer_cfg",
          14770,
          "Insufficient  HW entries :%d %d, ctx_idx: %u",
          v10,
          v11,
          *(_DWORD *)(a5 + 56));
        result = 4294967274LL;
        goto LABEL_40;
      }
      v14 = *(unsigned int **)(a5 + 9368);
      v15 = *v14;
      if ( *v14 )
      {
        v16 = 0;
        v17 = 0;
        v48 = *(_DWORD *)(a5 + 12LL * a2 + 8584);
        do
        {
          if ( ((v12 >> v16) & 1) == 0 )
          {
            if ( (unsigned int)v16 >= 2 )
              goto LABEL_44;
            v18 = v14 + 2;
            v19 = LOBYTE(v14[10 * v16 + 8]);
            v20 = *(unsigned __int8 *)(*(_QWORD *)(a5 + 8496) + v19);
            if ( v20 == 255 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_ife_add_scratch_buffer_cfg",
                14788,
                "Invalid index:%d for out_map",
                v19);
              result = 4294967274LL;
              goto LABEL_40;
            }
            v21 = *(_QWORD *)(a5 + 272) + (v20 << 7);
            v22 = *(_QWORD *)(v21 + 32);
            if ( v22 && *(_DWORD *)(*(_QWORD *)(v22 + 16) + 4LL) == v13 )
            {
              v23 = *(_DWORD *)(a3 + 20);
              v24 = *(_DWORD *)(a3 + 24);
              v25 = v23 - (v24 + v17);
              if ( v23 <= v24 + v17 )
                goto LABEL_42;
              v26 = (__int64)&v18[10 * v16];
              v27 = v9[458];
              v28 = *(_QWORD *)(a3 + 8);
              v29 = v9;
              if ( (v27 & 8) != 0 && !debug_priority )
              {
                v30 = a3;
                v47 = v23 - (v24 + v17);
                v46 = v26;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v27 & 8,
                  4,
                  "cam_isp_ife_add_scratch_buffer_cfg",
                  14817,
                  "WM res_id: 0x%x io_addr: %pK, ctx_idx: %u",
                  *(_DWORD *)(v22 + 4),
                  *(const void **)(v26 + 16),
                  *(_DWORD *)(a5 + 56));
                v26 = v46;
                v25 = v47;
                v22 = *(_QWORD *)(v21 + 32);
              }
              else
              {
                v30 = a3;
              }
              result = cam_isp_sfe_send_scratch_buf_upd(
                         v25,
                         1,
                         v22,
                         v26,
                         v28 + (v17 & 0xFFFFFFFC) + (v24 & 0xFFFFFFFC),
                         &v51);
              if ( (_DWORD)result )
                goto LABEL_40;
              a5 = v50;
              a3 = v30;
              a4 = v49;
              v9 = v29;
              v13 = v48;
              v17 += v51;
            }
            v33 = *(_QWORD *)(v21 + 40);
            v32 = (__int64 *)(v21 + 40);
            v31 = v33;
            if ( v33 && *(_DWORD *)(*(_QWORD *)(v31 + 16) + 4LL) == v13 )
            {
              v34 = *(_DWORD *)(a3 + 20);
              v35 = *(_DWORD *)(a3 + 24);
              v36 = v34 - (v35 + v17);
              if ( v34 <= v35 + v17 )
              {
LABEL_42:
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_isp_ife_add_scratch_buffer_cfg",
                  14808,
                  "no free kmd memory for base %u, ctx_idx: %u",
                  v13,
                  *(_DWORD *)(a5 + 56));
                result = 4294967284LL;
                goto LABEL_40;
              }
              v37 = *(_QWORD *)(a5 + 9368) + 40LL * v16;
              v38 = *(_QWORD *)(a3 + 8);
              v39 = v9[458];
              if ( (v39 & 8) != 0 && !debug_priority )
              {
                v40 = a3;
                v41 = v9;
                v42 = v36;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v39 & 8,
                  4,
                  "cam_isp_ife_add_scratch_buffer_cfg",
                  14817,
                  "WM res_id: 0x%x io_addr: %pK, ctx_idx: %u",
                  *(_DWORD *)(v31 + 4),
                  *(const void **)(v37 + 24),
                  *(_DWORD *)(a5 + 56));
                v36 = v42;
                v9 = v41;
                v13 = v48;
                v31 = *v32;
              }
              else
              {
                v40 = a3;
              }
              result = cam_isp_sfe_send_scratch_buf_upd(
                         v36,
                         1,
                         v31,
                         v37 + 8,
                         v38 + (v17 & 0xFFFFFFFC) + (v35 & 0xFFFFFFFC),
                         &v51);
              if ( (_DWORD)result )
                goto LABEL_40;
              a5 = v50;
              a3 = v40;
              a4 = v49;
              v17 += v51;
            }
            v14 = *(unsigned int **)(a5 + 9368);
            v15 = *v14;
          }
          ++v16;
        }
        while ( v16 < v15 );
        if ( v17 )
          cam_isp_update_hw_entry(3, a4, a3, v17, 0);
      }
      goto LABEL_39;
    }
LABEL_44:
    __break(0x5512u);
  }
  if ( a1 != 1 )
    goto LABEL_39;
  result = 0;
  *(_BYTE *)(*(_QWORD *)(a5 + 9368) + 88LL) = 1;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
