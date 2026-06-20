__int64 __fastcall sme_set_chan_info_callback(__int64 result, __int64 a2)
{
  if ( result )
    *(_QWORD *)(result + 21568) = a2;
  return result;
}
