__int64 __usercall clear_reserved@<X0>(__int64 result@<X0>, _BYTE *a2@<X8>)
{
  unsigned __int64 v8; // x10

  if ( (unsigned int)result >= 0x20 )
    __break(0x5512u);
  else
    a2 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)result)];
  _X8 = (unsigned __int64 *)(a2 + 80);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  return result;
}
