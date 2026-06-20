__int64 __fastcall wma_update_hw_mode_list(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  unsigned int v11; // w21
  __int64 v12; // x20
  _DWORD *v14; // x25
  __int64 v15; // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  unsigned int v26; // w26
  unsigned int v27; // w22
  _DWORD *v28; // x10
  int v29; // w9
  unsigned int v30; // w20
  bool v31; // zf
  __int64 v32; // x9
  int v33; // w9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wma_validate_handle",
      "wma_update_hw_mode_list");
    return 16;
  }
  v10 = a2[126];
  v11 = a2[206];
  v12 = a1;
  v14 = a2 + 268;
  if ( v10 <= 0xA )
  {
    if ( *v14 == v10 )
    {
      v15 = 0;
    }
    else if ( a2[332] == v10 )
    {
      v15 = 1;
    }
    else if ( a2[396] == v10 )
    {
      v15 = 2;
    }
    else if ( a2[460] == v10 )
    {
      v15 = 3;
    }
    else if ( a2[524] == v10 )
    {
      v15 = 4;
    }
    else if ( a2[588] == v10 )
    {
      v15 = 5;
    }
    else if ( a2[652] == v10 )
    {
      v15 = 6;
    }
    else
    {
      if ( a2[716] != v10 )
      {
LABEL_42:
        qdf_trace_msg(0x36u, 2u, "%s: mac_phy_cap Null", a3, a4, a5, a6, a7, a8, a9, a10, "wma_update_hw_mode_list");
        return 16;
      }
      v15 = 7;
    }
    v14 += 64 * v15;
  }
  if ( !v14 )
    goto LABEL_42;
  qdf_trace_msg(0x36u, 8u, "%s: Num modes:%d", a3, a4, a5, a6, a7, a8, a9, a10, "wma_update_hw_mode_list", v11);
  if ( v11 )
  {
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v42 = v12;
    do
    {
      v28 = &v14[64 * (unsigned __int64)v26];
      v29 = v28[6];
      v30 = v28[4];
      if ( v29 == 2 )
      {
        v27 |= 1u;
      }
      else if ( v29 == 1 )
      {
        v27 |= 2u;
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: wrong supported band",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wma_update_supported_bands");
        v25 = 1;
      }
      v31 = v30 > 5 || ((1 << v30) & 0x2E) == 0;
      v32 = v26 + 1;
      if ( v31 )
      {
        ++v26;
      }
      else
      {
        v26 += 2;
        v33 = v14[64 * v32 + 6];
        if ( v33 == 2 )
        {
          v27 |= 1u;
        }
        else if ( v33 == 1 )
        {
          v27 |= 2u;
        }
        else
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: wrong supported band",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "wma_update_supported_bands");
          v25 = 1;
        }
      }
      --v11;
    }
    while ( v11 );
    v12 = v42;
    if ( (v25 & 1) != 0 )
      goto LABEL_45;
  }
  else
  {
    v27 = 0;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: updating supported band from old[%d] to new[%d]",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wma_update_hw_mode_list",
    (unsigned int)a2[170],
    v27);
  a2[170] = v27;
LABEL_45:
  result = policy_mgr_update_hw_mode_list(*(_QWORD *)(v12 + 24), (__int64)a2);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: failed to update policy manager",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wma_update_hw_mode_list");
    return 0;
  }
  return result;
}
