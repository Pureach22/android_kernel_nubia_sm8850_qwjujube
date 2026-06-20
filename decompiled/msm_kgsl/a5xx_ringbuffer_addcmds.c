__int64 __fastcall a5xx_ringbuffer_addcmds(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        char a4,
        const void *a5,
        int a6,
        int a7,
        _QWORD *a8)
{
  _DWORD *v12; // x23
  int v16; // w8
  _DWORD *v17; // x0
  int v18; // w9
  int v19; // w25
  int v20; // w28
  __int64 v21; // x0
  const void *v22; // x1
  __int64 v23; // x9
  int v24; // w10
  int v25; // w11
  int v26; // w22
  int v27; // w8
  int v28; // w28
  int v29; // w8
  __int64 v30; // x0
  int v31; // w9
  int v32; // w8
  __int64 v33; // x11
  int v34; // w9
  unsigned int v35; // w10
  __int64 v36; // x9
  int v37; // w12
  int v38; // w10
  int v39; // w8
  int v40; // w22
  int v41; // w8
  int v44; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 && (*(_QWORD *)(a3 + 32) & 2) != 0 )
  {
    LODWORD(v12) = -2;
  }
  else
  {
    v44 = 0;
    __dmb(9u);
    if ( *(_DWORD *)(a1 + 24448) )
    {
      LODWORD(v12) = -71;
    }
    else
    {
      v16 = a2[9] + 1;
      a2[9] = v16;
      if ( a3 )
        *(_DWORD *)(a3 + 396) = v16;
      v17 = (_DWORD *)adreno_ringbuffer_allocspace(a2, (unsigned int)(a6 + 64));
      v12 = v17;
      if ( (unsigned __int64)v17 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( a3 )
          v18 = 787348174;
        else
          v18 = 787337229;
        *v17 = 1880096769;
        v17[1] = v18;
        v19 = a5xx_preemption_pre_ibsubmit(a1, (__int64)a2, a3, (__int64)(v17 + 2));
        v20 = v19 + 2;
        v21 = adreno_profile_preib_processing(a1, a3, &v44);
        if ( v21 )
        {
          v12[v20] = 1891598339;
          v20 = v19 + 6;
          v12[v19 + 3] = v21;
          v12[v19 + 4] = HIDWORD(v21);
          v12[v19 + 5] = v44;
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
        v12[v20 + 1] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40 * a2[7] + 32520;
        v12[v20 + 2] = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * (int)a2[7] + 32520) >> 32;
        v12[v20 + 3] = a2[9];
        if ( (a4 & 8) != 0 )
        {
          v12[v26] = 1894121473;
          v26 = v20 + 6;
          v12[v20 + 5] = 1;
        }
        if ( (a4 & 1) != 0 )
        {
          v27 = v26 + 1;
          v12[v26] = 1893662721;
          v26 += 2;
          v12[v27] = 0;
        }
        memcpy(&v12[v26], v22, (unsigned int)(4 * a6));
        v28 = v26 + a6;
        if ( (a4 & 1) != 0 )
        {
          v29 = v28 + 1;
          v12[v28] = 1893662721;
          v28 += 2;
          v12[v29] = 1;
        }
        v30 = adreno_profile_postib_processing(a1, a3, &v44);
        if ( v30 )
        {
          v31 = v28 + 2;
          v12[v28] = 1891598339;
          v12[v28 + 1] = v30;
          v32 = v28 + 3;
          v28 += 4;
          v12[v31] = HIDWORD(v30);
          v12[v32] = v44;
        }
        if ( **(_DWORD **)(a1 + 14264) != 510 && (*(_QWORD *)(a1 + 112) & 2) != 0 )
          v12[v28++] = 1888649216;
        v12[v28] = 1883078659;
        v12[v28 + 1] = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 24;
        v12[v28 + 2] = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 24LL) >> 32;
        v12[v28 + 3] = ++a5xx_ringbuffer_addcmds_sequence;
        v12[v28 + 4] = 1883635716;
        v12[v28 + 5] = -2147483644;
        v33 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
        v34 = v28 + 6;
        if ( a3 )
        {
          v12[v34] = v33 + 40 * *(_DWORD *)(a3 + 4) + 8;
          v35 = *(_DWORD *)(a3 + 4);
          v36 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
          v12[v28 + 9] = 1883635716;
          v37 = 12;
          v12[v28 + 8] = a7;
          v12[v28 + 7] = (v36 + 40 * (unsigned __int64)v35 + 8) >> 32;
          v38 = 13;
          v12[v28 + 10] = 4;
          v34 = v28 + 11;
          v33 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
          v39 = 14;
        }
        else
        {
          v39 = 9;
          v38 = 8;
          v37 = 7;
        }
        v40 = v28 + v39;
        v12[v34] = v33 + 40 * a2[7] + 32528;
        v12[v28 + v37] = (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL) + 40LL * (int)a2[7] + 32528) >> 32;
        v12[v28 + v38] = a2[9];
        if ( (a4 & 2) != 0 )
          v12[v40++] = 1881571328;
        if ( (a4 & 8) != 0 )
        {
          v41 = v40 + 1;
          v12[v40] = 1894121473;
          v40 += 2;
          v12[v41] = 0;
        }
        a2[4] = v40 - a6 + a2[4] + a5xx_preemption_post_ibsubmit(a1, (__int64)&v12[v40]) - 64;
        a5xx_ringbuffer_submit(a2, a8, (*(_QWORD *)(a1 + 14240) & 0x200LL) == 0);
        LODWORD(v12) = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v12;
}
