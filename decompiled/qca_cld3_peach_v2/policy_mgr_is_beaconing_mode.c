bool __fastcall policy_mgr_is_beaconing_mode(int a1)
{
  return a1 == 6 || (a1 & 0xFFFFFFFD) == 1;
}
