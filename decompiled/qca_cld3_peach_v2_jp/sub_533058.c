__int64 __fastcall sub_533058(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( !(_DWORD)a1 )
    JUMPOUT(0x5FB344);
  return wmi_extract_recv_bcn_stats(a1, a2, a3, a4);
}
