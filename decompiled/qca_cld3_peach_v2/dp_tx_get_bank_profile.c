__int64 __fastcall dp_tx_get_bank_profile(__int64 a1, __int64 a2)
{
  int v2; // w20
  unsigned int v3; // w21
  const char *v4; // x22
  __int64 v5; // x23
  __int64 v6; // x24
  int v9; // w9
  __int64 v10; // x9
  int v11; // w20
  char v12; // w25
  char v13; // w22
  char v14; // w21
  int v15; // w26
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w8
  int v25; // w10
  __int64 v26; // x8
  _DWORD *v27; // x11
  int v28; // w10
  __int64 v29; // x8
  void (*v30)(void); // x9
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v54; // w9
  __int64 v55; // [xsp+0h] [xbp-40h]

  _X8 = (unsigned int *)(a2 + 43268);
  if ( *(_DWORD *)(a2 + 40) )
  {
    v9 = 2 * (*(_DWORD *)(a2 + 40) & 3);
  }
  else
  {
    v10 = *_X8;
    if ( (unsigned int)v10 >= 0xC )
    {
      __break(0x5512u);
      goto LABEL_32;
    }
    v9 = 8 * (sec_type_map[v10] & 0xF);
  }
  if ( *(_BYTE *)(a2 + 73) == 1 && *(_DWORD *)(a2 + 32) == 3 )
    v11 = v9 | 0x40200;
  else
    v11 = ((*(_BYTE *)(a2 + 81) & 1) << 10) & 0xF7FF | (((*(unsigned __int8 *)(a2 + 81) >> 1) & 1) << 11) | v9;
  v5 = 22536;
  v12 = *(_BYTE *)(a2 + 72);
  v13 = *(_BYTE *)(a2 + 46249);
  v14 = *(_BYTE *)(a2 + 62);
  v15 = *(_DWORD *)(a2 + 64) != 0;
  qdf_mutex_acquire(a1 + 22536);
  if ( !*(_BYTE *)(a1 + 22528) )
  {
LABEL_29:
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: unable to find TX bank!",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_tx_get_bank_profile");
    return (unsigned int)-1;
  }
  v24 = v11 & 0xFFFE0FFF | (v15 << 12);
  v6 = 0;
  v2 = -1;
  v25 = v24 | ((v12 & 0x3F) << 19) | ((v13 & 1) << 14);
  v26 = *(_QWORD *)(a1 + 22600);
  v3 = v25 | ((v14 & 3) << 15);
  v27 = (_DWORD *)(v26 + 8);
  v28 = -1;
  do
  {
    if ( *((_BYTE *)v27 - 8) )
    {
      if ( *v27 == v3 )
      {
        v4 = "matching";
        v2 = v6;
        goto LABEL_28;
      }
    }
    else if ( v2 == -1 )
    {
      v2 = v6;
      goto LABEL_12;
    }
    if ( v28 == -1 )
    {
      if ( *(v27 - 1) )
        v28 = -1;
      else
        v28 = v6;
    }
LABEL_12:
    ++v6;
    v27 += 3;
  }
  while ( *(unsigned __int8 *)(a1 + 22528) != v6 );
  if ( v2 == -1 )
  {
    if ( v28 == -1 )
      goto LABEL_29;
    v4 = "zero_ref_count";
    v2 = v28;
  }
  else
  {
    v4 = "unconfigured";
  }
  v6 = v2;
  v29 = 12LL * v2;
  *(_BYTE *)(*(_QWORD *)(a1 + 22600) + v29) = 1;
  *(_DWORD *)(*(_QWORD *)(a1 + 22600) + v29 + 8) = v3;
  v30 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1808LL);
  if ( *((_DWORD *)v30 - 1) != -2046187666 )
    __break(0x8229u);
  v30();
  v26 = *(_QWORD *)(a1 + 22600);
LABEL_28:
  _X8 = (unsigned int *)(v26 + 12 * v6 + 4);
LABEL_32:
  __asm { PRFM            #0x11, [X8] }
  do
    v54 = __ldxr(_X8);
  while ( __stxr(v54 + 1, _X8) );
  qdf_mutex_release(a1 + v5);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: found %s slot at index %d, input:0x%x match:0x%x ref_count %u",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "dp_tx_get_bank_profile",
    v4,
    (unsigned int)v2,
    v3,
    *(unsigned int *)(*(_QWORD *)(a1 + 22600) + 12 * v6 + 8),
    *(_DWORD *)(*(_QWORD *)(a1 + 22600) + 12 * v6 + 4));
  v39 = *(_DWORD *)(*(_QWORD *)(a1 + 22600) + 12 * v6 + 8);
  LODWORD(v55) = (v39 >> 8) & 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: epd:%x encap:%x encryp:%x src_buf_swap:%x link_meta_swap:%x addrx_en:%x addry_en:%x mesh_en:%x vdev_id_check:%x "
    "pmac_id:%x mcast_pkt_ctrl:%x",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "dp_tx_print_bank_profile_config",
    v39 & 1,
    (v39 >> 1) & 3,
    (v39 >> 3) & 0xF,
    (v39 >> 7) & 1,
    v55,
    (v39 >> 10) & 1,
    (v39 >> 11) & 1,
    (v39 >> 12) & 3,
    (v39 >> 14) & 1,
    (v39 >> 15) & 3,
    (v39 >> 17) & 3);
  return (unsigned int)v2;
}
