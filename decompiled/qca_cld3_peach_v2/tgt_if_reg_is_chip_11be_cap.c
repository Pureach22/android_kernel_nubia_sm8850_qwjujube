__int64 __fastcall tgt_if_reg_is_chip_11be_cap(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  void (*v11)(void); // x8
  _DWORD *v13; // x9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  unsigned int v23; // w10
  _DWORD *v24; // x8
  __int64 v25; // x9
  _DWORD *v26; // x8
  unsigned __int8 v27; // [xsp+4h] [xbp-Ch]

  _ReadStatusReg(SP_EL0);
  v27 = 0;
  if ( a1 && (v10 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v11 = *(void (**)(void))(v10 + 992);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != 13449260 )
        __break(0x8228u);
      v11();
      v13 = *(_DWORD **)(a1 + 2800);
      if ( !v13 )
        goto LABEL_9;
    }
    else
    {
      v27 = a2;
      v13 = *(_DWORD **)(a1 + 2800);
      if ( !v13 )
        goto LABEL_9;
    }
    v23 = v13[126];
    v24 = v13 + 268;
    if ( v23 <= 0xA )
    {
      if ( *v24 == v23 )
      {
        v25 = 0;
      }
      else if ( v13[332] == v23 )
      {
        v25 = 1;
      }
      else if ( v13[396] == v23 )
      {
        v25 = 2;
      }
      else if ( v13[460] == v23 )
      {
        v25 = 3;
      }
      else if ( v13[524] == v23 )
      {
        v25 = 4;
      }
      else if ( v13[588] == v23 )
      {
        v25 = 5;
      }
      else if ( v13[652] == v23 )
      {
        v25 = 6;
      }
      else
      {
        if ( v13[716] != v23 )
          goto LABEL_9;
        v25 = 7;
      }
      v24 += 64 * v25;
    }
    if ( v24 )
    {
      v26 = &v24[64 * (unsigned __int64)v27];
      if ( v26 )
      {
        if ( (v26[5] & 0x40) != 0 )
        {
          result = 1;
          goto LABEL_10;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_regulatory_get_tx_ops");
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: reg_tx_ops is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tgt_if_reg_is_chip_11be_cap");
  }
LABEL_9:
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
