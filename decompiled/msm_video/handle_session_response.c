__int64 __fastcall handle_session_response(_QWORD *a1, __int64 a2)
{
  int v2; // w8
  unsigned int *v5; // x9
  __int64 v6; // x25
  unsigned int v7; // w21
  char v8; // w26
  unsigned int v9; // w8
  unsigned int *v10; // x27
  char *v11; // x23
  unsigned int i; // w28
  __int64 v13; // x4
  unsigned int v14; // w8
  _DWORD *v15; // x9
  __int64 v16; // x8
  char v17; // w9
  char v18; // w20
  __int64 *buffers; // x0
  __int64 v20; // x22
  __int64 *v21; // x23
  int v22; // w8
  unsigned __int64 v23; // x10
  _BYTE *v24; // x9
  bool v25; // w8
  bool v26; // cf
  unsigned int v27; // w1
  unsigned __int64 v28; // x10
  _BYTE *v29; // x9
  _QWORD *v30; // x0
  _QWORD *v31; // x8
  __int64 v32; // x27
  __int64 *v33; // x0
  __int64 v34; // x26
  __int64 *v35; // x21
  const char *v36; // x1
  const char *v37; // x2
  int v38; // w8
  __int64 v39; // x28
  unsigned int *v41; // [xsp+8h] [xbp-8h]

  v2 = *(_DWORD *)(a2 + 28);
  v41 = (unsigned int *)(a2 + 32);
  if ( v2 )
  {
    v5 = (unsigned int *)(a2 + 32);
    while ( v5[1] != 16777228 || v5[4] != 1 )
    {
      --v2;
      v5 = (unsigned int *)((char *)v5 + *v5);
      if ( !v2 )
        goto LABEL_7;
    }
    msm_vdec_init_input_subcr_params((__int64)a1);
  }
LABEL_7:
  a1[459] = 0;
  a1[458] = 0;
  v6 = 0;
  v7 = 0;
  a1[457] = 0;
  v8 = 0;
  a1[456] = 0;
  a1[455] = 0;
  a1[454] = 0;
  a1[453] = 0;
  a1[452] = 0;
  a1[451] = 0;
  a1[450] = 0;
  a1[449] = 0;
  a1[448] = 0;
  a1[447] = 0;
  a1[446] = 0;
  a1[445] = 0;
  a1[444] = 0;
  v9 = *(_DWORD *)(a2 + 28);
  do
  {
    if ( v9 )
    {
      v10 = v41;
      v11 = (char *)&_handle_session_response_be + 16 * v6;
      for ( i = 0; i < v9; ++i )
      {
        if ( (v10[2] & 4) == 0 )
          goto LABEL_28;
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_8BA7E, "err ", (char *)a1 + 340, "__handle_session_response", v10[1]);
        v13 = v10[1];
        if ( (int)v13 <= 67108866 )
        {
          if ( (_DWORD)v13 == 16777225 )
          {
            if ( a1 )
              goto LABEL_25;
            goto LABEL_27;
          }
          if ( (_DWORD)v13 != 67108865 )
          {
            if ( (_DWORD)v13 == 67108866 )
            {
              if ( a1 )
                goto LABEL_25;
              goto LABEL_27;
            }
LABEL_40:
            if ( a1 )
              goto LABEL_25;
            goto LABEL_27;
          }
          if ( a1 )
          {
LABEL_25:
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_972D1, "err ", (char *)a1 + 340, "handle_session_error", v13);
          }
        }
        else if ( (int)v13 > 67108868 )
        {
          if ( (_DWORD)v13 != 67108869 )
          {
            if ( (_DWORD)v13 == 67108870 )
            {
              if ( a1 )
                goto LABEL_25;
              goto LABEL_27;
            }
            goto LABEL_40;
          }
          if ( a1 )
            goto LABEL_25;
        }
        else if ( (_DWORD)v13 == 67108867 )
        {
          if ( a1 )
            goto LABEL_25;
        }
        else if ( a1 )
        {
          goto LABEL_25;
        }
LABEL_27:
        msm_vidc_change_state((__int64)a1, 5u, (__int64)"handle_session_error");
LABEL_28:
        v14 = v10[1];
        if ( *(_DWORD *)v11 < v14 && *((_DWORD *)v11 + 1) > v14 )
        {
          v15 = *((_DWORD **)v11 + 1);
          v8 |= v14 == 16777225;
          if ( *(v15 - 1) != 503439326 )
            __break(0x8229u);
          v7 = ((__int64 (__fastcall *)(_QWORD *, unsigned int *))v15)(a1, v10);
          if ( v7 )
            msm_vidc_change_state((__int64)a1, 5u, (__int64)"__handle_session_response");
        }
        v9 = *(_DWORD *)(a2 + 28);
        v10 = (unsigned int *)((char *)v10 + *v10);
      }
    }
    ++v6;
  }
  while ( v6 != 4 );
  if ( (v8 & 1) == 0 )
  {
LABEL_100:
    a1[458] = 0;
    a1[459] = 0;
    a1[456] = 0;
    a1[457] = 0;
    a1[454] = 0;
    a1[455] = 0;
    a1[452] = 0;
    a1[453] = 0;
    a1[450] = 0;
    a1[451] = 0;
    a1[448] = 0;
    a1[449] = 0;
    a1[446] = 0;
    a1[447] = 0;
    a1[444] = 0;
    a1[445] = 0;
    return v7;
  }
  v16 = 0;
  v17 = 1;
  while ( 2 )
  {
    v18 = v17;
    buffers = (__int64 *)msm_vidc_get_buffers(
                           (__int64)a1,
                           msm_vidc_check_meta_buffers_buffer_type[v16],
                           (__int64)"msm_vidc_check_meta_buffers");
    if ( !buffers )
      return (unsigned int)-22;
    v20 = *buffers;
    v21 = buffers;
LABEL_53:
    if ( (__int64 *)v20 == v21 )
    {
      v17 = 0;
      v16 = 1;
      if ( (v18 & 1) != 0 )
        continue;
      v32 = 0;
      while ( 1 )
      {
        v33 = (__int64 *)msm_vidc_get_buffers(
                           (__int64)a1,
                           handle_dequeue_buffers_buffer_type[v32],
                           (__int64)"handle_dequeue_buffers");
        if ( !v33 )
          return (unsigned int)-22;
        v34 = *v33;
        v35 = v33;
        if ( (__int64 *)*v33 != v33 )
          break;
LABEL_89:
        ++v32;
        v7 = 0;
        if ( v32 == 4 )
          goto LABEL_100;
      }
      while ( 1 )
      {
        v38 = *(_DWORD *)(v34 + 80);
        v39 = *(_QWORD *)v34;
        if ( (v38 & 0x10) != 0 )
        {
          *(_DWORD *)(v34 + 80) = v38 & 0xFFFFFFEF;
          if ( (v38 & 0x20) != 0 )
          {
            v36 = "high";
            v37 = "vb2 done already";
          }
          else
          {
            *(_DWORD *)(v34 + 80) = v38 & 0xFFFFFFCF | 0x20;
            if ( !(unsigned int)msm_vidc_vb2_buffer_done((__int64)a1, v34) )
              goto LABEL_95;
            v36 = "err ";
            v37 = "vb2 done failed";
          }
          print_vidc_buffer(2, (__int64)v36, (__int64)v37, (__int64)a1, v34);
        }
LABEL_95:
        v34 = v39;
        if ( (__int64 *)v39 == v35 )
          goto LABEL_89;
      }
    }
    break;
  }
  if ( (*(_BYTE *)(v20 + 80) & 0x10) == 0 )
    goto LABEL_52;
  v22 = *(_DWORD *)(v20 + 24);
  if ( v22 == 1 )
  {
    v28 = 1;
    v29 = a1 + 567;
    do
    {
      if ( (*v29 & 0x80) != 0
        && ((~*((_DWORD *)v29 - 4) & 9LL) == 0
         || (*((_QWORD *)v29 - 2) & 3LL) == 3
         || (*((_QWORD *)v29 - 2) & 0x22LL) == 0x22) )
      {
        break;
      }
      v26 = v28++ >= 0xC4;
      v29 += 168;
      LOBYTE(v22) = !v26;
    }
    while ( v28 != 197 );
    if ( (v22 & 1) != 0 )
    {
      v27 = 3;
      goto LABEL_79;
    }
LABEL_52:
    v20 = *(_QWORD *)v20;
    goto LABEL_53;
  }
  if ( v22 != 2 )
    goto LABEL_52;
  v23 = 1;
  v24 = a1 + 567;
  v25 = 1;
  do
  {
    if ( (*v24 & 0x80) != 0
      && ((~*((_DWORD *)v24 - 4) & 0x11LL) == 0
       || (*((_QWORD *)v24 - 2) & 5LL) == 5
       || (*((_QWORD *)v24 - 2) & 0x24LL) == 0x24) )
    {
      break;
    }
    v26 = v23++ >= 0xC4;
    v24 += 168;
    v25 = !v26;
  }
  while ( v23 != 197 );
  if ( !v25 )
    goto LABEL_52;
  v27 = 4;
LABEL_79:
  v30 = (_QWORD *)msm_vidc_get_buffers((__int64)a1, v27, (__int64)"is_metabuffer_dequeued");
  if ( v30 )
  {
    v31 = (_QWORD *)*v30;
    if ( (_QWORD *)*v30 != v30 )
    {
      while ( *((_DWORD *)v31 + 8) != *(_DWORD *)(v20 + 32) || (v31[10] & 0x30) == 0 )
      {
        v31 = (_QWORD *)*v31;
        if ( v31 == v30 )
          goto LABEL_88;
      }
      goto LABEL_52;
    }
  }
LABEL_88:
  print_vidc_buffer(1, (__int64)"err ", (__int64)"meta not dequeued", (__int64)a1, v20);
  return (unsigned int)-22;
}
