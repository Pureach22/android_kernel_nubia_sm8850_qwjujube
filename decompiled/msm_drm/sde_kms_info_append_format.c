// positive sp value has been detected, the output may be wrong!
__int64 __usercall sde_kms_info_append_format@<X0>(
        __int64 result@<X0>,
        unsigned int a2@<W1>,
        unsigned __int64 a3@<X2>,
        unsigned int a4@<W8>,
        __int64 a5,
        int a6,
        __int64 a7,
        int a8,
        __int64 a9)
{
  char *v9; // x21
  __int64 v10; // x22
  char v11; // w23
  unsigned int *v12; // x25
  __int64 v13; // x26
  __int64 v14; // x19
  __int64 v15; // x10
  const char *v16; // x9
  __int64 v17; // x6
  char *v18; // x0
  unsigned int v19; // w8
  __int64 v20; // x20
  int v21; // w24
  unsigned int v22; // w9
  bool v23; // cf
  __int64 v24; // x24
  _QWORD *v25; // x27
  int v26; // w0
  __int64 v27; // x23
  __int64 v28; // x25
  unsigned __int64 v29; // x27
  int v30; // w0
  __int64 v31; // x25

  if ( result )
  {
    v14 = result + 0x4000;
    v15 = *(unsigned int *)(result + 16388);
    if ( a3 )
    {
      if ( (unsigned int)v15 <= 0x4000 )
      {
        v16 = " %c%c%c%c/%llX/%llX";
        if ( *(_BYTE *)(result + 16392) )
          v16 = "%c%c%c%c/%llX/%llX";
        result = snprintf(
                   (char *)(result + v15),
                   0x4000 - v15,
                   v16,
                   (unsigned __int8)a2,
                   BYTE1(a2),
                   BYTE2(a2),
                   HIBYTE(a2),
                   HIBYTE(a3),
                   a3 & 0xFFFFFFFFFFFFFFLL);
        goto LABEL_11;
      }
    }
    else if ( (unsigned int)v15 <= 0x4000 )
    {
      v17 = HIBYTE(a2);
      v18 = (char *)(result + v15);
      if ( *(_BYTE *)(v14 + 8) )
        result = snprintf(v18, (unsigned int)(0x4000 - v15), "%c%c%c%c", (unsigned __int8)a2, BYTE1(a2), BYTE2(a2), v17);
      else
        result = snprintf(
                   v18,
                   (unsigned int)(0x4000 - v15),
                   " %c%c%c%c",
                   (unsigned __int8)a2,
                   BYTE1(a2),
                   BYTE2(a2),
                   v17);
LABEL_11:
      v19 = *(_DWORD *)(v14 + 4) + result;
      if ( !(v19 >> 14) )
      {
        *(_DWORD *)(v14 + 4) = v19;
        *(_BYTE *)(v14 + 8) = 0;
      }
      return result;
    }
    __break(0x5512u);
    if ( v10 )
      return sde_kms_info_append_dnsc_blur_filter_info();
    v20 = result;
    v21 = v15;
    *v12 = a4;
    if ( (v11 & 1) != 0 )
    {
      v22 = v12[1];
      v12[2] = v22;
      v23 = v22 >= a4;
      if ( v22 != a4 )
        goto LABEL_18;
    }
    else
    {
      v22 = v12[2];
      v23 = v22 >= a4;
      if ( v22 != a4 )
      {
LABEL_18:
        if ( !v23 )
        {
          a4 &= 0x1FFFu;
          *v12 = a4;
          if ( v22 < a4 )
          {
            v22 += 0x2000;
            v12[2] = v22;
          }
        }
        if ( v22 - a4 > (unsigned int)v15 )
        {
          printk(&unk_21E263, "_sde_evtlog_dump_calc_range");
          a4 = v12[2] - v21;
          *v12 = a4;
        }
        v24 = v14 + 96LL * (a4 & 0x1FFF);
        v25 = (_QWORD *)(v14 + 96LL * (((_WORD)a4 - 1) & 0x1FFF));
        v12[4] = a4 + 1;
        v26 = snprintf(v9, 0, "%s:%-4d", *(const char **)(v24 + 8), *(_DWORD *)(v24 + 16));
        v27 = v26;
        if ( v26 < 32 )
        {
          memset(&v9[v26], 32, 32LL - v26);
          v27 = 32;
        }
        v28 = v27
            + snprintf(
                &v9[v27],
                -v27,
                "=>[%-8d:%-11llu:%9llu][%-4d]:[%-4d]:",
                *v12,
                *(_QWORD *)v24,
                *(_QWORD *)v24 - *v25,
                *(_DWORD *)(v24 + 84),
                *(unsigned __int8 *)(v24 + 88));
        if ( *(_DWORD *)(v24 + 80) )
        {
          v29 = 0;
          do
          {
            if ( v29 == 15 )
            {
              __break(0x5512u);
              JUMPOUT(0x144E6C);
            }
            v30 = snprintf(&v9[v28], -v28, "%x ", *(_DWORD *)(v24 + 20 + 4 * v29++));
            v28 += v30;
          }
          while ( v29 < *(unsigned int *)(v24 + 80) );
        }
        v31 = v28 + snprintf(&v9[v28], -v28, "\n");
        goto LABEL_32;
      }
    }
    v31 = 0;
LABEL_32:
    raw_spin_unlock_irqrestore(v14 + v13, v20);
    return v31;
  }
  return result;
}
