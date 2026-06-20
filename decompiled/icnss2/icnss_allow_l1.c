__int64 __fastcall icnss_allow_l1(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 152);
  if ( (*(_QWORD *)(result + 1832) & 0x200) == 0 && (*(_QWORD *)(result + 1832) & 0x10000) != 0 )
    return icnss_send_smp2p(result, 6, 2u);
  return result;
}
