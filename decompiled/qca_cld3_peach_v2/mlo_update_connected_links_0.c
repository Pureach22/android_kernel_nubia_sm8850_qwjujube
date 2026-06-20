__int64 __fastcall mlo_update_connected_links_0(__int64 result, char a2)
{
  _QWORD *v2; // x9
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x9

  v2 = *(_QWORD **)(result + 1360);
  if ( v2 )
  {
    v3 = v2[278];
    if ( v3 )
    {
      v4 = v2[3];
      if ( v4 && v4 == result )
      {
        v5 = *(_QWORD *)(v3 + 8);
        if ( a2 )
        {
          *(_QWORD *)(v3 + 8) = v5 | 1;
          v6 = v2[4];
          if ( !v6 || v6 != result )
            return result;
LABEL_12:
          *(_QWORD *)(v3 + 8) |= 2uLL;
          return result;
        }
        *(_QWORD *)(v3 + 8) = v5 & 0xFFFFFFFFFFFFFFFELL;
        v8 = v2[4];
        if ( v8 && v8 == result )
LABEL_15:
          *(_QWORD *)(v3 + 8) &= ~2uLL;
      }
      else
      {
        v7 = v2[4];
        if ( v7 && v7 == result )
        {
          if ( a2 )
            goto LABEL_12;
          goto LABEL_15;
        }
      }
    }
  }
  return result;
}
