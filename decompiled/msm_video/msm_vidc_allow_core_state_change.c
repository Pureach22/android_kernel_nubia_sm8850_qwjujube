__int64 __fastcall msm_vidc_allow_core_state_change(__int64 a1, unsigned int a2)
{
  int v2; // w8
  __int64 result; // x0
  _UNKNOWN **v4; // x8

  v2 = *(_DWORD *)(a1 + 3704);
  result = 0;
  if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      if ( a2 < 4 )
      {
        v4 = &off_9DE58;
        return *((unsigned int *)v4[a2] + 2);
      }
    }
    else
    {
      if ( v2 != 3 )
        return result;
      if ( a2 < 4 )
      {
        v4 = &off_9DE78;
        return *((unsigned int *)v4[a2] + 2);
      }
    }
  }
  else if ( v2 )
  {
    if ( v2 != 1 )
      return result;
    if ( a2 < 4 )
    {
      v4 = &off_9DE38;
      return *((unsigned int *)v4[a2] + 2);
    }
  }
  else if ( a2 <= 3 )
  {
    v4 = &off_9DE18;
    return *((unsigned int *)v4[a2] + 2);
  }
  return 0;
}
