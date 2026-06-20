__int64 __fastcall cm_get_entry(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x8
  __int64 result; // x0
  _QWORD *v10; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = nullptr;
  v11[0] = nullptr;
  qdf_list_peek_front(a1, v11);
  v6 = v11[0];
  if ( v11[0] )
  {
    while ( 1 )
    {
      result = v6[3];
      if ( *(_DWORD *)(result + 1) == *(_DWORD *)a2
        && *(unsigned __int16 *)(result + 5) == *(unsigned __int16 *)(a2 + 4) )
      {
        if ( !a3 )
          break;
        if ( *(_DWORD *)(result + 1912) == *(_DWORD *)a3
          && *(unsigned __int16 *)(result + 1916) == *(unsigned __int16 *)(a3 + 4) )
        {
          break;
        }
      }
      qdf_list_peek_next(a1, v11[0], &v10);
      v6 = v10;
      v10 = nullptr;
      v11[0] = v6;
      if ( !v6 )
        goto LABEL_2;
    }
  }
  else
  {
LABEL_2:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
