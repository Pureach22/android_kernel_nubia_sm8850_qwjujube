__int64 __fastcall mlo_get_sta_num_links(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(a1 + 3880);
  if ( *(_DWORD *)(v1 + 24) | *(unsigned __int16 *)(v1 + 28) )
    result = (*(_DWORD *)v1 | *(unsigned __int16 *)(v1 + 4)) != 0;
  else
    result = 0;
  if ( *(_DWORD *)(v1 + 72) | *(unsigned __int16 *)(v1 + 76) )
  {
    if ( *(_DWORD *)(v1 + 48) | *(unsigned __int16 *)(v1 + 52) )
      result = (unsigned int)(result + 1);
    else
      result = (unsigned int)result;
  }
  if ( *(_DWORD *)(v1 + 120) | *(unsigned __int16 *)(v1 + 124) )
  {
    if ( *(_DWORD *)(v1 + 96) | *(unsigned __int16 *)(v1 + 100) )
      result = (unsigned int)(result + 1);
    else
      result = (unsigned int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
