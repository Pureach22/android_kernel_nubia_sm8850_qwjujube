__int64 __fastcall cm_roam_trigger_info_event(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, char a4)
{
  unsigned int v8; // w23
  __int64 v9; // x0
  int v10; // w9
  int v11; // w8
  int v12; // w10
  int v13; // w12
  int v14; // w9
  __int64 v15; // x10
  _DWORD *v16; // x9
  int v17; // w9
  int v18; // w10
  _DWORD *v19; // x9
  int v20; // t1
  int v21; // w8
  __int64 result; // x0
  __int64 v23; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  int v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v23, 0x34u, 0);
  v8 = *(_DWORD *)(a1 + 16);
  HIWORD(v23) = a3;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v9 = ktime_get();
  v10 = 0;
  v11 = *(_DWORD *)(a1 + 4);
  v25 = 1000LL * v8;
  v26 = v9 / 1000;
  if ( (unsigned int)(v11 - 1) <= 0x12 )
    v10 = dword_AEFD0C[v11 - 1];
  v12 = *(_DWORD *)(a1 + 8);
  v13 = *a2;
  if ( (unsigned int)(v12 - 1) >= 0xA )
    v12 = 0;
  HIDWORD(v27) = v10;
  LODWORD(v28) = v12;
  LOBYTE(v27) = 2;
  if ( v13 == 1 )
  {
    if ( *((_WORD *)a2 + 2) )
    {
      if ( ((*((_WORD *)a2 + 2) - 1) & 0xFFF8) != 0 )
        v14 = 8;
      else
        v14 = (unsigned __int16)(*((_WORD *)a2 + 2) - 1);
      v15 = (unsigned int)(v14 + 1);
      v16 = a2 + 116;
      while ( *((_BYTE *)v16 - 20) != 1 )
      {
        --v15;
        v16 += 15;
        if ( !v15 )
          goto LABEL_18;
      }
      v20 = *v16;
      v19 = v16 - 2;
      HIDWORD(v28) = -v20;
      goto LABEL_17;
    }
  }
  else
  {
    v17 = *(_DWORD *)(a1 + 12);
    if ( v17 )
    {
      v18 = -*(_DWORD *)(a1 + 20);
      HIDWORD(v28) = -v17;
      v29 = v18;
      v19 = a2 + 108;
LABEL_17:
      WORD1(v27) = *v19;
    }
  }
LABEL_18:
  if ( v11 == 5 || v11 == 3 )
  {
    if ( *(_BYTE *)(a1 + 1) == 1 )
      v21 = *(unsigned __int8 *)(a1 + 21);
    else
      v21 = *(_DWORD *)(a1 + 20);
    v29 = -v21;
  }
  BYTE1(v27) = a4 & 1 | (2 * a2[677]);
  result = host_diag_event_report_payload(3356, 52, &v23);
  _ReadStatusReg(SP_EL0);
  return result;
}
