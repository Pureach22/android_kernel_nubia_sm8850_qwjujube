__int64 __fastcall generate_realtime_timestamp(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        _DWORD *a6)
{
  int v6; // w8
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x19
  int v10; // w12
  __int64 result; // x0
  __int64 v12; // x19
  unsigned __int64 v13; // x21
  __int64 v14; // x20
  __int64 v15; // x1
  __int64 v16; // x22
  __int64 v17; // x21
  __int64 v18; // x1
  __int64 v19; // x23
  int v20; // w27
  int v21; // w25
  int v22; // w26
  int v23; // w24
  __int64 v24; // x0
  __int64 v25; // x1
  unsigned int v26; // w21
  __int64 v28; // x22
  __int64 v29; // [xsp+34h] [xbp-4Ch] BYREF
  int v30; // [xsp+3Ch] [xbp-44h]
  int v31; // [xsp+40h] [xbp-40h]
  int v32; // [xsp+44h] [xbp-3Ch]
  unsigned __int64 v33; // [xsp+58h] [xbp-28h] BYREF
  _QWORD v34[2]; // [xsp+60h] [xbp-20h] BYREF
  char v35; // [xsp+70h] [xbp-10h]
  __int64 v36; // [xsp+78h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a1 + a2);
  v33 = 0;
  v34[0] = 0;
  v35 = 0;
  v34[1] = 0;
  if ( v6 != 91 )
  {
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v7 = g_hlos_uptime_baseline;
  if ( a3 >= 0x11 )
    v8 = 17;
  else
    v8 = a3;
  if ( a3 < 2 )
  {
    LODWORD(v8) = 1;
  }
  else
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = *(unsigned __int8 *)(a1 + (a2 + 1 + (unsigned int)v9) % a4);
      if ( v10 == 93 )
        break;
      *((_BYTE *)v34 + v9++) = v10;
      if ( v8 - 1 == v9 )
        goto LABEL_11;
    }
    v26 = a3;
    v28 = a5;
    *((_BYTE *)v34 + v9) = 0;
    if ( (unsigned int)kstrtoull(v34, 16, &v33) )
      goto LABEL_17;
    LODWORD(v8) = v9 + 1;
    a5 = v28;
    a3 = v26;
    *a6 = v9 + 2;
  }
LABEL_11:
  result = 4294967274LL;
  if ( (_DWORD)v8 != a3 && (_DWORD)v8 != 17 )
  {
    v12 = a5;
    if ( v33 <= g_tz_ticks_baseline )
      v13 = v7 - 10000 * (g_tz_ticks_baseline - v33) / g_tz_ticks_frequency;
    else
      v13 = 10000 * (v33 - g_tz_ticks_baseline) / g_tz_ticks_frequency + v7;
    v14 = ns_to_timespec64(v13);
    v16 = v15;
    v17 = ktime_mono_to_any(v13, 0);
    ns_to_timespec64(v17);
    v19 = v18;
    rtc_ktime_to_tm(&v29, v17);
    v20 = v32;
    v21 = v30;
    v22 = v31;
    LODWORD(v17) = v29;
    v23 = HIDWORD(v29);
    v24 = ns_to_timespec64(10000 * v33 / g_tz_ticks_frequency);
    result = scnprintf(
               v12,
               128,
               "[%02d-%02d %02d:%02d:%02d.%05ld][%lld.%05ld][%lld.%05ld]",
               v20 + 1,
               v22,
               v21,
               v23,
               v17,
               v19 / 10000,
               v14,
               v16 / 10000,
               v24,
               v25 / 10000);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
