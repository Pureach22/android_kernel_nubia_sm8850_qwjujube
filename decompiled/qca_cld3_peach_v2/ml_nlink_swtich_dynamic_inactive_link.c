__int64 __fastcall ml_nlink_swtich_dynamic_inactive_link(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w21
  const char *v11; // x2
  __int64 v12; // x4
  __int64 result; // x0
  unsigned __int8 link_switch_last_link_id; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  __int16 v26; // w24
  int v27; // w10
  unsigned int v28; // w23
  unsigned int v29; // w4
  unsigned __int64 v30; // x22
  __int16 v31; // w20
  unsigned int v32; // w5
  bool v33; // cc
  unsigned int v34; // w21
  int v35; // w25
  unsigned int v36; // w5
  unsigned int v37; // w4
  unsigned __int64 v38; // x22
  int v39; // w22
  __int16 v40; // w20
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w22
  __int64 vdev_by_link_id; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w23
  __int64 v61; // x24
  __int16 v62; // w26
  __int64 v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // [xsp+18h] [xbp-78h] BYREF
  __int64 v82; // [xsp+20h] [xbp-70h]
  __int16 v83; // [xsp+28h] [xbp-68h]
  _BYTE v84[4]; // [xsp+30h] [xbp-60h] BYREF
  int v85; // [xsp+34h] [xbp-5Ch] BYREF
  char v86; // [xsp+38h] [xbp-58h]
  int v87; // [xsp+3Ch] [xbp-54h] BYREF
  char v88; // [xsp+40h] [xbp-50h]
  int v89; // [xsp+44h] [xbp-4Ch] BYREF
  __int128 v90; // [xsp+48h] [xbp-48h] BYREF
  __int64 v91; // [xsp+58h] [xbp-38h]
  __int64 v92; // [xsp+60h] [xbp-30h]
  __int64 v93; // [xsp+68h] [xbp-28h]
  __int64 v94; // [xsp+70h] [xbp-20h] BYREF
  __int64 v95; // [xsp+78h] [xbp-18h]
  int v96; // [xsp+80h] [xbp-10h]
  __int64 v97; // [xsp+88h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a2 + 93);
  v83 = 0;
  v81 = 0;
  v82 = 0;
  if ( v10 >= 0xF )
  {
    v11 = "%s: invalid link id %d";
    v12 = v10;
    goto LABEL_3;
  }
  link_switch_last_link_id = mlo_mgr_get_link_switch_last_link_id(a2);
  v89 = 0;
  v88 = 0;
  v87 = 0;
  v96 = 0;
  v94 = 0;
  v95 = 0;
  v86 = 0;
  v85 = 0;
  v92 = 0;
  v93 = 0;
  v91 = 0;
  v90 = 0u;
  ml_nlink_get_link_info(a1, a2, 1, 5, (int)&v90, (int)&v94, (int)&v87, (int)&v85, (__int64)v84);
  v25 = *(_QWORD *)(a2 + 1360);
  v26 = v89;
  if ( v25 && *(_QWORD *)(v25 + 2224) )
  {
    qdf_mutex_acquire(v25 + 1656);
    qdf_mem_copy(&v81, (const void *)(*(_QWORD *)(v25 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v25 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ml_nlink_get_curr_force_state");
  }
  *(_QWORD *)((char *)&v90 + 7) = 0;
  *(_QWORD *)&v90 = 0;
  v84[0] = 0;
  v87 = 0;
  BYTE2(v85) = 0;
  LOWORD(v85) = 0;
  LODWORD(v95) = 0;
  v94 = 0;
  BYTE2(v89) = 0;
  LOWORD(v89) = 0;
  ml_nlink_get_standby_link_info(a2, 0x10u, 3u, (__int64)&v94, (__int64)&v85, (__int64)&v89, v84, &v87);
  v27 = 1 << v10;
  v28 = v87 & ~(1 << v10) & WORD1(v82);
  if ( ((1 << v10) & WORD2(v82)) == 0
    || ((unsigned __int16)v27 & WORD1(v82)) == 0
    || !v28
    || ((unsigned __int16)v28 & WORD2(v82)) != 0 )
  {
    result = 0;
    if ( !WORD2(v82) )
      goto LABEL_36;
    if ( link_switch_last_link_id == 0xFF )
      goto LABEL_36;
    v34 = link_switch_last_link_id;
    result = 0;
    v35 = 1 << link_switch_last_link_id;
    if ( (v28 & (1 << link_switch_last_link_id)) == 0
      || ((unsigned __int16)v35 & WORD2(v82)) != 0
      || ((unsigned __int16)v35 & WORD1(v82)) == 0 )
    {
      goto LABEL_36;
    }
    v36 = v26 & ~(v28 | WORD1(v81)) & WORD2(v82);
    if ( ((unsigned __int16)(v26 & ~(v28 | WORD1(v81))) & WORD2(v82)) == 0 )
      goto LABEL_35;
    v37 = 0;
    v38 = 0;
    while ( 1 )
    {
      if ( (v36 & 1) != 0 )
      {
        if ( v37 >= 0xF )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: linkid invalid %d 0x%x",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "convert_link_bitmap_to_link_ids");
LABEL_41:
          if ( (_BYTE)v38 )
          {
            v50 = (unsigned __int8)v90;
            vdev_by_link_id = mlo_get_vdev_by_link_id(a2, v90, 0x5Au, a3, a4, a5, a6, a7, a8, a9, a10);
            if ( vdev_by_link_id )
            {
              v60 = *(unsigned __int8 *)(vdev_by_link_id + 168);
              v61 = vdev_by_link_id;
              v62 = WORD2(v82) & ~(unsigned __int16)(1 << v50);
              v63 = qdf_trace_msg(
                      0x8Fu,
                      8u,
                      "%s: move out link id %d from dynamic inactive, add standby link id %d",
                      v52,
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      "ml_nlink_swtich_dynamic_inactive_link",
                      v50,
                      v34);
              ml_nlink_set_dynamic_inactive_links(v64, v65, v66, v67, v68, v69, v70, v71, v63, a2, v62 | v35);
              policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, v60);
              wlan_objmgr_vdev_release_ref(v61, 0x5Au, v72, v73, v74, v75, v76, v77, v78, v79, v80);
            }
            else
            {
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: links vdev not found for link id %d",
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                "ml_nlink_swtich_dynamic_inactive_link",
                v50);
            }
          }
LABEL_35:
          result = 0;
          goto LABEL_36;
        }
        if ( v38 >= 0xF )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: linkid buff overflow 0x%x",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "convert_link_bitmap_to_link_ids",
            v36);
          goto LABEL_41;
        }
        *((_BYTE *)&v90 + v38++) = v37;
      }
      v33 = v36 > 1;
      ++v37;
      v36 >>= 1;
      if ( !v33 )
        goto LABEL_41;
    }
  }
  v29 = 0;
  v30 = 0;
  v31 = ~(_WORD)v27;
  v32 = v87 & ~(1 << v10) & WORD1(v82);
  while ( 1 )
  {
    if ( (v32 & 1) == 0 )
      goto LABEL_13;
    if ( v29 >= 0xF )
      break;
    if ( v30 >= 0xF )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: linkid buff overflow 0x%x",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "convert_link_bitmap_to_link_ids",
        v32);
      if ( !(_BYTE)v30 )
        goto LABEL_38;
LABEL_34:
      v39 = 1 << v90;
      v40 = WORD2(v82) & v31;
      v41 = qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: move out vdev %d link id %d from dynamic inactive, add standby link id %d",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              "ml_nlink_swtich_dynamic_inactive_link",
              *(unsigned __int8 *)(a2 + 168),
              v10);
      ml_nlink_set_dynamic_inactive_links(v42, v43, v44, v45, v46, v47, v48, v49, v41, a2, v39 | v40);
      goto LABEL_35;
    }
    *((_BYTE *)&v90 + v30++) = v29;
LABEL_13:
    v33 = v32 > 1;
    ++v29;
    v32 >>= 1;
    if ( !v33 )
      goto LABEL_33;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: linkid invalid %d 0x%x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "convert_link_bitmap_to_link_ids");
LABEL_33:
  if ( (_BYTE)v30 )
    goto LABEL_34;
LABEL_38:
  v11 = "%s: unexpected 0 link ids for bitmap 0x%x";
  v12 = v28;
LABEL_3:
  qdf_trace_msg(0x8Fu, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "ml_nlink_swtich_dynamic_inactive_link", v12);
  result = 4;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
