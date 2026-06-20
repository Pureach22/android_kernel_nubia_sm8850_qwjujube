__int64 __fastcall msm_vidc_scale_power(__int64 a1, char a2)
{
  __int64 v2; // x20
  __int64 v5; // x0
  unsigned __int64 v6; // x24
  unsigned int *v7; // x27
  __int64 *v8; // x8
  __int64 v9; // x10
  unsigned int v10; // w9
  unsigned int v11; // w11
  unsigned int v12; // w11
  unsigned int frame_rate; // w22
  unsigned int operating_rate; // w0
  int v15; // w8
  unsigned int v16; // w26
  unsigned int timestamp_rate; // w25
  unsigned int input_rate; // w0
  unsigned int v19; // w8
  __int64 *i; // x8
  unsigned __int64 v21; // x12
  unsigned __int64 v22; // x13
  bool v23; // cf
  unsigned __int64 v24; // x12
  __int64 v25; // x8
  unsigned int (__fastcall **v26)(_QWORD); // x8
  unsigned int (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x1
  int v29; // w0
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  int v34; // w0
  __int64 v35; // x3
  __int64 v36; // x4

  v2 = *(_QWORD *)(a1 + 320);
  v5 = ktime_get(a1);
  if ( (*(_BYTE *)(v2 + 4768) & 1) != 0 )
    return 0;
  v6 = v5;
  v7 = (unsigned int *)(a1 + 38400);
  if ( (*(_BYTE *)(a1 + 38408) & 1) == 0 )
  {
    a2 = 1;
    *(_BYTE *)(a1 + 38408) = 1;
  }
  v8 = *(__int64 **)(a1 + 2504);
  v9 = a1 + 2504;
  if ( *(_BYTE *)(a1 + 3680) == 1 )
  {
    if ( v8 != (__int64 *)v9 )
    {
      v10 = 0;
      v11 = 0;
      do
      {
        if ( (v8[10] & 9) != 0 )
        {
          ++v11;
          v10 += *((_DWORD *)v8 + 12);
        }
        v8 = (__int64 *)*v8;
      }
      while ( v8 != (__int64 *)v9 );
      if ( v11 )
        v10 /= v11;
      goto LABEL_19;
    }
LABEL_16:
    v10 = 0;
    goto LABEL_19;
  }
  if ( v8 == (__int64 *)v9 )
    goto LABEL_16;
  v10 = 0;
  do
  {
    v12 = *((_DWORD *)v8 + 12);
    v8 = (__int64 *)*v8;
    if ( v10 <= v12 )
      v10 = v12;
  }
  while ( v8 != (__int64 *)v9 );
LABEL_19:
  *(_DWORD *)(a1 + 38432) = v10;
  frame_rate = msm_vidc_get_frame_rate(a1);
  operating_rate = msm_vidc_get_operating_rate(a1);
  v15 = *(_DWORD *)(a1 + 308);
  if ( frame_rate <= operating_rate )
    v16 = operating_rate;
  else
    v16 = frame_rate;
  if ( v15 == 2 || v15 == 1 && *(_QWORD *)(a1 + 33416) )
  {
    timestamp_rate = msm_vidc_get_timestamp_rate(a1);
    input_rate = msm_vidc_get_input_rate(a1);
    if ( timestamp_rate > v16 + (v16 >> 3) )
      v16 = timestamp_rate;
    if ( input_rate > v16 )
    {
      if ( *(_QWORD *)(a1 + 33416) )
        v16 = input_rate + (input_rate >> 4);
      else
        v16 = input_rate;
    }
  }
  v19 = *(_DWORD *)(a1 + 38432);
  *(_DWORD *)(a1 + 38700) = v16;
  *(_QWORD *)(a1 + 38416) = v6;
  if ( v19 )
  {
    if ( *(_DWORD *)(a1 + 308) == 2 && *(_QWORD *)(a1 + 13256) )
    {
      if ( v19 <= *v7 )
        v19 = *v7;
      *(_DWORD *)(a1 + 38432) = v19;
    }
    core_lock(v2);
    for ( i = *(__int64 **)(v2 + 3528); i != (__int64 *)(v2 + 3528); i = (__int64 *)*i )
    {
      if ( i != (__int64 *)a1 )
      {
        if ( v6 )
        {
          v21 = i[4802];
          if ( v21 )
          {
            v22 = v6 - v21;
            v23 = v21 >= v6;
            v24 = v21 - v6;
            if ( !v23 )
              v24 = v22;
            if ( v24 >= 0x3BAA0C40 )
              *((_BYTE *)i + 38408) = 0;
          }
        }
      }
    }
    core_unlock(v2);
    v25 = *(_QWORD *)(a1 + 320);
    if ( v25 && (v26 = *(unsigned int (__fastcall ***)(_QWORD))(v25 + 6560)) != nullptr && (v27 = *v26) != nullptr )
    {
      if ( *((_DWORD *)v27 - 1) != 1661903850 )
        __break(0x8228u);
      v28 = v27(a1);
    }
    else
    {
      v28 = 0;
    }
    v29 = venus_hfi_scale_clocks(a1, v28);
    if ( a1 && v29 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_89422, "err ", a1 + 340, v32, v33);
      if ( (a2 & 1) == 0 )
        goto LABEL_63;
    }
    else if ( (a2 & 1) == 0 )
    {
      goto LABEL_63;
    }
    v34 = msm_vidc_scale_buses(a1, v30, v31, v32, v33);
    if ( a1 && v34 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8C246, "err ", a1 + 340, v35, v36);
LABEL_64:
      if ( (msm_vidc_debug & 0xA) != 0 )
        printk(&unk_931EA, "high", a1 + 340, *(_QWORD *)(a1 + 1944), *(_QWORD *)(a1 + 1952));
      return 0;
    }
LABEL_63:
    if ( !a1 )
      return 0;
    goto LABEL_64;
  }
  return 0;
}
