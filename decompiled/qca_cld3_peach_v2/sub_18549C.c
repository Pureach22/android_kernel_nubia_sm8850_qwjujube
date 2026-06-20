__int64 __fastcall sub_18549C(__int64 a1, __int64 a2, __int64 a3)
{
  if ( (a1 & 0x20000000000000LL) == 0 )
    JUMPOUT(0x1803B0);
  return osif_cm_disconnect_comp_ind(a1, a2, a3);
}
