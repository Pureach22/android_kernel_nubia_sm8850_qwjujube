__int64 __fastcall gen8_ringbuffer_addcmds(
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
  _DWORD *v16; // x0
  int v17; // w9
  int v18; // w0
  int v19; // w25
  int v20; // w27
  __int64 v21; // x0
  const void *v22; // x1
  __int64 v23; // x10
  int v24; // w11
  int v25; // w12
  char v26; // w25
  int v27; // w26
  int v28; // w27
  __int64 v29; // x0
  int v30; // w9
  int v31; // w8
  __int64 v32; // x11
  __int64 v33; // x10
  unsigned __int64 v34; // x10
  unsigned __int64 v35; // x12
  int v36; // w22
  unsigned int v37; // w11
  __int64 v38; // x10
  int v39; // w9
  unsigned __int64 v40; // x10
  int v41; // w8
  int v42; // w9
  int v43; // w8
  int v47; // [xsp+10h] [xbp-10h] BYREF
  int v48; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+18h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = a6;
  if ( a3 && (*(_QWORD *)(a3 + 32) & 2) != 0 )
  {
    LODWORD(v12) = -2;
  }
  else
  {
    v47 = 0;
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
      v16 = (_DWORD *)adreno_ringbuffer_allocspace(a2, (unsigned int)(a6 + 104));
      v12 = v16;
      if ( (unsigned __int64)v16 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( a3 )
          v17 = 787348174;
        else
          v17 = 787337229;
        *v16 = 1880096769;
        v16[1] = v17;
        v18 = gen8_preemption_pre_ibsubmit(a1, (unsigned __int64 *)a2, a3, (__int64)(v16 + 2));
        v12[v18 + 2] = 1888944129;
        v19 = v18;
        v12[v18 + 3] = 3;
        v12[v18 + 4] = 1894055937;
        v12[v18 + 5] = 257;
        v12[v18 + 6] = 1888944129;
        v20 = v18 + 8;
        v12[v18 + 7] = 1;
        v21 = adreno_profile_preib_processing(a1, a3, &v47);
        if ( v21 )
        {
          v12[v20] = 1891598339;
          v20 = v19 + 12;
          v12[v19 + 9] = v21;
          v12[v19 + 10] = HIDWORD(v21);
          v12[v19 + 11] = v47;
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
        v26 = a4;
        v27 = v20 + 4;
        v12[v20 + 1] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * *(_DWORD *)(a2 + 28) + 32520;
        v12[v20 + 2] = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * *(int *)(a2 + 28) + 32520) >> 32;
        v12[v20 + 3] = *(_DWORD *)(a2 + 36);
        if ( (a4 & 8) != 0 )
        {
          v12[v20 + 5] = -2013265920;
          v12[v27] = 1888944129;
          v27 = v20 + 8;
          v12[v20 + 6] = 1894121473;
          v12[v20 + 7] = 1;
        }
        memcpy(&v12[v27], v22, (unsigned int)(4 * a6));
        v28 = v27 + a6;
        v29 = adreno_profile_postib_processing(a1, a3, &v48);
        if ( v29 )
        {
          v30 = v28 + 2;
          v12[v28] = 1891598339;
          v12[v28 + 1] = v29;
          v31 = v28 + 3;
          v28 += 4;
          v12[v30] = HIDWORD(v29);
          v12[v31] = v47;
        }
        if ( (*(_QWORD *)(a1 + 112) & 2) != 0 )
          v12[v28++] = 1888649216;
        if ( a3 )
        {
          if ( (*(_BYTE *)(a3 + 202) & 2) == 0 )
          {
            v32 = *(int *)(a2 + 28);
            v33 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL);
            v12[v28 + 1] = 2;
            v12[v28] = 1888944129;
            v12[v28 + 2] = 1883635716;
            v12[v28 + 3] = 134217777;
            v34 = v33 + 32 * v32 + 8;
            v12[v28 + 4] = v34;
            v35 = HIDWORD(v34);
            v12[v28 + 5] = HIDWORD(v34);
            LODWORD(v32) = *(_DWORD *)(a2 + 36);
            v12[v28 + 8] = 1;
            v12[v28 + 9] = 1888747524;
            v12[v28 + 7] = 1888944129;
            v12[v28 + 10] = 0;
            v12[v28 + 6] = v32;
            LODWORD(v32) = v28 + 12;
            v12[v28 + 11] = v34;
            LODWORD(v34) = v28 + 13;
            v28 += 14;
            v12[(unsigned int)v32] = v35;
            v12[(unsigned int)v34] = *(_DWORD *)(a2 + 36);
          }
          v12[v28] = 1883635716;
          v12[v28 + 1] = -2013265871;
          v36 = v28 + 10;
          v12[v28 + 2] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * *(_DWORD *)(a3 + 4) + 8;
          v37 = *(_DWORD *)(a3 + 4);
          v38 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
          v12[v28 + 5] = 1883635716;
          v12[v28 + 4] = a7;
          v12[v28 + 3] = (v38 + 40 * (unsigned __int64)v37 + 8) >> 32;
          v12[v28 + 6] = 134217777;
          v12[v28 + 7] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * *(_DWORD *)(a2 + 28) + 32528;
          v39 = v28 + 8;
          v40 = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * *(int *)(a2 + 28) + 32528) >> 32;
          v41 = v28 + 9;
        }
        else
        {
          v12[v28] = 1883635716;
          v12[v28 + 1] = -2013265871;
          v36 = v28 + 5;
          v12[v28 + 2] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * *(_DWORD *)(a2 + 28) + 32528;
          v39 = v28 + 3;
          v40 = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * *(int *)(a2 + 28) + 32528) >> 32;
          v41 = v28 + 4;
        }
        v12[v39] = v40;
        v12[v41] = *(_DWORD *)(a2 + 36);
        if ( (v26 & 2) != 0 )
          v12[v36++] = 1881571328;
        if ( (v26 & 8) != 0 )
        {
          v12[v36 + 1] = 0x8000000;
          v12[v36] = 1888944129;
          v12[v36 + 2] = 1894121473;
          v42 = v36 + 4;
          v12[v36 + 3] = 0;
          v43 = v36 + 5;
          v36 += 6;
          v12[v42] = 1888944129;
          v12[v43] = 0x80000000;
        }
        v12[v36 + 1] = 3;
        v12[v36 + 3] = 256;
        v12[v36 + 2] = 1894055937;
        v12[v36] = 1888944129;
        v12[v36 + 4] = 1888944129;
        v12[v36 + 5] = 1;
        *(_DWORD *)(a2 + 16) = v36
                             - a6
                             + *(_DWORD *)(a2 + 16)
                             + gen8_preemption_post_ibsubmit((_QWORD *)a1, (__int64)&v12[v36 + 6])
                             - 98;
        LODWORD(v12) = gen8_ringbuffer_submit(a2, a8);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v12;
}
