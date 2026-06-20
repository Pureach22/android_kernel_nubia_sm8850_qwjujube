__int64 __fastcall sde_evtlog_count(__int64 result)
{
  unsigned int v1; // w9
  unsigned int v2; // w8
  unsigned int v3; // w8

  if ( result )
  {
    v1 = *(_DWORD *)(result + 786448);
    v2 = *(_DWORD *)(result + 786436);
    if ( v2 == v1 )
    {
      return 0;
    }
    else
    {
      if ( v2 < v1 )
        v1 = *(_DWORD *)(result + 786448) & 0x1FFF;
      if ( v2 < (*(_DWORD *)(result + 786448) & 0x1FFFu) )
        v2 += 0x2000;
      v3 = v2 - v1;
      if ( v3 >= 0x2000 )
        return 0x2000;
      else
        return v3;
    }
  }
  return result;
}
