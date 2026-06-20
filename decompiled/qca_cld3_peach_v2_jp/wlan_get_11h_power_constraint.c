__int64 __fastcall wlan_get_11h_power_constraint(__int64 a1, _BYTE *a2)
{
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1061LL) == 1 && *a2 )
    return (unsigned __int8)a2[1];
  else
    return 0;
}
