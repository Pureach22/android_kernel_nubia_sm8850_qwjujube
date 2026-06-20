__int64 __fastcall ce_recv_entries_done_nolock_srng(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x8
  unsigned int v3; // w9
  unsigned int v4; // w10
  bool v5; // cf
  unsigned int v6; // w9

  v2 = *(_DWORD **)(*(_QWORD *)(a2 + 152) + 80LL);
  v3 = v2[30];
  v4 = v2[34];
  v5 = v4 >= v3;
  v6 = v4 - v3;
  if ( !v5 )
    v6 += v2[9];
  return v6 / v2[11];
}
