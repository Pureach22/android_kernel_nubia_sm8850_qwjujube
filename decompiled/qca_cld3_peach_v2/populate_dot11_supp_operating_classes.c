__int64 __fastcall populate_dot11_supp_operating_classes(__int64 a1, _BYTE *a2, __int64 a3)
{
  __int64 result; // x0
  char v7; // w8

  wlan_reg_dmn_get_curr_opclasses();
  result = lim_op_class_from_bandwidth(a1, *(_DWORD *)(a3 + 284), *(_DWORD *)(a3 + 7176));
  v7 = a2[1];
  a2[2] = result;
  a2[1] = v7 + 1;
  *a2 = 1;
  return result;
}
