__int64 __fastcall qcom_clk_crm_set_rate(__int64 parent, unsigned int a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  _QWORD *hw; // x23
  __int64 v10; // x8
  _DWORD *v11; // x8

  if ( !parent )
    return 4294967274LL;
  while ( 1 )
  {
    hw = (_QWORD *)_clk_get_hw(parent);
    if ( clk_is_regmap_clk(hw) )
    {
      v10 = hw[11];
      if ( v10 )
      {
        v11 = *(_DWORD **)(v10 + 32);
        if ( v11 )
          break;
      }
    }
    parent = clk_get_parent(hw[1]);
    if ( !parent )
      return 4294967274LL;
  }
  if ( *(v11 - 1) != -1931329457 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD, __int64))v11)(hw, a2, a3, a4, a5);
}
