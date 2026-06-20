_QWORD *__fastcall rmnet_offload_ingress(_QWORD *result, __int64 a2)
{
  _QWORD *v2; // x24
  _QWORD *v3; // x19
  _QWORD *v5; // x22
  _QWORD *v6; // x8
  _QWORD *v7; // t2
  _QWORD *v8; // x23
  int v9; // w28
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned __int8 *v12; // x8
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x8
  int v16; // w9
  int v17; // w11
  unsigned int v18; // w8
  int v19; // w8
  int v20; // w9
  char v21; // w10
  __int64 v22; // x0
  int v23; // w9
  __int64 v24; // x0
  __int64 v25; // x9
  __int64 v26; // x8
  __int64 v27; // x10
  char v28; // w8
  __int16 v29; // w8
  _DWORD *v30; // x0
  __int64 v31; // x0
  unsigned int *v32; // x8
  int v33; // w0
  __int16 v34; // w8
  __int16 v35; // w9
  int v36; // w10
  __int64 v37; // x0
  __int64 v38; // x23
  __int64 v39; // x10
  __int64 v40; // x8
  __int64 v41; // x11
  __int64 v42; // x0
  _DWORD *v43; // x0
  char v44; // w10
  int v45; // w9
  __int64 v46; // x0
  __int64 ***v47; // x1
  __int64 *v48; // [xsp+0h] [xbp-C0h] BYREF
  __int64 ***v49; // [xsp+8h] [xbp-B8h]
  _BYTE v50[4]; // [xsp+14h] [xbp-ACh] BYREF
  _BYTE v51[4]; // [xsp+18h] [xbp-A8h] BYREF
  unsigned __int8 v52[4]; // [xsp+1Ch] [xbp-A4h] BYREF
  _QWORD v53[2]; // [xsp+20h] [xbp-A0h] BYREF
  int v54; // [xsp+30h] [xbp-90h]
  __int64 v55; // [xsp+38h] [xbp-88h] BYREF
  _QWORD v56[6]; // [xsp+40h] [xbp-80h] BYREF
  __int64 v57; // [xsp+70h] [xbp-50h]
  __int64 v58; // [xsp+78h] [xbp-48h]
  __int64 v59; // [xsp+80h] [xbp-40h]
  __int64 v60; // [xsp+88h] [xbp-38h] BYREF
  __int64 v61; // [xsp+90h] [xbp-30h]
  __int64 v62; // [xsp+98h] [xbp-28h]
  __int64 v63; // [xsp+A0h] [xbp-20h]
  __int64 v64; // [xsp+A8h] [xbp-18h]
  __int64 v65; // [xsp+B0h] [xbp-10h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)*result;
  if ( (_QWORD *)*result != result )
  {
    v3 = result;
    while ( 1 )
    {
      v5 = v2;
      v7 = v2;
      v2 = (_QWORD *)*v2;
      v6 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v6 == v5 && (_QWORD *)v2[1] == v5 )
      {
        v2[1] = v6;
        *v6 = v2;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      *v5 = v5;
      v5[1] = v5;
      v8 = (_QWORD *)rmnet_offload_state_get();
      v48 = (__int64 *)&v48;
      v49 = (__int64 ***)&v48;
      memset(v56, 0, sizeof(v56));
      v57 = 0;
      v58 = 0;
      v59 = 0;
      raw_spin_lock_bh(&rmnet_offload_main_lock);
      *v8 = a2;
      v9 = *((_DWORD *)v5 + 12);
      BYTE3(v59) = 1;
      if ( (*(_BYTE *)(v5[4] + 189LL) & 1) == 0 )
        goto LABEL_56;
      if ( (*((_BYTE *)v5 + 81) & 2) == 0 )
        break;
      v19 = *((unsigned __int8 *)v5 + 78);
      v20 = *(_DWORD *)((char *)v5 + 74);
      v21 = *((_BYTE *)v5 + 79);
      v55 = 0;
      v54 = 0;
      v53[0] = 0;
      v53[1] = 0;
      LOBYTE(v58) = v19;
      HIDWORD(v57) = v20;
      BYTE1(v58) = v21;
      if ( v19 == 4 )
      {
        LODWORD(v62) = 0;
        v60 = 0;
        v61 = 0;
        v22 = rmnet_frag_header_ptr(v5, 0, 20, &v60);
        if ( !v22 )
          goto LABEL_56;
        v23 = *(_DWORD *)(v22 + 16);
        HIDWORD(v56[1]) = *(_DWORD *)(v22 + 12);
        HIDWORD(v56[3]) = v23;
        BYTE4(v56[5]) = *(_BYTE *)(v22 + 8);
        BYTE5(v56[5]) = *(_BYTE *)(v22 + 1);
        HIWORD(v56[5]) = *(_WORD *)(v22 + 6);
      }
      else
      {
        v63 = 0;
        v64 = 0;
        v61 = 0;
        v62 = 0;
        v60 = 0;
        v24 = rmnet_frag_header_ptr(v5, 0, 40, &v60);
        if ( !v24 )
          goto LABEL_56;
        v25 = *(_QWORD *)(v24 + 8);
        *(_QWORD *)((char *)&v56[2] + 4) = *(_QWORD *)(v24 + 16);
        v26 = *(_QWORD *)(v24 + 24);
        v27 = *(_QWORD *)(v24 + 32);
        *(_QWORD *)((char *)&v56[1] + 4) = v25;
        *(_QWORD *)((char *)&v56[3] + 4) = v26;
        *(_QWORD *)((char *)&v56[4] + 4) = v27;
        HIDWORD(v56[5]) = *(_DWORD *)v24;
        if ( WORD2(v57) >= 0x29u )
        {
          v28 = *(_BYTE *)(v24 + 6);
          *(_WORD *)v52 = 0;
          v51[0] = 0;
          v50[0] = v28;
          if ( (rmnet_frag_ipv6_skip_exthdr(v5, 40, v50, v52, v51) & 0x80000000) != 0
            || *(_WORD *)v52
            || (v51[0] & 1) != 0 )
          {
            if ( v50[0] == 44 )
            {
              v29 = WORD2(v57) + 8;
              goto LABEL_30;
            }
LABEL_31:
            rmnet_offload_stats_update(6);
LABEL_56:
            LOWORD(v59) = v9 - (WORD2(v57) + HIWORD(v57));
            if ( BYTE4(v59) == 1 )
              rmnet_offload_stats_update(7);
            v56[0] = v5;
            goto LABEL_59;
          }
        }
      }
      v30 = (_DWORD *)rmnet_frag_header_ptr(v5, WORD2(v57), 8, &v55);
      if ( !v30 )
        goto LABEL_56;
      LODWORD(v56[1]) = *v30;
      if ( BYTE1(v58) == 6 )
      {
        v31 = rmnet_frag_header_ptr(v5, WORD2(v57), 20, v53);
        if ( !v31 )
          goto LABEL_56;
        if ( (*((_BYTE *)v5 + 81) & 8) != 0 )
          v32 = (unsigned int *)v5 + 15;
        else
          v32 = (unsigned int *)(v31 + 4);
        LODWORD(v57) = bswap32(*v32);
      }
      v33 = rmnet_offload_compute_flow_hash(v56);
      v34 = *((_WORD *)v5 + 37);
      v35 = *((_WORD *)v5 + 38);
      HIDWORD(v58) = v33;
      v36 = *((_DWORD *)v5 + 12);
      v56[0] = v5;
      BYTE3(v59) = 0;
      LOWORD(v59) = v36 - (v34 + v35);
LABEL_59:
      rmnet_offload_stats_update(0);
      if ( (v59 & 0x1000000) != 0 )
        goto LABEL_64;
      if ( BYTE4(v59) == 1 )
      {
        rmnet_offload_engine_flush_by_hash(HIDWORD(v58), &v48);
LABEL_64:
        if ( WORD2(v57) + (unsigned __int16)v59 + (unsigned int)HIWORD(v57) <= 0x10000 )
        {
          v46 = v56[0];
          if ( (v59 & 0x1000000) == 0 )
            *(_DWORD *)(v56[0] + 52LL) = HIDWORD(v58);
          v47 = v49;
          if ( (__int64 **)v46 == &v48 || v49 == (__int64 ***)v46 || *v49 != &v48 )
          {
            _list_add_valid_or_report(v46, v49, &v48);
          }
          else
          {
            v49 = (__int64 ***)v46;
            *(_QWORD *)v46 = &v48;
            *(_QWORD *)(v46 + 8) = v47;
            *v47 = (__int64 **)v46;
          }
        }
        goto LABEL_4;
      }
      if ( (*((_BYTE *)v5 + 81) & 1) == 0
        || (((__int64 (__fastcall *)(_QWORD *, __int64 **))rmnet_offload_engine_ingress)(v56, &v48) & 1) == 0 )
      {
        goto LABEL_64;
      }
LABEL_4:
      raw_spin_unlock_bh(&rmnet_offload_main_lock);
      result = (_QWORD *)rmnet_offload_deliver_descs(&v48);
      if ( v2 == v3 )
        goto LABEL_72;
    }
    v10 = v5[2];
    if ( (_QWORD *)v10 == v5 + 2
      || !v10
      || (v11 = *(_QWORD *)(v10 + 16)) == 0
      || (v11 & 1) != 0
      || (v12 = (unsigned __int8 *)((((v11 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                                  + *(unsigned int *)(v10 + 28))) == nullptr )
    {
LABEL_3:
      rmnet_offload_stats_update(2);
      rmnet_recycle_frag_descriptor(v5, a2);
      goto LABEL_4;
    }
    v13 = *v12 >> 4;
    LOBYTE(v58) = v13;
    if ( v13 == 6 )
    {
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v60 = 0;
      LOWORD(v53[0]) = 0;
      LOBYTE(v55) = 0;
      v37 = rmnet_frag_header_ptr(v5, 0, 40, &v60);
      if ( !v37 )
        goto LABEL_56;
      v38 = v37;
      v52[0] = *(_BYTE *)(v37 + 6);
      LODWORD(v14) = rmnet_frag_ipv6_skip_exthdr(v5, 40, v52, v53, &v55);
      if ( (v14 & 0x80000000) != 0 )
        goto LABEL_56;
      v16 = v52[0];
      WORD2(v57) = v14;
      BYTE1(v58) = v52[0];
      v39 = *(_QWORD *)(v38 + 8);
      *(_QWORD *)((char *)&v56[2] + 4) = *(_QWORD *)(v38 + 16);
      v41 = *(_QWORD *)(v38 + 24);
      v40 = *(_QWORD *)(v38 + 32);
      *(_QWORD *)((char *)&v56[1] + 4) = v39;
      *(_QWORD *)((char *)&v56[4] + 4) = v40;
      *(_QWORD *)((char *)&v56[3] + 4) = v41;
      HIDWORD(v56[5]) = *(_DWORD *)v38;
      if ( LOWORD(v53[0]) || (unsigned __int8)v55 == 1 )
      {
        if ( v52[0] == 44 )
        {
          v29 = v14 + 8;
LABEL_30:
          WORD2(v57) = v29;
        }
        goto LABEL_31;
      }
      v18 = (unsigned __int16)((bswap32(*(unsigned __int16 *)(v38 + 4)) >> 16) + 40);
    }
    else
    {
      if ( v13 != 4 )
        goto LABEL_3;
      LODWORD(v62) = 0;
      v60 = 0;
      v61 = 0;
      v14 = rmnet_frag_header_ptr(v5, 0, 20, &v60);
      if ( !v14 )
        goto LABEL_56;
      v15 = v14;
      LOWORD(v14) = 4 * (*(_BYTE *)v14 & 0xF);
      WORD2(v57) = v14;
      v16 = *(unsigned __int8 *)(v15 + 9);
      BYTE1(v58) = *(_BYTE *)(v15 + 9);
      v17 = *(_DWORD *)(v15 + 16);
      HIDWORD(v56[1]) = *(_DWORD *)(v15 + 12);
      HIDWORD(v56[3]) = v17;
      BYTE4(v56[5]) = *(_BYTE *)(v15 + 8);
      BYTE5(v56[5]) = *(_BYTE *)(v15 + 1);
      HIWORD(v56[5]) = *(_WORD *)(v15 + 6);
      if ( (v56[5] & 0xFF3F000000000000LL) != 0 )
        goto LABEL_31;
      v18 = bswap32(*(unsigned __int16 *)(v15 + 2)) >> 16;
    }
    BYTE4(v59) = v18 != (unsigned __int16)v9;
    if ( v16 == 17 )
    {
      v60 = 0;
      v43 = (_DWORD *)rmnet_frag_header_ptr(v5, (unsigned __int16)v14, 8, &v60);
      if ( !v43 )
        goto LABEL_56;
      HIWORD(v57) = 8;
      LODWORD(v56[1]) = *v43;
    }
    else
    {
      if ( v16 != 6 )
        goto LABEL_56;
      LODWORD(v62) = 0;
      v60 = 0;
      v61 = 0;
      v42 = rmnet_frag_header_ptr(v5, (unsigned __int16)v14, 20, &v60);
      if ( !v42 )
        goto LABEL_56;
      HIWORD(v57) = (*(_BYTE *)(v42 + 12) >> 2) & 0x3C;
      LODWORD(v56[1]) = *(_DWORD *)v42;
      LODWORD(v57) = bswap32(*(_DWORD *)(v42 + 4));
    }
    BYTE3(v59) = 0;
    HIDWORD(v58) = rmnet_offload_compute_flow_hash(v56);
    if ( (v59 & 0x100000000LL) == 0 )
    {
      v44 = *((_BYTE *)v5 + 81);
      v45 = HIDWORD(v57);
      *((_WORD *)v5 + 39) = v58;
      *(_DWORD *)((char *)v5 + 74) = v45;
      *((_BYTE *)v5 + 81) = v44 | 2;
    }
    goto LABEL_56;
  }
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
