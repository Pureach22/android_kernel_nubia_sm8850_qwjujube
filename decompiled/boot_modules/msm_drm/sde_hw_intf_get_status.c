__int64 __fastcall sde_hw_intf_get_status(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8

  result = sde_reg_read(a1, 0);
  *(_BYTE *)a2 = result;
  if ( (_BYTE)result )
  {
    *(_DWORD *)(a2 + 4) = sde_reg_read(a1, 172);
    result = sde_reg_read(a1, 176);
    v5 = (unsigned __int16)result;
  }
  else
  {
    v5 = 0;
    *(_DWORD *)(a2 + 4) = 0;
  }
  *(_DWORD *)(a2 + 8) = v5;
  return result;
}
