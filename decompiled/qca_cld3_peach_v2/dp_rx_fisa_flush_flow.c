__int64 __fastcall dp_rx_fisa_flush_flow(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 *v5; // x24
  int v6; // w10
  __int64 v7; // x11
  __int64 v8; // x12
  __int64 v9; // x21
  __int64 v10; // x23
  __int64 *v11; // x25
  unsigned int v12; // w8
  char v13; // w9
  int v14; // w9
  int v15; // w9
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x8
  unsigned int *v19; // x10
  __int64 v20; // x9
  int v21; // w11
  unsigned int v22; // t1
  unsigned __int64 v23; // t2
  _QWORD *v24; // x8
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 v26; // x0
  __int64 v27; // x1
  int v28; // w9
  __int64 v29; // x0
  __int64 v30; // x1
  unsigned int *v31; // x26
  __int64 v32; // x3
  int v33; // w0
  unsigned __int64 v34; // t2
  __int64 v35; // x8
  int v36; // w9
  int v37; // w11
  __int64 v38; // x10
  unsigned int v39; // t1
  unsigned __int64 v40; // t2
  int v41; // w10
  __int64 v42; // x8
  _QWORD *v43; // x8
  __int64 ref_by_id_3; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x22
  unsigned int *v54; // x8
  int v55; // w1
  __int64 v56; // x0
  unsigned int *v57; // x8
  __int64 v58; // x23
  unsigned int *v59; // x8
  unsigned __int8 v60; // w22
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x1
  __int64 v71; // x0
  __int64 v72; // x0
  int v73; // w8

  v3 = result;
  v5 = (__int64 *)(a2 + 48);
  v4 = *(_QWORD *)(a2 + 48);
  if ( *(_BYTE *)(a2 + 41) )
  {
    if ( !v4 )
      return result;
    v6 = *(_DWORD *)(v4 + 129);
    v7 = *(_QWORD *)(v4 + 216);
    v8 = *(unsigned int *)(v4 + 212);
    v9 = *(_QWORD *)(*(_QWORD *)(a2 + 200) + 240LL);
    *(_DWORD *)(v4 + 152) = *(_DWORD *)(v4 + 80);
    *(_DWORD *)(v4 + 129) = v6 | 0x400;
    if ( *(_QWORD *)(v7 + v8 + 8) )
    {
      v10 = *(_QWORD *)(a2 + 224);
      v11 = (__int64 *)(*(_QWORD *)(v4 + 224) + *(unsigned int *)(a2 + 80));
      v12 = *(unsigned __int16 *)(a2 + 58) - (bswap32(*(unsigned __int16 *)(v10 + 4)) >> 16);
      v13 = *(_BYTE *)(v4 + 68);
      *(_DWORD *)(v4 + 116) = v12;
      if ( (v13 & 4) != 0 )
        v14 = *(unsigned __int16 *)(v4 + 66);
      else
        v14 = 0;
      *(_DWORD *)(v4 + 112) += v14 + v12;
      v28 = *(unsigned __int16 *)(a2 + 84);
      v29 = *((unsigned int *)v11 + 3);
      v31 = (unsigned int *)(v11 + 2);
      v30 = *((unsigned int *)v11 + 4);
      v32 = *((unsigned __int8 *)v11 + 9);
      *((_WORD *)v11 + 1) = bswap32(*(unsigned __int16 *)(a2 + 58) + v28) >> 16;
      v33 = csum_tcpudp_nofold(v29, v30, *(unsigned __int16 *)(a2 + 58), v32, 0);
      *((_WORD *)v11 + 5) = 0;
      HIDWORD(v34) = v33;
      LODWORD(v34) = v33;
      v35 = *v11;
      v36 = (v34 >> 16) + v33;
      v37 = (*(_BYTE *)v11 & 0xF) - 3;
      v38 = v11[1] + __CFADD__(v11[1], *v11) + *v11;
      do
      {
        v39 = *v31++;
        --v37;
        v38 += v39;
      }
      while ( v37 > 1 );
      HIDWORD(v40) = (unsigned __int64)(__ROR8__(v38, 32) + v38) >> 32;
      LODWORD(v40) = HIDWORD(v40);
      *((_WORD *)v11 + 5) = ~(((unsigned int)(v40 >> 16) + HIDWORD(v40)) >> 16);
      v41 = *(unsigned __int16 *)(a2 + 84);
      *(_WORD *)(v10 + 6) = HIWORD(v36);
      *(_WORD *)(v10 + 4) = bswap32(bswap32(v35) - v41) >> 16;
      v42 = *(_QWORD *)(v4 + 216);
      *(_WORD *)(v4 + 142) = 6;
      *(_WORD *)(v4 + 140) = v10 - v42;
      *(_WORD *)(v42 + *(unsigned int *)(v4 + 212) + 4) = *(_DWORD *)(a2 + 220);
      *(_WORD *)(*(_QWORD *)(v4 + 216) + *(unsigned int *)(v4 + 212) + 6LL) = *(_WORD *)(a2 + 60);
      *(_DWORD *)(*(_QWORD *)(v4 + 216) + *(unsigned int *)(v4 + 212) + 24LL) = 0x20000;
      *(_BYTE *)(v4 + 128) |= 0x60u;
    }
    **(_QWORD **)(a2 + 48) = 0;
    *(_BYTE *)(*(_QWORD *)(a2 + 48) + 75LL) = 1;
    v43 = *(_QWORD **)(a2 + 72);
    if ( v43 )
      *v43 = 0;
    ref_by_id_3 = dp_vdev_get_ref_by_id_3(v9, *(_BYTE *)(*v5 + 86));
    if ( ref_by_id_3 )
    {
      v53 = ref_by_id_3;
      while ( v53 != *(_QWORD *)(a2 + 152) )
      {
        v54 = (unsigned int *)*(unsigned __int8 *)(v53 + 59);
        v55 = *(unsigned __int8 *)(a2 + 160);
        if ( (_DWORD)v54 == v55 )
          goto LABEL_44;
        v56 = dp_vdev_get_ref_by_id_3(v9, v55);
        if ( !v56 )
          goto LABEL_44;
        v57 = *(unsigned int **)(a2 + 152);
        v58 = v56;
        if ( (unsigned int *)v56 != v57
          || (unsigned int)qdf_mem_cmp((const void *)(v56 + 104), (const void *)(v53 + 104), 6u) )
        {
          dp_vdev_unref_delete(v9, v58, 2u, v57, v45, v46, v47, v48, v49, v50, v51, v52);
LABEL_44:
          v72 = *v5;
          if ( !*v5 )
          {
LABEL_39:
            result = dp_vdev_unref_delete(v9, v53, 2u, v54, v45, v46, v47, v48, v49, v50, v51, v52);
            goto LABEL_40;
          }
LABEL_38:
          _qdf_nbuf_free(v72);
          goto LABEL_39;
        }
        v59 = (unsigned int *)(*(_QWORD *)(a2 + 264) + 1LL);
        *(_QWORD *)(a2 + 264) = v59;
        dp_vdev_unref_delete(v9, v53, 2u, v59, v45, v46, v47, v48, v49, v50, v51, v52);
        v60 = *(_BYTE *)(v58 + 59);
        dp_vdev_unref_delete(v9, v58, 2u, v61, v62, v63, v64, v65, v66, v67, v68, v69);
        v53 = dp_vdev_get_ref_by_id_3(v9, v60);
        if ( !v53 )
          goto LABEL_28;
      }
      v70 = *(_QWORD *)(a2 + 48);
      v54 = (unsigned int *)*(unsigned __int16 *)(a2 + 232);
      if ( *(_DWORD *)(v70 + 116) == (_DWORD)v54 )
      {
        v54 = *(unsigned int **)(v3 + 168);
        if ( v54 )
        {
          v71 = *(_QWORD *)(v3 + 88);
          if ( *(v54 - 1) != 424933381 )
            __break(0x8228u);
          if ( !((unsigned int (__fastcall *)(__int64))v54)(v71) )
            goto LABEL_39;
          v70 = *v5;
        }
      }
      if ( !v70 )
        goto LABEL_39;
      v72 = v70;
      goto LABEL_38;
    }
LABEL_28:
    result = *v5;
    if ( *v5 )
      result = _qdf_nbuf_free(result);
LABEL_40:
    *v5 = 0;
    v5 = (__int64 *)(a2 + 72);
  }
  else
  {
    if ( !v4 )
      return result;
    v15 = *(_DWORD *)(v4 + 129);
    v16 = *(_QWORD *)(v4 + 216);
    v17 = *(unsigned int *)(v4 + 212);
    *(_DWORD *)(v4 + 152) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v4 + 129) = v15 | 0x400;
    *(_DWORD *)(v16 + v17 + 24) = 0x20000;
    v18 = *(_QWORD *)(v4 + 224) + *(unsigned int *)(a2 + 80);
    *(_WORD *)(v18 + 2) = *(_WORD *)(a2 + 58);
    v19 = (unsigned int *)(v18 + 16);
    v20 = *(_QWORD *)(v18 + 8) + __CFADD__(*(_QWORD *)(v18 + 8), *(_QWORD *)v18) + *(_QWORD *)v18;
    v21 = (*(_BYTE *)v18 & 0xF) - 3;
    do
    {
      v22 = *v19++;
      --v21;
      v20 += v22;
    }
    while ( v21 > 1 );
    HIDWORD(v23) = (unsigned __int64)(__ROR8__(v20, 32) + v20) >> 32;
    LODWORD(v23) = HIDWORD(v23);
    *(_WORD *)(v18 + 10) = ~(((unsigned int)(v23 >> 16) + HIDWORD(v23)) >> 16);
    **(_QWORD **)(a2 + 48) = 0;
    v24 = *(_QWORD **)(a2 + 72);
    if ( v24 )
      *v24 = 0;
    v25 = *(__int64 (__fastcall **)(__int64, __int64))(result + 168);
    v26 = *(_QWORD *)(result + 88);
    v27 = *v5;
    if ( *((_DWORD *)v25 - 1) != 424933381 )
      __break(0x8228u);
    result = v25(v26, v27);
  }
  v73 = *(_DWORD *)(a2 + 184);
  *v5 = 0;
  *(_DWORD *)(a2 + 184) = v73 + 1;
  return result;
}
