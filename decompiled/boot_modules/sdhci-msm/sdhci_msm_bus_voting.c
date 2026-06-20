__int64 __fastcall sdhci_msm_bus_voting(__int64 a1, char a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x11
  unsigned int v4; // w1

  if ( (a2 & 1) != 0 )
  {
    v2 = *(_QWORD *)(a1 + 1520);
    v3 = v2 >> 3;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1055LL) == 2 )
      v2 >>= 1;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1055LL) )
      v4 = v2;
    else
      v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  return sdhci_msm_bus_get_and_set_vote(a1, v4);
}
