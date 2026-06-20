__int64 __fastcall msm_vidc_decoder_bin_size_iris4(__int64 a1)
{
  unsigned int v1; // w9
  int v2; // w12
  unsigned int v3; // w8
  unsigned int v4; // w19
  int v5; // w11
  int v6; // w10
  unsigned int v7; // w10
  int v8; // w10
  unsigned int v9; // w9
  unsigned int v10; // w9
  int v11; // w10
  unsigned int v12; // w9
  unsigned int v13; // w10
  unsigned int v14; // w10
  unsigned int v15; // w9
  unsigned int v17; // w9

  if ( *(_BYTE *)(a1 + 3792) == 1 )
    v1 = ((26 * (*(_DWORD *)(a1 + 3796) & 0x1Eu)) >> 8) + 2;
  else
    v1 = 2;
  v2 = *(_DWORD *)(a1 + 312);
  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4272LL);
  v4 = 0;
  v5 = *(_DWORD *)(a1 + 392);
  v6 = *(_DWORD *)(a1 + 396);
  if ( v2 <= 3 )
  {
    if ( v2 != 1 )
    {
      if ( v2 != 2 )
        goto LABEL_18;
      goto LABEL_13;
    }
    v13 = ((v6 + 15) & 0xFFFFFFF0) * ((v5 + 15) & 0xFFFFFFF0);
    if ( v13 > 0xE6000 )
      v14 = (3 * v13) >> 1;
    else
      v14 = 1413120;
    v15 = v14 * v1;
    v11 = (v15 >> 1) / v3;
    v12 = (3 * v15) >> 1;
LABEL_27:
    v4 = (((v12 / v3 + 255) & 0xFFFFFF00) + ((v11 + 255) & 0xFFFFFF00)) * v3;
    if ( !a1 )
      return v4;
    goto LABEL_28;
  }
  if ( v2 == 4 )
  {
    v10 = (3 * ((v5 + 15) & 0xFFFFFFF0) * ((v6 + 15) & 0xFFFFFFF0)) >> 1;
    if ( v10 <= 0x159000 )
      v10 = 1413120;
    v11 = v10 / v3;
    v12 = 3 * v10;
    goto LABEL_27;
  }
  if ( v2 != 8 )
  {
    if ( v2 != 16 )
      goto LABEL_18;
    if ( *(_QWORD *)(a1 + 31904) )
    {
      v4 = 0;
      if ( !a1 )
        return v4;
      goto LABEL_28;
    }
    v17 = ((v6 + 15) & 0xFFFFFFF0) * ((v5 + 15) & 0xFFFFFFF0);
    if ( v17 > 0xE6000 )
      v9 = (3 * v17) & 0x7FFFFF00;
    else
      v9 = 2826240;
    goto LABEL_17;
  }
LABEL_13:
  v7 = ((v6 + 15) & 0xFFFFFFF0) * ((v5 + 15) & 0xFFFFFFF0);
  if ( v7 > 0xE6000 )
    v8 = 3 * v7;
  else
    v8 = 2826240;
  v9 = (v8 * v1) >> 1;
LABEL_17:
  v4 = 2 * v3 * ((v9 / v3 + 255) & 0x7FFFFF00);
LABEL_18:
  if ( !a1 )
    return v4;
LABEL_28:
  if ( (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FA63, "low ", a1 + 340, "msm_vidc_decoder_bin_size_iris4", v4);
  return v4;
}
