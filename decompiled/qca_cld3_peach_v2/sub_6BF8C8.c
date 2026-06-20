__int64 __usercall sub_6BF8C8@<X0>(__int64 a1@<X0>, unsigned int a2@<W8>)
{
  __int64 v2; // x26

  atomic_store(a2, (unsigned int *)(v2 - 106));
  return mlo_mgr_standby_link_csa_notify(a1);
}
