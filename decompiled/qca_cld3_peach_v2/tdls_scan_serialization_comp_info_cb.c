void __fastcall tdls_scan_serialization_comp_info_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x0

  if ( a2 )
  {
    v3 = tdls_soc_global;
    *(_BYTE *)(a2 + 1) = 0;
    if ( (unsigned int)tdls_scan_callback(v3) == 8 )
      *(_BYTE *)(a2 + 1) = 1;
  }
}
