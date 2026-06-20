__int64 __usercall sub_6388@<X0>(__int64 a1@<X7>, __int64 a2@<X8>)
{
  *(_QWORD *)(a2 - 432) = a1;
  *(_QWORD *)(a2 - 424) = a2;
  return qcom_hwspinlock_bust();
}
