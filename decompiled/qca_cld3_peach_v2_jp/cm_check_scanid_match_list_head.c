__int64 __fastcall cm_check_scanid_match_list_head(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w21
  unsigned int v5; // w21
  unsigned int v6; // w22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  __int64 v16; // x4
  __int64 v17; // [xsp+0h] [xbp-10h] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  if ( !a2 )
    goto LABEL_9;
  qdf_mutex_acquire(a1 + 120);
  qdf_list_peek_front((_QWORD *)(a1 + 96), &v17);
  if ( !v17 )
  {
    v4 = 0;
    goto LABEL_7;
  }
  v4 = *(_DWORD *)(v17 + 16) & 0xF000000;
  if ( v4 != 201326592 )
  {
LABEL_7:
    qdf_mutex_release(a1 + 120);
    v16 = 0;
LABEL_8:
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: head_scan_id 0x%x didn't match the given scan_id 0x%x prefix 0x%x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_check_scanid_match_list_head",
      v16,
      *a2,
      v4,
      v17,
      v18);
LABEL_9:
    result = 0;
    goto LABEL_10;
  }
  v5 = *(_DWORD *)(v17 + 28);
  v6 = *a2;
  qdf_mutex_release(a1 + 120);
  if ( v5 != v6 )
  {
    v16 = v5;
    v4 = 201326592;
    goto LABEL_8;
  }
  result = 1;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
