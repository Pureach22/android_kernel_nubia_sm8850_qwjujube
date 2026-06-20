__int64 __fastcall drm_dp_mst_hpd_irq_handle_event(__int64 a1, unsigned __int8 *a2, __int64 a3, _BYTE *a4)
{
  int v8; // w8
  unsigned __int8 v9; // w8
  __int64 v10; // x23
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // x22
  unsigned __int8 *v16; // x25
  char v17; // w8
  __int64 v18; // x2
  unsigned int v19; // w5
  __int64 v20; // x4
  unsigned int v21; // w5
  __int64 v22; // x4
  unsigned __int8 v23; // w8
  char v24; // w9
  __int64 v25; // x2
  __int64 v26; // x4
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x1
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x1
  int v33; // w24
  __int64 v34; // x26
  __int64 v35; // x0
  __int64 v36; // x24
  int v37; // w8
  __int64 v38; // x8
  __int64 v39; // x1
  __int64 v40; // x8
  __int64 v41; // x1
  __int64 v42; // x8
  __int64 v43; // x1
  char v44; // w8
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x1
  __int64 v48; // x8
  __int64 v49; // x2
  __int64 *v50; // x1
  __int64 v51; // x4
  const char *v52; // x3
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x8
  int v56; // w8
  __int64 v57; // x4
  __int64 v58; // x4
  size_t v59; // x2
  const char *v60; // x3
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  __int64 v63; // x10
  __int64 v64; // x12
  unsigned int v65; // w13
  char v66; // w14
  unsigned int v67; // w5
  char v68; // w13
  char v69; // w13
  _QWORD *v70; // x13
  __int64 v71; // x13
  _QWORD *v72; // t2
  char v73; // w13
  __int64 v74; // x8
  __int64 v75; // x1
  unsigned int v76; // w4
  const char *v77; // x5
  unsigned int v78; // w6
  const char *v79; // x7
  _QWORD *v80; // x8
  __int64 v81; // x9
  __int64 v82; // x8
  __int64 v83; // x0
  const char *v84; // x3
  _QWORD *v85[2]; // [xsp+10h] [xbp-10h] BYREF

  v85[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  *a4 = 0;
  v8 = *a2 & 0x3F | (((*a2 >> 7) & 1) << 6);
  if ( v8 != *(unsigned __int8 *)(a1 + 927) )
  {
    *(_BYTE *)(a1 + 927) = v8;
    *a4 = 1;
  }
  v9 = a2[1];
  if ( (v9 & 0x10) != 0 )
  {
    v85[0] = nullptr;
    if ( (drm_dp_get_one_sb_msg(a1, 0, v85) & 1) == 0 )
    {
LABEL_13:
      memset((void *)(a1 + 470), 0, 0x146u);
LABEL_14:
      if ( v85[0] )
        drm_dp_mst_topology_put_mstb(v85[0]);
LABEL_16:
      *a4 = 1;
      *(_BYTE *)(a3 + 1) |= 0x10u;
      v9 = a2[1];
      goto LABEL_17;
    }
    if ( *(_BYTE *)(a1 + 779) != 1 )
      goto LABEL_14;
    mutex_lock(a1 + 936);
    v10 = *(_QWORD *)(a1 + 984);
    mutex_unlock(a1 + 936);
    if ( v10 == a1 + 984 || v10 == 320 || *(_QWORD **)(v10 - 8) != v85[0] )
    {
      v11 = *(_QWORD *)(a1 + 104);
      if ( v11 )
        v12 = *(_QWORD *)(v11 + 8);
      else
        v12 = 0;
      _drm_dev_dbg(
        0,
        v12,
        2,
        "Got MST reply with no msg %p %d %d %02x %02x\n",
        v85[0],
        *(unsigned __int8 *)(a1 + 795),
        *(unsigned __int8 *)(a1 + 780),
        *(unsigned __int8 *)(a1 + 782),
        *(unsigned __int8 *)(a1 + 518));
      goto LABEL_13;
    }
    memset((void *)(v10 + 26), 0, 0x1A4u);
    v23 = *(_BYTE *)(a1 + 518);
    *(_BYTE *)(v10 + 26) = v23 >> 7;
    v24 = *(_BYTE *)(a1 + 518);
    v25 = v24 & 0x7F;
    *(_BYTE *)(v10 + 27) = v24 & 0x7F;
    if ( (v23 & 0x80) != 0 )
    {
      v45 = *(_QWORD *)(a1 + 519);
      *(_QWORD *)(v10 + 36) = *(_QWORD *)(a1 + 527);
      *(_QWORD *)(v10 + 28) = v45;
      *(_BYTE *)(v10 + 44) = *(_BYTE *)(a1 + 535);
      *(_BYTE *)(v10 + 45) = *(_BYTE *)(a1 + 536);
      goto LABEL_153;
    }
    if ( (v24 & 0x7Fu) <= 0x20 )
    {
      if ( (v24 & 0x7Fu) <= 0x11 )
      {
        if ( (_DWORD)v25 != 1 )
        {
          if ( (_DWORD)v25 != 16 )
          {
            if ( (_DWORD)v25 == 17 )
            {
              *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) >> 4;
              if ( *(unsigned __int8 *)(a1 + 777) < 2u )
              {
                v26 = 2;
LABEL_148:
                _drm_dev_dbg(0, 0, 2, "allocate payload parse length fail %d %d\n", v26);
                goto LABEL_153;
              }
              *(_BYTE *)(v10 + 29) = *(_BYTE *)(a1 + 520);
              if ( *(unsigned __int8 *)(a1 + 777) < 3u )
              {
                v26 = 3;
                goto LABEL_148;
              }
              *(_WORD *)(v10 + 30) = bswap32(*(unsigned __int16 *)(a1 + 521)) >> 16;
              if ( *(unsigned __int8 *)(a1 + 777) <= 4u )
              {
                v26 = 5;
                goto LABEL_148;
              }
              goto LABEL_153;
            }
            goto LABEL_170;
          }
          *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) >> 4;
          *(_BYTE *)(v10 + 29) = *(_BYTE *)(a1 + 519) & 1;
          if ( *(unsigned __int8 *)(a1 + 777) >= 2u )
          {
            *(_WORD *)(v10 + 30) = bswap32(*(unsigned __int16 *)(a1 + 520)) >> 16;
            if ( *(unsigned __int8 *)(a1 + 777) >= 4u )
            {
              *(_WORD *)(v10 + 32) = bswap32(*(unsigned __int16 *)(a1 + 522)) >> 16;
              if ( *(unsigned __int8 *)(a1 + 777) > 5u )
                goto LABEL_153;
              v58 = 6;
            }
            else
            {
              v58 = 4;
            }
          }
          else
          {
            v58 = 2;
          }
          v52 = "enum resource parse length fail %d %d\n";
LABEL_152:
          _drm_dev_dbg(0, 0, 2, v52, v58);
          goto LABEL_153;
        }
        v55 = *(_QWORD *)(a1 + 519);
        *(_QWORD *)(v10 + 36) = *(_QWORD *)(a1 + 527);
        *(_QWORD *)(v10 + 28) = v55;
        v56 = *(_BYTE *)(a1 + 535) & 0xF;
        *(_BYTE *)(v10 + 44) = v56;
        if ( *(unsigned __int8 *)(a1 + 777) >= 0x12u )
        {
          if ( v56 )
          {
            v61 = 0;
            v62 = a1 + 518;
            v63 = v10 + 45;
            LODWORD(v51) = 18;
            while ( 1 )
            {
              v64 = (unsigned int)v51;
              v65 = *(char *)(v62 + (unsigned int)v51);
              if ( (v65 & 0x80000000) != 0 )
              {
                if ( v61 > 0xF )
                {
LABEL_177:
                  __break(0x5512u);
                  goto LABEL_178;
                }
                *(_BYTE *)v63 = 1;
                v65 = *(unsigned __int8 *)(v62 + (unsigned int)v51);
              }
              else if ( v61 > 0xF )
              {
                goto LABEL_177;
              }
              v51 = (unsigned int)v51 + 1LL;
              *(_BYTE *)(v63 + 1) = (v65 >> 4) & 7;
              *(_BYTE *)(v63 + 2) = *(_BYTE *)(v62 + v64) & 0xF;
              if ( (unsigned int)v64 >= *(unsigned __int8 *)(a1 + 777) )
                goto LABEL_140;
              v66 = *(_BYTE *)v63;
              *(_BYTE *)(v63 + 3) = *(_BYTE *)(v62 + v51) >> 7;
              *(_BYTE *)(v63 + 4) = (*(_BYTE *)(v62 + v51) & 0x40) != 0;
              if ( (v66 & 1) != 0 )
              {
                v67 = *(unsigned __int8 *)(a1 + 777);
                v51 = (unsigned int)(v64 + 2);
                if ( (unsigned int)v51 > v67 )
                  goto LABEL_140;
              }
              else
              {
                v68 = *(_BYTE *)(v62 + v51);
                v51 = v64 + 2;
                *(_BYTE *)(v63 + 5) = (v68 & 0x20) != 0;
                if ( (int)v64 + 2 > (unsigned int)*(unsigned __int8 *)(a1 + 777) )
                  goto LABEL_140;
                v69 = *(_BYTE *)(v62 + v51);
                v51 = (unsigned int)(v64 + 3);
                *(_BYTE *)(v63 + 6) = v69;
                if ( (unsigned int)v51 > *(unsigned __int8 *)(a1 + 777) )
                  goto LABEL_140;
                v70 = (_QWORD *)(v62 + (unsigned int)v51);
                v51 = v64 + 19;
                v72 = v70;
                v71 = *v70;
                *(_QWORD *)(v63 + 15) = v72[1];
                *(_QWORD *)(v63 + 7) = v71;
                if ( (int)v64 + 19 > (unsigned int)*(unsigned __int8 *)(a1 + 777) )
                  goto LABEL_140;
                *(_BYTE *)(v63 + 23) = *(_BYTE *)(v62 + v51) >> 4;
                v73 = *(_BYTE *)(v62 + v51);
                v51 = (unsigned int)(v64 + 20);
                *(_BYTE *)(v63 + 24) = v73 & 0xF;
                v67 = *(unsigned __int8 *)(a1 + 777);
              }
              if ( (unsigned int)v51 > v67 )
                goto LABEL_140;
              ++v61;
              v63 += 25;
              if ( v61 >= *(unsigned __int8 *)(v10 + 44) )
                goto LABEL_153;
            }
          }
          goto LABEL_153;
        }
        v51 = 18;
LABEL_140:
        _drm_dev_dbg(0, 0, 2, "link address reply parse length fail %d %d\n", v51);
        goto LABEL_153;
      }
      if ( (_DWORD)v25 == 18 )
      {
        *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) >> 4;
        if ( *(unsigned __int8 *)(a1 + 777) >= 2u )
        {
          *(_WORD *)(v10 + 30) = bswap32(*(unsigned __int16 *)(a1 + 520)) >> 16;
          if ( *(unsigned __int8 *)(a1 + 777) > 3u )
            goto LABEL_153;
          v57 = 4;
        }
        else
        {
          v57 = 2;
        }
        _drm_dev_dbg(0, 0, 2, "query payload parse length fail %d %d\n", v57);
        goto LABEL_153;
      }
      if ( (_DWORD)v25 == 20 )
      {
LABEL_153:
        if ( *(_BYTE *)(v10 + 26) == 1 )
        {
          v74 = *(_QWORD *)(a1 + 104);
          if ( v74 )
            v75 = *(_QWORD *)(v74 + 8);
          else
            v75 = 0;
          v76 = *(unsigned __int8 *)(v10 + 27);
          v77 = "unknown";
          if ( v76 <= 0x38 && ((0xFEFFC0FFE0FFF8uLL >> v76) & 1) == 0 )
            v77 = drm_dp_mst_req_type_str_req_type_str[*(unsigned __int8 *)(v10 + 27)];
          v78 = *(unsigned __int8 *)(v10 + 44);
          v79 = "unknown";
          if ( v78 <= 0xA && *(_BYTE *)(v10 + 44) )
            v79 = (const char *)drm_dp_mst_nak_reason_str_nak_reason_str[*(unsigned __int8 *)(v10 + 44)];
          _drm_dev_dbg(
            0,
            v75,
            2,
            "Got NAK reply: req 0x%02x (%s), reason 0x%02x (%s), nak data 0x%02x\n",
            v76,
            v77,
            v78,
            v79,
            *(unsigned __int8 *)(v10 + 45));
        }
        memset((void *)(a1 + 470), 0, 0x146u);
        drm_dp_mst_topology_put_mstb(v85[0]);
        mutex_lock(a1 + 936);
        v80 = *(_QWORD **)(v10 + 8);
        *(_DWORD *)(v10 + 20) = 3;
        if ( *v80 == v10 && (v81 = *(_QWORD *)v10, *(_QWORD *)(*(_QWORD *)v10 + 8LL) == v10) )
        {
          *(_QWORD *)(v81 + 8) = v80;
          *v80 = v81;
        }
        else
        {
          _list_del_entry_valid_or_report(v10);
        }
        *(_QWORD *)v10 = 0xDEAD000000000100LL;
        *(_QWORD *)(v10 + 8) = 0xDEAD000000000122LL;
        mutex_unlock(a1 + 936);
        _wake_up(a1 + 1000, 3, 0, 0);
        goto LABEL_16;
      }
      if ( (_DWORD)v25 != 32 )
      {
LABEL_170:
        v82 = *(_QWORD *)(a1 + 104);
        if ( v82 )
          v83 = *(_QWORD *)(v82 + 8);
        else
          v83 = 0;
        v84 = "unknown";
        if ( (unsigned int)v25 <= 0x38 && ((0xFEFFC0FFE0FFF8uLL >> v25) & 1) == 0 )
          v84 = drm_dp_mst_req_type_str_req_type_str[v25];
        dev_err(v83, "[drm] *ERROR* Got unknown reply 0x%02x (%s)\n", v25, v84);
        goto LABEL_153;
      }
      *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) & 0xF;
      if ( *(unsigned __int8 *)(a1 + 777) < 2u )
      {
        v51 = 2;
        goto LABEL_140;
      }
      v59 = *(unsigned __int8 *)(a1 + 520);
      *(_BYTE *)(v10 + 29) = v59;
      if ( *(unsigned __int8 *)(a1 + 777) < 3u )
      {
        v51 = 3;
        goto LABEL_140;
      }
