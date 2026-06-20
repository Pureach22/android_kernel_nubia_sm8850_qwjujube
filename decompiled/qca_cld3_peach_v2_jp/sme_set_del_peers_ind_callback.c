__int64 __fastcall sme_set_del_peers_ind_callback(__int64 result, __int64 a2)
{
  if ( result )
    *(_QWORD *)(result + 21576) = a2;
  return result;
}
