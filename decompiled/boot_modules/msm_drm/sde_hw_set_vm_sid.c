__int64 __fastcall sde_hw_set_vm_sid(__int64 result, int a2, __int64 a3)
{
  if ( result )
  {
    if ( a3 )
      return sde_reg_write(result, 0x2Cu, 4 * a2, "MDP_SID_XIN7");
  }
  return result;
}
