__int64 __fastcall policy_mgr_dump_current_concurrency_three_connection(const char *a1)
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
  int v11; // w20
  size_t v12; // x0
  unsigned __int64 v13; // x21
  bool v14; // cf
  __int64 v15; // x10
  size_t v16; // x9
  const char *v17; // x1
  int v18; // w21
  size_t v19; // x2
  char *v20; // x0
  __int64 v21; // x22
  size_t v22; // x20
  size_t v23; // x0
  unsigned __int64 v24; // x22
  __int64 v25; // x23
  size_t v26; // x2
  size_t v28; // x2
  __int64 v29; // x0
  __int64 v30; // x1
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  char v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = qword_81C488;
  v32 = 0;
  *(_QWORD *)string = 0;
  v3 = scnprintf(string, 9, "(vdev %d)", qword_81C4A0);
  if ( v2 > 2 )
  {
    if ( v2 <= 4 )
    {
      if ( v2 == 3 )
      {
        v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
        v12 = strnlen(a1, 0x12Cu);
        if ( v12 != -1 )
        {
          v13 = v12 + 7;
          if ( v12 <= 0x12B )
          {
            v14 = v13 >= 0x12C;
            v15 = 7;
            v16 = 299 - v12;
            v17 = "+P2P GO";
            goto LABEL_31;
          }
          goto LABEL_38;
        }
      }
      else
      {
        v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
        v12 = strnlen(a1, 0x12Cu);
        if ( v12 != -1 )
        {
          v13 = v12 + 4;
          if ( v12 <= 0x12B )
          {
            v14 = v13 >= 0x12C;
            v15 = 4;
            v16 = 299 - v12;
            v17 = "+NDI";
LABEL_31:
            if ( v14 )
              v19 = v16;
            else
              v19 = v15;
            v20 = (char *)&a1[v12];
            if ( v14 )
              v21 = 299;
            else
              v21 = v13;
            memcpy(v20, v17, v19);
            a1[v21] = 0;
            goto LABEL_38;
          }
          goto LABEL_38;
        }
      }
LABEL_54:
      v28 = v12 + 1;
      goto LABEL_55;
    }
    if ( v2 == 5 )
    {
      v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
      v12 = strnlen(a1, 0x12Cu);
      if ( v12 != -1 )
      {
        v13 = v12 + 9;
        if ( v12 <= 0x12B )
        {
          v14 = v13 >= 0x12C;
          v15 = 9;
          v16 = 299 - v12;
          v17 = "+NAN Disc";
          goto LABEL_31;
        }
        goto LABEL_38;
      }
      goto LABEL_54;
    }
    if ( v2 == 6 )
    {
      v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
      v12 = strnlen(a1, 0x12Cu);
      if ( v12 != -1 )
      {
        v13 = v12 + 7;
        if ( v12 <= 0x12B )
        {
          v14 = v13 >= 0x12C;
          v15 = 7;
          v16 = 299 - v12;
          v17 = "+LT_SAP";
          goto LABEL_31;
        }
        goto LABEL_38;
      }
      goto LABEL_54;
    }
LABEL_21:
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
      "policy_mgr_dump_current_concurrency_three_connection",
      (unsigned int)v2);
    v18 = 0;
    goto LABEL_39;
  }
  if ( !v2 )
  {
    v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
    v12 = strnlen(a1, 0x12Cu);
    if ( v12 != -1 )
    {
      v13 = v12 + 4;
      if ( v12 <= 0x12B )
      {
        v14 = v13 >= 0x12C;
        v15 = 4;
        v16 = 299 - v12;
        v17 = "+STA";
        goto LABEL_31;
      }
      goto LABEL_38;
    }
    goto LABEL_54;
  }
  if ( v2 == 1 )
  {
    v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
    v12 = strnlen(a1, 0x12Cu);
    if ( v12 != -1 )
    {
      v13 = v12 + 4;
      if ( v12 <= 0x12B )
      {
        v14 = v13 >= 0x12C;
        v15 = 4;
        v16 = 299 - v12;
        v17 = "+SAP";
        goto LABEL_31;
      }
      goto LABEL_38;
    }
    goto LABEL_54;
  }
  if ( v2 != 2 )
    goto LABEL_21;
  v11 = policy_mgr_dump_current_concurrency_two_connection(a1);
  v12 = strnlen(a1, 0x12Cu);
  if ( v12 == -1 )
    goto LABEL_54;
  v13 = v12 + 8;
  if ( v12 <= 0x12B )
  {
    v14 = v13 >= 0x12C;
    v15 = 8;
    v16 = 299 - v12;
    v17 = "+P2P CLI";
    goto LABEL_31;
  }
LABEL_38:
  v18 = v11 + v13;
LABEL_39:
  v22 = strnlen(a1, 0x12Cu);
  if ( v22 == -1 )
  {
    v28 = 0;
LABEL_55:
    v29 = _fortify_panic(2, -1, v28);
    return policy_mgr_dump_dbs_concurrency(v29, v30);
  }
  v23 = strnlen(string, 9u);
  if ( v23 >= 0xA )
  {
    v23 = _fortify_panic(2, 9, v23 + 1);
LABEL_53:
    _fortify_panic(4, 9, v23 + 1);
  }
  if ( v23 == 9 )
    goto LABEL_53;
  v24 = v23 + v22;
  if ( v22 <= 0x12B )
  {
    if ( v24 >= 0x12C )
      v25 = 299;
    else
      v25 = v23 + v22;
    if ( v24 >= 0x12C )
      v26 = 299 - v22;
    else
      v26 = v23;
    memcpy((void *)&a1[v22], string, v26);
    a1[v25] = 0;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v18 + v24);
}
