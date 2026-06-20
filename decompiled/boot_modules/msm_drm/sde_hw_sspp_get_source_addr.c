__int64 __fastcall sde_hw_sspp_get_source_addr(__int64 result, char a2)
{
  int v2; // w9

  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v2 = 24;
    else
      v2 = 20;
    return sde_reg_read(result, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + v2);
  }
  return result;
}
