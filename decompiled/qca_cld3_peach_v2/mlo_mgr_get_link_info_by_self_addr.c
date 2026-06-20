__int64 __fastcall mlo_mgr_get_link_info_by_self_addr(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v6; // x8
  int v7; // t1

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v2 = *(_QWORD *)(result + 1360);
    if ( !v2 )
      goto LABEL_17;
    result = 0;
    if ( !a2 )
      goto LABEL_18;
    v3 = *(_QWORD *)(v2 + 3880);
    if ( !v3 )
      goto LABEL_18;
    if ( !(*(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4)) )
    {
LABEL_17:
      result = 0;
      goto LABEL_18;
    }
    if ( *(_DWORD *)v3 == *(_DWORD *)a2 && *(unsigned __int16 *)(v3 + 4) == *(unsigned __int16 *)(a2 + 4) )
    {
      result = v3;
    }
    else
    {
      result = v3 + 48;
      if ( *(_DWORD *)(v3 + 48) != *(_DWORD *)a2 || *(unsigned __int16 *)(v3 + 52) != *(unsigned __int16 *)(a2 + 4) )
      {
        v7 = *(_DWORD *)(v3 + 96);
        v6 = v3 + 96;
        if ( v7 ^ *(_DWORD *)a2 | *(unsigned __int16 *)(v6 + 4) ^ *(unsigned __int16 *)(a2 + 4) )
          result = 0;
        else
          result = v6;
      }
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
