__int64 __fastcall wlansap_update_sap_config_add_ie(
        __int64 a1,
        const void *a2,
        unsigned __int16 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int16 v13; // w20
  unsigned int v14; // w23
  bool v16; // w25
  __int64 v17; // x21
  __int64 v18; // x0
  __int64 result; // x0
  void *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x0

  if ( !a1 )
    return 5;
  v13 = a3;
  v14 = a3;
  if ( a3 )
    v16 = a2 == nullptr;
  else
    v16 = 1;
  if ( v16 )
  {
    v13 = 0;
    v17 = 0;
    if ( a4 != 3 )
    {
LABEL_7:
      if ( a4 == 2 )
      {
        v31 = *(_QWORD *)(a1 + 1752);
        if ( v31 )
          _qdf_mem_free(v31);
        result = 0;
        if ( v16 )
        {
          *(_WORD *)(a1 + 1744) = 0;
          *(_QWORD *)(a1 + 1752) = 0;
        }
        else
        {
          *(_WORD *)(a1 + 1744) = v13;
          *(_QWORD *)(a1 + 1752) = v17;
        }
      }
      else if ( a4 == 1 )
      {
        v18 = *(_QWORD *)(a1 + 1784);
        if ( v18 )
          _qdf_mem_free(v18);
        result = 0;
        if ( v16 )
        {
          *(_WORD *)(a1 + 1776) = 0;
          *(_QWORD *)(a1 + 1784) = 0;
        }
        else
        {
          *(_WORD *)(a1 + 1776) = v13;
          *(_QWORD *)(a1 + 1784) = v17;
        }
      }
      else
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: No matching buffer type %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "wlansap_update_sap_config_add_ie",
          a4);
        if ( v17 )
          _qdf_mem_free(v17);
        return 0;
      }
      return result;
    }
  }
  else
  {
    v21 = (void *)_qdf_mem_malloc(a3, "wlansap_update_sap_config_add_ie", 2788);
    if ( !v21 )
      return 2;
    v17 = (__int64)v21;
    qdf_mem_copy(v21, a2, v14);
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: update_type: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlansap_update_sap_config_add_ie",
      a4);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(57, 8, v17, v14);
    if ( a4 != 3 )
      goto LABEL_7;
  }
  v30 = *(_QWORD *)(a1 + 1768);
  if ( v30 )
    _qdf_mem_free(v30);
  result = 0;
  if ( v16 )
  {
    *(_WORD *)(a1 + 1760) = 0;
    *(_QWORD *)(a1 + 1768) = 0;
  }
  else
  {
    *(_WORD *)(a1 + 1760) = v13;
    *(_QWORD *)(a1 + 1768) = v17;
  }
  return result;
}
