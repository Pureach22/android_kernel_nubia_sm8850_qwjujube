bool __fastcall ucfg_mlme_check_bit_in_rso_disabled_bitmap(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  return ((unsigned __int8)mlme_get_rso_disabled_bitmap(a1, a2) & a3) != 0;
}
