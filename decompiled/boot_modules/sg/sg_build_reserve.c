__int64 __fastcall sg_build_reserve(__int64 a1, unsigned int a2)
{
  signed int v3; // w20
  __int64 result; // x0

  do
  {
    if ( a2 <= 0x1000 )
      v3 = 4096;
    else
      v3 = a2;
    result = sg_build_indirect(a1 + 112, a1, v3);
    if ( !(_DWORD)result )
      break;
    result = sg_remove_scat((unsigned __int16 *)(a1 + 112));
    a2 = v3 >> 1;
  }
  while ( (unsigned int)(v3 >> 1) > 0x800 );
  return result;
}
