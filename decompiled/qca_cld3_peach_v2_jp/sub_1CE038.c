__int64 __usercall sub_1CE038@<X0>(__int64 a1@<X8>, long double a2@<Q5>)
{
  *(long double *)(a1 + 51280) = a2;
  return wlan_cm_get_curr_candidate_entry();
}
