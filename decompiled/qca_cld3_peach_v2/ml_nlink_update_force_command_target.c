__int64 __fastcall ml_nlink_update_force_command_target(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 *a5,
        unsigned __int16 *a6,
        unsigned __int16 *a7)
{
  int v13; // w8
  int v14; // w20
  unsigned int v15; // w26
  int v16; // w27
  unsigned __int16 v17; // w25
  __int64 result; // x0
  int v19; // w9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w27
  unsigned int v29; // w28
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v39; // w8
  int v40; // w4
  int v41; // w5
  int v42; // w4
  int v43; // w5
  int v44; // [xsp+18h] [xbp-68h]
  unsigned int v45; // [xsp+1Ch] [xbp-64h]
  unsigned int v46; // [xsp+20h] [xbp-60h] BYREF
  char v47; // [xsp+27h] [xbp-59h] BYREF
  int v48; // [xsp+28h] [xbp-58h] BYREF
  char v49; // [xsp+2Ch] [xbp-54h]
  int v50; // [xsp+30h] [xbp-50h] BYREF
  char v51; // [xsp+34h] [xbp-4Ch]
  __int64 v52; // [xsp+38h] [xbp-48h] BYREF
  __int64 v53; // [xsp+40h] [xbp-40h]
  __int64 v54; // [xsp+48h] [xbp-38h]
  __int64 v55; // [xsp+50h] [xbp-30h]
  __int64 v56; // [xsp+58h] [xbp-28h]
  __int64 v57; // [xsp+60h] [xbp-20h] BYREF
  __int64 v58; // [xsp+68h] [xbp-18h]
  int v59; // [xsp+70h] [xbp-10h]
  __int64 v60; // [xsp+78h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 == 19 && a5 )
  {
    v13 = *a5 << 30;
    goto LABEL_4;
  }
  v13 = 0;
  if ( a4 > 0x18 || ((1 << a4) & 0x1204410) == 0 )
  {
LABEL_4:
    v14 = v13 | 8;
    if ( a4 > 0x18 )
      goto LABEL_11;
    goto LABEL_9;
  }
  v14 = 16;
LABEL_9:
  if ( ((1 << a4) & 0x120CC90) != 0 )
    v14 |= 0x40u;
LABEL_11:
  v15 = a7[1];
  if ( a7[1] )
    goto LABEL_16;
  if ( *((_BYTE *)a7 + 8) || *a7 || *((_BYTE *)a7 + 4) || !a6[1] && !*((_BYTE *)a6 + 8) && !*a6 && !*((_BYTE *)a6 + 4) )
  {
    v15 = 0;
    goto LABEL_16;
  }
  if ( (ml_nlink_allow_conc(a1, a2) & 1) == 0 )
  {
    result = 4;
    goto LABEL_54;
  }
  result = policy_mgr_mlo_sta_set_nlink(a1, *(unsigned __int8 *)(a2 + 168), a3, 5u, 0, 0, 0, v14 & 0xFFFFFFF7);
  if ( (v14 & 0x10) != 0 && (_DWORD)result == 24 )
    result = policy_mgr_wait_for_set_link_update(a1);
  if ( !(_DWORD)result )
  {
    v15 = a7[1];
LABEL_16:
    v16 = a6[1];
    v17 = *a6;
    if ( v15 == v16 )
    {
      result = 0;
      v19 = 0;
      goto LABEL_23;
    }
    v46 = 0;
    v51 = 0;
    v50 = 0;
    v59 = 0;
    v57 = 0;
    v58 = 0;
    v49 = 0;
    v48 = 0;
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    v52 = 0;
    ml_nlink_get_link_info(a1, a2, 5u, 5u, &v52, (unsigned int *)&v57, (unsigned __int8 *)&v50, &v48, &v47, &v46);
    if ( (v46 & ~v15) != 0 )
    {
      if ( (policy_mgr_allow_non_force_link_bitmap(a1, a2, (unsigned __int16)v16 & (unsigned __int16)~(_WORD)v15, v15)
          & 1) != 0 )
      {
        LOWORD(v15) = a7[1];
        result = 0;
        v19 = 1;
        goto LABEL_23;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: not allow - no active link after force inactive 0x%x",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "ml_nlink_sta_inactivity_allowed_with_quiet",
        v15);
    }
    v19 = 0;
    result = 11;
    LOWORD(v15) = v16;
LABEL_23:
    v28 = *a7;
    if ( v28 != *a6 )
    {
      v44 = v19;
      v45 = a3;
      v29 = a7[1];
      v46 = 0;
      v51 = 0;
      v50 = 0;
      v59 = 0;
      v57 = 0;
      v58 = 0;
      v49 = 0;
      v48 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v52 = 0;
      ml_nlink_get_link_info(a1, a2, 5u, 5u, &v52, (unsigned int *)&v57, (unsigned __int8 *)&v50, &v48, &v47, &v46);
      if ( (v46 & ~v29) != 0 )
      {
        if ( (policy_mgr_allow_non_force_link_bitmap(a1, a2, v28, v29) & 1) != 0 )
        {
          a3 = v45;
          v17 = *a7;
          goto LABEL_37;
        }
        a3 = v45;
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: not allow - no active link after force inactive 0x%x",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "ml_nlink_sta_inactivity_allowed_with_quiet",
          v29);
        a3 = v45;
      }
      result = 11;
      v19 = v44;
    }
    if ( a4 == 18 && (_DWORD)result == 0 )
      v39 = 1;
    else
      v39 = v19;
    if ( v39 != 1 )
    {
LABEL_40:
      if ( (_DWORD)result == 11 || !(_DWORD)result )
      {
        v40 = *((unsigned __int8 *)a7 + 8);
        v41 = a7[5];
        if ( v40 == *((unsigned __int8 *)a6 + 8) && v41 == a6[5] )
          goto LABEL_48;
        result = policy_mgr_mlo_sta_set_nlink(a1, *(unsigned __int8 *)(a2 + 168), a3, 4u, v40, v41, 0, v14 | 4u);
        if ( (v14 & 0x10) != 0 && (_DWORD)result == 24 )
          result = policy_mgr_wait_for_set_link_update(a1);
        if ( !(_DWORD)result )
        {
LABEL_48:
          v42 = *((unsigned __int8 *)a7 + 4);
          v43 = a7[3];
          if ( v42 == *((unsigned __int8 *)a6 + 4) && v43 == a6[3] )
          {
            result = 0;
          }
          else
          {
            result = policy_mgr_mlo_sta_set_nlink(a1, *(unsigned __int8 *)(a2 + 168), a3, 3u, v42, v43, 0, v14 | 4u);
            if ( (v14 & 0x10) != 0 && (_DWORD)result == 24 )
              result = policy_mgr_wait_for_set_link_update(a1);
          }
        }
      }
      goto LABEL_54;
    }
LABEL_37:
    result = policy_mgr_mlo_sta_set_nlink(a1, *(unsigned __int8 *)(a2 + 168), a3, 6u, 0, v17, v15, v14 | 3u);
    if ( (v14 & 0x10) != 0 && (_DWORD)result == 24 )
      result = policy_mgr_wait_for_set_link_update(a1);
    goto LABEL_40;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
