__int64 __fastcall hif_wlan_disable(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1

  result = hif_get_conparam(a1);
  if ( *(_DWORD *)(a1 + 600) != 1 )
  {
    if ( (_DWORD)result == 5 )
      v3 = 1;
    else
      v3 = 2 * (unsigned int)((_DWORD)result == 8);
    return pld_wlan_disable(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v3);
  }
  return result;
}
