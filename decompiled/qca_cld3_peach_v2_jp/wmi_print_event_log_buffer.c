__int64 __fastcall wmi_print_event_log_buffer(
        __int64 a1,
        unsigned int a2,
        __int64 (__fastcall *a3)(__int64, const char *),
        __int64 a4)
{
  unsigned int v6; // w19
  unsigned int v7; // w8
  int *v8; // x9
  unsigned int v9; // w10
  unsigned int v10; // w25
  int v11; // w22
  __int64 result; // x0
  __int64 v13; // x7
  unsigned int v14; // w26
  unsigned int *v15; // x19
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned int v18; // w0
  unsigned int v19; // w24
  int v20; // w0
  __int64 v21; // x24
  int v22; // w0
  __int64 v23; // x24
  int v24; // w0
  __int64 v25; // x8
  long double v26; // q0
  __int64 v27; // [xsp+0h] [xbp-90h]
  __int64 v28; // [xsp+8h] [xbp-88h] BYREF
  __int64 v29; // [xsp+10h] [xbp-80h]
  __int64 v30; // [xsp+18h] [xbp-78h]
  __int64 v31; // [xsp+20h] [xbp-70h]
  __int64 v32; // [xsp+28h] [xbp-68h]
  __int64 v33; // [xsp+30h] [xbp-60h]
  __int64 v34; // [xsp+38h] [xbp-58h]
  __int64 v35; // [xsp+40h] [xbp-50h]
  __int64 v36; // [xsp+48h] [xbp-48h]
  __int64 v37; // [xsp+50h] [xbp-40h]
  __int64 v38; // [xsp+58h] [xbp-38h]
  __int64 v39; // [xsp+60h] [xbp-30h]
  __int64 v40; // [xsp+68h] [xbp-28h]
  __int64 v41; // [xsp+70h] [xbp-20h]
  __int64 v42; // [xsp+78h] [xbp-18h]
  __int64 v43; // [xsp+80h] [xbp-10h]
  __int64 v44; // [xsp+88h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 24);
  v7 = *(_DWORD *)(a1 + 8);
  v8 = *(int **)(a1 + 16);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  if ( v6 >= a2 )
    v9 = a2;
  else
    v9 = v6;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( v9 >= v7 )
    v10 = v7;
  else
    v10 = v9;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v11 = *v8;
  v27 = a4;
  if ( *((_DWORD *)a3 - 1) != 1872960511 )
    __break(0x8222u);
  result = a3(a4, "Time (seconds)      Event Id             Payload");
  if ( v10 )
  {
    v14 = (v6 - v10 + v11) % v6;
    do
    {
      v15 = (unsigned int *)(*(_QWORD *)a1 + 32LL * v14);
      v16 = *((_QWORD *)v15 + 3);
      if ( 10 * v16 < v16 )
        v17 = 10 * (v16 / 0xC0);
      else
        v17 = 10 * v16 / 0xC0;
      scnprintf(
        &v28,
        128,
        "% 8lld.%06lld    %6u (0x%06x)    ",
        v17 / 0xF4240,
        v17 % 0xF4240,
        *v15,
        *v15,
        v13,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44);
      if ( v18 >= 0x81
        || (v19 = v18,
            scnprintf((char *)&v28 + v18, 128LL - v18, "0x%08x ", v15[1]),
            v21 = v20 + v19,
            (unsigned int)v21 > 0x80)
        || (scnprintf((char *)&v28 + v21, 128 - v21, "0x%08x ", v15[2]),
            v23 = (unsigned int)(v22 + v21),
            (unsigned int)v23 > 0x80)
        || (scnprintf((char *)&v28 + v23, 128 - v23, "0x%08x ", v15[3]),
            v25 = (unsigned int)(v24 + v23),
            (unsigned int)v25 > 0x80) )
      {
        __break(0x5512u);
      }
      *(double *)&v26 = scnprintf((char *)&v28 + v25, 128 - v25, "0x%08x ", v15[4]);
      if ( *((_DWORD *)a3 - 1) != 1872960511 )
        __break(0x8234u);
      result = ((__int64 (__fastcall *)(__int64, __int64 *, long double))a3)(v27, &v28, v26);
      --v10;
      if ( v14 + 1 < *(_DWORD *)(a1 + 24) )
        ++v14;
      else
        v14 = 0;
    }
    while ( v10 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
