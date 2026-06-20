__int64 __fastcall sub_16900(__int64 a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, __int64 a9, char s)
{
  __int64 v10; // x20
  void *v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  unsigned __int64 v14; // x3
  __int64 v15; // x4
  unsigned __int64 v16; // x8
  __int64 v17; // x10
  __int64 *v18; // x12
  unsigned __int64 v19; // x11
  __int64 v20; // x13
  __int64 v21; // t1
  __int64 **v22; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x13
  unsigned __int64 v25; // x11
  unsigned __int64 v26; // x12
  __int64 *v27; // x13
  unsigned int v28; // w15
  __int64 v29; // x16
  __int64 v30; // t1

  v10 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  v11 = memset(&s, 0, 0x400u);
  v16 = *(unsigned __int8 *)(v10 + 2);
  if ( !*(_BYTE *)(v10 + 2) )
  {
    v14 = 0;
LABEL_9:
    v22 = *(__int64 ***)(v10 + 8);
    if ( v22 )
    {
      v23 = 0xFFFFFFFEC0000000LL - ((__int64)memstart_addr >> 12 << 6);
      do
      {
        v24 = (__int64)v22[27] + *((unsigned int *)v22 + 53);
        v25 = *(unsigned __int8 *)(v24 + 2);
        if ( *(_BYTE *)(v24 + 2) )
        {
          v26 = 0;
          v27 = (__int64 *)(v24 + 88);
          do
          {
            if ( v26 == 18 )
              goto LABEL_23;
            v28 = (v14 + v26) & 0x7F;
            if ( (int)v14 + (int)v26 <= 0 )
              v28 = -(-(v14 + v26) & 0x7F);
            if ( v28 > 0x7F )
              goto LABEL_23;
            v30 = *v27;
            v27 += 2;
            v29 = v30;
            ++v26;
            if ( (v30 & 1) != 0 )
              v29 = 0;
            *((_QWORD *)&s + v28) = (__int64)(v29 - v23) >> 6;
          }
          while ( v26 < v25 );
          v14 = (unsigned int)(v14 + v26);
        }
        v22 = (__int64 **)*v22;
      }
      while ( v22 );
    }
    JUMPOUT(0x168D0);
  }
  v17 = 0;
  v18 = (__int64 *)(v10 + 88);
  v19 = 0xFFFFFFFEC0000000LL - ((__int64)memstart_addr >> 12 << 6);
  while ( v17 != 18 )
  {
    v21 = *v18;
    v18 += 2;
    v20 = v21;
    v14 = v17 + 1;
    if ( (v21 & 1) != 0 )
      v20 = 0;
    *((_QWORD *)&s + v17++) = (__int64)(v20 - v19) >> 6;
    if ( v14 >= v16 )
      goto LABEL_9;
  }
LABEL_23:
  __break(0x5512u);
  return _rmnet_frag_segment_data(v11, v12, v13, v14, v15);
}
