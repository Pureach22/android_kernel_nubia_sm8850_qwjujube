__int64 __fastcall sde_hw_intf_read_wd_ltj_ctl(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x0

  if ( (*(_BYTE *)(*(_QWORD *)(result + 40) + 33LL) & 0x80) != 0 )
  {
    v3 = result;
    v4 = sde_reg_read(result, 576);
    *(_BYTE *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = v4 & 0x1FFFFF;
    result = sde_reg_read(v3, 580);
    *(_DWORD *)(a2 + 20) = (unsigned __int16)result;
  }
  return result;
}
