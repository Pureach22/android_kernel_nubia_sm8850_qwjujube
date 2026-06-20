__int64 __fastcall wbuff_module_register(unsigned __int8 *a1, unsigned __int8 a2, int a3, int a4, unsigned int a5)
{
  __int64 v5; // x11
  char *v6; // x8
  unsigned __int8 *v9; // x8
  __int64 v10; // x10
  unsigned __int64 v11; // x9
  unsigned int v12; // t1
  __int64 v14; // x12
  unsigned __int8 *v15; // x8
  __int64 v16; // x13
  int v17; // w21
  __int64 v18; // x25
  unsigned __int64 v19; // x26
  __int64 v20; // x22
  char *v21; // x23
  __int64 v22; // x27
  __int64 v23; // x0
  char *v24; // [xsp+8h] [xbp-58h]
  char *v25; // [xsp+10h] [xbp-50h]
  __int64 v26; // [xsp+18h] [xbp-48h]
  unsigned __int8 *v27; // [xsp+20h] [xbp-40h]
  __int64 v28; // [xsp+28h] [xbp-38h]
  __int64 v29; // [xsp+38h] [xbp-28h]
  unsigned __int8 v31; // [xsp+50h] [xbp-10h]
  __int64 v32; // [xsp+58h] [xbp-8h]

  if ( wbuff[0] != 1 )
    return 0;
  v5 = a2;
  v6 = nullptr;
  if ( (unsigned int)a2 - 17 < 0xFFFFFFF0 || a5 > 1 )
    return (__int64)v6;
  if ( *a1 > 0xFu )
    return 0;
  v9 = a1 + 6;
  v10 = 1;
  do
  {
    v11 = v10;
    if ( a2 == v10 )
      break;
    v12 = *v9;
    v9 += 6;
    ++v10;
  }
  while ( v12 < 0x10 );
  if ( v11 < a2 || (wbuff[808 * a5 + 8] & 1) != 0 )
    return 0;
  wbuff[808 * a5 + 32] = a5;
  v24 = &wbuff[808 * a5 + 32];
  v25 = &wbuff[808 * a5 + 8];
  v14 = 0;
  v26 = a2;
  v27 = a1;
  v29 = 16LL * a5;
  v28 = 808LL * a5 + 48;
  while ( 1 )
  {
    v15 = &a1[6 * v14];
    v16 = *v15;
    if ( (unsigned int)v16 > 0x10 )
      break;
    v17 = *((unsigned __int16 *)v15 + 1);
    if ( *((_WORD *)v15 + 1) )
    {
      v18 = *((unsigned __int16 *)v15 + 2);
      v31 = *v15;
      v32 = v14;
      v19 = v28 + 48 * v16;
      v20 = (__int64)&v25[48 * v16 + 40];
      v21 = &wbuff[808 * a5 + 48 * v16];
      v22 = v29 | (2 * v16) | 1;
      do
      {
        v23 = _qdf_nbuf_page_frag_alloc(0, v18, a3, a4, (__int64)&unk_933E60, "wbuff_prepare_nbuf", 106);
        if ( v23 )
        {
          *(_QWORD *)(v23 + 16) = v22;
          if ( v19 >= 0x658 )
            goto LABEL_25;
          *((_QWORD *)v21 + 11) += (unsigned int)(*(_DWORD *)(v23 + 232) - 640);
          if ( v19 > 0x677 )
            goto LABEL_25;
          *(_QWORD *)v23 = *(_QWORD *)(v20 + 8);
          *(_QWORD *)(v20 + 8) = v23;
        }
        --v17;
      }
      while ( v17 );
      if ( v19 <= 0x66E )
      {
        v14 = v32;
        *(_WORD *)(v20 + 16) = v18;
        v5 = v26;
        a1 = v27;
        *(_BYTE *)(v20 + 18) = v31;
        *(_BYTE *)v20 = 1;
        goto LABEL_15;
      }
LABEL_25:
      __break(1u);
      break;
    }
LABEL_15:
    if ( ++v14 == v5 )
    {
      *v25 = 1;
      v6 = v24;
      *((_DWORD *)v25 + 7) = a3;
      *((_DWORD *)v25 + 8) = a4;
      return (__int64)v6;
    }
  }
  __break(0x5512u);
  return qdf_spin_lock_bh_19();
}
