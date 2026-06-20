__int64 __fastcall sub_35DFA8(__int64 a1, int _W1)
{
  __asm { STLLR           W1, [X1] }
  return hdd_get_link_info_by_vdev(a1);
}
