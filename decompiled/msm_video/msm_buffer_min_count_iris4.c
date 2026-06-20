__int64 __fastcall msm_buffer_min_count_iris4(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x4
  int v6; // w9
  int v7; // w10
  int v8; // w9
  int v9; // w9
  unsigned int v10; // w8
  int v11; // w12
  int v12; // w13
  int v13; // w11
  unsigned int v14; // w12
  int v15; // w11
  int v16; // w10
  unsigned int v17; // w13
  unsigned int v18; // w14
  bool v19; // cf
  unsigned int v20; // w21
  __int64 v21; // x0
  int v22; // w9
  unsigned int v23; // w13
  unsigned int v24; // w12
  unsigned int v25; // w11
  char v26; // w9
  unsigned int v27; // w12
  unsigned int v28; // w8
  int v29; // w10
  int v30; // w11
  unsigned int v31; // w12
  bool v32; // zf
  int v33; // w9

  result = 0;
  if ( (int)a2 > 3 )
  {
    if ( a2 > 0xF )
      goto LABEL_5;
    if ( ((1 << a2) & 0xEF80) != 0 )
    {
      result = msm_vidc_internal_buffer_count(a1, a2);
      goto LABEL_5;
    }
    if ( a2 != 4 )
    {
      if ( a2 != 12 )
        goto LABEL_5;
      v8 = *(_DWORD *)(a1 + 308);
      if ( v8 != 2 )
      {
        if ( v8 == 1 )
        {
          result = msm_vidc_get_recon_buf_count(a1);
          goto LABEL_5;
        }
        goto LABEL_50;
      }
      v22 = *(_DWORD *)(a1 + 312);
      if ( v22 == 64
        || ((v29 = *(_DWORD *)(a1 + 18128), (unsigned int)(v29 - 2) > 0x3E)
         || ((1LL << ((unsigned __int8)v29 - 2)) & 0x4000000000004005LL) == 0)
        && v29 != 256
        && !*(_QWORD *)(a1 + 20312)
        && (v22 != 16 || !*(_QWORD *)(a1 + 34088)) )
      {
LABEL_50:
        result = 0;
        goto LABEL_5;
      }
      result = *(unsigned int *)(a1 + 38716);
      if ( !(_DWORD)result )
        result = *(unsigned int *)(a1 + 2560);
LABEL_5:
      if ( !a1 )
        return result;
      goto LABEL_6;
    }
LABEL_24:
    result = msm_vidc_output_min_count(a1);
    if ( *(_DWORD *)(a1 + 16952) == 1 && *(_DWORD *)(a1 + 12920) )
    {
      v9 = *(_DWORD *)(a1 + 312);
      v10 = *(_DWORD *)(a1 + 30896);
      if ( v9 == 2 )
        v11 = 31;
      else
        v11 = 15;
      if ( v9 == 2 )
        v12 = -32;
      else
        v12 = -16;
      v13 = v11 + *(_DWORD *)(a1 + 604);
      v14 = (v11 + *(_DWORD *)(a1 + 600)) & v12;
      v15 = v13 & v12;
      v16 = 1;
      if ( v9 == 2 )
      {
        v17 = (v14 + 959) / 0x3C0;
        v18 = v14 - 960 * (v17 - 1);
        if ( v18 < 0x160 )
        {
          --v17;
          v18 = 1312;
        }
        v19 = v14 >= 0x521;
        if ( v14 < 0x521 )
        {
          v16 = 1;
        }
        else
        {
          v14 = 960;
          v16 = v17;
        }
        if ( v19 )
          v23 = v18;
        else
          v23 = 0;
      }
      else
      {
        v23 = 0;
      }
      v24 = v14 * v15;
      v25 = v23 * v15;
      if ( v9 == 2 )
        v26 = 10;
      else
        v26 = 8;
      v27 = ((v24 >> v26) + v10 - 1) / v10;
      v28 = ((v25 >> v26) + v10 - 1) / v10 + v27 * (v16 - 1);
      if ( !v23 )
        v28 = v27 * v16;
      result = v28 * (unsigned int)result;
    }
    goto LABEL_5;
  }
  if ( a2 != 1 )
  {
    if ( a2 == 2 )
      goto LABEL_24;
    if ( a2 != 3 )
      goto LABEL_5;
  }
  v5 = *(unsigned int *)(a1 + 308);
  if ( (_DWORD)v5 == 2 )
  {
    result = 4;
    if ( !*(_QWORD *)(a1 + 32576) )
      goto LABEL_43;
    goto LABEL_44;
  }
  if ( (_DWORD)v5 == 1 )
  {
    v6 = *(_DWORD *)(a1 + 312);
    if ( (unsigned int)(v6 - 1) > 1 || *(_QWORD *)(a1 + 27704) )
      goto LABEL_16;
    v30 = *(_DWORD *)(a1 + 15272);
    v31 = v30 + 1;
    if ( v6 == 1 )
    {
      v7 = 3;
      if ( !*(_QWORD *)(a1 + 27872) || v31 <= 1 )
        goto LABEL_17;
    }
    else if ( v31 < 2 )
    {
LABEL_16:
      v7 = 3;
      goto LABEL_17;
    }
    v32 = *(_DWORD *)(a1 + 15104) == 4 && v6 == 2;
    v33 = (1 << v30) + 2;
    if ( v32 )
      v33 = (2 << v30) + 1;
    if ( *(__int64 *)(a1 + 36104) <= 0 )
      v7 = v33;
    else
      v7 = v33 + 1;
LABEL_17:
    result = (unsigned int)(v7 + *(_DWORD *)(a1 + 36104));
    if ( !*(_QWORD *)(a1 + 32576) )
    {
LABEL_43:
      if ( *(_DWORD *)(a1 + 312) != 8 )
        goto LABEL_5;
    }
LABEL_44:
    result = 1;
    goto LABEL_5;
  }
  if ( !a1 )
    return 0;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_87097, "err ", a1 + 340, "msm_vidc_input_min_count_iris4", v5);
  result = 0;
LABEL_6:
  if ( (msm_vidc_debug & 4) != 0 )
  {
    v20 = result;
    v21 = buf_name(a2);
    printk(&unk_81D4A, "low ", a1 + 340, v21, v20);
    return v20;
  }
  return result;
}
