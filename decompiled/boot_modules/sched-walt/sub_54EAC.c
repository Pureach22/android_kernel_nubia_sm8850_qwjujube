__int64 sub_54EAC()
{
  unsigned int *v0; // x19

  atomic_load(v0);
  return walt_get_ncc_gclk_cycle_counter();
}
