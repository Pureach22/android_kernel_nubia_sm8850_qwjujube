__int64 __fastcall cm_check_cmid_match_list_head(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w21
  unsigned int v5; // w22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( !a2 )
    goto LABEL_7;
  qdf_mutex_acquire(a1 + 120);
  qdf_list_peek_front((_QWORD *)(a1 + 96), &v15);
  if ( !v15 )
  {
    qdf_mutex_release(a1 + 120);
    v4 = 0;
    goto LABEL_6;
  }
  v4 = *(_DWORD *)(v15 + 16);
  v5 = *a2;
  qdf_mutex_release(a1 + 120);
  if ( v4 != v5 )
  {
LABEL_6:
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: head_cm_id 0x%x didn't match the given cm_id 0x%x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_check_cmid_match_list_head",
      v4,
      *a2,
      v15,
      v16);
LABEL_7:
    result = 0;
    goto LABEL_8;
  }
  result = 1;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
