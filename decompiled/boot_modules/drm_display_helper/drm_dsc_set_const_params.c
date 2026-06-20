__int64 __fastcall drm_dsc_set_const_params(__int64 result)
{
  unsigned int v1; // w9
  char v2; // w8

  if ( !*(_WORD *)(result + 104) )
    *(_WORD *)(result + 104) = 0x2000;
  v1 = *(unsigned __int8 *)(result + 1);
  *(_BYTE *)(result + 18) = 6;
  *(_WORD *)(result + 14) = 771;
  if ( v1 >= 0xB )
    v2 = 64;
  else
    v2 = 48;
  *(_BYTE *)(result + 121) = v2;
  return result;
}