LABEL_141:
      memcpy((void *)(v10 + 30), (const void *)(a1 + 521), v59);
      goto LABEL_153;
    }
    if ( (v24 & 0x7Fu) > 0x23 )
    {
      if ( (unsigned int)(v25 - 36) >= 2 )
      {
        if ( (_DWORD)v25 == 56 )
        {
          *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 521);
          *(_BYTE *)(v10 + 29) = *(_BYTE *)(a1 + 520) & 1;
          *(_BYTE *)(v10 + 33) = (*(_BYTE *)(a1 + 520) & 0x10) != 0;
          *(_BYTE *)(v10 + 34) = (*(_BYTE *)(a1 + 520) & 8) != 0;
          *(_BYTE *)(v10 + 32) = (*(_BYTE *)(a1 + 520) & 0x20) != 0;
          *(_BYTE *)(v10 + 31) = (*(_BYTE *)(a1 + 520) & 0x40) != 0;
          *(_BYTE *)(v10 + 30) = *(_BYTE *)(a1 + 520) >> 7;
          *(_BYTE *)(v10 + 35) = (*(_BYTE *)(a1 + 519) & 8) != 0;
          *(_BYTE *)(v10 + 36) = (*(_BYTE *)(a1 + 519) & 0x10) != 0;
          *(_BYTE *)(v10 + 37) = (*(_BYTE *)(a1 + 519) & 0x20) != 0;
          *(_BYTE *)(v10 + 38) = *(_BYTE *)(a1 + 519) >> 6;
          goto LABEL_153;
        }
        goto LABEL_170;
      }
      *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) >> 4;
      if ( *(unsigned __int8 *)(a1 + 777) > 1u )
        goto LABEL_153;
      v52 = "power up/down phy parse length fail %d %d\n";
    }
    else if ( (_DWORD)v25 == 33 )
    {
      *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) & 0xF;
      if ( *(unsigned __int8 *)(a1 + 777) > 1u )
        goto LABEL_153;
      v52 = "parse length fail %d %d\n";
    }
    else
    {
      if ( (_DWORD)v25 != 34 )
        goto LABEL_153;
      *(_BYTE *)(v10 + 28) = *(_BYTE *)(a1 + 519) & 0xF;
      if ( *(unsigned __int8 *)(a1 + 777) >= 2u )
      {
        v59 = *(unsigned __int8 *)(a1 + 520);
        *(_BYTE *)(v10 + 29) = v59;
        goto LABEL_141;
      }
      v52 = "remote i2c reply parse length fail %d %d\n";
    }
    v58 = 2;
    goto LABEL_152;
  }
