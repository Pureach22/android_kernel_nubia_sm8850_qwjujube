__int64 __fastcall perf_trace_gh_rm_mem_accept_donate_lend_share(
        __int64 result,
        int a2,
        int a3,
        int a4,
        _DWORD *a5,
        unsigned int *a6,
        unsigned __int16 *a7,
        int *a8,
        __int16 a9,
        char a10)
{
  int v11; // w26
  int v12; // w27
  int v13; // w25
  int v14; // w8
  int v15; // w23
  __int64 v16; // x9
  __int64 v17; // x10
  int v18; // w8
  int v19; // w9
  int v20; // w28
  int v21; // w22
  __int64 v22; // x20
  unsigned __int64 StatusReg; // x21
  int v24; // w19
  __int64 v25; // x30
  _QWORD *v26; // x9
  int v27; // w2
  int v28; // w3
  char v29; // w10
  int v30; // w9
  unsigned int *v31; // x1
  unsigned __int64 v32; // x9
  _BYTE *v33; // x12
  char v34; // t1
  unsigned __int16 *v35; // x14
  unsigned int v36; // w9
  int v37; // w10
  unsigned __int64 v38; // x9
  __int64 *v39; // x12
  __int64 v40; // t1
  int v41; // w11
  unsigned __int64 v42; // x11
  __int16 *v43; // x13
  __int16 v44; // t1
  int v45; // w8
  _DWORD v46[4]; // [xsp+0h] [xbp-70h] BYREF
  __int64 v47; // [xsp+10h] [xbp-60h]
  int v48; // [xsp+1Ch] [xbp-54h]
  int v49; // [xsp+20h] [xbp-50h]
  int v50; // [xsp+24h] [xbp-4Ch]
  __int64 v51; // [xsp+28h] [xbp-48h]
  __int64 v52; // [xsp+30h] [xbp-40h]
  unsigned int *v53; // [xsp+38h] [xbp-38h]
  unsigned __int16 *v54; // [xsp+40h] [xbp-30h]
  int *v55; // [xsp+48h] [xbp-28h]
  __int64 v56; // [xsp+50h] [xbp-20h]
  int v57; // [xsp+5Ch] [xbp-14h]
  _QWORD *v58; // [xsp+60h] [xbp-10h]
  __int64 v59; // [xsp+68h] [xbp-8h]
  __int64 vars0; // [xsp+70h] [xbp+0h] BYREF

  v11 = 68;
  v55 = a8;
  v49 = a3;
  v50 = a4;
  v48 = a2;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a5 )
  {
    v13 = 0;
    v12 = 0;
    v14 = 0;
    if ( a6 )
      goto LABEL_3;
LABEL_8:
    v16 = (unsigned int)(v14 + 68);
    v15 = 0;
    v17 = (unsigned int)v16;
    goto LABEL_9;
  }
  v12 = *a5;
  v13 = 2 * *a5;
  v11 = (*a5 << 17) | 0x44;
  v14 = 3 * *a5;
  if ( !a6 )
    goto LABEL_8;
LABEL_3:
  if ( *a6 <= 4 )
    v15 = 8 * *a6;
  else
    v15 = 32;
  v16 = (v14 + 68) | (unsigned int)(v15 << 16);
  v14 += v15;
  v17 = (unsigned int)(v14 + 68);
LABEL_9:
  v18 = v15 + v14;
  v54 = a7;
  v52 = v16;
  v53 = a6;
  v51 = v17;
  if ( a7 )
  {
    v19 = *a7;
    v20 = 2 * v19;
    v21 = (v18 + 68) | (v19 << 17);
  }
  else
  {
    v20 = 0;
    v21 = v18 + 68;
  }
  v58 = nullptr;
  v22 = *(_QWORD *)(result + 104);
  v57 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v56 = result;
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v22) )
    goto LABEL_36;
  v24 = v20 + v18;
  v46[3] = ((v20 + v20 + v18 + 79) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc();
  if ( !result )
    goto LABEL_36;
  v25 = v47;
  v26 = v58;
  v28 = v51;
  v27 = v52;
  v58[31] = v46;
  v26[29] = &vars0;
  v26[32] = v25;
  v26[33] = 5;
  *(_DWORD *)(result + 24) = v11;
  *(_DWORD *)(result + 28) = (v13 + 68) | (v12 << 16);
  *(_DWORD *)(result + 36) = v27;
  *(_DWORD *)(result + 40) = v28 | (v15 << 16);
  *(_DWORD *)(result + 48) = v21;
  *(_DWORD *)(result + 52) = (v24 + 68) | (v20 << 16);
  v29 = v48;
  *(_DWORD *)(result + 12) = v49;
  LODWORD(v26) = v50;
  *(_BYTE *)(result + 8) = v29;
  *(_DWORD *)(result + 16) = (_DWORD)v26;
  if ( a5 )
  {
    v30 = *a5;
    v31 = v53;
    *(_DWORD *)(result + 20) = *a5;
    if ( v30 )
    {
      v32 = 0;
      v33 = (char *)a5 + 6;
      do
      {
        *(_WORD *)(result + (unsigned __int16)v11 + 2 * v32) = *((_WORD *)v33 - 1);
        v34 = *v33;
        v33 += 4;
        *(_BYTE *)(result + ((unsigned __int16)(v13 + 68) & 0xFFFE) + v32++) = v34;
      }
      while ( v32 < *(unsigned int *)(result + 20) );
    }
    v35 = v54;
    if ( v31 )
      goto LABEL_20;
  }
  else
  {
    v31 = v53;
    *(_DWORD *)(result + 20) = 0;
    v35 = v54;
    if ( v31 )
    {
LABEL_20:
      v36 = *v31;
      *(_DWORD *)(result + 32) = *v31;
      if ( v36 >= 4 )
        v37 = 4;
      else
        v37 = v36;
      *(_DWORD *)(result + 64) = v37;
      if ( v36 )
      {
        v38 = 0;
        v39 = (__int64 *)((char *)v31 + 14);
        do
        {
          *(_QWORD *)(result + (unsigned __int16)v27 + 8 * v38) = *(v39 - 1);
          v40 = *v39;
          v39 += 2;
          *(_QWORD *)(result + (unsigned __int16)v28 + 8 * v38++) = v40;
        }
        while ( v38 < *(unsigned int *)(result + 64) );
      }
      goto LABEL_29;
    }
  }
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 64) = 0;
LABEL_29:
  if ( v35 )
  {
    v41 = *v35;
    *(_WORD *)(result + 44) = v41;
    if ( v41 )
    {
      v42 = 0;
      v43 = (__int16 *)(v35 + 3);
      do
      {
        *(_WORD *)(result + (unsigned __int16)v21 + 2 * v42) = *(v43 - 1);
        v44 = *v43;
        v43 += 2;
        *(_WORD *)(result + (unsigned __int16)(v24 + 68) + 2 * v42++) = v44;
      }
      while ( v42 < *(unsigned __int16 *)(result + 44) );
    }
  }
  else
  {
    *(_WORD *)(result + 44) = 0;
  }
  v45 = *v55;
  *(_WORD *)(result + 60) = a9;
  *(_BYTE *)(result + 62) = a10;
  *(_DWORD *)(result + 56) = v45;
  result = perf_trace_run_bpf_submit();
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
