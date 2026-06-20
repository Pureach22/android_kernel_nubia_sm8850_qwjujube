char *__fastcall target_if_spectral_create_samp_msg(
        char *result,
        char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  char *v11; // x25
  char *v13; // x19
  int v14; // w8
  bool v15; // zf
  __int64 v16; // x8
  _DWORD *v17; // x8
  __int64 v18; // x0
  unsigned __int16 *v19; // x23
  _WORD *v20; // x26
  char *v21; // x22
  unsigned int v22; // w27
  __int64 v23; // x24
  int v24; // w8
  char *v25; // x8
  unsigned int v26; // t1
  char v27; // w11
  char v28; // w10
  const char *v29; // x2
  const char *v30; // x3
  char *v31; // x8
  unsigned int v32; // t1
  char v33; // w11
  char v34; // w10
  __int64 (__fastcall *v35)(char *, char *); // x8
  int v36; // w9
  _DWORD *v37; // x8
  __int64 v38; // x0
  unsigned int v39; // w9
  unsigned int v40; // w10
  size_t v41; // x2
  __int64 v42; // x8
  int v43; // w11
  unsigned __int16 *v44; // x1
  char *v45; // x10
  unsigned int v46; // t1
  char v47; // w13
  char v48; // w12
  unsigned __int16 *v49; // x9
  char *v50; // x10
  unsigned int v51; // t1
  char v52; // w13
  char v53; // w12
  char *v54; // x8
  unsigned int v55; // t1
  char v56; // w11
  char v57; // w10
  __int64 v58; // x8
  int v59; // w9
  _DWORD *v60; // x8
  __int64 v61; // x0
  int v62; // w10
  __int64 v63; // x1

  v10 = *((unsigned int *)a2 + 47);
  if ( (unsigned int)v10 >= 2 )
  {
    v29 = "%s: Invalid spectral mode";
    v30 = "target_if_get_spectral_msg_type";
    return (char *)qdf_trace_msg(0x56u, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, v30);
  }
  v11 = result + 1184;
  v13 = result;
  if ( (unsigned int)(*(_DWORD *)&result[4 * v10 + 1184] - 3) > 1
    || (v14 = *((_DWORD *)result + 313), v14 == 1)
    || (v15 = v14 == 2, v16 = *((unsigned int *)a2 + 47), v15)
    && (result[v10 + 1398] != 1 || (v16 = *((unsigned int *)a2 + 47), *(_DWORD *)&result[4 * v10 + 1376] == 1)) )
  {
    v17 = *((_DWORD **)result + 158);
    v18 = *(_QWORD *)result;
    if ( *(v17 - 1) != 650551869 )
      __break(0x8228u);
    result = (char *)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v17)(v18, (unsigned int)v10, 0);
    if ( !result )
      return result;
    v19 = *((unsigned __int16 **)a2 + 8);
    v20 = result + 1693;
    v21 = result;
    *(_DWORD *)result = -559038737;
    *((_WORD *)result + 2) = *((_WORD *)a2 + 44);
    *((_WORD *)result + 5) = *((_WORD *)a2 + 47);
    *((_WORD *)result + 6) = *((_WORD *)a2 + 48);
    *((_WORD *)result + 7) = *((_WORD *)a2 + 49);
    *((_WORD *)result + 3) = *((_WORD *)a2 + 45);
    *((_WORD *)result + 4) = *((_WORD *)a2 + 46);
    *(_DWORD *)(result + 1705) = *((_DWORD *)a2 + 47);
    *((_WORD *)result + 14) = *((_WORD *)a2 + 6);
    *((_WORD *)result + 16) = *a2;
    *(_DWORD *)(result + 1697) = *((_DWORD *)v13 + 296);
    *(_DWORD *)(result + 1735) = *((_DWORD *)v13 + 297);
    result[1701] = a2[184];
    result[1703] = a2[186];
    result[1709] = a2[192];
    *(_DWORD *)(result + 1711) = *((_DWORD *)a2 + 49);
    *(_DWORD *)(result + 1715) = *((_DWORD *)a2 + 50);
    *(_DWORD *)(result + 1719) = *((_DWORD *)a2 + 51);
    *(_DWORD *)(result + 1727) = *((_DWORD *)a2 + 53);
    *(_DWORD *)(result + 1731) = *((_DWORD *)a2 + 54);
    result[36] = *a2;
    result[37] = a2[3];
    result[38] = a2[2];
    qdf_mem_copy(result + 39, a2 + 4, 3u);
    qdf_mem_copy(v21 + 42, a2 + 7, 3u);
    *((_WORD *)v21 + 23) = *((_WORD *)a2 + 5);
    *((_DWORD *)v21 + 12) = *((_DWORD *)a2 + 4);
    *((_WORD *)v21 + 26) = *((_WORD *)a2 + 14);
    *(_WORD *)(v21 + 67) = *((_WORD *)a2 + 27);
    *(_WORD *)(v21 + 65) = *((_WORD *)a2 + 28);
    v21[70] = a2[52];
    v21[69] = a2[53];
    *(_DWORD *)(v21 + 61) = *((_DWORD *)a2 + 5);
    *((_WORD *)v21 + 28) = *((_WORD *)a2 + 12);
    v22 = *((_DWORD *)a2 + 10);
    if ( v22 >= 0x400 )
      v23 = 1024;
    else
      v23 = v22;
    *(_WORD *)(v21 + 91) = v23;
    v21[93] = *((_DWORD *)v13 + 137);
    v21[94] = *((_DWORD *)v13 + 138);
    v21[36] = *a2;
    v21[45] = a2[32];
    *v20 = *((_WORD *)a2 + 50);
    qdf_mem_copy(v21 + 71, a2 + 156, 0x14u);
    v24 = *((_DWORD *)v13 + 337);
    if ( v24 == 2 )
    {
      if ( v22 )
      {
        v31 = v21 + 97;
        do
        {
          v32 = *v19;
          v19 += 2;
          v33 = v32;
          if ( v32 >= 0x100 )
            v34 = -1;
          else
            v34 = v33;
          --v23;
          *v31++ = v34;
        }
        while ( v23 );
      }
    }
    else if ( v24 == 1 )
    {
      if ( v22 )
      {
        v25 = v21 + 97;
        do
        {
          v26 = *v19++;
          v27 = v26;
          if ( v26 >= 0x100 )
            v28 = -1;
          else
            v28 = v27;
          --v23;
          *v25++ = v28;
        }
        while ( v23 );
      }
    }
    else
    {
      qdf_mem_copy(v21 + 97, v19, (unsigned int)v23);
    }
    v35 = *((__int64 (__fastcall **)(char *, char *))v13 + 15);
    if ( *((_DWORD *)v35 - 1) != 803707193 )
      __break(0x8228u);
    result = (char *)v35(v13, v21 + 22);
    v16 = *((unsigned int *)a2 + 47);
    if ( (unsigned int)v16 >= 2 )
      goto LABEL_90;
  }
  if ( (unsigned int)(*(_DWORD *)&v11[4 * v16] - 3) <= 1 )
  {
    v36 = *((_DWORD *)v13 + 313);
    if ( v36 == 1 || v36 == 2 && (v13[v16 + 1398] != 1 || *(_DWORD *)&v13[4 * v16 + 1376] == 3) )
    {
      v37 = *((_DWORD **)v13 + 158);
      v38 = *(_QWORD *)v13;
      if ( *(v37 - 1) != 650551869 )
        __break(0x8228u);
      result = (char *)((__int64 (__fastcall *)(__int64, _QWORD, __int64))v37)(v38, (unsigned int)v10, 1);
      if ( result )
      {
        *((_WORD *)result + 17) = a2[1];
        *(_WORD *)(result + 1695) = *((_WORD *)a2 + 51);
        result[1702] = a2[185];
        result[1704] = a2[187];
        result[1710] = a2[193];
        *((_WORD *)result + 15) = *((_WORD *)a2 + 7);
        *((_WORD *)result + 27) = *((_WORD *)a2 + 15);
        *((_WORD *)result + 29) = *((_WORD *)a2 + 13);
        *(_DWORD *)(result + 1723) = *((_DWORD *)a2 + 52);
        v39 = *((_DWORD *)a2 + 11);
        v40 = *((_DWORD *)a2 + 12);
        if ( v40 >= 0x208 )
          v41 = 520;
        else
          v41 = v40;
        if ( v39 >= 0x20 )
          v42 = 32;
        else
          v42 = v39;
        *(_WORD *)(result + 95) = v41;
        *(_WORD *)(result + 1739) = v42;
        v43 = *((_DWORD *)v13 + 337);
        v44 = *((unsigned __int16 **)a2 + 10);
        if ( v43 == 2 )
        {
          if ( v40 )
          {
            v54 = result + 1121;
            do
            {
              v55 = *v44;
              v44 += 2;
              v56 = v55;
              if ( v55 >= 0x100 )
                v57 = -1;
              else
                v57 = v56;
              --v41;
              *v54++ = v57;
            }
            while ( v41 );
          }
        }
        else if ( v43 == 1 )
        {
          if ( v40 )
          {
            v45 = result + 1121;
            do
            {
              v46 = *v44++;
              v47 = v46;
              if ( v46 >= 0x100 )
                v48 = -1;
              else
                v48 = v47;
              --v41;
              *v45++ = v48;
            }
            while ( v41 );
          }
          if ( v39 )
          {
            v49 = *((unsigned __int16 **)a2 + 9);
            v50 = result + 1741;
            do
            {
              v51 = *v49++;
              v52 = v51;
              if ( v51 >= 0x100 )
                v53 = -1;
              else
                v53 = v52;
              --v42;
              *v50++ = v53;
            }
            while ( v42 );
          }
        }
        else
        {
          result = (char *)qdf_mem_copy(result + 1121, v44, v41);
        }
        goto LABEL_75;
      }
      v29 = "%s: Spectral SAMP message is NULL";
      v30 = "target_if_spectral_create_samp_msg";
      return (char *)qdf_trace_msg(0x56u, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, v30);
    }
  }
