__int64 __fastcall msm_vidc_encoder_input_meta_size(__int64 a1)
{
  int v1; // w8
  unsigned int v2; // w9
  int v3; // w10
  int v4; // w11
  int v5; // w12
  int v6; // w11
  char v7; // w11
  unsigned int v8; // w12
  unsigned int v9; // w8

  if ( *(_QWORD *)(a1 + 8216) )
  {
    v1 = *(_DWORD *)(a1 + 396);
    if ( *(_DWORD *)(a1 + 608) == 1129727304 )
      v2 = 32;
    else
      v2 = 16;
    v3 = *(_DWORD *)(a1 + 392);
    if ( *(_DWORD *)(a1 + 312) == 8 )
    {
      v4 = *(_DWORD *)(a1 + 26528);
      v5 = v4 - 1;
      v6 = -v4;
      v3 = (v5 + v3) & v6;
      v1 = (v5 + v1) & v6;
    }
    v7 = 0;
    do
    {
      v8 = v2;
      v2 >>= 1;
      ++v7;
    }
    while ( v8 && (v8 & 2) == 0 );
    v9 = (2 * ((v2 - 1 + v1) >> v7) * ((((v2 - 1 + v3) >> v7) + 7) & 0x7FFFFFF8) + 20479) & 0xFFFFF000;
  }
  else
  {
    v9 = 0x4000;
  }
  if ( *(_QWORD *)(a1 + 8720) )
    return (v9 + 46079) & 0xFFFFF000;
  else
    return v9;
}
