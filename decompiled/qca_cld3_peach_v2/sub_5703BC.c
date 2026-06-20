__int64 __fastcall sub_5703BC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (a1 & 4) != 0 )
    JUMPOUT(0x57593C);
  return dp_mlo_latency_req(a1, a2, a3, a4);
}
