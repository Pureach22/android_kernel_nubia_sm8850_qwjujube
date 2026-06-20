int *__fastcall hal_compute_reo_remap_ix2_ix3_peach(int *result, int a2, int *a3, int *a4)
{
  int v4; // w11
  int v5; // w12
  int v6; // w8
  int v7; // w9
  int v8; // w10
  int v9; // w8
  int v10; // w11
  int v11; // w9
  int v12; // w9

  v4 = result[1];
  v5 = result[2];
  v6 = *result;
  v7 = 16 * v4;
  v8 = v5 << 8;
  if ( a2 == 4 )
  {
    *a3 = (v6 << 16) | (v4 << 20) | (v5 << 24) | (result[3] << 12) | (result[3] << 28) | v8 | v7 | v6;
    v9 = *result;
    v12 = (*result << 16)
        | (16 * result[1])
        | (result[1] << 20)
        | (result[2] << 8)
        | (result[2] << 24)
        | (result[3] << 12)
        | (result[3] << 28);
  }
  else
  {
    if ( a2 == 6 )
    {
      *a3 = (v6 << 24) | (v4 << 28) | (result[3] << 12) | (result[4] << 16) | (result[5] << 20) | v8 | v7 | v6;
      v9 = result[2];
      v10 = result[1];
      v11 = (v9 << 24) | (16 * result[3]) | (result[3] << 28) | (result[4] << 8) | (result[5] << 12) | (*result << 16);
    }
    else
    {
      if ( a2 == 8 )
      {
        *a3 = (result[3] << 12)
            | (result[4] << 16)
            | (result[5] << 20)
            | (result[6] << 24)
            | (result[7] << 28)
            | v8
            | v6
            | v7;
        *a4 = *result
            | (16 * result[1])
            | (result[2] << 8)
            | (result[3] << 12)
            | (result[4] << 16)
            | (result[5] << 20)
            | (result[6] << 24)
            | (result[7] << 28);
        return result;
      }
      *a3 = (v6 << 12) | (v6 << 24) | (v4 << 16) | (v4 << 28) | (v5 << 20) | v8 | v7 | v6;
      v10 = result[1];
      v9 = result[2];
      v11 = (v9 << 12) | (v9 << 24) | (16 * *result) | (*result << 16) | (*result << 28) | (v10 << 8);
    }
    v12 = v11 | (v10 << 20);
  }
  *a4 = v12 | v9;
  return result;
}
