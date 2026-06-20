__int64 __fastcall icnss_prevent_l1(__int64 a1)
{
  __int64 v1; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( (*(_QWORD *)(v1 + 1832) & 0x200) == 0 && (*(_QWORD *)(v1 + 1832) & 0x10000) != 0 )
    return icnss_send_smp2p(v1, 7, 2u);
  else
    return 0;
}
