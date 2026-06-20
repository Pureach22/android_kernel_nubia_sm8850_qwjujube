__int64 __fastcall sde_connector_update_dimming_ctrl(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned int v4; // w8

  if ( result )
  {
    if ( *(_DWORD *)(result + 2736) == 16 )
    {
      v2 = result + 2760;
      if ( *(_BYTE *)(result + 5128) == 1 )
        v2 = *(_QWORD *)v2;
      if ( !*(_QWORD *)v2 )
        return 0;
      v3 = *(_QWORD *)(*(_QWORD *)v2 + 264LL);
      if ( !v3 )
      {
        printk(&unk_227B42, "_sde_connector_update_dimming_ctrl");
        return 4294967274LL;
      }
      if ( (a2 != 0) == (*(_DWORD *)(v3 + 1532) & 1) )
      {
        return 0;
      }
      else
      {
        v4 = *(_DWORD *)(v3 + 1532) & 0xFFFFFFFE;
        if ( a2 )
          ++v4;
        *(_BYTE *)(v3 + 1536) = 0;
        *(_DWORD *)(v3 + 1532) = v4;
        sde_dimming_bl_notify(result, v3 + 1472);
        result = 0;
        if ( !a2 )
        {
          *(_BYTE *)(v3 + 1536) = 1;
          return 0;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
