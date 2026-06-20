__int64 __fastcall sap_sort_chl_weight(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  __int64 v23; // x23
  unsigned __int64 v24; // x22
  unsigned int *v25; // x24
  __int64 v26; // x25
  unsigned __int64 v27; // x27
  unsigned int *v28; // x10
  __int64 v29; // x12
  unsigned int v30; // w11
  __int64 v31; // x13
  unsigned int v32; // w15
  void *v33; // x21
  void *v34; // x22
  unsigned int v35; // w8
  int v36; // w22
  unsigned __int64 v37; // x24
  _DWORD *v38; // x25
  unsigned int v39; // w26
  _DWORD *v40; // x12
  unsigned int v41; // w9
  unsigned __int64 v42; // x11
  unsigned int v43; // w9
  int v44; // w13
  int v45; // w14
  unsigned __int64 v46; // x28
  int v47; // w19
  unsigned int v48; // w21
  void *v49; // x21
  __int64 v50; // [xsp+8h] [xbp-28h]
  _QWORD v51[4]; // [xsp+10h] [xbp-20h] BYREF

  v51[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v51, 0, 24);
  result = sap_update_vlp_deprority_chan(a1, (__int64 *)a2, a4, a5, a6, a7, a8, a9, a10, a11);
  v22 = *(unsigned __int8 *)(a2 + 8);
  v23 = *(_QWORD *)a2;
  if ( *(_BYTE *)(a2 + 8) )
  {
    v24 = 0;
    v25 = (unsigned int *)(v23 + 36);
    v26 = 1;
    do
    {
      v27 = v24 + 1;
      if ( v24 + 1 >= v22 )
      {
        v30 = v24;
      }
      else
      {
        v28 = v25;
        v29 = v26;
        v30 = v24;
        do
        {
          v31 = v23 + 24LL * v30;
          v32 = *(_DWORD *)(v31 + 12);
          if ( *v28 < v32 )
          {
            v30 = v29;
          }
          else if ( *v28 == v32 && *((unsigned __int16 *)v28 - 4) < (unsigned int)*(unsigned __int16 *)(v31 + 4) )
          {
            v30 = v29;
          }
          ++v29;
          v28 += 6;
        }
        while ( v22 != v29 );
      }
      if ( v24 != v30 )
      {
        v33 = (void *)(v23 + 24LL * v30);
        qdf_mem_copy(v51, v33, 0x18u);
        v34 = (void *)(v23 + 24 * v24);
        qdf_mem_copy(v33, v34, 0x18u);
        result = (__int64)qdf_mem_copy(v34, v51, 0x18u);
        v22 = *(unsigned __int8 *)(a2 + 8);
      }
      ++v26;
      v25 += 6;
      v24 = v27;
    }
    while ( v27 < v22 );
  }
  if ( *(_BYTE *)(*(_QWORD *)(a3 + 1536) + 604LL) == 1 )
  {
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: ACS Ext: Same Channel Randomization Enabled",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "sap_sort_chl_weight");
    v35 = *(unsigned __int8 *)(a2 + 8);
    if ( *(_BYTE *)(a2 + 8) )
    {
      v36 = 0;
      v37 = 0;
      v38 = (_DWORD *)(v23 + 36);
      v39 = 1;
      v50 = a2;
      do
      {
        v40 = v38;
        if ( v35 <= v39 )
          v41 = v39;
        else
          v41 = v35;
        v42 = v37;
        v43 = v41 - 1;
        while ( 1 )
        {
          if ( v42 + 1 >= v35 )
            goto LABEL_28;
          if ( *(v40 - 6) != *v40 )
            break;
          v44 = *((unsigned __int16 *)v40 - 16);
          v45 = *((unsigned __int16 *)v40 - 4);
          v40 += 6;
          ++v42;
          if ( v44 != v45 )
          {
            v43 = v42 - 1;
LABEL_28:
            if ( v37 == v43 )
              goto LABEL_19;
            goto LABEL_31;
          }
        }
        v43 = v42;
        if ( v37 == (unsigned int)v42 )
          goto LABEL_19;
LABEL_31:
        v46 = v43 - (unsigned int)v37 + 1;
        if ( v43 + v36 <= 1 )
          v47 = 1;
        else
          v47 = v43 + v36;
        do
        {
          v48 = v37 + ktime_get_with_offset(0) % v46;
          qdf_mem_copy(v51, (const void *)(v23 + 24 * v37), 0x18u);
          v49 = (void *)(v23 + 24LL * v48);
          qdf_mem_copy((void *)(v23 + 24 * v37), v49, 0x18u);
          result = (__int64)qdf_mem_copy(v49, v51, 0x18u);
          --v47;
        }
        while ( v47 );
        v35 = *(unsigned __int8 *)(v50 + 8);
LABEL_19:
        ++v37;
        ++v39;
        --v36;
        v38 += 6;
      }
      while ( v37 < v35 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
