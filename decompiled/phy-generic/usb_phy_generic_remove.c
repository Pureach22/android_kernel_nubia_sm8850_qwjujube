__int64 __fastcall usb_phy_generic_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  usb_remove_phy(v1);
  result = *(_QWORD *)(v1 + 408);
  if ( result )
  {
    if ( *(_BYTE *)(v1 + 416) == 1 )
      return regulator_disable(result);
  }
  return result;
}
