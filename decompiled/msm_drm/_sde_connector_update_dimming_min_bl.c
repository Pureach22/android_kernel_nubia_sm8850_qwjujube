__int64 __fastcall sde_connector_update_dimming_min_bl(__int64 result, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w8

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
      if ( v3 )
      {
        if ( *(_DWORD *)(v3 + 1528) == a2 )
          return 0;
        v4 = *(_DWORD *)(v3 + 1532);
        *(_DWORD *)(v3 + 1528) = a2;
        *(_DWORD *)(v3 + 1532) = v4 | 2;
        sde_dimming_bl_notify(result, v3 + 1472);
        *(_DWORD *)(v3 + 1532) &= ~2u;
        return 0;
      }
      else
      {
        printk(&unk_227B42, "_sde_connector_update_dimming_min_bl");
        return 4294967274LL;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
