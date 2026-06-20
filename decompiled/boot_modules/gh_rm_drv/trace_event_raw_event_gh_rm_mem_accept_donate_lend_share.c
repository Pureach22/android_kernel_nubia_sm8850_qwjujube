__int64 __fastcall trace_event_raw_event_gh_rm_mem_accept_donate_lend_share(
        __int64 a1,
        char a2,
        int a3,
        int a4,
        _DWORD *a5,
        _DWORD *a6,
        unsigned __int16 *a7,
        int *a8,
        __int16 a9,
        char a10)
{
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w12
  int v13; // w23
  int v14; // w9
  int v15; // w9
  _DWORD *v16; // x19
  int v17; // w25
  int v18; // w21
  int v19; // w24
  unsigned int *v20; // x22
  int v21; // w9
  int v22; // w10
  unsigned __int16 *v23; // x27
  int v24; // w26
  int v25; // w20
  int v26; // w28
  __int64 result; // x0
  int v28; // w9
  unsigned __int64 v29; // x9
  _BYTE *v30; // x12
  char v31; // t1
  unsigned int v32; // w9
  int v33; // w10
  unsigned __int64 v34; // x9
  __int64 *v35; // x12
  __int64 v36; // t1
  int v37; // w11
  unsigned __int64 v38; // x11
  __int16 *v39; // x13
  __int16 v40; // t1
  int v41; // w8
  unsigned __int16 *v43; // x20
  _DWORD *v44; // x21
  _DWORD *v45; // x22
  int v46; // [xsp+4h] [xbp-5Ch]
  int v47; // [xsp+8h] [xbp-58h]
  _QWORD v52[7]; // [xsp+28h] [xbp-38h] BYREF

  v10 = a1;
  v52[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v52, 0, 48);
  if ( (v11 & 0x2C0) != 0 && (v11 & 0x100) == 0 )
  {
    v43 = a7;
    v44 = a6;
    v45 = a5;
    result = _trace_trigger_soft_disabled(a1);
    a5 = v45;
    a6 = v44;
    a7 = v43;
    v10 = a1;
    if ( (result & 1) != 0 )
      goto LABEL_36;
  }
  v12 = 68;
  if ( a5 )
  {
    v13 = *a5;
    v14 = 2 * *a5;
    v12 = (*a5 << 17) | 0x44;
  }
  else
  {
    v14 = 0;
    v13 = 0;
  }
  v46 = v14;
  v15 = v13 + v14;
  v16 = a5;
  if ( a6 )
  {
    v17 = *a6 <= 4u ? 8 * *a6 : 32;
    v18 = (v15 + 68) | (v17 << 16);
    v15 += v17;
    v19 = v15 + 68;
  }
  else
  {
    v18 = v15 + 68;
    v17 = 0;
    v19 = v15 + 68;
  }
  v20 = a6;
  v21 = v17 + v15;
  v47 = v12;
  if ( a7 )
  {
    v22 = *a7;
    v23 = a7;
    v24 = 2 * v22;
    v25 = (v21 + 68) | (v22 << 17);
  }
  else
  {
    v23 = nullptr;
    v24 = 0;
    v25 = v21 + 68;
  }
  v26 = v24 + v21;
  result = trace_event_buffer_reserve(v52, v10, v24 + v21 + v24 + 68LL);
  if ( !result )
    goto LABEL_36;
  *(_DWORD *)(result + 36) = v18;
  *(_DWORD *)(result + 40) = v19 | (v17 << 16);
  *(_DWORD *)(result + 24) = v47;
  *(_DWORD *)(result + 28) = (v46 + 68) | (v13 << 16);
  *(_DWORD *)(result + 48) = v25;
  *(_DWORD *)(result + 52) = (v26 + 68) | (v24 << 16);
  *(_DWORD *)(result + 12) = a3;
  *(_BYTE *)(result + 8) = a2;
  *(_DWORD *)(result + 16) = a4;
  if ( v16 )
  {
    v28 = *v16;
    *(_DWORD *)(result + 20) = *v16;
    if ( v28 )
    {
      v29 = 0;
      v30 = (char *)v16 + 6;
      do
      {
        *(_WORD *)(result + (unsigned __int16)v47 + 2 * v29) = *((_WORD *)v30 - 1);
        v31 = *v30;
        v30 += 4;
        *(_BYTE *)(result + ((unsigned __int16)(v46 + 68) & 0xFFFE) + v29++) = v31;
      }
      while ( v29 < *(unsigned int *)(result + 20) );
    }
    if ( v20 )
      goto LABEL_20;
  }
  else
  {
    *(_DWORD *)(result + 20) = 0;
    if ( v20 )
    {
LABEL_20:
      v32 = *v20;
      *(_DWORD *)(result + 32) = *v20;
      if ( v32 >= 4 )
        v33 = 4;
      else
        v33 = v32;
      *(_DWORD *)(result + 64) = v33;
      if ( v32 )
      {
        v34 = 0;
        v35 = (__int64 *)((char *)v20 + 14);
        do
        {
          *(_QWORD *)(result + (unsigned __int16)v18 + 8 * v34) = *(v35 - 1);
          v36 = *v35;
          v35 += 2;
          *(_QWORD *)(result + (unsigned __int16)v19 + 8 * v34++) = v36;
        }
        while ( v34 < *(unsigned int *)(result + 64) );
      }
      goto LABEL_29;
    }
  }
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 64) = 0;
LABEL_29:
  if ( v23 )
  {
    v37 = *v23;
    *(_WORD *)(result + 44) = v37;
    if ( v37 )
    {
      v38 = 0;
      v39 = (__int16 *)(v23 + 3);
      do
      {
        *(_WORD *)(result + (unsigned __int16)v25 + 2 * v38) = *(v39 - 1);
        v40 = *v39;
        v39 += 2;
        *(_WORD *)(result + (unsigned __int16)(v26 + 68) + 2 * v38++) = v40;
      }
      while ( v38 < *(unsigned __int16 *)(result + 44) );
    }
  }
  else
  {
    *(_WORD *)(result + 44) = 0;
  }
  v41 = *a8;
  *(_WORD *)(result + 60) = a9;
  *(_BYTE *)(result + 62) = a10;
  *(_DWORD *)(result + 56) = v41;
  result = trace_event_buffer_commit(v52);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
