__int64 __fastcall dsi_panel_parse_rgb_led(__int64 a1, __int64 a2)
{
  int v4; // w0
  __int64 v5; // x8
  int v6; // w8
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // [xsp+8h] [xbp-58h] BYREF
  __int64 v10; // [xsp+10h] [xbp-50h]
  __int64 v11; // [xsp+18h] [xbp-48h]
  __int64 v12; // [xsp+20h] [xbp-40h]
  __int64 v13; // [xsp+28h] [xbp-38h]
  __int64 v14; // [xsp+30h] [xbp-30h]
  __int64 v15; // [xsp+38h] [xbp-28h]
  __int64 v16; // [xsp+40h] [xbp-20h]
  __int64 v17; // [xsp+48h] [xbp-18h]
  __int64 v18; // [xsp+50h] [xbp-10h]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( *(_DWORD *)(a1 + 1472) == 4 )
    {
      v17 = 0;
      v18 = 0;
      v15 = 0;
      v16 = 0;
      v13 = 0;
      v14 = 0;
      v11 = 0;
      v12 = 0;
      v9 = 0;
      v10 = 0;
      v4 = _of_parse_phandle_with_args(a2, "qcom,panel-rgb-left-led", 0, 0, 0, &v9);
      v5 = v9;
      if ( v4 )
        v5 = 0;
      v17 = 0;
      v18 = 0;
      *(_QWORD *)(a1 + 1024) = v5;
      v15 = 0;
      v16 = 0;
      v13 = 0;
      v14 = 0;
      v11 = 0;
      v12 = 0;
      v9 = 0;
      v10 = 0;
      v6 = _of_parse_phandle_with_args(a2, "qcom,panel-rgb-right-led", 0, 0, 0, &v9);
      result = 0;
      if ( v6 )
        v8 = 0;
      else
        v8 = v9;
      *(_QWORD *)(a1 + 1032) = v8;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
