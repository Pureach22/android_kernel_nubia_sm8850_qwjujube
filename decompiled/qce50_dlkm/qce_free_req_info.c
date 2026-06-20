__int64 __usercall qce_free_req_info@<X0>(
        __int64 result@<X0>,
        unsigned int a2@<W1>,
        char a3@<W2>,
        unsigned int *_X8@<X8>)
{
  __int64 v4; // x9
  unsigned int v11; // w9
  unsigned int v13; // w10

  if ( a2 >= 9 )
  {
    __break(0x5512u);
LABEL_11:
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 - 1, _X8) );
    return result;
  }
  v4 = result + 7432LL * a2;
  *(_DWORD *)(v4 + 2632) = 5;
  _X11 = (unsigned int *)(v4 + 2624);
  __asm { PRFM            #0x11, [X11] }
  do
    v11 = __ldxr(_X11);
  while ( __stlxr(0, _X11) );
  __dmb(0xBu);
  if ( !v11 )
    return printk(&unk_15B49, "qce_free_req_info", a2);
  if ( a2 != 8 && (a3 & 1) != 0 )
  {
    _X8 = (unsigned int *)(result + 69520);
    goto LABEL_11;
  }
  return result;
}
