__int64 __fastcall msm_vidc_flush_buffers(__int64 a1, unsigned int a2)
{
  __int64 v2; // x25
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x27
  _QWORD **v8; // x26
  _QWORD *v9; // x1
  int v10; // w21
  _QWORD *v11; // x22
  __int64 v12; // x8
  void (__fastcall *v13)(_QWORD); // x8
  bool v14; // w27
  _QWORD *v15; // x1
  int v16; // w21
  _QWORD *v17; // x22
  __int64 v18; // x8
  void (__fastcall *v19)(_QWORD); // x8
  char v20; // w8
  __int64 v21; // x8
  __int64 *v22; // x24
  __int64 v23; // x21
  __int64 *v24; // x27
  char v25; // w8
  __int64 v26; // x9
  void (__fastcall *v27)(__int64, __int64); // x9
  __int64 v28; // x1
  __int64 v29; // x8
  __int64 *v30; // x23
  __int64 v31; // x21
  __int64 *v33; // x26
  char v34; // w8
  __int64 v35; // x9
  void (__fastcall *v36)(__int64, __int64); // x9
  __int64 v37; // x1
  const char *v38; // x4
  const char *v39; // x4

  v2 = *(_QWORD *)(a1 + 320);
  if ( a2 == 1 )
  {
    v5 = 38000;
    v6 = 37824;
  }
  else
  {
    if ( a2 != 2 )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_88043, "high", a1 + 340, "msm_vidc_flush_buffers", a2);
      return 4294967274LL;
    }
    v5 = 38352;
    v6 = 38176;
  }
  v7 = a1 + v6;
  v8 = (_QWORD **)(a1 + v5);
  v9 = *(_QWORD **)(a1 + v6);
  if ( v9 == (_QWORD *)(a1 + v6) )
  {
    v14 = a1 != 0;
    goto LABEL_24;
  }
  v10 = 0;
  do
  {
    v11 = (_QWORD *)*v9;
    if ( a1 && v9 && (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_915A6, "high", a1 + 340, "release", v9 + 2);
      if ( !v2 )
        goto LABEL_7;
    }
    else if ( !v2 )
    {
      goto LABEL_7;
    }
    v12 = *(_QWORD *)(v2 + 6584);
    if ( v12 )
    {
      v13 = *(void (__fastcall **)(_QWORD))(v12 + 56);
      if ( v13 )
      {
        if ( *((_DWORD *)v13 - 1) != -1185588215 )
          __break(0x8228u);
        v13(a1);
      }
    }
LABEL_7:
    ++v10;
    v9 = v11;
  }
  while ( v11 != (_QWORD *)v7 );
  v14 = a1 != 0;
  if ( a1 && v10 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      if ( a2 == 1 )
        v39 = "input";
      else
        v39 = "output";
      printk(&unk_8B65F, "high", a1 + 340, "msm_vidc_flush_buffers", v39);
    }
    v14 = 1;
  }
LABEL_24:
  v15 = *v8;
  if ( *v8 == v8 )
    goto LABEL_42;
  v16 = 0;
  while ( 2 )
  {
    v17 = (_QWORD *)*v15;
    if ( a1 && v15 && (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_915A6, "high", a1 + 340, "destroy", v15 + 2);
      if ( v2 )
      {
LABEL_31:
        v18 = *(_QWORD *)(v2 + 6584);
        if ( v18 )
        {
          v19 = *(void (__fastcall **)(_QWORD))(v18 + 48);
          if ( v19 )
          {
            if ( *((_DWORD *)v19 - 1) != -1185588215 )
              __break(0x8228u);
            v19(a1);
          }
        }
      }
    }
    else if ( v2 )
    {
      goto LABEL_31;
    }
    ++v16;
    v15 = v17;
    if ( v17 != v8 )
      continue;
    break;
  }
  v20 = !v14;
  if ( !v16 )
    v20 = 1;
  if ( (v20 & 1) == 0 && (msm_vidc_debug & 2) != 0 )
  {
    if ( a2 == 1 )
      v38 = "input";
    else
      v38 = "output";
    printk(&unk_822DE, "high", a1 + 340, "msm_vidc_flush_buffers", v38);
  }
LABEL_42:
  v21 = 2664;
  if ( a2 == 1 )
    v21 = 2624;
  v22 = (__int64 *)(a1 + v21);
  if ( !(a1 + v21) )
    return 4294967274LL;
  v23 = *v22;
  if ( (__int64 *)*v22 != v22 )
  {
    do
    {
      v24 = *(__int64 **)v23;
      if ( (*(_BYTE *)(v23 + 80) & 9) != 0 )
      {
        print_vidc_buffer(2, (__int64)"high", (__int64)"flushing buffer", a1, v23);
        if ( (*(_BYTE *)(v23 + 80) & 0x20) == 0 )
        {
          if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)(v23 + 24) == 2 )
          {
            v25 = *(_BYTE *)(v23 + 112);
            if ( (v25 & 1) != 0 )
            {
              if ( v2 )
              {
                v26 = *(_QWORD *)(v2 + 6568);
                if ( v26 )
                {
                  v27 = *(void (__fastcall **)(__int64, __int64))(v26 + 8);
                  if ( v27 )
                  {
                    v28 = *(_QWORD *)(v23 + 88);
                    if ( *((_DWORD *)v27 - 1) != 381883841 )
                      __break(0x8229u);
                    v27(a1, v28);
                    v25 = *(_BYTE *)(v23 + 112);
                  }
                }
              }
              *(_BYTE *)(v23 + 112) = v25 & 0xFE;
            }
          }
          *(_DWORD *)(v23 + 48) = 0;
          msm_vidc_vb2_buffer_done(a1, v23);
        }
      }
      v23 = (__int64)v24;
    }
    while ( v24 != v22 );
  }
  v29 = 2544;
  if ( a2 == 1 )
    v29 = 2504;
  v30 = (__int64 *)(a1 + v29);
  if ( !(a1 + v29) )
    return 4294967274LL;
  v31 = *v30;
  if ( (__int64 *)*v30 != v30 )
  {
    do
    {
      v33 = *(__int64 **)v31;
      if ( (*(_BYTE *)(v31 + 80) & 9) != 0 )
      {
        print_vidc_buffer(2, (__int64)"high", (__int64)"flushing buffer", a1, v31);
        if ( (*(_BYTE *)(v31 + 80) & 0x20) == 0 )
        {
          if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)(v31 + 24) == 2 )
          {
            v34 = *(_BYTE *)(v31 + 112);
            if ( (v34 & 1) != 0 )
            {
              if ( v2 )
              {
                v35 = *(_QWORD *)(v2 + 6568);
                if ( v35 )
                {
                  v36 = *(void (__fastcall **)(__int64, __int64))(v35 + 8);
                  if ( v36 )
                  {
                    v37 = *(_QWORD *)(v31 + 88);
                    if ( *((_DWORD *)v36 - 1) != 381883841 )
                      __break(0x8229u);
                    v36(a1, v37);
                    v34 = *(_BYTE *)(v31 + 112);
                  }
                }
              }
              *(_BYTE *)(v31 + 112) = v34 & 0xFE;
            }
          }
          *(_DWORD *)(v31 + 48) = 0;
          msm_vidc_vb2_buffer_done(a1, v31);
        }
      }
      v31 = (__int64)v33;
    }
    while ( v33 != v30 );
  }
  return 0;
}
