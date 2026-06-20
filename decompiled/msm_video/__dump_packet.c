unsigned int *__fastcall _dump_packet(
        unsigned int *result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int *v8; // x19
  unsigned int v9; // w20
  unsigned int v10; // w25
  unsigned int v11; // w8
  unsigned int v12; // w28
  __int64 v13; // x1
  int v14; // [xsp+0h] [xbp-70h]
  __int64 v15; // [xsp+8h] [xbp-68h] BYREF
  __int64 v16; // [xsp+10h] [xbp-60h]
  __int64 v17; // [xsp+18h] [xbp-58h]
  __int64 v18; // [xsp+20h] [xbp-50h]
  __int64 v19; // [xsp+28h] [xbp-48h]
  __int64 v20; // [xsp+30h] [xbp-40h]
  __int64 v21; // [xsp+38h] [xbp-38h]
  __int64 v22; // [xsp+40h] [xbp-30h]
  __int64 v23; // [xsp+48h] [xbp-28h]
  __int64 v24; // [xsp+50h] [xbp-20h]
  __int64 v25; // [xsp+58h] [xbp-18h]
  __int64 v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v8 = result;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *result;
  v9 = result[1];
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  if ( (msm_vidc_debug & 0x10) != 0 )
  {
    v14 = *(_DWORD *)(*(_QWORD *)a3 + 52LL);
    result = (unsigned int *)printk(&unk_85F76, "pkt ", 0xFFFFFFFFLL, "codec", v9);
    if ( !v10 )
      goto LABEL_11;
  }
  else if ( !v10 )
  {
    goto LABEL_11;
  }
  v11 = 0;
  do
  {
    v12 = v11 + 32;
    if ( v11 + 32 <= v10 )
      v13 = 32;
    else
      v13 = v10 & 0x1F;
    result = (unsigned int *)hex_dump_to_buffer(
                               (char *)v8 + v11,
                               v13,
                               32,
                               4,
                               &v15,
                               96,
                               0,
                               a8,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19,
                               v20,
                               v21,
                               v22,
                               v23,
                               v24,
                               v25,
                               v26,
                               v27);
    if ( (msm_vidc_debug & 0x10) != 0 )
      result = (unsigned int *)printk(&unk_8D194, "pkt ", 0xFFFFFFFFLL, "codec", v9);
    v11 = v12;
  }
  while ( v12 < v10 );
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
