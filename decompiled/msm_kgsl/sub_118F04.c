__int64 __usercall sub_118F04@<X0>(__int64 a1@<X0>, int a2@<W8>)
{
  if ( !a2 )
    JUMPOUT(0x10B304);
  return kgsl_timeline_add_signal(a1);
}
