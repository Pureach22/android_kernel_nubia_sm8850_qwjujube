bool __fastcall policy_mgr_init_disallow_mode_bmap(_DWORD *a1)
{
  if ( a1 )
  {
    a1[32] = -1;
    a1[34] = -1;
    a1[36] = -1;
    a1[38] = -1;
  }
  return a1 != nullptr;
}
