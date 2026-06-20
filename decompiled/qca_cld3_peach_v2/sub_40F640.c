__int64 __fastcall sub_40F640(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w18

  if ( (v4 & 0x4000000) == 0 )
    JUMPOUT(0x409AE8);
  return lim_post_sm_state_update(a1, a2, a3, a4);
}
