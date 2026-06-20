__int64 __fastcall clk_gfx3d_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 *v2; // x8
  __int64 v3; // x20
  __int64 v4; // x23
  __int64 v5; // x21
  unsigned int v7; // w24
  __int64 parent_by_index; // x0
  __int64 v9; // x25
  __int64 v10; // x22
  __int64 result; // x0
  __int64 v12; // x8
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x24
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned __int64 v17; // x9
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v19; // [xsp+10h] [xbp-30h]
  unsigned __int64 v20; // [xsp+18h] [xbp-28h]
  unsigned __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a1 + 160);
  v22 = 0;
  v23 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = -1;
  v3 = *v2;
  if ( *v2 && (v4 = v2[1]) != 0 && (v5 = v2[2]) != 0 )
  {
    v7 = *(unsigned __int8 *)(a1 - 56);
    parent_by_index = clk_hw_get_parent_by_index(a1, 0);
    if ( parent_by_index )
    {
      v9 = a2[1];
      v10 = parent_by_index;
      if ( v9 == clk_hw_get_rate(parent_by_index) )
      {
        result = 0;
        a2[5] = v10;
      }
      else
      {
        v12 = a2[1];
        if ( v7 <= 1 )
          v13 = 1;
        else
          v13 = v7;
        v14 = v12 * v13;
        v19 = v12 * v13;
        if ( v12 * v13 == clk_hw_get_rate(v3) )
        {
          result = 0;
          a2[1] = v14;
          a2[4] = v14;
          a2[5] = v3;
        }
        else
        {
          v15 = a2[5];
          if ( v15 == v3 )
          {
            if ( clk_hw_get_rate(v5) == v14 )
              v16 = v5;
            else
              v16 = v4;
          }
          else if ( v15 == v5 )
          {
            v16 = v4;
          }
          else
          {
            v16 = v5;
          }
          a2[5] = v16;
          clk_hw_get_rate_range();
          if ( a2[2] > v20 )
            v20 = a2[2];
          if ( a2[3] < v21 )
            v21 = a2[3];
          result = _clk_determine_rate(a2[5], &v18);
          if ( !(_DWORD)result )
          {
            v17 = v19 / v13;
            a2[4] = v19;
            a2[1] = v17;
          }
        }
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
