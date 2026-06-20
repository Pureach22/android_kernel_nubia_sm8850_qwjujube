_DWORD *__fastcall cam_cdm_write_regcontinuous(unsigned __int64 *a1, int a2, unsigned int a3, int *a4)
{
  _DWORD *v4; // x0
  __int64 v5; // x9
  _DWORD *v6; // x10
  int v7; // t1

  *a1 = (unsigned __int16)a3 | ((unsigned __int64)(a2 & 0xFFFFFF) << 32) | 0x3000000;
  v4 = a1 + 1;
  if ( a3 )
  {
    v5 = a3;
    v6 = v4;
    do
    {
      v7 = *a4++;
      --v5;
      *v6++ = v7;
    }
    while ( v5 );
  }
  return &v4[a3];
}
