__int64 __fastcall policy_mgr_dump_current_concurrency_one_connection(__int64 a1, const char *a2)
{
  int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  size_t v13; // x0
  unsigned __int64 v14; // x21
  bool v15; // cf
  __int64 v16; // x10
  size_t v17; // x9
  __int64 v18; // x20
  const char *v19; // x1
  unsigned int v20; // w20
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  char is_mlo_vdev; // w21
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  size_t v42; // x2
  size_t v43; // x20
  size_t v44; // x0
  unsigned __int64 v45; // x22
  __int64 v46; // x23
  size_t v47; // x2
  size_t v48; // x2
  __int64 v49; // x0
  __int64 v50; // x1
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  char v52; // [xsp+10h] [xbp-10h]
  __int64 v53; // [xsp+18h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = pm_conc_connection_list;
  v52 = 0;
  *(_QWORD *)string = 0;
  v5 = scnprintf(string, 9, "(vdev %d)", qword_8D4F00);
  if ( v4 > 2 )
  {
    if ( v4 <= 4 )
    {
      if ( v4 == 3 )
      {
        v13 = strnlen(a2, 0x12Cu);
        if ( v13 != -1 )
        {
          v14 = v13 + 6;
          if ( v13 > 0x12B )
            goto LABEL_60;
          v15 = v14 >= 0x12C;
          v16 = 6;
          v17 = 299 - v13;
          if ( v14 >= 0x12C )
            v18 = 299;
          else
            v18 = v13 + 6;
          v19 = "P2P GO";
          goto LABEL_56;
        }
      }
      else
      {
        v13 = strnlen(a2, 0x12Cu);
        if ( v13 != -1 )
        {
          v14 = v13 + 3;
          if ( v13 > 0x12B )
            goto LABEL_60;
          v15 = v14 >= 0x12C;
          v16 = 3;
          v17 = 299 - v13;
          if ( v14 >= 0x12C )
            v18 = 299;
          else
            v18 = v13 + 3;
          v19 = "NDI";
          goto LABEL_56;
        }
      }
LABEL_76:
      v48 = v13 + 1;
      goto LABEL_77;
    }
    if ( v4 == 5 )
    {
      v13 = strnlen(a2, 0x12Cu);
      if ( v13 != -1 )
      {
        v14 = v13 + 8;
        if ( v13 > 0x12B )
          goto LABEL_60;
        v15 = v14 >= 0x12C;
        v16 = 8;
        v17 = 299 - v13;
        if ( v14 >= 0x12C )
          v18 = 299;
        else
          v18 = v13 + 8;
        v19 = "NAN DISC";
        goto LABEL_56;
      }
      goto LABEL_76;
    }
    if ( v4 == 6 )
    {
      v13 = strnlen(a2, 0x12Cu);
      if ( v13 != -1 )
      {
        v14 = v13 + 6;
        if ( v13 > 0x12B )
          goto LABEL_60;
        v15 = v14 >= 0x12C;
        v16 = 6;
        v17 = 299 - v13;
        if ( v14 >= 0x12C )
          v18 = 299;
        else
          v18 = v13 + 6;
        v19 = "LT_SAP";
        goto LABEL_56;
      }
      goto LABEL_76;
    }
    goto LABEL_30;
  }
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v13 = strnlen(a2, 0x12Cu);
      if ( v13 != -1 )
      {
        v14 = v13 + 3;
        if ( v13 > 0x12B )
          goto LABEL_60;
        v15 = v14 >= 0x12C;
        v16 = 3;
        v17 = 299 - v13;
        if ( v14 >= 0x12C )
          v18 = 299;
        else
          v18 = v13 + 3;
        v19 = "SAP";
        goto LABEL_56;
      }
      goto LABEL_76;
    }
    if ( v4 == 2 )
    {
      v13 = strnlen(a2, 0x12Cu);
      if ( v13 != -1 )
      {
        v14 = v13 + 7;
        if ( v13 > 0x12B )
          goto LABEL_60;
        v15 = v14 >= 0x12C;
        v16 = 7;
        v17 = 299 - v13;
        if ( v14 >= 0x12C )
          v18 = 299;
        else
          v18 = v13 + 7;
        v19 = "P2P CLI";
        goto LABEL_56;
      }
      goto LABEL_76;
    }
LABEL_30:
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
      "policy_mgr_dump_current_concurrency_one_connection",
      (unsigned int)v4);
    LODWORD(v14) = 0;
    goto LABEL_60;
  }
  v20 = qword_8D4F00;
  v21 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, double))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned int)qword_8D4F00,
          24,
          v5);
  if ( v21 )
  {
    v30 = v21;
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v21, v22, v23, v24, v25, v26, v27, v28, v29);
    wlan_objmgr_vdev_release_ref(v30, 0x18u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    if ( (is_mlo_vdev & 1) != 0 )
    {
      result = 0;
LABEL_72:
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
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "policy_mgr_is_ml_vdev",
      v20);
  }
  v13 = strnlen(a2, 0x12Cu);
  if ( v13 == -1 )
    goto LABEL_76;
  v14 = v13 + 3;
  if ( v13 <= 0x12B )
  {
    v15 = v14 >= 0x12C;
    v16 = 3;
    v17 = 299 - v13;
    if ( v14 >= 0x12C )
      v18 = 299;
    else
      v18 = v13 + 3;
    v19 = "STA";
LABEL_56:
    if ( v15 )
      v42 = v17;
    else
      v42 = v16;
    memcpy((void *)&a2[v13], v19, v42);
    a2[v18] = 0;
  }
LABEL_60:
  v43 = strnlen(a2, 0x12Cu);
  if ( v43 != -1 )
  {
    v44 = strnlen(string, 9u);
    if ( v44 >= 0xA )
    {
      v44 = _fortify_panic(2, 9, v44 + 1);
    }
    else if ( v44 != 9 )
    {
      v45 = v44 + v43;
      if ( v43 <= 0x12B )
      {
        if ( v45 >= 0x12C )
          v46 = 299;
        else
          v46 = v44 + v43;
        if ( v45 >= 0x12C )
          v47 = 299 - v43;
        else
          v47 = v44;
        memcpy((void *)&a2[v43], string, v47);
        a2[v46] = 0;
      }
      result = (unsigned int)(v45 + v14);
      goto LABEL_72;
    }
    v13 = _fortify_panic(4, 9, v44 + 1);
    goto LABEL_76;
  }
  v48 = 0;
LABEL_77:
  v49 = _fortify_panic(2, -1, v48);
  return policy_mgr_dump_current_concurrency_two_connection(v49, v50);
}
