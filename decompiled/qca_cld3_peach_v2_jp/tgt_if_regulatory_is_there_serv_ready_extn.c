__int64 __fastcall tgt_if_regulatory_is_there_serv_ready_extn(__int64 a1)
{
  __int64 v1; // x8

  if ( !a1 )
    return a1 & 1;
  v1 = *(_QWORD *)(a1 + 2800);
  if ( v1 )
  {
    a1 = *(_QWORD *)(v1 + 16);
    if ( a1 )
      LOBYTE(a1) = wmi_service_enabled(a1, 92);
    return a1 & 1;
  }
  return 0;
}
