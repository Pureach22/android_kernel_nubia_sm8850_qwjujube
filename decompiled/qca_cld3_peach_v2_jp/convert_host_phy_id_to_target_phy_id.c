__int64 __fastcall convert_host_phy_id_to_target_phy_id(__int64 a1, unsigned int a2)
{
  if ( a2 <= 2 && (*(_BYTE *)(*(_QWORD *)(a1 + 760) + 7749LL) & 1) != 0 )
    return *(unsigned int *)(*(_QWORD *)(a1 + 872) + 4LL * a2);
  return a2;
}
