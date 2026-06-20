__int64 __usercall sub_471C8@<X0>(__int64 a1@<X7>, __int64 a2@<X8>)
{
  __int64 v2; // x25

  *(_QWORD *)(a2 - 256) = v2;
  *(_QWORD *)(a2 - 248) = a1;
  return cvp_release_dsp_buffers();
}
