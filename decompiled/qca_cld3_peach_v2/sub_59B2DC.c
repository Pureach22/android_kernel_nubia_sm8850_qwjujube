__int64 __fastcall sub_59B2DC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( !(_DWORD)a1 )
    JUMPOUT(0x6635C8);
  return wmi_extract_recv_bcn_stats(a1, a2, a3, a4);
}
