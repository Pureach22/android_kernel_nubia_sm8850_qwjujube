__int64 __fastcall parse_config(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x0
  __int64 v6; // x9
  int v7; // w10
  int v8; // w11
  unsigned int v9; // w12
  __int64 (__fastcall *v10)(); // x13
  __int64 (__fastcall *v11)(); // x14
  char v12; // w15
  __int64 v13; // x16
  unsigned int v14; // w22
  unsigned __int64 v15; // x8
  __int64 v16; // x17
  int v17; // w0
  int v18; // w17
  int v19; // w17
  int v20; // w1
  int v21; // w2
  int v22; // w16
  __int64 (__fastcall *v23)(); // x16
  _QWORD *v24; // x0
  _QWORD *v25; // x1
  unsigned __int64 v26; // x23
  unsigned __int64 v27; // x22
  __int64 v28; // x0
  int v29; // w8
  __int64 v30; // x9
  unsigned __int64 v31; // x14
  __int64 v32; // x16
  __int64 v33; // x3
  unsigned int v34; // w4
  int v35; // w4
  __int64 (__fastcall *v36)(); // x5
  int v37; // w4
  __int64 (__fastcall *v38)(); // x4
  int v39; // w4
  char v40; // w3
  __int64 v41; // x4
  int v42; // w8
  __int64 v43; // x8
  __int64 result; // x0
  __int64 v45; // x8
  int v46; // w8
  unsigned int v47; // w20
  __int64 v48; // x20
  __int64 v49; // x20
  __int64 v50; // x20
  __int64 v51; // x20
  __int64 v52; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v54; // x23
  __int64 v55; // x0

  v2 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 208) = *(_DWORD *)a2;
  v5 = vcalloc_noprof(*(unsigned int *)(a1 + 208), 400);
  *(_QWORD *)(a1 + 176) = v5;
  if ( !v5 )
    return 4294967284LL;
  while ( 1 )
  {
    v6 = a1 + 184;
    *(_QWORD *)(a1 + 184) = a1 + 184;
    *(_QWORD *)(a1 + 192) = a1 + 184;
    if ( *(_DWORD *)(a2 + 16) )
      break;
LABEL_29:
    v26 = *(int *)(a2 + 32);
    v2 = *(_QWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 212) = v26;
    if ( !is_mul_ok(v26, 0x108u) )
    {
      *(_QWORD *)(a1 + 248) = 0;
      v47 = -12;
      goto LABEL_151;
    }
    v27 = 264 * v26;
    v28 = _kmalloc_noprof(264 * v26, 3520);
    *(_QWORD *)(a1 + 248) = v28;
    if ( !v28 )
    {
      v47 = -12;
LABEL_151:
      vfree(*(_QWORD *)(a1 + 176));
      return v47;
    }
    if ( (int)v26 < 1 )
    {
LABEL_122:
      v42 = *(_DWORD *)(a2 + 4);
      if ( !v42 )
        v42 = 1000;
      *(_DWORD *)(a1 + 328) = v42;
      v43 = *(unsigned int *)(a2 + 52);
      if ( (_DWORD)v43 )
        *(_QWORD *)(a1 + 48) = *(_QWORD *)(a1 + 32) + v43;
      result = 0;
      *(_DWORD *)(a1 + 332) = *(_DWORD *)(a2 + 8);
      *(_BYTE *)(a1 + 613) = *(_BYTE *)(a2 + 48);
      LODWORD(v45) = *(_DWORD *)(a2 + 12);
      if ( (_DWORD)v45 )
        v45 = (unsigned int)v45;
      else
        v45 = 0xFFFF;
      *(_QWORD *)(a1 + 600) = v45;
      *(_DWORD *)(a1 + 340) = 12;
      if ( *(_BYTE *)(a2 + 49) )
        v46 = 4;
      else
        v46 = 12;
      *(_DWORD *)(a1 + 340) = v46;
      return result;
    }
    v29 = 0;
    v30 = 0;
    v31 = v27 - 248;
    v32 = 30;
    while ( v27 >= v30 + 16 )
    {
      if ( v31 + 232 < 4 )
        break;
      if ( v30 + 16 < 0 )
        break;
      if ( v27 < v30 + 16 )
        break;
      if ( v31 + 232 < 4 )
        break;
      v33 = *(_QWORD *)(a2 + 40);
      *(_DWORD *)(v28 + v30 + 16) = v29;
      if ( v27 < v30 + 112 )
        break;
      if ( v31 + 136 < 8 )
        break;
      if ( v30 + 112 < 0 )
        break;
      if ( v27 < v30 + 112 )
        break;
      if ( v31 + 136 < 8 )
        break;
      *(_QWORD *)(v28 + v30 + 112) = *(unsigned int *)(v33 + v32 - 30);
      if ( v31 + 228 < 4 )
        break;
      if ( v30 + 20 < 0 )
        break;
      if ( v27 < v30 + 20 )
        break;
      if ( v31 + 228 < 4 )
        break;
      *(_DWORD *)(v28 + v30 + 20) = *(_DWORD *)(v33 + v32 - 26);
      if ( v31 + 224 < 4 || v30 + 24 < 0 || v27 < v30 + 24 || v31 + 224 < 4 )
        break;
      *(_DWORD *)(v28 + v30 + 24) = *(_DWORD *)(v33 + v32 - 22);
      v34 = *(_DWORD *)(v33 + v32 - 18);
      if ( v34 != -1 )
      {
        if ( v31 + 220 < 4 || v30 + 28 < 0 || v27 < v30 + 28 || v31 + 220 < 4 )
          break;
        *(_DWORD *)(v28 + v30 + 28) = v34;
        if ( v34 >= *(_DWORD *)(a1 + 208) )
        {
          v51 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          dev_err(v2, "[E][%s] Event Ring channel not available\n", "parse_ev_cfg");
          if ( v51 && *(_DWORD *)(v51 + 24) < 3u )
            ipc_log_string(*(_QWORD *)(v51 + 32), "[E][%s] Event Ring channel not available\n", "parse_ev_cfg");
          goto LABEL_150;
        }
        if ( v31 + 240 < 8 || v30 + 8 < 0 || v27 < v30 + 8 || v31 + 240 < 8 )
          break;
        *(_QWORD *)(v28 + v30 + 8) = *(_QWORD *)(a1 + 176) + 400LL * (int)v34;
      }
      if ( v27 < v30 + 32 )
        break;
      if ( v31 + 216 < 4 )
        break;
      if ( v30 + 32 < 0 )
        break;
      if ( v27 < v30 + 32 )
        break;
      if ( v31 + 216 < 4 )
        break;
      *(_DWORD *)(v28 + v30 + 32) = *(_DWORD *)(v33 + v32 - 14);
      if ( v27 < v30 + 144 || v31 + 104 < 4 || v30 + 144 < 0 || v27 < v30 + 144 || v31 + 104 < 4 )
        break;
      v35 = *(_DWORD *)(v33 + v32 - 10);
      *(_DWORD *)(v28 + v30 + 144) = v35;
      if ( (v35 & 0xFFFFFFFE) != 2 )
        goto LABEL_150;
      if ( v27 < v30 + 160 || v31 + 88 < 8 || v30 + 160 < 0 || v27 < v30 + 160 || v31 + 88 < 8 )
        break;
      v36 = v35 == 3 ? mhi_db_brstmode : mhi_db_brstmode_disable;
      *(_QWORD *)(v28 + v30 + 160) = v36;
      if ( v31 + 212 < 4 || v30 + 36 < 0 || v27 < v30 + 36 )
        break;
      v37 = *(_DWORD *)(v33 + v32 - 6);
      *(_DWORD *)(v28 + v30 + 36) = v37;
      if ( v37 > 1 )
      {
        if ( v37 == 2 )
        {
          if ( v27 < v30 + 248 || v31 < 8 || v30 + 248 < 0 || v27 < v30 + 248 )
            break;
          v38 = mhi_process_misc_bw_ev_ring;
        }
        else
        {
          if ( v37 != 3 )
          {
LABEL_147:
            v52 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            dev_err(v2, "[E][%s] Event Ring type not supported\n", "parse_ev_cfg");
            if ( v52 && *(_DWORD *)(v52 + 24) < 3u )
              ipc_log_string(*(_QWORD *)(v52 + 32), "[E][%s] Event Ring type not supported\n", "parse_ev_cfg");
LABEL_150:
            kfree(*(_QWORD *)(a1 + 248));
            v47 = -22;
            goto LABEL_151;
          }
          if ( v27 < v30 + 248 || v31 < 8 || v30 + 248 < 0 || v27 < v30 + 248 )
            break;
          v38 = mhi_process_misc_tsync_ev_ring;
        }
      }
      else if ( v37 )
      {
        if ( v37 != 1 )
          goto LABEL_147;
        if ( v27 < v30 + 248 || v31 < 8 || v30 + 248 < 0 || v27 < v30 + 248 )
          break;
        v38 = mhi_process_ctrl_ev_ring;
      }
      else
      {
        if ( v27 < v30 + 248 || v31 < 8 || v30 + 248 < 0 || v27 < v30 + 248 )
          break;
        v38 = mhi_process_data_event_ring;
      }
      *(_QWORD *)(v28 + v30 + 248) = v38;
      if ( v27 <= v30 + 256 || v30 + 256 < 0 || v27 <= v30 + 256 )
        break;
      v39 = *(unsigned __int8 *)(v33 + v32 - 2);
      *(_BYTE *)(v28 + v30 + 256) = v39;
      if ( v39 == 1 )
        ++*(_DWORD *)(a1 + 216);
      else
        ++*(_DWORD *)(a1 + 220);
      if ( v27 <= v30 + 257 )
        break;
      if ( v30 + 257 < 0 )
        break;
      if ( v27 <= v30 + 257 )
        break;
      *(_BYTE *)(v28 + v30 + 257) = *(_BYTE *)(v33 + v32 - 1);
      if ( v27 <= v30 + 258 || v30 + 258 < 0 || v27 <= v30 + 258 )
        break;
      v40 = *(_BYTE *)(v33 + v32);
      v41 = v28 + v30;
      v30 += 264;
      ++v29;
      v32 += 32;
      v31 -= 264LL;
      *(_BYTE *)(v41 + 258) = v40;
      if ( 264 * v26 == v30 )
        goto LABEL_122;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v54 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &parse_ch_cfg__alloc_tag;
    v55 = vcalloc_noprof(*(unsigned int *)(a1 + 208), 400);
    *(_QWORD *)(StatusReg + 80) = v54;
    *(_QWORD *)(a1 + 176) = v55;
    if ( !v55 )
      return 4294967284LL;
  }
  v7 = 0;
  v8 = 56;
  v9 = 400;
  v10 = mhi_db_brstmode_disable;
  v11 = mhi_db_brstmode;
  v12 = 1;
  while ( 1 )
  {
    v13 = *(_QWORD *)(a2 + 24) + v7 * (__int64)v8;
    v14 = *(_DWORD *)(v13 + 8);
    if ( v14 >= *(_DWORD *)(a1 + 208) )
      break;
    v15 = *(_QWORD *)(a1 + 176) + v14 * (unsigned __int64)v9;
    *(_QWORD *)v15 = *(_QWORD *)v13;
    *(_DWORD *)(v15 + 200) = v14;
    v16 = *(unsigned int *)(v13 + 12);
    *(_QWORD *)(v15 + 176) = v16;
    if ( !(_DWORD)v16 )
      goto LABEL_143;
    if ( *(_DWORD *)(v13 + 16) )
      v16 = *(unsigned int *)(v13 + 16);
    *(_QWORD *)(v15 + 80) = v16;
    *(_DWORD *)(v15 + 204) = *(_DWORD *)(v13 + 20);
    v17 = *(_DWORD *)(v13 + 24);
    *(_DWORD *)(v15 + 216) = v17;
    v18 = *(_DWORD *)(v13 + 28);
    if ( !v18 )
      v18 = v17;
    *(_DWORD *)(v15 + 212) = v18;
    *(_DWORD *)(v15 + 256) = *(_DWORD *)(v13 + 32);
    *(_DWORD *)(v15 + 228) = *(_DWORD *)(v13 + 36);
    v19 = *(unsigned __int8 *)(v13 + 44);
    *(_BYTE *)(v15 + 392) = v19;
    v20 = *(unsigned __int8 *)(v13 + 45);
    *(_BYTE *)(v15 + 394) = v20;
    *(_BYTE *)(v15 + 224) = *(_BYTE *)(v13 + 46);
    v21 = *(unsigned __int8 *)(v13 + 47);
    *(_BYTE *)(v15 + 395) = v21;
    *(_BYTE *)(v15 + 396) = *(_BYTE *)(v13 + 48);
    if ( v21 == 1 )
    {
      if ( v17 != 2 )
        goto LABEL_137;
    }
    else if ( (v17 == 3 || !v17) && (v20 & 1) == 0 )
    {
LABEL_137:
      v49 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(v2, "[E][%s] Invalid channel configuration\n", "parse_ch_cfg");
      if ( v49 )
      {
        if ( *(_DWORD *)(v49 + 24) <= 2u )
          ipc_log_string(*(_QWORD *)(v49 + 32), "[E][%s] Invalid channel configuration\n", "parse_ch_cfg");
      }
      goto LABEL_143;
    }
    if ( v20 )
    {
      v22 = *(_DWORD *)(v15 + 232);
    }
    else
    {
      v22 = *(_DWORD *)(v13 + 40);
      *(_DWORD *)(v15 + 232) = v22;
      if ( (v22 & 0xFFFFFFFE) != 2 )
      {
        v50 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        dev_err(v2, "[E][%s] Invalid Door bell mode\n", "parse_ch_cfg");
        if ( v50 && *(_DWORD *)(v50 + 24) <= 2u )
          ipc_log_string(*(_QWORD *)(v50 + 32), "[E][%s] Invalid Door bell mode\n", "parse_ch_cfg");
        goto LABEL_143;
      }
    }
    *(_BYTE *)(v15 + 393) = v12;
    if ( v22 == 3 )
      v23 = v11;
    else
      v23 = v10;
    *(_QWORD *)(v15 + 248) = v23;
    if ( v19 )
    {
      v24 = (_QWORD *)(v15 + 376);
      v25 = *(_QWORD **)(a1 + 192);
      if ( v15 + 376 == v6 || v25 == v24 || *v25 != v6 )
      {
        _list_add_valid_or_report();
      }
      else
      {
        *(_QWORD *)(a1 + 192) = v24;
        *(_QWORD *)(v15 + 376) = v6;
        *(_QWORD *)(v15 + 384) = v25;
        *v25 = v24;
      }
    }
    if ( (unsigned int)++v7 >= *(_DWORD *)(a2 + 16) )
      goto LABEL_29;
  }
  v48 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  dev_err(v2, "[E][%s] Channel %d not available\n", "parse_ch_cfg", v14);
  if ( v48 && *(_DWORD *)(v48 + 24) <= 2u )
    ipc_log_string(*(_QWORD *)(v48 + 32), "[E][%s] Channel %d not available\n", "parse_ch_cfg", v14);
LABEL_143:
  vfree(*(_QWORD *)(a1 + 176));
  return 4294967274LL;
}
