__int64 __fastcall sap_cac_reset_current_notify(__int64 result)
{
  *(_WORD *)(result + 1553) = 0;
  return result;
}
