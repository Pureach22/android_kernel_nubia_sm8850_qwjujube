__int64 __fastcall hif_diag_read_mem(__int64 a1, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  __int64 v4; // x25
  unsigned int v9; // w27
  unsigned int v10; // w28
  unsigned int v11; // w8
  unsigned __int64 v12; // t2
  unsigned int v13; // w8
  unsigned int v14; // w27
  int v15; // w25
  unsigned int mem; // w0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  unsigned int v20; // w27
  unsigned int v21; // w24
  __int64 v22; // x0
  int v23; // w0
  int v24; // w24
  __int64 v25; // x0
  __int64 v26; // x22
  __int64 v27; // x2
  unsigned int v28; // w9
  int v29; // w8
  unsigned int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x10
  __int64 v33; // x11
  __int64 v34; // x8
  __int64 v35; // x0
  unsigned int v36; // w27
  unsigned int v37; // w22
  __int64 v38; // x8
  int v39; // w0
  int v40; // w22
  __int64 v41; // x8
  __int64 v42; // x11
  __int64 v43; // x9
  __int64 v44; // x8
  __int64 v45; // x0
  unsigned int v46; // w27
  unsigned int v47; // w22
  __int64 v48; // x8
  int v49; // w0
  int v50; // w22
  __int64 v51; // x22
  unsigned int v52; // w0
  int v53; // w27
  int v54; // w22
  unsigned int v56; // [xsp+1Ch] [xbp-64h]
  __int64 v57; // [xsp+20h] [xbp-60h]
  unsigned int v58; // [xsp+2Ch] [xbp-54h]
  __int64 v59; // [xsp+30h] [xbp-50h]
  unsigned int v60; // [xsp+3Ch] [xbp-44h]
  int v61; // [xsp+4Ch] [xbp-34h] BYREF
  __int64 v62; // [xsp+50h] [xbp-30h] BYREF
  int v63; // [xsp+5Ch] [xbp-24h] BYREF
  __int64 v64; // [xsp+60h] [xbp-20h] BYREF
  __int64 v65; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v66[2]; // [xsp+70h] [xbp-10h] BYREF

  v66[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 29152);
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v62 = 0;
  v61 = 0;
  if ( v4 )
  {
    v9 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 632) + 232LL);
    v10 = *(_DWORD *)(hif_get_target_info_handle(a1) + 4);
    HIDWORD(v12) = v10 - 7;
    LODWORD(v12) = v10 - 7;
    v11 = v12 >> 1;
    if ( v11 < 6 && ((0x33u >> v11) & 1) != 0 )
      v13 = 786432;
    else
      v13 = *(_DWORD *)(*(_QWORD *)(a1 + 616) + 268LL);
    if ( v13 > a2 )
    {
      v14 = 4;
      if ( (a2 & 3) == 0 && ((unsigned __int8)a3 & 3) == 0 )
      {
        if ( (int)a4 >= 4 )
        {
          v15 = a4 + 4;
          do
          {
            if ( *(_DWORD *)(*(_QWORD *)(a1 + 616) + 268LL) <= a2 )
            {
              mem = hif_diag_read_mem(a1, a2, a3, 4);
              if ( mem )
              {
                v14 = mem;
                goto LABEL_70;
              }
            }
            else
            {
              if ( (hif_target_sleep_state_adjust(a1, 0, 1) & 0x80000000) != 0 )
                goto LABEL_23;
              v17 = *(_QWORD *)(a1 + 40);
              v66[0] = 0;
              v18 = v17 + a2;
              v19 = *(_QWORD *)(a1 + 30720);
              if ( *(_BYTE *)(a1 + 31089) == 1 && (v20 = v18 - v19, (unsigned int)(v18 - v19) >> 19) )
              {
                pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v66);
                v21 = (v20 >> 19) & 0x3F | 0x40000000;
                writel(v21, *(_QWORD *)(a1 + 30720) + 12920LL);
                v22 = *(_QWORD *)(a1 + 30720) + 12920LL;
                *(_DWORD *)(a1 + 31092) = (v20 >> 19) & 0x3F;
                v23 = readl(v22);
                if ( v23 != v21 )
                  qdf_trace_msg(
                    61,
                    2,
                    "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                    "hif_reg_write_result_check",
                    v21,
                    v23,
                    12920);
                v24 = readl(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v20 & 0x7FFFFLL) + 0x80000);
                pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v66);
              }
              else
              {
                v24 = readl(v18);
              }
              *a3 = v24;
              if ( (hif_target_sleep_state_adjust(a1, 1, 0) & 0x80000000) != 0 )
              {
LABEL_23:
                v14 = 16;
                goto LABEL_70;
              }
            }
            v15 -= 4;
            a2 += 4;
            ++a3;
          }
          while ( v15 > 7 );
        }
        v14 = 0;
      }
    }
    else
    {
      v25 = _qdf_mem_alloc_consistent(
              *(_QWORD *)(a1 + 576),
              *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
              a4,
              &v62,
              "hif_diag_read_mem",
              201);
      v26 = v25;
      if ( v25 )
      {
        qdf_mem_set(v25, a4, 0);
        if ( !a4 )
          goto LABEL_63;
        v27 = v62;
        v28 = a4;
        v59 = v26;
        v58 = v9;
        while ( 2 )
        {
          if ( v28 >= 0x800 )
            v29 = 2048;
          else
            v29 = v28;
          v56 = v28;
          v60 = v29;
          v57 = v27;
          v30 = ce_recv_buf_enqueue(v4, 0);
          if ( v30 )
          {
            v14 = v30;
          }
          else if ( (hif_target_sleep_state_adjust(a1, 0, 1) & 0x80000000) != 0 )
          {
            v14 = 16;
          }
          else
          {
            if ( v10 <= 0x11 && ((1 << v10) & 0x28200) != 0 )
            {
              v31 = *(_QWORD *)(a1 + 616);
              v32 = *(_QWORD *)(a1 + 40);
              v66[0] = 0;
              v33 = *(unsigned int *)(v31 + 316);
              v34 = *(_QWORD *)(a1 + 30720);
              v35 = v32 + v33;
              if ( *(_BYTE *)(a1 + 31089) == 1 && (v36 = v35 - v34, (unsigned int)(v35 - v34) >> 19) )
              {
                pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v66);
                v37 = (v36 >> 19) & 0x3F | 0x40000000;
                writel(v37, *(_QWORD *)(a1 + 30720) + 12920LL);
                v38 = *(_QWORD *)(a1 + 30720);
                *(_DWORD *)(a1 + 31092) = (v36 >> 19) & 0x3F;
                v39 = readl(v38 + 12920);
                if ( v39 != v37 )
                  qdf_trace_msg(
                    61,
                    2,
                    "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                    "hif_reg_write_result_check",
                    v37,
                    v39,
                    12920);
                v40 = readl(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v36 & 0x7FFFFLL) + 0x80000);
                pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v66);
              }
              else
              {
                v40 = readl(v35);
              }
            }
            else
            {
              v41 = *(_QWORD *)(a1 + 616);
              v42 = *(_QWORD *)(a1 + 40);
              v66[0] = 0;
              v43 = (unsigned int)(*(_DWORD *)(v41 + 276) | *(_DWORD *)(v41 + 272));
              v44 = *(_QWORD *)(a1 + 30720);
              v45 = v42 + v43;
              if ( *(_BYTE *)(a1 + 31089) == 1 && (v46 = v45 - v44, (unsigned int)(v45 - v44) >> 19) )
              {
                pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v66);
                v47 = (v46 >> 19) & 0x3F | 0x40000000;
                writel(v47, *(_QWORD *)(a1 + 30720) + 12920LL);
                v48 = *(_QWORD *)(a1 + 30720);
                *(_DWORD *)(a1 + 31092) = (v46 >> 19) & 0x3F;
                v49 = readl(v48 + 12920);
                if ( v49 != v47 )
                  qdf_trace_msg(
                    61,
                    2,
                    "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
                    "hif_reg_write_result_check",
                    v47,
                    v49,
                    12920);
                v50 = readl(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v46 & 0x7FFFFLL) + 0x80000);
                pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v66);
              }
              else
              {
                v50 = readl(v45);
              }
              v40 = v50 << 21;
            }
            if ( (hif_target_sleep_state_adjust(a1, 1, 0) & 0x80000000) != 0 )
            {
              v26 = v59;
              v14 = 16;
            }
            else
            {
              v51 = a2 & 0xFFFFF | v40 | 0x100000;
              v52 = ce_send(v4, 0, v51, v60, v58, 0, 0);
              if ( v52 )
              {
                v26 = v59;
                v14 = v52;
              }
              else
              {
                v53 = 12;
                while ( (unsigned int)ce_completed_send_next(v4, 0, 0, &v65, (char *)&v64 + 4, &v64, 0, 0, &v61) )
                {
                  _const_udelay(4295000);
                  if ( !--v53 )
                  {
LABEL_67:
                    v26 = v59;
                    v14 = 8;
                    goto LABEL_68;
                  }
                }
                v14 = 16;
                if ( v60 == HIDWORD(v64) && v65 == v51 )
                {
                  v54 = 12;
                  while ( (unsigned int)ce_completed_recv_next(v4, 0, 0, &v65, (char *)&v64 + 4, &v64, &v63) )
                  {
                    _const_udelay(4295000);
                    if ( !--v54 )
                      goto LABEL_67;
                  }
                  v14 = 16;
                  v26 = v59;
                  if ( v60 == HIDWORD(v64) && v65 == v57 )
                  {
                    v27 = v57 + v60;
                    v28 = v56 - v60;
                    a2 += v60;
                    if ( v56 != v60 )
                      continue;
LABEL_63:
                    qdf_mem_copy((int)a3, v26, a4);
                    v14 = 0;
                    if ( !v26 )
                      goto LABEL_70;
                    goto LABEL_69;
                  }
                }
                else
                {
                  v26 = v59;
                }
              }
            }
          }
          break;
        }
      }
      else
      {
        v14 = 2;
      }
LABEL_68:
      qdf_trace_msg(61, 2, "%s: Failure (0x%x)", "hif_diag_read_mem", a2);
      if ( v26 )
LABEL_69:
        _qdf_mem_free_consistent(*(_QWORD *)(a1 + 576), *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), a4, v26, v62, 0);
    }
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: DIAG CE not present", "hif_diag_read_mem");
    v14 = 4;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return v14;
}
