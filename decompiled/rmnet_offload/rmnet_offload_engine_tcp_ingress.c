__int64 __fastcall rmnet_offload_engine_tcp_ingress(__int64 a1, _QWORD *a2, char a3, __int64 **a4)
{
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x0
  char v11; // w8
  bool v12; // w9
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x22
  __int64 v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  int v21; // w8
  __int64 v22; // x0
  _QWORD v24[7]; // [xsp+8h] [xbp-88h] BYREF
  int v25; // [xsp+40h] [xbp-50h]
  __int64 v26; // [xsp+48h] [xbp-48h] BYREF
  __int64 v27; // [xsp+50h] [xbp-40h]
  __int64 v28; // [xsp+58h] [xbp-38h]
  __int64 v29; // [xsp+60h] [xbp-30h]
  __int64 v30; // [xsp+68h] [xbp-28h]
  __int64 v31; // [xsp+70h] [xbp-20h]
  __int64 v32; // [xsp+78h] [xbp-18h]
  int v33; // [xsp+80h] [xbp-10h]
  __int64 v34; // [xsp+88h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a3 & 1) != 0 )
  {
    v7 = 12;
LABEL_31:
    rmnet_offload_stats_update(v7);
    rmnet_offload_engine_flush_flow(a1, a4);
    rmnet_offload_flush_current_pkt((__int64)a2, (__int64)a4);
    goto LABEL_32;
  }
  v8 = *a2;
  v9 = *((unsigned __int16 *)a2 + 26);
  LODWORD(v28) = 0;
  v26 = 0;
  v27 = 0;
  v10 = rmnet_frag_header_ptr(v8, v9, 20, &v26);
  if ( !v10 )
  {
    v7 = 13;
    goto LABEL_31;
  }
  if ( (*(_BYTE *)(*a2 + 81LL) & 0x20) != 0 )
    v11 = *(_BYTE *)(*a2 + 67LL);
  else
    v11 = *(_BYTE *)(v10 + 13);
  v7 = 13;
  if ( *((_WORD *)a2 + 32) )
    v12 = 0;
  else
    v12 = (v11 & 0x10) != 0;
  if ( v12 || (v11 & 0xAF) != 0 )
    goto LABEL_31;
  if ( *(_BYTE *)(a1 + 98) )
  {
    v13 = *(_QWORD *)(a1 + 16);
    v14 = *(unsigned __int16 *)(a1 + 76);
    v15 = *(unsigned __int16 *)(a1 + 78);
    v33 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v26 = 0;
    v25 = 0;
    memset(v24, 0, sizeof(v24));
    v16 = rmnet_frag_header_ptr(v13, v14, v15, &v26);
    if ( !v16
      || (v17 = v16,
          (v18 = rmnet_frag_header_ptr(*a2, *((unsigned __int16 *)a2 + 26), *((unsigned __int16 *)a2 + 27), v24)) == 0)
      || (v19 = ((unsigned __int64)*(unsigned __int8 *)(v17 + 12) >> 2) & 0x3C,
          ((*(unsigned __int8 *)(v18 + 12) >> 2) & 0x3C) != (_DWORD)v19) )
    {
LABEL_27:
      v22 = 14;
LABEL_28:
      rmnet_offload_stats_update(v22);
      rmnet_offload_engine_flush_flow(a1, a4);
      goto LABEL_29;
    }
    if ( (unsigned int)v19 >= 0x15 )
    {
      v20 = 20;
      while ( *(_DWORD *)(v17 + v20) == *(_DWORD *)(v18 + v20) )
      {
        v20 += 4LL;
        if ( v20 >= v19 )
          goto LABEL_21;
      }
      goto LABEL_27;
    }
LABEL_21:
    if ( *((_DWORD *)a2 + 12) != *(_DWORD *)(a1 + 72) )
    {
      v7 = 15;
      goto LABEL_31;
    }
    v21 = *(unsigned __int16 *)(*a2 + 70LL);
    if ( !*(_WORD *)(*a2 + 70LL) )
      v21 = *((unsigned __int16 *)a2 + 32);
    if ( v21 != *(unsigned __int16 *)(a1 + 96) )
    {
      v22 = 16;
      goto LABEL_28;
    }
    if ( *(unsigned __int16 *)(a1 + 88) + (unsigned __int64)*((unsigned __int16 *)a2 + 32) >= rmnet_offload_knob_get(0) )
    {
      v22 = 17;
      goto LABEL_28;
    }
    *((_BYTE *)a2 + 66) = 0;
  }
LABEL_29:
  rmnet_offload_engine_add_flow_pkt(a1, (__int64)a2);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return 1;
}
