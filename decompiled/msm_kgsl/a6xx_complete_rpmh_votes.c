void __fastcall a6xx_complete_rpmh_votes(__int64 a1, unsigned int a2)
{
  int v4; // w21

  v4 = **(_DWORD **)(a1 + 14264);
  if ( (unsigned int)(v4 - 620) <= 0x28 && ((1LL << ((unsigned __int8)v4 - 108)) & 0x10040000001LL) != 0 )
  {
    timed_poll_check_rscc(a1, 838, 1u, a2, 1u);
    timed_poll_check_rscc(a1, 1006, 1u, a2, 1u);
    timed_poll_check_rscc(a1, 1174, 1u, a2, 1u);
    timed_poll_check_rscc(a1, 1342, 1u, a2, 1u);
    timed_poll_check_rscc(a1, 1510, 1u, a2, 1u);
    JUMPOUT(0x88A30);
  }
  JUMPOUT(0x88AF0);
}
