__int64 __fastcall msm_vidc_decoder_line_size_iris4(__int64 a1)
{
  int v2; // w20
  int v3; // w12
  unsigned int v4; // w8
  __int64 result; // x0
  unsigned int v6; // w9
  int v7; // w10
  int v8; // w11
  __int64 v9; // x12
  __int64 v10; // x12
  _BOOL8 v11; // x10
  unsigned int *v12; // x11
  unsigned int v13; // w11
  __int64 v14; // x12
  __int64 v15; // x10
  __int64 v16; // x10
  __int64 v17; // x9
  int v18; // w14
  unsigned int v19; // w12
  __int64 v20; // x13
  unsigned int v21; // w0
  unsigned int v22; // w3
  int v23; // w12
  int v24; // w17
  unsigned int v25; // w13
  unsigned int v26; // w9
  bool v27; // zf
  unsigned int v28; // w8
  int v29; // w8
  unsigned int v30; // w9
  unsigned int v31; // w11
  unsigned int *v32; // x8
  unsigned int v33; // w8
  __int64 v34; // x9
  char *v35; // x10
  unsigned int v36; // w14
  int v37; // w12
  unsigned int v38; // w10
  unsigned int v39; // w11
  __int64 v40; // x12
  unsigned int v41; // w8
  unsigned int v42; // w9
  unsigned int v43; // w8
  int v44; // w14
  unsigned int v45; // w12
  __int64 v46; // x13
  unsigned int v47; // w0
  unsigned int v48; // w3
  int v49; // w12
  int v50; // w17
  unsigned int v51; // w13
  unsigned int v52; // w9
  unsigned int v53; // w8
  int v54; // w8
  unsigned int v55; // w9
  unsigned int v56; // w11
  unsigned int v57; // w9
  unsigned int v58; // w10
  int v59; // w12
  __int64 v60; // x13
  unsigned int v61; // w16
  unsigned int v62; // w0
  int v63; // w12
  unsigned int v64; // w15
  unsigned int v65; // w14
  int v66; // w13
  int v67; // w16
  unsigned int v68; // w9
  int v69; // w8
  int v70; // w9
  unsigned int v71; // w10
  unsigned int v72; // w9
  int v73; // w13
  unsigned int v74; // w10
  __int64 v75; // x12
  bool v76; // cc
  __int64 v77; // x8
  __int64 v78; // x2
  unsigned int v79; // w19

  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4272LL);
  v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 608), "msm_vidc_decoder_line_size_iris4");
  v3 = *(_DWORD *)(a1 + 312);
  v4 = *(_DWORD *)(a1 + 392);
  result = 0;
  v6 = *(_DWORD *)(a1 + 396);
  v7 = *(_DWORD *)(a1 + 1904);
  v8 = *(_DWORD *)(a1 + 1908);
  if ( v3 > 3 )
  {
    if ( v3 == 4 )
    {
      v11 = v6 > v4;
      v12 = (unsigned int *)((char *)&unk_9E8AC + 16 * v11);
      if ( v4 <= *v12 )
      {
        v13 = 0;
      }
      else if ( v4 <= v12[1] )
      {
        v13 = 1;
      }
      else if ( v4 <= v12[2] )
      {
        v13 = 2;
      }
      else
      {
        v13 = 3;
      }
      v32 = (unsigned int *)((char *)&unk_9E8AC + 16 * (v6 <= v4));
      if ( v6 <= *v32 )
      {
        v33 = 0;
      }
      else if ( v6 <= v32[1] )
      {
        v33 = 1;
      }
      else if ( v6 <= v32[2] )
      {
        v33 = 2;
      }
      else
      {
        v33 = 3;
      }
      v34 = 4 * v11;
      v35 = (char *)&unk_9E7EC + 16 * v11;
      if ( v13 <= v33 )
        v36 = v33;
      else
        v36 = v13;
      result = (unsigned int)(dword_9E7CC[v34 + v33]
                            + *(_DWORD *)&v35[4 * v13]
                            + dword_9E71C[v36]
                            + (dword_9E86C[v34 + v33] + 2 * dword_9E82C[v34 + v33]) * v2);
      goto LABEL_143;
    }
    if ( v3 != 8 )
    {
      if ( v3 != 16 )
        goto LABEL_143;
      if ( *(_QWORD *)(a1 + 20312) )
      {
        if ( v6 >= 0x501 )
        {
          if ( v6 >= 0x781 )
          {
            v9 = 2;
            if ( v6 > 0x1000 )
              v9 = 3;
          }
          else
          {
            v9 = 1;
          }
        }
        else
        {
          v9 = 0;
        }
        v59 = dword_9E6DC[v9];
        if ( v4 >= 0x501 )
        {
          if ( v4 >= 0x781 )
          {
            v60 = 2;
            if ( v4 > 0x1000 )
              v60 = 3;
          }
          else
          {
            v60 = 1;
          }
        }
        else
        {
          v60 = 0;
        }
        v61 = (v6 + 7) & 0xFFFFFFF8;
        v62 = 32 * v61;
        v63 = v59 * v2;
        v64 = v61 << 6;
        v65 = ((8 * v4 + 248) & 0xFFFFFF00) + 7936;
        v66 = dword_9E88C[2 * v60 + 1];
        v67 = 16 * v7;
        if ( v65 <= v62 )
          v65 = v62;
        if ( v6 == v8 )
        {
          v68 = 0;
          v27 = v4 == v7;
          v53 = 0;
          if ( v27 )
            goto LABEL_122;
        }
        else
        {
          v69 = v7 << (v4 > 4 * v7);
          if ( v6 <= 4 * v8 )
          {
            v72 = 0;
            v71 = 0;
          }
          else
          {
            v70 = 8 * v7;
            v71 = (v67 + 224) & 0xFFFFFF00;
            v72 = (v70 + 248) & 0xFFFFFF00;
          }
          v68 = ((8 * v69 + 248) & 0xFFFFFF00) + ((16 * v69 + 224) & 0xFFFFFF00) + v72 + v71;
        }
        v53 = ((v67 + 224) & 0xFFFFFF00) + ((v67 + 240) & 0xFFFFFF00) + v68;
LABEL_122:
        v57 = v64 + 2 * v65;
        v58 = v63 + v66;
        goto LABEL_123;
      }
      if ( v6 >= 0x501 )
      {
        if ( v6 >= 0x781 )
        {
          v76 = v6 > 0x1000;
          v17 = 2;
          if ( v76 )
            v17 = 3;
        }
        else
        {
          v17 = 1;
        }
      }
      else
      {
        v17 = 0;
      }
      v42 = dword_9E6DC[v17] * v2;
      if ( v4 >= 0x501 )
      {
        if ( v4 >= 0x781 )
        {
          v76 = v4 > 0x1000;
          v77 = 2;
          if ( v76 )
            v77 = 3;
        }
        else
        {
          v77 = 1;
        }
      }
      else
      {
        v77 = 0;
      }
      v43 = dword_9E88C[2 * v77 + 1];
      goto LABEL_142;
    }
LABEL_10:
    if ( !*(_QWORD *)(a1 + 20312) )
    {
      if ( v6 >= 0x501 )
      {
        if ( v6 >= 0x781 )
        {
          v15 = 2;
          if ( v6 > 0x1000 )
            v15 = 3;
        }
        else
        {
          v15 = 1;
        }
      }
      else
      {
        v15 = 0;
      }
      v37 = dword_9E6EC[v15];
      v38 = (((dword_9E73C[v15] + 255) & 0xFFFFFF00)
           + ((dword_9E70C[v15] + 255) & 0xFFFFFF00)
           + ((dword_9E74C[v15] + 255) & 0xFFFFFF00))
          * v2;
      v39 = (v37 + 255) & 0xFFFFFF00;
      if ( v4 >= 0x501 )
      {
        if ( v4 >= 0x781 )
        {
          v40 = 2;
          if ( v4 > 0x1000 )
            v40 = 3;
        }
        else
        {
          v40 = 1;
        }
      }
      else
      {
        v40 = 0;
      }
      v41 = ((2 * v4 + 126) & 0xFFFFFF80) * ((v6 + 63) >> 6) + 255;
      v42 = (dword_9E77C[v40] + 255) & 0xFFFFFF00;
      v43 = v39 + v38 + (v41 & 0xFFFFFF00);
LABEL_142:
      result = v43 + v42;
      goto LABEL_143;
    }
    if ( v6 >= 0x501 )
    {
      if ( v6 >= 0x781 )
      {
        v10 = 2;
        if ( v6 > 0x1000 )
          v10 = 3;
      }
      else
      {
        v10 = 1;
      }
    }
    else
    {
      v10 = 0;
    }
    v18 = dword_9E6EC[v10] + 255;
    v19 = ((dword_9E73C[v10] + 255) & 0xFFFFFF00)
        + ((dword_9E70C[v10] + 255) & 0xFFFFFF00)
        + ((dword_9E74C[v10] + 255) & 0xFFFFFF00);
    if ( v4 >= 0x501 )
    {
      if ( v4 >= 0x781 )
      {
        v20 = 2;
        if ( v4 > 0x1000 )
          v20 = 3;
      }
      else
      {
        v20 = 1;
      }
    }
    else
    {
      v20 = 0;
    }
    v21 = (v6 + 7) & 0xFFFFFFF8;
    v22 = ((2 * v4 + 126) & 0xFFFFFF80) * ((v6 + 63) >> 6) + 255;
    v23 = v19 * v2;
    v24 = dword_9E77C[v20] + 255;
    if ( ((8 * v4 + 248) & 0xFFFFFF00) + 7936 <= 32 * v21 )
      v25 = 32 * v21;
    else
      v25 = ((8 * v4 + 248) & 0xFFFFFF00) + 7936;
    if ( v6 == v8 )
    {
      v26 = 0;
      v27 = v4 == v7;
      v28 = 0;
      if ( v27 )
        goto LABEL_54;
    }
    else
    {
      v29 = v7 << (v4 > 4 * v7);
      if ( v6 <= 4 * v8 )
      {
        v30 = 0;
        v31 = 0;
      }
      else
      {
        v30 = (8 * v7 + 248) & 0xFFFFFF00;
        v31 = (16 * v7 + 224) & 0xFFFFFF00;
      }
      v26 = ((8 * v29 + 248) & 0xFFFFFF00) + ((16 * v29 + 224) & 0xFFFFFF00) + v30 + v31;
    }
    v28 = ((16 * v7 + 224) & 0xFFFFFF00) + ((16 * v7 + 240) & 0xFFFFFF00) + v26;
LABEL_54:
    result = (v22 & 0xFFFFFF00) + (v21 << 6) + 2 * v25 + (v18 & 0xFFFFFF00) + v23 + (v24 & 0xFFFFFF00) + v28;
    goto LABEL_143;
  }
  if ( v3 != 1 )
  {
    if ( v3 != 2 )
      goto LABEL_143;
    goto LABEL_10;
  }
  if ( *(_QWORD *)(a1 + 20312) )
  {
    if ( v6 >= 0x501 )
    {
      if ( v6 >= 0x781 )
      {
        v14 = 2;
        if ( v6 > 0x1000 )
          v14 = 3;
      }
      else
      {
        v14 = 1;
      }
    }
    else
    {
      v14 = 0;
    }
    v44 = dword_9E6EC[v14] + 255;
    v45 = ((dword_9E6CC[v14] + 255) & 0xFFFFFF00) + ((dword_9E70C[v14] + 255) & 0xFFFFFF00);
    if ( v4 >= 0x501 )
    {
      if ( v4 >= 0x781 )
      {
        v46 = 2;
        if ( v4 > 0x1000 )
          v46 = 3;
      }
      else
      {
        v46 = 1;
      }
    }
    else
    {
      v46 = 0;
    }
    v47 = (v6 + 7) & 0xFFFFFFF8;
    v48 = ((2 * v4 + 126) & 0xFFFFFF80) * ((v6 + 63) >> 6) + 255;
    v49 = v45 * v2;
    v50 = dword_9E78C[v46] + 255;
    if ( ((8 * v4 + 248) & 0xFFFFFF00) + 7936 <= 32 * v47 )
      v51 = 32 * v47;
    else
      v51 = ((8 * v4 + 248) & 0xFFFFFF00) + 7936;
    if ( v6 == v8 )
    {
      v52 = 0;
      v27 = v4 == v7;
      v53 = 0;
      if ( v27 )
        goto LABEL_102;
    }
    else
    {
      v54 = v7 << (v4 > 4 * v7);
      if ( v6 <= 4 * v8 )
      {
        v55 = 0;
        v56 = 0;
      }
      else
      {
        v55 = (8 * v7 + 248) & 0xFFFFFF00;
        v56 = (16 * v7 + 224) & 0xFFFFFF00;
      }
      v52 = ((8 * v54 + 248) & 0xFFFFFF00) + ((16 * v54 + 224) & 0xFFFFFF00) + v55 + v56;
    }
    v53 = ((16 * v7 + 224) & 0xFFFFFF00) + ((16 * v7 + 240) & 0xFFFFFF00) + v52;
LABEL_102:
    v57 = (v48 & 0xFFFFFF00) + (v47 << 6) + 2 * v51;
    v58 = (v44 & 0xFFFFFF00) + v49 + (v50 & 0xFFFFFF00);
LABEL_123:
    result = (v57 + v58 + v53 + 255) & 0xFFFFFF00;
    goto LABEL_143;
  }
  if ( v6 >= 0x501 )
  {
    if ( v6 >= 0x781 )
    {
      v16 = 2;
      if ( v6 > 0x1000 )
        v16 = 3;
    }
    else
    {
      v16 = 1;
    }
  }
  else
  {
    v16 = 0;
  }
  v73 = dword_9E6EC[v16];
  v74 = (((dword_9E6CC[v16] + 255) & 0xFFFFFF00) + ((dword_9E70C[v16] + 255) & 0xFFFFFF00)) * v2;
  if ( v4 >= 0x501 )
  {
    if ( v4 >= 0x781 )
    {
      v75 = 2;
      if ( v4 > 0x1000 )
        v75 = 3;
    }
    else
    {
      v75 = 1;
    }
  }
  else
  {
    v75 = 0;
  }
  result = ((v73 + 255) & 0xFFFFFF00)
         + v74
         + ((dword_9E78C[v75] + 255) & 0xFFFFFF00)
         + ((((2 * v4 + 126) & 0xFFFFFF80) * ((v6 + 63) >> 6) + 255) & 0xFFFFFF00);
LABEL_143:
  if ( a1 )
  {
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v78 = a1 + 340;
      v79 = result;
      printk(&unk_8FA63, "low ", v78, "msm_vidc_decoder_line_size_iris4", (unsigned int)result);
      return v79;
    }
  }
  return result;
}