LABEL_17:
  if ( (v9 & 0x20) != 0 )
  {
    if ( (drm_dp_get_one_sb_msg(a1, 1, 0) & 1) == 0 )
    {
LABEL_91:
      memset((void *)(a1 + 144), 0, 0x146u);
      goto LABEL_92;
    }
    if ( *(_BYTE *)(a1 + 453) != 1 )
    {
LABEL_92:
      result = 0;
LABEL_93:
      *a4 = 1;
      *(_BYTE *)(a3 + 1) |= 0x20u;
      goto LABEL_94;
    }
    v14 = _kmalloc_cache_noprof(drm_edid_free, 3520, 152);
    v15 = v14;
    if ( !v14 )
    {
      result = 4294967284LL;
      goto LABEL_93;
    }
    *(_QWORD *)(v14 + 16) = 0;
    v16 = (unsigned __int8 *)(v14 + 16);
    v10 = v14 + 136;
    *(_QWORD *)(v14 + 136) = v14 + 136;
    *(_QWORD *)(v14 + 144) = v14 + 136;
    v17 = *(_BYTE *)(a1 + 192);
    *(_QWORD *)(v14 + 24) = 0;
    *(_QWORD *)(v14 + 32) = 0;
    *(_QWORD *)(v14 + 40) = 0;
    *(_QWORD *)(v14 + 48) = 0;
    v18 = v17 & 0x7F;
    *(_QWORD *)(v14 + 56) = 0;
    *(_QWORD *)(v14 + 64) = 0;
    *(_QWORD *)(v14 + 72) = 0;
    *(_QWORD *)(v14 + 80) = 0;
    *(_QWORD *)(v14 + 88) = 0;
    *(_QWORD *)(v14 + 96) = 0;
    *(_QWORD *)(v14 + 104) = 0;
    *(_QWORD *)(v14 + 112) = 0;
    *(_QWORD *)(v14 + 120) = 0;
    *(_QWORD *)(v14 + 128) = 0;
    *(_BYTE *)(v14 + 16) = v17 & 0x7F;
    if ( (v17 & 0x7F) == 0x13 )
    {
      v21 = *(unsigned __int8 *)(a1 + 451);
      *(_BYTE *)(v14 + 24) = *(_BYTE *)(a1 + 193) >> 4;
      if ( v21 >= 2 )
      {
        v30 = *(_QWORD *)(a1 + 202);
        *(_QWORD *)(v14 + 25) = *(_QWORD *)(a1 + 194);
        *(_QWORD *)(v14 + 33) = v30;
        if ( v21 >= 0x12 )
        {
          *(_WORD *)(v14 + 42) = bswap32(*(unsigned __int16 *)(a1 + 210)) >> 16;
          goto LABEL_48;
        }
        v22 = 18;
      }
      else
      {
        v22 = 2;
      }
      v31 = *(_QWORD *)(a1 + 104);
      if ( v31 )
        v32 = *(_QWORD *)(v31 + 8);
      else
        v32 = 0;
      _drm_dev_dbg(0, v32, 2, "resource status reply parse length fail %d %d\n", v22);
    }
    else if ( (_DWORD)v18 == 2 )
    {
      v19 = *(unsigned __int8 *)(a1 + 451);
      *(_BYTE *)(v14 + 40) = *(_BYTE *)(a1 + 193) >> 4;
      if ( v19 >= 2 )
      {
        v27 = *(_QWORD *)(a1 + 202);
        *(_QWORD *)(v14 + 24) = *(_QWORD *)(a1 + 194);
        *(_QWORD *)(v14 + 32) = v27;
        if ( v19 >= 0x12 )
        {
          v44 = *(_BYTE *)(a1 + 210);
          *(_BYTE *)(v14 + 41) = (v44 & 0x40) != 0;
          *(_BYTE *)(v14 + 42) = (v44 & 0x20) != 0;
          *(_BYTE *)(v14 + 43) = (v44 & 0x10) != 0;
          *(_BYTE *)(v14 + 44) = (v44 & 8) != 0;
          *(_BYTE *)(v14 + 45) = v44 & 7;
          goto LABEL_48;
        }
        v20 = 18;
      }
      else
      {
        v20 = 2;
      }
      v28 = *(_QWORD *)(a1 + 104);
      if ( v28 )
        v29 = *(_QWORD *)(v28 + 8);
      else
        v29 = 0;
      _drm_dev_dbg(0, v29, 2, "connection status reply parse length fail %d %d\n", v20);
    }
    else
    {
      v53 = *(_QWORD *)(a1 + 104);
      if ( v53 )
        v54 = *(_QWORD *)(v53 + 8);
      else
        v54 = 0;
      v60 = "unknown";
      if ( (unsigned int)v18 <= 0x38 && ((0xFEFFC0FFE0FFF8uLL >> v18) & 1) == 0 )
        v60 = drm_dp_mst_req_type_str_req_type_str[v18];
      dev_err(v54, "[drm] *ERROR* Got unknown request 0x%02x (%s)\n", v18, v60);
    }
LABEL_48:
    v33 = *v16;
    if ( v33 == 2 || v33 == 19 )
    {
      v34 = *(_QWORD *)(a1 + 904);
      v35 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
      if ( v35 )
      {
        *(_QWORD *)(v35 + 312) = v34;
        *(_BYTE *)v35 = v33;
        v36 = v35;
        *(_BYTE *)(v35 + 305) = 1;
        mutex_lock(a1 + 936);
        process_single_tx_qlock(a1, v36, 1);
        mutex_unlock(a1 + 936);
        kfree(v36);
      }
      v37 = *v16;
      if ( v37 == 19 )
      {
        v42 = *(_QWORD *)(a1 + 104);
        if ( v42 )
          v43 = *(_QWORD *)(v42 + 8);
        else
          v43 = 0;
        _drm_dev_dbg(
          0,
          v43,
          2,
          "Got RSN: pn: %d avail_pbn %d\n",
          *(unsigned __int8 *)(v15 + 24),
          *(unsigned __int16 *)(v15 + 42));
      }
      else if ( v37 == 2 )
      {
        v38 = *(_QWORD *)(a1 + 104);
        v39 = v38 ? *(_QWORD *)(v38 + 8) : 0LL;
        _drm_dev_dbg(
          0,
          v39,
          2,
          "Got CSN: pn: %d ldps:%d ddps: %d mcs: %d ip: %d pdt: %d\n",
          *(unsigned __int8 *)(v15 + 40),
          *(unsigned __int8 *)(v15 + 41),
          *(unsigned __int8 *)(v15 + 42),
          *(unsigned __int8 *)(v15 + 43),
          *(unsigned __int8 *)(v15 + 44),
          *(unsigned __int8 *)(v15 + 45));
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 904) + 72LL) & 1) == 0 )
        {
          v46 = *(_QWORD *)(a1 + 104);
          if ( v46 )
            v47 = *(_QWORD *)(v46 + 8);
          else
            v47 = 0;
          _drm_dev_dbg(0, v47, 2, "Got CSN before finish topology probing. Skip it.");
LABEL_90:
          kfree(v15);
          goto LABEL_91;
        }
      }
      v48 = *(_QWORD *)(a1 + 462);
      *(_QWORD *)v15 = *(_QWORD *)(a1 + 454);
      *(_QWORD *)(v15 + 8) = v48;
      mutex_lock(a1 + 1224);
      v49 = a1 + 1208;
      v50 = *(__int64 **)(a1 + 1216);
      if ( v10 == a1 + 1208 || v50 == (__int64 *)v10 || *v50 != v49 )
      {
LABEL_178:
        _list_add_valid_or_report(v10);
      }
      else
      {
        *(_QWORD *)(a1 + 1216) = v10;
        *(_QWORD *)(v15 + 136) = v49;
        *(_QWORD *)(v15 + 144) = v50;
        *v50 = v10;
      }
      mutex_unlock(a1 + 1224);
      queue_work_on(32, system_long_wq, a1 + 1272);
      goto LABEL_91;
    }
    v40 = *(_QWORD *)(a1 + 104);
    if ( v40 )
      v41 = *(_QWORD *)(v40 + 8);
    else
      v41 = 0;
    _drm_dev_dbg(0, v41, 2, "Received unknown up req type, ignoring: %x\n", v33);
    goto LABEL_90;
  }
  result = 0;
LABEL_94:
  _ReadStatusReg(SP_EL0);
  return result;
}
