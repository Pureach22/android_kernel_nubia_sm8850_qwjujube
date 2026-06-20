__int64 __fastcall policy_mgr_update_dynamic_inactive_bitmap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w8
  unsigned int v18; // w23
  unsigned int v19; // w22
  int v20; // w27
  int standby_link_bitmap; // w26
  int v22; // w25
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  unsigned int v27; // w8
  int v28; // w24
  unsigned int v29; // w26
  __int64 v30; // x9
  unsigned int v31; // w8
  unsigned int v32; // w11
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x10
  char v35; // w8
  unsigned __int64 v36; // x9
  unsigned int v37; // w24
  __int64 v38; // x9
  int v39; // w11
  int v40; // w12
  __int64 v41; // x9
  __int64 v42; // x13
  char *v43; // x13
  unsigned __int64 v44; // x15
  char v45; // w16
  char v46; // t1
  unsigned __int64 v47; // x10
  char v48; // w13
  __int64 v49; // [xsp+10h] [xbp-40h] BYREF
  __int64 v50; // [xsp+18h] [xbp-38h]
  __int16 v51; // [xsp+20h] [xbp-30h]
  _QWORD v52[5]; // [xsp+28h] [xbp-28h] BYREF

  v52[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v52, 0, 30);
  v51 = 0;
  v49 = 0;
  v50 = 0;
  result = ml_nlink_get_curr_force_state(a1, a2, &v49);
  v17 = *(_DWORD *)(a3 + 32);
  if ( v17 > 6 )
    goto LABEL_41;
  if ( ((1 << v17) & 0x6E) != 0 )
  {
    if ( WORD2(v50) )
      goto LABEL_4;
LABEL_41:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v17 != 4 )
    goto LABEL_41;
  if ( (*(_BYTE *)(a3 + 102) & 1) == 0 )
  {
    if ( WORD2(v50) )
    {
      v37 = 0;
      v27 = 0;
      v18 = 0;
      v19 = 0;
LABEL_40:
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: inactive link num %d bitmap 0x%x force inactive 0x%x curr 0x%x dyn links 0x%x num %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "policy_mgr_update_dynamic_inactive_bitmap",
        v18,
        v19,
        *(unsigned int *)(a4 + 44),
        *(unsigned int *)(a4 + 48),
        v37,
        v27);
      result = ml_nlink_set_dynamic_inactive_links(a1, a2, v37);
      goto LABEL_41;
    }
    goto LABEL_41;
  }
LABEL_4:
  v18 = (unsigned __int8)v50;
  v19 = WORD1(v50);
  if ( !(_BYTE)v50 )
  {
    v37 = 0;
    v27 = 0;
    goto LABEL_40;
  }
  v20 = (unsigned __int16)(WORD1(v49) & WORD1(v50));
  standby_link_bitmap = ml_nlink_get_standby_link_bitmap(a1, a2);
  v22 = standby_link_bitmap & v20;
  v23 = ml_nlink_convert_link_bitmap_to_ids(standby_link_bitmap & (unsigned int)v20, 30, v52);
  v27 = (unsigned __int8)v23;
  v28 = v23;
  if ( (unsigned __int8)v23 < v18 && (unsigned __int8)v23 < 0x1Eu )
  {
    v23 = ml_nlink_convert_link_bitmap_to_ids(
            v22 ^ (unsigned int)v20,
            (unsigned int)(30 - v23),
            (char *)v52 + (unsigned __int8)v23);
    v28 += v23;
    v22 = v20;
    v27 = (unsigned __int8)v28;
  }
  if ( v27 < v18 && v27 <= 0x1D )
  {
    v29 = standby_link_bitmap & v19;
    v23 = ml_nlink_convert_link_bitmap_to_ids(v29, (unsigned int)(30 - v28), (char *)v52 + v27);
    v28 += v23;
    v22 |= v29;
    v27 = (unsigned __int8)v28;
  }
  if ( v27 < v18 && v27 <= 0x1D )
  {
    v23 = ml_nlink_convert_link_bitmap_to_ids(
            *(_DWORD *)(a4 + 48) & ~v22 & v19,
            (unsigned int)(30 - v28),
            (char *)v52 + v27);
    v27 = (unsigned __int8)(v23 + v28);
    if ( !((_BYTE)v23 + (_BYTE)v28) )
    {
      v37 = 0;
      goto LABEL_40;
    }
  }
  v30 = v27;
  v31 = v27 - 1;
  v32 = (unsigned __int8)(v18 - 1);
  v33 = v30 - 1;
  v34 = (unsigned __int8)(v18 - 1);
  if ( v31 < v32 )
    v32 = v31;
  if ( v33 >= v34 )
    v35 = v18 - 1;
  else
    v35 = v33;
  if ( v32 <= 0x1D )
  {
    if ( v33 < v34 )
      v34 = v33;
    if ( v34 >= 2 )
    {
      v38 = 30;
      if ( v34 < 0x1E )
        v38 = v34;
      v39 = 0;
      v40 = 0;
      v41 = v38 + 1;
      v42 = v41 & 1;
      if ( (v41 & 1) == 0 )
        v42 = 2;
      v36 = v41 - v42;
      v43 = (char *)v52 + 1;
      v44 = v36;
      do
      {
        v45 = *(v43 - 1);
        v46 = *v43;
        v43 += 2;
        v44 -= 2LL;
        v39 |= 1 << v45;
        v40 |= 1 << v46;
      }
      while ( v44 );
      v37 = v40 | v39;
    }
    else
    {
      v36 = 0;
      v37 = 0;
    }
    v47 = v34 + 1;
    do
    {
      if ( v36 > 0x1D )
        __break(1u);
      v48 = *((_BYTE *)v52 + v36++);
      v37 |= 1 << v48;
    }
    while ( v47 != v36 );
    v27 = (unsigned __int8)(v35 + 1);
    goto LABEL_40;
  }
  __break(0x5512u);
  return policy_mgr_handle_vdev_active_inactive_resp(v23, v24, v25, v26);
}
