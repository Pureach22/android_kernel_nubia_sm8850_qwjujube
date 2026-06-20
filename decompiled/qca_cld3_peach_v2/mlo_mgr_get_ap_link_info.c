__int64 __fastcall mlo_mgr_get_ap_link_info(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v2 = result;
    result = 0;
    if ( a2 )
    {
      v3 = *(_QWORD *)(v2 + 1360);
      if ( v3 )
      {
        if ( *(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4) )
        {
          result = *(_QWORD *)(v3 + 3880);
          if ( *(_DWORD *)(result + 24) != *(_DWORD *)a2
            || *(unsigned __int16 *)(result + 28) != *(unsigned __int16 *)(a2 + 4) )
          {
            if ( *(_DWORD *)(result + 72) == *(_DWORD *)a2
              && *(unsigned __int16 *)(result + 76) == *(unsigned __int16 *)(a2 + 4) )
            {
              result += 48;
            }
            else if ( *(_DWORD *)(result + 120) ^ *(_DWORD *)a2
                    | *(unsigned __int16 *)(result + 124) ^ *(unsigned __int16 *)(a2 + 4) )
            {
              result = 0;
            }
            else
            {
              result += 96;
            }
          }
        }
        else
        {
          result = 0;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
