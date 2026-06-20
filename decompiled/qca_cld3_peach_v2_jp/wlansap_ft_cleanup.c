__int64 __fastcall wlansap_ft_cleanup(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  const char *v19; // x2
  unsigned int v20; // w1
  _QWORD *i; // x1
  __int64 v22; // x23
  _QWORD *v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _QWORD *v32; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v33[2]; // [xsp+10h] [xbp-10h] BYREF

  v33[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = nullptr;
  v33[0] = nullptr;
  if ( !_cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v19 = "%s: Invalid MAC context";
    v20 = 2;
    goto LABEL_5;
  }
  result = qdf_list_peek_front((_QWORD *)(a1 + 1656), v33);
  if ( (_DWORD)result )
  {
    v19 = "%s: Failed to find assoc ind list";
    v20 = 8;
LABEL_5:
    result = qdf_trace_msg(0x39u, v20, v19, v10, v11, v12, v13, v14, v15, v16, v17, "wlansap_ft_cleanup");
    goto LABEL_6;
  }
  for ( i = v33[0]; i; v33[0] = i )
  {
    qdf_list_peek_next((_QWORD *)(a1 + 1656), i, &v32);
    v23 = v33[0];
    if ( (unsigned int)qdf_list_remove_node(a1 + 1656, v33[0]) )
    {
      result = qdf_trace_msg(
                 0x39u,
                 2u,
                 "%s: Failed to remove assoc ind",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "wlansap_ft_cleanup");
    }
    else
    {
      v22 = v23[2];
      _qdf_mem_free((__int64)v23);
      *(_QWORD *)(v22 + 2928) = 0;
      *(_DWORD *)(v22 + 2936) = 0;
      *(_WORD *)(v22 + 2940) = 1;
      result = _qdf_mem_free(v22);
    }
    i = v32;
    v32 = nullptr;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
