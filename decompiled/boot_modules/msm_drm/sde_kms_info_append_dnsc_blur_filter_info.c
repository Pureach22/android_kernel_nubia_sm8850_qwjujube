__int64 __fastcall sde_kms_info_append_dnsc_blur_filter_info(__int64 result, unsigned __int8 *a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v4; // x20
  __int64 v5; // x8
  const char *v7; // x2
  int v8; // w9
  int v9; // w21
  unsigned int v10; // w8
  char *v11; // x0
  __int64 v12; // x3
  unsigned int v13; // w8
  unsigned int v14; // w9
  char *v15; // x0
  __int64 v16; // x3
  unsigned int v17; // w8
  unsigned int v18; // w9
  char *v19; // x0
  __int64 v20; // x3
  unsigned int v21; // w8
  unsigned int v22; // w9
  char *v23; // x0
  __int64 v24; // x3
  unsigned int v25; // w8
  unsigned int v26; // w9
  char *v27; // x0
  __int64 v28; // x3
  unsigned int v29; // w8
  unsigned int v30; // w9
  char *v31; // x0
  __int64 v32; // x3
  unsigned int v33; // w8
  unsigned int v34; // w9
  char *v35; // x0
  __int64 v36; // x3
  unsigned int v37; // w8
  int v38; // [xsp+0h] [xbp-20h]
  int v39; // [xsp+8h] [xbp-18h]
  int v40; // [xsp+10h] [xbp-10h]
  int v41; // [xsp+18h] [xbp-8h]

  if ( result )
  {
    v3 = result + 0x4000;
    v4 = result;
    v5 = *(unsigned int *)(result + 16388);
    if ( (unsigned int)v5 <= 0x4000 )
    {
      if ( *(_BYTE *)(result + 16392) )
        v7 = "%c/%c/%c/%c/%c/%c/%c/%c/%c/";
      else
        v7 = " %c/%c/%c/%c/%c/%c/%c/%c/%c/";
      v40 = a2[28];
      v41 = a2[32];
      v39 = a2[24];
      v38 = a2[20];
      result = snprintf(
                 (char *)(result + v5),
                 (unsigned int)(0x4000 - v5),
                 v7,
                 *a2,
                 a2[4],
                 a2[8],
                 a2[12],
                 a2[16],
                 v38,
                 v39,
                 v40,
                 v41);
      v8 = *((_DWORD *)a2 + 8);
      v9 = result;
      if ( !v8 )
        goto LABEL_43;
      v10 = *(_DWORD *)(v3 + 4) + result;
      if ( v10 <= 0x4000 )
      {
        v11 = (char *)(v4 + v10);
        v12 = *((unsigned int *)a2 + 9);
        if ( v8 == 1 )
          result = snprintf(v11, 0x4000 - v10, "%c", v12);
        else
          result = snprintf(v11, 0x4000 - v10, "%c,", v12);
        v13 = *((_DWORD *)a2 + 8);
        v9 += result;
        if ( v13 < 2 )
          goto LABEL_43;
        v14 = *(_DWORD *)(v3 + 4) + v9;
        if ( v14 <= 0x4000 )
        {
          v15 = (char *)(v4 + v14);
          v16 = *((unsigned int *)a2 + 10);
          if ( v13 == 2 )
            result = snprintf(v15, 0x4000 - v14, "%c", v16);
          else
            result = snprintf(v15, 0x4000 - v14, "%c,", v16);
          v17 = *((_DWORD *)a2 + 8);
          v9 += result;
          if ( v17 < 3 )
            goto LABEL_43;
          v18 = *(_DWORD *)(v3 + 4) + v9;
          if ( v18 <= 0x4000 )
          {
            v19 = (char *)(v4 + v18);
            v20 = *((unsigned int *)a2 + 11);
            if ( v17 == 3 )
              result = snprintf(v19, 0x4000 - v18, "%c", v20);
            else
              result = snprintf(v19, 0x4000 - v18, "%c,", v20);
            v21 = *((_DWORD *)a2 + 8);
            v9 += result;
            if ( v21 < 4 )
              goto LABEL_43;
            v22 = *(_DWORD *)(v3 + 4) + v9;
            if ( v22 <= 0x4000 )
            {
              v23 = (char *)(v4 + v22);
              v24 = *((unsigned int *)a2 + 12);
              if ( v21 == 4 )
                result = snprintf(v23, 0x4000 - v22, "%c", v24);
              else
                result = snprintf(v23, 0x4000 - v22, "%c,", v24);
              v25 = *((_DWORD *)a2 + 8);
              v9 += result;
              if ( v25 < 5 )
                goto LABEL_43;
              v26 = *(_DWORD *)(v3 + 4) + v9;
              if ( v26 <= 0x4000 )
              {
                v27 = (char *)(v4 + v26);
                v28 = *((unsigned int *)a2 + 13);
                if ( v25 == 5 )
                  result = snprintf(v27, 0x4000 - v26, "%c", v28);
                else
                  result = snprintf(v27, 0x4000 - v26, "%c,", v28);
                v29 = *((_DWORD *)a2 + 8);
                v9 += result;
                if ( v29 < 6 )
                  goto LABEL_43;
                v30 = *(_DWORD *)(v3 + 4) + v9;
                if ( v30 <= 0x4000 )
                {
                  v31 = (char *)(v4 + v30);
                  v32 = *((unsigned int *)a2 + 14);
                  if ( v29 == 6 )
                    result = snprintf(v31, 0x4000 - v30, "%c", v32);
                  else
                    result = snprintf(v31, 0x4000 - v30, "%c,", v32);
                  v33 = *((_DWORD *)a2 + 8);
                  v9 += result;
                  if ( v33 < 7 )
                    goto LABEL_43;
                  v34 = *(_DWORD *)(v3 + 4) + v9;
                  if ( v34 <= 0x4000 )
                  {
                    v35 = (char *)(v4 + v34);
                    v36 = *((unsigned int *)a2 + 15);
                    result = v33 == 7 ? snprintf(v35, 0x4000 - v34, "%c", v36) : snprintf(v35, 0x4000 - v34, "%c,", v36);
                    if ( *((_DWORD *)a2 + 8) <= 7u )
                    {
                      v9 += result;
LABEL_43:
                      v37 = *(_DWORD *)(v3 + 4) + v9;
                      if ( !(v37 >> 14) )
                      {
                        *(_DWORD *)(v3 + 4) = v37;
                        *(_BYTE *)(v3 + 8) = 0;
                      }
                      return result;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    __break(0x5512u);
    return sde_kms_rect_intersect(result, a2, a3);
  }
  return result;
}
