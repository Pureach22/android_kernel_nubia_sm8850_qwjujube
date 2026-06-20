__int64 __fastcall policy_mgr_dump_current_concurrency_three_connection(__int64 a1, const char *a2)
{
  int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w20
  size_t v14; // x0
  unsigned __int64 v15; // x21
  bool v16; // cf
  __int64 v17; // x10
  size_t v18; // x9
  const char *v19; // x1
  int v20; // w21
  unsigned int v21; // w22
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  char is_mlo_vdev; // w22
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  int v43; // w21
  size_t v44; // x2
  char *v45; // x0
  __int64 v46; // x22
  size_t v47; // x20
  size_t v48; // x0
  unsigned __int64 v49; // x22
  __int64 v50; // x23
  size_t v51; // x2
  unsigned __int64 v52; // x20
  size_t v53; // x2
  char *v54; // x0
  __int64 v55; // x22
  size_t v56; // x2
  __int64 v57; // x0
  __int64 v58; // x1
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  char v60; // [xsp+10h] [xbp-10h]
  __int64 v61; // [xsp+18h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = qword_8D4F30;
  v60 = 0;
  *(_QWORD *)string = 0;
  v5 = scnprintf(string, 9, "(vdev %d)", qword_8D4F48);
  if ( v4 > 2 )
  {
    if ( v4 <= 4 )
    {
      if ( v4 == 3 )
      {
        v13 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
        v14 = strnlen(a2, 0x12Cu);
        if ( v14 != -1 )
        {
          v15 = v14 + 7;
          if ( v14 <= 0x12B )
          {
            v16 = v15 >= 0x12C;
            v17 = 7;
            v18 = 299 - v14;
            v19 = "+P2P GO";
            goto LABEL_31;
          }
          goto LABEL_38;
        }
      }
      else
      {
        v13 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
        v14 = strnlen(a2, 0x12Cu);
        if ( v14 != -1 )
        {
          v15 = v14 + 4;
          if ( v14 <= 0x12B )
          {
            v16 = v15 >= 0x12C;
            v17 = 4;
            v18 = 299 - v14;
            v19 = "+NDI";
LABEL_31:
            if ( v16 )
              v44 = v18;
            else
              v44 = v17;
            v45 = (char *)&a2[v14];
            if ( v16 )
              v46 = 299;
            else
              v46 = v15;
            memcpy(v45, v19, v44);
            a2[v46] = 0;
            goto LABEL_38;
          }
          goto LABEL_38;
        }
      }
      goto LABEL_66;
    }
    if ( v4 == 5 )
    {
      v13 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
      v14 = strnlen(a2, 0x12Cu);
      if ( v14 != -1 )
      {
        v15 = v14 + 9;
        if ( v14 <= 0x12B )
        {
          v16 = v15 >= 0x12C;
          v17 = 9;
          v18 = 299 - v14;
          v19 = "+NAN Disc";
          goto LABEL_31;
        }
        goto LABEL_38;
      }
      goto LABEL_66;
    }
    if ( v4 == 6 )
    {
      v13 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
      v14 = strnlen(a2, 0x12Cu);
      if ( v14 != -1 )
      {
        v15 = v14 + 7;
        if ( v14 <= 0x12B )
        {
          v16 = v15 >= 0x12C;
          v17 = 7;
          v18 = 299 - v14;
          v19 = "+LT_SAP";
          goto LABEL_31;
        }
        goto LABEL_38;
      }
      goto LABEL_66;
    }
    goto LABEL_21;
  }
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v13 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
      v14 = strnlen(a2, 0x12Cu);
      if ( v14 != -1 )
      {
        v15 = v14 + 4;
        if ( v14 <= 0x12B )
        {
          v16 = v15 >= 0x12C;
          v17 = 4;
          v18 = 299 - v14;
          v19 = "+SAP";
          goto LABEL_31;
        }
        goto LABEL_38;
      }
      goto LABEL_66;
    }
    if ( v4 == 2 )
    {
      v13 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
      v14 = strnlen(a2, 0x12Cu);
      if ( v14 != -1 )
      {
        v15 = v14 + 8;
        if ( v14 <= 0x12B )
        {
          v16 = v15 >= 0x12C;
          v17 = 8;
          v18 = 299 - v14;
          v19 = "+P2P CLI";
          goto LABEL_31;
        }
LABEL_38:
        v43 = v13 + v15;
        goto LABEL_39;
      }
LABEL_66:
      v56 = v14 + 1;
      goto LABEL_67;
    }
LABEL_21:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unexpected mode %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_dump_current_concurrency_three_connection",
      (unsigned int)v4);
    v43 = 0;
    goto LABEL_39;
  }
  v20 = policy_mgr_dump_current_concurrency_two_connection(a1, a2);
  v21 = qword_8D4F48;
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned int)qword_8D4F48,
          24);
  if ( v22 )
  {
    v31 = v22;
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v22, v23, v24, v25, v26, v27, v28, v29, v30);
    wlan_objmgr_vdev_release_ref(v31, 0x18u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
    if ( (is_mlo_vdev & 1) != 0 )
    {
      result = 0;
LABEL_51:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: invalid vdev for id %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "policy_mgr_is_ml_vdev",
      v21);
  }
  v14 = strnlen(a2, 0x12Cu);
  if ( v14 == -1 )
    goto LABEL_66;
  v52 = v14 + 4;
  if ( v14 <= 0x12B )
  {
    if ( v52 >= 0x12C )
      v53 = 299 - v14;
    else
      v53 = 4;
    v54 = (char *)&a2[v14];
    if ( v52 >= 0x12C )
      v55 = 299;
    else
      v55 = v52;
    memcpy(v54, "+STA", v53);
    a2[v55] = 0;
  }
  v43 = v20 + v52;
LABEL_39:
  v47 = strnlen(a2, 0x12Cu);
  if ( v47 != -1 )
  {
    v48 = strnlen(string, 9u);
    if ( v48 >= 0xA )
    {
      v48 = _fortify_panic(2, 9, v48 + 1);
    }
    else if ( v48 != 9 )
    {
      v49 = v48 + v47;
      if ( v47 <= 0x12B )
      {
        if ( v49 >= 0x12C )
          v50 = 299;
        else
          v50 = v48 + v47;
        if ( v49 >= 0x12C )
          v51 = 299 - v47;
        else
          v51 = v48;
        memcpy((void *)&a2[v47], string, v51);
        a2[v50] = 0;
      }
      result = (unsigned int)(v43 + v49);
      goto LABEL_51;
    }
    v14 = _fortify_panic(4, 9, v48 + 1);
    goto LABEL_66;
  }
  v56 = 0;
LABEL_67:
  v57 = _fortify_panic(2, -1, v56);
  return policy_mgr_dump_dbs_concurrency(v57, v58);
}
