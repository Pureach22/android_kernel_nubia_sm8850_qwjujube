__int64 __fastcall msm_vidc_enc_delivery_mode_based_output_buf_size(__int64 a1, unsigned int a2)
{
  int v2; // w9
  __int64 result; // x0
  int v5; // w10
  int v6; // w11
  __int64 v7; // x8
  bool v8; // zf
  int v9; // w9
  unsigned int v10; // w10
  char v11; // w12
  __int64 v12; // x9

  v2 = *(_DWORD *)(a1 + 608);
  result = a2;
  if ( (v2 == 1129727304 || v2 == 875967048)
    && *(_QWORD *)(a1 + 16952) == 1
    && *(_DWORD *)(a1 + 308) != 2
    && *(_QWORD *)(a1 + 12920) )
  {
    v5 = *(_DWORD *)(a1 + 600);
    v6 = *(_DWORD *)(a1 + 604);
    v7 = *(_QWORD *)(a1 + 30896);
    v8 = v2 == 1129727304;
    if ( v2 == 1129727304 )
      v9 = 31;
    else
      v9 = 15;
    v10 = v9 + v5;
    if ( v8 )
      v11 = 5;
    else
      v11 = 4;
    v12 = ((unsigned int)(v9 + v6) >> v11) * (v10 >> v11);
    return ((unsigned int)((v12 + v7 * a2 - 1) / v12) + 4095) & 0xFFFFF000;
  }
  return result;
}
