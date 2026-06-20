__int64 __fastcall extract_dbam_config_resp_event_tlv(__int64 a1, __int64 a2, int *a3)
{
  __int64 v3; // x8
  int v4; // w8

  v3 = *(unsigned int *)(*(_QWORD *)a2 + 4LL);
  if ( (unsigned int)v3 > 3 )
    v4 = 2;
  else
    v4 = dword_A2F9E8[v3];
  *a3 = v4;
  return 0;
}
