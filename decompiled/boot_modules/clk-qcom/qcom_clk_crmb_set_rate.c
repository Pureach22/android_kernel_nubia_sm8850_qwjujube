__int64 __fastcall qcom_clk_crmb_set_rate(
        __int64 parent,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  _QWORD *hw; // x25
  __int64 v14; // x8
  _DWORD *v15; // x8

  if ( !parent )
    return 4294967274LL;
  while ( 1 )
  {
    hw = (_QWORD *)_clk_get_hw(parent);
    if ( clk_is_regmap_clk(hw) )
    {
      v14 = hw[11];
      if ( v14 )
      {
        v15 = *(_DWORD **)(v14 + 40);
        if ( v15 )
          break;
      }
    }
    parent = clk_get_parent(hw[1]);
    if ( !parent )
      return 4294967274LL;
  }
  if ( *(v15 - 1) != 484713604 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v15)(
           hw,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7);
}
