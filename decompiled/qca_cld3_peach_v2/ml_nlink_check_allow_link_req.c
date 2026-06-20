__int64 __fastcall ml_nlink_check_allow_link_req(__int64 a1, __int64 a2, unsigned __int16 *a3, __int64 a4)
{
  unsigned int v8; // w23
  int v9; // w24
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w23
  unsigned int v19; // w21
  __int64 result; // x0
  __int64 v21; // x4
  unsigned __int16 v22; // w2
  char v23; // w8
  unsigned int v24; // [xsp+10h] [xbp-60h] BYREF
  char v25; // [xsp+17h] [xbp-59h] BYREF
  int v26; // [xsp+18h] [xbp-58h] BYREF
  char v27; // [xsp+1Ch] [xbp-54h]
  int v28; // [xsp+20h] [xbp-50h] BYREF
  char v29; // [xsp+24h] [xbp-4Ch]
  __int64 v30; // [xsp+28h] [xbp-48h] BYREF
  __int64 v31; // [xsp+30h] [xbp-40h]
  __int64 v32; // [xsp+38h] [xbp-38h]
  __int64 v33; // [xsp+40h] [xbp-30h]
  __int64 v34; // [xsp+48h] [xbp-28h]
  __int64 v35; // [xsp+50h] [xbp-20h] BYREF
  __int64 v36; // [xsp+58h] [xbp-18h]
  int v37; // [xsp+60h] [xbp-10h]
  __int64 v38; // [xsp+68h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int16 *)(a4 + 10);
  if ( !*(_WORD *)(a4 + 10) )
  {
    if ( !*(_BYTE *)(a4 + 16)
      && !*(_WORD *)(a4 + 8)
      && !*(_BYTE *)(a4 + 12)
      && ((v22 = a3[1]) != 0 || *((_BYTE *)a3 + 8) || *a3 || *((_BYTE *)a3 + 4)) )
    {
      v23 = ml_nlink_allow_conc(a1, a2, v22, 0);
      result = 0;
      if ( (v23 & 1) == 0 )
        goto LABEL_17;
      v8 = *(unsigned __int16 *)(a4 + 10);
    }
    else
    {
      v8 = 0;
    }
  }
  v9 = a3[1];
  if ( v8 != v9 )
  {
    v24 = 0;
    v29 = 0;
    v28 = 0;
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v27 = 0;
    v26 = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v30 = 0;
    ml_nlink_get_link_info(a1, a2, 5u, 5u, &v30, (unsigned int *)&v35, (unsigned __int8 *)&v28, &v26, &v25, &v24);
    if ( (v24 & ~v8) == 0 )
    {
      v21 = v8;
      goto LABEL_15;
    }
    if ( (policy_mgr_allow_non_force_link_bitmap(a1, a2, (unsigned __int16)v9 & (unsigned __int16)~(_WORD)v8, v8) & 1) == 0 )
      goto LABEL_16;
  }
  v18 = *(unsigned __int16 *)(a4 + 8);
  if ( v18 != *a3 )
  {
    v19 = *(unsigned __int16 *)(a4 + 10);
    v24 = 0;
    v29 = 0;
    v28 = 0;
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v27 = 0;
    v26 = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v30 = 0;
    ml_nlink_get_link_info(a1, a2, 5u, 5u, &v30, (unsigned int *)&v35, (unsigned __int8 *)&v28, &v26, &v25, &v24);
    if ( (v24 & ~v19) != 0 )
    {
      if ( (policy_mgr_allow_non_force_link_bitmap(a1, a2, v18, v19) & 1) != 0 )
        goto LABEL_12;
LABEL_16:
      result = 0;
      goto LABEL_17;
    }
    v21 = v19;
LABEL_15:
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: not allow - no active link after force inactive 0x%x",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "ml_nlink_sta_inactivity_allowed_with_quiet",
      v21);
    goto LABEL_16;
  }
LABEL_12:
  result = 1;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
