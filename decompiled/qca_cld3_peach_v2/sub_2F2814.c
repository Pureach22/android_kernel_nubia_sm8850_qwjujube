__int64 __fastcall sub_2F2814(__int64 a1, __int64 a2)
{
  if ( (a1 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x2F5AE8);
  return cm_send_roam_invoke_req(a1, a2);
}
