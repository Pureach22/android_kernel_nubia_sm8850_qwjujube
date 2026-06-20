__int64 __fastcall sub_586D58(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x9

  return hal_tx_comp_get_status_generic_be(a1, a2, a3, a4, (__int128)v4 >> 12);
}
