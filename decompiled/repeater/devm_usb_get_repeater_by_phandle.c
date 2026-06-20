__int64 __fastcall devm_usb_get_repeater_by_phandle(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v4; // x0
  int v5; // w8
  __int64 result; // x0
  __int64 v7[11]; // [xsp+8h] [xbp-58h] BYREF

  v7[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  if ( v4 )
  {
    memset(v7, 0, 80);
    v5 = _of_parse_phandle_with_args(v4, a2, 0, 0, a3, v7);
    result = -19;
    if ( !v5 && v7[0] )
      result = devm_usb_get_repeater_by_node(a1, v7[0]);
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
