__int64 __fastcall policy_mgr_dump_current_concurrency_one_connection(const char *a1)
{
  int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  size_t v11; // x0
  unsigned __int64 v12; // x21
  bool v13; // cf
  __int64 v14; // x10
  size_t v15; // x9
  __int64 v16; // x20
  const char *v17; // x1
  size_t v18; // x2
  size_t v19; // x20
  size_t v20; // x0
  unsigned __int64 v21; // x22
  __int64 v22; // x23
  size_t v23; // x2
  size_t v25; // x2
  __int64 v26; // x0
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  char v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = pm_conc_connection_list;
  v28 = 0;
  *(_QWORD *)string = 0;
  v3 = scnprintf(string, 9, "(vdev %d)", qword_81C458);
  if ( v2 > 2 )
  {
    if ( v2 <= 4 )
    {
      if ( v2 == 3 )
      {
        v11 = strnlen(a1, 0x12Cu);
        if ( v11 != -1 )
        {
          v12 = v11 + 6;
          if ( v11 > 0x12B )
            goto LABEL_56;
          v13 = v12 >= 0x12C;
          v14 = 6;
          v15 = 299 - v11;
          if ( v12 >= 0x12C )
            v16 = 299;
          else
            v16 = v11 + 6;
          v17 = "P2P GO";
          goto LABEL_52;
        }
      }
      else
      {
        v11 = strnlen(a1, 0x12Cu);
        if ( v11 != -1 )
        {
          v12 = v11 + 3;
          if ( v11 > 0x12B )
            goto LABEL_56;
          v13 = v12 >= 0x12C;
          v14 = 3;
          v15 = 299 - v11;
          if ( v12 >= 0x12C )
            v16 = 299;
          else
            v16 = v11 + 3;
          v17 = "NDI";
          goto LABEL_52;
        }
      }
LABEL_71:
      v25 = v11 + 1;
      goto LABEL_72;
    }
    if ( v2 == 5 )
    {
      v11 = strnlen(a1, 0x12Cu);
      if ( v11 != -1 )
      {
        v12 = v11 + 8;
        if ( v11 > 0x12B )
          goto LABEL_56;
        v13 = v12 >= 0x12C;
        v14 = 8;
        v15 = 299 - v11;
        if ( v12 >= 0x12C )
          v16 = 299;
        else
          v16 = v11 + 8;
        v17 = "NAN DISC";
        goto LABEL_52;
      }
      goto LABEL_71;
    }
    if ( v2 == 6 )
    {
      v11 = strnlen(a1, 0x12Cu);
      if ( v11 != -1 )
      {
        v12 = v11 + 6;
        if ( v11 > 0x12B )
          goto LABEL_56;
        v13 = v12 >= 0x12C;
        v14 = 6;
        v15 = 299 - v11;
        if ( v12 >= 0x12C )
          v16 = 299;
        else
          v16 = v11 + 6;
        v17 = "LT_SAP";
        goto LABEL_52;
      }
      goto LABEL_71;
    }
    goto LABEL_33;
  }
  if ( !v2 )
  {
    v11 = strnlen(a1, 0x12Cu);
    if ( v11 != -1 )
    {
      v12 = v11 + 3;
      if ( v11 > 0x12B )
        goto LABEL_56;
      v13 = v12 >= 0x12C;
      v14 = 3;
      v15 = 299 - v11;
      if ( v12 >= 0x12C )
        v16 = 299;
      else
        v16 = v11 + 3;
      v17 = "STA";
      goto LABEL_52;
    }
    goto LABEL_71;
  }
  if ( v2 != 1 )
  {
    if ( v2 == 2 )
    {
      v11 = strnlen(a1, 0x12Cu);
      if ( v11 != -1 )
      {
        v12 = v11 + 7;
        if ( v11 > 0x12B )
          goto LABEL_56;
        v13 = v12 >= 0x12C;
        v14 = 7;
        v15 = 299 - v11;
        if ( v12 >= 0x12C )
          v16 = 299;
        else
          v16 = v11 + 7;
        v17 = "P2P CLI";
        goto LABEL_52;
      }
      goto LABEL_71;
    }
LABEL_33:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unexpected mode %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_dump_current_concurrency_one_connection",
      (unsigned int)v2);
    LODWORD(v12) = 0;
    goto LABEL_56;
  }
  v11 = strnlen(a1, 0x12Cu);
  if ( v11 == -1 )
    goto LABEL_71;
  v12 = v11 + 3;
  if ( v11 > 0x12B )
    goto LABEL_56;
  v13 = v12 >= 0x12C;
  v14 = 3;
  v15 = 299 - v11;
  if ( v12 >= 0x12C )
    v16 = 299;
  else
    v16 = v11 + 3;
  v17 = "SAP";
LABEL_52:
  if ( v13 )
    v18 = v15;
  else
    v18 = v14;
  memcpy((void *)&a1[v11], v17, v18);
  a1[v16] = 0;
LABEL_56:
  v19 = strnlen(a1, 0x12Cu);
  if ( v19 == -1 )
  {
    v25 = 0;
LABEL_72:
    v26 = _fortify_panic(2, -1, v25);
    return policy_mgr_dump_current_concurrency_two_connection(v26);
  }
  v20 = strnlen(string, 9u);
  if ( v20 >= 0xA )
  {
    v20 = _fortify_panic(2, 9, v20 + 1);
LABEL_70:
    _fortify_panic(4, 9, v20 + 1);
  }
  if ( v20 == 9 )
    goto LABEL_70;
  v21 = v20 + v19;
  if ( v19 <= 0x12B )
  {
    if ( v21 >= 0x12C )
      v22 = 299;
    else
      v22 = v20 + v19;
    if ( v21 >= 0x12C )
      v23 = 299 - v19;
    else
      v23 = v20;
    memcpy((void *)&a1[v19], string, v23);
    a1[v22] = 0;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v21 + v12);
}
