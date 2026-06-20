__int64 __fastcall sub_2BF268(__int64 a1, __int64 a2)
{
  if ( (a1 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x2C253C);
  return cm_send_roam_invoke_req(a1, a2);
}
