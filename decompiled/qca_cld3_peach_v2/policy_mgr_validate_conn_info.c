__int64 __fastcall policy_mgr_validate_conn_info(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned __int8 *v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w8
  int v21; // w23
  unsigned int v22; // w20
  __int64 v23; // x4

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "policy_mgr_validate_conn_info");
  v10 = (unsigned __int8 *)context;
  qdf_mutex_acquire(context + 56);
  if ( BYTE4(qword_8D4F00) == 1 )
  {
    if ( BYTE4(qword_8D4F24) == 1 && (_DWORD)qword_8D4F00 == (_DWORD)qword_8D4F24 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    else
    {
      v19 = 0;
    }
    if ( BYTE4(qword_8D4F48) == 1 && (_DWORD)qword_8D4F00 == (_DWORD)qword_8D4F48 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    if ( BYTE4(qword_8D4F6C) == 1 && (_DWORD)qword_8D4F00 == (_DWORD)qword_8D4F6C )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F00 == (_DWORD)qword_8D4F90 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v21 = 1;
      v19 = 1;
    }
    else
    {
      v21 = 1;
    }
  }
  else
  {
    v21 = 0;
    v19 = 0;
  }
  if ( BYTE4(qword_8D4F24) == 1 )
  {
    if ( BYTE4(qword_8D4F48) == 1 && (_DWORD)qword_8D4F24 == (_DWORD)qword_8D4F48 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    if ( BYTE4(qword_8D4F6C) == 1 && (_DWORD)qword_8D4F24 == (_DWORD)qword_8D4F6C )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F24 == (_DWORD)qword_8D4F90 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    ++v21;
  }
  if ( BYTE4(qword_8D4F48) == 1 )
  {
    if ( BYTE4(qword_8D4F6C) == 1 && (_DWORD)qword_8D4F48 == (_DWORD)qword_8D4F6C )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F48 == (_DWORD)qword_8D4F90 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    ++v21;
  }
  if ( BYTE4(qword_8D4F6C) == 1 )
  {
    if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F6C == (_DWORD)qword_8D4F90 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: dup entry %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_validate_conn_info");
      v19 = 1;
    }
    ++v21;
  }
  v22 = v21 + BYTE4(qword_8D4F90);
  if ( v19 )
    qdf_trace_msg(0x4Fu, 2u, "%s: dup entry", v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_validate_conn_info");
  v23 = v10[989]
      + v10[990]
      + v10[991]
      + v10[992]
      + v10[993]
      + v10[994]
      + v10[995]
      + v10[996]
      + v10[997]
      + v10[998]
      + v10[999]
      + v10[1000]
      + v10[1001]
      + v10[1002]
      + v10[1003]
      + v10[1004]
      + (unsigned int)v10[1005];
  if ( (_DWORD)v23 != v22 )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: active session/conn count mismatch %d %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_validate_conn_info",
      v23,
      v22);
  return qdf_mutex_release((__int64)(v10 + 56));
}
