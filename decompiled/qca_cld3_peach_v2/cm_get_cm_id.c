__int64 __fastcall cm_get_cm_id(unsigned int *a1, unsigned int a2)
{
  int v2; // w8
  int v3; // w9
  unsigned int v4; // w8
  unsigned int v5; // w11
  unsigned int v13; // w10
  unsigned int v14; // w10

  if ( a2 > 0x14 )
    v2 = 218103808;
  else
    v2 = dword_AD1FD8[a2];
  v3 = *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL);
  _X11 = a1 + 47;
  __asm { PRFM            #0x11, [X11] }
  do
  {
    v13 = __ldxr(_X11);
    v14 = v13 + 1;
  }
  while ( __stlxr(v14, _X11) );
  __dmb(0xBu);
  v4 = (unsigned __int16)v14 | (v3 << 16) | v2;
  v5 = v4 | 0x10000000;
  if ( a2 == 15 )
    v4 |= 0x20000000u;
  if ( a2 - 17 >= 2 )
    return v4;
  else
    return v5;
}
