__int64 __fastcall target_if_spectral_copy_fft_bins(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int a4,
        _DWORD *a5,
        unsigned __int16 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int *v14; // x22
  unsigned int v16; // w26
  unsigned int v17; // w12
  const char *v19; // x2
  char v20; // w13
  int v21; // w27
  int v22; // w28
  unsigned int v23; // w23
  __int64 v24; // x19
  char v25; // w8
  int v26; // w25
  unsigned int v27; // w24
  int v28; // w8
  __int64 v29; // x20
  int v30; // w8
  __int64 v31; // x20
  int v32; // w8
  __int64 v33; // x25
  int v34; // w9
  __int64 v35; // x20
  unsigned int v37; // [xsp+18h] [xbp-8h]
  unsigned __int16 v38; // [xsp+1Ch] [xbp-4h]

  *a5 = 0;
  if ( !a1 )
  {
    v19 = "%s: spectral lmac object is NULL";
LABEL_9:
    qdf_trace_msg(0x56u, 2u, v19, a7, a8, a9, a10, a11, a12, a13, a14, "target_if_spectral_copy_fft_bins");
    return 29;
  }
  v14 = a2;
  if ( !a2 )
  {
    v19 = "%s: source fft bin buffer is NULL";
    goto LABEL_9;
  }
  if ( !a3 )
  {
    v19 = "%s: destination fft bin buffer is NULL";
    goto LABEL_9;
  }
  v16 = *(unsigned __int8 *)(a1 + 1442);
  v17 = a4 / (4 / v16);
  if ( 4 / v16 <= a4 )
  {
    v20 = 8 * (v16 & 0x1F);
    v21 = 0;
    v22 = 0;
    v23 = a6;
    v24 = ~(-1LL << v20);
    v37 = a4 / (4 / v16);
    v38 = a6;
    do
    {
      v27 = *v14;
      v28 = (__int16)(*v14 & v24);
      if ( v23 == 1 )
      {
        if ( v28 > 127 )
        {
          LOBYTE(v28) = 127;
        }
        else if ( v28 <= -128 )
        {
          LOBYTE(v28) = 0x80;
        }
      }
      else if ( v23 )
      {
        v29 = jiffies;
        if ( clamp_fft_bin_value___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x56u,
            2u,
            "%s: Invalid pwr format: %d.",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "clamp_fft_bin_value",
            v23);
          v20 = 8 * (v16 & 0x1F);
          v17 = v37;
          a6 = v38;
          LOBYTE(v28) = 0;
          clamp_fft_bin_value___last_ticks = v29;
        }
        else
        {
          LOBYTE(v28) = 0;
        }
      }
      else if ( (unsigned int)v28 >= 0xFF )
      {
        LOBYTE(v28) = -1;
      }
      v26 = v21 + 1;
      *(_BYTE *)(a3 + (unsigned __int16)v21) = v28;
      if ( v16 <= 2 )
      {
        v30 = (__int16)((v27 >> v20) & v24);
        if ( a6 )
        {
          if ( a6 == 1 )
          {
            if ( v30 > 127 )
            {
              LOBYTE(v30) = 127;
            }
            else if ( v30 <= -128 )
            {
              LOBYTE(v30) = 0x80;
            }
          }
          else
          {
            v31 = jiffies;
            if ( clamp_fft_bin_value___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x56u,
                2u,
                "%s: Invalid pwr format: %d.",
                a7,
                a8,
                a9,
                a10,
                a11,
                a12,
                a13,
                a14,
                "clamp_fft_bin_value",
                v23);
              v20 = 8 * (v16 & 0x1F);
              v17 = v37;
              a6 = v38;
              LOBYTE(v30) = 0;
              clamp_fft_bin_value___last_ticks = v31;
            }
            else
            {
              LOBYTE(v30) = 0;
            }
          }
        }
        else if ( (unsigned int)v30 >= 0xFF )
        {
          LOBYTE(v30) = -1;
        }
        v26 = v21 + 2;
        *(_BYTE *)(a3 + (unsigned __int16)(v21 + 1)) = v30;
        if ( v16 != 2 )
        {
          v32 = (__int16)((v27 >> (16 * (v16 & 0x1F))) & v24);
          if ( a6 )
          {
            if ( a6 == 1 )
            {
              if ( v32 > 127 )
              {
                LOBYTE(v32) = 127;
              }
              else if ( v32 <= -128 )
              {
                LOBYTE(v32) = 0x80;
              }
            }
            else
            {
              v33 = jiffies;
              if ( clamp_fft_bin_value___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x56u,
                  2u,
                  "%s: Invalid pwr format: %d.",
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  a12,
                  a13,
                  a14,
                  "clamp_fft_bin_value",
                  v23);
                v20 = 8 * (v16 & 0x1F);
                v17 = v37;
                a6 = v38;
                LOBYTE(v32) = 0;
                clamp_fft_bin_value___last_ticks = v33;
              }
              else
              {
                LOBYTE(v32) = 0;
              }
            }
          }
          else if ( (unsigned int)v32 >= 0xFF )
          {
            LOBYTE(v32) = -1;
          }
          *(_BYTE *)(a3 + (unsigned __int16)(v21 + 2)) = v32;
          v34 = (__int16)((v27 >> (24 * (v16 & 0x1F))) & v24);
          if ( a6 )
          {
            if ( a6 == 1 )
            {
              if ( v34 > 127 )
              {
                v25 = 127;
              }
              else if ( v34 <= -128 )
              {
                v25 = 0x80;
              }
              else
              {
                v25 = (v27 >> (24 * (v16 & 0x1F))) & v24;
              }
            }
            else
            {
              v35 = jiffies;
              if ( clamp_fft_bin_value___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x56u,
                  2u,
                  "%s: Invalid pwr format: %d.",
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  a12,
                  a13,
                  a14,
                  "clamp_fft_bin_value",
                  v23);
                v20 = 8 * (v16 & 0x1F);
                v17 = v37;
                a6 = v38;
                v25 = 0;
                clamp_fft_bin_value___last_ticks = v35;
              }
              else
              {
                v25 = 0;
              }
            }
          }
          else if ( (unsigned int)v34 >= 0xFF )
          {
            v25 = -1;
          }
          else
          {
            v25 = (v27 >> (24 * (v16 & 0x1F))) & v24;
          }
          v26 = v21 + 4;
          *(_BYTE *)(a3 + (unsigned __int16)(v21 + 3)) = v25;
        }
      }
      ++v22;
      ++v14;
      v21 = v26;
    }
    while ( v17 > (unsigned __int16)v22 );
  }
  *a5 = 4 * v17;
  return 0;
}
