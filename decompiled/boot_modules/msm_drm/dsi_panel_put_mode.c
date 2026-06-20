__int64 __fastcall dsi_panel_put_mode(__int64 result)
{
  __int64 v1; // x19
  __int64 i; // x20
  __int64 v3; // x8
  __int64 v4; // x22
  unsigned __int64 v5; // x23
  __int64 v6; // x24

  if ( *(_QWORD *)(result + 184) )
  {
    v1 = result;
    for ( i = 0; i != 59; ++i )
    {
      v3 = *(_QWORD *)(v1 + 184);
      v4 = v3 + 40 * i;
      if ( *(_DWORD *)(v4 + 8) )
      {
        v5 = 0;
        v6 = 16;
        do
        {
          kfree(*(_QWORD *)(*(_QWORD *)(v4 + 16) + v6));
          ++v5;
          v6 += 64;
        }
        while ( v5 < *(unsigned int *)(v4 + 8) );
        v3 = *(_QWORD *)(v1 + 184);
      }
      kfree(*(_QWORD *)(v3 + 40 * i + 16));
    }
    return kfree(*(_QWORD *)(v1 + 184));
  }
  return result;
}
