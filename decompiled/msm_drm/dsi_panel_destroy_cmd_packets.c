__int64 __fastcall dsi_panel_destroy_cmd_packets(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x20
  __int64 v3; // x21

  if ( *(_DWORD *)(result + 8) )
  {
    v1 = result;
    v2 = 0;
    v3 = 16;
    do
    {
      result = kfree(*(_QWORD *)(*(_QWORD *)(v1 + 16) + v3));
      ++v2;
      v3 += 64;
    }
    while ( v2 < *(unsigned int *)(v1 + 8) );
  }
  return result;
}
