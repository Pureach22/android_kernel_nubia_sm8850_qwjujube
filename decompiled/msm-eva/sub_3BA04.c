__int64 __usercall sub_3BA04@<X0>(__int16 a1@<W8>)
{
  __int64 v1; // x30

  *(_WORD *)(v1 + 5370) = a1;
  return msm_cvp_set_sysprop_sess();
}
