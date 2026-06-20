__int64 __usercall sub_14375C@<X0>(__int64 a1@<X0>, int a2@<W8>)
{
  unsigned int v2; // w23

  return cam_sync_util_find_and_set_empty_row(a1, a2 - (v2 >> 11));
}
