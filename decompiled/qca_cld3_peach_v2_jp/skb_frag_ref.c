__int64 __usercall skb_frag_ref@<X0>(__int64 result@<X0>, unsigned int a2@<W1>, __int64 a3@<X8>)
{
  __int64 v3; // x9
  unsigned int v10; // w9

  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
  }
  else
  {
    a3 = *(_QWORD *)(*(_QWORD *)(result + 216) + *(unsigned int *)(result + 212) + 16LL * a2 + 88);
    if ( (a3 & 1) != 0 )
      a3 = 0;
    v3 = *(_QWORD *)(a3 + 8);
    if ( (v3 & 1) != 0 )
      a3 = v3 - 1;
  }
  _X8 = (unsigned int *)(a3 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 + 1, _X8) );
  return result;
}
