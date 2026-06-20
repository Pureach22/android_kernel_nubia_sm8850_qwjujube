__int64 __fastcall mlo_get_assoc_rsp(__int64 result, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  _QWORD *v4; // x8
  __int64 v5; // x9

  v2 = *(_QWORD *)(result + 1360);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 2224);
    if ( v3 )
    {
      v4 = (_QWORD *)(v3 + 104);
      if ( *(_DWORD *)(v3 + 104) )
      {
        if ( *(_QWORD *)(v3 + 112) )
        {
          v5 = *(_QWORD *)(v3 + 112);
          *a2 = *v4;
          a2[1] = v5;
        }
      }
    }
  }
  return result;
}
