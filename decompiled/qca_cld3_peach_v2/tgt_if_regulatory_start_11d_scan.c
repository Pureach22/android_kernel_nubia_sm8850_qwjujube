__int64 __fastcall tgt_if_regulatory_start_11d_scan(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 && *(_QWORD *)(v1 + 16) )
    return wmi_unified_send_start_11d_scan_cmd();
  else
    return 16;
}
