__int64 __usercall sub_A990@<X0>(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x12
  __int64 v3; // x13

  *(_QWORD *)(v3 - 400) = a2;
  *(_QWORD *)(v3 - 392) = v2;
  return _append__async_reqs(a1);
}
