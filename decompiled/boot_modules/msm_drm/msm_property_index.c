__int64 __fastcall msm_property_index(__int64 a1, __int64 a2)
{
  int v4; // w8
  int v5; // w20
  int v6; // w10

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 80);
    v4 = *(_DWORD *)(a1 + 32);
    if ( v4 )
    {
      v5 = *(_DWORD *)(a1 + 48);
      v6 = v4 - 1;
      while ( *(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL * v5) != a2 )
      {
        --v4;
        if ( v5 - 1 >= 0 )
          --v5;
        else
          v5 = v6;
        if ( !v4 )
          goto LABEL_10;
      }
      *(_DWORD *)(a1 + 48) = v5;
    }
    else
    {
LABEL_10:
      v5 = -22;
    }
    mutex_unlock(a1 + 80);
  }
  else
  {
    _drm_err("invalid argument(s)\n");
    return (unsigned int)-22;
  }
  return (unsigned int)v5;
}
