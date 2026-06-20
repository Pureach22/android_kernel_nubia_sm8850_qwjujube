__int64 __fastcall qcom_clk_set_flags(unsigned __int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *hw; // x20
  __int64 v6; // x8
  _DWORD *v7; // x8

  result = 0;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      hw = (_QWORD *)_clk_get_hw(a1);
      result = 4294967274LL;
      if ( hw )
      {
        if ( (unsigned __int64)hw <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( clk_is_regmap_clk(hw) )
          {
            v6 = hw[11];
            if ( v6 && (v7 = *(_DWORD **)(v6 + 16)) != nullptr )
            {
              if ( *(v7 - 1) != -1157018402 )
                __break(0x8228u);
              return ((__int64 (__fastcall *)(_QWORD *, __int64))v7)(hw, a2);
            }
            else
            {
              return 0;
            }
          }
          else
          {
            return 4294967274LL;
          }
        }
      }
    }
  }
  return result;
}
