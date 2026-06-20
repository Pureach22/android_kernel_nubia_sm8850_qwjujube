__int64 __fastcall get_next_record_index(unsigned int *_X0, int a2)
{
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v11; // w9

  __asm { PRFM            #0x11, [X0] }
  do
  {
    v8 = __ldxr(_X0);
    v9 = v8 + 1;
  }
  while ( __stlxr(v9, _X0) );
  __dmb(0xBu);
  if ( v9 == a2 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v11 = __ldxr(_X0);
    while ( __stxr(v11 - a2, _X0) );
  }
  LODWORD(result) = v9 + a2;
  do
    result = (unsigned int)(result - a2);
  while ( (int)result >= a2 );
  return result;
}
