_QWORD *__fastcall _rmnet_frag_segment_data(__int64 a1, __int64 a2, __int64 a3, char a4, char a5)
{
  int v9; // w27
  int v10; // w22
  int v11; // w19
  int v12; // w24
  int v13; // w23
  _QWORD *result; // x0
  __int64 v15; // x9
  unsigned int v16; // w24
  __int64 v17; // x10
  __int64 v18; // x20
  __int64 v19; // x8
  __int64 v20; // x11
  __int64 v21; // x12
  __int64 v22; // x8
  __int64 v23; // x11
  __int64 v24; // x12
  unsigned int v25; // w9
  __int64 *v26; // x19
  __int64 *v27; // x28
  unsigned int v28; // w8
  unsigned int v29; // w26
  unsigned int v30; // w9
  unsigned int v31; // w9
  __int64 v32; // x1
  int v33; // w25
  unsigned int v34; // w27
  unsigned int v35; // w8
  unsigned int v36; // w22
  __int64 *v37; // x19
  unsigned int v38; // w23
  unsigned int v39; // w9
  unsigned int v40; // w9
  __int64 v41; // x1
  int v42; // w25
  int v43; // w8
  char v44; // w24
  unsigned int v45; // w1
  unsigned __int64 v46; // x0
  __int64 v47; // x19
  char v48; // w23
  char v49; // w8
  __int16 v50; // w9
  unsigned int v51; // w1
  unsigned __int64 v52; // x0
  unsigned __int64 v53; // x0
  char v54; // w8
  __int64 v55; // x0
  __int16 v56; // w8
  __int64 *v57; // x1
  char v58; // [xsp+Ch] [xbp-44h]
  __int64 v59; // [xsp+10h] [xbp-40h]
  char v60; // [xsp+1Ch] [xbp-34h]
  __int64 v61; // [xsp+20h] [xbp-30h]
  __int64 v63; // [xsp+30h] [xbp-20h] BYREF
  __int64 v64; // [xsp+38h] [xbp-18h]
  int v65; // [xsp+40h] [xbp-10h]
  __int64 v66; // [xsp+48h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int16 *)(a1 + 70);
  v10 = *(unsigned __int16 *)(a1 + 72);
  v11 = *(unsigned __int16 *)(a1 + 74);
  v12 = *(unsigned __int16 *)(a1 + 76);
  v13 = *(unsigned __int16 *)(a1 + 68);
  v61 = *(_QWORD *)(a1 + 32);
  result = rmnet_get_frag_descriptor(a2);
  if ( !result )
    goto LABEL_4;
  v15 = *(_QWORD *)(a1 + 8);
  v16 = v12 + v11;
  v17 = *(_QWORD *)(a1 + 16);
  v60 = a5;
  v18 = (__int64)result;
  v58 = a4;
  *result = *(_QWORD *)a1;
  result[1] = v15;
  v19 = *(_QWORD *)(a1 + 48);
  v59 = a3;
  v21 = *(_QWORD *)(a1 + 24);
  v20 = *(_QWORD *)(a1 + 32);
  result[5] = *(_QWORD *)(a1 + 40);
  result[6] = v19;
  result[3] = v21;
  result[4] = v20;
  v22 = *(_QWORD *)(a1 + 80);
  v23 = *(_QWORD *)(a1 + 56);
  v24 = *(_QWORD *)(a1 + 64);
  result[9] = *(_QWORD *)(a1 + 72);
  result[10] = v22;
  result[7] = v23;
  result[8] = v24;
  result[2] = v17;
  *result = result;
  result[1] = result;
  result[2] = result + 2;
  result[3] = result + 2;
  *((_DWORD *)result + 12) = 0;
  v25 = *(_DWORD *)(a1 + 48);
  if ( v16 > v25 )
    goto LABEL_3;
  v27 = (__int64 *)(a1 + 16);
  v26 = *(__int64 **)(a1 + 16);
  if ( v16 && v26 != v27 )
  {
    v28 = 0;
    v29 = v16;
    do
    {
      v30 = *((_DWORD *)v26 + 6);
      if ( v28 >= v30 )
      {
        v28 -= v30;
      }
      else
      {
        v31 = v30 - v28;
        if ( (v26[2] & 1) != 0 )
          v32 = 0;
        else
          v32 = v26[2];
        if ( v29 >= v31 )
          v33 = v31;
        else
          v33 = v29;
        if ( (rmnet_frag_descriptor_add_frag(v18, v32, *((_DWORD *)v26 + 7) + v28, v33) & 0x80000000) != 0 )
          goto LABEL_3;
        v28 = 0;
        v29 -= v33;
      }
      v26 = (__int64 *)*v26;
    }
    while ( v26 != v27 && v29 );
    v25 = *(_DWORD *)(a1 + 48);
  }
  v34 = v10 * v9;
  v35 = v16 + v13;
  v36 = v16 + v13 + v34;
  if ( v36 > v25 || v25 < v35 || v25 < v34 )
    goto LABEL_3;
  if ( v34 )
  {
    v37 = (__int64 *)*v27;
    if ( (__int64 *)*v27 != v27 )
    {
      v38 = v34;
      do
      {
        v39 = *((_DWORD *)v37 + 6);
        if ( v35 >= v39 )
        {
          v35 -= v39;
        }
        else
        {
          v40 = v39 - v35;
          if ( (v37[2] & 1) != 0 )
            v41 = 0;
          else
            v41 = v37[2];
          if ( v38 >= v40 )
            v42 = v40;
          else
            v42 = v38;
          if ( (rmnet_frag_descriptor_add_frag(v18, v41, *((_DWORD *)v37 + 7) + v35, v42) & 0x80000000) != 0 )
            goto LABEL_3;
          v35 = 0;
          v38 -= v42;
        }
        v37 = (__int64 *)*v37;
      }
      while ( v37 != v27 && v38 );
    }
  }
  v43 = *(unsigned __int8 *)(a1 + 79);
  if ( v43 == 17 )
  {
    v51 = *(unsigned __int16 *)(a1 + 74);
    v63 = 0;
    v52 = rmnet_frag_header_ptr(a1, v51, 8u, (__int64)&v63);
    v44 = v60;
    if ( !v52 )
      goto LABEL_3;
    if ( *(_BYTE *)(a1 + 78) == 4 )
      v44 = (*(_WORD *)(v52 + 6) == 0) | v60;
    goto LABEL_48;
  }
  v44 = v60;
  if ( v43 != 6 )
  {
LABEL_48:
    v47 = v59;
    v48 = v58;
    goto LABEL_49;
  }
  v45 = *(unsigned __int16 *)(a1 + 74);
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v46 = rmnet_frag_header_ptr(a1, v45, 0x14u, (__int64)&v63);
  v47 = v59;
  v48 = v58;
  if ( !v46 )
    goto LABEL_3;
  v49 = *(_BYTE *)(v18 + 81);
  *(_BYTE *)(v18 + 81) = v49 | 8;
  *(_DWORD *)(v18 + 60) = bswap32(bswap32(*(_DWORD *)(v46 + 4)) + *(unsigned __int16 *)(a1 + 68));
  if ( (*(_WORD *)(v46 + 12) & 0x900) != 0 && v36 < *(_DWORD *)(a1 + 48) )
  {
    v50 = *(_WORD *)(v46 + 12) & 0xF6FF;
    *(_BYTE *)(v18 + 81) = v49 | 0x28;
    *(_WORD *)(v18 + 66) = v50;
  }
LABEL_49:
  if ( *(_BYTE *)(a1 + 78) != 4 )
  {
    v54 = *(_BYTE *)(v18 + 81);
    goto LABEL_53;
  }
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v53 = rmnet_frag_header_ptr(a1, 0, 0x14u, (__int64)&v63);
  if ( !v53 )
  {
LABEL_3:
    result = (_QWORD *)rmnet_recycle_frag_descriptor((_QWORD *)v18, a2);
    goto LABEL_4;
  }
  v54 = *(_BYTE *)(v18 + 81) | 4;
  *(_BYTE *)(v18 + 81) = v54;
  *(_WORD *)(v18 + 64) = bswap32(*(unsigned __int8 *)(a1 + 80) + (bswap32(*(unsigned __int16 *)(v53 + 4)) >> 16)) >> 16;
LABEL_53:
  *(_BYTE *)(v18 + 81) = v54 & 0xFE | v44 & 1;
  v55 = *(unsigned __int8 *)(v61 + 2688);
  ++*(_QWORD *)(v61 + 2840);
  result = (_QWORD *)rmnet_module_hook_perf_coal_common_stat(v55, 1);
  v56 = *(_WORD *)(a1 + 68);
  *(_WORD *)(a1 + 72) = 0;
  *(_BYTE *)(a1 + 80) = v48 + 1;
  *(_QWORD *)(a1 + 40) = 0;
  *(_WORD *)(a1 + 68) = v56 + v34;
  v57 = *(__int64 **)(v47 + 8);
  if ( v18 == v47 || v57 == (__int64 *)v18 || *v57 != v47 )
  {
    result = (_QWORD *)_list_add_valid_or_report(v18, v57, v47);
  }
  else
  {
    *(_QWORD *)(v47 + 8) = v18;
    *(_QWORD *)v18 = v47;
    *(_QWORD *)(v18 + 8) = v57;
    *v57 = v18;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