LABEL_75:
  v58 = *((unsigned int *)a2 + 47);
  if ( (unsigned int)v58 > 1 )
    goto LABEL_90;
  if ( (unsigned int)(*(_DWORD *)&v11[4 * v58] - 3) <= 1 )
  {
    v59 = *((_DWORD *)v13 + 313);
    if ( v59 != 1 )
    {
      if ( v59 != 2 )
        return result;
      if ( v13[v58 + 1398] == 1 && *(_DWORD *)&v13[4 * v58 + 1376] != 3 )
        goto LABEL_86;
    }
  }
  v60 = *((_DWORD **)v13 + 167);
  v61 = *(_QWORD *)v13;
  if ( *(v60 - 1) != -1315954906 )
    __break(0x8228u);
  result = (char *)((__int64 (__fastcall *)(__int64, _QWORD))v60)(v61, (unsigned int)v10);
  if ( !(_DWORD)result )
    ++*((_DWORD *)v13 + 144);
  v62 = *((_DWORD *)v13 + 313);
  ++target_if_spectral_create_samp_msg_samp_msg_index;
  if ( v62 == 2 )
  {
LABEL_86:
    v63 = *((unsigned int *)a2 + 47);
    if ( (unsigned int)v63 <= 1 )
    {
      if ( (unsigned int)(*(_DWORD *)&v11[4 * v63] - 3) <= 1 && v13[v63 + 1398] == 1 )
        return (char *)target_if_160mhz_delivery_state_change(v13);
      return result;
    }
LABEL_90:
    __break(0x5512u);
    return (char *)target_if_spectral_dump_fft(result);
  }
  return result;
}
