__int64 __usercall sub_6A1C70@<X0>(unsigned int a1@<W8>)
{
  __int64 v1; // x26

  atomic_store(a1, (unsigned int *)(v1 - 106));
  return hdd_mlo_channel_switch_notify();
}
