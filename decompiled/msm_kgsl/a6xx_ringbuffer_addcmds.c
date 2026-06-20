__int64 __fastcall a6xx_ringbuffer_addcmds(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        const void *a5,
        int a6,
        int a7,
        _QWORD *a8)
{
  _DWORD *v12; // x23
  int v15; // w8
  char v16; // w26
  _DWORD *v17; // x0
  int v18; // w9
  int v19; // w25
  int v20; // w27
  __int64 v21; // x0
  const void *v22; // x1
  __int64 v23; // x10
  int v24; // w11
  int v25; // w12
  int v26; // w22
  int v27; // w8
  int v28; // w25
  int v29; // w8
  __int64 v30; // x0
  int v31; // w9
  int v32; // w8
  int v33; // w10
  __int64 v34; // x11
  int v35; // w8
  unsigned int v36; // w11
  __int64 v37; // x10
  int v38; // w12
  int v39; // w9
  int v40; // w11
  int v41; // w12
  int v42; // w8
  unsigned int v43; // w22
  int v44; // w10
  unsigned int v45; // w8
  int v48; // [xsp+10h] [xbp-10h] BYREF
  int v49; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+18h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = a6;
  if ( a3 && (*(_QWORD *)(a3 + 32) & 2) != 0 )
  {
    LODWORD(v12) = -2;
  }
  else
  {
    v48 = 0;
    __dmb(9u);
    if ( *(_DWORD *)(a1 + 24448) )
    {
      LODWORD(v12) = -71;
    }
    else
    {
      v15 = *(_DWORD *)(a2 + 36) + 1;
      *(_DWORD *)(a2 + 36) = v15;
      if ( a3 )
        *(_DWORD *)(a3 + 396) = v15;
      if ( (*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x800LL) != 0 )
        v16 = a4 & 0xFE;
      else
        v16 = a4;
      v17 = (_DWORD *)adreno_ringbuffer_allocspace(a2, (unsigned int)(a6 + 79));
      v12 = v17;
      if ( (unsigned __int64)v17 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( a3 )
          v18 = 787348174;
        else
          v18 = 787337229;
        *v17 = 1880096769;
        v17[1] = v18;
        v19 = a6xx_preemption_pre_ibsubmit(a1, (_QWORD *)a2, a3, (__int64)(v17 + 2));
        v20 = v19 + 4;
        v12[v19 + 2] = 1894055937;
        v12[v19 + 3] = 257;
        v21 = adreno_profile_preib_processing(a1, a3, &v48);
        if ( v21 )
        {
          v12[v20] = 1891598339;
          v20 = v19 + 8;
          v12[v19 + 5] = v21;
          v12[v19 + 6] = HIDWORD(v21);
          v12[v19 + 7] = v48;
        }
        v22 = a5;
        if ( a3 )
        {
          v12[v20] = 1883078659;
          v12[v20 + 1] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * *(_DWORD *)(a3 + 4);
          v23 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * *(unsigned int *)(a3 + 4);
          v24 = v20 + 2;
          v25 = v20 + 3;
          v20 += 4;
          v12[v25] = a7;
          v12[v24] = HIDWORD(v23);
        }
        v12[v20] = 1883078659;
        v26 = v20 + 4;
        v12[v20 + 1] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * *(_DWORD *)(a2 + 28) + 32520;
        v12[v20 + 2] = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * *(int *)(a2 + 28) + 32520) >> 32;
        v12[v20 + 3] = *(_DWORD *)(a2 + 36);
        if ( (v16 & 8) != 0 )
        {
          v12[v26] = 1894121473;
          v26 = v20 + 6;
          v12[v20 + 5] = 1;
        }
        if ( (v16 & 1) != 0 )
        {
          v27 = v26 + 1;
          v12[v26] = 1893662721;
          v26 += 2;
          v12[v27] = 0;
        }
        memcpy(&v12[v26], v22, (unsigned int)(4 * a6));
        v28 = v26 + a6;
        if ( (v16 & 1) != 0 )
        {
          v29 = v28 + 1;
          v12[v28] = 1893662721;
          v28 += 2;
          v12[v29] = 1;
        }
        v30 = adreno_profile_postib_processing(a1, a3, &v49);
        if ( v30 )
        {
          v31 = v28 + 2;
          v12[v28] = 1891598339;
          v12[v28 + 1] = v30;
          v32 = v28 + 3;
          v28 += 4;
          v12[v31] = HIDWORD(v30);
          v12[v32] = v48;
        }
        if ( (*(_QWORD *)(a1 + 112) & 2) != 0 )
          v12[v28++] = 1888649216;
        v12[v28] = 1883635716;
        v12[v28 + 1] = -2147483644;
        v33 = v28 + 2;
        v34 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
        v35 = 4;
        if ( a3 )
        {
          v12[v33] = v34 + 40 * *(_DWORD *)(a3 + 4) + 8;
          v36 = *(_DWORD *)(a3 + 4);
          v37 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
          v12[v28 + 5] = 1883635716;
          v38 = 8;
          v12[v28 + 4] = a7;
          v12[v28 + 3] = (v37 + 40 * (unsigned __int64)v36 + 8) >> 32;
          v39 = 10;
          v12[v28 + 6] = 4;
          v33 = v28 + 7;
          v34 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
          v35 = 9;
        }
        else
        {
          v39 = 5;
          v38 = 3;
        }
        v12[v33] = v34 + 40 * *(_DWORD *)(a2 + 28) + 32528;
        v40 = v28 + v38;
        v41 = v28 + v35;
        v42 = v28 + v39;
        v43 = v28 + v39 + 2;
        v12[v40] = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * *(int *)(a2 + 28) + 32528) >> 32;
        v44 = *(_DWORD *)(a2 + 36);
        v12[v42] = 1894055937;
        v12[v41] = v44;
        v12[v42 + 1] = 256;
        if ( (v16 & 2) != 0 )
        {
          v12[v43] = 1881571328;
          v43 = v42 + 3;
        }
        if ( (v16 & 8) != 0 )
        {
          v45 = v43 + 1;
          v12[v43] = 1894121473;
          v43 += 2;
          v12[v45] = 0;
        }
        *(_DWORD *)(a2 + 16) = v43
                             - a6
                             + *(_DWORD *)(a2 + 16)
                             + a6xx_preemption_post_ibsubmit((_QWORD *)a1, (__int64)&v12[v43])
                             - 79;
        LODWORD(v12) = a6xx_ringbuffer_submit(a2, a8, (*(_QWORD *)(a1 + 14240) & 0x200LL) == 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v12;
}
