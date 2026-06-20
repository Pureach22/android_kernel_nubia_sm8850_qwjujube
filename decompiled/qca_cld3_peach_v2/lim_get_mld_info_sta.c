__int64 __fastcall lim_get_mld_info_sta(__int64 result, _QWORD *a2, _BYTE *a3)
{
  char v3; // w8

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(result + 7) | *(unsigned __int16 *)(result + 11) )
  {
    *a2 = result + 7;
    v3 = *(_BYTE *)(result + 13);
  }
  else
  {
    v3 = 0;
    *a2 = 0;
  }
  *a3 = v3;
  _ReadStatusReg(SP_EL0);
  return result;
}
