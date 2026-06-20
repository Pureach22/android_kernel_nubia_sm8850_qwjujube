__int64 __fastcall aps_data_active(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 coarse_with_offset; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  _BYTE *v7; // x8
  int v8; // w8
  __int64 v9; // x20
  __int64 v10; // x0
  char v11; // w10
  int v12; // w8
  int v13; // w22
  int v14; // w21
  int v15; // w11
  int v16; // w12
  int v17; // w9
  __int64 v18; // x8
  __int64 v19; // x1
  __int64 v20; // x19
  __int64 v21; // x23
  __int64 v22; // x0
  __int64 v23; // x20
  __int64 v24; // x10
  __int64 v25; // x11
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x20
  unsigned int v29; // w10
  __int64 *v30; // x11
  __int64 v31; // x13
  __int64 v32; // x14
  __int64 v33; // x13
  __int64 v34; // x12
  __int64 v35; // x14
  int v36; // w8
  char v37[4]; // [xsp+4h] [xbp-6Ch] BYREF
  char v38[4]; // [xsp+8h] [xbp-68h] BYREF
  __int16 v39; // [xsp+Ch] [xbp-64h] BYREF
  _QWORD v40[5]; // [xsp+10h] [xbp-60h] BYREF
  __int64 v41; // [xsp+38h] [xbp-38h]
  __int64 v42; // [xsp+40h] [xbp-30h] BYREF
  __int64 v43; // [xsp+48h] [xbp-28h]
  __int64 v44; // [xsp+50h] [xbp-20h]
  __int64 v45; // [xsp+58h] [xbp-18h]
  __int64 v46; // [xsp+60h] [xbp-10h]
  __int64 v47; // [xsp+68h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  memset(v40, 0, sizeof(v40));
  if ( !(result | a2) )
    goto LABEL_42;
  v2 = result;
  raw_spin_lock_bh(&dl_activity_lock);
  if ( !inactive_ktime )
    goto LABEL_41;
  coarse_with_offset = ktime_get_coarse_with_offset(1);
  if ( coarse_with_offset - last_inactive_ts <= inactive_ktime )
    goto LABEL_41;
  if ( v2 )
  {
    v5 = *(_QWORD *)(v2 + 16);
    if ( v5 == v2 + 16 )
      goto LABEL_41;
    if ( !v5 )
      goto LABEL_41;
    v6 = *(_QWORD *)(v5 + 16);
    if ( !v6 )
      goto LABEL_41;
    if ( (v6 & 1) != 0 )
      goto LABEL_41;
    v7 = (_BYTE *)((((v6 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                 + *(unsigned int *)(v5 + 28));
    if ( !v7 )
      goto LABEL_41;
    v8 = *v7 & 0xF0;
    if ( v8 == 96 )
    {
      v21 = coarse_with_offset;
      v45 = 0;
      v46 = 0;
      v43 = 0;
      v44 = 0;
      v42 = 0;
      v39 = 0;
      v37[0] = 0;
      v22 = rmnet_frag_header_ptr(v2, 0, 40, &v42);
      if ( !v22 )
        goto LABEL_41;
      v23 = v22;
      v38[0] = *(_BYTE *)(v22 + 6);
      v10 = rmnet_frag_ipv6_skip_exthdr(v2, 40, v38, &v39, v37);
      if ( (v10 & 0x80000000) != 0 )
        goto LABEL_41;
      v19 = (unsigned int)v10;
      if ( v39 || (v37[0] & 1) != 0 )
      {
        v14 = 1;
        BYTE1(v40[0]) = 1;
        v13 = (v39 & 0xF8FF) == 0;
        BYTE2(v40[0]) = (v39 & 0xF8FF) == 0;
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v25 = *(_QWORD *)(v23 + 8);
      v24 = *(_QWORD *)(v23 + 16);
      LOBYTE(v40[0]) = 6;
      v17 = (unsigned __int8)v38[0];
      v18 = v21;
      *(_QWORD *)((char *)&v40[1] + 4) = v24;
      *(_QWORD *)((char *)v40 + 4) = v25;
      v27 = *(_QWORD *)(v23 + 24);
      v26 = *(_QWORD *)(v23 + 32);
      BYTE3(v40[0]) = v38[0];
      *(_QWORD *)((char *)&v40[3] + 4) = v26;
      *(_QWORD *)((char *)&v40[2] + 4) = v27;
      LODWORD(v27) = bswap32(*(_DWORD *)v23 & 0xF00F) >> 20;
      LODWORD(v41) = bswap32(*(_DWORD *)v23 & 0xFFFF0F00);
      BYTE4(v41) = v27;
    }
    else
    {
      if ( v8 != 64 )
        goto LABEL_41;
      v9 = coarse_with_offset;
      LODWORD(v44) = 0;
      v42 = 0;
      v43 = 0;
      v10 = rmnet_frag_header_ptr(v2, 0, 20, &v42);
      if ( !v10 )
        goto LABEL_41;
      v11 = *(_BYTE *)v10;
      if ( (*(_BYTE *)v10 & 0xFu) < 5 )
        goto LABEL_41;
      v12 = *(unsigned __int16 *)(v10 + 6);
      if ( (v12 & 0xFFFFFF3F) != 0 )
      {
        v14 = 1;
        BYTE1(v40[0]) = 1;
        v13 = (v12 & 0xFF1F) == 0;
        BYTE2(v40[0]) = (v12 & 0xFF1F) == 0;
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v15 = *(_DWORD *)(v10 + 12);
      v16 = *(_DWORD *)(v10 + 16);
      v17 = *(unsigned __int8 *)(v10 + 9);
      v18 = v9;
      v19 = 4 * (v11 & 0xFu);
      BYTE3(v40[0]) = *(_BYTE *)(v10 + 9);
      HIDWORD(v40[0]) = v15;
      HIDWORD(v40[2]) = v16;
      LOBYTE(v16) = *(_BYTE *)(v10 + 1);
      LOBYTE(v40[0]) = 4;
      BYTE4(v41) = v16;
    }
    if ( v14 && !v13 )
    {
      v14 = 1;
      goto LABEL_33;
    }
    if ( v17 == 17 || v17 == 6 )
    {
      v28 = v18;
      LODWORD(v42) = 0;
      v10 = rmnet_frag_header_ptr(v2, v19, 4, &v42);
      if ( v10 )
      {
        WORD2(v40[4]) = bswap32(*(unsigned __int16 *)v10) >> 16;
        HIWORD(v40[4]) = bswap32(*(unsigned __int16 *)(v10 + 2)) >> 16;
        v18 = v28;
        goto LABEL_33;
      }
LABEL_41:
      result = raw_spin_unlock_bh(&dl_activity_lock);
LABEL_42:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  else
  {
    if ( !a2 )
      goto LABEL_41;
    v20 = coarse_with_offset;
    v10 = aps_dissect_skb(a2, v40);
    if ( (_DWORD)v10 )
      goto LABEL_41;
    v14 = BYTE1(v40[0]);
    v13 = BYTE2(v40[0]);
    v18 = v20;
  }
LABEL_33:
  if ( v14 && !v13 )
    goto LABEL_41;
  v29 = next_activity_index;
  if ( (unsigned int)next_activity_index >= 0xB )
  {
    __break(0x5512u);
  }
  else if ( next_activity_index != 10 )
  {
    v30 = (__int64 *)((char *)&dl_activity_records + 56 * (unsigned int)next_activity_index);
    v31 = v40[4];
    v32 = v41;
    v30[4] = v40[3];
    v30[5] = v31;
    v33 = v40[2];
    v30[6] = v32;
    v34 = v40[0];
    v35 = v40[1];
    *v30 = v18;
    v30[1] = v34;
    if ( v29 <= 8 )
      v36 = v29 + 1;
    else
      v36 = 0;
    v30[2] = v35;
    v30[3] = v33;
    next_activity_index = v36;
    goto LABEL_41;
  }
  __break(1u);
  return aps_dissect_skb(v10, v19);
}
