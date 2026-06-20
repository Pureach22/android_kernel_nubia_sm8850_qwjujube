__int64 __fastcall ml_nlink_handle_mcc_links(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w20
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w5
  unsigned int v25; // w4
  char v26; // w21
  bool v27; // cc
  int v28; // w8
  int v29; // w8
  __int64 v30; // [xsp+0h] [xbp-80h]
  __int64 v31; // [xsp+8h] [xbp-78h]
  __int64 v32; // [xsp+18h] [xbp-68h] BYREF
  unsigned int v33; // [xsp+20h] [xbp-60h] BYREF
  unsigned __int8 v34[4]; // [xsp+24h] [xbp-5Ch] BYREF
  int v35; // [xsp+28h] [xbp-58h] BYREF
  char v36; // [xsp+2Ch] [xbp-54h]
  int v37; // [xsp+30h] [xbp-50h] BYREF
  char v38; // [xsp+34h] [xbp-4Ch]
  _QWORD v39[5]; // [xsp+38h] [xbp-48h] BYREF
  _QWORD v40[2]; // [xsp+60h] [xbp-20h] BYREF
  int v41; // [xsp+70h] [xbp-10h]
  __int64 v42; // [xsp+78h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v32 = 0;
  v38 = 0;
  v37 = 0;
  v41 = 0;
  v40[0] = 0;
  v40[1] = 0;
  v36 = 0;
  v35 = 0;
  memset(v39, 0, sizeof(v39));
  ml_nlink_get_link_info(
    a1,
    a2,
    0x12u,
    5u,
    v39,
    (unsigned int *)v40,
    (unsigned __int8 *)&v37,
    &v35,
    v34,
    (unsigned int *)&v32);
  v14 = v32;
  if ( (_DWORD)v32 )
  {
    a3[1] = v32;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AP removed link 0x%x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "ml_nlink_handle_mcc_links",
      v14);
  }
  result = ml_nlink_get_link_info(a1, a2, 0x11u, 5u, v39, (unsigned int *)v40, (unsigned __int8 *)&v37, &v35, v34, &v33);
  if ( v34[0] < 2u )
    goto LABEL_17;
  result = policy_mgr_is_ml_sta_links_in_mcc(a1, (__int64)v40, (__int64)&v37, (__int64)&v35, v34[0], (_DWORD *)&v32 + 1);
  v24 = HIDWORD(v32);
  if ( !HIDWORD(v32) )
  {
    if ( v14 )
      goto LABEL_16;
    goto LABEL_17;
  }
  v25 = 0;
  v26 = 0;
  while ( (v24 & 1) == 0 )
  {
LABEL_6:
    v27 = v24 > 1;
    ++v25;
    v24 >>= 1;
    if ( !v27 )
      goto LABEL_14;
  }
  if ( v25 < 0xF )
  {
    ++v26;
    goto LABEL_6;
  }
  result = qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: linkid invalid %d 0x%x",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "convert_link_bitmap_to_link_ids");
LABEL_14:
  if ( (v26 & 0xFE) != 0 )
  {
    v28 = HIDWORD(v32);
    *((_BYTE *)a3 + 8) = v26 - 1;
    a3[5] = v28;
    if ( v14 | v28 )
      goto LABEL_16;
  }
  else
  {
    v29 = HIDWORD(v32);
    *((_BYTE *)a3 + 8) = 0;
    if ( v14 | v29 )
    {
LABEL_16:
      LODWORD(v31) = a3[3];
      LODWORD(v30) = *((unsigned __int8 *)a3 + 4);
      result = qdf_trace_msg(
                 0x8Fu,
                 8u,
                 "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "ml_nlink_handle_mcc_links",
                 a3[1],
                 *a3,
                 *((unsigned __int8 *)a3 + 8),
                 a3[5],
                 v30,
                 v31,
                 a3[6]);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
